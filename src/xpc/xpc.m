
#include <Foundation/NSObject.h>
#include "xpc.h"

@interface OS_object : NSObject
@end

@implementation OS_object
@end

@interface OS_xpc_object : OS_object // _xpc_type_base
@end

@implementation OS_xpc_object
@end

@interface OS_xpc_null : OS_xpc_object // _xpc_type_null
@end

@implementation OS_xpc_null
@end

@interface OS_xpc_bool : OS_xpc_object // _xpc_type_bool
@end

@implementation OS_xpc_bool
@end

xpc_object_t _xpc_bool_true = &_xpc_type_bool;
xpc_object_t _xpc_bool_false = &_xpc_type_bool;

@interface OS_xpc_int64 : OS_xpc_object // _xpc_type_int64
@end

@implementation OS_xpc_int64
@end

@interface OS_xpc_uint64 : OS_xpc_object // _xpc_type_uint64
@end

@implementation OS_xpc_uint64
@end

@interface OS_xpc_double : OS_xpc_object // _xpc_type_double
@end

@implementation OS_xpc_double
@end

@interface OS_xpc_pointer : OS_xpc_object // _xpc_type_pointer
@end

@implementation OS_xpc_pointer
@end

@interface OS_xpc_date : OS_xpc_object // _xpc_type_date
@end

@implementation OS_xpc_date
@end

@interface OS_xpc_data : OS_xpc_object // _xpc_type_data
@end

@implementation OS_xpc_data
@end

@interface OS_xpc_string : OS_xpc_object // _xpc_type_string
@end

@implementation OS_xpc_string
@end

@interface OS_xpc_uuid : OS_xpc_object // _xpc_type_uuid
@end

@implementation OS_xpc_uuid
@end

@interface OS_xpc_fd : OS_xpc_object // _xpc_type_fd
@end

@implementation OS_xpc_fd
@end

@interface OS_xpc_shmem : OS_xpc_object // _xpc_type_shmem
@end

@implementation OS_xpc_shmem
@end

@interface OS_xpc_mach_send : OS_xpc_object // _xpc_type_mach_send
@end

@implementation OS_xpc_mach_send
@end

@interface OS_xpc_array : OS_xpc_object // _xpc_type_array
@end

@implementation OS_xpc_array
@end

@interface OS_xpc_dictionary : OS_xpc_object // _xpc_type_dictionary
@end

@implementation OS_xpc_dictionary
@end

@interface OS_xpc_error : OS_xpc_object // _xpc_type_error
@end

@implementation OS_xpc_error
@end

@interface OS_xpc_domain : OS_xpc_object // _xpc_type_domain
@end

@implementation OS_xpc_domain
@end

@interface OS_xpc_connection : OS_xpc_object // _xpc_type_connection
@end

@implementation OS_xpc_connection
@end

@interface OS_xpc_endpoint : OS_xpc_object // _xpc_type_endpoint
@end

@implementation OS_xpc_endpoint
@end

@interface OS_xpc_serializer : OS_xpc_object // _xpc_type_serializer
@end

@implementation OS_xpc_serializer
@end

@interface OS_xpc_barrier : OS_xpc_object // _xpc_type_barrier
@end

@implementation OS_xpc_barrier
@end

@interface OS_xpc_pipe : OS_xpc_object // _xpc_type_pipe
@end

@implementation OS_xpc_pipe
@end

@interface OS_xpc_mach_recv : OS_xpc_object // _xpc_type_mach_recv
@end

@implementation OS_xpc_mach_recv
@end

@interface OS_xpc_bundle : OS_xpc_object // _xpc_type_bundle
@end

@implementation OS_xpc_bundle
@end

xpc_object_t _xpc_error_connection_interrupted = &_xpc_type_error;
xpc_object_t _xpc_error_connection_invalid     = &_xpc_type_error;
xpc_object_t _xpc_error_termination_imminent   = &_xpc_type_error;

const char *_xpc_error_key_description = "XPCErrorDescription";
const char *_xpc_event_key_name        = "XPCEventName";
const char *_xpc_event_key_stream_name = "XPCEventStreamName";

xpc_object_t xpc_retain(xpc_object_t object)
{
  // TODO
  return object;
}

void xpc_release(xpc_object_t object)
{
  // TODO
}

