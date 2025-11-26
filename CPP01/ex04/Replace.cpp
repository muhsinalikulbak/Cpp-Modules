#include "Replace.hpp"

void	Replace::wordReplace(std::ifstream& source, std::ofstream& out, const char* oldStr, const char* newStr)
{
	std::string line;
	size_t		start;
	size_t		pos;
	size_t		oldLen;

	oldLen = std::strlen(oldStr);
	while (getline(source, line))
	{
		start = 0;
		pos = line.find(oldStr, start);
		if (pos == std::string::npos)
			out << line << '\n';
		else
		{
			while (pos != std::string::npos)
			{
				out << line.substr(start, pos - start) << newStr;
				start = pos + oldLen;
				pos = line.find(oldStr, start); 
			}
			if (start != line.size())
				out << line.substr(start, line.size() - start);
			out << '\n';
		}
	}
}

void	Replace::fileReplacer(const char* file, const char* oldStr, const char* newStr)
{
	const char* chrFile;
	std::string strFile(file);

	strFile += ".replace";
	chrFile = strFile.c_str();

	std::ifstream    sourceFile(file);
	std::ofstream    newFile(chrFile, std::ios::out | std::ios::trunc);
	
	wordReplace(sourceFile, newFile, oldStr, newStr);
}
