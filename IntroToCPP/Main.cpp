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

bool sort(int[])
{

} //sort

int main()
{
	fizzBuzz();
	return 17;
} //main