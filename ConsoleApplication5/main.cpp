// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "trie.h"
#include <iostream>
#include <fstream>


int main()
{
	trie *root = new trie();
	string key;
	string search;
	string remove;
	int choose = 0;
	int level = 0;
	char str[20];

	do
	{
		cout << "Choose: " << endl;
		cout << "1)Insert key." << endl;
		cout << "2)Erase key." << endl;
		cout << "3)Search for a key." << endl;
		cout << "4)Display." << endl;
		cout << "5)Auto-Complete." << endl;
		cout << "6)Exit." << endl;
		cin >> choose;

		if (choose == 1)
		{
			//cout << "Enter key or -1 to exit: ";
			//cin >> key;

			//while (key != "-1")
			//{
			//	root->insert(root, key);
			//	cin >> key;
			//}
			root->readfile(root);
			root->calweight(root, 'a');
		}

		else if (choose == 2)
		{
			cout << "Enter string to remove or press -1 to exit : ";
			cin >> remove;
			while (remove != "-1")
			{
				root->erase(root, remove);
				cin >> remove;
			}

		}

		else if (choose == 3)
		{
			cout << "Enter search: ";
			cin >> search;

			while (search != "-1")
			{
				if (root->search(root, search))
				{
					cout << "Key is found. " << endl;
				}
				else cout << "Key is not found. " << endl;

				cout << "Enter search: ";
				cin >> search;


			}
		}

		else if (choose == 4)
		{
			if (root->isempty(root))
				cout << "Trie is empty" << endl;
			else
			{
				cout << "Content of tree is: " << endl;
				cout << endl;
				root->display(root, str, level);
				cout << endl;
			}
		}
		else if (choose == 5)
		{
			string query;
			cout << "Enter Prefix: " << endl;
			cin >> query;
			root->printAutoSuggestions(root, query);
		}

	} while (choose != 6);


}

/*Run program: Ctrl + F5 or Debug > Start Without Debugging menu
Debug program: F5 or Debug > Start Debugging menu

Tips for Getting Started:
  1. Use the Solution Explorer window to add/manage files
  2. Use the Team Explorer window to connect to source control
  3. Use the Output window to see build output and other messages*/
  //   4. Use the Error List window to view errors
  //   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
  //   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
