#include <string>
#include "CipherInterface.h"
#include "Playfair.h"

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
		

	/* Create an instance of the Playfair cipher */	
	CipherInterface* cipher = new Playfair();
	
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key */
	cipher->setKey("security");
	
	/* Perform encryption */
	string cipherText = cipher->encrypt("hello world");
	
	/* Perform decryption */
	cipher->decrypt(cipherText);	
	
	return 0;
}
