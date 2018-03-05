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
	bool allNumbersPresent = false;
	int numberCounter = 1;

	vector<int> keyArr(key.length(), 0);
	//create an array with the key

	for (int k = 0; k < key.length(); k++)
	{
		keyArr[k] = key[k] - 48;
	}

	while (!allNumbersPresent && (numberCounter <= key.length()))		//loops until it find that all numbers in key from 1 to KeyLength are present, or if they are not present, returns false
	{
		int indexCounter = 0;
		bool found = false;
		while (indexCounter < key.length() && !found)	//search for key
		{
			if (numberCounter == keyArr[indexCounter])
			{
				found = true;
			}
			else
			{
				indexCounter++;
			}
		}
		if (!found)
		{
			//cout << "ERROR: INVALID KEY -> Missing number in key" << "\n";
			return false;
		}

		bool noDupes = true;
		if (found) //found number in key array
		{
			int j = indexCounter + 1;
			
			while (noDupes && (j < key.length()))	//searching for duplicate numbers in key array
			{
				if (numberCounter == keyArr[j])			//if a duplicate is found, return error and return false
				{
					//cout << "ERROR: INVALID KEY -> Duplicate number in key" << "\n";
					noDupes = false;
					return false;
				}
				else	//if it does not find a duplicate go to next index
				{
					j++;
				}
			}
		}
		if ((found) && (noDupes) && (numberCounter == key.length()))	//if found and the index is at the last number in key and there are no duplicate numbers 
		{
			allNumbersPresent = true;
		}
		numberCounter++;
	}

	if (allNumbersPresent)
	{
		this->keylength = key.length();
		this->key = key;
		return true;
	}

		
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

	string cleartext = plaintext;
	cleartext.erase(remove(cleartext.begin(), cleartext.end(), '\0'), cleartext.end());
	cleartext.erase(remove(cleartext.begin(), cleartext.end(), '\n'), cleartext.end());

	int pLength = cleartext.length();
	
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
				cipherMatrix[i][j] = cleartext[counter];
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
	/*for (int i = 0; i < rows; i++)
	{
		cout << "\n";
		for (int j = 0; j < cols; j++)
		{
			cout << cipherMatrix[i][j] << " ";
		}
	}*/



	int currKeyLoc;
	//concatenate into one long string
	for (int i = 0; i < keylength; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			currKeyLoc = (int)(keyArr[i]) - 49;
			cipherChar = cipherMatrix[j][currKeyLoc];
			if(cipherChar == '\n')
				cipherChar = '#';
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
	string cleartext = cipherText;
	cleartext.erase(remove(cleartext.begin(), cleartext.end(), '\0'), cleartext.end());
	cleartext.erase(remove(cleartext.begin(), cleartext.end(), '\n'), cleartext.end());

	int rows = cleartext.length() / cols;
	string decryptedText = "";
	char cipherChar;
	
	if ((cleartext.length() % cols) != 0)
	{
		rows++;
	}

	//create an array with the key as ints
	vector<int> keyArr(keylength, 0);
	for (int k = 0; k < keylength; k++)
	{
		keyArr[k] = this->key[k] - 48;
	}

	//cout << "ROWS: " << rows << "	CIPHERTEXT LEN: " << cleartext.length() << "\n";

	vector<vector<char> >cipherMatrix(rows, vector<char>(cols));
	int counter = 0;
	for (int i = 0; (i < cols) && (counter < cleartext.length()); i++)
	{

	
		for (int j = 0; j < rows; j++)
		{
				
			cipherMatrix[j][i] = cleartext[counter];
			counter++;
		}
	
	}



	int decIndex;
	int tkey;

	vector<vector<char> >decipheredMatrix(rows, vector<char>(cols));
	for (int i = 0; i < keylength; i++)
	{	

		bool found = false;
		int j = 0;
		while (!found && (j < keylength))
		{
			if (keyArr[j] == (i+1))
			{
				found = true;
				tkey = keyArr[j];
				for (int k = 0; k < rows; k++)
				{
					decipheredMatrix[k][tkey - 1] = cipherMatrix[k][j];
				}
			}
			else
			{
				j++;
			}
		}
		
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cipherChar = decipheredMatrix[i][j];
			if (cipherChar != '\n' && cipherChar != '#')
			{
				decryptedText = decryptedText + cipherChar;
			}
			
		}
	}

	return decryptedText;

}
