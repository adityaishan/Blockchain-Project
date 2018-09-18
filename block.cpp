#include <iostream>
#include <string>

#include "block.h"
#include "transaction_data.h"

block::block(int indx, transaction_data obj, size_t prev_hash)
{
    index = indx;
    data = obj;
    previous_hash = prev_hash;
    block_hash = generate_hash();
}

int block::get_index()
{
   return index;
}
size_t block::generate_hash()
{
    hash<std::string> hash1;
    hash<size_t> hash2;
    hash<size_t> final_hash;
    std::string to_hash = std::to_string(data.amount) + data.receiver_key + data.sender_key + std::to_string(data.timestamp);
    
    return final_hash(hash1(to_hash) + hash2(previous_hash));
}

size_t block::get_hash()
{
    return block_hash;
}

size_t block::get_previous_hash()
{
    return previous_hash;
}

bool block::is_hash_valid()
{
    return generate_hash() == block_hash;
}