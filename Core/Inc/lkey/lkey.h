//
// Created by Administrator on 25-4-24.
//

#ifndef LKEY_H
#define LKEY_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/sha256.h>
#include <mbedtls/rsa.h>
#include <mbedtls/ecdh.h>
#include <mbedtls/ecdsa.h>
#include "pk.h"
#include "tusb.h"


extern mbedtls_aes_context lkey_aes_context;
extern mbedtls_ctr_drbg_context lkey_ctr_drbg_context;
extern mbedtls_ecdh_context lkey_ecdh_context;
extern mbedtls_ecdsa_context lkey_ecdsa_context;
extern mbedtls_entropy_context lkey_entropy_context;
extern mbedtls_rsa_context lkey_rsa_context;
extern mbedtls_sha256_context lkey_sha256_context;
extern mbedtls_pk_context lkey_pk_context;

#define LKEY_PSK_LEN              32
#define LKEY_HUK_LEN              32
#define LKEY_ECC_PUBKEY_LEN       64
#define LKEY_ECC_PRIVKEY_LEN      32
#define LKEY_SHARED_SECRET_LEN    32
#define LKEY_SHA256_DIGEST_LEN    32
#define LKEY_AESGCM_IV_LEN        12
#define LKEY_AESGCM_TAG_LEN       16
#define LKEY_MAX_PAYLOAD_LEN      256
#define LKEY_MAX_SIG_LEN          72
#define LKEY_RSA_MODULUS_LEN_MAX  512
#define LKEY_RSA_EXPONENT_LEN     4

#define LKEY_OK                   0
#define LKEY_ERROR                (-1)

void LKEY_Crypto_Init(void);
void LKEY_Crypto_Deinit(void);

int LKEY_Random(uint8_t* buf, size_t len);

int LKEY_Hash_SHA256(const uint8_t* data, size_t len,
                     uint8_t output[LKEY_SHA256_DIGEST_LEN]);
int LKEY_HMAC_SHA256();
int LKEY_ECC_GenerateKeyPair(uint8_t* pub, uint8_t* priv, mbedtls_ecp_group_id group_id);
int LKEY_ECC_ExportKeyPair_PEM(uint8_t* pub_pem, size_t pub_len, uint8_t* priv_pem, size_t priv_len);
int LKEY_ECC_Sign();
int LKEY_ECC_Verify();

int LKEY_AES_GCM_Encrypt();
int LKEY_AES_GCM_Decrypt();

int LKEY_EdDSA_GenerateKeyPair(uint8_t pub[32], uint8_t priv[64]);
int LKEY_EdDSA_Sign(const uint8_t priv[64],
                    const uint8_t* message, size_t msg_len,
                    uint8_t sig[64]);
int LKEY_EdDSA_Verify(const uint8_t pub[32],
                      const uint8_t* message, size_t msg_len,
                      const uint8_t sig[64]);

void bytes_to_hex(const uint8_t* input, size_t len, char* output);

#endif //LKEY_H
