/*
 * helper.cpp
 *
 *  Created on: 17/04/2011
 *      Author: adonias
 */

#include "helper.h"

#define DECIMAL3 3
#define DECIMAL2 2

float arred(float x) {
	if (x < 1) {
		return floor(x * pow(10, DECIMAL3) + 0.5) / pow(10, DECIMAL3);
	} else {
		return floor(x * pow(10, DECIMAL2) + 0.5) / pow(10, DECIMAL2);
	}
}
