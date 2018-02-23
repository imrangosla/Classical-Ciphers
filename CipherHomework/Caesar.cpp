#include "Caesar.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{
  int Ckey = stoi(key);
  if (!(isdigit[Ckey]))
    return false;
	else
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
  for (size_t i = 0; i < plaintext.length(); i++) {
    if (isupper(plaintext[i])) {
      result += char(int(plaintext[i]+key-65)%26+65);
    }
    else
      result += char(int(plaintext[i]+key-97)%26+97);
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
  int key = 26 -3;
  string result = "";
  for (size_t i = 0; i < cipherText.length(); i++) {
    if (isupper(cipherText[i])) {
      result += char(int(cipherText[i]+s-65)%26+65);
    }
    else
    result += char(int(cipherText[i]+key-97)%26+97)
  }
	return "";

}
