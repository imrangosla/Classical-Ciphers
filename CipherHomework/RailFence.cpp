#include "RailFence.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Railfence::setKey(const string& key)
{
	int intKey = stoi(key);

	if (!isdigit(intKey))
		return false;
	else
		this->key = intKey;

	return true;
}




/**
* Encrypts a plaintext string
* @param plaintext - the plaintext string
* @return - the encrypted ciphertext string
*/
string Railfence::encrypt(const string& plaintext)
{
	string result;

	/*Railfence railfence;
	int key = railfence.key;
	if ((plaintext.length() % key) > 0) {
		int row = key;
		int col = (plaintext.length() / key) + 1;
		char rail[row][col] = { *};
	}
	else {
		int row = key;
		int col = (plaintext.length() / key);
		char rail[row][col] = { *};
	}*/

	int row = key;
	int col = (plaintext.length() / key);

	if ((plaintext.length() % key) > 0) {
		col += 1;
	}

	//dynamic creation of a 2 dimentional vector 
	vector<vector<char>>rail(row, vector<char>(col));


	int k = 0;
	do {

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; j++) {
				rail[j][i] = plaintext[k];
				k++;
			}
		}
	} while (k < plaintext.length());

	int g = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; i++) {
				if (rail[i][j] == '*') {
					g++;
				}
				else {
					result[g] = rail[i][j];
					g++;
				}
			}
		}
	} while (g < plaintext.length());

	return result;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Railfence::decrypt(const string& cipherText)
{
	string result;

	/*Railfence railfence;
	int key = railfence.key;
	if ((plaintext.length() % key) > 0) {
		int row = key;
		int col = (cipherText.length() / key) + 1;
		char rail[row][col] = { *};
	}
	else {
		int row = key;
		int col = (cipherText.length() / key);
		char rail[row][col] = { *};
	}*/

	int row = key;
	int col = (cipherText.length() / key);

	if ((cipherText.length() % key) > 0) {
		col += 1;
	}

	//dynamic creation of a 2 dimentional vector 
	vector<vector<char>>rail(row, vector<char>(col));

	int k = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; j++) {
				rail[i][j] = cipherText[k];
				k++;
			}
		}
	} while (k < cipherText.length());

	int g = 0;
	do {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; i++) {
				if (rail[j][i] == '*') {
					g++;
				}
				else {
					result[g] = rail[j][i];
					g++;
				}
			}
		}
	} while (g < cipherText.length());

	return result;

}
