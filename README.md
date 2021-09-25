# sparrow-messenger

This is a barebone module for enabling private communication through the Monero blockchain. Simply put, blockchains are distributed ledgers which facilitate the attribution of numeric values to specific addresses. Monero - as a privacy enabling blockchain, lets users attribute numeric values with privacy. Monero as it exists today is mostly known and used as a private digital currency.

This project relies on a basic premise: for computer systems everything is a numeric value - that includes character strings as well. The simplest way to explain is this:

- Alice and Bob want to communicate privately.
- Each of them has their own primary address.
- Both want to establish a private way to communicate.
- Each of them creates a secondary Monero address, and shares it only with the other.


----------------------------------------------------------------------Sender-----------------------------------------------------

Suppose Alice decides to send Bob a message saying:  "Hello Bob". What she needs to do is:

1.  Convert the message into a series of double percision floating point numbers which will be sent as transaction amounts to Bobs secondary sub-address.

2.  After the conversion, instead of "Hello Bob" she has the following series of numbers:

0.000000000072  = (H)

0.000000000101  = (e)

0.000000000108  = (l)

0.000000000108  = (l)

0.000000000111  = (o)

0.000000000032  = ( )

0.000000000066  = (B)

0.000000000111  = (o)

0.000000000098  = (b)


3. transmit a series of transactions with the amounts being the numbers above ( This is done serially - one transaction per block).


---------------------------------------------------------------------Recipient---------------------------------------------------

Bob decides to check whether he got a message from Alice, What he has to do is this:

1.  log into his Monero CLI wallet and export the transaction history using the built in  "export_transfers" command - which saves the transaction data in a csv format.

2.  Identify which transactions signify the beginning and end of different messages.

3.  Convert the amount of all transaction amounts from double percision floating point numbers into characters.

4.  Print the decoded message in the console along with a timestamp.

-----------------------------------------------------------------Sparrow-messenger-------------------------------------------

Sparrow in its current itteration helps to automate:

- Steps 1 and 2 for the sender.
- Steps 2, 3 and 4 for the Recipient.

-----------------------------------------------------------------Usage-----------------------------------------------------------

To send a message with sparrow, navigate to the sparrow.exe directory and use the command:

                                     sparrow < action > < address > < message >

Where:

        < action >  = "send" or "recieve"
        < address > = Adress to which the user wishes to send, or adress to which the user expects to recieve a message.
        < message > = The message which the user wishes to send ( only relevant when < action > = "send")



