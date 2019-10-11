
#include <assert.h>
#include "convert.h"
#include "common.h"


static uint32_t Convert_modcode(const std::string &str)
{
	static std::vector<std::pair<uint32_t, std::string>> tbl = {
		{ 0xFFFFFFFF, "" },
		{ 0x00, "ac" },
		{ 0x03, "red-dmg" },
		{ 0x05, "ac%" },
		{ 0x06, "red-mag" },
		{ 0x07, "str" },
		{ 0x08, "dex" },
		{ 0x0A, "enr" },
		{ 0x0B, "mana" },
		{ 0x0D, "hp" },
		{ 0x0F, "att" },
		{ 0x10, "block" },
		{ 0x11, "cold-min" },
		{ 0x12, "cold-max" },
		{ 0x13, "cold-len" },
		{ 0x14, "fire-min" },
		{ 0x15, "fire-max" },
		{ 0x16, "ltng-min" },
		{ 0x17, "ltng-max" },
		{ 0x18, "pois-min" },
		{ 0x19, "pois-max" },
		{ 0x1A, "pois-len" },
		{ 0x1B, "dmg-min" },
		{ 0x1C, "dmg-max" },
		{ 0x1D, "dmg%" },
		{ 0x1E, "dmg-to-mana" },
		{ 0x1F, "res-fire" },
		{ 0x21, "res-ltng" },
		{ 0x23, "res-cold" },
		{ 0x27, "res-pois" },
		{ 0x29, "res-all" },
		{ 0x2C, "abs-fire" },
		{ 0x2E, "abs-ltng" },
		{ 0x32, "abs-cold" },
		{ 0x35, "regen" },
		{ 0x36, "thorns" },
		{ 0x37, "swing1" },
		{ 0x38, "swing2" },
		{ 0x39, "swing3" },
		{ 0x3A, "gold%" },
		{ 0x3B, "mag%" },
		{ 0x3C, "knock" },
		{ 0x3D, "regen-stam" },
		{ 0x3F, "stam" },
		{ 0x41, "manasteal" },
		{ 0x42, "lifesteal" },
		{ 0x49, "light" },
		{ 0x4B, "ease" },
		{ 0x4C, "move1" },
		{ 0x4D, "move2" },
		{ 0x4E, "move3" },
		{ 0x4F, "balance1" },
		{ 0x50, "balance2" },
		{ 0x51, "balance3" },
		//{ 0x52, "block1" },
		{ 0x53, "block2" },
		//{ 0x54, "block3" },
		{ 0x55, "cast1" },
		//{ 0x56, "cast2" },
		{ 0x57, "cast3" },
		{ 0x58, "res-pois-len" },
		{ 0x5A, "howl" },
		{ 0x5C, "ignore-ac" },
		{ 0x5E, "noheal" },
		{ 0x5F, "half-freeze" },
		{ 0x60, "att%" },
		{ 0x61, "dmg-ac" },
		{ 0x62, "dmg-demon" },
		{ 0x63, "dmg-undead" },
		{ 0x64, "att-demon" },
		{ 0x65, "att-undead" },
		{ 0x6E, "mana-kill" },
		{ 0x74, "stamdrain" },
		{ 0x7C, "skilltab" },
		{ 0x7E, "att-skill" },
		{ 0x7F, "hit-skill" },
		{ 0x80, "gethit-skill" },
		{ 0x85, "sock" },
		{ 0x86, "dmg-fire" },
		{ 0x87, "dmg-ltng" },
		{ 0x89, "dmg-cold" },
		{ 0x8A, "dmg-pois" },
		{ 0x8D, "ac/lvl" },
		{ 0x8E, "ac%/lvl" },
		{ 0x8F, "hp/lvl" },
		{ 0x90, "mana/lvl" },
		{ 0x91, "dmg/lvl" },
		{ 0x92, "dmg%/lvl" },
		{ 0x93, "str/lvl" },
		{ 0x94, "dex/lvl" },
		{ 0x97, "att/lvl" },
		{ 0x98, "att%/lvl" },
		{ 0x9D, "res-cold/lvl" },
		{ 0x9E, "res-fire/lvl" },
		{ 0x9F, "res-ltng/lvl" },
		{ 0xA0, "res-pois/lvl" },
		{ 0xB3, "rep-dur" },
		{ 0xB4, "rep-quant" },
		{ 0xB5, "stack" },
		{ 0xC3, "ac/time" },
		{ 0xF2, "indestruct" },
		{ 0xF3, "charged" },

		{ 0x43, "ama" },
		{ 0x44, "pal" },
		{ 0x45, "nec" },
		{ 0x46, "sor" },
		{ 0x47, "bar" },

		{ 0x79, "dru" },
		{ 0x7A, "ass" },
	};

	for (const auto &a : tbl)
	{
		if (a.second == str)
			return a.first;
	}
	printf("Can't covert modcode value: %s\n", str.c_str());
	myexit(1);
}

static uint8_t Convert_transformcolor(const std::string &str)
{
	static std::vector<std::pair<uint8_t, std::string>> tbl = {
		{ 0xFF, "" },
		{ 0x00, "whit" },
		{ 0x03, "blac" },
		{ 0x04, "lblu" },
		{ 0x05, "dblu" },
		{ 0x06, "cblu" },
		{ 0x07, "lred" },
		{ 0x08, "dred" },
		{ 0x09, "cred" },
		{ 0x0A, "lgrn" },
		{ 0x0B, "dgrn" },
		{ 0x0C, "cgrn" },
		{ 0x0D, "lyel" },
		{ 0x0E, "dyel" },
		{ 0x0F, "lgld" },
		{ 0x10, "dgld" },
		{ 0x11, "lpur" },
		{ 0x13, "oran" },
	};

	for (const auto &a : tbl)
	{
		if (a.second == str)
			return a.first;
	}
	printf("Can't covert transformcolor value: %s\n", str.c_str());
	myexit(1);
}

static uint16_t Convert_ietype(const std::string &str, bool is_column_absent_in_txt = false)
{
	if (is_column_absent_in_txt) {
		return 0xFFFF;
	}

	static std::vector<std::pair<uint16_t, std::string>> tbl = {
		{ 0x00, "" },
		{ 0x03, "tors" },
		{ 0x0A, "ring" },
		{ 0x0A, "ring " },
		{ 0x0C, "amul" },
		{ 0x0F, "boot" },
		{ 0x10, "glov" },
		{ 0x13, "belt" },
		{ 0x18, "scep" },
		{ 0x19, "wand" },
		{ 0x1A, "staf" },
		{ 0x1A, "staff" },
		{ 0x1C, "axe" },
		{ 0x1D, "club" },
		{ 0x1E, "swor" },
		{ 0x1F, "hamm" },
		{ 0x20, "knif" },
		{ 0x21, "spea" },
		{ 0x22, "pole" },
		{ 0x24, "mace" },
		{ 0x25, "helm" },
		{ 0x2A, "tkni" },
		{ 0x2C, "jave" },
		{ 0x2D, "weap" },
		{ 0x2E, "mele" },
		{ 0x2F, "miss" },
		{ 0x30, "thro" },
		{ 0x32, "armo" },
		{ 0x33, "shld" },
		{ 0x37, "rod" },
		{ 0x39, "blun" },
		{ 0x3A, "jewl" },
		{ 0x3C, "amaz" },
		{ 0x43, "h2h" },
		{ 0x44, "orb" },
		{ 0x45, "head" },
		{ 0x46, "ashd" },
		{ 0x47, "phlm" },
		{ 0x48, "pelt" },
		{ 0x4B, "circ" },
		{ 0x52, "scha" },
		{ 0x53, "mcha" },
		{ 0x54, "lcha" },
		{ 0x55, "abow" },
		{ 0x56, "aspe" },
	};

	for (const auto &a : tbl)
	{
		if (a.second == str)
			return a.first;
	}
	printf("Can't covert ietype value: %s\n", str.c_str());
	myexit(1);
}

static uint8_t Convert_classspecific(const std::string &str)
{
	static std::vector<std::pair<uint8_t, std::string>> tbl = {
		{ 0xFF, "" },
		{ 0x00, "ama" },
		{ 0x01, "sor" },
		{ 0x02, "nec" },
		{ 0x03, "pal" },
		{ 0x04, "bar" },
		{ 0x05, "dru" },
		{ 0x06, "ass" },
	};

	for (const auto &a : tbl)
	{
		if (a.second == str)
			return a.first;
	}
	printf("Can't covert calassspecific/class value: %s\n", str.c_str());
	myexit(1);
}


void TestEntries(const MaffbinEntry &bin, const MafftxtEntry &txt, bool is_prefix)
{
	assert(!strcmp(bin.name, txt.name.c_str()));
	assert(bin.b20_AZ == 0);
	assert(bin.b22_version == txt.version);

	assert(bin.b24_mod1code == Convert_modcode(txt.mod1code));
	assert(bin.b28_mod1param == txt.mod1param);
	assert(bin.b2C_mod1min == txt.mod1min);
	assert(bin.b30_mod1max == txt.mod1max);

	assert(bin.b34_mod2code == Convert_modcode(txt.mod2code));
	assert(bin.b38_mod2param == txt.mod2param);
	assert(bin.b3C_mod2min == txt.mod2min);
	assert(bin.b40_mod2max == txt.mod2max);

	assert(bin.b44_mod3code == Convert_modcode(txt.mod3code));
	assert(bin.b48_mod3param == txt.mod3param);
	assert(bin.b4C_mod3min == txt.mod3min);
	assert(bin.b50_mod3max == txt.mod3max);

	assert(bin.b54_spawnable == txt.spawnable);
	assert(bin.b56_transformcolor == Convert_transformcolor(txt.transformcolor));
	assert(bin.b57_AZ == 0);
	assert(bin.b58_level == txt.level);
	assert(bin.b5C_group == txt.group);
	assert(bin.b60_maxlevel == txt.maxlevel);
	assert(bin.b64_rare == txt.rare);
	assert(bin.b65_levelreq == txt.levelreq);
	assert(bin.b66_calssspecific == Convert_classspecific(txt.classspecific));
	assert(bin.b67_class == Convert_classspecific(txt.class_));
	assert(bin.b68_classlevel == txt.classlevel);
	assert(bin.b6A_itype1 == Convert_ietype(txt.itype1));
	assert(bin.b6C_itype2 == Convert_ietype(txt.itype2));
	assert(bin.b6E_itype3 == Convert_ietype(txt.itype3));
	assert(bin.b70_itype4 == Convert_ietype(txt.itype4));
	assert(bin.b72_itype5 == Convert_ietype(txt.itype5));
	assert(bin.b74_itype6 == Convert_ietype(txt.itype6));
	assert(bin.b76_itype7 == Convert_ietype(txt.itype7));
	assert(bin.b78_etype1 == Convert_ietype(txt.etype1));
	assert(bin.b7A_etype2 == Convert_ietype(txt.etype2));
	assert(bin.b7C_etype3 == Convert_ietype(txt.etype3));
	assert(bin.b7E_etype4 == Convert_ietype(txt.etype4_pref_only, !is_prefix));
	assert(bin.b80_etype5 == Convert_ietype(txt.etype5_pref_only, !is_prefix));
	assert(bin.b82_frequency == txt.frequency);
	assert(bin.b84_divide == txt.divide); // правда всегда 0...
	assert(bin.b88_multiply == txt.multiply);
	assert(bin.b8C_add == txt.add);
}

MaffbinEntry ConvertMafftxtEntry(const MafftxtEntry &txt, bool is_prefix)
{
	MaffbinEntry bin;

	assert(txt.name.length() < MAFFBIN_ENTRY_NAME_SIZE);
	memset(bin.name, 0, MAFFBIN_ENTRY_NAME_SIZE);
	strcpy(bin.name, txt.name.c_str());
	bin.b20_AZ = 0;
	bin.b22_version = txt.version;

	bin.b24_mod1code = Convert_modcode(txt.mod1code);
	bin.b28_mod1param = txt.mod1param;
	bin.b2C_mod1min = txt.mod1min;
	bin.b30_mod1max = txt.mod1max;

	bin.b34_mod2code = Convert_modcode(txt.mod2code);
	bin.b38_mod2param = txt.mod2param;
	bin.b3C_mod2min = txt.mod2min;
	bin.b40_mod2max = txt.mod2max;

	bin.b44_mod3code = Convert_modcode(txt.mod3code);
	bin.b48_mod3param = txt.mod3param;
	bin.b4C_mod3min = txt.mod3min;
	bin.b50_mod3max = txt.mod3max;

	bin.b54_spawnable = txt.spawnable;
	bin.b56_transformcolor = Convert_transformcolor(txt.transformcolor);
	bin.b57_AZ = 0;
	bin.b58_level = txt.level;
	bin.b5C_group = txt.group;
	bin.b60_maxlevel = txt.maxlevel;
	bin.b64_rare = txt.rare;
	bin.b65_levelreq = txt.levelreq;
	bin.b66_calssspecific = Convert_classspecific(txt.classspecific);
	bin.b67_class = Convert_classspecific(txt.class_);
	bin.b68_classlevel = txt.classlevel;
	bin.b6A_itype1 = Convert_ietype(txt.itype1);
	bin.b6C_itype2 = Convert_ietype(txt.itype2);
	bin.b6E_itype3 = Convert_ietype(txt.itype3);
	bin.b70_itype4 = Convert_ietype(txt.itype4);
	bin.b72_itype5 = Convert_ietype(txt.itype5);
	bin.b74_itype6 = Convert_ietype(txt.itype6);
	bin.b76_itype7 = Convert_ietype(txt.itype7);
	bin.b78_etype1 = Convert_ietype(txt.etype1);
	bin.b7A_etype2 = Convert_ietype(txt.etype2);
	bin.b7C_etype3 = Convert_ietype(txt.etype3);
	bin.b7E_etype4 = Convert_ietype(txt.etype4_pref_only, !is_prefix);
	bin.b80_etype5 = Convert_ietype(txt.etype5_pref_only, !is_prefix);
	bin.b82_frequency = txt.frequency;
	bin.b84_divide = txt.divide;
	bin.b88_multiply = txt.multiply;
	bin.b8C_add = txt.add;

	return bin;
}

