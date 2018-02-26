/*
	Kevin Pham
	Feb 25, 2018
	CPSC 452
*/

#ifndef VIGENRE_H
#define VIGENRE_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include "CipherInterface.h"

using namespace std;

class Vigenre : public CipherInterface
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
	* Setup the vectors in this header file using parameter
	* @param text - the plaintext from encrypt, or ciphertext from decrypt
	*/
	void setupVectors(const string& text);

	/**
	* Ready the result for output.
	*/
	string readyResult();

	/* The protected members */
protected:
	vector<int> vectorKey;
	vector<int> vectorKeyLong;
	vector<int> vectorInput;
	vector<int> vectorOutput;
	int keyLength;
	int inputLength;
};
#endif