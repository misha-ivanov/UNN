#pragma once
#include <iostream>
#include <string>
#include "creature.h"
#include <stdlib.h>

using namespace std;

Person::Person() {

	int tmp;
	tmp = (int)rand() % 4;
	switch (tmp) {
	case 0: 
		gender = 'M'; // male
		break;
	case 1:
		gender = 'F'; // female
		break;
	case 2:
		gender = 'B'; // boy
		break;
	case 3:
		gender = 'G'; // girl
		break;
	default:
		break;
	}
}

string Person::type() {
	switch (gender) {
	case 'M':
		return "Male";
		break;
	case 'F':
		return "Female";
		break;
	case 'B':
		return "Boy";
		break;
	case 'G':
		return "Girl";
		break;
	default:
		break;
	}
}

Animal::Animal() {
	int tmp;
	tmp = (int)rand() % 2;
	switch (tmp) {
	case 0:
		kind = 'D'; // dog
		break;
	case 1:
		kind = 'C'; // female
		break;
	default:
		break;
	}
}

string Animal::type() {
	switch (kind) {
	case 'D':
		return "Dog";
		break;
	case 'C':
		return "Cat";
		break;
	default:
		break;
	}
}