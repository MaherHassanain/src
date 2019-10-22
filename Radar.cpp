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
	cout << "Plane ID: " << id << " - X position: " << x << " - Y position: " << y << " - Z position :" << z << endl;
}

bool Radar::plane_is_identified(){
	bool plane_has_id = true;
	if(id < 0) {
		plane_has_id = false;
	}

	return plane_has_id;
}
