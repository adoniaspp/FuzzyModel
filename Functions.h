/*
 * Trapezoidal.h
 *
 *  Created on: 16/03/2011
 *      Author: adonias
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <math.h>
#include "operationsSets.h"

float trapezoidalMembership(float,float *);
float triangularMembership(float,float *);
float inFormZMembership(float,float *);
float inFormSMembership(float,float *);
float inFormPiMembership(float,float *);
float gaussianMembership(float,float *);
float sigmoidMembership(float,float *);
float bellMembership(float,float *);
float diffSigmoidsMembership(float,float *);
float gaussian2Membership(float,float *);
float prodSigmoidsMembership(float,float *);
#endif /* FUNCTIONS_H_ */
