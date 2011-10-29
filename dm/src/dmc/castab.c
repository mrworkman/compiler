static const unsigned char casttab[CASTTABMAX][CASTTABMAX] = {
/* Vertical is from, horizontal is to   */
//              bool    char    schar   uchar   char8   char16  short   wchar_t ushort  enum    int     uint    long    ulong   dchar   llong   ullong  float   double  real64  real80  ifloat  idouble ildbl   cfloat  cdouble cldbl   jhandle nullptr nptr    sptr    cptr    f16ptr  fptr    hptr    vptr    ref     void
/* bool    */   NONE,   NONE,   PAINT,  PAINT,  PAINT,  CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   INT,    INT,    INT,    LONG,   LONG,   INT,    INT,    INT,    INT,    ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  INT,    INT,    INT,    INT,    INT,    ERROR,  INT,    INT,    INT,    REF,    PAINT,
/* char    */   BOOL,   NONE,   PAINT,  PAINT,  PAINT,  CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   INT,    INT,    INT,    INT,    LONG,   LONG,   INT,    INT,    INT,    INT,    ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  INT,    INT,    INT,    INT,    INT,    ERROR,  INT,    INT,    INT,    REF,    PAINT,
/* schar   */   BOOL,   PAINT,  NONE,   PAINT,  PAINT,  S8INT,  S8INT,  S8INT,  S8INT,  S8INT,  S8INT,  S8INT,  INT,    INT,    INT,    LONG,   LONG,   INT,    INT,    INT,    INT,    ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  INT,    INT,    INT,    INT,    INT,    ERROR,  INT,    INT,    INT,    REF,    PAINT,
/* uchar   */   BOOL,   PAINT,  PAINT,  NONE,   PAINT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  UINT,   UINT,   UINT,   UINT,   UINT,   ERROR,  UINT,   UINT,   UINT,   REF,    PAINT,
/* char8   */   BOOL,   PAINT,  PAINT,  PAINT,  NONE,   U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  UINT,   UINT,   UINT,   UINT,   UINT,   ERROR,  UINT,   UINT,   UINT,   REF,    PAINT,
/* char16  */   BOOL,   INT8,   INT8,   INT8,   INT8,   NONE,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, USHDBL, USHDBL, USHDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* short   */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  NONE,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  SHTLNG, SHTLNG, SHTLNG, LONG,   LONG,   DOUBLE, SHTDBL, SHTDBL, SHTDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* wchar_t */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  PAINT,  NONE,   PAINT,  PAINT,  PAINT,  PAINT,  USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, USHDBL, USHDBL, USHDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* ushort  */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  PAINT,  PAINT,  NONE,   PAINT,  PAINT,  PAINT,  USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, USHDBL, USHDBL, USHDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* enum    */   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   NONE,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ERROR,  ENUM,   ENUM,   ENUM,   REF,    PAINT,
/* int     */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  NONE,   PAINT,  SHTLNG, SHTLNG, SHTLNG, LONG,   LONG,   DOUBLE, SHTDBL, SHTDBL, SHTDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* uint    */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  NONE,   USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, USHDBL, USHDBL, USHDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* long    */   BOOL,   INT,    INT,    INT,    INT,    LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, NONE,   PAINT,  PAINT,  LNGLL,  LNGLL,  DOUBLE, LNGDBL, LNGDBL, LNGDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, ERROR,  PAINT,  PAINT,  PAINT,  REF,    PAINT,
/* ulong   */   BOOL,   INT,    INT,    INT,    INT,    LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  NONE,   PAINT,  ULNGLL, ULNGLL, DOUBLE, ULNGDBL,ULNGDBL,ULNGDBL,ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, ERROR,  PAINT,  PAINT,  PAINT,  REF,    PAINT,
/* dchar   */   BOOL,   INT,    INT,    INT,    INT,    LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  PAINT,  NONE,   ULNGLL, ULNGLL, DOUBLE, ULNGDBL,ULNGDBL,ULNGDBL,ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  LNGSHT, LNGSHT, LNGSHT, LNGSHT, LNGSHT, ERROR,  PAINT,  PAINT,  PAINT,  REF,    PAINT,
/* llong   */   BOOL,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    LONG,   LONG,   LLLNG,  LLLNG,  LLLNG,  NONE,   PAINT,  DOUBLE, OPs64_d,DOUBLE,DOUBLE,ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  INT,    INT,    INT,    INT,    INT,    ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* ullong  */   BOOL,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    LONG,   LONG,   LLLNG,  LLLNG,  LLLNG,  PAINT,  NONE,   DOUBLE, OPu64_d,DOUBLE, DOUBLE, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  INT,    INT,    INT,    INT,    INT,    ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* float   */   BOOL,   DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, NONE,   FLTDBL, FLTDBL, FLTDBL, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    PAINT,
/* double  */   BOOL,   INT,    INT,    INT,    INT,    DBLUSH, DBLSHT, DBLUSH, DBLUSH, DBLSHT, DBLSHT, DBLUSH, DBLLNG, DBLULNG,DBLULNG,OPd_s64,OPd_u64,DBLFLT,NONE,PAINT,   PAINT,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    PAINT,
/* real64  */   BOOL,   INT,    INT,    INT,    INT,    INT,    DBLSHT, INT,    INT,    INT,    DBLSHT, INT,    DBLLNG, DBLULNG,DBLULNG,DOUBLE, DOUBLE, DBLFLT, PAINT,  NONE,   NONE,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    PAINT,
/* real80  */   BOOL,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    DBLLNG, DBLULNG,DBLULNG,DOUBLE, DOUBLE, DBLFLT, PAINT,  NONE,   NONE,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    PAINT,
/* ifloat  */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* idouble */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* ildbl   */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* cfloat  */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* cdouble */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* cldbl   */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* jhandle */   BOOL,   INT,    INT,    INT,    INT,    PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PTRLPTR,PTRLPTR,PTRLPTR,ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  NONE,   PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  PTRLPTR,PTRLPTR,PTRLPTR, REF,   PAINT,
/* nullptr */   BOOL,   INT,    INT,    INT,    INT,    PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PTRLPTR,PTRLPTR,PTRLPTR,ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  NONE,   PAINT,  PAINT,  PAINT,  ERROR,  PTRLPTR,PTRLPTR,PTRLPTR, REF,   PAINT,
/* nptr    */   BOOL,   INT,    INT,    INT,    INT,    PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PTRLPTR,PTRLPTR,PTRLPTR,ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  NONE,   PAINT,  PAINT,  ERROR,  PTRLPTR,PTRLPTR,PTRLPTR, REF,   PAINT,
/* sptr    */   BOOL,   INT,    INT,    INT,    INT,    PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PTRLPTR,PTRLPTR,PTRLPTR,ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  NONE,   PAINT,  ERROR,  PTRLPTR,PTRLPTR,PTRLPTR, REF,   PAINT,
/* cptr    */   BOOL,   INT,    INT,    INT,    INT,    PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PTRLPTR,PTRLPTR,PTRLPTR,ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  NONE,   ERROR,  PTRLPTR,PTRLPTR,PTRLPTR, REF,   PAINT,
/* f16ptr  */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* fptr    */   BOOL,   INT,    INT,    INT,    INT,    LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  LONG,   LONG,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  OFFSET, OFFSET, OFFSET, OFFSET, OFFSET, ERROR,  NONE,   PAINT,  PAINT,  REF,    PAINT,
/* hptr    */   BOOL,   INT,    INT,    INT,    INT,    LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  LONG,   LONG,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  OFFSET, OFFSET, OFFSET, OFFSET, OFFSET, ERROR,  PAINT,  NONE,   PAINT,  REF,    PAINT,
/* vptr    */   BOOL,   INT,    INT,    INT,    INT,    LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  LONG,   LONG,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  OFFSET, OFFSET, OFFSET, OFFSET, OFFSET, ERROR,  FPTR,   NONE,   NONE,   REF,    PAINT,
/* ref     */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,
/* void    */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  NONE,
};

/* Same table, but for 32 bit ints and 48 bit far pointers      */
static const unsigned char casttab32[CASTTABMAX][CASTTABMAX] = {
/* Vertical is from, horizontal is to   */
//              bool    char    schar   uchar   char8   char16  short   wchar_t ushort  enum    int     uint    long    ulong   dchar   llong   ullong  float   double  real64  real80  ifloat  idouble ildbl   cfloat  cdouble cldbl   jhandle nullptr nptr    sptr    cptr    f16ptr  fptr    hptr    vptr    ref     void
/* bool    */   NONE,   NONE,   PAINT,  PAINT,  PAINT,  CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   INT,    INT,    INT,    LONG,   LONG,   INT,    INT,    INT,    INT,    ZERO,   ZERO,   ZERO,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    REF,    PAINT,
/* char    */   BOOL,   NONE,   PAINT,  PAINT,  PAINT,  CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   CINT,   INT,    INT,    INT,    LONG,   LONG,   INT,    INT,    INT,    INT,    ZERO,   ZERO,   ZERO,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    REF,    PAINT,
/* schar   */   BOOL,   PAINT,  NONE,   PAINT,  PAINT,  S8INT,  S8INT,  S8INT,  S8INT,  S8INT,  S8INT,  S8INT,  INT,    INT,    INT,    LONG,   LONG,   INT,    INT,    INT,    INT,    ZERO,   ZERO,   ZERO,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    REF,    PAINT,
/* uchar   */   BOOL,   PAINT,  PAINT,  NONE,   PAINT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   ZERO,   ZERO,   ZERO,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   REF,    PAINT,
/* char8   */   BOOL,   PAINT,  PAINT,  PAINT,  NONE,   U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  U8INT,  UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   ZERO,   ZERO,   ZERO,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   REF,    PAINT,
/* char16  */   BOOL,   INT8,   INT8,   INT8,   INT8,   NONE,   PAINT,  PAINT,  PAINT,   USHLNG, USHLNG, USHLNG, USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, LONG,   LONG,  LONG,   ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   LONG,   LONG,   LONG,   REF,    PAINT,
/* short   */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  NONE,   PAINT,  PAINT,  SHTLNG, SHTLNG, SHTLNG, SHTLNG, SHTLNG, SHTLNG, LONG,   LONG,   DOUBLE, SHTDBL, SHTDBL, DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, INT,    INT,    INT,    INT,    INT,    INT,    LONG,   LONG,   LONG,   REF,    PAINT,
/* wchar_t */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  PAINT,  NONE,   PAINT,  USHLNG, USHLNG, USHLNG, USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, LONG,   LONG,   LONG,   ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   LONG,   LONG,   LONG,   REF,    PAINT,
/* ushort  */   BOOL,   INT8,   INT8,   INT8,   INT8,   PAINT,  PAINT,  PAINT,  NONE,   USHLNG, USHLNG, USHLNG, USHLNG, USHLNG, USHLNG, ULONG,  ULONG,  DOUBLE, LONG,   LONG,   LONG,   ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, UINT,   UINT,   UINT,   UINT,   UINT,   UINT,   LONG,   LONG,   LONG,   REF,    PAINT,
/* enum    */   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ZERO,   ZERO,   ZERO,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   ENUM,   REF,    PAINT,
/* int     */   BOOL,   INT8,   INT8,   INT8,   INT8,   LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  NONE,   PAINT,  PAINT,  PAINT,  PAINT,  LONG,   LONG,   DOUBLE, LNGDBL, LNGDBL, DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  LONG,   LONG,   LONG,   REF,    PAINT,
/* uint    */   BOOL,   INT8,   INT8,   INT8,   INT8,   LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  PAINT,  NONE,   PAINT,  PAINT,  PAINT,  ULONG,  ULONG,  DOUBLE, ULNGDBL,ULNGDBL,DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  LONG,   LONG,   LONG,   REF,    PAINT,
/* long    */   BOOL,   INT,    INT,    INT,    INT,    LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  PAINT,  PAINT,  NONE,   PAINT,  PAINT,  LNGLL,  LNGLL,  DOUBLE, LNGDBL, LNGDBL, DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  LNGFPTR,LNGFPTR,LNGFPTR,REF,    PAINT,
/* ulong   */   BOOL,   INT,    INT,    INT,    INT,    LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  PAINT,  PAINT,  PAINT,  NONE,   PAINT,  ULNGLL, ULNGLL, DOUBLE, ULNGDBL,ULNGDBL,DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  LNGFPTR,LNGFPTR,LNGFPTR,REF,    PAINT,
/* dchar   */   BOOL,   INT,    INT,    INT,    INT,    LNGSHT, LNGSHT, LNGSHT, LNGSHT, PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  NONE,   ULNGLL, ULNGLL, DOUBLE, ULNGDBL,ULNGDBL,DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  LNGFPTR,LNGFPTR,LNGFPTR,REF,    PAINT,
/* llong   */   BOOL,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    LONG,   LONG,   LLLNG,  LLLNG,  LLLNG,  NONE,   PAINT,  DOUBLE, OPs64_d,OPs64_d,DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, INT,    INT,    INT,    INT,    INT,    ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* ullong  */   BOOL,   INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    INT,    LONG,   LONG,   LLLNG,  LLLNG,  LLLNG,  PAINT,  NONE,   DOUBLE, OPu64_d,OPu64_d,DOUBLE, ZERO,   ZERO,   ZERO,   DOUBLE, DOUBLE, DOUBLE, INT,    INT,    INT,    INT,    INT,    ERROR,  LONG,   LONG,   LONG,   REF,    PAINT,
/* float   */   BOOL,   DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, NONE,   OPf_d,  OPf_d,  DOUBLE, ZERO,   ZERO,   ZERO,   FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    VOID,
/* double  */   BOOL,   INT,    INT,    INT,    INT,    DBLUSH, DBLSHT, DBLUSH, DBLUSH, LONG,   LONG,   LONG,   DBLLNG, DBLULNG,DBLULNG,OPd_s64,OPd_u64,OPd_f,  NONE,   PAINT,  OPd_ld, ZERO,   ZERO,   ZERO,   FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    VOID,
/* real64  */   BOOL,   INT,    INT,    INT,    INT,    DBLUSH, DBLSHT, DBLUSH, DBLUSH, LONG,   LONG,   LONG,   DBLLNG, DBLULNG,DBLULNG,OPd_s64,OPd_u64,OPd_f,  NONE,   NONE,   OPd_ld, ZERO,   ZERO,   ZERO,   FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    VOID,
/* real80  */   BOOL,   DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, OPld_d, DOUBLE, NONE,   ZERO,   ZERO,   ZERO,   FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  REF,    VOID,
/* ifloat  */   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   NONE,   OPf_d,  IDOUBLE,FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* idouble */   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   OPd_f,  NONE,   OPd_ld, FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* ildbl   */   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   ZERO,   IDOUBLE,OPld_d, NONE,   FTOC,   FTOC,   FTOC,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* cfloat  */   BOOL,   DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, OPc_r,  CDOUBLE,ERROR,  CLDOUBLE,OPc_i, CDOUBLE,CLDOUBLE,NONE,  OPf_d,  CDOUBLE,ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* cdouble */   BOOL,   DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, CFLOAT, OPc_r,  ERROR,  CLDOUBLE,CFLOAT,OPc_i,  CLDOUBLE,OPd_f, NONE,   OPd_ld, ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* cldbl   */   BOOL,   DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, CFLOAT, CDOUBLE,ERROR,  OPc_r,  CFLOAT, CDOUBLE,OPc_i,  CDOUBLE,OPld_d, NONE,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,
/* jhandle */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  NONE,   PAINT,  PAINT,  PAINT,  PAINT,  TOF16,  PTRLPTR,ERROR,  PTRLPTR,REF,    PAINT,
/* nullptr */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  NONE,   PAINT,  PAINT,  PAINT,  TOF16,  PTRLPTR,ERROR,  PTRLPTR,REF,    PAINT,
/* nptr    */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  NONE,   PAINT,  PAINT,  TOF16,  PTRLPTR,ERROR,  PTRLPTR,REF,    PAINT,
/* sptr    */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  NONE,   PAINT,  NPTR,   PTRLPTR,ERROR,  PTRLPTR,REF,    PAINT,
/* cptr    */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ULONG,  ULONG,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,  PAINT,  PAINT,  PAINT,  NONE,   NPTR,   PTRLPTR,ERROR,  PTRLPTR,REF,    PAINT,
/* f16ptr  */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  PAINT,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  FRF16,  FRF16,  FRF16,  NPTR,   NPTR,   NONE,   NPTR,   ERROR,  NPTR,   REF,    PAINT,
/* fptr    */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   OFFSET, OFFSET, OFFSET, LONG,   LONG,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  OFFSET, OFFSET, OFFSET, OFFSET, OFFSET, NPTR,   NONE,   PAINT,  PAINT,  REF,    PAINT,
/* hptr    */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   OFFSET, OFFSET, OFFSET, LONG,   LONG,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  OFFSET, OFFSET, OFFSET, OFFSET, OFFSET, NPTR,   PAINT,  NONE,   PAINT,  REF,    PAINT,
/* vptr    */   BOOL,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   LONG,   OFFSET, OFFSET, OFFSET, LONG,   LONG,   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  OFFSET, OFFSET, OFFSET, OFFSET, OFFSET, NPTR,   FPTR,   NONE,   NONE,   REF,    PAINT,
/* ref     */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  PAINT,
/* void    */   ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  ERROR,  NONE,
};