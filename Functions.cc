/*
 * Trapezoidal.cpp
 *
 *  Created on: 17/04/2011
 *      Author: adonias
 */

#include "Functions.h"

float trapezoidalMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float b = points[1];
	float c = points[2];
	float d = points[3];
	if ((x > b) && (x <= c))
		result = 1;
	else if ((x > a) && (x <= b))
		result = (x - a) / (b - a);
	else if ((x > c) && (x <= d))
		result = (d - x) / (d - c);
	else if ((x <= a) || (x > d))
		result = 0;
	return result;
}

float triangularMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float b = points[1];
	float c = points[2];
	if (a == b)
		result = ((c - x) / (c - b) * (b <= x) * (x <= c));
	else if (b == c)
		result = ((x - a) / (b - a) * (a <= x) * (x <= b));
	else
		result = (Max(Min((x - a) / (b - a), (c - x) / (c - b)), 0));
	return result;
}

float inFormZMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float b = points[1];
	if (x <= a)
		result = 1;
	else if (x <= (a + b) / 2)
		result = 1 - 2 * pow((x - a) / (b - a), 2.0);
	else if (x <= b)
		result = 2 * pow((b - x) / (b - a), 2.0);
	else
		result = 0;
	return result;
}

float inFormSMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float b = points[1];
	if (x <= a)
		result = 0;
	else if (x <= (a + b) / 2)
		result = 2 * pow((x - a) / (b - a), 2.0);
	else if (x <= b)
		result = 1 - 2 * pow((b - x) / (b - a), 2.0);
	else
		result = 1;
	return result;
}

float inFormPiMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float b = points[1];
	float c = points[2];
	float d = points[3];
	if (x <= a)
		result = 0;
	else if (x <= (a + b) / 2)
		result = 2 * pow((x - a) / (b - a), 2.0);
	else if (x <= b)
		result = 1 - 2 * pow((b - x) / (b - a), 2.0);
	else if ((x > b) && (x < c))
		result = 1;
	else if (x <= (c + d) / 2)
		result = 2 * pow((x - c) / (d - c), 2.0);
	else if (x <= d)
		result = 1 - 2 * pow((d - x) / (d - c), 2.0);
	else
		result = 0;
	return result;
}

float gaussianMembership(float x, float points[]) {
	float result = 0;
	float temp;
	float sigma = points[0];
	float c = points[1];
	temp = (x - c) / sigma;
	result = exp(-temp * temp / 2);
	return result;
}

float sigmoidMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float c = points[1];
	result = (1 / (1 + exp(-a * (x - c))));
	return result;
}

float bellMembership(float x, float points[]) {
	float result = 0;
	float a = points[0];
	float b = points[1];
	float c = points[2];
	float temp;
	temp = pow((x - c) / a, 2.0);
	if (temp == 0 && b == 0)
		result = 0.5;
	else if (temp == 0 && b < 0)
		result = 0.0;
	else
		result = 1 / (1 + pow(temp, b));
	return result;
}

float diffSigmoidsMembership(float x, float points[]) {
	float result = 0;
	float a1 = points[0];
	float c1 = points[1];
	float a2 = points[2];
	float c2 = points[3];
	float temp1 = 1 / (1 + exp(-a1 * (x - c1)));
	float temp2 = 1 / (1 + exp(-a2 * (x - c2)));
	result = (fabs(temp1 - temp2));
	return result;
}

float gaussian2Membership(float x, float points[]) {
	float result = 0;
	float sigma1 = points[0];
	float c1 = points[1];
	float sigma2 = points[2];
	float c2 = points[3];
	float temp1, temp2;
	temp1 = x >= c1 ? 1 : exp(-pow((x - c1) / sigma1, 2.0) / 2);
	temp2 = x <= c2 ? 1 : exp(-pow((x - c2) / sigma2, 2.0) / 2);
	result = temp1 * temp2;
	return result;
}

float prodSigmoidsMembership(float x, float points[]) {
	float result = 0;
	float a1 = points[0];
	float c1 = points[1];
	float a2 = points[2];
	float c2 = points[3];
	float temp1 = 1 / (1 + exp(-a1 * (x - c1)));
	float temp2 = 1 / (1 + exp(-a2 * (x - c2)));
	result = temp1 * temp2;
	return result;
}
