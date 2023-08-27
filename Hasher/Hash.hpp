#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Settings.hpp"
#include "HashType.hpp"

template<class HashType>
std::shared_ptr<typename HashType::digest> hash(std::string input);

template<class HashType>
std::vector<typename HashType::word> getWords(std::string charData);


#include "Hash.tpp"