#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * processLine();
char getStep(char *line, char steps[5]);

char * processLine() {

	char steps[5] = {'P', 'E', 'M', 'A', 'T'};
	char step;
	char *input = (char *)malloc(100 * sizeof(char));
	gets(input);
	step = getStep(input, steps);
	printf("The step is %c: \n%s", step, input);

}

char getStep(char *line, char steps[5]){

	int i;
	for(i = 0; i < strlen(line); i++){
		
		if(line[i]=='('||line[i]==')'){
			return 'P';
		}
		
	
	}
	return 'T';

}

int main() {

	processLine();


	return 0;
}
