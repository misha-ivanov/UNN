#include <iostream>
#include <string>

std::string Soundex(std::string input);

int main() {
	std::string test = "ammonium";
	test = Soundex(test);
	std::cout << test;
	
	test = "implementation";
	test = Soundex(test);
	std::cout << test;

	return 0;
}

std::string Soundex(std::string input) {
	int i = 1;
	while (i < input.size()) {
		if ((input[i] == 'a') || (input[i] == 'e') || (input[i] == 'h') || (input[i] == 'i') || (input[i] == 'o') || (input[i] == 'u') || (input[i] == 'w') || (input[i] == 'y'))
		{
			input.erase(i, 1);
		}
		else
		{
			switch (input[i])
			{
			case 'b'://1
				input[i] = '1';
			case 'f':
				input[i] = '1';
			case 'p':
				input[i] = '1';
			case 'v':
			{
				input[i] = '1';
				break;
			}
			case 'c'://2
				input[i] = '2';
			case 'g':
				input[i] = '2';
			case 'j':
				input[i] = '2';
			case 'k':
				input[i] = '2';
			case 'q':
				input[i] = '2';
			case 's':
				input[i] = '2';
			case 'x':
				input[i] = '2';
			case 'z':
			{
				input[i] = '2';
				break;
			}
			case 'd'://3
				input[i] = '3';
			case 't':
			{
				input[i] = '3';
				break;
			}
			case 'l'://4
			{
				input[i] = '4';
				break;
			}
			case 'm'://5
				input[i] = '5';
			case 'n':
			{
				input[i] = '5';
				break;
			}
			case 'r'://6
			{
				input[i] = '6';
				break;
			}
			default:
				break;
			}
			i++;
		}
	}
	i = 1;
	while (i < input.size()-1)
	{
		if (input[i] == input[i + 1])
			input.erase(i + 1, 1);
		else
			i++;
	}
	if (input.size() != 4)
	{
		if (input.size() > 4)
			input.erase(4, input.size() - 4);
		else
			while (input.size() != 4)
				input = input + '0';
	}
	return input;
};