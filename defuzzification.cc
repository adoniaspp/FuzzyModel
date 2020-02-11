/*
 * gravity.cpp
 *
 *  Created on: 18/04/2011
 *      Author: adonias
 */

#include "defuzzification.h"

float centerGravity(MAX_FUNCTION *points, int xMin, int xMax) {

	float resultDen = 0; 
	float resultDiv = 0; 
	float defuzzification = 0;
	float *pointsImp;
	int b = 0;

	while (points[b].end != 't') {
		b++;
	}

	int size = b;

	for (float i = xMin; i <= xMax; (i >= 1 ? i += RESOLUTION2 : i
			+= RESOLUTION1)) {
		float ic = i;
		for (int z = 0; z < size; z++) {
			pointsImp = points[z].set->imp.pointsImp;
			if (ic >= points[z].pointsMax && ic <= ((z + 1) == size ? xMax
					: points[z + 1].pointsMax)) {
				if (points[z].set->imp.numPoints == 2) {
					if (pointsImp[0] <= ic && ic <= pointsImp[1]) {
						resultDen = resultDen + points[z].set->fuzzify * ic;
						resultDiv += points[z].set->fuzzify;
						break;
					} else {
						resultDen += points[z].set->membership(ic,
								points[z].set->pointsFun) * ic;
						resultDiv += points[z].set->membership(ic,
								points[z].set->pointsFun);
						break;
					}
				} else {
					if (pointsImp[0] <= ic) {
						resultDen += points[0].set->fuzzify * ic;
						resultDiv += points[0].set->fuzzify;
						break;
					} else {
						resultDen += points[0].set->membership(ic,
								points[z].set->pointsFun) * ic;
						resultDiv += points[0].set->membership(ic,
								points[z].set->pointsFun);
						break;
					}
				}
			} else {
				continue;
			}
		}
	}
	if (resultDiv == 0) {
		defuzzification = xMax / 2;
		return arred(defuzzification);
		//printf("%f\n", arred(defuzzification));
	} else {
		defuzzification = resultDen / resultDiv;
		return arred(defuzzification);
		//printf("%f\n", arred(defuzzification));
	}
	return defuzzification;
}

float meanMaximun(MAX_FUNCTION *points, int xMin, int xMax) {
	float resultDen = 0, resultDiv = 0;
	float *pointsImp;
	int i = 0;

	while (points[i].end != 't') {
		i++;
	}

	int size = i;

	float max = points[0].set->fuzzify;
	int m = 0;
	for (int z = 1; z < size; z++) {
		if (points[z].set->fuzzify > max) {
			max = points[z].set->fuzzify;
			m = z;
		} else
			continue;
	}
	pointsImp = points[m].set->imp.pointsImp;
	for (float i = xMin; i <= xMax; (i >= 1 ? i += RESOLUTION2 : i
			+= RESOLUTION1)) {
		if (points[m].set->imp.numPoints == 2) {
			if (pointsImp[0] <= i && i <= pointsImp[1]) {
				resultDen += i;
				resultDiv++;
			}
		} else {
			if (pointsImp[0] <= i) {
				resultDen += i;
				resultDiv++;
			}
		}
	}
	float resultMom = resultDen / resultDiv;
	return arred(resultMom);
	//printf("%f\n", resultMom);*/
}
float smallestMaximun(MAX_FUNCTION *points, int xMin, int xMax) {
	float resultDen = 0;
	float *pointsImp;
	int i = 0;

	while (points[i].end != 't') {
		i++;
	}

	int size = i;

	float max = points[0].set->fuzzify;
	int m = 0;
	for (int z = 1; z < size; z++) {
		if (points[z].set->fuzzify > max) {
			max = points[z].set->fuzzify;
			m = z;
		} else
			continue;
	}
	pointsImp = points[m].set->imp.pointsImp;
	for (float i = xMin; i <= xMax; (i >= 1 ? i += RESOLUTION2 : i
			+= RESOLUTION1)) {
		if (points[m].set->imp.numPoints == 2) {
			if (pointsImp[0] <= i && i <= pointsImp[1]) {
				resultDen = i;
				break;
			}
		} else {
			if (pointsImp[0] <= i) {
				resultDen = i;
				break;
			}
		}
	}
	float resultSom = resultDen;
	return arred(resultSom);
	//printf("%f\n", resultSom);*/
}

float largestMaximun(MAX_FUNCTION *points, int xMin, int xMax) {
	float resultDen = 0;
	float *pointsImp;
	int i = 0;

	while (points[i].end != 't') {
		i++;
	}

	int size = i;

	float max = points[0].set->fuzzify;
	int m = 0;
	for (int z = 1; z < size; z++) {
		if (points[z].set->fuzzify > max) {
			max = points[z].set->fuzzify;
			m = z;
		} else
			continue;
	}
	pointsImp = points[m].set->imp.pointsImp;
	for (float i = xMin; i <= xMax; (i >= 1 ? i += RESOLUTION2 : i
			+= RESOLUTION1)) {
		if (points[m].set->imp.numPoints == 2) {
			if (pointsImp[0] <= i && i <= pointsImp[1]) {
				resultDen = i;
			}
		} else {
			if (pointsImp[0] <= i) {
				resultDen = i;
			}
		}
	}
	float resultLom = resultDen;
	return arred(resultLom);
	//printf("%f\n", resultLom);*/
}

