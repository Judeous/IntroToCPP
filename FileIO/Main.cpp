#include <iostream>
#include <fstream>
#include "Character.h"

int main()
{
	Character player = Character();
	player.health = 100;
	player.damage = 15;

	//Saving Start
	std::fstream file;
	file.open("save.txt", std::ios::out | std::ios::_Nocreate);

	//If the file isn't open, then return
	if (!file.is_open())
		return 1;

	file << player.health << std::endl;
	file << player.damage;

	file.close();
	//Saving End

	//Loading Start
	Character player2 = Character();

	file.open("save.txt", std::ios::in);

	//If the file isn't open, then return
	if (!file.is_open())
		return 1;

	file >> player2.health;
	file >> player2.damage;

	file.close();
	//Loading End

	std::cout << player2.health << std::endl;
	std::cout << player2.damage << std::endl;

	system("pause");

	return 0;
} //main