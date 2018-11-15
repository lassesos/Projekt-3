#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <string>

#include "RPI.h"




int numSlices()
{
	int choice;
	std::cout << "V\x91lg antal slices, et lige tal op til 12" << std::endl;

	std::cin >> choice;

	switch (choice) {

case 2:
	std::cout << "sk\x91rer i 2 slices" << std::endl;

	//hovedMenu();
	return 0;
case 4:
	std::cout << "sk\x91rer i 4 slices" << std::endl;

	return 0;

case 6:
	std::cout << "sk\x91rer i 6 slices" << std::endl;

	return 0;

case 8:
	std::cout << "sk\x91rer i 8 slices" << std::endl;

	return 0;

case 10:
	std::cout << "sk\x91rer i 10 slices" << std::endl;

	return 0;

case 12:
	std::cout << "sk\x91rer i 12 slices" << std::endl;

	return 0;


default:

	std::cout << "forkert antal indtastet, pr\x9Bv igen" << std::endl;

	numSlices();

	return 0;
}
}

void hovedMenu() {

	std::cout << "Dette er hovedmenuen \n";

	int mainChoice;

	std::cout << "Tryk 1 for at v\x91lge antallet af slices \n"<<"Tryk 0 for at afslutte" <<std::endl;

	std::cin >> mainChoice;

	if (mainChoice == 1)
	{
		numSlices();
	}
	else if (mainChoice == 0) {

		std::cout << "Programmet afsluttes" << std::endl;

	}
}

int main()

{
	
	std::cout << "Velkommen til Pizzamaskinen" << std::endl;

	hovedMenu();

	//numSlices();


	return 0;
}
