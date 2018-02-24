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
	if ((plaintext.length()%key) > 0) {
		int row = key;
		int col = (plaintext.length()/key)+ 1;
		char rail[row][col] = {*};
	}
	else{
		int row = key;
		int col = (plaintext.length()/key);
		char rail[row][col] = {*};
	}


	int k = 0;
	do {

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; j++) {
				rail[j][i] = plaintext[k];
				k++;
			}
		}
	} while(k < plaintext.length());

	int g = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; i++) {
				if (rail[i][j] == "*") {
					g++
				}
				else {
					result[g] = rail[i][j];
					g++;
				}
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
	string result;

	RailFence railfence;
	int key = railfence.key;
	if ((plaintext.length()%key) > 0) {
		int row = key;
		int col = (cipherText.length()/key)+ 1;
		char rail[row][col] = {*};
	}
	else{
		int row = key;
		int col = (cipherText.length()/key);
		char rail[row][col] = {*};
	}

	int k = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; j++) {
				rail[i][j] = plaintext[k];
				k++;
			}
		}
	} while(k < plaintext.length());

	int g = 0;
	do {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; i++) {
				if (rail[j][i] == "*") {
					g++;
				}
				else {
					result[g] = rail[j][i];
					g++;
				}
			}
		}
	} while(g < cipherText.length());

return result;

}
