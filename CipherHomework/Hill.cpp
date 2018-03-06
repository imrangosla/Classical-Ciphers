#include "Hill.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Hill::setKey(const string& key)
{
	int size = stoi(key);

	if (!isdigit(key[0]))
		return false;
	
	int value = 0;
	cout << "Input Key Matrix (" << size << "x" << size << "): ";

	for (size_t i = 0; i < size; i++)
	{
		vector<int> row;
		for (size_t j = 0; j < size; j++)
		{
			cin >> value;
			row.push_back(value);
		}
		hillKey.push_back(row);
	}

	return true;
}




/**
* Encrypts a plaintext string
* @param plaintext - the plaintext string
* @return - the encrypted ciphertext string
*/
string Hill::encrypt(const string& plaintext)
{
	string cleartext = plaintext;
	string result;
	
	int k = 0;
	int size = hillKey.size();

	srand(time(NULL));

	while (k < cleartext.size())
	{
		vector<int> vec;

		for (size_t i = 0; i < size; i++)
		{
			if (i + k < cleartext.size())
				vec.push_back(int(cleartext[i + k] - 97) % 26);
			else
				vec.push_back(rand() % 26);
			
		}

		vector<int> solution = martrixMult(vec);

		for (size_t i = 0; i < size; i++)
			result += char(solution[i] % 26 + 97);

		k += size;
	}
	

	return result;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Hill::decrypt(const string& cipherText)
{
	string cyphertext = cipherText;
	string result;

	int k = 0;
	float determinant = 0;
	int size = hillKey.size();

	for (size_t i = 0; i < size; i++)
	{
		//determinant += (hillKey[0][i] * (hillKey[1][(i+1)%size] *)
	}

	return result;

}

/**
* Multiplies two vectors using matrix multiplication
* @param vector<int> - matrix to multiply hillkey by
* @return - dot product vector
*/
vector<int> Hill::martrixMult(vector<int> vec)
{
	int size = hillKey.size();
	vector<int>result(size,0);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			result[i] += hillKey[i][j] * vec[j];
		}
	}

	return result;
}
