#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


//  Used for decoding double percision floating point numbers into characters
double ATOMIC_INVERSE   = 1000000000000;
double ATOMIC           = 0.000000000001;
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
void invalidCommand()
{
    std::cout << "invalid command format, use 'help' for correct commands" << std::endl;
}

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
/*
std::vector<double> sparrow::encodeMessage(std::string& msg)                                //write
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

std::string sparrow::decodeMessage(std::vector<double>& msg)
{
    std::string decodedMsg;
    for (double number : msg)
    {
        decodedMsg += static_cast<char>(number * ATOMIC_INVERSE)               ;
    }
    return decodedMsg;
}
*/
