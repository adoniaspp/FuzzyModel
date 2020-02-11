/*
 * centerGravity.h
 *
 *  Created on: 05/04/2011
 *      Author: adonias
 */

#ifndef DEFUZZIFICATION_H_
#define DEFUZZIFICATION_H_

#include <stdio.h>
#include "membershipFunction.h"
#include "helper.h"

float centerGravity(MAX_FUNCTION *, int, int);
float meanMaximun(MAX_FUNCTION *, int, int);
float smallestMaximun(MAX_FUNCTION *, int, int);
float largestMaximun(MAX_FUNCTION *, int, int);

#endif /* DEFUZZIFICATION_H_ */
