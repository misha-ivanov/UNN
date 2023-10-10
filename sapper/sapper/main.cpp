#include <iostream>

void Sapper();

int main() {

	Sapper();

	return 0;
}

void Sapper() {
	int m, n, k, i, j, tmp;// m -strings, n - columns, k - mines; i, j, tmp - counters
	std::cout << "Enter size of field (number of strings and column) and number of mines" << std::endl; //data of field
	std::cin >> m >> n >> k;

	char** field = new char* [m];//creating field
	for (i = 0; i < m; i++)
		field[i] = new char[n];
	
	for (i = 0; i < m; i++)//initialization
		for (int j = 0; j < n; j++)
			field[i][j] = '0';

	std::cout << "Enter mines coordinates, please:" << std::endl;//filling of mines
	for (tmp = 0; tmp < k; tmp++) {
		std::cout << "Mine #" << tmp + 1 << ": " << std::endl;
		std::cin >> i >> j;
		i--;
		j--;
		field[i][j] = '*';

	if ((i > 0) && (i < m - 1)) {//comparing of strings
			if(field[i - 1][j] != '*')
				field[i - 1][j]++;
			if (field[i + 1][j] != '*')
				field[i + 1][j]++;

			if ((j > 0) && (j < n - 1)) {//comparing of columns
				if ((field[i - 1][j - 1] != '*') & (field[i - 1][j + 1] != '*') && (field[i][j - 1] != '*') && (field[i][j + 1] != '*') && (field[i + 1][j - 1] != '*') && (field[i + 1][j + 1] != '*')) {
					field[i - 1][j - 1]++;
					field[i - 1][j + 1]++;
					field[i][j - 1]++;
					field[i][j + 1]++;
					field[i + 1][j - 1]++;
					field[i + 1][j + 1]++;
				}
				else {
					if (field[i - 1][j - 1] != '*')
						field[i - 1][j - 1]++;
					if (field[i - 1][j + 1] != '*')
						field[i - 1][j + 1]++;
					if (field[i][j - 1] != '*')
						field[i][j - 1]++;
					if (field[i][j + 1] != '*')
						field[i][j + 1]++;
					if (field[i + 1][j - 1] != '*')
						field[i + 1][j - 1]++;
					if (field[i + 1][j + 1] != '*')
						field[i + 1][j + 1]++;
				}
			}
			else {//exceptions of columns
				if (j == n - 1) {
					if (field[i - 1][j - 1] != '*')
						field[i - 1][j - 1]++;
					if (field[i][j - 1] != '*')
						field[i][j - 1]++;
					if (field[i + 1][j - 1] != '*')
						field[i + 1][j - 1]++;
				}
				if (j == 0) {
					if (field[i - 1][j + 1] != '*')
						field[i - 1][j + 1]++;
					if (field[i][j + 1] != '*')
						field[i][j + 1]++;
					if (field[i + 1][j + 1] != '*')
						field[i + 1][j + 1]++;
				}
					
			}
		}
		else {//exceptions of strings
			if (i == m - 1){
				if (field[i - 1][j] != '*')
					field[i - 1][j]++;

				if ((j > 0) && (j < n - 1)) {//comparing of columns
					if ((field[i - 1][j - 1] != '*') && (field[i - 1][j + 1] != '*') && (field[i][j - 1] != '*') && (field[i][j + 1] != '*')) {
						field[i - 1][j - 1]++;
						field[i - 1][j + 1]++;
						field[i][j - 1]++;
						field[i][j + 1]++;
					}
					else {
						if (field[i - 1][j - 1] != '*')
							field[i - 1][j - 1]++;
						if (field[i - 1][j + 1] != '*')
							field[i - 1][j + 1]++;
						if (field[i][j - 1] != '*')
							field[i][j - 1]++;
						if (field[i][j + 1] != '*')
							field[i][j + 1]++;
					}
				}
				else {//exceptions of columns
					if (j == n - 1) {
						if (field[i - 1][j - 1] != '*')
							field[i - 1][j - 1]++;
						if (field[i][j - 1] != '*')
							field[i][j - 1]++;
					}
					if(j == 0) {
						if (field[i - 1][j + 1] != '*')
							field[i - 1][j + 1]++;
						if (field[i][j + 1] != '*')
							field[i][j + 1]++;
					}
				}
			}
			if (i == 0) {
				if (field[i + 1][j] != '*')
					field[i + 1][j]++;

				if ((j > 0) && (j < n - 1)) {//comparing of columns
					if ((field[i][j - 1] != '*') && (field[i][j + 1] != '*') && (field[i + 1][j - 1] != '*') && (field[i + 1][j + 1] != '*')) {
						field[i][j - 1]++;
						field[i][j + 1]++;
						field[i + 1][j - 1]++;
						field[i + 1][j + 1]++;
					}
					else {
						if (field[i][j - 1] != '*')
							field[i][j - 1]++;
						if (field[i][j + 1] != '*')
							field[i][j + 1]++;
						if (field[i + 1][j - 1] != '*')
							field[i + 1][j - 1]++;
						if (field[i + 1][j + 1] != '*')
							field[i + 1][j + 1]++;
					}
				}
				else {//exceptions of columns
					if (j == n - 1) {
						if (field[i][j - 1] != '*')
							field[i][j - 1]++;
						if (field[i + 1][j - 1] != '*')
							field[i + 1][j - 1]++;
					}
					if (j == 0) {
						if (field[i][j + 1] != '*')
							field[i][j + 1]++;
						if (field[i + 1][j + 1] != '*')
							field[i + 1][j + 1]++;
					}

				}
			}
		}
	}


	for (i = 0; i < m; i++) {//output
		for (j = 0; j < n; j++)
			std::cout << field[i][j];
		std::cout << std::endl;
	}

	for (i = 0; i < m; i++)//removing
		delete[] field[i];
	delete [] field;

}