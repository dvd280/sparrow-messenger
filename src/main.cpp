#include "HELPERS.h"


int main (int argc, char **argv) 
{
    std::string a = argv[1];

    if (a == "send")
    {
        if (argc < 4)
        {
            invalidCommand();
        }
        if (strlen(argv[2]) != 95)
        {
            std::cout << "Error: invalid Monero address" << std::endl;
            return 1;
        }
        std::string Address = argv[2];
        std::string message = argv[3];

        std::vector<double> txList = encodeMessage(message);

        std::ofstream outFile("EncodedTxs.txt");

        // get the vector output and write it to a file as a series of "transfer <address> <amount>"
        for (double amount : txList)
        {
            outFile << "transfer " << std::fixed << std::setprecision(12) << Address << " " << std::fixed << std::setprecision(12) << amount << std::endl;
        }
        
        std::cout << "encoded message exported successfully to: 'EncodedTxs.txt'" << std::endl;

    }
    else if (a == "recieve")
    {
        if (argc < 3)
        {
            invalidCommand();
            return 1;
        }
        if (strlen(argv[2]) != 95)
        {
            std::cout << "Error: invalid Monero address" << std::endl;
            return 1;
        }

        std::string RecAddress = argv[2];
        std::ifstream  data("output0.csv");
        if (data)
        {
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

            for (int i = 1; i < parsedCsv.size(); i++)
            {
                unsigned char character = static_cast<char>(std::stod(parsedCsv[i][AMOUNTA]) * ATOMIC_INVERSE);

                if (character != SEPARATOR)
                {
                    if (RecAddress == (parsedCsv[i][DESTINATION_ADDRESS]))
                    {
                        message.push_back(character);
                    }
                }
                else if (started)
                {
                    
                    std::string s(message.begin(), message.end());
                    std::cout << std::endl;
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
        else
        {
            std::cout << "the output0.csv has to be in the same directory  " << std::endl;
        }
    }
    else
    {
        invalidCommand();
    }
    return 0;
}





