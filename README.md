# sparrow-messenger

This is a barebone module for enabling private communication through the Monero blockchain. Simply put, blockchains are distributed ledgers which facilitate the attribution of numeric values to specific addresses. Monero - as a privacy enabling blockchain, lets users attribute numeric values with privacy. Monero as it exists today is mostly known and used as a private digital currency.

This project relies on a basic premise: for computer systems everything is a numeric value - that includes character strings as well. The simplest way to explain is this:

- Alice and Bob want to communicate privately.
- Each of them has their own primary address.
- Both want to establish a private way to communicate.
- Each of them creates a secondary Monero address, and shares it only with the other.


## Sender

Suppose Alice decides to send Bob a message saying:  "Hello Bob". What she needs to do is:

1.  Convert the message into a series of double percision floating point numbers which will later be sent as transaction amounts to Bobs secondary sub-address.

2.  After the conversion, instead of `"Hello Bob"` she has the following series of numbers:

`0.000000000072`  = (H)

`0.000000000101`  = (e)

`0.000000000108`  = (l)

`0.000000000108`  = (l)

`0.000000000111`  = (o)

`0.000000000032`  = ( )

`0.000000000066`  = (B)

`0.000000000111`  = (o)

`0.000000000098`  = (b)


3. Transmit a series of transactions to Bob's address, with the amounts being the numbers above (This should be done serially - one transaction per block).


## Recipient

Bob decides to check whether he got a message from Alice, What he has to do is this:

1.  log into his Monero CLI wallet and export the transaction history using the built in  "export_transfers" command - which saves the transaction data in a csv format (the csv is saved in the same folder as the cli exe by default).

2.  Identify which transactions signify the beginning and end of different messages.

3.  Convert the amount of all transaction amounts from double percision floating point numbers into characters.

4.  Print the decoded message in the console along with a timestamp.

## Sparrow-messenger

**A.  Sparrow in its current itteration helps to automate:**

- Steps 1 and 2 for the sender.
- Steps 2, 3 and 4 for the Recipient.


**B.  Sparrow in its current form does not interact directly with any Monero processes.**

**C.  Users will never be asked to enter any passwords or seeds - all sensitive parts are carried out by the user** 

**D.  The user is free to choose how to execute step 3 for the sender and 1 for the recipient.**

## Compiling

Sparrow is a very small module - less than 200 lines of just standard C++, Which makes it possible to compile on any platform by just copying main.cpp and the Helpers.h header into the same folder/directory. Compilation is possible with any C++ compiler. 

## Usage

To send a message with sparrow, navigate to the sparrow.exe directory and Use the following command:

                                     sparrow < action > < address > < message >

Where:

`<action>`  = `send` or `recieve`

`<address>` = A monero sub-address to which the user wishes to send, or to which the user expects to recieve a message.

`<message>` = The message which the user wishes to send (only relevant when `<action>` = `send`)
        
As a sender, the process will create and save a file named "EncodedTxs.txt" in the same directory as the sparrow executable. The file will include the list of transaction commands that the user will need to transmit to the network by copy-pasting the commands into the cli wallet one by one (one per block), in decending order.

As a reciever, the user exports the list of transfers to/from his wallet by using the "export_transfers" command (after logging into the wallet cli), this will create a csv file named "output0.csv" in the same directory/folder as the cli wallet. The sparrow executable must be located in the same directory as the "output0.csv" and so it would be simplest to place the sparrow exeutable in the same directory as the monero-wallet-cli executable. If the user wants to avoid this, they would need to manually move the .csv to the same directory as the sparrow executable.

## Donate

My Monero donation address:

                    88FFQrAf6y18xTq3tiKiKtFBGWm7s57Q7XSToHfSw6CdXziHq2fC2gMDcFCzrvbRxrVY42FjipBU722iprjNsh7QTThB9yT




