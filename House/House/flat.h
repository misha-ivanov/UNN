#pragma once
#include <iostream>
#include <stdlib.h>
#include "creature.h"

using namespace std;

class Flat {
	int n_residents; // number of residents
	Creature** residents; // list of residents
public:
	Flat() {
		n_residents = 0;
		residents = nullptr;
	};

	Flat(const Flat& flat) {
		n_residents = flat.n_residents;
		residents = new Creature*[n_residents];
		for (int i = 0; i < n_residents; i++)
			residents[i] = flat.residents[i];
	}

	Flat(int _n_residents) {
		n_residents = _n_residents;
		residents = new Creature * [n_residents];
		for (int i = 0; i < n_residents; i++) {
			if ((int)rand() % 4 == 0)
			{
				Creature* tmp = new Animal;
				residents[i] = tmp;
			}
			else
			{
				Person* tmp = new Person;
				residents[i] = tmp;
			}
		}
	};

	int out_n_residents() { return n_residents; };

	Creature** out_residents() { return residents; };

	void review() {
		for (int i = 0; i < n_residents; i++)
			residents[i]->out();

	};
};

