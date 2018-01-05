/**
* Implements a spell-checker.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <clocale>

using namespace std;

#include "BinaryTree.h"

const int LENGTH = 45;

int main()
{
	BinaryTree<string> *tree = new BinaryTree<string>;

	// open text file to read
	string text;
	cout << "Enter text filename: ";
	cin >> text;
	ifstream fp;
	fp.open(text);

	// open text file to write words and frequency
	ofstream ofp;
	ofp.open("results.txt");

	// prepare to spell-check
	int index = 0, misspellings = 0, words = 0;
	char word[LENGTH + 1];
	char c;

	// spell-check each word in text
	for (fp.get(c); !fp.eof(); fp.get(c))
	{
		// allow only alphabetical characters and apostrophes
		if (isalnum((unsigned char) c))
		{
			// append character to word
			word[index] = tolower(c);
			index++;
		}
		// found a whole word
		else if (index > 0)
		{
			// terminate current word
				word[index] = '\0';

			tree->insertNode(word);

			index = 0;
		}
	}
	// prepare to report misspellings
	cout << "\nWORD FREQUENCY\n\n";

	tree->displayInOrder();

	// Close text
	fp.close();

	// Unload dictionary
	delete tree;
}