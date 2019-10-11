
#include <stdio.h>
#include <assert.h>
#include "maffbin.h"
#include "common.h"

std::vector<MaffbinEntry> ReadMaffbinFile(const std::string &filename)
{
	FILE *f = fopen(filename.c_str(), "rb");
	if (!f)
	{
		printf("Can't open file for reading: %s\n", filename.c_str());
		myexit(1);
	}

	uint32_t header;
	fread(&header, 4, 1, f);

	std::vector<MaffbinEntry> res;
	MaffbinEntry entry;

	while (fread(&entry, sizeof(entry), 1, f) == 1)
	{
		res.push_back(entry);
	}
	assert(feof(f));

	fclose(f);
	return std::move(res);
}

void WriteMaffbinFile(const std::vector<MaffbinEntry> &maffbin, const std::string &filename, bool is_prefix)
{
	FILE *f = fopen(filename.c_str(), "wb");
	if (!f)
	{
		printf("Can't open file for writing: %s\n", filename.c_str());
		myexit(1);
	}

	uint32_t header = is_prefix ? MAFFBIN_PREFIX_HEADER : MAFFBIN_SUFFIX_HEADER;
	int r = fwrite(&header, 4, 1, f);
	assert(r == 1);

	for (const MaffbinEntry &entry : maffbin)
	{
		int r = fwrite(&entry, sizeof(entry), 1, f);
		assert(r == 1);
	}

	fclose(f);
}
