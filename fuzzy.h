/*
 * routing.h
 *
 *  Created on: 15/05/2011
 *      Author: adonias
 */

#ifndef ROUTING_H_
#define ROUTING_H_

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>

#include <queue>
#include <vector>
#include <omnetpp.h>
#include <algorithm>
#include <string>

#include "VirtualRouting.h"
#include "operationsSets.h"
#include "membershipFunction.h"
#include "Functions.h"
#include "implication.h"
#include "maximization.h"
#include "defuzzification.h"

using namespace std;
using std::ifstream;
using std::ofstream;
using std::ios;

class routing : public VirtualRouting{
public:
	void startup();
	void fromApplicationLayer(cPacket *, const char *);
	void fromMacLayer(cPacket *, int, double, double);
	float fuzzy(INPUT *,const char *,const char *);
};

#endif /* ROUTING_H_ */
