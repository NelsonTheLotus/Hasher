#pragma once

#include <vector>
#include <memory>

#include "Settings.hpp"

template<class HashType>
class MessageBlock
{

using blocksize_b = typename HashType::blocksize_b;
using entrysize_b = typename HashType::entrysize_b;
using word = typename HashType::word;

using block_address = typename HashType::block_address;
using entry_address = typename HashType::entry_address;

private:
    block_address blockID;

    word dataBlock[16];
    class MessageBlock* nextBlock;

public:
    MessageBlock(std::vector<word> inputData);
    ~MessageBlock();

    std::vector<word> getBlockData(block_address blockID);
    word getWord(entry_address lineID, block_address blockID = 0);
};

#include "Block.tpp"