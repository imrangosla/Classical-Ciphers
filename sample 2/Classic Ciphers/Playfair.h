#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <algorithm>
#include "CipherInterface.h"

using namespace std;

/**
* This class implements the playfair cipher.
* The class extends the abstract class
* CipherInterface.
*/

class Playfair : public CipherInterface
{
	/** The public members **/
public:

	/**
	* Sets the key to use
	* @param key - the key to use
	* @return - True if the key is valid and False otherwise
	*/
	virtual bool setKey(const string& key);

	/**
	* Encrypts a plaintext string
	* @param plaintext - the plaintext string
	* @return - the encrypted ciphertext string
	*/
	virtual string encrypt(const string& plaintext);

	/**
	* Decrypts a string of ciphertext
	* @param ciphertext - the ciphertext
	* @return - the plaintext
	*/
	virtual string decrypt(const string& ciphertext);

	/**
	* setKey helper function to find repeating characters in a string
	* @param key - the key to use
	* @return True if string contains repeating characters and False otherwise
	*/
	bool hasRepeatingChars(string key);

	/**
	* Helper function to do modulus arithmetic for results less than zero
	* because -1 % 5 in c++ is -1 instead of 4...
	* @param x , y - integers in operation
	* @return - result of the operation
	*/
	int mod(int x, int y);

	/* The protected members */
protected:
	char squareKey[5][5];

};

#endif
#pragma once
