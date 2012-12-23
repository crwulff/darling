
#include <unistd.h>
#include <stdint.h>

extern "C" {

typedef size_t CSSM_SIZE;

typedef struct cssm_data {
    CSSM_SIZE  Length;
    uint8_t   *Data;
} CSSM_DATA, *CSSM_DATA_PTR;

typedef CSSM_DATA CSSM_OID, *CSSM_OID_PTR;

}
