#pragma once
#include <iostream>
#include <stdlib.h>
#include "creature.h"
#include "flat.h"

using namespace std;

class House {
	int n_floors;
	int n_flats;
	int n_residents;
	Flat** flats;
public:
	House() {
		n_floors = 0;
		n_flats = 0;
		n_residents = 0;
		flats = nullptr;
	};

	House(int _n_floors, int _n_flats, int _n_residents) {
		n_floors = _n_floors;
		n_flats = _n_flats;
		n_residents = _n_residents;

		int n_residents_per_flat;
		int resident_counter = 0; // number of creatures in one flat except last one

		flats = new Flat* [n_flats];
		for (int i = 0; i < n_flats; i++) {
			int n_residents_per_flat = (n_residents - resident_counter) / (n_flats - i);
			flats[i] = new Flat(n_residents_per_flat);
			resident_counter = resident_counter + n_residents_per_flat;
		}
	};

	void review() {
		int n_flats_per_floor;
		int flat_counter = 0;
		for (int i = 0; i < n_floors; i++) {
			cout << "----<    Floor #" << i + 1 << "    >--------------------" << endl << endl;
			n_flats_per_floor = (n_flats - flat_counter) / double(n_floors-i);
			for (int j = 0; j < n_flats_per_floor; j++) {
				cout << "--Flat #" << flat_counter+1 << endl << "    Residents:" << endl;
				flats[flat_counter]->review();
				flat_counter++;
			}
			cout << endl;
		}
	}

	void FG_counter() {
		int n_flats_per_floor;
		int flat_counter = 0;
		int FG_counter; // number of women and girls on the floor
		for (int i = 0; i < n_floors; i++) {
			FG_counter = 0;
			cout << "Floor #" << i + 1 << endl << endl;
			n_flats_per_floor = ceil((n_flats - flat_counter) / (n_floors - i));
			for (int j = flat_counter; j < flat_counter + n_flats_per_floor; j++) {
				for (int k = 0; k < flats[j]->out_n_residents(); k++) {
					if ((flats[j]->out_residents()[k]->IsPerson() == 1) && ((flats[j]->out_residents()[k]->type() == "Female") || (flats[j]->out_residents()[k]->type() == "Girl")))
					{
						FG_counter++;
					}
				}
			}
			flat_counter = flat_counter + n_flats_per_floor;
			cout << "Number of women and girls on the floor: " << FG_counter << endl;
			cout << endl;
		}
	}

	int BG_with_D_counter() {
		int counter = 0;
		int f;
		for (int i = 0; i < n_flats; i++) {
			f = 0;
			int j = 0;
			while (j < flats[i]->out_n_residents() && f == 0) {
				if (flats[i]->out_residents()[j]->type() == "Dog")
					f = 1;
				j++;
			}
			if (f == 1)
				for (j = 0; j < flats[i]->out_n_residents(); j++)
					if ((flats[i]->out_residents()[j]->type() == "Boy") || (flats[i]->out_residents()[j]->type() == "Girl"))
						counter++;
		}
		return counter;
	}
};


