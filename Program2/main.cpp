/*****************************************************************************
*                    
*  Author:           Lindsey
*  Email:            nager.lindsey@gmail.com
*  Label:            Squares
*  Title:            Feynman Problem
*  Course:           CMPS 2433-101
*  Semester:         Fall 2021
* 
*  Description:
*        This program will solve how many squares are in an 
*        NxN grid iterativly, recursivly, and closed form
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

// Purpose: Prints headers to the outfile to mark the program clearly when printed
// Recieves: ofstream&
// Returns: N/A
void printHeaders(std::ofstream& outfile);

// Purpose:  Calculates the number of squares found in an nxn grid using a for loop
// Recieves: int useN   :   marks the size of the grid
// Returns:  int        :   number of squares found
int squareIterative(int useN);

// Purpose:  Calculates the number of squares found in an nxn 
//           grid using recursion (recurrence relation)
// Recieves: int useN   :   marks the size of the grid
// Returns:  int        :   number of squares found
int squareRecursive(int useN);

// Purpose:  Calculates the number of squares found in an nxn grid using
//           a closed equation
// Recieves: int useN   :   marks the size of the grid
// Returns:  int        :   number of squares found
int squareClosed(int useN);

// Purpose: print values that have been reversed
// Recieves: unsigned short, ofstream&
// Returns: N/A
void print(std::ofstream& outfile, int orginal, int sumI, int sumR, int sumC);

int main()
{
    // Creates stream variables
    std::ifstream infile;
    std::ofstream outfile;

    // Variables
    int numTimes; 
    int n;
    int sumClosed;
    int sumIterate;
    int sumRecurisive;

    // Calls openFiles
    openFiles(infile, outfile);
    printHeaders(outfile);
    
    // Reads in number of data enteries 
    infile >> numTimes;

    // Loops through number of data enteries
    for(int i = 0; i < numTimes; i++)
    {
        // Reads in size of grid
        infile >> n;

        // Computes the sums three different ways 
        sumClosed = squareClosed(n);
        sumIterate = squareIterative(n);
        sumRecurisive = squareRecursive(n);

        // Prints current computated numbers
        print(outfile, n, sumIterate, sumRecurisive, sumClosed);
    }

    // Closes files
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
    outfile << "Program 2 - Feynman Problem\n";
    outfile << "10/7/2021\n";
    outfile << "This program will solve how many squares are in an NxN grid iterativly, recursivly, and closed form\n\n";

    outfile << std::right << std::setw(2) << "N" << std::setw(12) << "Iterative" 
    << std::setw(12) << "Recursive" << std::setw(12) << "Closed\n";
}
int squareIterative(int useN)
{
    // Variables
    int sum = 0;

    // Loops from 1 - n and adds values to sum
    for(int i = 1; i <= useN; i++)
    {
        sum = sum + (int)pow(i, 2);
    }

    return sum;
}
int squareRecursive(int useN)
{
    // Varaibles
    int sum;

    // Base case
    if(useN == 1)
    {
        return 1;
    }
    // Recursive call = n^2 + n-1^2
    else
    {
        return (int)(pow(useN, 2) + squareRecursive(useN-1));
    }
}
int squareClosed(int useN)
{
    // Variables
    int sum;

    // Closed form equation
    sum = (useN*(useN+1)*(2*useN+1))/6;
    return sum;
}
void print(std::ofstream& outfile, int orginal, int sumI, int sumR, int sumC)
{
    // outfiles values correctly set 
    outfile << std::right << std::setw(2) << orginal << std::setw(12) << sumI 
    << std::setw(12) << sumR << std::setw(11) << sumC << "\n";    
}