#include <iostream>
#include <ctime>
#include <vector>

#include "transaction_data.h"
#include "block.h"
#include "blockchain.h"

using namespace std;

int main()
{
	blockchain coin;

	time_t data_time1;

	transaction_data data1(1.5, "ADI", "ISHAN", time(&data_time1));
	coin.add_block(data1);

	time_t data_time2;

	transaction_data data2(0.2233, "ADITYA", "GHOST", time(&data_time2));
	coin.add_block(data2);

	coin.print_chain();

	cout<<"\nIs Chain Is Still Valid?"<<coin.is_chain_valid();
    
    //false block to check.
	block *hack_block = coin.get_latest_block();
	hack_block->data.amount = 100000;
	hack_block->data.receiver_key = "UNKNOWN";

	coin.print_chain();

	cout<<"\nIs Chain still Valid"<<coin.is_chain_valid();
	
	return 0;
}