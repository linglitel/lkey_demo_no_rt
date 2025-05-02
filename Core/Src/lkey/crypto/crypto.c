//
// Created by Administrator on 25-4-24.
//

#include "lkey/lkey.h"
void LKEY_Crypto_Init(void)
{
    mbedtls_aes_init(&lkey_aes_context);
    mbedtls_ecdh_init(&lkey_ecdh_context);
    mbedtls_sha256_init(&lkey_sha256_context);
    mbedtls_ecdsa_init(&lkey_ecdsa_context);
    mbedtls_entropy_init(&lkey_entropy_context);
    mbedtls_ctr_drbg_init(&lkey_ctr_drbg_context);
    mbedtls_rsa_init(&lkey_rsa_context);
    mbedtls_pk_init(&lkey_pk_context);
}
void LKEY_Crypto_Deinit(void)
{
    mbedtls_aes_free(&lkey_aes_context);
    mbedtls_ecdh_free(&lkey_ecdh_context);
    mbedtls_sha256_free(&lkey_sha256_context);
    mbedtls_ecdsa_free(&lkey_ecdsa_context);
    mbedtls_entropy_free(&lkey_entropy_context);
    mbedtls_ctr_drbg_free(&lkey_ctr_drbg_context);
    mbedtls_rsa_free(&lkey_rsa_context);
    mbedtls_pk_free(&lkey_pk_context);
}



