char * splitFunction(char*, int);
/* This function may be nixed in the future */

int getSplitFactor(char*, char);
/*
 * This function is a precursor to the cacluation 'constructor'
 * It basically determines how many like operators are present
 * to define the size of the calculation
 *  
 */

char * processLine();
/*
 * This is the root function
 */

char getStep(char*);
/*
 * This returns what step the function is in the Order of Operations
 */
