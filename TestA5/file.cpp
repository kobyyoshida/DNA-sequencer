#include <iostream>
#include "File.h"

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

File::File() : data() //default constructor
{
	numLines = 0;
	currLine = 0;
	numChar = 0;
	name = "";
}

File::File(string n) : data()//overloaded constructor
{
	numLines = 0;
	currLine = 0;
	numChar = 0;
	name = n;
}

File::~File() //deconstructor
{}

string File::readLine(int l) //returns a line given the line number
{
	return data[l-1];
}

string File::nextLine() //returns the next line
{
	if((currLine+1) <= numLines && (currLine+1) > 0)
	{
		currLine = currLine+1;
		return data[currLine-1];
	}
	else
		cout << "Invalid line number: does not exist" << endl;
}
string File::prevLine() //returns the previous line
{
	if((currLine-1) <= numLines && (currLine-1) > 0)
	{
		currLine = currLine-1;
		return data[currLine-1];
	}
	else
		cout << "Invalid line number: does not exist" << endl;
}

void File::setName(string n) //sets the file name
{
	name =n;
}

void File::process() //gets the path and data of a file
{
	if (name==""){ //getting a file to open from the user
		cout << "Enter a file name: " << endl;
		cin >> name;
	}
	file.open(name.c_str());
	if(file.is_open())
	{
		string currLine;
		while(getline(file, currLine))
		{
			data.push_back(currLine);
			numChar += currLine.length(); //setting number of characters in line
			numLines++; //increasing the number of lines while reading file
		}
		file.close(); //closing the file
		printAll(); //printing file data

	}else{
		cout << "Invalid file: could not open" <<endl;
	}
}

int File::getCurrLine() //accessor for current line variable
{
	return currLine;
}

int File::getNumLines() //accessor for number of lines variable
{
	return numLines;
}

void File::printAll() //prints all the elements in vector form
{
	for(int i =0; i<numLines; ++i)
		cout <<data[i]<<endl;
}
