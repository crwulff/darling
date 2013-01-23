
#ifdef __cplusplus
extern "C" {
#endif

#define EXTERN __attribute__((visibility("default"))) extern

typedef void* xpc_object_t;

extern xpc_object_t *_xpc_type_bool;
extern xpc_object_t *_xpc_type_error;

EXTERN xpc_object_t _xpc_bool_true;
EXTERN xpc_object_t _xpc_bool_false;

EXTERN xpc_object_t _xpc_error_connection_interrupted;
EXTERN xpc_object_t _xpc_error_connection_invalid;
EXTERN xpc_object_t _xpc_error_termination_imminent;

EXTERN const char *_xpc_error_key_description;
EXTERN const char *_xpc_event_key_name;
EXTERN const char *_xpc_event_key_stream_name;

EXTERN xpc_object_t xpc_retain(xpc_object_t object);

EXTERN void xpc_release(xpc_object_t object);

#ifdef __cplusplus
}
#endif
