//
// Created by Administrator on 25-4-24.
//

#include <string.h>

#include "lkey.h"

int LKEY_ECC_GenerateKeyPair(uint8_t* pub, uint8_t* priv, mbedtls_ecp_group_id group_id)
{
    int ret;
    ret = mbedtls_ecdsa_genkey(&lkey_ecdsa_context, group_id, mbedtls_ctr_drbg_random, &lkey_ctr_drbg_context);
    if (ret) return LKEY_ERROR;
    size_t len;
    ret = mbedtls_ecp_point_write_binary(&lkey_ecdsa_context.private_grp, &lkey_ecdsa_context.private_Q,
                                         MBEDTLS_ECP_PF_UNCOMPRESSED, &len, pub, 65);
    if (ret) return LKEY_ERROR;
    ret = mbedtls_mpi_write_binary(&lkey_ecdsa_context.private_d, priv, 32);
    if (ret) return LKEY_ERROR;

    return 0;
}

int LKEY_ECC_ExportKeyPair_PEM(uint8_t* pub_pem, size_t pub_len, uint8_t* priv_pem, size_t priv_len)
{
    int ret;
    mbedtls_pk_setup(&lkey_pk_context, mbedtls_pk_info_from_type(MBEDTLS_PK_ECKEY));
    ret = mbedtls_ecdsa_from_keypair(mbedtls_pk_ec(lkey_pk_context), &lkey_ecdsa_context);
    if (ret) return LKEY_ERROR;
    ret = mbedtls_pk_write_pubkey_pem(&lkey_pk_context, pub_pem, pub_len);
    if (ret) return LKEY_ERROR;
    ret = mbedtls_pk_write_key_pem(&lkey_pk_context, priv_pem, priv_len);
    if (ret) return LKEY_ERROR;
    return ret;
}
