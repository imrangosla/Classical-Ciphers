#include <string>
#include <fstream>
#include "CipherInterface.h"
#include "Playfair.h"
//#include "RowTransposition.h"
#include "Railfence.h"
//#include "Vigenre.h"
#include "Caesar.h"


#ifndef __HP_aCC
using namespace std;
#endif

int main(int argc, char** argv)
{
	/* REPLACE THIS PART WITH YOUR CODE
	* THE CODE BELOW IS A SAMPLE TO
	* ILLUSTRATE INSTANTIATION OF CLASSES
	* THAT USE THE SAME INTERFACE.
	*/

	if (argc != 5)
		return -1;

	string cipherName = argv[0];
	string key = argv[1];
	string encDec = argv[2];
	string inputFile = argv[3];
	string outputFile = argv[4];

	fstream stream(inputFile);
	string content((istreambuf_iterator<char>(stream)),(istreambuf_iterator<char>()));

	ofstream outFile;
	outFile.open(outputFile);
	
	/* Create an instance of the CipherInterface */
	CipherInterface* cipher = NULL;
	
	if (cipherName == "PLF")
	{
		cipher = new Playfair();
		errorCheck(cipher);

		/* Set the encryption key */
		cipher->setKey(key);

		if (encDec == "ENC")
		{
			/* Perform encryption */
			string cipherText = cipher->encrypt(content);
			outFile << cipherText;

		}
		else if (encDec == "DEC")
		{
			/* Perform decryption */
			string plainText = cipher->decrypt(content);
			outFile << plainText;
		}
		

		
	}
	else if (cipherName == "RTS")
	{

	}
	else if (cipherName == "RFC")
	{
		cipher = new Railfence();
		errorCheck(cipher);

		/* Set the encryption key */
		cipher->setKey(key);

		if (encDec == "ENC")
		{
			/* Perform encryption */
			string cipherText = cipher->encrypt(content);
			outFile << cipherText;

		}
		else if (encDec == "DEC")
		{
			/* Perform decryption */
			string plainText = cipher->decrypt(content);
			outFile << plainText;
		}
	}
	else if (cipherName == "VIG")
	{

	}
	else if (cipherName == "CES")
	{
		cipher = new Caesar();
		errorCheck(cipher);

		/* Set the encryption key */
		cipher->setKey(key);

		if (encDec == "ENC")
		{
			/* Perform encryption */
			string cipherText = cipher->encrypt(content);
			outFile << cipherText;

		}
		else if (encDec == "DEC")
		{
			/* Perform decryption */
			string plainText = cipher->decrypt(content);
			outFile << plainText;
		}
	}
	
	outFile.close();
	stream.close();
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
