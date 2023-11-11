/**
 * Compiler implementation of the
 * $(LINK2 http://www.dlang.org, D programming language).
 *
 * Copyright:    Copyright (c) 2012-2017 by Digital Mars, All Rights Reserved
 * Authors:     $(LINK2 http://www.digitalmars.com, Walter Bright)
 * License:     Distributed under the Boost Software License, Version 1.0.
 *              http://www.boost.org/LICENSE_1_0.txt
 * Source:      https://github.com/dlang/dmd/blob/master/src/ddmd/backend/code.c
 */

// This module generates the .debug$S and .debug$T sections for Win64,
// which are the MS-Coff symbolic debug info and type debug info sections.

#if !SPP

#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include        <time.h>

#include        "cc.h"
#include        "el.h"
#include        "code.h"
#include        "oper.h"
#include        "global.h"
#include        "type.h"
#include        "dt.h"
#include        "exh.h"
#include        "cgcv.h"
#include        "cv4.h"
#include        "obj.h"
#include        "outbuf.h"
#include        "varstats.h"

static char __file__[] = __FILE__;      /* for tassert.h                */
#include        "tassert.h"

#if _MSC_VER
#include        <alloca.h>
#endif

#endif
