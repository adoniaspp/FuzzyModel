/*
 * routing.cpp
 *
 *  Created on: 15/05/2011
 *      Author: adonias
 */

#include "fuzzy.h"

Define_Module(routing);

void routing::startup() {
}
void routing::fromApplicationLayer(cPacket *pkt, const char *dstAddr){
}
void routing::fromMacLayer(cPacket *pkt, int srcMacAddress, double RSSI, double LQI){
}

float getMembership(float x, SET_FUZZY set) {
	if (strcmp(set.type, "trapmf") == 0)
		return trapezoidalMembership(x, set.points);
	if (strcmp(set.type, "trimf") == 0)
		return triangularMembership(x, set.points);
	if (strcmp(set.type, "zmf") == 0)
		return inFormZMembership(x, set.points);
	if (strcmp(set.type, "smf") == 0)
		return inFormSMembership(x, set.points);
	if (strcmp(set.type, "pimf") == 0)
		return inFormPiMembership(x, set.points);
	if (strcmp(set.type, "gbellmf") == 0)
		return bellMembership(x, set.points);
	if (strcmp(set.type, "psigmf") == 0)
		return prodSigmoidsMembership(x, set.points);
	if (strcmp(set.type, "dsigmf") == 0)
		return diffSigmoidsMembership(x, set.points);
	if (strcmp(set.type, "sigmf") == 0)
		return sigmoidMembership(x, set.points);
	if (strcmp(set.type, "gauss2mf") == 0)
		return gaussian2Membership(x, set.points);
	if (strcmp(set.type, "gaussmf") == 0)
		return gaussianMembership(x, set.points);
}

float *consequence(float points[], INPUT input[], float *buffer, int index, int numMf){
	float result = 0;
	for (int i = 0; i<numMf; i++){
		result = result + (points[i] * input[i].value);
	}
	result = result + points[numMf];
	buffer[index] = result;
	return buffer;
}

SETS_FUNCTION *getImplication(float result, SET_FUZZY set, MEMB_FUNCTION func,char nameFunc[],
		SETS_FUNCTION *buffer, int b) {
	if (strcmp(set.type, "trapmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, trapezoidalMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = trapezoidalMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "trimf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, triangularMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = triangularMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "zmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, inFormZMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = inFormZMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "smf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, inFormSMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = inFormSMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "pimf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, inFormPiMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = inFormPiMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "gbellmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, bellMembership, func.xMin,
				func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = bellMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "psigmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, prodSigmoidsMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = prodSigmoidsMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "dsigmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, diffSigmoidsMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = diffSigmoidsMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "sigmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, sigmoidMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = sigmoidMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "gauss2mf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, gaussian2Membership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = gaussian2Membership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
	if (strcmp(set.type, "gaussmf") == 0) {
		IMP_FUNCTION imp = min(result, set.points, gaussianMembership,
				func.xMin, func.xMax);
		buffer[b].fuzzify = result;
		buffer[b].imp = imp;
		buffer[b].membership = gaussianMembership;
		buffer[b].pointsFun = set.points;
		buffer[b].id = b;
		//memcpy(buffer[b].name, nameFunc, strlen(nameFunc));
		strcpy(buffer[b].name, nameFunc);
		return buffer;
	}
}

float getOperation(float *array, int size, char operation[]) {
	if (strcmp(operation, "min") == 0) {
		return operationArray(array, size, Min);
	}
	if (strcmp(operation, "max") == 0) {
		return operationArray(array, size, Max);
	}
	if (strcmp(operation, "prod") == 0) {
		return operationArray(array, size, Prod);
	}
	if (strcmp(operation, "probOr") == 0) {
		return operationArray(array, size, ProbOr);
	}
	if (strcmp(operation, "sum") == 0) {
		return operationArray(array, size, Sum);
	}
}

MAX_FUNCTION *getAggregation(SETS_FUNCTION *buffer, MAX_FUNCTION *points,
		float xMin, float xMax, int crtl, char operation[]) {
	if (strcmp(operation, "max") == 0) {
		return max(buffer, points, xMin, xMax, crtl);
	}
}

float getDefuzzification(MAX_FUNCTION *points, float xMin, float xMax,
		char operation[]) {
	if (strcmp(operation, "centroid") == 0) {
		return centerGravity(points, xMin, xMax);
	}
	if (strcmp(operation, "mom") == 0) {
		return meanMaximun(points, xMin, xMax);
	}
	if (strcmp(operation, "som") == 0) {
		return smallestMaximun(points, xMin, xMax);
	}
	if (strcmp(operation, "lom") == 0) {
		return largestMaximun(points, xMin, xMax);
	}
}

float routing::fuzzy(INPUT *input, const char *setupFile, const char *baseRuleFile){
			ifstream fin(setupFile, ios::in);
			if (fin == NULL) {
				printf("file cannot be opened");
			}

			/*Construção da Função de Pertinência*/

			//Entrada
			int numMfInput;
			int numSetsFuzzy;
			string tempName;
			string temptype;
			char testPoint[20];
			char inferenceMachine[20];
			fin >> inferenceMachine;
			fin >> numMfInput;
			MEMB_FUNCTION *mfInput;
			mfInput = (MEMB_FUNCTION*) calloc(numMfInput, sizeof(MEMB_FUNCTION));
			for (int i = 0; i < numMfInput; i++) {
				fin >> tempName;
				memcpy(mfInput[i].name, tempName.c_str(), tempName.length());
				fin >> mfInput[i].xMin;
				fin >> mfInput[i].xMax;
				fin >> numSetsFuzzy;
				mfInput[i].numSets = numSetsFuzzy; //Pode ser alterado
				mfInput[i].sets = (SET_FUZZY*) calloc(numSetsFuzzy, sizeof(SET_FUZZY));
				for (int z = 0; z < numSetsFuzzy; z++) {
					fin >> temptype;
					memcpy(mfInput[i].sets[z].type, temptype.c_str(), temptype.length());
					fin >> tempName;
					memcpy(mfInput[i].sets[z].name, tempName.c_str(), tempName.length());
					mfInput[i].sets[z].points = (float*) malloc(sizeof(float));
					int x = 0;
					fin >> testPoint;
					while ((strcmp(testPoint, "#")) != 0) {
						mfInput[i].sets[z].points[x] = atof(testPoint);
						x++;
						mfInput[i].sets[z].points = (float*) realloc(
								mfInput[i].sets[z].points, sizeof(float) * (x + 1));
						fin >> testPoint;
					}
				}
			}
			int numMfOutput;
			MEMB_FUNCTION *mfOutput;
		if(strcmp(inferenceMachine, "mamdani") == 0){
			//Saida
			//int numMfOutput;
			fin >> numMfOutput;
			//MEMB_FUNCTION *mfOutput;
			mfOutput = (MEMB_FUNCTION*) calloc(numMfOutput, sizeof(MEMB_FUNCTION));
			for (int i = 0; i < numMfOutput; i++) {
				fin >> tempName;
				memcpy(mfOutput[i].name, tempName.c_str(), tempName.length());
				fin >> mfOutput[i].xMin;
				fin >> mfOutput[i].xMax;
				fin >> numSetsFuzzy;
				mfOutput[i].numSets = numSetsFuzzy; //Pode ser alterado
				mfOutput[i].sets = (SET_FUZZY*) calloc(numSetsFuzzy, sizeof(SET_FUZZY));
				for (int z = 0; z < numSetsFuzzy; z++) {
					fin >> temptype;
					memcpy(mfOutput[i].sets[z].type, temptype.c_str(), temptype.length());
					fin >> tempName;
					memcpy(mfOutput[i].sets[z].name, tempName.c_str(), tempName.length());
					mfOutput[i].sets[z].points = (float*) malloc(sizeof(float));
					int x = 0;
					fin >> testPoint;
					while ((strcmp(testPoint, "#")) != 0) {
						mfOutput[i].sets[z].points[x] = atof(testPoint);
						x++;
						mfOutput[i].sets[z].points = (float*) realloc(
								mfOutput[i].sets[z].points, sizeof(float) * (x + 1));
						fin >> testPoint;
					}
				}
			}
		}else {
				//Saida
				//int numMfOutput;
				fin >> numMfOutput;
				//MEMB_FUNCTION *mfOutput;
				mfOutput = (MEMB_FUNCTION*) calloc(numMfOutput, sizeof(MEMB_FUNCTION));
				for (int i = 0; i < numMfOutput; i++) {
					fin >> tempName;
					memcpy(mfOutput[i].name, tempName.c_str(), tempName.length());
					fin >> numSetsFuzzy;
					mfOutput[i].numSets = numSetsFuzzy; //Pode ser alterado
					mfOutput[i].sets = (SET_FUZZY*) calloc(numSetsFuzzy, sizeof(SET_FUZZY));
					for (int z = 0; z < numSetsFuzzy; z++) {
						fin >> temptype;
						memcpy(mfOutput[i].sets[z].type, temptype.c_str(), temptype.length());
						fin >> tempName;
						memcpy(mfOutput[i].sets[z].name, tempName.c_str(), tempName.length());
						mfOutput[i].sets[z].points = (float*) malloc(sizeof(float));
						int x = 0;
						fin >> testPoint;
						while ((strcmp(testPoint, "#")) != 0) {
							mfOutput[i].sets[z].points[x] = atof(testPoint);
							x++;
							mfOutput[i].sets[z].points = (float*) realloc(
									mfOutput[i].sets[z].points, sizeof(float) * (x + 1));
							fin >> testPoint;
						}
					}
				}
		}
		ifstream finb(baseRuleFile, ios::in);
			if (finb == NULL) {
				printf("file cannot be opened");
			}
		int numRules;
		char OpImp[20];
		char OpAgr[20];
		char OpDef[20];
		char bufferTemp[20];
		float *membTemp;
		int crtlA;
		int crtlC = 0;
		SETS_FUNCTION *sets;
		//Sugeno
		float *cons;
		float *tv;
		float pond;
		if(strcmp(inferenceMachine, "mamdani") == 0){
			finb >> numRules;
			finb >> OpImp;
			finb >> OpAgr;
			finb >> OpDef;
			sets = (SETS_FUNCTION*) malloc(sizeof(SETS_FUNCTION));

			for (int u = 0; u < numRules; u++) {
				crtlA = 0;
				membTemp = (float*) malloc(sizeof(float));
				finb >> bufferTemp;
				//Antecedente
				while (strcmp(bufferTemp, "#") != 0) { //Condição de parada de uma regra
					for (int i = 0; i < numMfInput; i++) {
						if (strcmp(mfInput[i].name, bufferTemp) == 0) { //Verifica se existe a mf
							finb >> bufferTemp;
							for (int j = 0; j < mfInput[i].numSets; j++) {
								if (strcmp(mfInput[i].sets[j].name, bufferTemp) == 0) { //Verifica se existe o conjunto para mf
									for (int z = 0; z < numMfInput; z++) {
										if (strcmp(input[z].name, mfInput[i].name) == 0) { //Verifica qual a entrada da mf
											membTemp[crtlA] = getMembership(
													input[z].value, mfInput[i].sets[j]);
											crtlA++;
											membTemp = (float*) realloc(membTemp,
													sizeof(float) * (crtlA + 1));
										}
									}
								}
							}
						}
					}
					finb >> bufferTemp;
				}
				finb >> bufferTemp;
				finb >> pond;
				float result = getOperation(membTemp, crtlA, bufferTemp) * pond;
				free(membTemp);
				finb >> bufferTemp;
				while (strcmp(bufferTemp, "#") != 0) { //Condição de parada de uma regra
					for (int i = 0; i < numMfOutput; i++) {
						if (strcmp(mfOutput[i].name, bufferTemp) == 0) { //Verifica se existe a mf
							finb >> bufferTemp;
							for (int j = 0; j < mfOutput[i].numSets; j++) {
								if (strcmp(mfOutput[i].sets[j].name, bufferTemp) == 0) { //Verifica se existe o conjunto para mf
									sets = getImplication(result, mfOutput[i].sets[j],
											mfOutput[i], mfOutput[i].name, sets, crtlC);
									//trace() << mfOutput[i].name << "\n";
									crtlC++;
									sets = (SETS_FUNCTION*) realloc(sets,
											sizeof(SETS_FUNCTION) * (crtlC + 1));
								}
							}
						}
					}
					finb >> bufferTemp;
				}
			}
		}else {
				finb >> numRules;
				finb >> OpDef;
				cons = (float*) calloc(numRules, sizeof(float));
				tv = (float*) calloc(numRules, sizeof(float));
				for (int u = 0; u < numRules; u++) {
					crtlA = 0;
					membTemp = (float*) malloc(sizeof(float));
					finb >> bufferTemp;
					//Antecedente
					while (strcmp(bufferTemp, "#") != 0) { //Condição de parada de uma regra
						for (int i = 0; i < numMfInput; i++) {
							if (strcmp(mfInput[i].name, bufferTemp) == 0) { //Verifica se existe a mf
								finb >> bufferTemp;
								for (int j = 0; j < mfInput[i].numSets; j++) {
									if (strcmp(mfInput[i].sets[j].name, bufferTemp) == 0) { //Verifica se existe o conjunto para mf
										for (int z = 0; z < numMfInput; z++) {
											if (strcmp(input[z].name, mfInput[i].name) == 0) { //Verifica qual a entrada da mf
												membTemp[crtlA] = getMembership(
														input[z].value, mfInput[i].sets[j]);
												crtlA++;
												membTemp = (float*) realloc(membTemp,
														sizeof(float) * (crtlA + 1));
											}
										}
									}
								}
							}
						}
						finb >> bufferTemp;
					}
					finb >> bufferTemp;
					finb >> pond;
					tv[u] = getOperation(membTemp, crtlA, bufferTemp) * pond;
					//float result = getOperation(membTemp, crtlA, bufferTemp);
					free(membTemp);
					//Consequente
					finb >> bufferTemp;
					while (strcmp(bufferTemp, "#") != 0) { //Condição de parada de uma regra
						for (int i = 0; i < numMfOutput; i++) {
							if (strcmp(mfOutput[i].name, bufferTemp) == 0) { //Verifica se existe a mf
								finb >> bufferTemp;
								for (int j = 0; j < mfOutput[i].numSets; j++) {
									if (strcmp(mfOutput[i].sets[j].name, bufferTemp) == 0) { //Verifica se existe o conjunto para mf
										cons = consequence(mfOutput[i].sets[j].points, input, cons, crtlC, numMfInput);
										crtlC++;
										cons = (float*) realloc(cons, sizeof(float) * (crtlC + 1));
									}
								}
							}
						}
						finb >> bufferTemp;
					}
				}
		}
		if(strcmp(inferenceMachine, "mamdani") == 0){
			//Agregação e Defuzzification
			SETS_FUNCTION *intermediateBuffer;
			for (int j = 0; j < numMfOutput; j++) {
				crtlA = 0;
				intermediateBuffer = (SETS_FUNCTION*) malloc(sizeof(SETS_FUNCTION));
				for (int i = 0; i < crtlC; i++) {
					if (strcmp(mfOutput[j].name, sets[i].name) == 0) {
						intermediateBuffer[crtlA] = sets[i];
						crtlA++;
						intermediateBuffer
								= (SETS_FUNCTION*) realloc(intermediateBuffer,
										sizeof(SETS_FUNCTION) * (crtlA + 1));
					}
				}
				MAX_FUNCTION *points = NULL;
				points = getAggregation(intermediateBuffer, points, mfOutput[j].xMin,
						mfOutput[j].xMax, crtlA, OpAgr);
				
				return getDefuzzification(points, mfOutput[j].xMin, mfOutput[j].xMax, OpDef);
				free(intermediateBuffer);
				free(points);
				points = NULL;	
				intermediateBuffer = NULL;

			}
		}else {
			float result = 0;
			float den = 0;
			float div = 0;
			for(int i=0; i<numRules; i++){
				den = den + (tv[i] * cons[i]);
				div = div + tv[i];
			}
			if(strcmp(OpDef, "weightedAverage") == 0) {
				result = den / div;
			}else {
				result = den;
			}
			return arred(result);
			//printf("%f\n",result);
		}
			//Limpeza
			if(strcmp(inferenceMachine, "mamdani") != 0){
			free(cons);
			free(tv);
			}
			for(int i=0; i<numMfInput; i++)	{		
				for(int j=0; j<mfInput[i].numSets; j++) {
					free(mfInput[i].sets[j].points);
					mfInput[i].sets[j].points = NULL;
				}	
				free(mfInput[i].sets);
				mfInput[i].sets = NULL;
			}
			for(int i=0; i<numMfOutput; i++)	{		
				for(int j=0; j<mfOutput[i].numSets; j++) {
					free(mfOutput[i].sets[j].points);
					mfOutput[i].sets[j].points = NULL;
				}	
				free(mfOutput[i].sets);
				mfOutput[i].sets = NULL;
			}
			free(mfOutput);
			free(mfInput);
			free(sets);
			mfOutput = NULL;
			mfInput = NULL;
			sets = NULL;
			cons = NULL;
			tv = NULL;
			membTemp = NULL;
}

