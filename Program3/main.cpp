/*****************************************************************************
*                    
*  Author:           Lindsey
*  Email:            nager.lindsey@gmail.com
*  Label:            Program 3
*  Title:            Greedy Algorithm
*  Course:           CMPS 2433-101
*  Semester:         Fall 2021
* 
*  Description:
*        This program will solve how many tasks can be
*        completed based on the start time and length of the task
*  
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

struct times
{
    int startTime;
    int length;
    int endTime;
};

// Purpose: Opens files to be used throughout the program
// Recieves: ifstream& and ofstream&
// Returns: N/A
void openFiles(std::ifstream& infile, std::ofstream& outfile);

// Purpose: Prints headers to the outfile to mark the program 
//      clearly when printed
// Recieves: ofstream&
// Returns: N/A
void printHeaders(std::ofstream& outfile);

// Purpose: Calculates the ending time based on the start time and length given
// Recieves: int start   :   marks the beggining time
//           int length  :   the time it takes to get to the end time of a task
// Returns:  int         :   the calculated end time of the given task
int calculateEndTime(int start, int length);

// Purpose: Sorts a vector of type times based on the endTime variable
// Recieves: std::vector<times> sortMe  :   vector containing all avaible tasks
// Returns:  N/A
void selectionSort(std::vector<times> &sortMe);

// Purpose: Selects what tasks can be completed 
// Recieves: std::vector<times> useMe  :   vector containing all avaible tasks
// Returns:  std::vector<times>        :   vector containing all selected tasks
std::vector<times> chooseAvaiable(std::vector<times> &useMe);

// Purpose: print values that have been selected
// Recieves: std::vector<times> printtMe  :   vector containing all 
//      selected tasks
//           ofstream&
// Returns: N/A
void print(std::vector<times>& printMe, std::ofstream& outfile);

int main()
{
    // Creates stream variables
    std::ifstream infile;
    std::ofstream outfile;

    // Calls openFiles
    openFiles(infile, outfile);
    printHeaders(outfile);

    // Variables
    int numTimes;
    int start;
    int len;
    int end;
    std::vector<times> options;

    // Reads in number of data sets
    infile >> numTimes;

    // loops through data sets and loads vector
    for(int i = 0; i < numTimes; i++)
    {
        // Temporary (overwritten) times variable
        times temp;
        
        // Read in start and length and set end to calculation
        infile >> start;
        infile >> len;
        end = calculateEndTime(start, len);

        // Sets the times variable based on info pulled from file
        temp.startTime = start;
        temp.length = len;
        temp.endTime = end;

        // Pushes temp variable on the end of the vector
        options.push_back(temp); 
    }

    // Calls sorting algorithm 
    selectionSort(options);

    // Chooses the schedule for an individual person
    options = chooseAvaiable(options);

    // Prints the schedule asthetically 
    print(options, outfile);

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
    outfile << "Program 3 - Greedy Algorithm\n";
    outfile << "11/9/2021\n";
    outfile << "This program will solve how many tasks can be" << 
    "completed based on the start time and length of the task\n\n";

    outfile << std::left << std::setw(14) << "Start Time" 
    << std::setw(12) << "Length" << std::setw(18) << "End Time\n";
}
int calculateEndTime(int start, int length)
{
    // sums start and length to calculate endTime
    return start + length;
}
void selectionSort(std::vector<times> &sortMe)
{
    // Loops through sortMe's size
    for(int i = 0; i < sortMe.size(); i++)
    {
        // Moves sorted section further down vector
        int lowestIndex = i;

        // Loops thorugh the remaining section of vector past sorted section
        for(int j = i; j < sortMe.size(); j++)
        {
            // compares current pos to the lowest index 
            if(sortMe[j].endTime < sortMe[lowestIndex].endTime)
            {
                // sets lowestIndex to current j value
                lowestIndex = j;
            }
        }

        // Uses std::swap to switch the current value and the value with the smallest value
        std::swap(sortMe[i], sortMe[lowestIndex]);
    }
}
std::vector<times> chooseAvaiable(std::vector<times> &useMe)
{
    // Creates return Vector of type times
    std::vector<times> returnVec;

    // Loops through useMe's size
    for(int i = 0; i < useMe.size(); i++)
    {
        // If it is the first position, automatically push it onto the new vector
        if(i == 0)
        {
            returnVec.push_back(useMe[i]);
        }
        else
        {
            // If the last item in return vector <= the vector with all tasks current startTime
            if(returnVec[returnVec.size()-1].endTime <= useMe[i].startTime)
            {
                returnVec.push_back(useMe[i]);
            }
        }
    }

    // Return vector with only possible values
    return returnVec;
}
void print(std::vector<times>& printMe, std::ofstream& outfile)
{
    // Left aligns
    outfile << std::left;

    // Loops through vector and prints each value with spacing
    for(int i = 0; i < printMe.size(); i++)
    {
        outfile << std::setw(14) << printMe[i].startTime 
        << std::setw(12) << printMe[i].length << std::setw(18) << printMe[i].endTime << "\n";
    }

    // Prints total number of activities 
    outfile << "\nMaximum number of activities scheduled is " << printMe.size() << ".\n";
}