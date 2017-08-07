// Program counts frequency of each alphabetic 
//   character in text file.

#include < fstream >
#include < iostream >
#include < cctype >
#include <string>
#include <ostream>
#include <iomanip>
using namespace std;


const int SIZE = 91;
void PrintOccurrences(const  int[]); // Prototype 

int  main()
{
	ifstream dataFile;
	int  freqCount[SIZE];
	char ch;
	char index;
	
	dataFile.open("my.dat"); // Open 
	if (!dataFile)         // Verify success
	{
		cout << "CAN’T OPEN INPUT FILE !" << endl;
		return  1;
	}
	for (int m = 0; m < SIZE; m++) // Zero array
		freqCount[m] = 0;

	// Read file one character at a time
	dataFile.get(ch);  // Priming read
	while (dataFile)	// While read successful
	{
		if (isalpha(ch))
		{
			if (islower(ch))
				ch = toupper(ch);

			freqCount[ch] = freqCount[ch] + 1;
		}
		dataFile.get(ch); // Get next character
	}
	PrintOccurrences(freqCount);
	return  0;
}
void PrintOccurrences(
	/* in */ const int  freqCount[])
	// Prints each alphabet character and its frequency
	// Precondition:
	//	freqCount[‘A’ . . ‘Z’] are assigned
	// Postcondition:
	//	freqCount[‘A’ . . ‘Z’] have been printed
{
	char  index;
	cout << "File contained " << endl;
	cout << "LETTER      OCCURRENCES" << endl;
	for (index = 'A'; index <= 'Z'; index++)
	{
		cout << setw(4) << index << setw(10)
			<< freqCount[index] << endl;
	}
}
