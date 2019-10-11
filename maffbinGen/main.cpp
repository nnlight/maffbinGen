
#include <stdio.h>
#include <assert.h>
#include "maffbin.h"
#include "mafftxt.h"
#include "convert.h"
#include "common.h"


int main()
{
	assert(sizeof(MaffbinEntry) == MAFFBIN_ENTRY_SIZE);


	for (bool is_prefix : {true, false})
	{
		std::string bin_filepath = EXCEL_DIR + (is_prefix ? MAFFBIN_PREFIX_FILENAME : MAFFBIN_SUFFIX_FILENAME);
		std::string txt_filepath = EXCEL_DIR + (is_prefix ? MAFFTXT_PREFIX_FILENAME : MAFFTXT_SUFFIX_FILENAME);

		std::vector<MafftxtEntry> mafftxt = ReadMafftxtFile(txt_filepath, is_prefix);
		std::vector<MaffbinEntry> maffbin = ReadMaffbinFile(bin_filepath);

		assert(mafftxt.size() == maffbin.size());
		int size = mafftxt.size();

		//WriteMaffbinFile(maffbin, bin_filepath + ".my", is_prefix);


		for (int i = 0; i < size; i++)
		{
			MaffbinEntry &bin = maffbin[i];
			MafftxtEntry &txt = mafftxt[i];

			//TestEntries(bin, txt, is_prefix);
		}

		std::vector<MaffbinEntry> new_maffbin;
		for (int i = 0; i < size; i++)
		{
			new_maffbin.push_back(ConvertMafftxtEntry(mafftxt[i], is_prefix));
		}
		WriteMaffbinFile(new_maffbin, bin_filepath, is_prefix);
	}

	
	myexit(0);
}

