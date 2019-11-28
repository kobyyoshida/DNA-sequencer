//hello
//Koby Yoshida
//2329586
//Assignment 1
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;



int main(int argc, char**){
  int lineCount = 0;

  int countT = 0;
  int countA = 0;
  int countC = 0;
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

  int newA;
  int newC;
  int newT;
  int newG;

  int totalChars = 0;
  int totalBigrams = 0;

  int x = 0; //random number for a while loop

  double mean = 0;
  double variance = 0;
  double sd = 0;

  string line;
  string newDna;
  string response = "yes";
  string filePath = "dna.txt";
  //reading from a file
  while (response == "yes"){

    ifstream inputfile;
    inputfile.open(filePath);

    if(!inputfile){//if the file does not exist
      cerr << "Could not find file. " << endl;
      return 0;
    }
    else{//if the file does exist
      cout << "Opened file " << filePath << endl;
    }

    while(getline(inputfile, line)){//iterates through each line as long as there is not an empty space
      lineCount++;

        for (int i = 0; i < line.size()-1; i++) {//this loop will count the letters one by one and count them
          if(toupper(line[i] == 'A')) {
            countA++;
            totalChars++;
          }
          else if(toupper(line[i] == 'C')) {
            countC++;
            totalChars++;
          }
          else if(toupper(line[i] == 'T')) {
            countT++;
            totalChars++;
          }
          else if(toupper(line[i] == 'G')) {
            countG++;
            totalChars++;
          }
          else{
            cout << "Letter is not a nuecleotide. " << endl;
            return 0;
          }
        }
      }
          //string bigram = line.substr(i,2);

      	for (int i = 0; i < line.size()-1; i+=2){//counting bigrams loop
      		if(line[i] == 'A' &&  line[i+1] == 'T'){
      			countAT++;
            totalBigrams++;
          }
          else if(line[i] == 'A' && line[i+1] == 'A'){
      			countAA++;
            totalBigrams++;
          }
          else if(line[i] == 'A' && line[i+1] == 'C'){
            countAC++;
            totalBigrams++;
          }
          else if(line[i] == 'A' && line[i+1] == 'G'){
      			countAG++;
            totalBigrams++;

      		}
      		else if(line[i] == 'C' && line[i+1] == 'A'){
            countCA++;
            totalBigrams++;

          }
          else if(line[i] == 'C' && line[i+1] == 'C'){
            countCC++;
            totalBigrams++;

          }
          else if(line[i] == 'C' && line[i+1] == 'T'){
      			countCT++;
            totalBigrams++;

      		}
      	  else if(line[i] == 'C' && line[i+1] == 'G'){
      			countCG++;
            totalBigrams++;

          }
          else if(line[i] == 'T' && line[i+1] == 'A'){
      			countTA++;
            totalBigrams++;

          }
          else if(line[i] == 'T' && line[i+1] == 'C'){
      			countTC++;
            totalBigrams++;

          }
      		else if(line[i] == 'T' && line[i+1] == 'T'){
      			countTT++;
            totalBigrams++;

      		}
      		else if(line[i] == 'T' && line[i+1] == 'G'){
      			countTG++;
            totalBigrams++;

      		}
      		else if(line[i] == 'G' && line[i+1] == 'A'){
      			countGA++;
            totalBigrams++;

      		}
      		else if(line[i] == 'G' && line[i+1] == 'C'){
      			countGC++;
            totalBigrams++;

      		}
      		else if(line[i] == 'G' && line[i+1] == 'T'){
      		  countGT++;
            totalBigrams++;

      		}
          else if(line[i] == 'G' && line[i+1] == 'G'){
      			countGG++;
            totalBigrams++;

      		}
      	}
      		cout << line << endl;
    inputfile.close();

    //totalBigrams = countAA + countAC + countAT + countAG + countCA + countCC + countCT + countCG + countTA + countTC + countTT + countTG + countGA + countGC + countGT + countGG;

    //these calculate the percent of each bigram out of the total amount
    float percentAA = countAA/totalBigrams;
    float percentAC = countAC/totalBigrams;
    float percentAT = countAT/totalBigrams;
    float percentAG = countAG/totalBigrams;

    float percentGA = countGA/totalBigrams;
    float percentGC = countGC/totalBigrams;
    float percentGT = countGT/totalBigrams;
    float percentGG = countGG/totalBigrams;

    float percentCA = countCA/totalBigrams;
    float percentCC = countCC/totalBigrams;
    float percentCT = countCT/totalBigrams;
    float percentCG = countCG/totalBigrams;

    float percentTA = countTA/totalBigrams;
    float percentTC = countTC/totalBigrams;
    float percentTT = countTT/totalBigrams;
    float percentTG = countTG/totalBigrams;

    float percentA = countA/totalChars;
    float percentT = countT/totalChars;
    float percentC = countC/totalChars;
    float percentG = countG/totalChars;

    //other calculations needed for the bigrams
    mean = (line.size()-1)/lineCount;
    variance = pow((line.size()-1)-mean,2)/lineCount;
    sd = sqrt(variance);


    //generating random numbers to convert into ATGC
    double a = (double(rand())/(RAND_MAX)); //generate a random double a
    double b = (double(rand())/(RAND_MAX)); //generate a random double b
    double c = sqrt((-2)*log(a))*cos(2*(M_PI)*b); //this line uses the given equation to generate a random double based off of the previous doubles
    double d = (sd*c)+mean;

    //gives us new values for when we write a new file based off the old information
    newA = d * percentA;
    newT = d * percentT;
    newC = d * percentG;
    newG = d * percentC;

    //these for loops will add letters to a string that will later be shuffled
    for(int i = 0; i < newA; i++){
      newDna += "A";
    }
    for(int i = 0; i < newT; i++){
      newDna += "T";
    }
    for(int i = 0; i < newG; i++){
      newDna += "G";
    }
    for(int i = 0; i < newC; i++){
      newDna += "C";
    }

    while(x<1000){
      random_shuffle(newDna.begin(), newDna.end());
      x++;
    }


    //writing to a file
    ofstream outputfile;
    outputfile.open("KobyYoshida.txt", std::ofstream::out | std::ofstream::app);
    outputfile << "Koby Yoshida" << endl;
    outputfile << "2329586" << endl;
    outputfile << "CPSC 350" << endl;
    outputfile << "Section 1" << endl;
    outputfile << "Assignment 1" << endl;
    outputfile << endl;
    outputfile << "The percentage of the A nucleotide is "<< percentA << endl;
    outputfile << "The percentage of the C nucleotide is "<< percentC << endl;
    outputfile << "The percentage of the T nucleotide is "<< percentT << endl;
    outputfile << "The percentage of the G nucleotide is "<< percentG << endl;
    outputfile << "The percentage of the AA bigram is "<< percentAA << endl;
    outputfile << "The percentage of the AT bigram is "<< percentAT << endl;
    outputfile << "The percentage of the AG bigram is "<< percentAG << endl;
    outputfile << "The percentage of the AC bigram is "<< percentAC << endl;
    outputfile << "The percentage of the CA bigram is "<< percentCA << endl;
    outputfile << "The percentage of the CT bigram is "<< percentCT << endl;
    outputfile << "The percentage of the CG bigram is "<< percentCG << endl;
    outputfile << "The percentage of the CC bigram is "<< percentCC << endl;
    outputfile << "The percentage of the TA bigram is "<< percentTA << endl;
    outputfile << "The percentage of the TT bigram is "<< percentTT << endl;
    outputfile << "The percentage of the TC bigram is "<< percentTC << endl;
    outputfile << "The percentage of the TG bigram is "<< percentTG << endl;
    outputfile << "The percentage of the GA bigram is "<< percentGA << endl;
    outputfile << "The percentage of the GT bigram is "<< percentGT << endl;
    outputfile << "The percentage of the GG bigram is "<< percentGG << endl;
    outputfile << "The percentage of the GC bigram is "<< percentGC << endl;
    outputfile << endl;
    outputfile << "The number of lines is " << lineCount << endl;
    outputfile << "The mean is " << mean << endl;
    outputfile << "The variance is " << variance << endl;
    outputfile << "The standard deviation is " << sd << endl;
    outputfile << endl;
    outputfile << newDna;

    outputfile.close();

  cout << "Would you like to run another file?";
  cin >> response;
  if (response == "yes"){
    cout << "Enter the name of the file. ";
    cin >> filePath;
  }
  else{
    return 0;
  }
}
}
