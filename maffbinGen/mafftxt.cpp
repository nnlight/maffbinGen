
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include "mafftxt.h"
#include "common.h"


// trim from start (in place)
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

static std::string readstrelem(std::istringstream &linef)
{
	std::string elem;
	if (std::getline(linef, elem, '\t')) {
		//ltrim(elem);
		//rtrim(elem);
		return elem;
	}
	return "";
}

static int readintelem(std::istringstream &linef)
{
	return atoi(readstrelem(linef).c_str());
}

std::vector<MafftxtEntry> ReadMafftxtFile(const std::string &filename, bool is_prefix)
{
	std::ifstream f(filename, std::ifstream::in);
	if (!f.is_open())
	{
		printf("Can't open file for reading: %s\n", filename.c_str());
		myexit(1);
	}


	std::vector<MafftxtEntry> res;

	std::string line;
	for (int line_no = 1;
		 std::getline(f, line);
		 line_no++)
	{
		// ignore first line with column names
		if (line_no == 1)
			continue;
		
		std::istringstream linef(line);
		std::string name = readstrelem(linef);

		// corresponding entry doesnt exist in bin file, so just ignore this txt line
		if (name == "Expansion")
			continue;

		MafftxtEntry entry;
		entry.line_no = line_no;
		entry.name = name;
		entry.version = readintelem(linef);
		entry.spawnable = readintelem(linef);
		entry.rare = readintelem(linef);
		entry.level = readintelem(linef);
		entry.maxlevel = readintelem(linef);
		entry.levelreq = readintelem(linef);
		entry.classspecific = readstrelem(linef);
		entry.class_ = readstrelem(linef);
		entry.classlevel = readintelem(linef);
		entry.frequency = readintelem(linef);
		entry.group = readintelem(linef);

		entry.mod1code = readstrelem(linef);
		entry.mod1param = readintelem(linef);
		entry.mod1min = readintelem(linef);
		entry.mod1max = readintelem(linef);

		entry.mod2code = readstrelem(linef);
		entry.mod2param = readintelem(linef);
		entry.mod2min = readintelem(linef);
		entry.mod2max = readintelem(linef);

		entry.mod3code = readstrelem(linef);
		entry.mod3param = readintelem(linef);
		entry.mod3min = readintelem(linef);
		entry.mod3max = readintelem(linef);

		entry.transform = readintelem(linef);
		entry.transformcolor = readstrelem(linef);
		entry.itype1 = readstrelem(linef);
		entry.itype2 = readstrelem(linef);
		entry.itype3 = readstrelem(linef);
		entry.itype4 = readstrelem(linef);
		entry.itype5 = readstrelem(linef);
		entry.itype6 = readstrelem(linef);
		entry.itype7 = readstrelem(linef);
		entry.etype1 = readstrelem(linef);
		entry.etype2 = readstrelem(linef);
		entry.etype3 = readstrelem(linef);
		if (is_prefix) {
			entry.etype4_pref_only = readstrelem(linef);
			entry.etype5_pref_only = readstrelem(linef);
		}
		entry.divide = readintelem(linef);
		entry.multiply = readintelem(linef);
		entry.add = readintelem(linef);

		assert(linef.eof());

		res.push_back(std::move(entry));
	}


	return std::move(res);
}