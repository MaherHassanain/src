/*
 * Radar.cpp
 *
 *  Created on: Oct 9, 2019
 *      Author: Maher
 */

#include "Radar.h"

Radar::Radar(int p_id, int x1, int y1, int z1) {
	// TODO Auto-generated constructor stub

	id = p_id;
	x = x1;
	y = y1;
	z = z1;
}

Radar::~Radar() {
	// TODO Auto-generated destructor stub
}

bool Radar::plane_in_environment(int p_id){
	if (x >= 0 && x <= 528000) {
		if(y >= 0 && y <= 528000){
			if(z >= 15000 && z <= 25000) {
				plane_in_env = true;
			}
		}
	}
	return plane_in_env;
}
