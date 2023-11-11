/**
 * Compiler implementation of the
 * $(LINK2 http://www.dlang.org, D programming language).
 *
 * Copyright:   Copyright (c) 1999-2017 by Digital Mars, All Rights Reserved
 * Authors:     $(LINK2 http://www.digitalmars.com, Walter Bright)
 * License:     Distributed under the Boost Software License, Version 1.0.
 *              http://www.boost.org/LICENSE_1_0.txt
 * Source:      https://github.com/dlang/dmd/blob/master/src/ddmd/backend/dwarf.c
 */

// Emit Dwarf symbolic debug info

#if !SPP
#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        <ctype.h>

#if __DMC__ || __linux__
#include        <malloc.h>
#endif

#if __linux__ || __APPLE__
#include        <signal.h>
#include        <unistd.h>
#include        <errno.h>
#endif

#include        "cc.h"
#include        "global.h"
#include        "code.h"
#include        "type.h"
#include        "outbuf.h"
#include        "filespec.h"
#include        "cv4.h"
#include        "cgcv.h"
#include        "dt.h"
#include        "rtlsym.h"

#include        "aa.h"
#include        "tinfo.h"

void dwarf_CFA_set_loc(size_t location) { }
void dwarf_CFA_set_reg_offset(int reg, int offset) { }
void dwarf_CFA_offset(int reg, int offset) { }
void dwarf_except_gentables(Funcsym *sfunc, unsigned startoffset, unsigned retoffset) { }
#endif
