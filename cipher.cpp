#include <string>
#include <iostream>
#include <fstream>
#include "CipherInterface.h"
#include "Playfair.h"
#include "RowTransposition.h"
#include "Railfence.h"
#include "Vigenre.h"
#include "Caesar.h"


#ifndef __HP_aCC
using namespace std;
#endif

/* Error handling for cipher creation */
void errorCheck(CipherInterface*);

/* Sets the key, perfroms encryption/decryption and writes to the output file */
void cryptoDriver(CipherInterface*, string, string, string, string);

int main(int argc, char** argv)
{
	if (argc != 6)
		return -1;

	/* Code for parsing the command line parameters */
	string cipherName = argv[1];
	string key = argv[2];
	string encDec = argv[3];
	string inputFile = argv[4];
	string outputFile = argv[5];

	/* Code for reading the file */
	fstream stream(inputFile);
	string content((istreambuf_iterator<char>(stream)),(istreambuf_iterator<char>()));
	stream.close();
	
	/* An interface class */
	CipherInterface* cipher = NULL;
	
	if (cipherName == "PLF")
	{
		/* Create an instance of the Playfair cipher */
		cipher = new Playfair();
		errorCheck(cipher);
		cryptoDriver(cipher, key, encDec, outputFile, content);
	}
	else if (cipherName == "RTS")
	{
		/* Create an instance of the Row Transposition cipher */
		cipher = new RowTransposition();
		errorCheck(cipher);
		cryptoDriver(cipher, key, encDec, outputFile, content);
	}
	else if (cipherName == "RFC")
	{
		/* Create an instance of the Railfence cipher */
		cipher = new Railfence();
		errorCheck(cipher);
		cryptoDriver(cipher, key, encDec, outputFile, content);
	}
	else if (cipherName == "VIG")
	{
		/* Create an instance of the Vigenre cipher */
		cipher = new Vigenre();
		errorCheck(cipher);
		cryptoDriver(cipher, key, encDec, outputFile, content);
	}
	else if (cipherName == "CES")
	{
		/* Create an instance of the Caesar cipher */
		cipher = new Caesar();
		errorCheck(cipher);
		cryptoDriver(cipher, key, encDec, outputFile, content);
	}
	else 
	{
		cout << "Invalid Cipher" << endl;
		return -1;
	}
	
	system("pause");
	return 0;
}

void errorCheck(CipherInterface * cipher) 
{
	/* Error checks */
	if (!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
}

void cryptoDriver(CipherInterface * cipher, string key, string encDec, string outputFile, string content)
{
	ofstream outFile;
	outFile.open(outputFile);

	/* Set the encryption key */
	if (cipher->setKey(key))
	{
		if (encDec == "ENC")
		{
			/* Perform encryption */
			string cipherText = cipher->encrypt(content);
			outFile << cipherText;
			cout << "Encryption Successful" << endl;
		}
		else if (encDec == "DEC")
		{
			/* Perform decryption */
			string plainText = cipher->decrypt(content);
			outFile << plainText;
			cout << "Decryption Successful" << endl;
		}
	}
	else
		cout << "Invalid Key" << endl;

	outFile.close();
}
