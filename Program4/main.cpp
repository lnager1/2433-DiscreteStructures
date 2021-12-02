/*****************************************************************************
*                    
*  Author:           Lindsey
*  Email:            nager.lindsey@gmail.com
*  Label:            Program 4
*  Title:            Combinatorics
*  Course:           CMPS 2433-101
*  Semester:         Fall 2021
* 
*  Description:
*        This program will solve the number of combinations of schools and students 
*        from the selected schools and selected students
*  
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

// Purpose: Opens files to be used throughout the program
// Recieves: ifstream& and ofstream&
// Returns: N/A
void openFiles(std::ifstream& infile, std::ofstream& outfile);

// Purpose: Prints headers to the outfile to mark the program 
//      clearly when printed
// Recieves: ofstream&
// Returns: N/A
void printHeaders(std::ofstream& outfile);

// Purpose: Computes an iterative factorial number
// Recieves: unsigned long long int :   number to factorialize 
// Returns: unsigned long long int  :   factorial solution
unsigned long long int factorial(unsigned long long int doFact);

// Purpose: Computes the number of possible combinations
// Recieves: unsigned long long int :   number of total choices
//           unsigned long long int :   number of combinations chosen
// Returns:  unsigned long long int :   number of combinations calculated
unsigned long long int combination(unsigned long long int n, unsigned long long int r);

// Purpose: Computes a number to the power of a number
// Recieves: unsigned long long int :   number being multiplied
//           unsigned long long int :   number of times being multiplied
// Returns:  unsigned long long int :   number that is now to the power
unsigned long long int power(unsigned long long int powerTo, unsigned long long int powerOf);

// Purpose: print values that have been selected
// Recieves: unsigned long long int :   final calculated value
//           ofstream&
// Returns: N/A
void print(unsigned long long int printMe, std::ofstream& outfile);

int main()
{
    // Creates stream variables
    std::ifstream infile;
    std::ofstream outfile;

    // Calls openFiles
    openFiles(infile, outfile);

    // Outfiles heading 
    printHeaders(outfile);

    // Variables
    unsigned long long int totalNumberSchools;
    unsigned long long int chosenSchools;
    unsigned long long int studentsAvailable;
    unsigned long long int chosenStudents;

    unsigned long long int finalVal;

    // Loops until end of file
    while(!(infile.eof()))
    {
        // Reads in N A B D
        infile >> totalNumberSchools >> chosenSchools >> studentsAvailable >> chosenStudents;
        
        // Calculate C(N,A)*C(B,D)^A
        finalVal = (combination(totalNumberSchools, chosenSchools) * power(combination(studentsAvailable, chosenStudents), chosenSchools));
        finalVal = finalVal % int(std::pow(10,9) + 7);

        // Prints
        print(finalVal, outfile);
    }

    // Closes streams
    infile.close();
    outfile.close();

    return 0;
}

void openFiles(std::ifstream& infile, std::ofstream& outfile)
{
    std::string inFileName;
    std::string outFileName;

    // Prompts user, reads and opens files
    std::cout << "Enter the input file name: ";
    std::cin >> inFileName;

    infile.open(inFileName);

    std::cout << "Enter the output file name: ";
    std::cin >> outFileName;

    outfile.open(outFileName);
}
void printHeaders(std::ofstream& outfile)
{
	outfile << "Lindsey Nager\n";
    outfile << "Discrete Structures and Analysis\n";
    outfile << "Program 4 - Combinatorics\n";
    outfile << "12/2/2021\n";
    outfile << "This program will solve the number of combinations of schools and students " << 
    "from the selected schools and selected students\n\n";
}
unsigned long long int factorial(unsigned long long int doFact)
{
    // Factorial Value 
    unsigned long long int fact = 1;

    // Loops through and multiplies by i each time
    for(int i = 1; i <= doFact; i++)
    {
        fact *= i;
    }

    return fact;
}

unsigned long long int combination(unsigned long long int n, unsigned long long int r)
{
    // Factorialized variables
    unsigned long long int nFact = factorial(n);
    unsigned long long int rFact = factorial(r);
    unsigned long long int nrFact = factorial(n-r);

    // Combination formula
    return nFact/(nrFact*(rFact));
}

unsigned long long int power(unsigned long long int powerTo, unsigned long long int powerOf)
{
    // Return Value
    unsigned long long int returnMe = powerTo;

    // Loops thorugh multiplying by original num each time
    for(int i = 1; i < powerOf; i++)
    {
        returnMe *= powerTo;
    }

    return returnMe;
}

void print(unsigned long long int printMe, std::ofstream& outfile)
{
    // outfiles printMe
    outfile << printMe << "\n";
}