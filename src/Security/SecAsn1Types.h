
#include <Security/cssmtype.h>

typedef CSSM_DATA SecAsn1Item;
typedef CSSM_OID SecAsn1Oid;

typedef struct SecAsn1Template_struct {
  uint32_t    kind;
  uint32_t    offset;
  const void *sub;
  uint32_t    size;
} SecAsn1Template;
