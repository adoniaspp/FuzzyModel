/*
 * maxAgr.cpp
 *
 *  Created on: 18/04/2011
 *      Author: adonias
 */

#include "maximization.h"

MAX_FUNCTION *max(SETS_FUNCTION *sets, MAX_FUNCTION *pointsMax, int xMin, int xMax, int size){
		SETS_FUNCTION *func, *lastFunc;
		lastFunc = NULL;
		func = NULL;
		int count = 0;
		float first, next;
		float *points1, *points2;
		pointsMax = (MAX_FUNCTION*) malloc(sizeof(MAX_FUNCTION));
		int crtl;
		int lastCrtl = -1;

		for (float i = xMin; i <= xMax; (i >= 1 ? i += RESOLUTION2 : i
				+= RESOLUTION1)) {
			points1 = sets[0].imp.pointsImp;
			if (sets[0].imp.numPoints == 2) {
				if (points1[0] <= i && i <= points1[1])
					first = sets[0].fuzzify;
				else {
					first = sets[0].membership(i,sets[0].pointsFun);
				}
			} else {
				if (points1[0] <= i)
					first = sets[0].fuzzify;
				else
					first = sets[0].membership(i,sets[0].pointsFun);
			}
			for (int j = 1; j < size; j++) {
				points2 = sets[j].imp.pointsImp;
				if (sets[j].imp.numPoints == 2) {
					if (points2[0] <= i && i <= points2[1])
						next = sets[j].fuzzify;
					else
						next = sets[j].membership(i,sets[j].pointsFun);
				} else {
					if (points2[0] <= i)
						next = sets[j].fuzzify;
					else
						next = sets[j].membership(i,sets[j].pointsFun);
				}
				first = Max(first, next);
				if (points2[0] <= i && i <= points2[1]){
					if (first == sets[j].fuzzify){
						func = &sets[j];
						crtl = sets[j].id;
						continue;
					}
				}else{
					if (first == sets[j].membership(i,sets[j].pointsFun)){
						func = &sets[j];
						crtl = sets[j].id;
						continue;
					}
				}
				if (points1[0] <= i && i <= points1[1]){
					if (first == sets[0].fuzzify){
						func = &sets[0];
						crtl = sets[0].id;
						continue;
					}
				}else{
					if (first == sets[0].membership(i,sets[j].pointsFun)){
						func = &sets[0];
						crtl = sets[0].id;
						continue;
					}
				}
			}
			if (lastFunc == NULL) {
			//if (lastCrtl == -1) {
				//trace() << crtl << "\n";
				pointsMax[count].pointsMax = i;
				pointsMax[count].set = func;
				pointsMax[count].end = 'f';
				count++;
				pointsMax = (MAX_FUNCTION*) realloc(pointsMax,sizeof(MAX_FUNCTION)*(count+1));
			}
			else if (lastFunc != func) {
			//else if (lastCrtl != crtl) {
				//trace() << crtl << "\n";
				pointsMax[count].pointsMax = i;
				pointsMax[count].set = func;
				pointsMax[count].end = 'f';
				count++;
				pointsMax = (MAX_FUNCTION*) realloc(pointsMax,sizeof(MAX_FUNCTION)*(count+1));
			}
			lastFunc = func;
			//lastCrtl = crtl;
		}
		pointsMax[count].end = 't';
		return pointsMax;
}
