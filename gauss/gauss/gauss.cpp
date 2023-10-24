#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;


void PrintMatrix(double** _matrix, int _N, double* _x, double* _y, int* _equation); //print matrix
void MatrixToDefaultForm(double** _matrix, int _N, double* _x, double* _y, int* _equation); //sort equations from 1 to N

int main() {
	srand(time(NULL));

	int N, tmp_j; //N - size, max - max elem in the column, tmp_p - settle of tmp pointer
	double max, tmp_double;//max - max elem in the column
	double* tmp_p;//tmp_p - tmp pointer
	cin >> N;

	//memory
	double** matrix = new double* [N];
	for (int i = 0; i < N; i++)
		matrix[i] = new double[N];
	double* y = new double[N];
	double* x = new double[N];
	int* equation = new int[N];

	//matrix creating
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = rand() % 21 - 10;
		}
	}

	//y creating
	for (int i = 0; i < N; i++)
		y[i] = rand() % 21 - 10;

	//x creating
	for (int i = 0; i < N; i++)
			x[i] = 0;

	//equation creating
	for (int i = 0; i < N; i++)
		equation[i] = i+1;

	PrintMatrix(matrix, N, x, y, equation); // print primal matrix

	for (int i = 0; i < N; i++) {
		max = abs(matrix[i][i]);//finding max
		tmp_j = i;
		for (int j = i+1; j < N; j++) {
			if (abs(matrix[j][i]) > max) {
				max = abs(matrix[j][i]);
				tmp_j = j;
			}
		}
		if (tmp_j != i) {
			tmp_p = matrix[i];//swipe lines
			matrix[i] = matrix[tmp_j];
			matrix[tmp_j] = tmp_p;
			tmp_double = y[i];//swipe lines y
			y[i] = y[tmp_j];
			y[tmp_j] = tmp_double;
			tmp_double = x[i];//swipe lines x
			x[i] = x[tmp_j];
			x[tmp_j] = tmp_double;
			tmp_double = equation[i];//swipe lines equation 
			equation[i] = equation[tmp_j];
			equation[tmp_j] = tmp_double;
		}
		for (int j = i+1; j < N; j++) {
			tmp_double = (matrix[j][i] / matrix[i][i]);
		for (int k = i; k < N; k++)
			matrix[j][k] = floor((matrix[j][k] - matrix[i][k] * tmp_double)*1000)/1000;
		y[j] =floor(( y[j] - y[i]*tmp_double)*1000)/1000;
		}
	}

	for (int i = N-1; i > -1; i--) {//searchig x
		x[i] = y[i] / matrix[i][i];
		for (int j = 0; j < i; j++) {
			y[j] = y[j] - x[i] * matrix[j][i];
		}
	}


	PrintMatrix(matrix, N, x, y, equation);

	MatrixToDefaultForm(matrix, N, x, y, equation);

	PrintMatrix(matrix, N, x, y, equation);

	return 0;
}


void PrintMatrix(double** _matrix, int _N, double* _x, double* _y, int* _equation) {
	for (int i = 0; i < _N; i++) {
		cout << "equation #"<< setw(3) << _equation[i] << ":  ";
		for (int j = 0; j < _N; j++) {
			cout << left << setw(7) << setprecision(4) << _matrix[i][j] << "  ";
		}
		cout << left << "|" << left << setw(7) << setprecision(4) << _x[i] << " |" << left << setw(7) << setprecision(4) << _y[i] << endl;
	}
	cout << endl;
}


void MatrixToDefaultForm(double** _matrix, int _N, double* _x, double* _y, int* _equation) {
	double* tmp_p;
	int tmp_j;
	double tmp_double;
	for (int i = 0; i < _N; i++) {
		if (_equation[i] - 1 != i) {
			for (int j = i + 1; j < _N; j++)
				if (_equation[j] - 1 == i)
					tmp_j = j;
			tmp_p = _matrix[i];//swipe lines
			_matrix[i] = _matrix[tmp_j];
			_matrix[tmp_j] = tmp_p;
			tmp_double = _y[i];//swipe lines y
			_y[i] = _y[tmp_j];
			_y[tmp_j] = tmp_double;
			tmp_double = _x[i];//swipe lines x
			_x[i] = _x[tmp_j];
			_x[tmp_j] = tmp_double;
			tmp_double = _equation[i];//swipe lines equations 
			_equation[i] = _equation[tmp_j];
			_equation[tmp_j] = tmp_double;
		}
	}
}
