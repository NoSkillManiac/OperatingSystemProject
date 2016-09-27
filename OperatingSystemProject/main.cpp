#include "Disk.h"
#include "Memory.h"
#include <fstream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

Disk* hdd;
Memory* mem;
queue<unsigned int>* directory;

enum readstate { NONE, TEXT, DATA };

int* splitstr(string line)
{
	stringstream ss;
	string token;
	int* hdr = new int[3];
	int curlen;

	//first piece
	curlen = line.find(" ");
	token = line.substr(0, curlen);
	ss << hex << token;
	ss >> hdr[0];
	line = line.substr(curlen); //cut off the token amt

	//second piece
	curlen = line.find(" ");
	token = line.substr(0, curlen);
	ss << hex << token;
	ss >> hdr[1];
	line = line.substr(curlen);

	//third piece should just be the last number and then end of string
	ss << hex << line;
	ss >> hdr[2];

	return hdr;
}

void loadPrograms()
{
	//load the program file
	ifstream file;
	file.open("Program-File.txt", ios::in);
	string line;
	readstate state = NONE;
	unsigned int currentfile = -1;

	while (getline(file, line))
	{
		if (line.find("// JOB ") != string::npos)
		{
			state = TEXT;

			//start a new file
			currentfile = hdd->mkfile();
			directory->push(currentfile);

			//remove "// JOB "
			line = line.substr(0, 8);

			//parse line into pieces
			int* hdr = splitstr(line);

			//append the numbers to the hdd file
			hdd->append(currentfile, hdr, 3);

			//mem clean
			delete hdr;
		}
		else if (line.find("// Data ") != string::npos)
		{
			state = DATA;

			//remove "// Data "
			line = line.substr(0, 9);

			//split into the three number components
			int* hdr = splitstr(line);

			//write to file
			hdd->append(currentfile, hdr, 3);

			//mem cleanup
			delete hdr;
		}

		//now time to continue reading
		string instruction;
		int ins;
		queue<int> instructions;

		//read lines of data until we reach // END or // Data lines
		while (getline(file, instruction) && instruction.substr(0, 2) == "0x")
		{
			instruction = instruction.substr(2); //cut off the 0x bit
			stringstream ss;
			ss << hex << instruction;
			ss >> ins;
			instructions.push(ins);
		}

		//convert instructions/data values into an array to write to the hdd
		size_t length = instructions.size();
		int* values = new int[length];
		int currentindex = 0;
		while (currentindex < length)
		{
			values[currentindex] = instructions.front();
			instructions.pop();
			currentindex++;
		}

		//append data
		hdd->append(currentfile, values, length);
	}
}

int main()
{
	//initialize hard drive
	hdd = new Disk();

	//initialize virtual memory
	mem = new Memory();

	//load programs from host file into virtual hard drive
	loadPrograms();


}