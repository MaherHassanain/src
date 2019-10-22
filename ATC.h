/*
 * ATC.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Maher
 */

#ifndef ATC_H_
#define ATC_H_

class ATC {
private:
	int airCraftID;
	int x;
	int y;
	int z;
	int size;
	bool hitStatus;
public:
	ATC();
	virtual ~ATC();
};

#endif /* ATC_H_ */
