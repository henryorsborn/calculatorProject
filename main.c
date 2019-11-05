#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * processLine();
char getStep(char *line, char steps[5]);

char * processLine() {

	char steps[6] = {'P', 'E', 'M', 'A', 'T', 'X'};
	char step;
	char *input = (char *)malloc(100 * sizeof(char));
	gets(input);
	step = getStep(input, steps);
	printf("The step is %c: \n%s", step, input);

}


char getStep(char *line, char steps[6]){

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

int main() {

	processLine();


	return 0;
}
