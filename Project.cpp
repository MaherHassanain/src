#include <iostream>
#include<vector>
#include"Plane.h"
#include"Radar.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include<functional>
#include<chrono>
using namespace std;

Plane* planeArray[20];
Radar* planeRadar[20];
vector<Plane> planeVector;

mutex mtx; // to be used when we want to run more than a thread
condition_variable cv; // used with mutex
bool ready = false; // thread flag
int current = 0; // current count

class DisplayThread
{
public:
    void operator()(Plane *p[])
    {
    	int counter = 0;
    	int uCounter = 0; // for detecting -1 to set unique ID to them
    	int secondCounter = 0; // for other unkown planes
        for(int i = 0; i < 20; i++){
         	if(p[i]->get_plane_id() == -1) {
//         		cout << "Un-identified Plane" << endl;
         		int temp;
         		temp = p[i]->get_plane_id() - uCounter;
         		p[i]->set_plane_id(temp);
         		uCounter++;
         	} else if(p[i]->get_plane_id() < -1) { // means the new found ID for unknown planes -2,-3, -4 etc
         		secondCounter++; // count total unknown planes smaller ID than -1
         	} else {
         		// do nothing
         		counter++;
         	}

         	cout << "Plane ID: " << p[i]->get_plane_id() << " X: " << p[i]->get_plane_x() << " Y: " << p[i]->get_plane_y() << " Z: " <<p[i]->get_plane_z() << endl;
        }

        int total = uCounter + secondCounter;

        cout<< "Total  Un-idetntified planes: " << total << endl;
        cout<< "Total  idetntified planes: " << counter << endl;

        //Array to pass to ATC
    }
};

void timer_start(std::function<void(void)> func, unsigned int interval)
{
    std::thread([func, interval]() {
        while (true)
        {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

void radarScan() {
	thread threadObj( (DisplayThread()), planeArray);
	threadObj.join();
}

int main() {
	// id , spd x, spd y, spd z, pos x, pos y, pos z, entry time
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

		planeRadar[counter] = new Radar(airplane_schedule[i],  airplane_schedule [i+4],
				airplane_schedule [i+5], airplane_schedule [i+6]);

		planeVector.push_back(Plane(airplane_schedule [i] , airplane_schedule [i+1], airplane_schedule [i+2], airplane_schedule [i+3], airplane_schedule [i+4],
				airplane_schedule [i+5], airplane_schedule [i+6], airplane_schedule [i+7]));

		i = i + 7;
		cout << planeArray[counter]->get_plane_id() <<endl;
//		cout << planeRadar[counter]->plane_in_environment() <<endl;
//		planeRadar[counter]->print_current_position();
//		cout<< planeRadar[counter]->plane_is_identified() << endl;
		counter++;

	}
//
//	for (unsigned int j = 0; j < planeVector.size(); j++) {
//	            cout << planeVector[j].get_plane_x() << endl;
//	        }

	timer_start(radarScan, 15000);

	while(true);

	return 0;
}
