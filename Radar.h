/*
 * Radar.h
 *
 *  Created on: Oct 9, 2019
 *      Author: Maher
 */

#ifndef RADAR_H_
#define RADAR_H_
#include"Plane.h"
#include<vector>
using namespace std;

class Radar {
private:
	int id;
	int x;
	int y;
	int z;
	bool plane_in_env = false;
	vector<Plane> vectorPlane;

public:
	Radar(int p_id, int x, int y, int z);
	Radar(vector<Plane> p);
	virtual ~Radar();
	bool plane_in_environment();
	void print_current_position();
};

#endif /* RADAR_H_ */
