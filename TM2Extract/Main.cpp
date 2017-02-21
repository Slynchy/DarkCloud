//
//	Dark Cloud Tools
//	By Sam Lynch
//
//	For documentation/preservation purposes only
//	Don't let old games die!
//
//	Covered by MIT Licensing
//

#include "tm2.h"
#include <string>

int WriteData(std::vector<char> _data, const char* _filename, const char* _ext);

int main(int argc, char *argv[])
{
	printf("TM2Extract - By Sam Lynch\n");

	if (argc == 1)
	{
		printf("\nUsage: TM2Extract.exe <file> <flags>\n");
		return 1;
	}

	std::ifstream* test = new std::ifstream(argv[1], std::ifstream::binary);

	if (test->fail())
	{
		printf("Could not load file!\n");
		return -1;
	}

	std::vector<TM2::TM2> result = TM2::ExtractTIM2(test, argv[1]);

	for (size_t i = 0; i < result.size(); i++)
	{
		WriteData(result.at(i).data, result.at(i).filename.c_str(), ".tm2");
	}

	return 0;
}

int WriteData(std::vector<char> _data, const char* _filename, const char* _ext)
{
	std::string filename = _filename;
	filename.append(_ext);
	//filename.append(_ext);
	std::ofstream output(filename.c_str(), std::ofstream::binary);
	
	for (size_t i = 0; i < _data.size(); i++)
	{
		output.write(&_data[i], 1);
	}
	return 0;
}