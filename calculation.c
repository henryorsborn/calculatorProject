#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculation.h"
#include "logic.h"

struct calculation* makeCalculation(char* ops, struct calculation* calculs,
		float dat, char isAtomic, int sizeFact) {
	struct calculation* makeCalc;
	makeCalc = (struct calculation*)malloc(sizeof(struct calculation));
	makeCalc->operators = ops;
	makeCalc->calcs = calculs;
	makeCalc->data = dat;
	makeCalc->isAtomic = isAtomic;
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
		myCalc = makeCalculation(myOps, myCalcs, myData, 1, 0);
		printCalc(*myCalc);
		return myCalc;
	}	
	return myCalc;
}



char* calcToString(struct calculation c){
	
	int i;
	char* bigString;
        bigString = (char*)malloc(1000*sizeof(char));
	bigString = strcat(bigString, "[");
	char* tempStr;
	char* operatorString;
	for(i = 0; i < c.sizeFactor; i++){
		tempStr = (char*)malloc(100*sizeof(char));
		if(c.calcs[i].isAtomic){
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
	if(c.calcs[i].isAtomic){		
		sprintf(tempStr, "{%f}", c.calcs[i].data);
	} else {
		sprintf(tempStr, "{%s}", calcToString(c.calcs[i]));
	}
	bigString = strcat(bigString, tempStr);
        bigString = strcat(bigString, "]");	
	return bigString;
}


