/**********************************
   Jeremy Wong
   SID: 504 675 576
   Date: 10/10/2016


   Implementation of functions defined in
   the header file hw1.h.
**********************************/
#include "hw1.h";

/*
NON-MEMBER FUNCTIONS
*/

/*
   Compute the overall score by creating a Student object 
   and first read the assigned input file. 
   Then compute the result within the function that will
   output the desired file.
   And then print the result in the console.
*/
void compute_overall_score(string input, string output){
   Student studentA;
   studentA.readFile(input);
   studentA.writeFile(output);
   printFile(output);
}

// Print an input file line by line.
void printFile(string file){
   string line;
   std::ifstream fin(file);
   if (fin.is_open())
   {
      while (std::getline(fin, line)){
         std::cout << line << "\n";
      }
   }
   fin.close();
}

// Compare two score(float) and return the higher one.
// Return the first one when two are equals.
float compareScore(const float &a, const float&b){
   if (a >= b){
      return a;
   }
   else { return b; }
}

//Default constructor
Student::Student(){
   hwScore.clear();
   midtermScore.clear();
   finalScore = 0;
}

/*
   Read the file with the assigned file name (string) and
   then save scores in the private member fields.
   Tell the user when failing to open the correct file.
*/
void Student::readFile(string inputFile){
   int score = 0;
   string line;
   std::ifstream fin(inputFile);
   if (fin.is_open())
   {
      while (std::getline(fin, line))
      {
         std::istringstream ss(line);
         if (hwScore.empty() == true)
         {
            while (ss >> score){
               hwScore.push_back(score); 
            } 
         }
         else if (midtermScore.empty() == true) { 
            while (ss >> score){ 
               midtermScore.push_back(score); 
            } 
         }
         else {
            ss >> score;
            this->finalScore = score;
         }
      }
   }
   else 
   {
      std::cout << "Fail to open file: " << inputFile << "\n";
   }
   fin.close();
}

/*
Create a file with the name as assigned.
Write the two calculated scores, then compare
both, and write the higher score in the desired precision.
*/
void Student::writeFile(string outputFile){
   std::ofstream fout(outputFile);
   string output;
   if (fout.is_open()){
      fout << "Score A: " << finalScoreA() << "\n";
      fout << "Score B: " << finalScoreB() << "\n";
      fout << std::fixed;
      fout << std::setprecision(2);
      fout << "Overall score: "
         << compareScore(finalScoreA(), finalScoreB()) << "%\n";
   }
   fout.close();
}

/*
   Calculate the final score with the first grading breakdown:
   25% Homework + 20% Midterm 1 + 20% Midterm 2 + 35% Final
*/
float Student::finalScoreA(){
   float total = 0;
   total += weightedHwScore() ;
   for (int i = 0; i < midtermScore.size(); i++){
      total += (midtermScore[i] / 100 * 20);
   }
   total += (finalScore * 35 /100);
   return total;
}

/*
   Calculate the final score with the second grading breakdown:
   25% Homework + 30% Highest Midterm + 44% Final
*/
float Student::finalScoreB(){
   float total = 0;
   total += weightedHwScore();
   total += (compareScore(midtermScore[0],
      midtermScore[1]) * 30 / 100);
   total += (finalScore * 44 / 100);
   return total;
}

// Calculated the weighted homework score.
float Student::weightedHwScore(){
   float score = 0;
   for (int i = 0; i < hwScore.size(); i++){
      score += hwScore[i];
   }
   score = (score / hwScore.size());
   score = (score * 25 / 20);
   return score;
}