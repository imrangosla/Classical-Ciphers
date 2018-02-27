#include "Railfence.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Railfence::setKey(const string& key)
{
	int intKey = stoi(key);

	if (!isdigit(key[0]))
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

	int row = key;
	int col = (plaintext.length() / key);

	if ((plaintext.length() % key) > 0) {
		col += 1;
	}

	//dynamic creation of a 2 dimentional vector 
	vector<vector<char> >rail(row, vector<char>(col));

	//nested for loop to load plaintext into rail vector
	int k = 0;
	do {

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; j++) {
				if (k < plaintext.length())
				{
					rail[j][i] = plaintext[k];
					k++;
				}
				else
					rail[j][i] = '*';
			}
		}
	} while (k < plaintext.length());

	//nested loop to write out encrypted message for returning
	int g = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; j++) {
				if (rail[i][j] == '*') {
					j++;
				}
				else {
					result += rail[i][j];		
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

	int row = key;
	int col = (cipherText.length() / key);

	if ((cipherText.length() % key) > 0) {
		col += 1;
	}

	//dynamic creation of a 2 dimentional vector 
	vector<vector<char> >rail(row, vector<char>(col));

	//nested loop to load ciphertext into rail vector
	int k = 0;
	do {
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; j++) {
				rail[i][j] = cipherText[k];
				k++;
			}
		}
	} while (k < cipherText.length());

	//nested loop to parse decoded message for returning
	int g = 0;
	do {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; j++) {
				if (rail[j][i] == '*') {
					i++;
				}
				else {
					result += rail[j][i];
					g++;
				}
			}
		}
	} while (g < cipherText.length());

	return result;
}
