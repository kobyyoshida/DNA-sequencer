//Koby Yoshida
//2329586
//Assignment 1
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

string line;
string newDna;
string response = "yes";
string filePath;

int main(int argc, char* argv[]){
  //put all variables in the main to initialize when the loop restarts
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

  float newA;
  float newC;
  float newT;
  float newG;

  //these are floats so we can perform operations on them later
  float totalChars = 0;
  float totalBigrams = 0;

  int x = 0; //random number for a while loop

  double mean = 0;
  double variance = 0;
  double sd = 0;

  //reading from a file using command line args
  while (response == "yes"){
    if (argc != 2){
      cerr << "Could not find file. ";
      return 0;
    }
    else
      filePath = argv[1];
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
    double percentAA = countAA/totalBigrams;
    double percentAC = countAC/totalBigrams;
    double percentAT = countAT/totalBigrams;
    double percentAG = countAG/totalBigrams;

    double percentGA = countGA/totalBigrams;
    double percentGC = countGC/totalBigrams;
    double percentGT = countGT/totalBigrams;
    double percentGG = countGG/totalBigrams;

    double percentCA = countCA/totalBigrams;
    double percentCC = countCC/totalBigrams;
    double percentCT = countCT/totalBigrams;
    double percentCG = countCG/totalBigrams;

    double percentTA = countTA/totalBigrams;
    double percentTC = countTC/totalBigrams;
    double percentTT = countTT/totalBigrams;
    double percentTG = countTG/totalBigrams;

    double percentA = countA/totalChars;
    double percentT = countT/totalChars;
    double percentC = countC/totalChars;
    double percentG = countG/totalChars;

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



    //writing to a file
    ofstream outputfile;
    outputfile.open("KobyYoshida.txt", std::ofstream::out | std::ofstream::app); //opens a file to write in and puts it in the correct mode to write
    outputfile << "Koby Yoshida\n" << endl;
    outputfile << "2329586\n" << endl;
    outputfile << "CPSC 350\n" << endl;
    outputfile << "Section 1\n" << endl;
    outputfile << "Assignment 1\n" << endl;
    outputfile << endl;
    outputfile << "The probability of the A nucleotide is "<< percentA << "\n"<< endl;
    outputfile << "The probability of the C nucleotide is "<< percentC << "\n"<< endl;
    outputfile << "The probability of the T nucleotide is "<< percentT << "\n"<< endl;
    outputfile << "The probability of the G nucleotide is "<< percentG << "\n"<< endl;
    outputfile << "The probability of the AA bigram is "<< percentAA << "\n"<< endl;
    outputfile << "The probability of the AT bigram is "<< percentAT << "\n"<< endl;
    outputfile << "The probability of the AG bigram is "<< percentAG << "\n"<< endl;
    outputfile << "The probability of the AC bigram is "<< percentAC << "\n"<< endl;
    outputfile << "The probability of the CA bigram is "<< percentCA << "\n"<< endl;
    outputfile << "The probability of the CT bigram is "<< percentCT << "\n"<< endl;
    outputfile << "The probability of the CG bigram is "<< percentCG << "\n"<< endl;
    outputfile << "The probability of the CC bigram is "<< percentCC << "\n"<< endl;
    outputfile << "The probability of the TA bigram is "<< percentTA << "\n"<< endl;
    outputfile << "The probability of the TT bigram is "<< percentTT << "\n"<< endl;
    outputfile << "The probability of the TC bigram is "<< percentTC << "\n"<< endl;
    outputfile << "The probability of the TG bigram is "<< percentTG << "\n"<< endl;
    outputfile << "The probability of the GA bigram is "<< percentGA << "\n"<< endl;
    outputfile << "The probability of the GT bigram is "<< percentGT << "\n"<< endl;
    outputfile << "The probability of the GG bigram is "<< percentGG << "\n"<< endl;
    outputfile << "The probability of the GC bigram is "<< percentGC << "\n"<< endl;
    outputfile << endl;
    outputfile << "The number of lines is " << lineCount << "\n"<< endl;
    outputfile << "The mean is " << mean << "\n"<< endl;
    outputfile << "The variance is " << variance << "\n"<< endl;
    outputfile << "The standard deviation is " << sd << "\n"<< "\n"<< endl;
    outputfile << endl;
    outputfile << "New DNA sequence: " << "\n"<< endl;

    //gives us a loop that will run 1000 times using the letters we found above
    while(x<1000){
      random_shuffle(newDna.begin(), newDna.end());
      outputfile << newDna;
      x++;
    }

    outputfile.close();
    //asking user if they are going to run another file
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
