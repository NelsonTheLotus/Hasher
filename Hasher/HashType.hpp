#pragma once

#include <cstdint>

#include "Settings.hpp"
/*typedef enum HashType : int
{
    SHA256,
    SHA512,
    MD5
}HashType;

namespace GENERIC
{
    using blocksize_b = uint_least32_t;
    using entrysize_b;
    using word;

    using block_address;
    using entry_address;

    using digest;
};*/


struct SHA256
{
    using blocksize_b = uint_least16_t; //blockwidth_b = 512
    using entrysize_b = uint_least8_t;  //entrywidth_b = 32
    using word = uint_least32_t;        //wordsize = 32 bits

    using block_address = uint_least64_t;   //Max input size = 2^64 bits  (not relating to blocks)
    using entry_address = uint_least8_t;    //Max words/block = 2^4 (=16)

    using digest = uint[8];
};

struct SHA512
{
    using blocksize_b = uint_least16_t; //blockwidth_b = 1024
    using entrysize_b = uint_least8_t;  //entrywidth_b = 64
    using word = uint_least32_t;        //wordsize = 64 bits

    using block_address = uint[4];   //Max input size = 2^128 bits (not relating to blocks)
    using entry_address = uint_least8_t;    //Max words/block = 2^4 (=16)

    using digest = uint[16];
};