/*
 * minImp.h
 *
 *  Created on: 04/04/2011
 *      Author: adonias
 */

#ifndef IMPLICATION_H_
#define IMPLICATION_H_

#include <stdlib.h>

#include "operationsSets.h"
#include "membershipFunction.h"

IMP_FUNCTION min(float fuzzify, float *pointsFunc, float (*)(float,float *), int xMin, int xMax);

#endif /* IMPLICATION_H_ */
