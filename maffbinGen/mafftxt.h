#pragma once

#include <stdint.h>
#include <memory.h>
#include <vector>
#include <string>


// prefix file containts 41 fields (+ etype4 etype5)
// suffix file containts 39 fields
struct MafftxtEntry
{
	int line_no; // in excel file

	std::string name;
	int version;
	int spawnable;
	int rare;
	int level;
	int maxlevel;
	int levelreq;
	std::string classspecific; // ama sor nec pal bar dru ass
	std::string class_;        // ama sor nec pal bar dru ass
	int classlevel;
	int frequency;
	int group;

	std::string mod1code;  // ac% dmg% red-dmg cold-min etc.
	int mod1param;
	int mod1min; // negative values exist
	int mod1max; // negative values exist

	std::string mod2code;
	int mod2param;
	int mod2min;
	int mod2max;

	std::string mod3code;
	int mod3param;
	int mod3min;
	int mod3max;

	int transform; // NOT USED IN CONVERTION TO BIN
	std::string transformcolor;
	std::string itype1; // tors ring amul rod mele weap shld belt glov boot scep armo jewl miss circ etc.
	std::string itype2;
	std::string itype3;
	std::string itype4;
	std::string itype5;
	std::string itype6;
	std::string itype7;
	std::string etype1; // wand staf rod glov miss scep glov boot etc.
	std::string etype2;
	std::string etype3;
	std::string etype4_pref_only; // only in prefix file present
	std::string etype5_pref_only; // only in prefix file present
	int divide;
	int multiply;
	int add;
};


std::vector<MafftxtEntry> ReadMafftxtFile(const std::string &filename, bool is_prefix);

