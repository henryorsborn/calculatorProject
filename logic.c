#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculation.h"
#include "logic.h"

char * processLine() {

	/*
	char steps[6] = {'P', 'E', 'M', 'A', 'T', 'X'};
	char step;
	char *input = (char *)malloc(100 * sizeof(char));
	scanf("%[^\n]",input);
	step = getStep(input, steps);
	getSplitFactor(input, step);
	splitFunction(input, 0);
	printf("The step is %c: \n%s\n", step, input);
	*/
	struct calculation myCalc;
	char myOps[3] = {'+', '-', '-'};
	struct calculation subCalc1;
	subCalc1.sizeFactor = 0;
	subCalc1.data = 4;
	struct calculation subCalc2;
	subCalc2.sizeFactor = 0;
	subCalc2.data = 3;
	struct calculation subCalc3;
	struct calculation subCalc4;
	subCalc4.sizeFactor = 0;
	subCalc4.data = 7;
	struct calculation subCalc5;
	subCalc5.sizeFactor = 0;
	subCalc5.data = 3;
	struct calculation subCalc6;
	subCalc6.sizeFactor = 0;
	subCalc6.data = 34;
	struct calculation myOtherCals[2] = {subCalc5, subCalc6};
	subCalc3.calcs = myOtherCals;
	//char otherOps[1] = {'+'};
	//subCalc3.operators = otherOps;
	subCalc3.sizeFactor = 0;
	subCalc3.data = 12;
	struct calculation subCalcs[4] = {subCalc1, subCalc2, subCalc3, subCalc4};	
	
	myCalc.operators = myOps;
	myCalc.calcs = subCalcs;
	myCalc.sizeFactor = sizeof(myOps);
	struct calculation* subCalc7 = stringToCalc("5");
	printf("%f\n", subCalc7->data);
	printf("%s\n", calcToString(*subCalc7));
	printCalc(myCalc);
	char* testString = "45 + 3 / 67 * (3 + 2 - 9) / 3";
	printf("%s\n", testString);
	stringToCalc(testString);
	printf("%s\n", calcToString(myCalc));
	printf("ATOMIC %d\n", isCalculationAtomic(myCalc));
	printCalc(reduceASCalculation(myCalc, '+', 0));

}

int getSplitFactor(char *line, char step){

	int total = 1;
	int i;
	for(i = 0; i < strlen(line); i++){
		if(step=='A'&&((line[i]=='+')||(line[i]=='-'))){
			total+=2;	
		}
	}
	return 0;
}

char * splitFunction(char *line, int splitFactor){


	return "";
}

char getStep(char *line){


	char steps[6] = {'P', 'E', 'M', 'A', 'T', 'X'};
	int i;
	char step='T';
	for(i = 0; i < strlen(line); i++){

		if(line[i]=='('||line[i]==')'){
			return 'P';
		}else if(line[i]=='^') {
			step='E';
		}else if((line[i]=='*'||line[i]=='/')&&step!='E') {
			step='M';
		} else if((line[i]=='+'||line[i]=='-')&&step!='E'&&step!='M'){
			step='A';
		}else if(line[i]==' '){
			continue;
		} else {
			int a;
			if(!sscanf(&line[i], "%d", &a)){
				return 'X';
			}

		}

	}
	return step;

}
