
#ifndef _ELF_BLOCK_H_
#define _ELF_BLOCK_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <map>

class DWARFProducer;

#define INVALID_TYPE 0xffffffffffffffff
#define INVALID_SIZE 0xffffffffffffffff

class ELFBlock
{
	public:
		class StringTable
		{
			public:
				StringTable(void) : m_offset(0), m_size(0), m_currentOffset(1), m_data(nullptr) {}

				uint64_t add(const std::string &str);

			public:
				uint64_t m_offset;
				uint64_t m_size;
				uint64_t m_currentOffset;
				char *m_data;
		};

		class Section
		{
			public:
				class DataChunk
				{
					public:
						DataChunk(void *start, uint64_t startOffset, uint64_t size) : m_start(start), m_startOffset(startOffset), m_size(size) {}
					public:
						void     *m_start;
						uint64_t  m_startOffset;
						uint64_t  m_size;
				};

			public:
				Section(const std::string &name, void *start, uint64_t size, uint64_t flags, uint64_t type, bool loadable) :
					m_name(name), m_lastUsedChunk(nullptr), m_flags(flags), m_type(type), m_offset(0), m_loadable(loadable)
				{
					if (start != nullptr || size > 0)
					{
						uint64_t startOffset = 0;
						if (m_data.size() > 0)
						{
							startOffset = m_data.back().m_startOffset + m_data.back().m_size;
						}
						m_data.emplace_back(start, startOffset, size);
					}
				}

				void setData(void *start, uint64_t size)
				{
					m_data.clear();
					appendData(start, size);
				}

				void appendData(void *start, uint64_t size)
				{
					if (start != nullptr || size > 0)
					{
						uint64_t startOffset = 0;
						if (m_data.size() > 0)
						{
							startOffset = m_data.back().m_startOffset + m_data.back().m_size;
						}
						m_data.emplace_back(start, startOffset, size);
					}
				}

				void* getStart(void) const
				{
					return (m_data.size() > 0) ? m_data[0].m_start : nullptr;
				}

				void* getPointer(uint64_t offset) const
				{
					// Optimization - Most often this gets called repeatedly for the same chunk.
					if (m_lastUsedChunk && (m_lastUsedChunk->m_startOffset <= offset) && (m_lastUsedChunk->m_startOffset + m_lastUsedChunk->m_size > offset))
					{
						return (void*)((uintptr_t)m_lastUsedChunk->m_start + (offset - m_lastUsedChunk->m_startOffset));
					}

					auto chunk = m_data.begin();
					while (chunk != m_data.end() && offset >= chunk->m_size)
					{
						offset -= chunk->m_size;
						chunk++;
					}
					if (chunk == m_data.end())
					{
						m_lastUsedChunk = nullptr;
						return nullptr;
					}
					m_lastUsedChunk = &(*chunk);
					return (void*)((uintptr_t)chunk->m_start + offset);
				}

				uint64_t getSize(void) const
				{
					uint64_t size = 0;
					for (auto &chunk : m_data)
					{
						size += chunk.m_size;
					}
					return size;
				}

			public:
				std::string            m_name;
				std::vector<DataChunk> m_data;
				uint64_t               m_flags;
				uint64_t               m_type;
				uint64_t               m_offset;
				bool                   m_loadable;

			protected:
				mutable const DataChunk *m_lastUsedChunk;
		};

		class Symbol
		{
			public:
				enum Type { eUnknown = 0, eFunction, eVariable, eClass };
			public:
				Symbol(const std::string &name, void* addr, Type type = eUnknown, uint64_t size = INVALID_SIZE) :
					m_name(name), m_addr(addr), m_type(type), m_size(size) {}

				std::string m_name;
				void       *m_addr;
				uint64_t    m_size;
				Type        m_type;
		};

	protected:
		const std::string   &m_filename;
		std::vector<Section> m_sections;
		std::multimap<void*, Symbol>  m_symbols;

		uint8_t *m_data;
		uint64_t m_size;

		DWARFProducer *m_dwarfProducer;

	public:
		ELFBlock(const std::string &filename);
		~ELFBlock(void);

		const uint8_t* address(void) { if (nullptr == m_data) { finalize(); } return m_data; }

		uint64_t size(void) const { return m_size; }

		int addSection(const std::string &name, void *start, uint64_t size, uint64_t flags, uint64_t type = INVALID_TYPE, bool loadable = true)
		{
			m_sections.emplace_back(name, start, size, flags, type, loadable);
			return m_sections.size() - 1;
		}

		void setSectionData(int sectionIndex, void *start, uint64_t size)
		{
			if (sectionIndex < m_sections.size())
			{
				m_sections[sectionIndex].setData(start, size);
			}
		}

		void appendSectionData(int sectionIndex, void *start, uint64_t size)
		{
			if (sectionIndex < m_sections.size())
			{
				m_sections[sectionIndex].appendData(start, size);
			}
		}

		auto getSections(void) const -> const decltype(this->m_sections) & { return m_sections; }

		void addSymbol(const std::string &name, void *addr)
		{
			m_symbols.insert(std::pair<void*, Symbol>(addr, Symbol(name, addr)));
		}

		auto getSymbols(void) -> decltype(this->m_symbols) & { return m_symbols; }
		auto getSymbols(void) const -> const decltype(this->m_symbols) & { return m_symbols; }

		void finalize(void);

		const std::string& getFilename(void) { return m_filename; }

	protected:
		uint64_t calcSize(StringTable &strtab, uint64_t &symtabOffset);
};

#endif // _ELF_BLOCK_H_
