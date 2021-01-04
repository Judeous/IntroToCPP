#include <iostream>
#include <fstream>
#include "Character.h"

bool fileIOExample()
{
	Character player;
	player.health = 100;
	player.damage = 15;

	std::cout << "Input Player Health: ";
	std::cin >> player.health;
	std::cout << std::endl;
	std::cout << "Input Player Damage: ";
	std::cin >> player.damage;
	std::cout << std::endl;

	//Saving Start
	std::fstream file;
	file.open("save.txt", std::ios::out | std::ios::_Nocreate | std::ios::binary || std::ios::app);

	//If the file isn't open, then return
	if (!file.is_open())
		return false;
	//Send the Health and Damage into the file
	file.write((char*)&player, sizeof(Character));

	file.close();
	//Saving End

	//Loading Start
	Character playerIn = Character();

	file.open("save.txt", std::ios::in | std::ios::binary);

	//If the file isn't open, then return
	if (!file.is_open())
		return false;
	//Get the Health and Damage from the file
	file.seekg(sizeof(Character), std::ios::beg);
	file.read((char*)&playerIn, sizeof(Character));
	file.close();
	//Loading End

	std::cout << playerIn.health << std::endl;
	std::cout << playerIn.damage << std::endl;
} //fileIO Example

bool binaryFileExample()
{
	Character sbeve = Character();
	sbeve.health = 100;
	sbeve.damage = 10;
	
	Character sbeve2 = Character();
	sbeve2.health = 90;
	sbeve2.damage = 15;
	
	Character sbeve3 = Character();
	sbeve3.health = 110;
	sbeve3.damage = 8;

	std::fstream file;

	file.open("datData.dat", std::ios::out | std::ios::binary);
	if (!file.is_open())
		return false;

	file.write((char*)&sbeve, sizeof(Character));
	file.write((char*)&sbeve2, sizeof(Character));
	file.write((char*)&sbeve3, sizeof(Character));
	file.close();

	Character sbeve4 = Character();
	file.open("datData.dat", std::ios::in | std::ios::binary);
	if (!file.is_open())
		return false;

	file.seekg(sizeof(Character) * 2, std::ios::beg);
	file.read((char*)&sbeve4, sizeof(Character));
	std::cout << sbeve4.health << std::endl;
	std::cout << sbeve4.damage << std::endl;
	file.close();

	return true;
} //binary File Example

int main()
{
	fileIOExample();
	system("pause");

	return 0;
} //main