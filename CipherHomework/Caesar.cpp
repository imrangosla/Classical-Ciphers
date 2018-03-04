#include "Caesar.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Caesar::setKey(const string& key)
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
string Caesar::encrypt(const string& plaintext)
{
	string result = "";
	for (size_t i = 0; i < plaintext.length()-1; i++) {
		if (islower(plaintext[i])) {
			char letterToChange = char(int(plaintext[i] + key - 97) % 26 + 97);
			result += letterToChange;
		}
		else{
			char letterToChange = char(int(plaintext[i] + key - 65) % 26 + 65);
			result += letterToChange;
		}
	}
	return result;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Caesar::decrypt(const string& cipherText)
{
	int dKey = 26 - key;
	string result = "";
	for (size_t i = 0; i < cipherText.length(); i++) {
		if (islower(cipherText[i])) {
			char letterToChange = char(int(cipherText[i] + dKey - 97) % 26 + 97);
			result += letterToChange;
		}
		else{
			char letterToChange = char(int(cipherText[i] + dKey - 65) % 26 + 65);
			result += letterToChange;
		}
	}
	return result;

}
