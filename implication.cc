/*
 * imp.cpp
 *
 *  Created on: 17/04/2011
 *      Author: adonias
 */

#include "implication.h"

IMP_FUNCTION min(float fuzzify, float *pointsFunc, float (*membership)(float,float *), int xMin, int xMax){
			int j = 0;
			float lastMem = 0, lastPos = 0;
			float *pointsMin = (float*) malloc(sizeof(float));;

			for (float i = xMin; i <= xMax; (i >= 1 ? i += RESOLUTION2 : i += RESOLUTION1)) {
				float p = Min(fuzzify, membership(i,pointsFunc));
				if (p == fuzzify && j == 0) {
					pointsMin[j] = i;
					j++;
					pointsMin = (float*) realloc(pointsMin,sizeof(float)*(j+1));
				}
				if (p != fuzzify && lastMem == fuzzify) {
					pointsMin[j] = lastPos;
					j++;
					pointsMin = (float*) realloc(pointsMin,sizeof(float)*(j+1));
				}
				lastMem = p;
				lastPos = i;
			}
			IMP_FUNCTION imp;
			imp.pointsImp[0] = pointsMin[0];
			imp.pointsImp[1] = pointsMin[1];
			imp.numPoints = j;
			free(pointsMin);
			return imp;
}
