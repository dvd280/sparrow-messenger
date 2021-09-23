#include "HELPERS.h"


int main (int argc, char **argv) 
{

    std::string input;
    std::cout << "use as 'sender' or as 'reciepient' : ";
    std::cin >> input;
    std::cout << std::endl;

    if (input == std::string("sender"))
    {
        std::string msgInput;
        std::string addrInput;

        std::cout << "enter the message: ";
        std::cin >> msgInput;
        std::cout << std::endl;

        std::cout << "enter the recipient's address: ";
        std::cin >> addrInput;
        std::cout << std::endl;

        std::vector<double> txList = encodeMessage(msgInput); 

        std::ofstream outFile("EncodedTxs.txt");
        // get the vector output and write it to a file as a series of "transfer <address> <amount>"
        for (double amount : txList)
        {
            outFile << "transfer " << std::fixed << std::setprecision(12) << addrInput << " " << std::fixed << std::setprecision(12) << amount << std::endl;
        }

    }
    else
    {
        std::string txPath;
        std::string recAdrInput;

        std::cout << "Enter path to the csv file containing exported tx's: ";
        std::cin >> txPath;
        std::cout << std::endl;

        std::cout << "enter the recipient address: ";
        std::cin >> recAdrInput;
        std::cout << std::endl;


        std::ifstream  data(txPath);
        std::string line;
        std::vector<std::vector<std::string> > parsedCsv;
        while (std::getline(data, line))
        {
            std::stringstream lineStream(line);
            std::string cell;
            std::vector<std::string> parsedRow;
            while (std::getline(lineStream, cell, ','))
            {
                cell = removeSpaces(cell);
                parsedRow.push_back(cell);
            }

            parsedCsv.push_back(parsedRow);
        }

        bool started = false;

        std::vector<unsigned char> message;

        //  Decoding the amounts obtained from the amount column
        for (int i = 1; i < parsedCsv.size(); i++)
        {
            //  convert the amount from a string into a double. 
            //  multiply by the inverse of the monero atomic unit
            //  cast into an ascii char
            unsigned char character = static_cast<char>(std::stod(parsedCsv[i][AMOUNTA]) * ATOMIC_INVERSE);

            //  Store the non-separator characters in the message vector. When done, print : <timestamp> <message>
            if (character != SEPARATOR)
            {
                if (recAdrInput == (parsedCsv[i][DESTINATION_ADDRESS]))
                {
                    message.push_back(character);
                }
            }
            else if (started)
            {
                std::string s(message.begin(), message.end());

                std::cout << parsedCsv[i][TIMESTAMP] << ": " << s << std::endl;

                message.clear();

                started = false;
            }
            else
            {
                started = true;
            }
        }

    }

    return 0;
}





