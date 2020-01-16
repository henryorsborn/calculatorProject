#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculation.h"
#include "logic.h"

struct calculation* makeCalculation(char* ops, struct calculation* calculs,
		float dat, int sizeFact) {
	struct calculation* makeCalc;
	makeCalc = (struct calculation*)malloc(sizeof(struct calculation));
	makeCalc->operators = ops;
	makeCalc->calcs = calculs;
	makeCalc->data = dat;
	makeCalc->sizeFactor = sizeFact;
	return makeCalc;
}

void printCalc(struct calculation c){
	
	int i;
	for(i = 0; i < c.sizeFactor; i++){
		printf("{%f} ", c.calcs[i].data);	
		printf("{%c} ", c.operators[i]);
	}
	printf("{%f}\n", c.calcs[i].data);

}

struct calculation* stringToCalc(char* line){

	struct calculation* myCalc;
	char* myOps;
	struct calculation* myCalcs;
	if(getStep(line)=='T'){

		float myData;
		sscanf(line, "%f", &myData);
		myCalc = makeCalculation(myOps, myCalcs, myData, 0);
		printCalc(*myCalc);
		return myCalc;
	}	
	return myCalc;
}

struct calculation reduceCalculation(struct calculation c, char stepAcc, float dataAcc){

	if(isCalculationAtomic(c)){
		printf("%f\nDONE\n", stepAcc=='+'? dataAcc+c.calcs[0].data :
				dataAcc-c.calcs[0].data);
		return c;
	} else {
		if(stepAcc == '+'){
			if(isCalculationAtomic(c.calcs[0])){
				dataAcc += c.calcs[0].data;
			}
		} else {
			if(isCalculationAtomic(c.calcs[0])){
				dataAcc -= c.calcs[0].data;
			}
		}
		int i;
		char newOperators[c.sizeFactor-1];
		struct calculation newCalcs[c.sizeFactor];
		for(i = 1; i < c.sizeFactor; i++){
			newOperators[i-1] = c.operators[i];
			newCalcs[i-1] = c.calcs[i];
		}
		stepAcc = c.operators[0];
		newCalcs[i-1] = c.calcs[i];
		c.operators = newOperators;
		c.calcs = newCalcs;
		c.sizeFactor--;
		return reduceCalculation(c, stepAcc, dataAcc);
	}
	return c;
}

char* calcToString(struct calculation c){
	
	int i;
	char* bigString;
        bigString = (char*)malloc(1000*sizeof(char));
	bigString = strcat(bigString, "[");
	char* tempStr;
	char* operatorString;
	if(isCalculationAtomic(c)){
		tempStr = (char*)malloc(100*sizeof(char));
		sprintf(tempStr, "{%f}", c.data);
		bigString = strcat(bigString, tempStr);
	} else {
		for(i = 0; i < c.sizeFactor; i++){
			tempStr = (char*)malloc(100*sizeof(char));
			if(isCalculationAtomic(c.calcs[i])){
				sprintf(tempStr, "{%f} ", c.calcs[i].data);
			} else {
				sprintf(tempStr, "{%s} ", calcToString(c.calcs[i]));
			}
			bigString = strcat(bigString, tempStr);
			operatorString = (char*)malloc(100*sizeof(char));
			sprintf(operatorString, "{%c} ", c.operators[i]);
			bigString = strcat(bigString, operatorString);
		}
		tempStr = (char*)malloc(100*sizeof(char));
		if(isCalculationAtomic(c.calcs[i])){		
			sprintf(tempStr, "{%f}", c.calcs[i].data);
		} else {
			sprintf(tempStr, "{%s}", calcToString(c.calcs[i]));
		}
	
	bigString = strcat(bigString, tempStr);
	}
	bigString = strcat(bigString, "]");	
	return bigString;
}


int isCalculationAtomic(struct calculation c) {

	return c.sizeFactor==0;

}
