/*
 * membershipFunction.h
 *
 *  Created on: 16/03/2011
 *      Author: adonias
 */

#ifndef MEMBERSHIPFUNCTION_H_
#define MEMBERSHIPFUNCTION_H_

#include <iostream>
using namespace std;
#define RESOLUTION1 0.001
#define RESOLUTION2 0.01

struct INPUT {
	const char *name;
	float value;
};

struct SET_FUZZY {
	char name[20];
	char type[20];
	float *points;
};

struct MEMB_FUNCTION {
	char name[20];
	float xMin;
	float xMax;
	SET_FUZZY *sets;
	int numSets;
};

struct IMP_FUNCTION {
	float pointsImp[2];
	int numPoints;
};

struct SETS_FUNCTION {
	float fuzzify;
	float *pointsFun;
	float (*membership)(float,float *);
	IMP_FUNCTION imp;
	char name[20];
	int id;
};

struct MAX_FUNCTION {
	float pointsMax;
	SETS_FUNCTION *set;
	char end;
	//char end[1];
};

#endif /* MEMBERSHIPFUNCTION_H_ */
