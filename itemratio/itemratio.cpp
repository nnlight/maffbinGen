
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include "../maffbinGen/common.h"

static constexpr uint32_t ITEMRATIO_BIN_HEADER = 0x00000006;

// sizeof = 4 * 17
struct ItemratioBinEntry
{
	uint32_t Unique;
	uint32_t UniqueDivisor;
	uint32_t UniqueMin;
	uint32_t Rare;
	uint32_t RareDivisor;
	uint32_t RareMin;
	uint32_t Set;
	uint32_t SetDivisor;
	uint32_t SetMin;
	uint32_t Magic;
	uint32_t MagicDivisor;
	uint32_t MagicMin;
	uint32_t HiQuality;
	uint32_t HiQualityDivisor;
	uint32_t Normal;
	uint32_t NormalDivisor;
	uint16_t Version;
	uint8_t Uber;
	uint8_t ClassSpecific;
};

static void Replace(const std::string &filename)
{
	FILE *f = fopen(filename.c_str(), "r+b");
	if (!f)
	{
		printf("Can't open file for reading and writing: %s\n", filename.c_str());
		myexit(1);
	}

	uint32_t header;
	fread(&header, 4, 1, f);
	assert(header == ITEMRATIO_BIN_HEADER);

	std::vector<ItemratioBinEntry> res;
	ItemratioBinEntry entry;

	while (fread(&entry, sizeof(entry), 1, f) == 1)
	{
		res.push_back(entry);
	}
	assert(feof(f));


	fseek(f, 4, SEEK_SET);

	for (ItemratioBinEntry &e : res)
	{
		e.Unique = 3;
		e.UniqueDivisor = 100;
		e.UniqueMin = 10;
		fwrite(&e, sizeof(e), 1, f);
	}

	fclose(f);
}

int main()
{
	Replace(EXCEL_DIR + ITEMRATIO_BIN_FILENAME);

	myexit(0);
}

