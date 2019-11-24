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

ATC::ATC(int id,int xc, int yc, int zc, int xps, int yps, int zps, int t, bool hit) {
	// TODO Auto-generated constructor stub
	airCraftID = id;
	 x = xc;
	 y = yc;
	 z = zc;
	 xs = xps;
	 ys = yps;
	 zs = zps;
	 arrival_t = t;
	 hitStatus = hit;
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

