
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	string filename;
	int count(0);
	double tmp, first1, first2, last1, last2;
	cout << "Please enter a filename: ";
	getline(cin, filename);
	inFile.open(filename);

	while (!inFile)
	{
		cerr << "Could not open file, please enter a new filename: " << endl;
		inFile.clear();
		getline(cin, filename);
		inFile.open(filename);
	}

	if (inFile.is_open())
	{
		while (!inFile.eof() || !inFile.fail())
		{
			inFile >> tmp;

			if (count == 0)
			{
				first1 = tmp;
			}
			else if (count == 1)
			{
				first2 = tmp;
			}
			count++;
		}
		last1 = tmp;	
	}
	inFile.close();

	inFile.open(filename);
	for (int i = 0; i <= (count - 3); i++)
	{
		inFile >> last2;
	}
	inFile.close();

	cout << "The number of numbers is: " << (count - 1) << endl;
	cout << "The first number is: " << first1 << endl;
	cout << "The second number is: " << first2 << endl;
	cout << "The last number is: " << last1 << endl;
	cout << "The second to last number is: " << last2 << endl;
	return 0;
}