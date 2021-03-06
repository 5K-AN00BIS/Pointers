// Ryan Bachman - C++ Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ryan Bachman
// CSC215 C/C++ Programming
// University of Advancing Technology
// C++ Pointers
// November 05, 2018

// Preprocessor directives.
#include "pch.h"
#include <iostream>
#include <string>

// Global declarations.
using namespace std;

// Function prototypes.
void jumbleName(string* const pFirst, string* const pMiddle, string* const pLast);
void unjumbleName(string* const pFirst, string* const pMiddle, string* const pLast);
int countLetters(string* const pFirst, string* const pMiddle, string* const pLast);

// Main function.
int main()
{
	// Gets user input on their first name.
    string firstName;
	cout << "Please enter your first name: ";
	cin >> firstName;
	// Gets user input on their middle name.
    string middleName;
	cout << "Please enter your middle name: ";
	cin >> middleName;
	// Gets user input on their last name.
	string lastName;
	cout << "Please enter your last name: ";
	cin >> lastName;

	// Calls the jumbleName function.
    jumbleName(&firstName, &middleName, &lastName);
    cout << "\n\nHello there " << firstName << " " << middleName << " " << lastName << "!\n";

	cout << "Er... I think I got that wrong there...\n";
	cout << "I definitely meant to say ";
	// Calls the unjumbleName function.
	unjumbleName(&firstName, &middleName, &lastName);
	cout << firstName << " " << middleName << " " << lastName << ".\n\n";

	cout << "Sorry again about the confusion there...\n";
	cout << "Just to make it up to you, I'll count the letters in your full name.\n";
	// Calls the countLetters function.
	cout << "You have " << countLetters(&firstName, &middleName, &lastName) << " letters in your name!\n\n";

    return 0;
}

// Functions
// jumbleName will disorganize the full name entered by the user previously.
void jumbleName(string* const pFirst, string* const pMiddle, string* const pLast)
{
    // Store value pointed to by pFirst in temp.
    string temp = *pFirst;
    // Store value pointed to by pMiddle in address pointed to by pFirst.
    *pFirst = *pMiddle;
    // Store value originally pointed to by pLast in address pointed to by pMiddle.
    *pMiddle = *pLast;
	// Stores value originally pointed to by pLast in address pointed to temp.
	*pLast = temp;
}

// unjumbleName will reorganize the full name as the user expects it to be.
void unjumbleName(string* const pFirst, string* const pMiddle, string* const pLast)
{
    // Store value pointed to by pMiddle in temp.
    string temp = *pMiddle;
    // Store value pointed to by pFirst in address pointed to by pMiddle.
    *pMiddle = *pFirst;
    // Store value originally pointed to by pLast in address pointed to by pFirst.
    *pFirst = *pLast;
	// Store value orignally pointed to by pLast in address pointed to temp.
	*pLast = temp;
}

// countLetters will count the amount of letters in the users name.
int countLetters(string* const pFirst, string* const pMiddle, string* const pLast)
{
	// Add together the size of all the pointers and returns the int letterCount.
	int letterCount = pFirst->size() + pMiddle->size() + pLast->size();

	return letterCount;
}
