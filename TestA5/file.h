#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

class File
{
	public:
		File(); //default constructor
		File(string name);	//overloaded constructor
		~File(); //destructor

		string readLine(int l); //returns a line given the line number
		string nextLine(); //returns the next line
		string prevLine(); //returns the previous line

		void setName(string n); //sets the file name
		void process(); //gets the path and data of a file
		int getCurrLine(); //returns the current line number
		int getNumLines(); //returns the total number of lines in a file
		void printAll(); //prints all the elements in vector form

	private:
		fstream file; //file stream
		string name; //name of the file
		unsigned int numLines; //count variables should be unsigned
		unsigned int currLine;
		unsigned int numChar;

		vector<string> data;
};

#endif
