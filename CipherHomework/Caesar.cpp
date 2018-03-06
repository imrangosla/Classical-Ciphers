#include "Caesar.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

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
		string cleanText = plaintext;
		cleanText.erase(remove(cleanText.begin(), cleanText.end(), '\n'),cleanText.end());
    string str="";
    int asciiOfPlain = 0;
    int caesar = 0;
    int size = 0;
    int newAscii = 0;
    int remainderKey = 0;
    int keyMovedSoFar = 0;
    char caesarChar;
  //  char *cstr = new char[str.length()];

    
   // cout << "cleanText: " << cleanText << endl;
    cout << "cleanText Length: " << cleanText.length() << endl;
    for(int i = 0; i < cleanText.length();i++)
    {
        asciiOfPlain = int(cleanText[i]);
        newAscii = asciiOfPlain + key;
        //ascii value of z is 122
        if(newAscii > 122)
        {
            keyMovedSoFar = 122 - int(cleanText[i]);
            remainderKey = key - keyMovedSoFar;
            asciiOfPlain = 96 + remainderKey;
            caesar = asciiOfPlain;
            caesarChar = char(caesar);
           // strcpy(cstr, str.c_str());
           // cstr[i] = caesarChar;
          //  str[i] = cstr[i];
            
            //str.insert(i,1,caesarChar);
            str += caesarChar;
            size++;
            //cleartext.insert(i, 1, 'x');
        }
        else
        {
            caesar = asciiOfPlain;
            caesar += key;
            //STORING THE ENCRYPTION
            //cstr[i] = char(caesar);
            //str[i] = cstr[i];
            caesarChar = char(caesar);
            //str.insert(i,1,caesarChar);
            str += caesarChar;
            size++;
        }
    }
		string result = str;
		//We turn our str string AKA actually now a c-string back into a string
//        for (int i = 0; i < size; i++)
//        {
//            char temp = static_cast<char>(cstr[i]);
//            result.push_back(str[i]);
//        }
			return result;
} // End of Encrypt

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Caesar::decrypt(const string& cipherText)
{
	string cleanText = cipherText;
	cleanText.erase(remove(cleanText.begin(), cleanText.end(), '\n'),cleanText.end());
	string str;
	int asciiOfPlain = 0;
	int caesar = 0;
	int size = 0;
	int newAscii = 0;
	int remainderKey = 0;
	int keyMovedSoFar = 0;
	char caesarChar;
	char *cstr = new char[str.length()];

	for(int i = 0; i < cleanText.length();i++)
	{
			 asciiOfPlain = int(cleanText[i]);
			 newAscii = asciiOfPlain - key;
			// //ascii value of a is 96
			 if(newAscii <= 96)
			 {
			 		keyMovedSoFar = int(cleanText[i]) - 96;
			 		remainderKey = key - keyMovedSoFar;
			 		asciiOfPlain = 122 - remainderKey;
			 		caesar = asciiOfPlain;
			 		caesarChar = char(caesar);
//                     strcpy(cstr, str.c_str());
//                     cstr[i] = caesarChar;
//                     str[i] = cstr[i];
                    str += caesarChar;
			 		size++;
			 }
			else
			{
				caesar = asciiOfPlain;
				caesar -= key;
                caesarChar = char(caesar);
                str += caesarChar;
				//STORING THE ENCRYPTION
				//cstr[i] = char(caesar);
				//str[i] = cstr[i];
				size++;
			}
	}
	string result = str;
	//We turn our str string AKA actually now a c-string back into a string
//    for (int i = 0; i < size; i++)
//    {
//        char temp = static_cast<char>(cstr[i]);
//        result.push_back(str[i]);
//    }
		return result;

}
