//
// Created by Administrator on 25-4-24.
//

#include "lkey/lkey.h"

mbedtls_aes_context lkey_aes_context;
mbedtls_ctr_drbg_context lkey_ctr_drbg_context;
mbedtls_ecdh_context lkey_ecdh_context;
mbedtls_ecdsa_context lkey_ecdsa_context;
mbedtls_entropy_context lkey_entropy_context;
mbedtls_rsa_context lkey_rsa_context;
mbedtls_sha256_context lkey_sha256_context;
mbedtls_pk_context lkey_pk_context;