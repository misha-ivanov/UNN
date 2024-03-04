#include <iostream>
#include <ctime>
#include "creature.h"
#include "house.h"

using namespace std;

int main() {
	srand(time(NULL));
	int floors, flats, residents;
	
	cout << "WELCOME to the simulator of HOUSE DEPARTMENT" << "\n\n" << "Please, enter the number of floors of the building: ";
	cin >> floors;
	while (floors < 1) {
		cout << endl << "Please, use positive real numbers for this." << endl << "Please, enter the number of floors in the building: ";
		cin >> floors;
	}

	cout << endl << "Please, enter the number of flats in the building: ";
	cin >> flats;
	while (flats < 1 || flats < floors) {
		cout << endl << "Please, use positive real numbers for this and be sure that the number of flats more or equel than number of floors." << endl << "Please, enter the number of flats in the building: ";
		cin >> flats;
	}
	
	cout << endl << "Please, enter the number of residents in the building: ";
	cin >> residents;
	while (residents < 1) {
		cout << endl << "Please, use positive real numbers for this." << endl << "Please, enter the number of residents in the building: ";
		cin >> residents;
	}
	cout << endl << endl;

	House A(floors, flats, residents);
	A.review();
	A.FG_counter();
	cout << endl << "Number of Boys and Girls with a dog: " << A.BG_with_D_counter() << endl;
	return 0;
}