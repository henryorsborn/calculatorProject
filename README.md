# calculatorProject
I'm creating a simple calculator in C that parses a user input and shows each step.

This is a simple program to help me practice C, in the future I hope to implement this program in a web setting.

Currently it's following a recursive algorithm that uses a data type Calculation. A Calculation is a struct
that will contain an array of operators ('+', '/', '\*') and an array of Calculations and that will have 2x + 1 the length of
prior array.

This will run backwards through the order of operations in the initial recursive breakdown.
