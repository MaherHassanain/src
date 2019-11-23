/*
 * Radar.cpp
 *
 *  Created on: Oct 9, 2019
 *      Author: Maher
 */
#include<iostream>
#include "Radar.h"
using namespace std;

Radar::Radar(int p_id, int x1, int y1, int z1) {
	// TODO Auto-generated constructor stub

	id = p_id;
	x = x1;
	y = y1;
	z = z1;
}

Radar::Radar(vector<Plane> p) {
	// TODO Auto-generated constructor stub
	vectorPlane = p;

}

void Radar::operator()(Plane *p[]) {
//	cout << "Plane ID: " << id << " - X position: " << x << " - Y position: " << y << " - Z position :" << z << endl;
	cout<<x<<endl;
}

Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

bool Radar::plane_in_environment(){
	if (x >= 0 && x <= 528000) {
		if(y >= 0 && y <= 528000){
			if(z >= 15000 && z <= 25000) {
				plane_in_env = true;
			}
		}
	}
	return plane_in_env;
}

void Radar::print_current_position(){
//	cout << "Plane ID: " << id << " - X position: " << x << " - Y position: " << y << " - Z position :" << z << endl;
}
void Radar::checkCollision(vector<Plane> p){
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
    			dy= pow(y3, 2);

    			int dz = abs(z2 - z1);

    			// calculate distance
    			int dist = sqrt(dx + dy);
    			if(dist <= 3 && dy <= 1000) {
    				cout << "Collision alert for aircraft ID: " << vectorPlane[i].get_plane_id() << " and aircraft ID: " << vectorPlane[j].get_plane_id << endl;
    			}
    		}
    	}
    }
	
bool Radar::plane_is_identified(){
	bool plane_has_id = true;
	if(id < 0) {
		plane_has_id = false;
	}

	return plane_has_id;
}
