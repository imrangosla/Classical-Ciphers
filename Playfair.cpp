#include "Playfair.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Playfair::setKey(const string& key)
{
	string skeleton = key;

	replace(skeleton.begin(), skeleton.end(), 'j', 'i');

	if (skeleton.size() > 25 || hasRepeatingChars(skeleton))
		return false;

	int count = 0;
	string alphabet = "abcdefghiklmnopqrstuvwxyz";

	for (size_t i = 0; i < skeleton.size(); i++)
		alphabet.erase(alphabet.begin() + alphabet.find(skeleton[i]));

	string playfairMatrix = skeleton + alphabet;

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			squareKey[i][j] = playfairMatrix[count];
			count++;
		}
	}

	return true;
}




/**
* Encrypts a plaintext string
* @param plaintext - the plaintext string
* @return - the encrypted ciphertext string
*/
string Playfair::encrypt(const string& plaintext)
{
	string cleartext = plaintext;

	if (hasRepeatingChars(cleartext))
	{
		for (size_t i = 1; i < cleartext.size(); i+=2)
		{
			if (cleartext[i] == cleartext[i-1])
				cleartext.insert(i, 1, 'x');
		}
	}

	if ((cleartext.size() % 2) != 0)
		cleartext.append("x");

	string result;
	int count = 0;
	int A[2];
	int B[2];

	while (count < cleartext.size())
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (squareKey[i][j] == cleartext[count])
				{
					A[0] = i;
					A[1] = j;
				}
				if (squareKey[i][j] == cleartext[count + 1])
				{
					B[0] = i;
					B[1] = j;
				}
			}
		}

		count += 2;

		if (A[0] == B[0])
		{
			result += squareKey[A[0]][(A[1] + 1) % 5];
			result += squareKey[B[0]][(B[1] + 1) % 5];
		}
		else if (A[1] == B[1])
		{
			result += squareKey[(A[0] + 1) % 5][A[1]];
			result += squareKey[(B[0] + 1) % 5][B[1]];
		}
		else
		{
			result += squareKey[A[0]][B[1]];
			result += squareKey[B[0]][A[1]];
		}
	}
	
	return result;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Playfair::decrypt(const string& cipherText)
{
	string cyphertext = cipherText;

	string result;
	int count = 0;
	int A[2];
	int B[2];

	while (count < cyphertext.size())
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (squareKey[i][j] == cyphertext[count])
				{
					A[0] = i;
					A[1] = j;
				}
				if (squareKey[i][j] == cyphertext[count + 1])
				{
					B[0] = i;
					B[1] = j;
				}
			}
		}

		count += 2;

		if (A[0] == B[0])
		{
			result += squareKey[A[0]][(A[1] - 1) % 5];
			result += squareKey[B[0]][(B[1] - 1) % 5];
		}
		else if (A[1] == B[1])
		{
			result += squareKey[(A[0] - 1) % 5][A[1]];
			result += squareKey[(B[0] - 1) % 5][B[1]];
		}
		else
		{
			result += squareKey[A[0]][B[1]];
			result += squareKey[B[0]][A[1]];
		}
	}

	return result;

}

/**
*Helper function to find if a string has repeating characters
*@param s - string to analyze
*@return True if string contains repeating characters and False otherwise
*/
bool Playfair::hasRepeatingChars(string s)
{
	sort(s.begin(), s.end());
	auto it = unique(s.begin(), s.end());

	if (it - s.begin() == s.size())
		return false;
	
	return true;
}
