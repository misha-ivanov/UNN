#include <iostream>
#include <iomanip>

void Calendar(int n, int k);

int main(){
	int n = 4, k = 22;
	Calendar(n, k);

//	std::cout << std::setw(2) << 1 << std::setw(2) << 2;

	return 0;
}

void Calendar(int n, int k) {
	//int tmp, tmp_i;
	for (int i = 0; i < n-1; i++)//empty space
		std::cout << "___";
	for (int i = 1; i < k+1; i++) {//days
		std::cout << "_";
		/*tmp = 0;//counter of number ranks
		tmp_i = i;//clone of i
		while (tmp_i != 0) {
			tmp_i = tmp_i / 10;
			tmp++;
		}
		for (int j = 0; j < 2 - tmp; j++)
			std::cout << "_";
		tmp_i = i;
		for (int j = 0; j < tmp - 1; j++) {
			std::cout << tmp_i / 10;
			tmp_i = tmp_i % 10;
		}
		std::cout << tmp_i;*/
		if(i>9)
		std::cout << std::setw(2) << i;
		else
		{
			std::cout << "_";
			std::cout << i;
		}


		if ((i+n-1) % 7 == 0)
			std::cout << std::endl;
	}
};