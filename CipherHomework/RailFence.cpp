#include "RailFence.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool RailFence::setKey(const string& key)
{
	RailFence railfence;
  int Ckey = stoi(key);
  if (!(isdigit[Ckey]))
    return false;
	else{
    railfence.key = key;
    return true;
  }
}




/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string RailFence::encrypt(const string& plaintext)
{
	string result;

	RailFence railfence;
	int key = railfence.key;
	char rail [key][(plaintext.length()/key) + 1];

	int k = 0;
	do {

		for (int i = 0; i < (plaintext.length()/key) + 1; i++) {
			for (int j = 0; j < key; j++) {
				rail[j][i] = plaintext[k];
			}
		}
	} while(k < plaintext.length());

	int g = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < (plaintext.length()/key) + 1; i++) {
				result[g] = rail[i][j];
			}
		}
	} while(g < plaintext.length());

return result;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RailFence::decrypt(const string& cipherText)
{
	return "";

}
