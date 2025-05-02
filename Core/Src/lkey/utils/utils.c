//
// Created by Administrator on 25-4-24.
//

#include <stdio.h>

#include "lkey.h"

void Utils_Random(uint8_t* buf, size_t len)
{
    UNUSED(buf);
    UNUSED(len);
}

void bytes_to_hex(const uint8_t* input, size_t len, char* output)
{
    for (size_t i = 0; i < len; ++i)
    {
        sprintf(output + i * 2, "%02x", input[i]);
    }
    output[len * 2] = '\0'; // 添加字符串终止符
}
