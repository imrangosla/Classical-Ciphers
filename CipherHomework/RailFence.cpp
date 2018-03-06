#include "RailFence.h"
#include <iostream>
#include <string>
#include <algorithm>

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

	string cleartext = plaintext;
	cleartext.erase(remove(cleartext.begin(), cleartext.end(), '\0'), cleartext.end());
	cleartext.erase(remove(cleartext.begin(), cleartext.end(), '\n'), cleartext.end());

	int row = key;
	int col = (cleartext.length() / key);

	if ((cleartext.length() % key) > 0) {
		col += 1;
	}

	//dynamic creation of a 2 dimentional vector 
	vector<vector<char> >rail(row, vector<char>(col));
			
	//nested for loop to load plaintext into rail vector

	int k = 0;
	while(k < (row * col)){

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < key; j++) {
				if(k >= cleartext.length()){
					rail[j][i] = '*';
					k++;
				}
				else{
				rail[j][i] = cleartext[k];
				k++;
				}
			}
		}
	}


	//nested loop to write out encrypted message for returning
	int g = 0;
	while(g < (row * col)){
		for (int i = 0; i < key; i++) {
			for (int j = 0; j < col; j++) {
				if(rail[i][j] == '*')
					g++;
				else{
				result += rail[i][j];		
				g++;
				}
			}
		}
	}
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

	string cyphertext = cipherText;
	cyphertext.erase(remove(cyphertext.begin(), cyphertext.end(), '\0'), cyphertext.end());
        cyphertext.erase(remove(cyphertext.begin(), cyphertext.end(), '\n'), cyphertext.end());

	int row = key;
	int col = (cyphertext.length() / key);
	bool extraCol = false;

	if ((cyphertext.length() % key) > 0) {
		col += 1;
		extraCol = true;
	}
	//dynamic creation of a 2 dimentional vector 
	vector<vector<char> >rail(row, vector<char>(col));

	//nested loop to load ciphertext into rail vector
	int k = 0; //string iterator
	int x = 0; //rail iterator
	 while(k + x < (row * col)){

                for (int i = 0; i < key; i++) {
                        for (int j = 0; j < col; j++) {
				if (extraCol){	
                               		 if(i >= (cyphertext.length() % key) && j == col-1){
						rail[i][j] = '*';
						x++;
                               		 }
					 else{
						rail[i][j] = cyphertext[k];
						k++;
       					}
				}
                                else{
                                rail[i][j] = cyphertext[k];
                                k++;
                                }
                        }
                }
        }

	int g = 0;
	while(g < (row * col)){
                for (int i = 0; i < col; i++) {
                        for (int j = 0; j < key; j++) {
                                if(rail[j][i] == '*')
                                        g++;
                                else{
                                result += rail[j][i];
                                g++;
                                }
                        }
                }
        }

	return result;
}
