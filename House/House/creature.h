#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Creature {
	public:
		virtual string type() = 0;
		virtual bool IsPerson() = 0; // 0 - animal, 1 - person
		void out() {
			cout << "    Type: " << type() << endl;
		};
};

class Person :public Creature {
	char gender;
public:
	Person();
	bool IsPerson() { return 1; };
	string type();
};

class Animal :public Creature {
	char kind;
public:
	Animal();
	bool IsPerson() { return 0; };
	string type();
};