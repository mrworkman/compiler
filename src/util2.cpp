/**
 * Compiler implementation of the
 * $(LINK2 http://www.dlang.org, D programming language).
 *
 * Copyright:   Copyright (C) 1984-1998 by Symantec
 *              Copyright (c) 2000-2017 by Digital Mars, All Rights Reserved
 * Authors:     $(LINK2 http://www.digitalmars.com, Walter Bright)
 * License:     Distributed under the Boost Software License, Version 1.0.
 *              http://www.boost.org/LICENSE_1_0.txt
 * Source:      https://github.com/dlang/dmd/blob/master/src/ddmd/backend/util2.c
 */

// Utility subroutines

#include        <stdio.h>
#include        <ctype.h>
#include        <string.h>
#include        <stdlib.h>
#include        <time.h>

#include        "cc.h"
#include        "global.h"
#include        "mem.h"
#include        "token.h"
#if SCPP
#include        "el.h"
#endif

static char __file__[] = __FILE__;      /* for tassert.h                */
#include        "tassert.h"

void *ph_malloc(size_t nbytes);
void *ph_calloc(size_t nbytes);
void ph_free(void *p);
void *ph_realloc(void *p , size_t nbytes);


void util_exit(int exitcode);

void file_progress()
{
}

/*******************************
 * Alternative assert failure.
 */

void util_assert(const char *file, int line)
{
    fflush(stdout);
    printf("Internal error: %s %d\n",file,line);
    err_exit();
#if __clang__
    __builtin_unreachable();
#endif
}

/****************************
 * Clean up and exit program.
 */

void err_exit()
{
    util_exit(EXIT_FAILURE);
}

/********************************
 * Clean up and exit program.
 */

void err_break()
{
    util_exit(255);
}


/****************************
 * Clean up and exit program.
 */

void util_exit(int exitcode)
{
    exit(exitcode);                     /* terminate abnormally         */
}


#if _WIN32 && !_MSC_VER

volatile int controlc_saw;

/********************************
 * Control C interrupts go here.
 */

static void __cdecl controlc_handler(void)
{
    //printf("saw controlc\n");
    controlc_saw = 1;
}

/*********************************
 * Trap control C interrupts.
 */

void _STI_controlc()
{
    //printf("_STI_controlc()\n");
    _controlc_handler = controlc_handler;
    controlc_open();                    /* trap control C               */
}

void _STD_controlc()
{
    //printf("_STD_controlc()\n");
    controlc_close();
}

/***********************************
 * Send progress report.
 */

void util_progress()
{
    if (controlc_saw)
        err_break();
}

void util_progress(int linnum)
{
    if (controlc_saw)
        err_break();
}

#endif

#if __linux__ || __APPLE__ || _MSC_VER
void util_progress()
{
}

void util_progress(int linnum)
{
}
#endif

/**********************************
 * Binary string search.
 * Input:
 *      p ->    string of characters
 *      tab     array of pointers to strings
 *      n =     number of pointers in the array
 * Returns:
 *      index (0..n-1) into tab[] if we found a string match
 *      else -1
 */

int binary(const char *p, const char ** table, int high)
{
    int low = 0;
    char cp = *p;
    high--;
    p++;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cond = table[mid][0] - cp;

        if (cond == 0)
            cond = strcmp(table[mid] + 1,p);
        if (cond > 0)
            high = mid - 1;
        else if (cond < 0)
            low = mid + 1;
        else
            return mid;                 /* match index                  */
    }
    return -1;
}

// search table[0 .. high] for p[0 .. len] (where p.length not necessairily equal to len)
int binary(const char *p, size_t len, const char ** table, int high)
{
    int low = 0;
    char cp = *p;
    high--;
    p++;
    len--;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cond = table[mid][0] - cp;

        if (cond == 0)
        {
            cond = strncmp(table[mid] + 1, p, len);
            if (cond == 0)
                cond = table[mid][len+1]; // same as: if (table[mid][len+1] != '\0') cond = 1;
        }

        if (cond > 0)
            high = mid - 1;
        else if (cond < 0)
            low = mid + 1;
        else
            return mid;                 /* match index                  */
    }
    return -1;
}

/**********************
 * If c is a power of 2, return that power else -1.
 */

int ispow2(targ_ullong c)
{       int i;

        if (c == 0 || (c & (c - 1)))
            i = -1;
        else
            for (i = 0; c >>= 1; i++)
                ;
        return i;
}

/***************************
 */

#define UTIL_PH 1

#if _WIN32
void *util_malloc(unsigned n,unsigned size)
{
#if 0 && MEM_DEBUG
    void *p;

    p = mem_malloc(n * size);
    //dbg_printf("util_calloc(%d) = %p\n",n * size,p);
    return p;
#elif UTIL_PH
    return ph_malloc(n * size);
#else
    size_t nbytes = (size_t)n * (size_t)size;
    void *p = malloc(nbytes);
    if (!p && nbytes)
        err_nomem();
    return p;
#endif
}
#endif

/***************************
 */

#if _WIN32
void *util_calloc(unsigned n,unsigned size)
{
#if 0 && MEM_DEBUG
    void *p;

    p = mem_calloc(n * size);
    //dbg_printf("util_calloc(%d) = %p\n",n * size,p);
    return p;
#elif UTIL_PH
    return ph_calloc(n * size);
#else
    size_t nbytes = (size_t) n * (size_t) size;
    void *p = calloc(n,size);
    if (!p && nbytes)
        err_nomem();
    return p;
#endif
}
#endif

/***************************
 */

#if _WIN32
void util_free(void *p)
{
    //dbg_printf("util_free(%p)\n",p);
#if 0 && MEM_DEBUG
    mem_free(p);
#elif UTIL_PH
    ph_free(p);
#else
    free(p);
#endif
}
#endif

/***************************
 */

#if _WIN32
void *util_realloc(void *oldp,unsigned n,unsigned size)
{
#if 0 && MEM_DEBUG
    //dbg_printf("util_realloc(%p,%d)\n",oldp,n * size);
    return mem_realloc(oldp,n * size);
#elif UTIL_PH
    return ph_realloc(oldp,n * size);
#else
    size_t nbytes = (size_t) n * (size_t) size;
    void *p = realloc(oldp,nbytes);
    if (!p && nbytes)
        err_nomem();
    return p;
#endif
}
#endif
