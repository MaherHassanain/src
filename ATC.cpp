/*
 * ATC.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Maher
 */

#include "ATC.h"

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

