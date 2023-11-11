/**
 * Compiler implementation of the
 * $(LINK2 http://www.dlang.org, D programming language).
 *
 * Copyright:   Copyright (c) 2000-2017 by Digital Mars, All Rights Reserved
 * Authors:     $(LINK2 http://www.digitalmars.com, Walter Bright)
 * License:     Distributed under the Boost Software License, Version 1.0.
 *              http://www.boost.org/LICENSE_1_0.txt
 * Source:      https://github.com/dlang/dmd/blob/master/src/ddmd/backend/backconfig.c
 */

// Configure the back end (optimizer and code generator)

#include        <stdio.h>
#include        <ctype.h>
#include        <string.h>
#include        <stdlib.h>
#include        <time.h>

#include        "cc.h"
#include        "global.h"
#include        "oper.h"
#include        "code.h"
#include        "type.h"
#include        "dt.h"
#include        "cgcv.h"

static char __file__[] = __FILE__;      /* for tassert.h                */
#include        "tassert.h"


/**************************************
 * Initialize configuration variables.
 */

void out_config_init(
        int model,      // 32: 32 bit code
                        // 64: 64 bit code
                        // Windows: set bit 0 to generate MS-COFF instead of OMF
        bool exe,       // true: exe file
                        // false: dll or shared library (generate PIC code)
        bool trace,     // add profiling code
        bool nofloat,   // do not pull in floating point code
        bool verbose,   // verbose compile
        bool optimize,  // optimize code
        int symdebug,   // add symbolic debug information
                        // 1: D
                        // 2: fake it with C symbolic debug info
        bool alwaysframe,       // always create standard function frame
        bool stackstomp,        // add stack stomping code
        bool avx                // use AVX instruction set
        )
{

}

#ifdef DEBUG

/****************************
 * Transmit internal compiler debugging flags.
 */
void out_config_debug(
        bool b,
        bool c,
        bool f,
        bool r,
        bool w,
        bool x,
        bool y
    )
{
    debugb = b;
    debugc = c;
    debugf = f;
    debugr = r;
    debugw = w;
    debugx = x;
    debugy = y;
}

#endif

/*************************************
 */

void util_set16()
{
    // The default is 16 bits
    _tysize[TYldouble] = 10;
    _tysize[TYildouble] = 10;
    _tysize[TYcldouble] = 20;

    _tyalignsize[TYldouble] = 2;
    _tyalignsize[TYildouble] = 2;
    _tyalignsize[TYcldouble] = 2;
}

/*******************************
 * Redo tables from 8086/286 to 386/486.
 */

void util_set32()
{
    _tyrelax[TYenum] = TYlong;
    _tyrelax[TYint]  = TYlong;
    _tyrelax[TYuint] = TYlong;

    tyequiv[TYint] = TYlong;
    tyequiv[TYuint] = TYulong;

    _tysize[TYenum] = LONGSIZE;
    _tysize[TYint ] = LONGSIZE;
    _tysize[TYuint] = LONGSIZE;
    _tysize[TYnullptr] = LONGSIZE;
    _tysize[TYnptr] = LONGSIZE;
    _tysize[TYnref] = LONGSIZE;
    _tysize[TYldouble] = 10;
    _tysize[TYildouble] = 10;
    _tysize[TYcldouble] = 20;
    _tysize[TYsptr] = LONGSIZE;
    _tysize[TYcptr] = LONGSIZE;
    _tysize[TYfptr] = 6;     // NOTE: There are codgen test that check
    _tysize[TYvptr] = 6;     // _tysize[x] == _tysize[TYfptr] so don't set
    _tysize[TYfref] = 6;     // _tysize[TYfptr] to _tysize[TYnptr]

    _tyalignsize[TYenum] = LONGSIZE;
    _tyalignsize[TYint ] = LONGSIZE;
    _tyalignsize[TYuint] = LONGSIZE;
    _tyalignsize[TYnullptr] = LONGSIZE;
    _tyalignsize[TYnref] = LONGSIZE;
    _tyalignsize[TYnptr] = LONGSIZE;
    _tyalignsize[TYldouble] = 2;
    _tyalignsize[TYildouble] = 2;
    _tyalignsize[TYcldouble] = 2;
    _tyalignsize[TYsptr] = LONGSIZE;
    _tyalignsize[TYcptr] = LONGSIZE;
}

/*******************************
 * Redo tables from 8086/286 to I64.
 */

void util_set64()
{
    _tyrelax[TYenum] = TYlong;
    _tyrelax[TYint]  = TYlong;
    _tyrelax[TYuint] = TYlong;

    tyequiv[TYint] = TYlong;
    tyequiv[TYuint] = TYulong;

    _tysize[TYenum] = LONGSIZE;
    _tysize[TYint ] = LONGSIZE;
    _tysize[TYuint] = LONGSIZE;
    _tysize[TYnullptr] = 8;
    _tysize[TYnptr] = 8;
    _tysize[TYnref] = 8;
    _tysize[TYldouble] = 10;
    _tysize[TYildouble] = 10;
    _tysize[TYcldouble] = 20;
    _tysize[TYsptr] = 8;
    _tysize[TYcptr] = 8;
    _tysize[TYfptr] = 10;    // NOTE: There are codgen test that check
    _tysize[TYvptr] = 10;    // _tysize[x] == _tysize[TYfptr] so don't set
    _tysize[TYfref] = 10;    // _tysize[TYfptr] to _tysize[TYnptr]

    _tyalignsize[TYenum] = LONGSIZE;
    _tyalignsize[TYint ] = LONGSIZE;
    _tyalignsize[TYuint] = LONGSIZE;
    _tyalignsize[TYnullptr] = 8;
    _tyalignsize[TYnptr] = 8;
    _tyalignsize[TYnref] = 8;
    _tyalignsize[TYldouble] = 2;
    _tyalignsize[TYildouble] = 2;
    _tyalignsize[TYcldouble] = 2;
    _tyalignsize[TYsptr] = 8;
    _tyalignsize[TYcptr] = 8;
    _tyalignsize[TYfptr] = 8;
    _tyalignsize[TYvptr] = 8;
    _tyalignsize[TYfref] = 8;
    tytab[TYjfunc] &= ~TYFLpascal;  // set so caller cleans the stack (as in C)

    TYptrdiff = TYllong;
    TYsize = TYullong;
    TYsize_t = TYullong;
    TYdelegate = TYcent;
    TYdarray = TYucent;
}

// cc.d
unsigned Srcpos::sizeCheck() { return sizeof(Srcpos); }
unsigned Pstate::sizeCheck() { return sizeof(Pstate); }
unsigned Cstate::sizeCheck() { return sizeof(Cstate); }
unsigned Blockx::sizeCheck() { return sizeof(Blockx); }
unsigned block::sizeCheck()  { return sizeof(block);  }
unsigned func_t::sizeCheck() { return sizeof(func_t); }
unsigned baseclass_t::sizeCheck() { return sizeof(baseclass_t); }
unsigned template_t::sizeCheck() { return sizeof(template_t); }
unsigned struct_t::sizeCheck() { return sizeof(struct_t); }
unsigned Symbol::sizeCheck() { return sizeof(Symbol); }
unsigned param_t::sizeCheck() { return sizeof(param_t); }
unsigned Declar::sizeCheck() { return sizeof(Declar); }
unsigned dt_t::sizeCheck() { return sizeof(dt_t); }

// cdef.d
unsigned Config::sizeCheck() { return sizeof(Config); }
unsigned Configv::sizeCheck() { return sizeof(Configv); }
unsigned eve::sizeCheck() { return sizeof(eve); }

// el.d

// type.d
unsigned TYPE::sizeCheck() { return sizeof(type); }

