#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Caesar.h"
#include "Railfence.h"
#include "RowTransposition.h"
#include "Vigenre.h"
#include <fstream>


#ifndef __HP_aCC
using namespace std;
#endif

int main(int argc, char** argv)
{
		if(argc != 5)
        {
            cout <<"There aren't enough arguments in the command\n";
            return 1;
        }
    string cipherName = argv[0];
    string key = argv[1];
    string encOrDec = argv[2];
    string inputFile = argv[3];
    string outputFile = argv[4];

    CipherInterface* cipher = NULL;


    if(cipherName == "PLF")
    {
        /* Create an instance of the Playfair cipher */
        cipher = new Playfair();
        /* Error checks */
        if(!cipher)
        {
            fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
                    __FILE__, __FUNCTION__, __LINE__);
            exit(-1);
        }
        /* Set the encryption key */
        cipher->setKey(key);
        /* Perform encryption */
        string cipherText = cipher->encrypt("hello world");
        /* Perform decryption */
        cipher->decrypt(cipherText);
    }
	return 0;
}
