#pragma once
#include <string>
#include <vector>

struct profile
{
	std::string name;
	int slices;
};

class databaseclass
{
public:
	databaseclass();
	std::vector<profile> readfile();
	void addprofile(std::string name, int slices);
	void deleteprofile(std::string name);
private:
	std::vector<profile> profiles;
	std::string txtname = "database.txt";
	const std::string DELIMITERS = ":";
	void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters);
};

