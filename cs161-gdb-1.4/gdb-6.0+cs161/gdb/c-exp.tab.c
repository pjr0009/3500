/* A Bison parser, made from c-exp.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	INT	257
# define	FLOAT	258
# define	STRING	259
# define	NAME	260
# define	TYPENAME	261
# define	NAME_OR_INT	262
# define	STRUCT	263
# define	CLASS	264
# define	UNION	265
# define	ENUM	266
# define	SIZEOF	267
# define	UNSIGNED	268
# define	COLONCOLON	269
# define	TEMPLATE	270
# define	ERROR	271
# define	SIGNED_KEYWORD	272
# define	LONG	273
# define	SHORT	274
# define	INT_KEYWORD	275
# define	CONST_KEYWORD	276
# define	VOLATILE_KEYWORD	277
# define	DOUBLE_KEYWORD	278
# define	VARIABLE	279
# define	ASSIGN_MODIFY	280
# define	TRUEKEYWORD	281
# define	FALSEKEYWORD	282
# define	ABOVE_COMMA	283
# define	OROR	284
# define	ANDAND	285
# define	EQUAL	286
# define	NOTEQUAL	287
# define	LEQ	288
# define	GEQ	289
# define	LSH	290
# define	RSH	291
# define	UNARY	292
# define	INCREMENT	293
# define	DECREMENT	294
# define	ARROW	295
# define	BLOCKNAME	296
# define	FILENAME	297

#line 39 "c-exp.y"


#include "defs.h"
#include "gdb_string.h"
#include <ctype.h>
#include "expression.h"
#include "value.h"
#include "parser-defs.h"
#include "language.h"
#include "c-lang.h"
#include "bfd.h" /* Required by objfiles.h.  */
#include "symfile.h" /* Required by objfiles.h.  */
#include "objfiles.h" /* For have_full_symbols and have_partial_symbols */
#include "charset.h"
#include "block.h"

/* Flag indicating we're dealing with HP-compiled objects */ 
extern int hp_som_som_object_present;

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror, etc),
   as well as gratuitiously global symbol names, so we can have multiple
   yacc generated parsers in gdb.  Note that these are only the variables
   produced by yacc.  If other parser generators (bison, byacc, etc) produce
   additional global names that conflict at link time, then those parser
   generators need to be fixed instead of adding those names to this list. */

#define	yymaxdepth c_maxdepth
#define	yyparse	c_parse
#define	yylex	c_lex
#define	yyerror	c_error
#define	yylval	c_lval
#define	yychar	c_char
#define	yydebug	c_debug
#define	yypact	c_pact	
#define	yyr1	c_r1			
#define	yyr2	c_r2			
#define	yydef	c_def		
#define	yychk	c_chk		
#define	yypgo	c_pgo		
#define	yyact	c_act		
#define	yyexca	c_exca
#define yyerrflag c_errflag
#define yynerrs	c_nerrs
#define	yyps	c_ps
#define	yypv	c_pv
#define	yys	c_s
#define	yy_yys	c_yys
#define	yystate	c_state
#define	yytmp	c_tmp
#define	yyv	c_v
#define	yy_yyv	c_yyv
#define	yyval	c_val
#define	yylloc	c_lloc
#define yyreds	c_reds		/* With YYDEBUG defined */
#define yytoks	c_toks		/* With YYDEBUG defined */
#define yyname	c_name		/* With YYDEBUG defined */
#define yyrule	c_rule		/* With YYDEBUG defined */
#define yylhs	c_yylhs
#define yylen	c_yylen
#define yydefred c_yydefred
#define yydgoto	c_yydgoto
#define yysindex c_yysindex
#define yyrindex c_yyrindex
#define yygindex c_yygindex
#define yytable	 c_yytable
#define yycheck	 c_yycheck

#ifndef YYDEBUG
#define	YYDEBUG 1		/* Default to yydebug support */
#endif

#define YYFPRINTF parser_fprintf

int yyparse (void);

static int yylex (void);

void yyerror (char *);


#line 124 "c-exp.y"
#ifndef YYSTYPE
typedef union
  {
    LONGEST lval;
    struct {
      LONGEST val;
      struct type *type;
    } typed_val_int;
    struct {
      DOUBLEST dval;
      struct type *type;
    } typed_val_float;
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    struct ttype tsym;
    struct symtoken ssym;
    int voidval;
    struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  } yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#line 149 "c-exp.y"

/* YYSTYPE gets defined by %union */
static int parse_number (char *, int, int, YYSTYPE *);
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		239
#define	YYFLAG		-32768
#define	YYNTBASE	68

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 297 ? yytranslate[x] : 97)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    51,    37,     2,
      58,    64,    49,    47,    29,    48,    56,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,     2,
      40,    31,    41,    32,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    63,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    35,    66,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    30,    33,    34,    38,    39,    42,    43,
      44,    45,    52,    53,    54,    55,    59,    60
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     4,     6,     8,    12,    15,    18,    21,
      24,    27,    30,    33,    36,    39,    42,    46,    50,    55,
      59,    63,    68,    73,    74,    80,    82,    83,    85,    89,
      91,    95,   100,   105,   109,   113,   117,   121,   125,   129,
     133,   137,   141,   145,   149,   153,   157,   161,   165,   169,
     173,   177,   181,   185,   191,   195,   199,   201,   203,   205,
     207,   209,   214,   216,   218,   220,   222,   224,   228,   232,
     236,   241,   243,   246,   248,   251,   253,   254,   258,   260,
     262,   264,   265,   267,   270,   272,   275,   277,   281,   284,
     286,   289,   291,   294,   298,   301,   305,   307,   311,   313,
     315,   317,   319,   322,   326,   329,   333,   337,   341,   344,
     347,   351,   356,   360,   364,   369,   373,   378,   382,   387,
     390,   394,   397,   401,   404,   408,   410,   413,   416,   419,
     422,   425,   428,   430,   433,   435,   441,   444,   447,   449,
     451,   453,   455,   457,   461,   463,   468,   471,   474,   476,
     478,   480,   482,   484,   486,   488,   490
};
static const short yyrhs[] =
{
      70,     0,    69,     0,    88,     0,    71,     0,    70,    29,
      71,     0,    49,    71,     0,    37,    71,     0,    48,    71,
       0,    61,    71,     0,    62,    71,     0,    53,    71,     0,
      54,    71,     0,    71,    53,     0,    71,    54,     0,    13,
      71,     0,    71,    55,    95,     0,    71,    55,    78,     0,
      71,    55,    49,    71,     0,    71,    56,    95,     0,    71,
      56,    78,     0,    71,    56,    49,    71,     0,    71,    57,
      70,    63,     0,     0,    71,    58,    72,    74,    64,     0,
      65,     0,     0,    71,     0,    74,    29,    71,     0,    66,
       0,    73,    74,    75,     0,    73,    88,    75,    71,     0,
      58,    88,    64,    71,     0,    58,    70,    64,     0,    71,
      46,    71,     0,    71,    49,    71,     0,    71,    50,    71,
       0,    71,    51,    71,     0,    71,    47,    71,     0,    71,
      48,    71,     0,    71,    44,    71,     0,    71,    45,    71,
       0,    71,    38,    71,     0,    71,    39,    71,     0,    71,
      42,    71,     0,    71,    43,    71,     0,    71,    40,    71,
       0,    71,    41,    71,     0,    71,    37,    71,     0,    71,
      36,    71,     0,    71,    35,    71,     0,    71,    34,    71,
       0,    71,    33,    71,     0,    71,    32,    71,    67,    71,
       0,    71,    31,    71,     0,    71,    26,    71,     0,     3,
       0,     8,     0,     4,     0,    77,     0,    25,     0,    13,
      58,    88,    64,     0,     5,     0,    27,     0,    28,     0,
      59,     0,    60,     0,    76,    15,    95,     0,    76,    15,
      95,     0,    89,    15,    95,     0,    89,    15,    62,    95,
       0,    78,     0,    15,    95,     0,    96,     0,    46,     6,
       0,    94,     0,     0,    80,    79,    80,     0,    81,     0,
      94,     0,    82,     0,     0,    49,     0,    49,    84,     0,
      37,     0,    37,    84,     0,    85,     0,    58,    84,    64,
       0,    85,    86,     0,    86,     0,    85,    87,     0,    87,
       0,    57,    63,     0,    57,     3,    63,     0,    58,    64,
       0,    58,    91,    64,     0,    92,     0,    89,    15,    49,
       0,     7,     0,    21,     0,    19,     0,    20,     0,    19,
      21,     0,    19,    18,    21,     0,    19,    18,     0,    18,
      19,    21,     0,    14,    19,    21,     0,    19,    14,    21,
       0,    19,    14,     0,    19,    19,     0,    19,    19,    21,
       0,    19,    19,    18,    21,     0,    19,    19,    18,     0,
      18,    19,    19,     0,    18,    19,    19,    21,     0,    14,
      19,    19,     0,    14,    19,    19,    21,     0,    19,    19,
      14,     0,    19,    19,    14,    21,     0,    20,    21,     0,
      20,    18,    21,     0,    20,    18,     0,    14,    20,    21,
       0,    20,    14,     0,    20,    14,    21,     0,    24,     0,
      19,    24,     0,     9,    95,     0,    10,    95,     0,    11,
      95,     0,    12,    95,     0,    14,    90,     0,    14,     0,
      18,    90,     0,    18,     0,    16,    95,    40,    88,    41,
       0,    82,    89,     0,    89,    82,     0,     7,     0,    21,
       0,    19,     0,    20,     0,    88,     0,    91,    29,    88,
       0,    89,     0,    92,    83,    84,    83,     0,    22,    23,
       0,    23,    22,     0,    93,     0,    22,     0,    23,     0,
       6,     0,    59,     0,     7,     0,     8,     0,     6,     0,
      59,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   232,   233,   236,   243,   244,   249,   253,   257,   261,
     265,   269,   273,   277,   281,   285,   289,   295,   303,   307,
     313,   321,   325,   329,   329,   339,   343,   346,   350,   354,
     357,   364,   370,   376,   382,   386,   390,   394,   398,   402,
     406,   410,   414,   418,   422,   426,   430,   434,   438,   442,
     446,   450,   454,   458,   462,   466,   472,   479,   490,   497,
     500,   504,   512,   537,   544,   553,   561,   567,   578,   594,
     607,   631,   632,   666,   723,   729,   730,   733,   736,   737,
     740,   742,   745,   747,   749,   751,   753,   756,   758,   763,
     770,   772,   776,   778,   782,   784,   796,   797,   802,   804,
     806,   808,   810,   812,   814,   816,   818,   820,   822,   824,
     826,   828,   830,   832,   834,   836,   838,   840,   842,   844,
     846,   848,   850,   852,   854,   856,   858,   860,   863,   866,
     869,   872,   874,   876,   878,   883,   887,   889,   893,   894,
     900,   906,   915,   920,   927,   928,   932,   933,   936,   940,
     942,   946,   947,   948,   949,   952,   953
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "INT", "FLOAT", "STRING", "NAME", "TYPENAME", 
  "NAME_OR_INT", "STRUCT", "CLASS", "UNION", "ENUM", "SIZEOF", "UNSIGNED", 
  "COLONCOLON", "TEMPLATE", "ERROR", "SIGNED_KEYWORD", "LONG", "SHORT", 
  "INT_KEYWORD", "CONST_KEYWORD", "VOLATILE_KEYWORD", "DOUBLE_KEYWORD", 
  "VARIABLE", "ASSIGN_MODIFY", "TRUEKEYWORD", "FALSEKEYWORD", "','", 
  "ABOVE_COMMA", "'='", "'?'", "OROR", "ANDAND", "'|'", "'^'", "'&'", 
  "EQUAL", "NOTEQUAL", "'<'", "'>'", "LEQ", "GEQ", "LSH", "RSH", "'@'", 
  "'+'", "'-'", "'*'", "'/'", "'%'", "UNARY", "INCREMENT", "DECREMENT", 
  "ARROW", "'.'", "'['", "'('", "BLOCKNAME", "FILENAME", "'!'", "'~'", 
  "']'", "')'", "'{'", "'}'", "':'", "start", "type_exp", "exp1", "exp", 
  "@1", "lcurly", "arglist", "rcurly", "block", "variable", 
  "qualified_name", "space_identifier", "const_or_volatile", 
  "cv_with_space_id", "const_or_volatile_or_space_identifier_noopt", 
  "const_or_volatile_or_space_identifier", "abs_decl", "direct_abs_decl", 
  "array_mod", "func_mod", "type", "typebase", "typename", 
  "nonempty_typelist", "ptype", "const_and_volatile", 
  "const_or_volatile_noopt", "name", "name_not_typename", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    68,    68,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    71,    73,    74,    74,    74,    75,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    76,    76,    76,    77,    78,
      78,    77,    77,    77,    79,    80,    80,    81,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      94,    95,    95,    95,    95,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     1,     1,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     4,     3,
       3,     4,     4,     0,     5,     1,     0,     1,     3,     1,
       3,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     3,     3,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     3,     3,     3,
       4,     1,     2,     1,     2,     1,     0,     3,     1,     1,
       1,     0,     1,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     2,     3,     2,     3,     1,     3,     1,     1,
       1,     1,     2,     3,     2,     3,     3,     3,     2,     2,
       3,     4,     3,     3,     4,     3,     4,     3,     4,     2,
       3,     2,     3,     2,     3,     1,     2,     2,     2,     2,
       2,     2,     1,     2,     1,     5,     2,     2,     1,     1,
       1,     1,     1,     3,     1,     4,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
      76,    56,    58,    62,   155,    98,    57,     0,     0,     0,
       0,    76,   132,     0,     0,   134,   100,   101,    99,   149,
     150,   125,    60,    63,    64,    76,    76,    76,    76,    76,
      76,   156,    66,    76,    76,    25,     2,     1,     4,    26,
       0,    59,    71,     0,    78,    76,     3,   144,    96,   148,
      79,    73,   151,   153,   154,   152,   127,   128,   129,   130,
      76,    15,    76,   138,   140,   141,   139,   131,    72,     0,
     140,   141,   133,   108,   104,   109,   102,   126,   123,   121,
     119,   146,   147,     7,     8,     6,    11,    12,     0,     0,
       9,    10,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    13,    14,    76,    76,    76,
      23,    27,     0,     0,     0,     0,    76,   136,     0,   137,
      80,     0,     0,     0,   115,   106,   122,    76,   113,   105,
     107,   103,   117,   112,   110,   124,   120,    33,    76,     5,
      55,    54,     0,    52,    51,    50,    49,    48,    42,    43,
      46,    47,    44,    45,    40,    41,    34,    38,    39,    35,
      36,    37,   153,    76,    17,    16,    76,    20,    19,     0,
      26,    76,    29,    30,    76,    68,    74,    77,    75,    97,
       0,    69,    84,    82,     0,    76,    81,    86,    89,    91,
      61,   116,     0,   144,   114,   118,   111,    32,    76,    18,
      21,    22,     0,    28,    31,    70,    85,    83,     0,    92,
      94,     0,   142,     0,   145,    76,    88,    90,   135,     0,
      53,    24,    93,    87,    76,    95,   143,     0,     0,     0
};

static const short yydefgoto[] =
{
     237,    36,    88,    38,   180,    39,   122,   183,    40,    41,
      42,   126,    43,    44,    45,   131,   196,   197,   198,   199,
     222,    62,    67,   223,    48,    49,    50,   191,    51
};

static const short yypact[] =
{
     262,-32768,-32768,-32768,-32768,-32768,-32768,    49,    49,    49,
      49,   325,    17,    49,    49,    27,   219,   100,-32768,    -8,
      11,-32768,-32768,-32768,-32768,   262,   262,   262,   262,   262,
     262,    48,-32768,   262,   262,-32768,-32768,    39,   558,   199,
      57,-32768,-32768,    38,-32768,   284,-32768,   111,    90,-32768,
      71,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
     262,   725,   120,-32768,   110,    99,-32768,-32768,-32768,   105,
     125,-32768,-32768,   109,   119,   154,-32768,-32768,   146,   150,
  -32768,-32768,-32768,   725,   725,   725,   725,   725,   -15,    68,
     725,   725,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,-32768,-32768,   473,   492,   262,
  -32768,   558,   -16,    93,    49,   172,    19,     6,   103,-32768,
  -32768,   133,   116,   117,   160,-32768,-32768,   284,   162,-32768,
  -32768,-32768,   164,   165,-32768,-32768,-32768,-32768,   262,   558,
     558,   558,   521,   610,   634,   657,   679,   700,   719,   719,
     310,   310,   310,   310,   411,   411,   470,   480,   480,   725,
     725,   725,   138,   262,-32768,-32768,   262,-32768,-32768,    -4,
     199,   262,-32768,-32768,   262,   174,-32768,-32768,-32768,-32768,
      49,-32768,   -14,    92,     7,   414,     6,    97,-32768,-32768,
     388,-32768,   151,   141,-32768,-32768,-32768,   725,   262,   725,
     725,-32768,   -13,   558,   725,-32768,-32768,-32768,   131,-32768,
  -32768,   132,-32768,    -6,-32768,    55,-32768,-32768,-32768,   148,
     585,-32768,-32768,-32768,   284,-32768,-32768,   198,   200,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,     9,    -7,-32768,-32768,    36,    76,-32768,-32768,
     -64,-32768,   102,-32768,   -45,    33,  -112,-32768,    34,    35,
       1,     0,   215,-32768,-32768,-32768,   113,    -2,-32768
};


#define	YYLAST		783


static const short yytable[] =
{
      47,    46,   129,   130,    61,    56,    57,    58,    59,    37,
     218,    68,    69,   181,    92,    81,   181,   129,    83,    84,
      85,    86,    87,   234,    63,    92,    90,    91,    19,    20,
      47,    89,   121,    82,    63,   193,    64,    65,    66,    47,
     123,    19,    20,   194,   195,   127,    70,    71,    66,   147,
     182,   231,   -76,   174,   177,    52,    53,    54,   235,   211,
      47,   132,     5,   -65,     7,     8,     9,    10,    92,    12,
     219,    14,   124,    15,    16,    17,    18,    19,    20,    21,
     216,   217,   129,   221,   125,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    55,    52,
      53,    54,    19,    20,    78,   175,   178,   -75,    79,   220,
     136,    80,   185,    52,    53,    54,   128,   -81,   179,   134,
     140,   135,   148,    19,    20,   133,   -76,   203,   202,   -81,
     141,   207,    19,    20,   138,   137,   139,   -81,   -81,   194,
     195,   130,   189,   -98,   194,   225,   229,   -76,   129,   182,
     -98,   -98,    55,    19,    20,   190,   209,   145,   142,   210,
     192,   146,   143,   121,   213,   144,    55,   214,   186,   190,
     200,   201,   193,   204,   -98,   205,   206,   -76,   215,   -67,
     194,   195,   228,   207,   232,   203,   233,   189,   238,   184,
     239,   230,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   212,    15,    16,    17,
      18,    19,    20,    21,    22,   203,    23,    24,   187,   224,
      72,   226,   227,    73,   203,   236,    25,    74,    75,   188,
      76,     0,     0,    77,     0,   -76,     0,    26,    27,     0,
       0,     0,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,     0,    35,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,     5,     0,     7,     8,     9,    10,     0,    12,    25,
      14,     0,    15,    16,    17,    18,    19,    20,    21,     0,
      26,    27,     0,     0,     0,    28,    29,     0,     0,     0,
      30,    31,    32,    33,    34,     0,     0,    35,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,   107,   108,   109,   110,   111,   112,
     113,   114,    25,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,    26,    27,     0,     0,     0,    28,    29,
       0,     0,     0,    60,    31,    32,    33,    34,     0,     0,
      35,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,     0,    23,    24,     0,     0,     0,
       0,     5,     0,     7,     8,     9,    10,     0,    12,     0,
      14,     0,    15,    16,    17,    18,    19,    20,    21,     0,
       0,    28,    29,     0,     0,     0,    30,    31,    32,    33,
      34,   192,     0,    35,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   193,   115,   116,   117,   118,   119,   120,
       0,   194,   195,     0,     0,     0,     0,     0,   220,    52,
     172,    54,     7,     8,     9,    10,     0,    12,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    52,   172,
      54,     7,     8,     9,    10,     0,    12,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,   110,   111,   112,
     113,   114,   173,   115,   116,   117,   118,   119,   120,   112,
     113,   114,    55,   115,   116,   117,   118,   119,   120,     0,
       0,   176,     0,     0,     0,     0,     0,    93,     0,     0,
       0,    55,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,    93,     0,     0,     0,   208,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,   115,   116,
     117,   118,   119,   120,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,   115,   116,   117,   118,   119,   120,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
     115,   116,   117,   118,   119,   120,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,   115,   116,   117,   118,   119,   120,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   115,   116,
     117,   118,   119,   120
};

static const short yycheck[] =
{
       0,     0,    47,    48,    11,     7,     8,     9,    10,     0,
       3,    13,    14,    29,    29,    23,    29,    62,    25,    26,
      27,    28,    29,    29,     7,    29,    33,    34,    22,    23,
      30,    30,    39,    22,     7,    49,    19,    20,    21,    39,
      39,    22,    23,    57,    58,    45,    19,    20,    21,    64,
      66,    64,    46,   117,   118,     6,     7,     8,    64,    63,
      60,    60,     7,    15,     9,    10,    11,    12,    29,    14,
      63,    16,    15,    18,    19,    20,    21,    22,    23,    24,
     192,   193,   127,   195,    46,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    59,     6,
       7,     8,    22,    23,    14,   117,   118,    46,    18,    64,
      21,    21,   124,     6,     7,     8,    15,    37,   119,    19,
      21,    21,    64,    22,    23,    15,    46,   137,   137,    49,
      21,   148,    22,    23,    19,    40,    21,    57,    58,    57,
      58,   196,    49,    15,    57,    58,    15,    46,   203,    66,
      22,    23,    59,    22,    23,    62,   173,    21,    14,   176,
      37,    21,    18,   180,   181,    21,    59,   184,     6,    62,
      64,    21,    49,    21,    46,    21,    21,    46,   190,    15,
      57,    58,    41,   200,    63,   195,    64,    49,     0,   123,
       0,   208,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   180,    18,    19,    20,
      21,    22,    23,    24,    25,   225,    27,    28,   126,   196,
      15,   197,   197,    14,   234,   234,    37,    18,    19,   126,
      21,    -1,    -1,    24,    -1,    46,    -1,    48,    49,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    -1,    65,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,     7,    -1,     9,    10,    11,    12,    -1,    14,    37,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      48,    49,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    -1,    -1,    65,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    44,    45,    46,    47,    48,    49,
      50,    51,    37,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,    54,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    -1,    -1,
      65,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    12,    -1,    14,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    53,    54,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    37,    -1,    65,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    49,    53,    54,    55,    56,    57,    58,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    47,    48,    49,
      50,    51,    49,    53,    54,    55,    56,    57,    58,    49,
      50,    51,    59,    53,    54,    55,    56,    57,    58,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    59,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    67,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    53,    54,
      55,    56,    57,    58
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or xmalloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC xmalloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to xreallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to xreallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 3:
#line 237 "c-exp.y"
{ write_exp_elt_opcode(OP_TYPE);
			  write_exp_elt_type(yyvsp[0].tval);
			  write_exp_elt_opcode(OP_TYPE);}
    break;
case 5:
#line 245 "c-exp.y"
{ write_exp_elt_opcode (BINOP_COMMA); }
    break;
case 6:
#line 250 "c-exp.y"
{ write_exp_elt_opcode (UNOP_IND); }
    break;
case 7:
#line 254 "c-exp.y"
{ write_exp_elt_opcode (UNOP_ADDR); }
    break;
case 8:
#line 258 "c-exp.y"
{ write_exp_elt_opcode (UNOP_NEG); }
    break;
case 9:
#line 262 "c-exp.y"
{ write_exp_elt_opcode (UNOP_LOGICAL_NOT); }
    break;
case 10:
#line 266 "c-exp.y"
{ write_exp_elt_opcode (UNOP_COMPLEMENT); }
    break;
case 11:
#line 270 "c-exp.y"
{ write_exp_elt_opcode (UNOP_PREINCREMENT); }
    break;
case 12:
#line 274 "c-exp.y"
{ write_exp_elt_opcode (UNOP_PREDECREMENT); }
    break;
case 13:
#line 278 "c-exp.y"
{ write_exp_elt_opcode (UNOP_POSTINCREMENT); }
    break;
case 14:
#line 282 "c-exp.y"
{ write_exp_elt_opcode (UNOP_POSTDECREMENT); }
    break;
case 15:
#line 286 "c-exp.y"
{ write_exp_elt_opcode (UNOP_SIZEOF); }
    break;
case 16:
#line 290 "c-exp.y"
{ write_exp_elt_opcode (STRUCTOP_PTR);
			  write_exp_string (yyvsp[0].sval);
			  write_exp_elt_opcode (STRUCTOP_PTR); }
    break;
case 17:
#line 296 "c-exp.y"
{ /* exp->type::name becomes exp->*(&type::name) */
			  /* Note: this doesn't work if name is a
			     static member!  FIXME */
			  write_exp_elt_opcode (UNOP_ADDR);
			  write_exp_elt_opcode (STRUCTOP_MPTR); }
    break;
case 18:
#line 304 "c-exp.y"
{ write_exp_elt_opcode (STRUCTOP_MPTR); }
    break;
case 19:
#line 308 "c-exp.y"
{ write_exp_elt_opcode (STRUCTOP_STRUCT);
			  write_exp_string (yyvsp[0].sval);
			  write_exp_elt_opcode (STRUCTOP_STRUCT); }
    break;
case 20:
#line 314 "c-exp.y"
{ /* exp.type::name becomes exp.*(&type::name) */
			  /* Note: this doesn't work if name is a
			     static member!  FIXME */
			  write_exp_elt_opcode (UNOP_ADDR);
			  write_exp_elt_opcode (STRUCTOP_MEMBER); }
    break;
case 21:
#line 322 "c-exp.y"
{ write_exp_elt_opcode (STRUCTOP_MEMBER); }
    break;
case 22:
#line 326 "c-exp.y"
{ write_exp_elt_opcode (BINOP_SUBSCRIPT); }
    break;
case 23:
#line 332 "c-exp.y"
{ start_arglist (); }
    break;
case 24:
#line 334 "c-exp.y"
{ write_exp_elt_opcode (OP_FUNCALL);
			  write_exp_elt_longcst ((LONGEST) end_arglist ());
			  write_exp_elt_opcode (OP_FUNCALL); }
    break;
case 25:
#line 340 "c-exp.y"
{ start_arglist (); }
    break;
case 27:
#line 347 "c-exp.y"
{ arglist_len = 1; }
    break;
case 28:
#line 351 "c-exp.y"
{ arglist_len++; }
    break;
case 29:
#line 355 "c-exp.y"
{ yyval.lval = end_arglist () - 1; }
    break;
case 30:
#line 358 "c-exp.y"
{ write_exp_elt_opcode (OP_ARRAY);
			  write_exp_elt_longcst ((LONGEST) 0);
			  write_exp_elt_longcst ((LONGEST) yyvsp[0].lval);
			  write_exp_elt_opcode (OP_ARRAY); }
    break;
case 31:
#line 365 "c-exp.y"
{ write_exp_elt_opcode (UNOP_MEMVAL);
			  write_exp_elt_type (yyvsp[-2].tval);
			  write_exp_elt_opcode (UNOP_MEMVAL); }
    break;
case 32:
#line 371 "c-exp.y"
{ write_exp_elt_opcode (UNOP_CAST);
			  write_exp_elt_type (yyvsp[-2].tval);
			  write_exp_elt_opcode (UNOP_CAST); }
    break;
case 33:
#line 377 "c-exp.y"
{ }
    break;
case 34:
#line 383 "c-exp.y"
{ write_exp_elt_opcode (BINOP_REPEAT); }
    break;
case 35:
#line 387 "c-exp.y"
{ write_exp_elt_opcode (BINOP_MUL); }
    break;
case 36:
#line 391 "c-exp.y"
{ write_exp_elt_opcode (BINOP_DIV); }
    break;
case 37:
#line 395 "c-exp.y"
{ write_exp_elt_opcode (BINOP_REM); }
    break;
case 38:
#line 399 "c-exp.y"
{ write_exp_elt_opcode (BINOP_ADD); }
    break;
case 39:
#line 403 "c-exp.y"
{ write_exp_elt_opcode (BINOP_SUB); }
    break;
case 40:
#line 407 "c-exp.y"
{ write_exp_elt_opcode (BINOP_LSH); }
    break;
case 41:
#line 411 "c-exp.y"
{ write_exp_elt_opcode (BINOP_RSH); }
    break;
case 42:
#line 415 "c-exp.y"
{ write_exp_elt_opcode (BINOP_EQUAL); }
    break;
case 43:
#line 419 "c-exp.y"
{ write_exp_elt_opcode (BINOP_NOTEQUAL); }
    break;
case 44:
#line 423 "c-exp.y"
{ write_exp_elt_opcode (BINOP_LEQ); }
    break;
case 45:
#line 427 "c-exp.y"
{ write_exp_elt_opcode (BINOP_GEQ); }
    break;
case 46:
#line 431 "c-exp.y"
{ write_exp_elt_opcode (BINOP_LESS); }
    break;
case 47:
#line 435 "c-exp.y"
{ write_exp_elt_opcode (BINOP_GTR); }
    break;
case 48:
#line 439 "c-exp.y"
{ write_exp_elt_opcode (BINOP_BITWISE_AND); }
    break;
case 49:
#line 443 "c-exp.y"
{ write_exp_elt_opcode (BINOP_BITWISE_XOR); }
    break;
case 50:
#line 447 "c-exp.y"
{ write_exp_elt_opcode (BINOP_BITWISE_IOR); }
    break;
case 51:
#line 451 "c-exp.y"
{ write_exp_elt_opcode (BINOP_LOGICAL_AND); }
    break;
case 52:
#line 455 "c-exp.y"
{ write_exp_elt_opcode (BINOP_LOGICAL_OR); }
    break;
case 53:
#line 459 "c-exp.y"
{ write_exp_elt_opcode (TERNOP_COND); }
    break;
case 54:
#line 463 "c-exp.y"
{ write_exp_elt_opcode (BINOP_ASSIGN); }
    break;
case 55:
#line 467 "c-exp.y"
{ write_exp_elt_opcode (BINOP_ASSIGN_MODIFY);
			  write_exp_elt_opcode (yyvsp[-1].opcode);
			  write_exp_elt_opcode (BINOP_ASSIGN_MODIFY); }
    break;
case 56:
#line 473 "c-exp.y"
{ write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (yyvsp[0].typed_val_int.type);
			  write_exp_elt_longcst ((LONGEST)(yyvsp[0].typed_val_int.val));
			  write_exp_elt_opcode (OP_LONG); }
    break;
case 57:
#line 480 "c-exp.y"
{ YYSTYPE val;
			  parse_number (yyvsp[0].ssym.stoken.ptr, yyvsp[0].ssym.stoken.length, 0, &val);
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (val.typed_val_int.type);
			  write_exp_elt_longcst ((LONGEST)val.typed_val_int.val);
			  write_exp_elt_opcode (OP_LONG);
			}
    break;
case 58:
#line 491 "c-exp.y"
{ write_exp_elt_opcode (OP_DOUBLE);
			  write_exp_elt_type (yyvsp[0].typed_val_float.type);
			  write_exp_elt_dblcst (yyvsp[0].typed_val_float.dval);
			  write_exp_elt_opcode (OP_DOUBLE); }
    break;
case 61:
#line 505 "c-exp.y"
{ write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (builtin_type_int);
			  CHECK_TYPEDEF (yyvsp[-1].tval);
			  write_exp_elt_longcst ((LONGEST) TYPE_LENGTH (yyvsp[-1].tval));
			  write_exp_elt_opcode (OP_LONG); }
    break;
case 62:
#line 513 "c-exp.y"
{ /* C strings are converted into array constants with
			     an explicit null byte added at the end.  Thus
			     the array upper bound is the string length.
			     There is no such thing in C as a completely empty
			     string. */
			  char *sp = yyvsp[0].sval.ptr; int count = yyvsp[0].sval.length;
			  while (count-- > 0)
			    {
			      write_exp_elt_opcode (OP_LONG);
			      write_exp_elt_type (builtin_type_char);
			      write_exp_elt_longcst ((LONGEST)(*sp++));
			      write_exp_elt_opcode (OP_LONG);
			    }
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (builtin_type_char);
			  write_exp_elt_longcst ((LONGEST)'\0');
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_opcode (OP_ARRAY);
			  write_exp_elt_longcst ((LONGEST) 0);
			  write_exp_elt_longcst ((LONGEST) (yyvsp[0].sval.length));
			  write_exp_elt_opcode (OP_ARRAY); }
    break;
case 63:
#line 538 "c-exp.y"
{ write_exp_elt_opcode (OP_LONG);
                          write_exp_elt_type (builtin_type_bool);
                          write_exp_elt_longcst ((LONGEST) 1);
                          write_exp_elt_opcode (OP_LONG); }
    break;
case 64:
#line 545 "c-exp.y"
{ write_exp_elt_opcode (OP_LONG);
                          write_exp_elt_type (builtin_type_bool);
                          write_exp_elt_longcst ((LONGEST) 0);
                          write_exp_elt_opcode (OP_LONG); }
    break;
case 65:
#line 554 "c-exp.y"
{
			  if (yyvsp[0].ssym.sym)
			    yyval.bval = SYMBOL_BLOCK_VALUE (yyvsp[0].ssym.sym);
			  else
			    error ("No file or function \"%s\".",
				   copy_name (yyvsp[0].ssym.stoken));
			}
    break;
case 66:
#line 562 "c-exp.y"
{
			  yyval.bval = yyvsp[0].bval;
			}
    break;
case 67:
#line 568 "c-exp.y"
{ struct symbol *tem
			    = lookup_symbol (copy_name (yyvsp[0].sval), yyvsp[-2].bval,
					     VAR_DOMAIN, (int *) NULL,
					     (struct symtab **) NULL);
			  if (!tem || SYMBOL_CLASS (tem) != LOC_BLOCK)
			    error ("No function \"%s\" in specified context.",
				   copy_name (yyvsp[0].sval));
			  yyval.bval = SYMBOL_BLOCK_VALUE (tem); }
    break;
case 68:
#line 579 "c-exp.y"
{ struct symbol *sym;
			  sym = lookup_symbol (copy_name (yyvsp[0].sval), yyvsp[-2].bval,
					       VAR_DOMAIN, (int *) NULL,
					       (struct symtab **) NULL);
			  if (sym == 0)
			    error ("No symbol \"%s\" in specified context.",
				   copy_name (yyvsp[0].sval));

			  write_exp_elt_opcode (OP_VAR_VALUE);
			  /* block_found is set by lookup_symbol.  */
			  write_exp_elt_block (block_found);
			  write_exp_elt_sym (sym);
			  write_exp_elt_opcode (OP_VAR_VALUE); }
    break;
case 69:
#line 595 "c-exp.y"
{
			  struct type *type = yyvsp[-2].tval;
			  if (TYPE_CODE (type) != TYPE_CODE_STRUCT
			      && TYPE_CODE (type) != TYPE_CODE_UNION)
			    error ("`%s' is not defined as an aggregate type.",
				   TYPE_NAME (type));

			  write_exp_elt_opcode (OP_SCOPE);
			  write_exp_elt_type (type);
			  write_exp_string (yyvsp[0].sval);
			  write_exp_elt_opcode (OP_SCOPE);
			}
    break;
case 70:
#line 608 "c-exp.y"
{
			  struct type *type = yyvsp[-3].tval;
			  struct stoken tmp_token;
			  if (TYPE_CODE (type) != TYPE_CODE_STRUCT
			      && TYPE_CODE (type) != TYPE_CODE_UNION)
			    error ("`%s' is not defined as an aggregate type.",
				   TYPE_NAME (type));

			  tmp_token.ptr = (char*) alloca (yyvsp[0].sval.length + 2);
			  tmp_token.length = yyvsp[0].sval.length + 1;
			  tmp_token.ptr[0] = '~';
			  memcpy (tmp_token.ptr+1, yyvsp[0].sval.ptr, yyvsp[0].sval.length);
			  tmp_token.ptr[tmp_token.length] = 0;

			  /* Check for valid destructor name.  */
			  destructor_name_p (tmp_token.ptr, type);
			  write_exp_elt_opcode (OP_SCOPE);
			  write_exp_elt_type (type);
			  write_exp_string (tmp_token);
			  write_exp_elt_opcode (OP_SCOPE);
			}
    break;
case 72:
#line 633 "c-exp.y"
{
			  char *name = copy_name (yyvsp[0].sval);
			  struct symbol *sym;
			  struct minimal_symbol *msymbol;

			  sym =
			    lookup_symbol (name, (const struct block *) NULL,
					   VAR_DOMAIN, (int *) NULL,
					   (struct symtab **) NULL);
			  if (sym)
			    {
			      write_exp_elt_opcode (OP_VAR_VALUE);
			      write_exp_elt_block (NULL);
			      write_exp_elt_sym (sym);
			      write_exp_elt_opcode (OP_VAR_VALUE);
			      break;
			    }

			  msymbol = lookup_minimal_symbol (name, NULL, NULL);
			  if (msymbol != NULL)
			    {
			      write_exp_msymbol (msymbol,
						 lookup_function_type (builtin_type_int),
						 builtin_type_int);
			    }
			  else
			    if (!have_full_symbols () && !have_partial_symbols ())
			      error ("No symbol table is loaded.  Use the \"file\" command.");
			    else
			      error ("No symbol \"%s\" in current context.", name);
			}
    break;
case 73:
#line 667 "c-exp.y"
{ struct symbol *sym = yyvsp[0].ssym.sym;

			  if (sym)
			    {
			      if (symbol_read_needs_frame (sym))
				{
				  if (innermost_block == 0 ||
				      contained_in (block_found, 
						    innermost_block))
				    innermost_block = block_found;
				}

			      write_exp_elt_opcode (OP_VAR_VALUE);
			      /* We want to use the selected frame, not
				 another more inner frame which happens to
				 be in the same block.  */
			      write_exp_elt_block (NULL);
			      write_exp_elt_sym (sym);
			      write_exp_elt_opcode (OP_VAR_VALUE);
			    }
			  else if (yyvsp[0].ssym.is_a_field_of_this)
			    {
			      /* C++: it hangs off of `this'.  Must
			         not inadvertently convert from a method call
				 to data ref.  */
			      if (innermost_block == 0 || 
				  contained_in (block_found, innermost_block))
				innermost_block = block_found;
			      write_exp_elt_opcode (OP_THIS);
			      write_exp_elt_opcode (OP_THIS);
			      write_exp_elt_opcode (STRUCTOP_PTR);
			      write_exp_string (yyvsp[0].ssym.stoken);
			      write_exp_elt_opcode (STRUCTOP_PTR);
			    }
			  else
			    {
			      struct minimal_symbol *msymbol;
			      register char *arg = copy_name (yyvsp[0].ssym.stoken);

			      msymbol =
				lookup_minimal_symbol (arg, NULL, NULL);
			      if (msymbol != NULL)
				{
				  write_exp_msymbol (msymbol,
						     lookup_function_type (builtin_type_int),
						     builtin_type_int);
				}
			      else if (!have_full_symbols () && !have_partial_symbols ())
				error ("No symbol table is loaded.  Use the \"file\" command.");
			      else
				error ("No symbol \"%s\" in current context.",
				       copy_name (yyvsp[0].ssym.stoken));
			    }
			}
    break;
case 74:
#line 724 "c-exp.y"
{ push_type_address_space (copy_name (yyvsp[0].ssym.stoken));
		  push_type (tp_space_identifier);
		}
    break;
case 82:
#line 746 "c-exp.y"
{ push_type (tp_pointer); yyval.voidval = 0; }
    break;
case 83:
#line 748 "c-exp.y"
{ push_type (tp_pointer); yyval.voidval = yyvsp[0].voidval; }
    break;
case 84:
#line 750 "c-exp.y"
{ push_type (tp_reference); yyval.voidval = 0; }
    break;
case 85:
#line 752 "c-exp.y"
{ push_type (tp_reference); yyval.voidval = yyvsp[0].voidval; }
    break;
case 87:
#line 757 "c-exp.y"
{ yyval.voidval = yyvsp[-1].voidval; }
    break;
case 88:
#line 759 "c-exp.y"
{
			  push_type_int (yyvsp[0].lval);
			  push_type (tp_array);
			}
    break;
case 89:
#line 764 "c-exp.y"
{
			  push_type_int (yyvsp[0].lval);
			  push_type (tp_array);
			  yyval.voidval = 0;
			}
    break;
case 90:
#line 771 "c-exp.y"
{ push_type (tp_function); }
    break;
case 91:
#line 773 "c-exp.y"
{ push_type (tp_function); }
    break;
case 92:
#line 777 "c-exp.y"
{ yyval.lval = -1; }
    break;
case 93:
#line 779 "c-exp.y"
{ yyval.lval = yyvsp[-1].typed_val_int.val; }
    break;
case 94:
#line 783 "c-exp.y"
{ yyval.voidval = 0; }
    break;
case 95:
#line 785 "c-exp.y"
{ free (yyvsp[-1].tvec); yyval.voidval = 0; }
    break;
case 97:
#line 798 "c-exp.y"
{ yyval.tval = lookup_member_type (builtin_type_int, yyvsp[-2].tval); }
    break;
case 98:
#line 803 "c-exp.y"
{ yyval.tval = yyvsp[0].tsym.type; }
    break;
case 99:
#line 805 "c-exp.y"
{ yyval.tval = builtin_type_int; }
    break;
case 100:
#line 807 "c-exp.y"
{ yyval.tval = builtin_type_long; }
    break;
case 101:
#line 809 "c-exp.y"
{ yyval.tval = builtin_type_short; }
    break;
case 102:
#line 811 "c-exp.y"
{ yyval.tval = builtin_type_long; }
    break;
case 103:
#line 813 "c-exp.y"
{ yyval.tval = builtin_type_long; }
    break;
case 104:
#line 815 "c-exp.y"
{ yyval.tval = builtin_type_long; }
    break;
case 105:
#line 817 "c-exp.y"
{ yyval.tval = builtin_type_long; }
    break;
case 106:
#line 819 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long; }
    break;
case 107:
#line 821 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long; }
    break;
case 108:
#line 823 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long; }
    break;
case 109:
#line 825 "c-exp.y"
{ yyval.tval = builtin_type_long_long; }
    break;
case 110:
#line 827 "c-exp.y"
{ yyval.tval = builtin_type_long_long; }
    break;
case 111:
#line 829 "c-exp.y"
{ yyval.tval = builtin_type_long_long; }
    break;
case 112:
#line 831 "c-exp.y"
{ yyval.tval = builtin_type_long_long; }
    break;
case 113:
#line 833 "c-exp.y"
{ yyval.tval = builtin_type_long_long; }
    break;
case 114:
#line 835 "c-exp.y"
{ yyval.tval = builtin_type_long_long; }
    break;
case 115:
#line 837 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long_long; }
    break;
case 116:
#line 839 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long_long; }
    break;
case 117:
#line 841 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long_long; }
    break;
case 118:
#line 843 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_long_long; }
    break;
case 119:
#line 845 "c-exp.y"
{ yyval.tval = builtin_type_short; }
    break;
case 120:
#line 847 "c-exp.y"
{ yyval.tval = builtin_type_short; }
    break;
case 121:
#line 849 "c-exp.y"
{ yyval.tval = builtin_type_short; }
    break;
case 122:
#line 851 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_short; }
    break;
case 123:
#line 853 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_short; }
    break;
case 124:
#line 855 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_short; }
    break;
case 125:
#line 857 "c-exp.y"
{ yyval.tval = builtin_type_double; }
    break;
case 126:
#line 859 "c-exp.y"
{ yyval.tval = builtin_type_long_double; }
    break;
case 127:
#line 861 "c-exp.y"
{ yyval.tval = lookup_struct (copy_name (yyvsp[0].sval),
					      expression_context_block); }
    break;
case 128:
#line 864 "c-exp.y"
{ yyval.tval = lookup_struct (copy_name (yyvsp[0].sval),
					      expression_context_block); }
    break;
case 129:
#line 867 "c-exp.y"
{ yyval.tval = lookup_union (copy_name (yyvsp[0].sval),
					     expression_context_block); }
    break;
case 130:
#line 870 "c-exp.y"
{ yyval.tval = lookup_enum (copy_name (yyvsp[0].sval),
					    expression_context_block); }
    break;
case 131:
#line 873 "c-exp.y"
{ yyval.tval = lookup_unsigned_typename (TYPE_NAME(yyvsp[0].tsym.type)); }
    break;
case 132:
#line 875 "c-exp.y"
{ yyval.tval = builtin_type_unsigned_int; }
    break;
case 133:
#line 877 "c-exp.y"
{ yyval.tval = lookup_signed_typename (TYPE_NAME(yyvsp[0].tsym.type)); }
    break;
case 134:
#line 879 "c-exp.y"
{ yyval.tval = builtin_type_int; }
    break;
case 135:
#line 884 "c-exp.y"
{ yyval.tval = lookup_template_type(copy_name(yyvsp[-3].sval), yyvsp[-1].tval,
						    expression_context_block);
			}
    break;
case 136:
#line 888 "c-exp.y"
{ yyval.tval = follow_types (yyvsp[0].tval); }
    break;
case 137:
#line 890 "c-exp.y"
{ yyval.tval = follow_types (yyvsp[-1].tval); }
    break;
case 139:
#line 895 "c-exp.y"
{
		  yyval.tsym.stoken.ptr = "int";
		  yyval.tsym.stoken.length = 3;
		  yyval.tsym.type = builtin_type_int;
		}
    break;
case 140:
#line 901 "c-exp.y"
{
		  yyval.tsym.stoken.ptr = "long";
		  yyval.tsym.stoken.length = 4;
		  yyval.tsym.type = builtin_type_long;
		}
    break;
case 141:
#line 907 "c-exp.y"
{
		  yyval.tsym.stoken.ptr = "short";
		  yyval.tsym.stoken.length = 5;
		  yyval.tsym.type = builtin_type_short;
		}
    break;
case 142:
#line 916 "c-exp.y"
{ yyval.tvec = (struct type **) xmalloc (sizeof (struct type *) * 2);
		  yyval.ivec[0] = 1;	/* Number of types in vector */
		  yyval.tvec[1] = yyvsp[0].tval;
		}
    break;
case 143:
#line 921 "c-exp.y"
{ int len = sizeof (struct type *) * (++(yyvsp[-2].ivec[0]) + 1);
		  yyval.tvec = (struct type **) xrealloc ((char *) yyvsp[-2].tvec, len);
		  yyval.tvec[yyval.ivec[0]] = yyvsp[0].tval;
		}
    break;
case 145:
#line 929 "c-exp.y"
{ yyval.tval = follow_types (yyvsp[-3].tval); }
    break;
case 148:
#line 937 "c-exp.y"
{ push_type (tp_const);
			  push_type (tp_volatile); 
			}
    break;
case 149:
#line 941 "c-exp.y"
{ push_type (tp_const); }
    break;
case 150:
#line 943 "c-exp.y"
{ push_type (tp_volatile); }
    break;
case 151:
#line 946 "c-exp.y"
{ yyval.sval = yyvsp[0].ssym.stoken; }
    break;
case 152:
#line 947 "c-exp.y"
{ yyval.sval = yyvsp[0].ssym.stoken; }
    break;
case 153:
#line 948 "c-exp.y"
{ yyval.sval = yyvsp[0].tsym.stoken; }
    break;
case 154:
#line 949 "c-exp.y"
{ yyval.sval = yyvsp[0].ssym.stoken; }
    break;
}

#line 705 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 963 "c-exp.y"


/* Take care of parsing a number (anything that starts with a digit).
   Set yylval and return the token type; update lexptr.
   LEN is the number of characters in it.  */

/*** Needs some error checking for the float case ***/

static int
parse_number (p, len, parsed_float, putithere)
     register char *p;
     register int len;
     int parsed_float;
     YYSTYPE *putithere;
{
  /* FIXME: Shouldn't these be unsigned?  We don't deal with negative values
     here, and we do kind of silly things like cast to unsigned.  */
  register LONGEST n = 0;
  register LONGEST prevn = 0;
  ULONGEST un;

  register int i = 0;
  register int c;
  register int base = input_radix;
  int unsigned_p = 0;

  /* Number of "L" suffixes encountered.  */
  int long_p = 0;

  /* We have found a "L" or "U" suffix.  */
  int found_suffix = 0;

  ULONGEST high_bit;
  struct type *signed_type;
  struct type *unsigned_type;

  if (parsed_float)
    {
      /* It's a float since it contains a point or an exponent.  */
      char c;
      int num = 0;	/* number of tokens scanned by scanf */
      char saved_char = p[len];

      p[len] = 0;	/* null-terminate the token */
      if (sizeof (putithere->typed_val_float.dval) <= sizeof (float))
	num = sscanf (p, "%g%c", (float *) &putithere->typed_val_float.dval,&c);
      else if (sizeof (putithere->typed_val_float.dval) <= sizeof (double))
	num = sscanf (p, "%lg%c", (double *) &putithere->typed_val_float.dval,&c);
      else
	{
#ifdef SCANF_HAS_LONG_DOUBLE
	  num = sscanf (p, "%Lg%c", &putithere->typed_val_float.dval,&c);
#else
	  /* Scan it into a double, then assign it to the long double.
	     This at least wins with values representable in the range
	     of doubles. */
	  double temp;
	  num = sscanf (p, "%lg%c", &temp,&c);
	  putithere->typed_val_float.dval = temp;
#endif
	}
      p[len] = saved_char;	/* restore the input stream */
      if (num != 1) 		/* check scanf found ONLY a float ... */
	return ERROR;
      /* See if it has `f' or `l' suffix (float or long double).  */

      c = tolower (p[len - 1]);

      if (c == 'f')
	putithere->typed_val_float.type = builtin_type_float;
      else if (c == 'l')
	putithere->typed_val_float.type = builtin_type_long_double;
      else if (isdigit (c) || c == '.')
	putithere->typed_val_float.type = builtin_type_double;
      else
	return ERROR;

      return FLOAT;
    }

  /* Handle base-switching prefixes 0x, 0t, 0d, 0 */
  if (p[0] == '0')
    switch (p[1])
      {
      case 'x':
      case 'X':
	if (len >= 3)
	  {
	    p += 2;
	    base = 16;
	    len -= 2;
	  }
	break;

      case 't':
      case 'T':
      case 'd':
      case 'D':
	if (len >= 3)
	  {
	    p += 2;
	    base = 10;
	    len -= 2;
	  }
	break;

      default:
	base = 8;
	break;
      }

  while (len-- > 0)
    {
      c = *p++;
      if (c >= 'A' && c <= 'Z')
	c += 'a' - 'A';
      if (c != 'l' && c != 'u')
	n *= base;
      if (c >= '0' && c <= '9')
	{
	  if (found_suffix)
	    return ERROR;
	  n += i = c - '0';
	}
      else
	{
	  if (base > 10 && c >= 'a' && c <= 'f')
	    {
	      if (found_suffix)
		return ERROR;
	      n += i = c - 'a' + 10;
	    }
	  else if (c == 'l')
	    {
	      ++long_p;
	      found_suffix = 1;
	    }
	  else if (c == 'u')
	    {
	      unsigned_p = 1;
	      found_suffix = 1;
	    }
	  else
	    return ERROR;	/* Char not a digit */
	}
      if (i >= base)
	return ERROR;		/* Invalid digit in this base */

      /* Portably test for overflow (only works for nonzero values, so make
	 a second check for zero).  FIXME: Can't we just make n and prevn
	 unsigned and avoid this?  */
      if (c != 'l' && c != 'u' && (prevn >= n) && n != 0)
	unsigned_p = 1;		/* Try something unsigned */

      /* Portably test for unsigned overflow.
	 FIXME: This check is wrong; for example it doesn't find overflow
	 on 0x123456789 when LONGEST is 32 bits.  */
      if (c != 'l' && c != 'u' && n != 0)
	{	
	  if ((unsigned_p && (ULONGEST) prevn >= (ULONGEST) n))
	    error ("Numeric constant too large.");
	}
      prevn = n;
    }

  /* An integer constant is an int, a long, or a long long.  An L
     suffix forces it to be long; an LL suffix forces it to be long
     long.  If not forced to a larger size, it gets the first type of
     the above that it fits in.  To figure out whether it fits, we
     shift it right and see whether anything remains.  Note that we
     can't shift sizeof (LONGEST) * HOST_CHAR_BIT bits or more in one
     operation, because many compilers will warn about such a shift
     (which always produces a zero result).  Sometimes TARGET_INT_BIT
     or TARGET_LONG_BIT will be that big, sometimes not.  To deal with
     the case where it is we just always shift the value more than
     once, with fewer bits each time.  */

  un = (ULONGEST)n >> 2;
  if (long_p == 0
      && (un >> (TARGET_INT_BIT - 2)) == 0)
    {
      high_bit = ((ULONGEST)1) << (TARGET_INT_BIT-1);

      /* A large decimal (not hex or octal) constant (between INT_MAX
	 and UINT_MAX) is a long or unsigned long, according to ANSI,
	 never an unsigned int, but this code treats it as unsigned
	 int.  This probably should be fixed.  GCC gives a warning on
	 such constants.  */

      unsigned_type = builtin_type_unsigned_int;
      signed_type = builtin_type_int;
    }
  else if (long_p <= 1
	   && (un >> (TARGET_LONG_BIT - 2)) == 0)
    {
      high_bit = ((ULONGEST)1) << (TARGET_LONG_BIT-1);
      unsigned_type = builtin_type_unsigned_long;
      signed_type = builtin_type_long;
    }
  else
    {
      int shift;
      if (sizeof (ULONGEST) * HOST_CHAR_BIT < TARGET_LONG_LONG_BIT)
	/* A long long does not fit in a LONGEST.  */
	shift = (sizeof (ULONGEST) * HOST_CHAR_BIT - 1);
      else
	shift = (TARGET_LONG_LONG_BIT - 1);
      high_bit = (ULONGEST) 1 << shift;
      unsigned_type = builtin_type_unsigned_long_long;
      signed_type = builtin_type_long_long;
    }

   putithere->typed_val_int.val = n;

   /* If the high bit of the worked out type is set then this number
      has to be unsigned. */

   if (unsigned_p || (n & high_bit)) 
     {
       putithere->typed_val_int.type = unsigned_type;
     }
   else 
     {
       putithere->typed_val_int.type = signed_type;
     }

   return INT;
}

struct token
{
  char *operator;
  int token;
  enum exp_opcode opcode;
};

static const struct token tokentab3[] =
  {
    {">>=", ASSIGN_MODIFY, BINOP_RSH},
    {"<<=", ASSIGN_MODIFY, BINOP_LSH}
  };

static const struct token tokentab2[] =
  {
    {"+=", ASSIGN_MODIFY, BINOP_ADD},
    {"-=", ASSIGN_MODIFY, BINOP_SUB},
    {"*=", ASSIGN_MODIFY, BINOP_MUL},
    {"/=", ASSIGN_MODIFY, BINOP_DIV},
    {"%=", ASSIGN_MODIFY, BINOP_REM},
    {"|=", ASSIGN_MODIFY, BINOP_BITWISE_IOR},
    {"&=", ASSIGN_MODIFY, BINOP_BITWISE_AND},
    {"^=", ASSIGN_MODIFY, BINOP_BITWISE_XOR},
    {"++", INCREMENT, BINOP_END},
    {"--", DECREMENT, BINOP_END},
    {"->", ARROW, BINOP_END},
    {"&&", ANDAND, BINOP_END},
    {"||", OROR, BINOP_END},
    {"::", COLONCOLON, BINOP_END},
    {"<<", LSH, BINOP_END},
    {">>", RSH, BINOP_END},
    {"==", EQUAL, BINOP_END},
    {"!=", NOTEQUAL, BINOP_END},
    {"<=", LEQ, BINOP_END},
    {">=", GEQ, BINOP_END}
  };

/* Read one token, getting characters through lexptr.  */

static int
yylex ()
{
  int c;
  int namelen;
  unsigned int i;
  char *tokstart;
  char *tokptr;
  int tempbufindex;
  static char *tempbuf;
  static int tempbufsize;
  struct symbol * sym_class = NULL;
  char * token_string = NULL;
  int class_prefix = 0;
  int unquoted_expr;
   
 retry:

  /* Check if this is a macro invocation that we need to expand.  */
  if (! scanning_macro_expansion ())
    {
      char *expanded = macro_expand_next (&lexptr,
                                          expression_macro_lookup_func,
                                          expression_macro_lookup_baton);

      if (expanded)
        scan_macro_expansion (expanded);
    }

  prev_lexptr = lexptr;
  unquoted_expr = 1;

  tokstart = lexptr;
  /* See if it is a special token of length 3.  */
  for (i = 0; i < sizeof tokentab3 / sizeof tokentab3[0]; i++)
    if (STREQN (tokstart, tokentab3[i].operator, 3))
      {
	lexptr += 3;
	yylval.opcode = tokentab3[i].opcode;
	return tokentab3[i].token;
      }

  /* See if it is a special token of length 2.  */
  for (i = 0; i < sizeof tokentab2 / sizeof tokentab2[0]; i++)
    if (STREQN (tokstart, tokentab2[i].operator, 2))
      {
	lexptr += 2;
	yylval.opcode = tokentab2[i].opcode;
	return tokentab2[i].token;
      }

  switch (c = *tokstart)
    {
    case 0:
      /* If we were just scanning the result of a macro expansion,
         then we need to resume scanning the original text.
         Otherwise, we were already scanning the original text, and
         we're really done.  */
      if (scanning_macro_expansion ())
        {
          finished_macro_expansion ();
          goto retry;
        }
      else
        return 0;

    case ' ':
    case '\t':
    case '\n':
      lexptr++;
      goto retry;

    case '\'':
      /* We either have a character constant ('0' or '\177' for example)
	 or we have a quoted symbol reference ('foo(int,int)' in C++
	 for example). */
      lexptr++;
      c = *lexptr++;
      if (c == '\\')
	c = parse_escape (&lexptr);
      else if (c == '\'')
	error ("Empty character constant.");
      else if (! host_char_to_target (c, &c))
        {
          int toklen = lexptr - tokstart + 1;
          char *tok = alloca (toklen + 1);
          memcpy (tok, tokstart, toklen);
          tok[toklen] = '\0';
          error ("There is no character corresponding to %s in the target "
                 "character set `%s'.", tok, target_charset ());
        }

      yylval.typed_val_int.val = c;
      yylval.typed_val_int.type = builtin_type_char;

      c = *lexptr++;
      if (c != '\'')
	{
	  namelen = skip_quoted (tokstart) - tokstart;
	  if (namelen > 2)
	    {
	      lexptr = tokstart + namelen;
              unquoted_expr = 0;
	      if (lexptr[-1] != '\'')
		error ("Unmatched single quote.");
	      namelen -= 2;
	      tokstart++;
	      goto tryname;
	    }
	  error ("Invalid character constant.");
	}
      return INT;

    case '(':
      paren_depth++;
      lexptr++;
      return c;

    case ')':
      if (paren_depth == 0)
	return 0;
      paren_depth--;
      lexptr++;
      return c;

    case ',':
      if (comma_terminates
          && paren_depth == 0
          && ! scanning_macro_expansion ())
	return 0;
      lexptr++;
      return c;

    case '.':
      /* Might be a floating point number.  */
      if (lexptr[1] < '0' || lexptr[1] > '9')
	goto symbol;		/* Nope, must be a symbol. */
      /* FALL THRU into number case.  */

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      {
	/* It's a number.  */
	int got_dot = 0, got_e = 0, toktype;
	register char *p = tokstart;
	int hex = input_radix > 10;

	if (c == '0' && (p[1] == 'x' || p[1] == 'X'))
	  {
	    p += 2;
	    hex = 1;
	  }
	else if (c == '0' && (p[1]=='t' || p[1]=='T' || p[1]=='d' || p[1]=='D'))
	  {
	    p += 2;
	    hex = 0;
	  }

	for (;; ++p)
	  {
	    /* This test includes !hex because 'e' is a valid hex digit
	       and thus does not indicate a floating point number when
	       the radix is hex.  */
	    if (!hex && !got_e && (*p == 'e' || *p == 'E'))
	      got_dot = got_e = 1;
	    /* This test does not include !hex, because a '.' always indicates
	       a decimal floating point number regardless of the radix.  */
	    else if (!got_dot && *p == '.')
	      got_dot = 1;
	    else if (got_e && (p[-1] == 'e' || p[-1] == 'E')
		     && (*p == '-' || *p == '+'))
	      /* This is the sign of the exponent, not the end of the
		 number.  */
	      continue;
	    /* We will take any letters or digits.  parse_number will
	       complain if past the radix, or if L or U are not final.  */
	    else if ((*p < '0' || *p > '9')
		     && ((*p < 'a' || *p > 'z')
				  && (*p < 'A' || *p > 'Z')))
	      break;
	  }
	toktype = parse_number (tokstart, p - tokstart, got_dot|got_e, &yylval);
        if (toktype == ERROR)
	  {
	    char *err_copy = (char *) alloca (p - tokstart + 1);

	    memcpy (err_copy, tokstart, p - tokstart);
	    err_copy[p - tokstart] = 0;
	    error ("Invalid number \"%s\".", err_copy);
	  }
	lexptr = p;
	return toktype;
      }

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '|':
    case '&':
    case '^':
    case '~':
    case '!':
    case '@':
    case '<':
    case '>':
    case '[':
    case ']':
    case '?':
    case ':':
    case '=':
    case '{':
    case '}':
    symbol:
      lexptr++;
      return c;

    case '"':

      /* Build the gdb internal form of the input string in tempbuf,
	 translating any standard C escape forms seen.  Note that the
	 buffer is null byte terminated *only* for the convenience of
	 debugging gdb itself and printing the buffer contents when
	 the buffer contains no embedded nulls.  Gdb does not depend
	 upon the buffer being null byte terminated, it uses the length
	 string instead.  This allows gdb to handle C strings (as well
	 as strings in other languages) with embedded null bytes */

      tokptr = ++tokstart;
      tempbufindex = 0;

      do {
        char *char_start_pos = tokptr;

	/* Grow the static temp buffer if necessary, including allocating
	   the first one on demand. */
	if (tempbufindex + 1 >= tempbufsize)
	  {
	    tempbuf = (char *) xrealloc (tempbuf, tempbufsize += 64);
	  }
	switch (*tokptr)
	  {
	  case '\0':
	  case '"':
	    /* Do nothing, loop will terminate. */
	    break;
	  case '\\':
	    tokptr++;
	    c = parse_escape (&tokptr);
	    if (c == -1)
	      {
		continue;
	      }
	    tempbuf[tempbufindex++] = c;
	    break;
	  default:
	    c = *tokptr++;
            if (! host_char_to_target (c, &c))
              {
                int len = tokptr - char_start_pos;
                char *copy = alloca (len + 1);
                memcpy (copy, char_start_pos, len);
                copy[len] = '\0';

                error ("There is no character corresponding to `%s' "
                       "in the target character set `%s'.",
                       copy, target_charset ());
              }
            tempbuf[tempbufindex++] = c;
	    break;
	  }
      } while ((*tokptr != '"') && (*tokptr != '\0'));
      if (*tokptr++ != '"')
	{
	  error ("Unterminated string in expression.");
	}
      tempbuf[tempbufindex] = '\0';	/* See note above */
      yylval.sval.ptr = tempbuf;
      yylval.sval.length = tempbufindex;
      lexptr = tokptr;
      return (STRING);
    }

  if (!(c == '_' || c == '$'
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    /* We must have come across a bad character (e.g. ';').  */
    error ("Invalid character '%c' in expression.", c);

  /* It's a name.  See how long it is.  */
  namelen = 0;
  for (c = tokstart[namelen];
       (c == '_' || c == '$' || (c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '<');)
    {
      /* Template parameter lists are part of the name.
	 FIXME: This mishandles `print $a<4&&$a>3'.  */

      if (c == '<')
	{ 
               /* Scan ahead to get rest of the template specification.  Note
                  that we look ahead only when the '<' adjoins non-whitespace
                  characters; for comparison expressions, e.g. "a < b > c",
                  there must be spaces before the '<', etc. */
               
               char * p = find_template_name_end (tokstart + namelen);
               if (p)
                 namelen = p - tokstart;
               break;
	}
      c = tokstart[++namelen];
    }

  /* The token "if" terminates the expression and is NOT removed from
     the input stream.  It doesn't count if it appears in the
     expansion of a macro.  */
  if (namelen == 2
      && tokstart[0] == 'i'
      && tokstart[1] == 'f'
      && ! scanning_macro_expansion ())
    {
      return 0;
    }

  lexptr += namelen;

  tryname:

  /* Catch specific keywords.  Should be done with a data structure.  */
  switch (namelen)
    {
    case 8:
      if (STREQN (tokstart, "unsigned", 8))
	return UNSIGNED;
      if (current_language->la_language == language_cplus
	  && STREQN (tokstart, "template", 8))
	return TEMPLATE;
      if (STREQN (tokstart, "volatile", 8))
	return VOLATILE_KEYWORD;
      break;
    case 6:
      if (STREQN (tokstart, "struct", 6))
	return STRUCT;
      if (STREQN (tokstart, "signed", 6))
	return SIGNED_KEYWORD;
      if (STREQN (tokstart, "sizeof", 6))      
	return SIZEOF;
      if (STREQN (tokstart, "double", 6))      
	return DOUBLE_KEYWORD;
      break;
    case 5:
      if (current_language->la_language == language_cplus)
        {
          if (STREQN (tokstart, "false", 5))
            return FALSEKEYWORD;
          if (STREQN (tokstart, "class", 5))
            return CLASS;
        }
      if (STREQN (tokstart, "union", 5))
	return UNION;
      if (STREQN (tokstart, "short", 5))
	return SHORT;
      if (STREQN (tokstart, "const", 5))
	return CONST_KEYWORD;
      break;
    case 4:
      if (STREQN (tokstart, "enum", 4))
	return ENUM;
      if (STREQN (tokstart, "long", 4))
	return LONG;
      if (current_language->la_language == language_cplus)
          {
            if (STREQN (tokstart, "true", 4))
              return TRUEKEYWORD;
          }
      break;
    case 3:
      if (STREQN (tokstart, "int", 3))
	return INT_KEYWORD;
      break;
    default:
      break;
    }

  yylval.sval.ptr = tokstart;
  yylval.sval.length = namelen;

  if (*tokstart == '$')
    {
      write_dollar_variable (yylval.sval);
      return VARIABLE;
    }
  
  /* Look ahead and see if we can consume more of the input
     string to get a reasonable class/namespace spec or a
     fully-qualified name.  This is a kludge to get around the
     HP aCC compiler's generation of symbol names with embedded
     colons for namespace and nested classes. */ 
  if (unquoted_expr)
    {
      /* Only do it if not inside single quotes */ 
      sym_class = parse_nested_classes_for_hpacc (yylval.sval.ptr, yylval.sval.length,
                                                  &token_string, &class_prefix, &lexptr);
      if (sym_class)
        {
          /* Replace the current token with the bigger one we found */ 
          yylval.sval.ptr = token_string;
          yylval.sval.length = strlen (token_string);
        }
    }
  
  /* Use token-type BLOCKNAME for symbols that happen to be defined as
     functions or symtabs.  If this is not so, then ...
     Use token-type TYPENAME for symbols that happen to be defined
     currently as names of types; NAME for other symbols.
     The caller is not constrained to care about the distinction.  */
  {
    char *tmp = copy_name (yylval.sval);
    struct symbol *sym;
    int is_a_field_of_this = 0;
    int hextype;

    sym = lookup_symbol (tmp, expression_context_block,
			 VAR_DOMAIN,
			 current_language->la_language == language_cplus
			 ? &is_a_field_of_this : (int *) NULL,
			 (struct symtab **) NULL);
    /* Call lookup_symtab, not lookup_partial_symtab, in case there are
       no psymtabs (coff, xcoff, or some future change to blow away the
       psymtabs once once symbols are read).  */
    if (sym && SYMBOL_CLASS (sym) == LOC_BLOCK)
      {
	yylval.ssym.sym = sym;
	yylval.ssym.is_a_field_of_this = is_a_field_of_this;
	return BLOCKNAME;
      }
    else if (!sym)
      {				/* See if it's a file name. */
	struct symtab *symtab;

	symtab = lookup_symtab (tmp);

	if (symtab)
	  {
	    yylval.bval = BLOCKVECTOR_BLOCK (BLOCKVECTOR (symtab), STATIC_BLOCK);
	    return FILENAME;
	  }
      }

    if (sym && SYMBOL_CLASS (sym) == LOC_TYPEDEF)
        {
#if 1
	  /* Despite the following flaw, we need to keep this code enabled.
	     Because we can get called from check_stub_method, if we don't
	     handle nested types then it screws many operations in any
	     program which uses nested types.  */
	  /* In "A::x", if x is a member function of A and there happens
	     to be a type (nested or not, since the stabs don't make that
	     distinction) named x, then this code incorrectly thinks we
	     are dealing with nested types rather than a member function.  */

	  char *p;
	  char *namestart;
	  struct symbol *best_sym;

	  /* Look ahead to detect nested types.  This probably should be
	     done in the grammar, but trying seemed to introduce a lot
	     of shift/reduce and reduce/reduce conflicts.  It's possible
	     that it could be done, though.  Or perhaps a non-grammar, but
	     less ad hoc, approach would work well.  */

	  /* Since we do not currently have any way of distinguishing
	     a nested type from a non-nested one (the stabs don't tell
	     us whether a type is nested), we just ignore the
	     containing type.  */

	  p = lexptr;
	  best_sym = sym;
	  while (1)
	    {
	      /* Skip whitespace.  */
	      while (*p == ' ' || *p == '\t' || *p == '\n')
		++p;
	      if (*p == ':' && p[1] == ':')
		{
		  /* Skip the `::'.  */
		  p += 2;
		  /* Skip whitespace.  */
		  while (*p == ' ' || *p == '\t' || *p == '\n')
		    ++p;
		  namestart = p;
		  while (*p == '_' || *p == '$' || (*p >= '0' && *p <= '9')
			 || (*p >= 'a' && *p <= 'z')
			 || (*p >= 'A' && *p <= 'Z'))
		    ++p;
		  if (p != namestart)
		    {
		      struct symbol *cur_sym;
		      /* As big as the whole rest of the expression, which is
			 at least big enough.  */
		      char *ncopy = alloca (strlen (tmp)+strlen (namestart)+3);
		      char *tmp1;

		      tmp1 = ncopy;
		      memcpy (tmp1, tmp, strlen (tmp));
		      tmp1 += strlen (tmp);
		      memcpy (tmp1, "::", 2);
		      tmp1 += 2;
		      memcpy (tmp1, namestart, p - namestart);
		      tmp1[p - namestart] = '\0';
		      cur_sym = lookup_symbol (ncopy, expression_context_block,
					       VAR_DOMAIN, (int *) NULL,
					       (struct symtab **) NULL);
		      if (cur_sym)
			{
			  if (SYMBOL_CLASS (cur_sym) == LOC_TYPEDEF)
			    {
			      best_sym = cur_sym;
			      lexptr = p;
			    }
			  else
			    break;
			}
		      else
			break;
		    }
		  else
		    break;
		}
	      else
		break;
	    }

	  yylval.tsym.type = SYMBOL_TYPE (best_sym);
#else /* not 0 */
	  yylval.tsym.type = SYMBOL_TYPE (sym);
#endif /* not 0 */
	  return TYPENAME;
        }
    if ((yylval.tsym.type = lookup_primitive_typename (tmp)) != 0)
      return TYPENAME;

    /* Input names that aren't symbols but ARE valid hex numbers,
       when the input radix permits them, can be names or numbers
       depending on the parse.  Note we support radixes > 16 here.  */
    if (!sym && 
        ((tokstart[0] >= 'a' && tokstart[0] < 'a' + input_radix - 10) ||
         (tokstart[0] >= 'A' && tokstart[0] < 'A' + input_radix - 10)))
      {
 	YYSTYPE newlval;	/* Its value is ignored.  */
	hextype = parse_number (tokstart, namelen, 0, &newlval);
	if (hextype == INT)
	  {
	    yylval.ssym.sym = sym;
	    yylval.ssym.is_a_field_of_this = is_a_field_of_this;
	    return NAME_OR_INT;
	  }
      }

    /* Any other kind of symbol */
    yylval.ssym.sym = sym;
    yylval.ssym.is_a_field_of_this = is_a_field_of_this;
    return NAME;
  }
}

void
yyerror (msg)
     char *msg;
{
  if (prev_lexptr)
    lexptr = prev_lexptr;

  error ("A %s in expression, near `%s'.", (msg ? msg : "error"), lexptr);
}
