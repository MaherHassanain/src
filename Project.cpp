#include <iostream>
#include"Plane.h"
using namespace std;

Plane* planeArray[20];

int main() {

	int airplane_schedule[160] = {0, -641, 283, 500, 95000, 101589, 10000, 13,
		1, -223, -630, -526, 71000, 100000, 13000, 16,
		-1, -180, -446, -186, 41000, 100000, 6000, 31,
		3, 474, -239, 428, 38000, 0, 14000, 44,
		-1, -535, 520, 360, 95000, 100000, 1000, 49,
		-1, -164, -593, -501, 83000, 100000, 12000, 67,
		6, 512, 614, 520, 86000, -1571, 9000, 87,
		7, -275, 153, -399, 47000, 100000, 12000, 103,
		8, -129, 525, -300, 92000, 100000, 1000, 123,
		9, 437, 574, 339, 32000, 0, 8000, 129,
		10, 568, 538, 192, 50000, 0, 4000, 133,
		11, 347, 529, -599, 83000, -1799, 10000, 140,
		12, -512, -482, 578, 35000, 100000, 4000, 142,
		13, 619, -280, 194, 74000, 0, 10000, 157,
		14, -141, 427, -321, 41000, 102251, 11000, 165,
		15, -199, 242, -205, 56000, 100000, 4000, 172,
		16, 315, -197, -365, 77000, 0, 1000, 187,
		17, -138, 455, 602, 23000, 102290, 14000, 199,
		18, -150, 557, -356, 38000, 100000, 1000, 204,
		19, 194, 184, 598, 35000, 0, 2000, 221,
		};

	int counter = 0;



	for (int i = 0; i < 160; i++) {

		planeArray[counter] = new Plane(airplane_schedule [i] , airplane_schedule [i+1], airplane_schedule [i+2], airplane_schedule [i+3], airplane_schedule [i+4],
				airplane_schedule [i+5], airplane_schedule [i+6], airplane_schedule [i+7]);

		i = i + 7;
//		cout << planeArray[counter]->get_plane_id() <<endl;
		counter++;

	}

	cout <<"Plane1 ID is : "<< planeArray[0]->get_plane_id() <<endl;
	cout << "Plane2 ID is : "<< planeArray[1]->get_plane_id() <<endl;
	cout <<"Plane3 Entry Time is : "<< planeArray[2]->get_plane_entry_time() <<endl;
	cout <<"Plane1 is in environment : "<< planeArray[0]->plane_in_environment() <<endl;
	cout <<"Plane1 location : X : "<< planeArray[0]->get_plane_x() << "  Y : " << planeArray[0]->get_plane_y() << " Z : " << planeArray[0]->get_plane_z() <<endl;


	return 0;
}
