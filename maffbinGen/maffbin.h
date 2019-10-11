#pragma once

#include <stdint.h>
#include <memory.h>
#include <vector>
#include <string>

static constexpr uint32_t MAFFBIN_PREFIX_HEADER = 0x0000029D;
static constexpr uint32_t MAFFBIN_SUFFIX_HEADER = 0x000002EB;

static constexpr size_t MAFFBIN_ENTRY_SIZE = 16*9;
static constexpr size_t MAFFBIN_ENTRY_NAME_SIZE = 16 * 2; // 0x20

struct MaffbinEntry
{
	char name[MAFFBIN_ENTRY_NAME_SIZE];
	uint16_t b20_AZ; // always 0
	uint16_t b22_version;
	uint32_t b24_mod1code;
	uint32_t b28_mod1param;
	int32_t b2C_mod1min;
	int32_t b30_mod1max;
	uint32_t b34_mod2code;
	uint32_t b38_mod2param;
	int32_t b3C_mod2min;
	int32_t b40_mod2max;
	uint32_t b44_mod3code;
	uint32_t b48_mod3param;
	int32_t b4C_mod3min;
	int32_t b50_mod3max;
	uint16_t b54_spawnable;
	uint8_t b56_transformcolor;
	uint8_t b57_AZ; // always 0
	uint32_t b58_level;
	uint32_t b5C_group;
	uint32_t b60_maxlevel;
	uint8_t b64_rare;
	uint8_t b65_levelreq;
	uint8_t b66_calssspecific;
	uint8_t b67_class;
	uint16_t b68_classlevel;
	uint16_t b6A_itype1;
	uint16_t b6C_itype2;
	uint16_t b6E_itype3;
	uint16_t b70_itype4;
	uint16_t b72_itype5;
	uint16_t b74_itype6;
	uint16_t b76_itype7;
	uint16_t b78_etype1;
	uint16_t b7A_etype2;
	uint16_t b7C_etype3;
	uint16_t b7E_etype4;
	uint16_t b80_etype5;
	uint16_t b82_frequency;
	uint32_t b84_divide;
	uint32_t b88_multiply;
	uint32_t b8C_add;
};


std::vector<MaffbinEntry> ReadMaffbinFile(const std::string &filename);
void WriteMaffbinFile(const std::vector<MaffbinEntry> &maffbin, const std::string &filename, bool is_prefix);

