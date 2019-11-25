/*
 * Plane.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: Maher
 */

#include "Plane.h"
#include <chrono>
#include "math.h"
using namespace std::chrono;
using namespace std;
Plane::Plane(int id, int spx, int spy, int spz, int x1, int y1, int z1, int t) {
	// TODO Auto-generated constructor stub

	plane_id = id;
	speed_x = spx;
	speed_y = spy;
	speed_z = spz;
	saved_speed_x=0;
	saved_speed_y=0;
	saved_speed_z=0;
	x = x1;
	y = y1;
	z = z1;
	magnitude=0;
	entry_time = t;

}

int Plane::get_plane_id(){
	return plane_id;
}
int Plane::get_plane_speed_x(){
	if(holding)
	{
		theta+=5;
		speed_x=(double)magnitude*(double)sin(theta);
	}
	return speed_x;
}
int Plane::get_plane_speed_y(){
	if(holding)
	{
		speed_y=(double)magnitude*(double)cos(theta);
	}
	return speed_y;
}
int Plane::get_plane_speed_z(){
	if(holding)
	{
		return 0;
	}	
	return speed_z;
}
int Plane::get_plane_x(){

	return x;
}
int Plane::get_plane_y(){
	return y;
}
int Plane::get_plane_z(){
	return z;
}
int Plane::get_plane_entry_time(){
	return entry_time;
}

void Plane::set_plane_id(int id){
	plane_id = id;
}
void Plane::set_plane_speed_x(int spx){
	
	speed_x = spx;
}
void Plane::set_plane_speed_y(int spy){
	speed_y = spy;
}
void Plane::set_plane_speed_z(int spz){
	speed_z = spz;
}
void Plane::set_plane_x(int x1){
	x = x1;
}
void Plane::set_plane_y(int y1){
	y = y1 ;
}
void Plane::set_plane_z(int z1){
	z = z1 ;
}
void Plane::set_plane_entry_time(int t){
	entry_time = t;
}
void Plane::position_update(int t){
//update the plane's position after t sec based on the current speed.
    x=x+speed_x*t;
    y=y+speed_x*t;
    z=z+speed_x*t;
  }
  

bool Plane::plane_in_environment(){

	bool status = false;

	if(x >= 0 && x <= 528000){
		if(y >= 0 && y <= 528000){
			if(z >= 15000 && z <= 25000){
				status = true;
			}
		}
	}

	return status;
}

Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

void Plane::starthold(){
	saved_speed_x=speed_x;
	saved_speed_y=speed_y;
	saved_speed_z=speed_z;
	magnitude=sqrt(pow(speed_x,2)+pow(speed_y,2))
	bool holding=true;
	theta=0;
	speed_x=(double)magnitude*(double)sin(theta);
	speed_y=(double)magnitude*(double)cos(theta);
	speed_z=0;
}

void Plane::endhold(){
	speed_x=saved_speed_x;
	speed_y=saved_speed_y;
	speed_z=saved_speed_z;
	holding=false;
	theta=0;
	magnitude=0;
	}