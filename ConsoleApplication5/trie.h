#pragma once

#ifndef TRIE
#define TRIE

#include <iostream>
#include <string>
#include <assert.h>


using namespace std;


const int char_size = 26;
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

class trie
{
private:
	bool isleaf;
	bool endofword;
	trie* charac[char_size];
	unsigned long weight = 0;

public:
	trie();
	bool isempty(trie *root);
	bool isLastNode(trie* root);
	void insert(trie *root, string key);
	void display(trie* root, char std[], int level);
	bool search(trie *root, string search);
	trie* erase(trie *root, string key, int depth = 0);
	void readfile(trie* root);
	void calweight(trie* root, char x);
	void autocomplete(trie* root, string currprefix);
	int printAutoSuggestions(trie* root, const string query);
	/*void graphAux(trie* root, int indent);*/

};


#endif 
