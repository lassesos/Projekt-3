#include <iostream>
#include "databaseclass.h"
#include <vector>
#include "Trie.h"
using namespace std;

int main()
{
	Trie mytrie;

	std::vector<profile> mydata;
	databaseclass mydatabase;
	mydatabase.addprofile("kasper", 1);
	mydatabase.addprofile("lasse", 3);
	mydatabase.addprofile("enj", 5);
	mydatabase.addprofile("enja", 6);
	mydatabase.addprofile("kasper", 4);

	mydatabase.deleteprofile("enj");

	mydata = mydatabase.readfile();

	for (size_t i = 0; i < mydata.size(); i++)
	{
		mytrie.insert(mydata[i].name, mydata[i].slices);
	}

	int testint = 0;
	string A;
	cout << "Hvilken bruger onsker de at finde?\n";
	cin >> A;
	cout << mytrie.search(A, testint) << endl << testint << endl;


	return 0;
}
