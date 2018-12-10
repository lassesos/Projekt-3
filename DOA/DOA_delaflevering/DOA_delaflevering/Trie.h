#pragma once
#include <map>
#include <vector>

using namespace std;

class Trie
{
	class TrieNode;

	typedef map<char, TrieNode*> TrieMap;
	typedef map<char, TrieNode*>::iterator TrieMapIter;

	// Internal TrieNode class - not relevant outside Trie
	class TrieNode
	{
	public:
		TrieNode(char c = '\0', bool cw = false, TrieNode* p = nullptr) :
			val(c), parent(p), completesWord(cw)
		{
			children.clear();
		}

		char val;
		int slices;
		TrieNode* parent;
		bool completesWord;
		TrieMap children;
	};



public:
	Trie()
	{
		root = new TrieNode('\0', true);
	}


	~Trie()
	{

	}


	void insert(string str, int slice) const
	{
		// YOUR CODE GOES HERE
		TrieNode* end_;


		unsigned int searchnr = findPrefixEnd(str, end_);

		if (searchnr == str.length())
		{
			end_->slices = slice;
			end_->completesWord = true;
		}
		else
		{
			for (unsigned int i = searchnr; i < str.length(); i++)
			{
				TrieNode* nextchild = new TrieNode(str[i], false, end_);

				end_->children[str[i]] = nextchild;
				end_ = nextchild;
			}
			end_->slices = slice;
			end_->completesWord = true;
		}

	}


	bool search(string str, int& searchInt) const
	{
		// YOUR CODE GOES HERE
		TrieNode* end_;

		unsigned int searchnr = findPrefixEnd(str, end_);

		if (searchnr < str.length() || end_->completesWord == false)
		{
			return false;
		}
		else
		{
			searchInt = end_->slices;
			return true;
		}
	}


	void remove(string str) const
	{
		// YOUR CODE GOES HERE
		TrieNode* end_;

		unsigned int searchnr = findPrefixEnd(str, end_);

		if (searchnr != str.length())
		{
			return;
		}

		end_->completesWord = false;

		while (true)
		{
			if (end_->children.empty() && end_->completesWord == false && end_ != root)
			{
				TrieNode* newparent = end_->parent;
				end_->parent->children.erase(end_->val);
				delete end_;
				end_ = newparent;
			}
			else
			{
				return;
			}
		}

	}


private:

	// findPrefixEnd:
	// Sets the parameter end to the last node in the prefix of str and returns the length of the prefix
	unsigned int findPrefixEnd(string str, TrieNode*& end) const
	{
		TrieNode* cur = root;
		TrieMapIter res;
		unsigned int i = 0;

		// Find (part of) key already in trie
		for (; i < str.length(); i++)
		{
			if ((res = cur->children.find(str[i])) != cur->children.end())
			{
				cur = res->second;
			}
			else break;
		}

		end = cur;
		return i;
	}


	TrieNode* root;
};
#pragma once
