#include<iostream>
#include<fstream>
using namespace std;

#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "Hello World!";
	ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	fout << "Hello World!" << endl;
	fout.close();
	system("notepad File.txt");
#endif WRITE_TO_FILE

	char filename[_MAX_FNAME] = {};
	cout << "ֲגוהטעו טלÿ פאיכא: ";
	cin.getline(filename, _MAX_FNAME);
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		const int SIZE = 256;
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();
	}
	else
	{
		cout << "Error: File not found!" << endl;
	}
}