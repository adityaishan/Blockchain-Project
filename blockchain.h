#ifndef blockchain_h
#define blockchain_h

#include<vector>

//blockchain
class blockchain
{
  private:
    block create_block();
    std::vector<block>chain;

  public:
    
    blockchain();

    std::vector<block> get_chain();

    void add_block(transaction_data obj);
    
    bool is_chain_valid();

    block *get_latest_block();

    void print_chain();
};

#endif