/*
 *  Name: Phu Ha
 *
 * 	Project Name: CSC450-CTA05
 *
 *	Project Purpose: Take user input and save to file, then reverse file
 *
 *	Algorithm Used: reversing a string
 *
 *	Program Inputs: user inputs
 *
 *	Program Outputs: a file to save user input, a file to save reversed texts of the first file
 *
 *	Program Limitations:
 *
 *	Program Errors:
 *
 *  Created on: February 18, 2024
 *      Author: Phu Ha
 */

// libraries
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

// This method take input string and reverse it
string reverseString(string *inputString)
{
	// original string
	string strToReverse = *inputString;
	// string to save the reversed string
	string reversed = "";

	// loop through original array backward
	for (int i = strToReverse.length() - 1; i >=0; i--)
	{
		// add each letter to reversed
		reversed += strToReverse[i];
	}

	return reversed;
}

// this method takes two files name, reversed content of the first and write it
// to the second file
void reverseChars(string *filename1, string *filename2) {
	// filename1
	ifstream fileToRead(*filename1);
	// fikename2
	ofstream fileToWrite(*filename2);

	// variable to store contents in file 1
	string texts;

	// read file 1 and save contents to texts
	if (fileToRead.is_open())
	{
		string line;
		while (getline(fileToRead, line))
		{
			texts += line;
			texts += " ";
		}
		fileToRead.close();
	} else {
		cout << "Unable to open file.";
		return;
	}

	// reversed texts
	texts = reverseString(&texts);

	// write reversed texts to file 2
	if (fileToWrite.is_open())
	{
		fileToWrite << texts;
		fileToWrite.close();
	} else {
		cout << "Unable to open file.";
		return;
	}
}

int main() {

	// Part 1. Get user input and append to file

	// variable to store user input
	string userInput;
	// ask user for input
	cout << "Please enter your input: " << endl;
	//save input
	getline(cin, userInput);

	// open file
	ofstream myFile("CSC450_CT5_mod5.txt", ios::app);
	if (myFile.is_open())
	{
		// save user input to file
		myFile << userInput + "\n";
		myFile.close();
	}
	else {
		cout << "Unable to open file.";
	}

	// Part 2, reverse all characters in a file and save it to another file
	string filename1 = "CSC450_CT5_mod5.txt";
	string filename2 = "CSC450-mod5-reverse.txt";

	// call function to perform the reversing
	reverseChars(&filename1, &filename2);

	return 0;
}


