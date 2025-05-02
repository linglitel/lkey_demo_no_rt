//
// Created by Administrator on 25-4-24.
//

#include <assert.h>

#include "lkey.h"

int LKEY_Hash_SHA256(const uint8_t* data, size_t len, uint8_t output[32])
{
    int ret;
    ret = mbedtls_sha256_starts(&lkey_sha256_context,0);
    if (ret) return LKEY_ERROR;
    ret = mbedtls_sha256_update(&lkey_sha256_context,data,len);
    if (ret) return LKEY_ERROR;
    ret = mbedtls_sha256_finish(&lkey_sha256_context,output);
    if (ret) return LKEY_ERROR;
    return ret;
}
