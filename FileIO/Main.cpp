#include <iostream>
#include <fstream>
#include "Character.h"

bool fileIOExample()
{
	Character player;
	//player.health = 100;
	//player.damage = 15;

	char choice = ' ';

	std::cout << "Would you like to Save or Load a Character?" << std::endl << "1: Save" << std::endl << "2: Load" << std::endl;
	std::cin >> choice;

	std::fstream file;
	system("cls");

	switch (choice)
	{
	case '1': //Saving
		std::cout << "Input Player Health: ";
		std::cin >> player.health;
		std::cout << std::endl;
		std::cout << "Input Player Damage: ";
		std::cin >> player.damage;
		std::cout << std::endl;

		//Saving Start
		file.open("save.txt",std::ios::binary | std::ios::app);

		//If the file isn't open, then return
		if (!file.is_open())
			return false;
		//Send the Health and Damage into the file
		file.write((char*)&player, sizeof(Character));
		file.close();
		//Saving End
		break;

	case '2': //Load
		//Loading Start
		Character playerIn = Character();

		file.open("save.txt", std::ios::in | std::ios::binary | std::ios::_Nocreate);
		//If the file isn't open, then return
		if (!file.is_open())
			return false;

		int positionChoice = '0';
		std::cout << "Which Character would you like to load?" << std::endl
			<< "1: Character 1" << std::endl
			<< "2: Character 2" << std::endl
			<< "3: Character 3" << std::endl;
		std::cin >> positionChoice;
		positionChoice -= 1;

		//Get the Health and Damage from the file
		file.seekg(sizeof(Character) * positionChoice, std::ios::beg);
		file.read((char*)&playerIn, sizeof(Character));
		file.close();
		//Loading End

		std::cout << playerIn.health << std::endl;
		std::cout << playerIn.damage << std::endl;
		break;
	} //choice switch
} //fileIO Example

bool binaryFileExample()
{
	Character player1 = Character();
	player1.health = 100;
	player1.damage = 10;
	
	Character player2 = Character();
	player2.health = 90;
	player2.damage = 15;
	
	Character player3 = Character();
	player3.health = 110;
	player3.damage = 8;

	std::fstream file;

	//Saving Start
	file.open("datData.dat", std::ios::out | std::ios::binary);
	if (!file.is_open())
		return false;

	file.write((char*)&player1, sizeof(Character));
	file.write((char*)&player2, sizeof(Character));
	file.write((char*)&player3, sizeof(Character));
	file.close();
	//Saving End

	Character sbeve4 = Character();

	//Loading Start
	file.open("datData.dat", std::ios::in | std::ios::binary);
	if (!file.is_open())
		return false;

	file.seekg(sizeof(Character) * 2, std::ios::beg);
	file.read((char*)&sbeve4, sizeof(Character));
	std::cout << sbeve4.health << std::endl;
	std::cout << sbeve4.damage << std::endl;
	file.close();
	//Loading End

	return true;
} //binary File Example

int main()
{
	char choice = ' ';
	std::cout << "Which program are you grading?" << std::endl
		<< "1: fileIO" << std::endl
		<< "2: Binary File" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case '1':
		fileIOExample();
		break;

	case '2':
		binaryFileExample();
		break;
	}
	system("pause");

	return 0;
} //main