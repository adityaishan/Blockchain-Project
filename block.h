#ifndef block_h
#define block_h

#include "transaction_data.h"

//block class
class block
{
  private:
    int index;
    size_t block_hash;
    size_t previous_hash;
    size_t generate_hash();

  public:
    block(int indx, transaction_data obj, size_t prev_hash); 

    int get_index();

    size_t get_hash();

    size_t get_previous_hash();

    transaction_data data;

    bool is_hash_valid();
};

#endif