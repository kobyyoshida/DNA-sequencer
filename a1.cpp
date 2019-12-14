#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int countA = 0;
int countC = 0;
int countT = 0;
int countG = 0;

int countAA = 0;
int countAC = 0;
int countAT = 0;
int countAG = 0;

int countCA = 0;
int countCC = 0;
int countCT = 0;
int countCG = 0;

int countTA = 0;
int countTC = 0;
int countTT = 0;
int countTG = 0;

int countGA = 0;
int countGC = 0;
int countGT = 0;
int countGG = 0;

int totalBigrams = 0;
int lineCount = 0;

double percentAA = 0;
double percentAC = 0;
double percentAT = 0;
double percentAG = 0;

double percentCA = 0;
double percentCC = 0;
double percentCT = 0;
double percentCG = 0;

double percentTA = 0;
double percentTC = 0;
double percentTT = 0;
double percentTG = 0;

double percentGA = 0;
double percentGC = 0;
double percentGT = 0;
double percentGG = 0;

double percentA = 0;
double percentC = 0;
double percentG = 0;
double percentT = 0;

double mean = 0;
double variance = 0;
double sd = 0;

string line;

//void uppercase(string dna){//this is just a method to make sure the letters are all capital
//  for(int i=0; i< dna.size();i++)
//    dna[i].toupper();
//}

int countBigrams(string line){
  //needs loop right here to run this through the whole text file
  //i ended up putting the loop in the main method, but unsure if i need to put the loop here instead

  //each if statement will check each bigram and adds it to the total
  //line.uppercase(line);
  for(int i = 0; i<line.size()-2; i++){
    string line = line.substr(i,2);
    lineCount++;
    if(line == "AA"){
      countAA++;
      countA + 2;
    }
    else if(line == "AC"){
      countAC++;
      countA++;
      countC++;
    }
    else if(line == "AT"){
      countAT++;
      countA++;
      countT++;
    }
    else if(line == "AG"){
      countAG++;
      countA++;
      countG++;
    }
    else if(line == "CA"){
      countCA++;
      countC++;
      countA++;
    }
    else if(line == "CC"){
      countCC++;
      countC + 2;
    }
    else if(line == "CT"){
      countCT++;
      countC++;
      countT++;

    }
    else if(line == "CG"){
      countCG++;
      countC++;
      countG++;

    }
    else if (line == "TA"){
      countTA++;
      countT++;
      countA++;
    }
    else if (line == "TC"){
      countTC++;
      countT++;
      countC++;
    }
    else if (line == "TT"){
      countTT++;
      countT + 2;
    }
    else if (line == "TG"){
      countTG++;
      countT++;
      countG++;
    }
    else if (line == "GA"){
      countGA++;
      countG++;
      countA++;
    }
    else if (line == "GC"){
      countGC++;
      countG++;
      countC++;
    }
    else if (line == "GT"){
      countGT++;
      countG++;
      countT++;
    }
    else if (line == "GG"){
      countGG++;
      countG + 2;
    }
    else{
      cout << "Character does not exist. " << endl;
}
  }
}

int calculateBigramStats(){
  //calculating the total amount of bigrams in the file
  totalBigrams = countAA + countAC + countAT + countAG + countCA + countCC + countCT + countCG + countTA + countTC + countTT + countTG + countGA + countGC + countGT + countGG;

  //these calculate the percent of each bigram out of the total amount
  percentAA = countAA/totalBigrams;
  percentAC = countAC/totalBigrams;
  percentAT = countAT/totalBigrams;
  percentAG = countAG/totalBigrams;

  percentGA = countGA/totalBigrams;
  percentGC = countGC/totalBigrams;
  percentGT = countGT/totalBigrams;
  percentGG = countGG/totalBigrams;

  percentCA = countCA/totalBigrams;
  percentCC = countCC/totalBigrams;
  percentCT = countCT/totalBigrams;
  percentCG = countCG/totalBigrams;

  percentTA = countTA/totalBigrams;
  percentTC = countTC/totalBigrams;
  percentTT = countTT/totalBigrams;
  percentTG = countTG/totalBigrams;


  mean = (line.size()-1)/lineCount;
  variance = pow((line.size()-1)-mean,2)/lineCount;
  sd = sqrt(variance);
}

int main(int argc, char *argv[]){

  // reading a file with the dna sequences
  ofstream myfile;
  myfile.open("dna.txt");

  while(getline(myfile)){
    myfile.countBigrams(line);//dont forget to put a parameter in here before running
    myfile.calculateBigramStats();
  }
  myfile.close();

  //writing the new file
  ofstream myfile;
  myfile.open("KobyYoshida.out", std::ofstream::out | std::ofstream::app);

  //add here once we can randomize the numbers into letters

  //this code block will begin writing dna sequences to a new file
  //honestly im not sure what this does, something about creating a random number
  srand(time(NULL));

  for(int i = 0; i < 1000; i++){//generating random numbers to convert into ATGC
    double a = (double(rand())/(RAND_MAX)); //generate a random double a
    double b = (double(rand())/(RAND_MAX)); //generate a random double b
    double c = sqrt((-2)*log(a))*cos(2*(M_PI)*b); //this line uses the given equation to generate a random double based off of the previous doubles
    double d = (sd*c)+mean;
  }


  cout << "The total number of bigrams is:" << totalBigrams;

  cout << "The total percentage of AA bigrams is: " << percentAA << endl;
  cout << "The total percentage of AC bigrams is: " << percentAC << endl;
  cout << "The total percentage of AT bigrams is: " << percentAT << endl;
  cout << "The total percentage of AG bigrams is: " << percentAG << endl;
  cout << "The total percentage of CA bigrams is: " << percentCA << endl;
  cout << "The total percentage of CC bigrams is: " << percentCC << endl;
  cout << "The total percentage of CT bigrams is: " << percentCT << endl;
  cout << "The total percentage of CG bigrams is: " << percentCG << endl;
  cout << "The total percentage of TA bigrams is: " << percentTA << endl;
  cout << "The total percentage of TC bigrams is: " << percentTC << endl;
  cout << "The total percentage of TT bigrams is: " << percentTT << endl;
  cout << "The total percentage of TG bigrams is: " << percentTG << endl;
  cout << "The total percentage of GA bigrams is: " << percentGA << endl;
  cout << "The total percentage of GC bigrams is: " << percentGC << endl;
  cout << "The total percentage of GT bigrams is: " << percentGT << endl;
  cout << "The total percentage of GG bigrams is: " << percentGG << endl;

  cout << mean << endl;
  cout << variance << endl;
  cout << sd << endl;

  myfile << "Koby Yoshida" << endl;
  myfile << "2329586" << endl;
  myfile << "The mean is " << mean << endl;
  myfile << "The standard deviation is " << sd << endl;
  myfile << "The variance is " << variance << endl;
  myfile << "The sum is " << endl;

  return 0;
  }
