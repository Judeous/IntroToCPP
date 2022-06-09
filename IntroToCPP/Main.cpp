#include <iostream>

void fizzBuzz()
{
	int start = 0;
	int end = 0;

	std::cout << "Input a number to start from:" << std::endl;
	std::cout << "> "; std::cin >> start;
	std::cout << "Input a number to end at:" << std::endl;
	std::cout << "> "; std::cin >> end;
	system("cls");

	for (int i = start; i <= end; i++)
	{
		std::cout << i;
		//If the number is funny
		if (i == 69 || i == 420)
			std::cout << " Nice";
		//If the number is divisible by both three and five
		if (i % 3 == 0 && i % 5 == false)
			std::cout <<" FizzBuzz";
		//If the number is divisible by only three
		else if (i % 3 == false)
			std::cout <<" Fizz";
		//If the number is divisible only by five
		else if (i % 5 == 0)
			std::cout <<" Buzz";
		std::cout << std::endl;
	} //For every number from zero to the input
	system("pause");
} //fizzBuzz

bool CheckForCheating(bool& cheating, int guess, int min, int max) {
	//If the guess being any lower or higher would be outside the bounds of possible guesses

	// Does not work

	if (guess - 1 < min || guess + 1 > max)
	{
		std::cout << "Impossible. Either you've changed your number or lied." << std::endl;
		cheating = 1;
		system("pause");
	}
	return cheating;
}

void guessGame()
{
	std::cout << "Think of a number, do not type it" << std::endl;
	system("pause");

	int max = 10;
	int min = 0;

	//re-get input while input is invalid
	do {
		system("cls");

		//Gets the maximum
		std::cout << "Input a number that is greater than your number" << std::endl;;
		std::cout << "> "; std::cin >> max;
		std::cout << std::endl;

		//Gets the minimum
		std::cout << "Input a number that is less than your number" << std::endl;
		std::cout << "> "; std::cin >> min;

		//If the maximum is less than the minimum
		if (max < min) {
			std::cout << std::endl;
			std::cout << "The maximum is less than the minimum. I'll swap them for you:" << std::endl;

			//Swap the min and max
			int tempMax = max;
			max = min;
			min = tempMax;

			std::cout << "New Maximum: " << max << std::endl;
			std::cout << "New Minimum: " << min << std::endl << std::endl;
		}
		//If the maximum and minimum are too close
		if (max == min || max - 2 <= min) {
			std::cout << "The maximum and minimum are too close." << std::endl;
		}
		system("pause");
	} while (max <= min || max - 2 <= min);

	//Wipe the screen to prevent overcrowding it
	system("cls");

	char yayOrNay = ' '; bool cheating = 0;
	do
	{
		//Guess the number in the middle of the maximum and minimum
		int guess = (min + max) / 2;

		//Gets whether or not guess is the User's number, and repeats if the input is invalid
		do {
			system("cls");
			std::cout << "Is " << guess << " your number?" << std::endl;
			std::cout << "1: Yes" << std::endl
				<< "2: No, my number is higher" << std::endl
				<< "3: No, my number is lower" << std::endl;

			std::cout << "> "; std::cin >> yayOrNay;
		} while (yayOrNay != '1' && yayOrNay != '2' && yayOrNay != '3');

		switch (yayOrNay)
		{
			//If the guess was correct
		case '1':
			//If the guess was a funny number
			switch (guess) {
			case 6942069:
			case 42069:
			case 69420:
			case 69:
			case 420:
				std::cout << "Nice" << std::endl;
				break;
			default:
				std::cout << "Oh, look; I got it" << std::endl;
				break;
			}
			system("pause");
			break;

			//If the guess was too low
		case '2':
			//Check for cheating
			if (CheckForCheating(cheating, guess, min, max))
				break;
			//Otherwise, adjust the minimum to be the guessed number 
			min = guess;
			break;

		case '3':
			//Check for cheating
			if (CheckForCheating(cheating, guess, min, max))
				break;
			//Otherwise, adjust the maximum to be the guessed number 
			max = guess;
			break;
		} //yayOrNay switch
	} while (yayOrNay != '1' && cheating == 0);
} //guessGame

int main()
{
	int retry = 0;
	int game = 0;
	//Run the game if the player wishes to re-run it, or if it's the first time running
	do {
		system("cls");

		std::cout << "What function would you like to try?" << std::endl
			<< "1: Guess Game" << std::endl
			<< "2: FizzBuzz" << std::endl
			<< "3: None" << std::endl;

		//re-get input while input is invalid
		do {
			std::cout << "> ";
			std::cin >> game;
		} while (game != 1 && game != 2 && game != 3);

		if (game == 3) {
			break;
		}

		system("cls");
		//Play the game
		if (game == 1)
			guessGame();
		else if (game == 2)
			fizzBuzz();
		else if (game == 3)
			break;

		system("cls");
		std::cout << "Would you like to continue running the program?" << std::endl
			<< "1: No" << std::endl
			<< "2: Yes" << std::endl;

		//re-get input while input is invalid
		do {
			std::cout << "> "; std::cin >> retry;
		} while (retry != 1 && retry != 2);
		
		system("cls");
	} while (retry != 1);
	return 17;
} //main
