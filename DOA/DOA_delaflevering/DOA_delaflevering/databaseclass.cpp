#include "databaseclass.h"
#include <fstream>
#include <iostream>
using namespace std;

databaseclass::databaseclass()
{
	readfile();
}

std::vector<profile> databaseclass::readfile()
{
	string names;
	profiles.clear();
	std::ifstream file(txtname);

	if (!file.good()) throw "Bad filename";
	while (!file.eof())
	{

		// Read a single line
		vector<string> tokens;
		profile lineprofile;

		getline(file, names);

		tokenize(names, tokens, DELIMITERS);
		if (tokens.size() > 0)
		{
			//cout << tokens[0] << " " << tokens[1] << endl;
			lineprofile.name = tokens[0];
			lineprofile.slices = stoi(tokens[1]);
			profiles.push_back(lineprofile);

		}
	}
	return profiles;
}

void databaseclass::addprofile(std::string name, int slices)
{
	deleteprofile(name);

	std::ofstream file;
	file.open(txtname, std::ios_base::app);
	if (!file.good()) throw "Bad filename";

	file << name << ":" << slices << "\n";
}

void databaseclass::deleteprofile(std::string name)
{
	std::fstream myread(txtname);
	string names;
	string mytemp;
	if (!myread.good()) throw "Bad filename";

	while (!myread.eof())
	{

		// Read a single line
		vector<string> tokens;

		getline(myread, names);

		tokenize(names, tokens, DELIMITERS);
		if (tokens.size() > 0)
		{
			if (tokens[0] != name)
			{
				mytemp.append(tokens[0]);
				mytemp.append(":");
				mytemp.append(tokens[1]);
				mytemp.append("\n");

			}
		}


	}
	myread.close();

	std::ofstream file;
	file.open(txtname, std::ios_base::out);
	if (!file.good()) throw "Bad filename";
	file << mytemp;

}

void databaseclass::tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
{
	size_t lastPos = str.find_first_not_of(delimiters, 0);
	size_t pos = str.find_first_of(delimiters, lastPos);
	tokens.clear();

	while (string::npos != pos || std::string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
}