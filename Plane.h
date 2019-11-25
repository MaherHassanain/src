/*
 * Plane.h
 *
 *  Created on: Sep 18, 2019
 *      Author: Maher
 */

#ifndef PLANE_H_
#define PLANE_H_

class Plane {
private:
	int plane_id;
	int speed_x;
	int speed_y;
	int speed_z;
	int saved_speed_x;	//used for saving initial speed when entering holding pattern
	int saved_speed_y;
	int saved_speed_z;
	int theta;
	double magnitude;
	bool holding;		//flag for holding check.
	int x;
	int y;
	int z;
	int entry_time;



public:

	Plane(int id, int spx, int spy, int spz, int x1, int y1, int z1, int t);
	virtual ~Plane();
	int get_plane_id();
	int get_plane_speed_x();
	int get_plane_speed_y();
	int get_plane_speed_z();
	int get_plane_x();
	int get_plane_y();
	int get_plane_z();
	int get_plane_entry_time();
	void set_plane_id(int id);
	void set_plane_speed_x(int spx);
	void set_plane_speed_y(int spy);
	void set_plane_speed_z(int spz);
	void set_plane_x(int x1);
	void set_plane_y(int y1);
	void set_plane_z(int z1);
	void set_plane_entry_time(int t);
	void position_update(int t);
	bool plane_in_environment();
	void starthold();
	void endhold();
};

#endif /* PLANE_H_ */
