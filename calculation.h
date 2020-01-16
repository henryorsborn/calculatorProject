/*
 * This structure is used to divide the calculation into manageable parts
 * It consist of an array or characters that are the like operators
 * such as + and - per operation order
 * Likewise it contains a list of caculations on either side of the operators to handle
 * each aspect of the calculation
 *
 */


struct calculation {
	char* operators;
	struct calculation* calcs;
	float data;
	int sizeFactor;
};

struct calculation reduceCalculation(struct calculation, char, float);

void printCalc(struct calculation);
/*
 * This is a helper function used in debugging for calculations
 */

struct calculation* makeCalculation(char*, struct calculation*,
		float, int);
/*
 * This is the constructor of a calculation
 */

char* calcToString(struct calculation);
/*
 * This is the toString function that I use for debugging
 */

struct calculation* stringToCalc(char*);
/*
 * This is an alternate constructor that takes a string as an input
 */

int isCalculationAtomic(struct calculation);
