#include "tm2.h"
#include <exception>
#include <vector>
#include <string>

std::vector<TM2::TM2> TM2::ExtractTIM2(std::ifstream* _input, std::string _filename)
{
	std::vector<TM2> result;

	char byte;
	size_t pos = SIZE_MAX;
	size_t numOfFiles = 0;
	while (_input->read(&byte, 1))
	{
		int counter = 0;
		if (byte == 'T')
		{
			counter++;
			_input->read(&byte, 1);
			if (byte == 'I')
			{
				counter++;
				_input->read(&byte, 1);
				if (byte == 'M')
				{
					counter++;
					_input->read(&byte, 1);
					if (byte == '2')
					{
						counter = 0;
						numOfFiles++;
						result.push_back(TM2());
						result.back().filename = _filename;
						result.back().filename += "_";
						result.back().filename += std::to_string(numOfFiles);
						result.back().data.push_back('T');
						result.back().data.push_back('I');
						result.back().data.push_back('M');
					}
				}
			}
		}

		pos = (size_t)_input->tellg();
		_input->seekg(pos - counter);

		if (numOfFiles == 0) continue;

		result.back().data.push_back(byte);
	}

	return result;
}