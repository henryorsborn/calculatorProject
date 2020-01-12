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
	subCalc1.isAtomic = 1;
	subCalc1.data = 4;
	struct calculation subCalc2;
	subCalc2.isAtomic = 1;
	subCalc2.data = 3;
	struct calculation subCalc3;
	subCalc3.isAtomic = 0;
	subCalc3.data = 4542;
	struct calculation subCalc4;
	subCalc4.isAtomic = 1;
	subCalc4.data = 7;
	struct calculation subCalc5;
	subCalc5.isAtomic = 1;
	subCalc5.data = 3;
	struct calculation subCalc6;
	subCalc6.isAtomic = 1;
	subCalc6.data = 34;
	struct calculation myOtherCals[2] = {subCalc5, subCalc6};
	subCalc3.calcs = myOtherCals;
	char otherOps[1] = {'+'};
	subCalc3.operators = otherOps;
	subCalc3.sizeFactor = 1;
	struct calculation subCalcs[4] = {subCalc1, subCalc2, subCalc3, subCalc4};	
	myCalc.operators = myOps;
	myCalc.calcs = subCalcs;
	myCalc.sizeFactor = sizeof(myOps);
	struct calculation* subCalc7 = stringToCalc("5");
	printf("%f", subCalc7->data);
	printf("\n%s\n", calcToString(*subCalc7));
	printCalc(myCalc);
	printf("\n%s\n", calcToString(myCalc));
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
