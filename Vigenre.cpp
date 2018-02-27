/*
Kevin Pham
Feb 25, 2018
CPSC 452
*/

#include "Vigenre.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Vigenre::setKey(const string& key)
{
	//Make sure key provided is a string.
	if (isdigit(key[0]))
		return false;
	else
	{
		//Store length of key.
		//Convert string to ascii, subtract 97 to normalize numbers, and store as vectorKey.
		//Ex: "lemon" turns into l=11, e=4, m=12, o=14, n=13
		this->keyLength = key.length();

		for (int i = 0; i < keyLength; i++)
		{
			this->vectorKey.push_back((int)key[i] - 97);
		}
	}
	return true;
}

/**
* Encrypts a plaintext string
* @param plaintext - the plaintext string
* @return - the encrypted ciphertext string
*/
string Vigenre::encrypt(const string& plaintext)
{
	//Must setup vectors into header file.
	setupVectors(plaintext);

	//Add to encrypt values, store as ascii.
	//Also prevent ascii from leaving alphabetical value section.
	for (int i = 0; i < inputLength; i++)
	{
		this->vectorOutput.push_back(vectorInput[i] + vectorKeyLong[i] + 97);

		if (vectorOutput[i] > 122)
			vectorOutput[i] -= 26;
	}
	return readyResult();
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Vigenre::decrypt(const string& cipherText)
{
	//Must setup vectors into header file.
	setupVectors(cipherText);

	//Subtract to decrypt values, store as ascii.
	//Also prevent ascii from leaving alphabetical value section.
	for (int i = 0; i < inputLength; i++)
	{
		this->vectorOutput.push_back(vectorInput[i] - vectorKeyLong[i] + 97);

		if (vectorOutput[i] < 97)
			vectorOutput[i] += 26;
	}
	return readyResult();

}

/**
* Setup the vectors in this header file using parameter
* @param text - the plaintext from encrypt, or ciphertext from decrypt
*/
void Vigenre::setupVectors(const string & text)
{
	//Store length of plaintext.
	//Convert plaintext to ascii, subtract 97 to normalize numbers, and store as vectorInput.
	this->inputLength = text.length();

	for (int i = 0; i < inputLength; i++)
	{
		this->vectorInput.push_back((int)text[i] - 97);
	}

	//Take the key, and duplicate it over and over until each input character has a key character.
	//Ex) input: attackatdawn
	//  longkey: lemonlemonle
	for (int i = 0; i < inputLength; i++)
	{
		this->vectorKeyLong.push_back(vectorKey[i % keyLength]);
	}
}

/**
* Ready the result for output.
*/
string Vigenre::readyResult()
{
	//-REQUIRES- function setupVectors(text) and encrypt() or decrypt() to have been used.
	//Convert ascii numbers back into letters. Store as result.
	string result;
	for (int i = 0; i < inputLength; i++)
	{
		char temp = static_cast<char>(vectorOutput[i]);
		result.push_back(vectorOutput[i]);
	}
	return result;
}