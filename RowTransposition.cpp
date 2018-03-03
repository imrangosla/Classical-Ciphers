#include "RowTransposition.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool RowTransposition::setKey(const string& key)
{
  if (!(isdigit(key[0])))  //check if first char is a digit
  {			
	  return false;
  }
  else 
  {	
	this->keylength = key.length();
	this->key = key;
  }
}




/**
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string RowTransposition::encrypt(const string& plaintext)
{
	int rows;
	int cols = this->keylength;
	int pLength = plaintext.length();
	string text = plaintext;
	string ciphertext = "";
	

	char cipherChar;
	char textTest;


	rows = pLength / cols;

	if ((pLength % (cols)) != 0) 
	{
		rows++;
	}		
	
	vector<vector<char> >cipherMatrix(rows, vector<char>(cols));

	//populate the matrix
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cipherMatrix[i][j] = '#';
		}
	}

	int counter = 0;
	for (int i = 0; i < rows; i++)							
	{
		for (int j = 0; j < cols && (counter < pLength); j++)
		{
			//textTest = text[counter];			*used for debugging
			{
				cipherMatrix[i][j] = text[counter];
			}
			counter++;
		}
	}


	vector<int> keyArr(keylength, 0);
	//create an array with the key

	for (int k = 0; k < keylength; k++)		
	{
		keyArr[k] = this->key[k];
	}




//print *used for debugging purposes*
	for (int i = 0; i < rows; i++)
	{
		cout << "\n";
		for (int j = 0; j < cols; j++)
		{
			cout << cipherMatrix[i][j] << " ";
		}
	}



	int currKeyLoc;
	//concatenate into one long string
	for (int i = 0; i < keylength; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			currKeyLoc = (int)(keyArr[i]) - 49;
			cipherChar = cipherMatrix[j][currKeyLoc];
			ciphertext = ciphertext + cipherChar;
		}
	}

	return ciphertext;
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const string& cipherText)
{
	int cols = this->keylength;
	int rows = cipherText.length() / cols;
	string decryptedText = "";
	char cipherChar;
	
	if ((cipherText.length() % cols) != 0)
	{
		rows++;
	}

	//create an array with the key as ints
	vector<int> keyArr(keylength, 0);
	for (int k = 0; k < keylength; k++)
	{
		keyArr[k] = this->key[k];
	}


	vector<vector<char> >cipherMatrix(rows, vector<char>(cols));
	int counter = 0;
	for (int i = 0; (i < cols) && (counter < cipherText.length()); i++)
	{
		for (int j = 0; j < rows; j++)
		{
			
			cipherMatrix[j][i] = cipherText[counter];
			counter++;
		}
	}



	int keyArrCounter;
	int keyAtIndex;

	vector<vector<char> >decipheredMatrix(rows, vector<char>(cols));
	for (int i = 0; i < cols; i++)
	{
		keyArrCounter = 0;
		bool found = false;
		while (!found)
		{
			keyAtIndex = keyArr[keyArrCounter] - 48;
				if ((keyAtIndex) == (i+1))
				{
					found = true;
					for (int j = 0; j < rows; j++)
					{
						decipheredMatrix[j][i] = cipherMatrix[j][keyArrCounter];
					}
				}
				else
				{
					keyArrCounter++;
				}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cipherChar = decipheredMatrix[i][j];
			if (cipherChar == '#')
			{
				cipherChar = '\0';
			}
			decryptedText = decryptedText + cipherChar;
		}
	}

	return decryptedText;

}
