#pragma once

#include <stdlib.h>
#include <assert.h>
#include <string>


static const std::string EXCEL_DIR = "C:\\Games\\Diablo2_1.12\\mpqeditorWork\\data\\global\\excel\\";

#define MAFFBIN_PREFIX_FILENAME "magicprefix.bin"
#define MAFFBIN_SUFFIX_FILENAME "magicsuffix.bin"
#define MAFFTXT_PREFIX_FILENAME "MagicPrefix.txt"
#define MAFFTXT_SUFFIX_FILENAME "MagicSuffix.txt"

#define ITEMRATIO_BIN_FILENAME "itemratio.bin"

#define EXPERIENCE_BIN_FILENAME "experience.bin"


#ifdef _MSC_VER
//warning C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
#pragma warning(disable:4996)
#endif

static inline __declspec(noreturn) void myexit(int ec)
{
	if (ec) {
		assert(0);
	}
	printf("Press any key...");
	// want to press any key before exit
	getchar();
	exit(ec);
}
