/*
 * ATC.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Maher
 */

#include "ATC.h"
#include<cmath>
#include <iostream>
#include "math.h"

using namespace std;

ATC::ATC() {
	// TODO Auto-generated constructor stub
//	airCraftID = id;
//	 x = xc;
//	 y = yc;
//	 z = zc;
//	 xs = xps;
//	 ys = yps;
//	 zs = zps;
//	 arrival_t = t;
//	 hitStatus = hit;
}

ATC::~ATC() {
	// TODO Auto-generated destructor stub
}
void ATC::checkCollision(vector<Plane> p){
    	vectorPlane = p;
	for (int i = 0; i < vectorPlane.size() - 1; i++){
    		// get plane1 coordinates xyz
    		int x1 = vectorPlane[i].get_plane_x();
    		int y1 = vectorPlane[i].get_plane_y();
    		int z1 = vectorPlane[i].get_plane_z();
		int sx1 = vectorPlane[i].get_plane_speed_x();
		int sy1 = vectorPlane[i].get_plane_speed_y();
		int sz1 = vectorPlane[i].get_plane_speed_z();
		x1 +=sx1*180;
		y1 +=sy1*180;
		z1 +=sz1*180;
    		// Compare plane1 with every other plane after it
    		for(int j = i + 1; j < vectorPlane.size(); j++) {
    			int x2 = vectorPlane[j].get_plane_x();
    			int y2 = vectorPlane[j].get_plane_y();
    			int z2 = vectorPlane[j].get_plane_z();
			int sx2 = vectorPlane[j].get_plane_speed_x();
			int sy2 = vectorPlane[j].get_plane_speed_y();
			int sz2 = vectorPlane[j].get_plane_speed_z();
			x2 +=sx2*180;
			y2 +=sy2*180;
			z2 +=sz2*180;
    			int dx = abs(x2 - x1)/5280;
    			dx = pow(dx, 2);

    			int dy = abs(y2 - y1)/5280;
    			dy= pow(y2, 2);

    			int dz = abs(z2 - z1);

    			// calculate distance
    			int dist = sqrt(dx + dy);
    			if(dist <= 3 && dy <= 1000) {
    				cout << "Collision alert for aircraft ID: " << vectorPlane[i].get_plane_id() << " and aircraft ID: " << vectorPlane[j].get_plane_id() << endl;
    			}
    		}
    	}
    }

void ATC::commandInput(Message m){

    vector<string> command = m.getMsg();
    int planeID = stoi(command[1]);
    if(command[0] == "chgalt"){
        int altitude = stoi(command[2]);
        vectorPlane[planeID].set_plane_z(altitude);
    }
    else if(command[0] == "setspd"){
        int speedx= stoi(command[2]);
        int speedy= stoi(command[3]);
        int speedz= stoi(command[4]);

        vectorPlane[planeID].set_plane_speed_x(speedx);
        vectorPlane[planeID].set_plane_speed_y(speedy);
        vectorPlane[planeID].set_plane_speed_z(speedz);

    }
    else if(command[0] == "hold"){
        vectorPlane[planeID].starthold();
    }
    else if(command[0] == "leave"){
        vectorPlane[planeID].endhold();
    }
    else if(command[0] == "rpt"){
        if( stoi(command[1]) == -1){
            //if "all"
        }
        else{
            //specific planeID

            //to do: make a nicer output format..
            cout << "REPORTING PLANE ID: " + planeID  << endl;
            cout << "Speed X: " + vectorPlane[planeID].get_plane_speed_x() << endl;
            cout << "Speed Y: " + vectorPlane[planeID].get_plane_speed_y() << endl;
            cout << "Speed Z: " + vectorPlane[planeID].get_plane_speed_z() << endl;

            cout << "Speed X: " + vectorPlane[planeID].get_plane_x() << endl;
            cout << "Speed Y: " + vectorPlane[planeID].get_plane_y() << endl;
            cout << "Speed Z: " + vectorPlane[planeID].get_plane_z() << endl;

            cout << "Entry Time: "+vectorPlane[planeID].get_plane_entry_time() << endl;
        }

    }
}
