#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

//  Used for decoding double percision floating point numbers into characters
double ATOMIC_INVERSE = 1000000000000;

//  Used for detecting seperators 
const unsigned char SEPARATOR = static_cast<char>(1);

//  Used for data column selection inside the .csv
enum ColName {
    BLOCK,
    DIRECTION,
    UNLOCKED,
    TIMESTAMP,
    AMOUNTA,
    RUNNING_BALANCE,
    HASH,
    PAYMENT_ID,
    FEE,
    DESTINATION_ADDRESS,
    AMOUNTB,
    INDEX,
    NOTE
};

static std::string removeSpaces(std::string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}





std::vector<double> encodeMessage(std::string& msg)                                //write
{
    size_t len = msg.size() + 2;
    
    std::vector<double > encodedMsg;

    
    encodedMsg.push_back(1 / ATOMIC_INVERSE);
    for (unsigned char character : msg)
    {
        encodedMsg.push_back(static_cast<double>(character) / ATOMIC_INVERSE);
    }
    
    encodedMsg.push_back(1 / ATOMIC_INVERSE);
    
    return encodedMsg;
}
