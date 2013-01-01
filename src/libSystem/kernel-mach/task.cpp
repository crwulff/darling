#include "config.h"
#include "task.h"
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

darwin_task_t mach_task_self_ = new darwin_task(::getpid());

kern_return_t mach_port_deallocate(darwin_task_t task, void* port)
{
	free(port);
	return KERN_SUCCESS;
}

kern_return_t pid_for_task(mach_port_name_t t, int *pid)
{
	// TODO: this is supposed to be for the specified task but for now, just return our pid
	if (pid)
	{
		*pid = mach_task_self_->pid;
	}
	return KERN_SUCCESS;
}

kern_return_t mach_port_mod_refs(ipc_space_t task, mach_port_name_t name, mach_port_right_t right, mach_port_delta_t delta)
{
	return KERN_SUCCESS;
}

kern_return_t task_info(task_name_t target_task, task_flavor_t flavor, task_info_t task_info_out, mach_msg_type_number_t *task_info_outCnt)
{
	// TODO
	*task_info_outCnt = 0;
	return KERN_SUCCESS;
}

kern_return_t mach_vm_region_recurse(vm_map_t target_task, mach_vm_address_t *address, mach_vm_size_t *size, natural_t *nesting_depth, vm_region_recurse_info_t info, mach_msg_type_number_t *infoCnt)
{
	// TODO
	*infoCnt = 0;
	return KERN_SUCCESS;
}

int proc_name(int pid, void * buffer, uint32_t buffersize)
{
	// TODO: get process name
	if (buffer)
	{
		*(char*)buffer = 0;
	}
	return 0;
}

int proc_pidpath(int pid, void * buffer, uint32_t buffersize)
{
	// TODO: get process path
	if (buffer)
	{
		*(char*)buffer = 0;
	}
	return 0;
}

int proc_pidinfo(int pid, int flavor, uint64_t arg, void *buffer, int buffersize)
{
	// TODO: get other pid info?
	if (buffer)
	{
		*(char*)buffer = 0;
	}
	return 0;
}
