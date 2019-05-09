#include<iostream>
#include<queue>
#include <array>
#include<fstream>
#include<cstdlib>


using namespace std;
// -- emergency data arrays -- //
int Emerg_ID[500];
int Emerg_type[500];
int Emerg_zip[500];

// -- person in emergency data arrays -- //
int Person_ID[500];
int Person_type[500];
int Person_zip[500];

// -- temp variables -- //
int Temp_ID[500];
int Temp_type[500];
int Temp_zip[500];
int marker = 0;
int one = 0;
int two = 0;
int three = 0;
int lowest = 500;
int lowest_ID = 0;

int main() {
	cout << " ***********************************************************************************************************************************" << endl;
	// --- creates Zip and Vehicle type for each ID --- //
	for (int x = 0; x < 500; x++) {
		Emerg_ID[x] = x+1;
		Person_ID[x] = x+1;

		//-- these numbers need to stay the same so we have the same number of emergency vehicles as requests --//
		Emerg_type[x] = rand() % 3 + 1;
		Person_type[x] = Emerg_type[x];

		Emerg_zip[x] = rand() % 300 + 64000;
		Person_zip[x] = rand() % 300 + 64000;	
	}

	// --- sorts the emergency vehicles into groups based on 1,2,3 --- //
	for (int z = 1; z < 4; z++) {
		three = 0;
		for (int y = 0; y < 500; y++)
		{

			if (Emerg_type[y] == z) 
			{
				Temp_ID[marker] = Emerg_ID[y];
				Temp_type[marker] = Emerg_type[y];
				Temp_zip[marker] = Emerg_zip[y];
				marker++;
				three++;

			}
		}

// -- these are the number of each vehicle type ie we have 100 ambulances -- //
		// -- three doesnt need to be changed it will keep that number in memory -- //
		if (z == 1) {
			one = three;
		}
		if (z == 2) {
			two = three;
		}
	}

	// --- output  -- //
	for (int v = 0; v < 500; v++) {

		if (Person_type[v] == 1) {

			// -- this looks through to find the lowest vehicles ID -- //
			for (int g = 0; g < one; g++) {
				
				if (lowest > abs(Person_zip[v] - Temp_zip[g])) {
					lowest = abs(Person_zip[v] - Temp_zip[g]);
					lowest_ID = Temp_ID[g];
				}
			}
			// -- this is output and removing item from array --//
			for (int c = 0; c < sizeof(Temp_ID); c++) {
				if (lowest_ID == Temp_ID[c]) {
					cout << "Person ID: " << Person_ID[v] << "	Vehicle request type: " << Person_type[v] << "	Persons ZIP: " << Person_zip[v] << "	**	Emergency Vehicle ID: " << Temp_ID[v] << "	Emergency Vehicle ZIP: " << Temp_zip[v] << "	***		Distance between them: " << abs(Person_zip[v] - Temp_zip[v]) << endl;
					Temp_ID[c] = 501;
					Temp_type[c] = 501;
					Temp_zip[c] = 0;
					lowest = 500;
				}
			}
		}

		if (Person_type[v] == 2) {

			// -- this looks through to find the lowest vehicles ID -- //
			for (int g = one; g < two; g++) {
				
				if (lowest > abs(Person_zip[v] - Temp_zip[g])) {
					lowest = abs(Person_zip[v] - Temp_zip[g]);
					lowest_ID = Temp_ID[g];
				}
			}
			// -- this is output and removing item from array --//
			for (int c = 0; c < sizeof(Temp_ID); c++) {
				if (lowest_ID == Temp_ID[c]) {
					cout << "Person ID: " << Person_ID[v] << "	Vehicle request type: " << Person_type[v] << "	Persons ZIP: " << Person_zip[v] << "	**	Emergency Vehicle ID: " << Temp_ID[v] << "	Emergency Vehicle ZIP: " << Temp_zip[v] << "	***		Distance between them: " << abs(Person_zip[v] - Temp_zip[v]) << endl;
					Temp_ID[c] = 501;
					Temp_type[c] = 501;
					Temp_zip[c] = 0;
					lowest = 500;
				}
			}
		}

	}
	if (Person_type[v] == 2) {

			// -- this looks through to find the lowest vehicles ID -- //
			for (int g = two; g < 500; g++) {
				
				if (lowest > abs(Person_zip[v] - Temp_zip[g])) {
					lowest = abs(Person_zip[v] - Temp_zip[g]);
					lowest_ID = Temp_ID[g];
				}
			}
			// -- this is output and removing item from array --//
			for (int c = 0; c < sizeof(Temp_ID); c++) {
				if (lowest_ID == Temp_ID[c]) {
					cout << "Person ID: " << Person_ID[v] << "	Vehicle request type: " << Person_type[v] << "	Persons ZIP: " << Person_zip[v] << "	**	Emergency Vehicle ID: " << Temp_ID[v] << "	Emergency Vehicle ZIP: " << Temp_zip[v] << "	***		Distance between them: " << abs(Person_zip[v] - Temp_zip[v]) << endl;
					Temp_ID[c] = 501;
					Temp_type[c] = 501;
					Temp_zip[c] = 0;
					lowest = 500;
				}
			}
		}
	

	return 0;

}
