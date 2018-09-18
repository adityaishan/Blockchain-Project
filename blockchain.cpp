#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "block.h"
#include "blockchain.h"


blockchain::blockchain()
{
    block t = create_block();
    chain.push_back(t);
}

std::vector<block> blockcahin::get_chain()
{
	return chain;
}

block blockchain::create_block() 
{
    std::time_t current;
    transaction_data obj(0, "None", "None", time(&current));

    block t(0, obj, 0);
    return t;
}

block *blockchain::get_latest_block()
{
    return &chain.back();
}

void blockchain::add_block(transaction_data obj)
{
    int index = (int)chain.size() -1;
    std::size_t previous_hash = (int)chain.size() > 0 ? get_latest_block()->get_hash() : 0;
    block newBlock(index, obj, previous_hash);
    chain.push_back(newBlock);
}

bool blockchain::is_chain_valid()
{
    int chain_len = (int)chain.size();
    std::vector<block>::iterator it;
    for(it = chain.begin(); it != chain.end(); ++it)
    {
        block currentBlock = *it;
        if(!currentBlock.is_hash_valid()) return 0;
    

        if(chain_len>1)
        {
            block previousBlock = *(it - 1);
            if(currentBlock.get_previous_hash() != previousBlock.get_hash())
                return 0;
        }
    }
    return 1;
}

void blockchain::print_chain()
{
	std::vector<block>::iterator it;

	for(it = chain.begin(); it!=chain.end(); ++it)
	{
		block current_block = *it;

		std::cout<<"\n\nBlock =========================";
		std::cout<<"\nIndes: "<<current_block.get_index();
		std::cout<<"\nAmount: "<<current_block.data.amount;
		std::cout<<"\nSender Key: "<<current_block.data.sender_key;
		std::cout<<"\nReceiver Key: "<<current_block.data.receiver_key;
		std::cout<<"\nTimestamp: "<<current_block.data.timestamp;
		std::cout<<"\nHash: "<<current_block.get_hash();
		std::cout<<"\nPrevious Hash: "<<current_block.get_previous_hash();
		std::cout<<"\nIs Block Valid: "<<current_block.is_hash_valid();
	}
}