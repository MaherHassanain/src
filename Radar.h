/*
 * Radar.h
 *
 *  Created on: Oct 9, 2019
 *      Author: Maher
 */

#ifndef RADAR_H_
#define RADAR_H_
#include"Plane.h"


class Radar {
	int id;
	int x;
	int y;
	int z;
	bool plane_in_env = false;
public:
	Radar(int p_id, int x, int y, int z);
	virtual ~Radar();
	bool plane_in_environment();
	void print_current_position();
};

#endif /* RADAR_H_ */
