
#include <memory>
#include <vector>
#include <iostream>
#include <bitset>

#include "HashType.hpp"
#include "Settings.hpp"
#include "Block.hpp"


template<class HashType>
std::shared_ptr<typename HashType::digest> hash(std::string input)
{
using word = typename HashType::word;
using digest = typename HashType::digest;


    std::vector<word> fullData = getWords<HashType>(input);

    for(auto el : fullData)
    {
        std::cout<<std::bitset<sizeof(word)*8>(el)<<", "<<std::endl;
    }
    std::cout<<std::endl;

    MessageBlock<HashType> blockSchedule(fullData);
    return std::shared_ptr<digest>(nullptr);
}



template<class HashType>
std::vector<typename HashType::word> getWords(std::string charData)
{
using word = typename HashType::word;
using block_address = typename HashType::block_address;


    uint wordsize_b = sizeof(word);
    uint parsePerWord = wordsize_b/sizeof(char);

    std::cout<<"wordByte: "<<parsePerWord<<std::endl;

    std::vector<word> wordList = {};
    word entry = 0;
    uint wordIndex = 0;
    block_address charIndex = 0;

    uchar currentChar = charData[charIndex];
    while(charIndex++ != charData.size())
    {     
        entry <<= 8;
        entry += currentChar;
        
        if(++wordIndex == parsePerWord)
        {
            wordList.push_back(entry);
            entry = 0;
            wordIndex = 0;
        }
        
        currentChar = charData[charIndex];
    }

    if(wordIndex != 0)
    {
        entry <<= 8*(4-wordIndex);
        wordList.push_back(entry);
    }

    return wordList;
}