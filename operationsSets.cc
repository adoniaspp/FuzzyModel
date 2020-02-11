/*
 * operationsSets.cpp
 *
 *  Created on: 17/04/2011
 *      Author: adonias
 */

#include "operationsSets.h"

float Min(float x, float y) {
	return ((x) < (y) ? (x) : (y));
}

float Max(float x, float y){
	return((x) > (y) ? (x) : (y));
}

float Prod(float x, float y){
	return(x*y);
}

float ProbOr(float x, float y){
	return(x + y - x*y);
}

float Sum(float x, float y){
	return(x + y);
}

float Owa(float *, float *){

}

float OwaWeighted(float *, float *){

}

float operationArray(float *array, int size, float(*operation)(float,float)) {
		int i;
		float out;
		out = array[0];
		for (i = 1; i < size; i++)
			out = (*operation)(out, array[i]);
		return (out);
}
