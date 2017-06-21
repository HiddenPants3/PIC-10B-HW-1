/**************************************************
   Jeremy Wong
   SID: 504 675 576
   Date: 10/10/2016

   Declaration of functions and the class Student which are used
   to read and write file according to the file name passed
   to the function compute_overall_score() while 
   computing the overall score with the member functions
   in the class Student.
**************************************************/

#ifndef HW1_H
#define HW1_H

#include <string>;
#include <vector>;
#include <fstream>;
#include <iostream>;
#include <sstream>;
#include <iomanip>;

using std::string;
using std::vector;

void compute_overall_score(string inputFile, string outputFile);
float compareScore(const float &a, const float &b);
void printFile(string file);

//Student interface
class Student{
public:
   //Constructor
   Student();

   //Mutator
   void readFile(string inputFile);

   //Accessor
   void writeFile(string outputFile);
   float finalScoreA();
   float finalScoreB();
   float weightedHwScore();

private:
   vector<float> hwScore;
   vector<float> midtermScore;
   float finalScore;
};

#endif
