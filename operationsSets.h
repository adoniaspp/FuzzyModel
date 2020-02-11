/*
 * operationsSets.h
 *
 *  Created on: 14/04/2011
 *      Author: adonias
 */

#ifndef OPERATIONSSETS_H_
#define OPERATIONSSETS_H_

#include <stdio.h>

float Min(float,float);

float Max(float,float);

float Prod(float, float);

float ProbOr(float, float);

float Sum(float, float);

float Owa(float *, float *);  //Falta

float OwaWeighted(float *, float *); //Falta

float operationArray(float *, int, float(*)(float,float));

#endif /* OPERATIONSSETS_H_ */
