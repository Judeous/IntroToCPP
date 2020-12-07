#include <iostream>

void fizzBuzz()
{
	std::cout << "Input a number:" << std::endl;
	int num = 0;
	std::cin >> num;

	std::cout << num << std::endl;

	for (int i = 0; i <= num; i++)
	{
		if (i % 3 == 0 && i % 5 == false)
			std::cout << i << " fizzbuzz" << std::endl;
		else if (i % 3 == false)
			std::cout << i << " fizz" << std::endl;
		else if (i % 5 == 0)
			std::cout << i << " buzz" << std::endl;
	} //For every number from zero to the input
	system("pause");
} //fizzBuzz

void guessGame()
{
	std::cout << "Think of a number" << std::endl;
	system("pause");

	//Gets the maximum
	std::cout << "Input a number that is great than this number you thought of: ";
	int max = 10;
	std::cin >> max;

	std::cout << std::endl;

	//Gets the minimum
	std::cout << "Input a number that is less than this number you thought of: ";
	int min = 0;
	std::cin >> min;

	system("cls");

	char yayOrNay = ' '; bool cheating = 0;
	do
	{
		int guess = (min + max) / 2;
		do //Gets whether or not guess is the User's number
		{
			system("cls");
			std::cout << "Is " << guess << " your number?" << std::endl;
			std::cout << "1: Yes" << std::endl << "2: No, my number is higher" << std::endl << "3: No, my number is lower" << std::endl;
			std::cin >> yayOrNay;
		} while (yayOrNay != '1' && yayOrNay != '2' && yayOrNay != '3');

		switch (yayOrNay)
		{
		case '1':
			if (guess == 69)
				std::cout << "Nice" << std::endl;
			else ("Oh, look; I got it");
			break;

		case '2':
			if (guess + 1 > max)
			{
				std::cout << "Impossible. Either you've changed your number or lied." << std::endl;
				cheating = 1;
				break;
			} //If cheating
			min = guess;
			break;

		case '3':
			if (guess - 1 < min)
			{
				std::cout << "Impossible. Either you've changed your number or lied." << std::endl;
				cheating = 1;
				break;
			} //If cheating

			max = guess;
			break;
		} //yayOrNay switch
	} while (yayOrNay != '1' && cheating == 0);
} //guessGame

int main()
{
	guessGame();

	system("pause");
	return 17;
} //main