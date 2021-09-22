// Lindsey Nager
// Intro to Bitwise Operators
// Main Driver of Program

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

// Purpose: Opens files to be used throughout the program
// Recieves: ifstream& and ofstream&
// Returns: N/A
void openFiles(std::ifstream& infile, std::ofstream& outfile);

// Purpose: reverse every bit of a number. A bit in the 0 pos will be moved
// to the size of the number - i position 
// Recieves: unsigned short 
// Returns: unsigned short  :   new value after mirroring
unsigned short mirrorBits(unsigned short originalNum);

// Purpose: print values that have been reversed
// Recieves: unsigned short, ofstream&
// Returns: N/A
void print(unsigned short num, std::ofstream& outfile);

int main()
{
    // Creates stream variables
    std::ifstream infile;
    std::ofstream outfile;

    // Calls openFiles
    openFiles(infile, outfile);

    // Outfiles heading 
    outfile << "Lindsey Nager \nDiscrete Structures and Analysis \n2433-101\n\n";

    unsigned short finalAns;

    // Outfiles headers of table
    outfile << std::right << std::setw(8) << "Number\t\t\t" << std::setw(10) 
        << std::left << "Reverse" << std::endl;

    // Loops until end of file
    while(!(infile.eof()))
    {
        // Resets val to 0
        unsigned short originalNum = 0;

        // Reads in original number and prints
        infile >> originalNum;
        outfile << std::right << std::setw(6) << originalNum << "\t\t\t";

        // Calls mirrorBits and stores in finalAns
        finalAns = mirrorBits(originalNum);

        // Calls print function
        print(finalAns, outfile);
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

unsigned short mirrorBits(unsigned short originalNum)
{
    // Gets the number of bits
    int numBits = sizeof(originalNum)*8;
    unsigned short result = 0;

    // Loops through each bit
    for(unsigned short i = 0; i < numBits; i++)
    {
        // if pow(2,i) & orginalNum == 1
        if((1 << i) & originalNum)
        {
            // result | pow(2, numBits - 1 - i)
            result = result | (1 <<  (numBits - 1 - i));
        }
    }

    return result;
}

void print(unsigned short num, std::ofstream& outfile)
{
	outfile << num << "\n";
}