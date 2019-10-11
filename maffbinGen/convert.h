#pragma once

#include "maffbin.h"
#include "mafftxt.h"


void TestEntries(const MaffbinEntry &bin, const MafftxtEntry &txt, bool is_prefix);
MaffbinEntry ConvertMafftxtEntry(const MafftxtEntry &txt, bool is_prefix);


