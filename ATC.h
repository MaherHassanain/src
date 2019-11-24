/*
 * ATC.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Maher
 */

#ifndef ATC_H_
#define ATC_H_
#include"Plane.h"
#include<thread>
#include<vector>
using namespace std;

class ATC {
private:
	int airCraftID;
	int x;
	int y;
	int z;
	int xs;
	int ys;
	int zs;
	int arrival_t;
	vector<Plane> vectorPlane;
	bool hitStatus;
public:
	ATC(int id, int xc, int yc, int zc, int xps, int yps, int zps, int t, bool hit);
	virtual ~ATC();
	void checkCollision(vector<Plane> p);
};

#endif /* ATC_H_ */
