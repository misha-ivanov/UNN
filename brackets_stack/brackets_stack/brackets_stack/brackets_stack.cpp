#include <iostream>
#include "string.h"
#include "stack.h"

using namespace std;

bool Brackets();

int main() {

	Brackets();

	return 0;
}

bool Brackets() {
	string line;
	Stack<char> storage;
	int i = 0;
	cout << "Enter a combination of brackets (possible symbols are (){}[]<>):";
	cin >> line;
	while (line[i] != '\0') {
		switch (line[i]) {
		case '(':
			storage.push('(');
			break;
		case '{':
			storage.push('{');
			break;
		case '[':
			storage.push('[');
			break;
		case '<':
			storage.push('<');
			break;
		case ')':
			if (!storage.IsEmpty() && storage.Top() == '(')
				storage.pop();
			else {
				cout << endl << "Expression is wrong!";
				return false;
			}
			break;
		case '}':
			if (!storage.IsEmpty() && storage.Top() == '{')
				storage.pop();
			else {
				cout << endl << "Expression is wrong!";
				return false;
			}
			break;
		case ']':
			if (!storage.IsEmpty() && storage.Top() == '[')
				storage.pop();
			else {
				cout << endl << "Expression is wrong!";
				return false;
			}
			break;
		case '>':
			if (!storage.IsEmpty() && storage.Top() == '<')
				storage.pop();
			else {
				cout << endl << "Expression is wrong!";
				return false;
			}
			break;
		default:
			cout << endl << "Expression is wrong!";
			return false;
		}
		i++;
	}
	if (storage.IsEmpty()) {
		cout << endl << "Expression is correct!";
		return true;
	}
	cout << endl << "Expression is wrong!";
	return false;
}