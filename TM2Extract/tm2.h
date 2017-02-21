#pragma once

#include <string>
#include <vector>
#include <fstream>

namespace TM2
{
	struct TM2
	{
		std::string filename;
		std::vector<char> data;
	};

	std::vector<TM2> ExtractTIM2(std::ifstream* _input, std::string _filename);
}