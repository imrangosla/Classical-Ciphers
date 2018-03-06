#ifndef HILL_H
#define HILL_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CipherInterface.h"

using namespace std;

/**
* This class implements the playfair cipher.
* The class extends the abstract class
* CipherInterface.
*/

class Hill : public CipherInterface
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
	* Multiplies two vectors using matrix multiplication
	* @param vector<int> - matrix to multiply hillkey by
	* @return - dot product vector
	*/
	vector<int> martrixMult(vector<int>);

	/* The protected members */
protected:
	vector<vector<int> >hillKey;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";


};

#endif
#pragma once

