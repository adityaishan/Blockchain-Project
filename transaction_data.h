#ifndef transaction_data_h
#define transaction_data_h

//transaction data
struct transaction_data
{
    double amount;
    std::string sender_key;
    std::string receiver_key;
    time_t timestamp;

    transaction_data(){};

    transaction_data(double amnt, std::string sender, std::string receiver, time_t time)
    {
    	amount = amnt;
    	sender_key = sender;
    	receiver_key = receiver;
    	timestamp = time;
    };
};

#endif
