#include "pch.h"
#include "trie.h"
#include <fstream>
#include <iomanip>



trie::trie()
{
	for (int i = 0; i < char_size; i++)
	{
		charac[i] = NULL;
	}
	isleaf = false;
}

bool trie::isempty(trie* root)
{
	for (int i = 0; i < char_size; i++)
	{
		if (root->charac[i] != nullptr)
			return false;
	}
	return true;
}
//
//trie* trie:: *getNode(void)
//{
//	trie* root = new trie;
//	root->isleaf = false;
//
//	for (int i = 0; i < char_size; i++)
//		pNode->charac[i] = NULL;
//
//	return pNode;
//}

void trie::insert(trie *root, string key)
{
	trie *p1 = root;


	for (int i = 0; i < key.size(); i++)
	{
		if (isupper(key[i]) && isalpha(key[i]))
		{
			key[i] = tolower(key[i]);
		}
		//cout << "b";
		if (isalpha(key[i]))
		{
			int index = key[i] - 'a';
			if (p1->charac[index] == nullptr)
			{
				p1->charac[index] = new trie();
			}
			p1->weight++;

			p1 = p1->charac[index];
		}


	}
	p1->isleaf = true;
}

void trie::display(trie* root, char str[], int level)
{

	if (root->isleaf)
	{
		str[level] = '\0';
		cout << str << endl;
	}

	int i;
	for (i = 0; i < char_size; i++)
	{
		if (root->charac[i])
		{
			str[level] = i + 'a';
			display(root->charac[i], str, level + 1);

		}
	}
}

bool trie::search(trie *root, string search)
{
	for (int i = 0; i < search.length(); i++)
	{
		if (isupper(search[i]))
		{
			search[i] = tolower(search[i]);
		}
	}
	trie* curr = root;
	for (int i = 0; i < search.length(); i++)
	{
		int index = search[i] - 'a';
		if (curr->charac[index] == nullptr)
			return false;

		curr = curr->charac[index];
	}


	return curr->isleaf;
}

trie* trie::erase(trie* root, string key, int depth)
{
	if (!root)
		return NULL;

	for (int i = 0; i < key.length(); i++)
	{
		if (isupper(key[i]))
		{
			key[i] = tolower(key[i]);
		}
	}

	if (depth == key.size())
	{
		if (root->isleaf)
			root->isleaf = false;

		if (isempty(root))
		{
			delete (root);
			root = NULL;
		}

		return root;
	}

	int index = key[depth] - 'a';
	root->charac[index] = erase(root->charac[index], key, depth + 1);

	if (isempty(root) && root->isleaf == false)
	{
		delete (root);
		root = NULL;
	}

	return root;
}


void trie::readfile(trie* root)
{
	ifstream in;
	string word;
	in.open("D:\\all.txt", ios::in);
	////assert(!in.fail());
	in >> word;
	unsigned long count = 1;
	//cout << word;
	//root->insert(root,test);
	while (!in.eof())
	{
		root->insert(root, word);
		in >> word;
		count++;
	}

	in.close();
	cout << "count = " << count << endl;
}

void trie::calweight(trie* root, char x)
{
	trie* p1 = root;
	p1 = p1->charac[x - 'a'];
	//cout << p1->weight;
}

bool trie::isLastNode(trie* root)
{
	for (int i = 0; i < char_size; i++)
		if (root->charac[i])
			return 0;
	return 1;
}
//
void trie::autocomplete(trie * root, string currprefix)
{

	if (root->isleaf)
	{
		cout << currprefix;

		cout << endl;
	}

	if (isLastNode(root))
		return;

	for (int i = 0; i < char_size; i++)
	{
		if (root->charac[i])
		{
			currprefix.push_back(97 + i);
			autocomplete(root->charac[i], currprefix);
			currprefix.pop_back();
		}
	}
}

int trie::printAutoSuggestions(trie* root, const string query)
{
	trie* pCrawl = root;

	// Check if prefix is present and find the 
	// the node (of last level) with last character 
	// of given string. 
	int level;
	int n = query.length();
	for (level = 0; level < n; level++)
	{
		int index = CHAR_TO_INDEX(query[level]);

		// no string in the Trie has this prefix 
		if (!pCrawl->charac[index])
			return 0;

		pCrawl = pCrawl->charac[index];
	}

	// If prefix is present as a word. 
	bool isWord = (pCrawl->isleaf == true);

	// If prefix is last node of tree (has no 
	// children) 
	bool isLast = isLastNode(pCrawl);

	// If prefix is present as a word, but 
	// there is no subtree below the last 
	// matching node. 
	if (isWord && isLast)
	{
		cout << query << endl;
		return -1;
	}

	// If there are are nodes below last 
	// matching character. 
	if (!isLast)
	{
		string prefix = query;
		autocomplete(pCrawl, prefix);
		return 1;
	}
}

//void trie::graphAux(trie* root,int indent)
//{
//	int i = 0;
//	if (root != 0)
//	{
//		trie* p1 = root;
//		while (i < 26)
//		{
//			graphAux(root->charac[i], indent + 8);
//			cout << setw(indent) << charac[i] << endl;
//			i++;
//		}
//
//
//	}
//
//}
