
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include "../maffbinGen/common.h"

static constexpr uint32_t EXPERIENCE_BIN_HEADER = 0x00000065;

struct ExperienceBinEntry
{
	uint32_t elem[8];
	static constexpr int kExpRatio = 7;
};

static void Scan(const std::string &filename)
{
	FILE *f = fopen(filename.c_str(), "rb");
	if (!f)
	{
		printf("Can't open file for reading: %s\n", filename.c_str());
		myexit(1);
	}

	uint32_t word;
	while (fread(&word, sizeof(word), 1, f) == 1)
	{
		if (word == 1024)
		{
			int off = (int)ftell(f);
			printf("found one at offset 0x%x %d(%d) \n", off - 4, (off - 8)/4 % 8, (off - 8) / 4 / 8);
		}
	}
	assert(feof(f));

	fclose(f);
}

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
	assert(header == EXPERIENCE_BIN_HEADER);

	std::vector<ExperienceBinEntry> res;
	ExperienceBinEntry entry;

	while (fread(&entry, sizeof(entry), 1, f) == 1)
	{
		res.push_back(entry);
	}
	assert(feof(f));


	fseek(f, 4, SEEK_SET);

	int idx = 0;
	for (ExperienceBinEntry &e : res)
	{
		if (idx >= 1)
		{
			//e.elem[ExperienceBinEntry::kExpRatio] = 1024 * 100;
			e.elem[ExperienceBinEntry::kExpRatio] = 1024 * 20;
		}

		fwrite(&e, sizeof(e), 1, f);
		idx++;
	}

	fclose(f);
}

int main()
{
	//Scan(EXCEL_DIR + EXPERIENCE_BIN_FILENAME);
	Replace(EXCEL_DIR + EXPERIENCE_BIN_FILENAME);

	myexit(0);
}

