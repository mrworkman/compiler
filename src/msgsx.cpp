/**
 * Implementation of the
 * $(LINK2 http://www.digitalmars.com/download/freecompiler.html, Digital Mars C/C++ Compiler).
 *
 * Copyright:   Copyright (c) 1983-1998 by Symantec, All Rights Reserved
 *              Copyright (c) 2000-2017 by Digital Mars, All Rights Reserved
 * Authors:     $(LINK2 http://www.digitalmars.com, Walter Bright)
 * License:     Distributed under the Boost Software License, Version 1.0.
 *              http://www.boost.org/LICENSE_1_0.txt
 * Source:      https://github.com/DigitalMars/Compiler/blob/master/dm/src/dmc/msgsx.c
 */

// Generate msgs2.d, msgs2.h and msgs2.c
// This file pulls together all the various message files into one, which
// when compiled and run, generates the tables used by the compiler.
// Currently it puts all languages into one table, but it can be changed
// to generate binary files for different files loaded at runtime.

// Compile with -DSPP (preprocessor), -DSCPP (C/C++ compiler), -DHTOD (.h to .d converter)

struct Msgtable
{
        const char *name;       // handle for compiler
        const char *msg;        // default english message

        // Foreign language translations
        // NULL translations will be done in english
        const char *german;     // optional german message
        const char *french;     // optional french message
        const char *japanese;   // optional japanese message
};

struct Msgtable msgtable[] =
{
  { "usage",
#if SPP
"Use:\n\
        SPP sourcefile [-ooutput] { switches }\n\
-A  strict ANSI                         -D[macro[=text]] define macro\n\
-EC leave comments in                   -EL omit #line directives\n\
-Ipath  #include search path            -j[0|1|2] Asian language characters\n\
-J  chars default to unsigned\n\
-m  memory model\n\
-o  output file name (.i)\n\
-u  suppress predefined macros          -v  verbose compile\n\
-w[n]  suppress warning n               -x  turn off error maximum",

"Syntax:\n\
        SPP quelldatei [-oausgabe] { schalter }\n\
-A  Strikt nach ANSI                    -D[macro[=text]] Makro definieren\n\
-EC Kommentare beibehalten              -EL #line-Anweisungen �bergehen\n\
-Ipfad  Suchpfad f�r #include           -j[0|1|2] Asiatische Zeichens�tze\n\
-J  Zeichen standardm��ig 'unsigned'\n\
-m  Speichermodell\n\
-o  Name der Ausgabedatei (.i)\n\
-u  Vordefinierte Makros unterdr�cken   -v  Ausf�hrliche Meldungen\n\
-w[n]  Warnung n unterdr�cken           -x  Fehlermaximum abschalten",

"Usage:\n\
        fichier source SPP [-osortie] { commutateurs }\n\
-A  ANSI pur\n\
-D[macro[=texte]] d�finition d'une macro\n\
-EC conserver les commentaires\n\
-EL omettre directives #line \n\
-Ichemin  #include chemin de recherche\n\
-j[0|1|2] alphabets asiatiques \n\
-J  caract�res non sign�s par d�faut \n\
-m  mod�le de m�moire\n\
-o  nom du fichier de sortie (.i)\n\
-u  suppression macros pr�d�finies\n\
-v  compilation compl�te\n\
-w[n]  suppression des avertissements n\n\
-x  d�sactivation erreurs",

//#pragma dbcs(push,1)
//"�`��:\n\
//        SPP ���� [-o�o��] {-D[�}�N��[=�l]]}\n\
//            [-m(smclv)] {-(AjJuvwx)} {-I�p�X}\n\
//����    �\�[�X�t�@�C����\n\
//-A  ����ANSI (�g���L�[���[�h�Ȃ�)       -D  �}�N����`\n\
//-I  #include�����p�X                    -j  2�o�C�g����\n\
//-J  �����Ȃ���char\n\
//-ms  �R�[�h�A�f�[�^�����X���[��         -mm  �R�[�h=���[�W�A�f�[�^=�X���[��\n\
//-mc  �R�[�h=�X���[���A�f�[�^=���[�W     -ml  �R�[�h�A�f�[�^�������[�W\n\
//-mv  vcm���f��\n\
//-o  �o�̓t�@�C����(.i)\n\
//-u  ����`�}�N�����`���Ȃ�            -v  �ڍ׏��o��\n\
//-w[n]  �x��n�𔭍s���Ȃ�                -x  �ő�G���[���𖳌��ɂ���",
//#pragma dbcs(pop)
#else
        "C/C++ Compiler",                                               // 0
        0,
        "Compilateur C/C++",                                    // 0
#endif
  },
  { "bad_parameter",
        "unrecognized parameter '%s'",                  /*  1 C */
        "Unbekannter Parameter '%s'",                   /*  1 C */
        "param�tre '%s' non reconnu",                   /*  1 C */
//        #pragma dbcs(push,1)
//        "�s���p�����[�^ '%s'",                          /*  1 C */
//        #pragma dbcs(pop)
  },
  { "eof",
        "premature end of source file",                 /*  2   */
        "Vorzeitiges Ende der Quelldatei",              /*  2   */
        "fin inattendue du fichier source",             /*  2   */
        //#pragma dbcs(push,1)
        //"�\�[�X�t�@�C���̏I��ɒB����",                 /*  2   */
        //#pragma dbcs(pop)
        "\x83\x5c\x81\x5b\x83\x58\x83\x74\x83\x40\x83\x43\x83\x8b\x82\xcc\x8f\x49\x82\xe8\x82\xc9\x92\x42\x82\xb5\x82\xbd",

  },
  { "num2big",
        "number %s is too large",                       /*  3   */
        "Zahl %s ist zu gro�",                          /*  3   */
        "nombre %s trop �lev�",                         /*  3   */
//        #pragma dbcs(push,1)
//        "���l %s ���傫������",                         /*  3   */
//        #pragma dbcs(pop)
  },
  { "string2big",
        "max of %u characters in string exceeded",              /*  4   */
        "Max. Anz. von %u Zeichen im String �berschritten",     /*  4   */
        "la longueur de la cha�ne d�passe %u caract�res",       /*  4   */
        "������̕���������������",                             /*  4   */
  },
  { "ident2big",
        "identifier is longer than 254 chars",          /*  5   */
        "Bezeichner l�nger als 254 Zeichen",            /*  5   */
        "la longueur de l'identificateur d�passe 254 caract�res", /*  5 */
        "���ʎq�̕������� 254 �ȏ�",                    /*  5   */
  },
        // Could be caused by extra U or L integer suffixes
  { "badtoken",
        "unrecognized token",                           /*  6 L */
        "Unbekanntes Token",                            /*  6 L */
        "t�moin non reconnu",                           /*  6 L */
        "�s���ȃg�[�N��",                               /*  6 L */
  },
  { "hexdigit",
        "'%c' is not a hex digit",                      /*  8   */
        "Hex-Ziffer erwartet",                          /*  8   */
        "chiffre hexad�cimal requis",                   /*  8   */
        "16�i�̐����łȂ���΂Ȃ�Ȃ�",                 /*  8   */
  },
  // Disallowed universal character name per C99 6.4.3 or C++98 2.2.
  // Also, under Win32, values larger than 0xFFFF are not representable.
  { "disallowed_char_name",
        "disallowed universal character name \\\\U%08X",
  },
  { "not_universal_idchar",
        "\\\\U%08X is not a universal identifier character",
  },

        /* For integers, this means that the value exceeded ULONG_MAX.
           For real numbers, this means that the value overflowed
           or underflowed, in other words, it cannot be represented.
           For enums, this means it exceeds INT_MAX.
           For octal character constants, this means it cannot be
           represented in 8 bits.
         */
  { "badnumber",
        "number is not representable",                  /*  9   */
        "Zahl nicht darstellbar",                       /*  9   */
        "impossible de repr�senter ce nombre",          /*  9   */
        //#pragma dbcs(push,1)
        //"���l��\���ł��Ȃ�",                           /*  9   */
        //#pragma dbcs(pop)
        "\x90\x94\x92\x6c\x82\xf0\x95\x5c\x8c\xbb\x82\xc5\x82\xab\x82\xc8\x82\xa2",
  },
  { "exponent",
        "exponent expected",                            /* 10   */
        "Exponent erwartet",                            /* 10   */
        "exposant requis",                              /* 10   */
        "�w���łȂ���΂Ȃ�Ȃ�",                       /* 10   */
  },
  { "nosource",
        "no input file specified",                      /* 11 C */
        "Keine Eingabedatei angegeben",                 /* 11 C */
        "fichier d'entr�e non sp�cifi�",                /* 11 C */
        "���̓t�@�C���̎w�肪�Ȃ�",                     /* 11 C */
  },
  { "dashD",
        "bad -D switch, %s",                            /* 13 C */
        "Ung�ltiger Schalter f�r -D, %s",               /* 13 C */
        "commutateur -D %s incorrect",                  /* 13 C */
        "�s�� -D �X�C�b�`: %s",                         /* 13 C */
  },
  { "error",
        "Error: ",                                      /* 14   */
        "Fehler: ",                                     /* 14   */
        "Erreur : ",                                    /* 14   */
        "�G���[: ",                                     /* 14   */
  },
  { "unknown_pragma",
        "unrecognized pragma",                          /* 16   */
        "Unbekanntes Pragma",                           /* 16   */
        "pragma non reconnu",                           /* 16   */
        "�s���v���O�}",                                 /* 16   */
  },
  { "bad_char",
        "illegal character, ascii %u decimal",          /* 17   */
        "Unzul�ssiges Zeichen, ASCII %u dezimal",       /* 17   */
        "caract�re non autoris�, ascii %u en d�cimal",  /* 17   */
        "�s������: ascii %u (10�i)",                    /* 17   */
  },
  { "rpar",
        "')' expected",                                 /* 18   */
        "')' erwartet",                                 /* 18   */
        "')' requis",                                   /* 18   */
        "')' �łȂ���΂Ȃ�Ȃ�",                       /* 18   */
  },
  { "param_rpar",
        "')' expected to close function parameter list with",
        "')' erwartet",
        "')' requis",
        "')' �łȂ���΂Ȃ�Ȃ�",
  },
  { "arg_ellipsis",
        "macro argument list arg... form is obsolete",
  },
  { "ident_exp",
        "identifier expected",                          /* 20   */
        "Bezeichner erwartet",                          /* 20   */
        "identificateur requis",                        /* 20   */
        "���ʎq�łȂ���΂Ȃ�Ȃ�",                     /* 20   */
  },
  { "preprocess",
        "unrecognized preprocessing directive",         /* 21   */
        "Unbekannte Pr�prozessoranweisung '#%s'",       /* 21   */
        "instruction pr�processeur '#%s' non reconnue", /* 21   */
        "�s���v���v���Z�b�T�w�� '#%s'",                 /* 21   */
  },
  { "memmodels",
        "valid memory models are -m[tsmcrzlvfnpx]",     /* 22 C */
        "G�ltige Speichermodelle sind -m[tsmcrzlvfnpx]", /* 22 C */
        "les mod�les de m�moire autoris�s sont -m[tsmcrzlvfnpx]",       /* 22 C */
        "���������f���� -ms�A-mm�A-mc�A-ml �̂����ꂩ",  /* 22 C */
  },
  { "eol",
        "end of line expected",                         /* 23 P */
        "Zeilenende erwartet",                          /* 23 P */
        "fin de ligne requise",                         /* 23 P */
        "�s���łȂ���΂Ȃ�Ȃ�",                       /* 23 P */
  },
  { "num",
        "integer constant expression expected",         /* 24   */
        "Konstanter Integer-Ausdruck erwartet",         /* 24   */
        "expression de constante enti�re requise",      /* 24   */
        "�����̒萔���łȂ���΂Ȃ�Ȃ�",               /* 24   */
  },
  { "linnum",
        "line number expected",                         /* 25 P */
        "Zeilennummer erwartet",                        /* 25 P */
        "num�ro de ligne requis",                       /* 25 P */
        "�s�ԍ��łȂ���΂Ȃ�Ȃ�",                     /* 25 P */
  },
  { "2manyerrors",
        "too many errors",                              /* 27   */
        "Zu viele Fehler",                              /* 27   */
        "trop d'erreurs",                               /* 27   */
        "�G���[����������",                             /* 27   */
  },
  { "num_args",
        "%d actual arguments expected for %s, had %d",          /* 29   */
        "%d Argumente f�r %s erwartet, %d erhalten",            /* 29   */
        "%d arguments effectifs requis pour %s, %d fournis",    /* 29   */
        "%d �̈����łȂ���΂Ȃ�Ȃ� (%s)",                   /* 29   */
  },
  { "filespec",
        "filespec string expected",                     /* 30   */
        "String f�r Dateispezifikation erwartet",       /* 30   */
        "cha�ne d'identification de fichier requise",   /* 30   */
        "�t�@�C�����łȂ���΂Ȃ�Ȃ�",                 /* 30   */
  },
  { "endif",
        "'#endif' found without '#if'",                 /* 31 P */
        "'#endif' ohne '#if'",                          /* 31 P */
        "'#endif' d�tect� sans '#if'",                  /* 31 P */
        "'#if' ���Ȃ��̂� '#endif' ��������",           /* 31 P */
  },
  { "eof_endif",
        "end of file found before '#endif'",                    /* 32 P */
        "Dateiende vor '#endif'",                               /* 32 P */
        "fin de fichier d�tect�e avant '#endif'",               /* 32 P */
        "'#endif' ��������Ȃ��ԂɃt�@�C���̏I��ɒB����",    /* 32 P */
  },
  { "else",
        "'#else' or '#elif' found without '#if'",       /* 33 P */
        "'#else' oder '#elif' ohne '#if'",              /* 33 P */
        "''#else' ou '#elif' d�tect� sans '#if'",       /* 33 P */
        "'#if' ���Ȃ��̂� '#else' �� '#elif' ��������", /* 33 P */
  },
        // Probably missing closing quote or )
  { "macarg",
        "unterminated macro argument",                  // 34 P
        "Nicht abgeschlossenes Makroargument",          // 34 P
        "argument de macro incomplet",                  // 34 P
        "�}�N���������I�����Ă��Ȃ�",                   // 34 P
  },
  { "align",
        // Alignment for struct members must be 1,2,4,8, etc.
        "alignment must be a power of 2",                       /* 35 P,C */
        "Ausrichtung mu� eine Potenz von 2 sein",               /* 35 P,C */
        "l'alignement doit �tre une puissance de 2",            /* 35 P,C */
        "�A���C�������g�̎w���2�̙p��łȂ���΂Ȃ�Ȃ�",      // 35 P,C
  },
        // ANSI C 3.8.8
  { "undef",
        "macro '%s' can't be #undef'd or #define'd",                    /* 36 P */
        "'#undef' oder '#define' nicht anwendbar auf Makro '%s'",       /* 36 P */
        "impossible d'appliquer #undef ou #define � la macro '%s'",     /* 36 P */
        "�}�N�� '%s' �� #undef �܂��� #define �ł��Ȃ�",                /* 36 P */
  },
  { "rbra",
        "']' expected",                                 /* 38 S */
        "']' erwartet",                                 /* 38 S */
        "']' requis",                                   /* 38 S */
        "']' �łȂ���΂Ȃ�Ȃ�",                       /* 38 S */
  },
  { "punctuation",
        "'=', ';' or ',' expected",                     /* 46 S */
        "'=', ';' oder ',' erwartet",                   /* 46 S */
        "'=', ';' ou ',' requis",                       /* 46 S */
        "'='�A';'�A�܂��� ',' �łȂ���΂Ȃ�Ȃ�",      /* 46 S */
  },

  { "multiple_def",
        "'%s' is already defined",                      /* 48 S,P */
        "'%s' ist bereits definiert",                   /* 48 S,P */
        "'%s' est d�j� d�fini",                         /* 48 S,P */
        "'%s' �͊��ɒ�`����Ă���",                    /* 48 S,P */
  },
  { "redefined",
        "'%s' previously declared as something else",   /* 81 S */
        "'%s' wurde vorher bereits anders deklariert",  /* 81 S */
        "'%s' d�j� d�clar� de mani�re diff�rente",      /* 81 S */
        "'%s' �͊��ɕʂɐ錾����Ă���",                /* 81 S */
  },
  { "undefined",
        "undefined identifier '%s'",                    /* 49 S */
        "Undefinierter Bezeichner '%s'",                /* 49 S */
        "identificateur '%s' non d�fini",               /* 49 S */
        "���莯�ʎq '%s'",                              /* 49 S */
  },
  { "undefined2",
        "undefined identifier '%s', did you mean '%s'?",                        /* 49 S */
  },
  { "rcur",
        "'}' expected",                                 /* 55 S */
        "'}' erwartet",                                 /* 55 S */
        "'}' requis",                                   /* 55 S */
        "'}' �łȂ���΂Ȃ�Ȃ�",                       /* 55 S */
  },
  { "response_file",
        "can't open response file",                     /* 57 S */
        "Antwortdatei kann nicht ge�ffnet werden",      /* 57 S */
        "ouverture du fichier de r�ponse impossible",   /* 57 S */
        "���X�|���X�t�@�C�����J���Ȃ�",                 /* 57 S */
  },
  { "pragma_proto",
        "pragma parameter function prototype not found",/* 57 S */
        "Prototyp f�r Pragma-Parameterfunktion nicht gefunden",/* 57 S */
        "prototype de fonction du param�tre pragma introuvable",/* 57 S */
  },
  { "lcur_exp",
        "'{' expected",                                 /* 58 S } */
        "'{' erwartet",                                 /* 58 S } */
        "'{' requis",                                   /* 58 S } */
        "'{' �łȂ���΂Ȃ�Ȃ�",                       /* 58 S } */
  },
  { "colon",
        "':' expected",                                 /* 62 S */
        "':' erwartet",                                 /* 62 S */
        "':' requis",                                   /* 62 S */
        "':' �łȂ���΂Ȃ�Ȃ�",                       /* 62 S */
  },
  { "exp",
        "expression expected",                          /* 63 S */
        "Ausdruck erwartet",                                    /* 63 S */
        "expression requise",                           /* 63 S */
        "���łȂ���΂Ȃ�Ȃ�",                         /* 63 S */
  },
  { "lpar",
        "'(' expected",                                 /* 66 S */
        "'(' erwartet",                                 /* 66 S */
        "'(' requis",                                   /* 66 S */
        "'(' �łȂ���΂Ȃ�Ȃ�",                       /* 66 S */
  },
  { "lpar2",
        "'(' expected following %s",
        "'(' erwartet",
        "'(' requis",
        "'(' �łȂ���΂Ȃ�Ȃ�",
  },
  { "illegal_op_types",
        "illegal operand types",                        /* 83 S */
        "Unzul�ssiger Operandentyp",                            /* 83 S */
        "types d'op�randes non valides",                        /* 83 S */
        "�s���I�y�����h�^",                             /* 83 S */
  },
  { "open_input",
        "unable to open input file '%s'",               /* 84 S */
        "Eingabedatei '%s' kann nicht ge�ffnet werden", /* 84 S */
        "impossible d'ouvrir le fichier d'entr�e '%s'",         /* 84 S */
        "���̓t�@�C�� '%s' ���J���Ȃ�",                 /* 84 S */
  },
  { "open_output",
        "unable to open output file '%s'",              /* 85 S */
        "Ausgabedatei '%s' kann nicht ge�ffnet werden", /* 85 S */
        "impossible d'ouvrir le fichier de sortie '%s'",                /* 85 S */
        "�o�̓t�@�C�� '%s' ���J���Ȃ�",                 /* 85 S */
  },

        // Attempt to divide by 0 when constant folding.
        // For instance:
        //      int x = 5 / 0;
  { "divby0",
        "divide by 0",                                  /* 86 S */
        "Division durch 0",                                     /* 86 S */
        "division par z�ro",                                    /* 86 S */
        "�[�����Z",                                     /* 86 S */
  },
  { "bad_filespec",
        "can't build filespec '%s'",                    /* 88 S */
        "Dateispezifikation '%s' kann nicht erstellt werden",                   /* 88 S */
        "impossible de g�n�rer la sp�cification de fichier '%S'",                       /* 88 S */
        "�p�X '%s' ���s��",                             /* 88 S */
  },
        // Input and output files have the same name
  { "mult_files",
        "duplicate file names '%s'",                    /* 89 S */
        "Doppelter Dateiname: '%s'",                    /* 89 S */
        "nom de fichier '%s' en double",                        /* 89 S */
        "�d���t�@�C���� '%s'",                          /* 89 S */
  },
  { "bad_filename",
        "bad file name '%s'",                           /* 90 S */
        "Ung�ltiger Dateiname: '%s'",                           /* 90 S */
        "nom de fichier '%s' incorrect",                                /* 90 S */
        "�s���t�@�C���� '%s'",                          /* 90 S */
  },

        /* Comments do not nest in C. You cannot 'comment out' a block
           of code containing C comments with a C comment. The correct
           way to remove a block of code is to use a #if 0 ... #endif block.
           Also, this warning will appear if you 'forget' to terminate
           a comment (the warning appears at the start of the next comment).
         */
  { "nestcomment",
        "comments do not nest",                         /* 91 W */
        "Kommentare k�nnen nicht verschachtelt werden",                         /* 91 W */
        "imbrication des commentaires interdite",                               /* 91 W */
        "�R�����g�̓l�X�g�ł��Ȃ�",                     /* 91 W */
  },
  { "string",
        "string expected",                                      /* 92 P */
        "String erwartet",                                      /* 92 P */
        "cha�ne requise",                                       /* 92 P */
        "������łȂ���΂Ȃ�Ȃ�",                     /* 92 P */
  },
#if 0 // obsoleted by C99
  { "blank_arg",
        "blank arguments are illegal",                  /* 93 P */
        "Leere Argumente nicht zul�ssig",                       /* 93 P */
        "arguments vides non autoris�s",                        /* 93 P */
        "�󂫂̈����͎g���Ȃ�",                         /* 93 P */
  },
#endif
  { "integral",
        "integral expression expected",                 /* 94 S */
        "Integraler Ausdruck erwartet",                 /* 94 S */
        "expression int�grale requise",                 /* 94 S */
        "�������łȂ���΂Ȃ�Ȃ�",                     /* 94 S */
  },
        /* Happens when a ; immediately follows an if, for, while as in:
                if (x);
           which is a common and hard-to-spot error. To suppress put
           whitespace between the ) and the ;, as in:
                if (x)
                    ;
         */
  { "extra_semi",
        "possible extraneous ';'",                      /* 98 W */
        "M�glicherweise �berfl�ssiges ';'",             /* 98 W */
        "pr�sence possible de ';' superflu",            /* 98 W */
        //#pragma dbcs(push,1)
        //"';' ����������\��������",                 /* 98 W */
        //#pragma dbcs(pop)
        "\x27\x3b\x27\x20\x82\xaa\x91\xbd\x82\xb7\x82\xac\x82\xe9\x89\xc2\x94\x5c\x90\xab\x82\xaa\x82\xa0\x82\xe9",
  },
  { "lvalue",
        "lvalue expected",                              /* 101 S */
        "lvalue erwartet",                              /* 101 S */
        "lvalue requise",                               /* 101 S */
        "���Ӓl�łȂ���΂Ȃ�Ȃ�",                     /* 101 S */
  },

        /* Occurs in instances like:
                a == b;
                (short)func();
           where a value is computed, but is thrown away.
           To suppress the warning, cast to void:
                (void)(a == b);
                (void)(short)func();
         */
  { "valuenotused",
        "value of expression is not used",              /* 102 W */
        "Wert des Ausdrucks wird nicht benutzt",        /* 102 W */
        "valeur de l'expression inutilis�e",            /* 102 W */
        "���̒l���g���Ă��Ȃ�",                       /* 102 W */
  },
        /* ANSI C 3.1.3.4
           Found end of file or end of line before end of string.
         */
  { "noendofstring",
        "unterminated string",                          /* 104   */
        "Nicht abgeschlossener String",                 /* 104   */
        "cha�ne non termin�e",                          /* 104   */
        "�����񂪏I�����Ă��Ȃ�",                       /* 104   */
  },
        // Probably out of disk space
  { "write_error",
        "error writing output file '%s'",                       // 107F
        "Fehler beim Schreiben der Ausgabedatei",               /* 107F */
        "erreur d'�criture dans le fichier de sortie",                  /* 107F */
        "�o�̓t�@�C���������݃G���[",                   /* 107F */
  },
  { "octal_digit",
        "octal digit expected",                         /* 108L */
        "Oktalziffer erwartet",                         /* 108L */
        "chiffre octal requis",                         /* 108L */
        "8�i�̐����łȂ���΂Ȃ�Ȃ�",                  /* 108L */
  },
  { "const_assign",
        "can't assign to const variable %s",            /* 109S */
        "Zuweisung zu Const-Variable nicht m�glich",
        "affectation � une variable constante impossible",
        "const�ϐ��ւ̑�����ł��Ȃ�",
  },
  { "null_nl",
        "%s",                                           /* 110E */
  },

        /* The compiler has run out of memory. Try compiling with
           the -bx, -b and -br switches (usually in that order).
         */
  { "nomem",
        "out of memory",                                /* 111  */
        "Nicht gen�gend Speicher",                              /* 111  */
        "m�moire satur�e",                              /* 111  */
        "�������s��",                                   /* 111  */
  },
  { "command_line_error",
        "Command line error: ",                         /* 112  */
        "Fehler in der Befehlszeile: ",                 /* 112  */
        "erreur de ligne de commande :",                                /* 112  */
        "�R�}���h���C���G���[: ",                       /* 112  */
  },
  { "no_comment_term",
        "end of file found before end of comment, line %d",     /* 115  */
        "Dateiende vor Kommentarende, Zeile %d",        /* 115  */
        "fin de fichier d�tect� avant la fin du commentaire � la ligne %d",     /* 115  */
        "�R�����g���Ƀt�@�C���̏I��ɒB������ (�s�ԍ� %d)",     /* 115  */
  },
  { "warning",
        "Warning %d: ",                                 /* 116  */
        "Warnung %d: ",                                 /* 116  */
        "Avertissement %d :",                                   /* 116  */
        "�x�� %d: ",                                    /* 116  */
  },
  { "lexical_error",
        "Lexical error: ",                              /* 117  */
        "Lexikalischer Fehler: ",                               /* 117  */
        "Erreur de lexique :",                          /* 117  */
        "���G���[: ",                                 /* 117  */
  },
  { "preprocessor_error",
        "Preprocessor error: ",                         /* 118  */
        "Pr�prozessorfehler: ",                         /* 118  */
        "Erreur du pr�processeur :",                            /* 118  */
        "�v���v���Z�b�T�G���[: ",                       /* 118  */
  },

        // This line controls the format for how errors are reported
  { "line_format",
        "%s(%d) : ",                                    /* 119  */
  },
  { "0or1",
        "0 or 1 expected",                              /* 122L */
        "0 oder 1 erwartet",                            /* 122L */
        "0 ou 1 requis",                                /* 122L */
        "0 �܂��� 1 �łȂ���΂Ȃ�Ȃ�",                /* 122L */
  },

        /* Last line in source file must end in a \n without an         */
        /* immediately preceding backslash.                             */
  { "no_nl",
        "last line in file had no \\\\n",                       /* 126L */
        "Letzte Zeile der Datei hat kein \\\\n",        /* 126L */
        "\\\\n manquant sur la derni�re ligne du fichier",      /* 126L */
        "�t�@�C���̍ŏI�s�� \\\\n ���Ȃ�",              /* 126L */
  },

  { "prep_exp",
        "casts and sizeof are illegal in preprocessor expressions", /* 131 */
        "Casts und Sizeof unzul�ssig in Pr�prozessorausdr�cken", /* 131 */
        "cast et sizeof interdits dans les expressions du preprocesseur", /* 131 */
        "�v���v���Z�b�T���ɂ̓L���X�g����� sizeof �͎g���Ȃ�", /* 131 */
  },
        /* ANSI escape sequences are: \' \" \? \\
           \a \b \f \n \r \t \v \x hex-digit \octal-digit
         */
  { "bad_escape_seq",
        "undefined escape sequence",                    /* 133L */
        "Nicht definierte Escape-Sequenz",                      /* 133L */
        "s�quence d'�chappement inconnue",                      /* 133L */
        "����`�G�X�P�[�v�V�P���X",                     /* 133L */
  },
  { "binary_exp",
        "binary exponent part required for hex floating constants", /* 134L */
        "Bin�rer Exponentteil erforderlich f�r hex. Float-Konstanten", /* 134L */
        "exposant binaire obligatoire pour les constantes hexad�cimales � virgule flottante", /* 134L */
        "16�i�̕��������_���ɂ͎w�������K�v",           /* 134L */
  },
  { "cseg_global",
        "pragma cseg must be at global scope",          /* 136  */
        "Pragma Cseg mu� global g�ltig sein",           /* 136  */
        "pragma cseg doit �tre de visibilit� globale",          /* 136  */
        "pragma cseg �̓O���[�o���X�R�[�v�ŋL�q���Ȃ���΂Ȃ�Ȃ�",     /* 136  */
  },

        /* ANSI 3.8.3.3 */
  { "hashhash_end",
        "## cannot appear at beginning or end",         /* 142P */
        "## darf nicht am Anfang oder Ende stehen",             /* 142P */
        "## interdit au d�but et � la fin",             /* 142P */
        "## �͕�����̊ԂłȂ���΂Ȃ�Ȃ�",                    /* 142P */
  },
        /* ANSI 3.8.3.2 */
  { "hashparam",
        "# must be followed by a parameter",            /* 143P */
        "# mu� von einem Parameter gefolgt werden",             /* 143P */
        "# doit �tre suivi d'un param�tre",             /* 143P */
        "# �ɂ̓p�����[�^�������Ȃ���΂Ȃ�Ȃ�",               /* 143P */
  },
        /* ANSI 3.4     */
  { "comma_const",
        "comma not allowed in constant expression",             /* 147S */
        "Komma nicht zul�ssig in konstantem Ausdruck",          /* 147S */
        "les virgules ne sont pas autoris�es dans les exptessions constantes",  /* 147S */
        "�萔���ɂ̓R���}���g���Ă͂Ȃ�Ȃ�",           /* 147S */
  },

        // Compiler bug: report to Digital Mars
  { "internal_error",
        "internal error %s %d",                         // 168
        "Interner Fehler %s %d",                                // 168
        "erreur interne %s%d",                          // 168
        "�����G���[: %s %d",                            // 168
  },

        // Exceeded maximum length of macro replacement text.
        // (%s is replaced by "macro text")
  { "max_macro_text",
        "maximum %s length of %u exceeded",             // 169
        "Max. %s-L�nge von %u �berschritten",           // 169
        "la longueur de %s d�passe la limite de %u",            // 169
        "�ő�̒��� %u ���z���Ă���",                   // 169
  },

        // The compiler does not support macros with more than
        // 251 parameters.
  { "max_macro_params",
        "%u exceeds maximum of %u macro parameters",    // 171
        "%u �bersteigt die max. Anz. von %u Makroparametern",   // 171
        "%u d�passe le nombre maximal de %u param�tres de macro",       // 171
        "%u �͍ő�}�N���p�����[�^���� %u ���z���Ă���",// 171
  },

  { "null",
        "",                                             // 174
  },
        // Probably had syntax like:
        //      int x y;
        // where x was supposed to be a macro.
  { "missing_comma",
        "missing ',' between declaration of '%s' and '%s'",     // 176S
        "',' fehlt zwischen Deklaration von '%s' und '%s'",     // 176S
        "virgule manquante entre '%s' et sa d�claration",       // 176S
  },

        // Parameters are separated by commas.
  { "comma",
        "',' expected",                                         // 178S
        "',' erwartet",                                         // 178S
        "',' requis",                                           // 178S
  },
  { "pop_wo_push",
        "#pragma pack(pop) does not have corresponding push",   // 179P
        "#pragma pack(pop) hat kein entsprechendes push",       // 179P
        "#pragma pack(pop) sans push correspondant",    // 179P
  },
  { "pascal_str_2long",
        "pascal string length %u is longer than 255",           // 180L
        "Pascal-Stringl�nge %u ist gr��er als 255",             // 180L
        "longueur de la cha�ne pascal %u sup�rieure � 255",             // 180L
  },
  { "fatal_error",
        "Fatal error: ",                                        // 184
        "Schwerer Fehler: ",                                    // 184
        "Erreur fatale :",                                      // 184
  },
        // Either the file cannot be opened for reading or
        // the virtual memory address is not available
  { "cant_map_file",
        "cannot map file '%s' at %p",                   // 187
        "Umsetzung der Datei '%s' an %p nicht m�glich",                 // 187
        "impossible d'acc�der au fichier '%s' � %p",                    // 187
  },

        // There is insufficient virtual memory at that address
  { "cant_reserve_mem",
        "cannot reserve memory at %p",                  // 188
        "Speicher an %p kann nicht reserviert werden",                  // 188
        "impossible de r�server de la m�moire � %p",                    // 188
  },

        // There is a maximum on the number of #include files
        // used in precompiled headers.
  { "2manyfiles",
        "max of %d include files exceeded",                     // 190
  },

  { "nolocale",
        "locale \"%s\" not supported by operating system",      // 195
  },

        // 64 bit ints are only supported for 32 bit memory models.
        // The long long data type is not ANSI standard.
  { "no_longlong",
        "long long not supported for ANSI or 16 bit compiles",  // 167S
        "Long Long nicht unterst�tzt bei ANSI- oder 16-Bit-Kompilierung",       // 167S
        "long long incompatible avec la compilation ANSI ou 16 bits",   // 167S
  },

  { "no_complex",
        "complex and imaginary types not supported for this memory model",
  },

        // C99 6.7.5.2-2
  { "no_vla",
        "variable length arrays are only for function prototypes and autos",
  },

   /* C++0x A.2 "any member of the basic source character set except:
    * space, the left parenthesis (, the right parenthesis ), the backslash \,
    * and the control characters representing horizontal tab,
    * vertical tab, form feed, and newline."
    */
   { "invalid_dchar",
        "valid d-char's are ASCII except for ( ) space \\\\ \\\\t \\\\v \\\\f \\\\n, not x%02x",
   },

   { "bad_utf",
        "bad UTF-8 sequence %s",
   },

   { "mismatched_string",
        "concatenated string literal types do not match",
   },

   { "static_assert",
        "static_assert failed %s",
   },

   { "static_assert_semi",
        "';' expected following static_assert declaration",
   },

   { "narrow_string",
        "string literal must be a narrow string literal",
   },

   { "no_nullptr_bool",
        "nullptr cannot give boolean result",
   },

// Error messages specific to TX86
        // Can't specify 16 bit instruction set for 32 bit memory model
  { "bad_iset",
        "invalid instruction set '%c' for memory model '%c'",   // 166
        "Ung�ltiger Instruktionssatz '%c' f�r Speichermodell '%c'",     // 166
        "jeu d'instructions '%c' incompatible avec le mod�le de m�moire '%c'",  // 166
        "���߃Z�b�g '%c' �����������f�� '%c' �ɂ͎g���Ȃ�",     // 166
  },

   { "too_many_symbols",
        "more than %d symbols in object file",
   },


//////////////////////////////////////////////////////////////////
// Preprocessor and C messages

  { "cpp_comments",
        "// comments are not ANSI C",                   /* 60   */
        "Kommentare mit // entsprechen nicht ANSI C",                   /* 60   */
        "commentaires // non valides en C ANSI",                        /* 60   */
        "// �Ŏn�܂�R�����g�� ANSI C �ɂȂ�",          /* 60   */
  },

//////////////////////////////////////////////////////////////////
// C messages

        /* ANSI 3.5.2.1 There must be at least one member
           of the struct
         */
  { "empty_sdl",
        "struct-declaration-list can't be empty",
        "Struct-Declaration-Liste darf nicht leer sein",
        "la liste de d�claration des structures ne doit pas �tre vide",
        "struct �̐錾���X�g�͋󂫂ɂȂ��Ă��Ă͂Ȃ�Ȃ�",
  },
        // Use -p to turn off autoprototyping
  { "recursive_proto",
        "recursive prototype, turn off autoprototyping",
        "Rekursiver Prototyp, autom. Prototypbildung abschalten",
        "prototype r�cursif, d�sactivez le prototypage automatique",
        "�ċA�I�ȃv���g�^�C�v�錾�A�����v���g�^�C�v��OFF�ɂ��Ȃ���΂Ȃ�Ȃ�",
  },

//////////////////////////////////////////////////////////////////
// C and C++ messages


  { "bad_type_comb",
        "illegal type combination, possible missing ';' after struct", // 181S
        "Unzul�ssige Typkombination, evtl. fehlt ';' nach Struct", // 181S
        "combinaison de types non autoris�e, absence possible de ',' apr�s struct", // 181S
  },

        /* Can't have both near and far, etc.
           Can't use modifiers on references, pascal on pointers, etc.
           Can't have stack pointer to function.
           Can't have things like short long, etc.
         */
  { "illegal_type_combo",
        "illegal combination of types",                 /* 125S */
        "Unzul�ssige Typkombination",                   /* 125S */
        "combinaison de types incorrecte",                      /* 125S */
        "�s���Ȍ^�̑g����",                             /* 125S */
  },

  { "ptr_to_ref",
        "illegal pointer to reference",
  },

  { "ref_to_ref",
        "illegal reference to reference",
  },

  { "illegal_cast",
        "illegal cast",                                 /* 82 S */
        "Unzul�ssiges Cast",                                    /* 82 S */
        "cast non valide",                                      /* 82 S */
        "�s���L���X�g",                                 /* 82 S */
  },
  { "2manyinits",
        "too many initializers",                        /* 56 S */
        "Zu viele Initialisierer",                      /* 56 S */
        "trop de codes d'initialisation",               /* 56 S */
        "�������q����������",                           /* 56 S */
  },
        // Probably need an explicit cast
  { "explicit_cast",
        "need explicit cast to convert",                // 26
        "Implizite Konvertierung nicht m�glich",        /* 26   */
        "conversion implicite impossible",              /* 26   */
        "�Öقȕϊ����ł��Ȃ�",                         /* 26   */
  },
        /* ANSI C 3.5.4.3
                func(s) short s; { ... }
           should be prototyped as:
                func(int s);
           rather than:
                func(short s);
         */
  { "prototype",
        "prototype for '%s' should be %s",              /* 19   */
        "Prototyp f�r '%s' sollte %s sein",             /* 19   */
        "le prototype de '%s' doit �tre %s",            /* 19   */
        "'%s' �̃v���g�^�C�v�� %s �łȂ���΂Ȃ�Ȃ�",  /* 19   */
  },
  { "tag",
        "'{' or tag identifier expected",               /* 12 S */
        "'{' oder Tag-Bezeichner erwartet",             /* 12 S */
        "'{' ou identificateur de balise requis",       /* 12 S */
        "'{' �܂��̓^�O���ʎq�łȂ���΂Ȃ�Ȃ�",       /* 12 S */
  },
  { "no_inline",
        "function '%s' is too complicated to inline",   /* 15 W */
        "Funktion '%s' zu komplex f�r Inline",          /* 15 W */
        "fonction '%s' trop complexe pour inline",      /* 15 W */
        "�֐� '%s' �����G�����ăC�����C�����ł��Ȃ�",   /* 15 W */
  },
  { "statement",
        "statement expected",                           /*  7 S */
        "Anweisung erwartet",                           /*  7 S */
        "instruction requise",                          /*  7 S */
        "���łȂ���΂Ȃ�Ȃ�",                         /*  7 S */
  },
        // Identifer is both a symbol and a member of a struct.
  { "ambig_ref",
        "ambiguous reference to '%s'",                  // 189
        "Mehrdeutige Referenz '%s'",                            // 189
        "r�f�rence � '%s' ambigu�",                             // 189
  },

        // Can't implicitly convert one of the function parameters,
        // probably need a cast.
  { "explicitcast",
        "need explicit cast for function parameter %d to get", // 191
  },

        // 1. Command line switches aren't right
  { "nodebexp",
        "can't compile debugger expression",                    // 194
  },
  { "was_declared",
        "It was declared as: %s",                               // 185
        "Wurde deklariert als: %s",                             // 185
        "El�ment d�clar� auparavant sous la forme %s",                          // 185
  },
  { "now_declared",
        "It is now declared: %s",                               // 186
        "Wird jetzt deklariert als: %s",                        // 186
        "El�ment d�sormais d�clar� sous la forme %s",                           // 186
  },

        // ANSI 3.4
        // The value for a case is larger than the type of
        // the switch expression, for example, if you are
        // switching on a short, and the case is 100000L, then
        // it won't fit.
  { "const_case",
        "constant expression does not fit in switch type",      /* 148S */
        "Konstanter Ausdruck pa�t nicht in Schaltertyp",        /* 148S */
        "expression constante incompatible avec le type d'aiguillage",  /* 148S */
        "�萔���� switch �ϐ��̃T�C�Y���傫��",       /* 148S */
  },

        /* ANSI 3.5 A declarator shall declare at least
           a declarator, a tag, or the members of an enumeration
         */
  { "empty_decl",
        "empty declaration",                                    /* 149S */
        "Leere Deklaration",                                    /* 149S */
        "d�claration vide",                                     /* 149S */
        "�󂫐錾",                                     /* 149S */
  },

        /* This is detected when the optimizer does data flow analysis
           on the program. The analysis has determined that there
           is no path through the function that possibly sets the
           variable before it is used. This is nearly always indicative
           of a serious bug.
         */
  { "used_b4_set",
        "variable '%s' used before set",                // 150W
        "Variable '%s' wird vor dem Setzen benutzt",            // 150W
        "variable '%s' utilis�e avant sa d�finition",           // 150W
        "�ϐ� '%s' ������̑O�Ɏg�p����Ă���",         // 150W
  },

        // Probably results in an invalid pointer beyond the end of the stack
  { "ret_auto",
        "returning address of automatic '%s'",          // 161W
        "R�ckgabe der Adresse der Automatic-Zuweisung '%s'",            // 161W
        "renvoi de l'adresse de la fonction automatic '%s'",            // 161W
        "�����ϐ� '%s' �̃|�C���^��Ԃ��Ă���",                 // 161W
  },

        // Code and data for 16 bit compiles is output into 64Kb
        // segments. One of those segments
        // exceeded 64Kb. Divide your source module up into smaller
        // pieces, or switch to a 32 bit memory model.
  { "seg_gt_64k",
        "segment size is 0x%lx, exceeding 64Kb",                        // 162
        "Segmentgr��e 0x%lx �bersteigt 64 Kb",                  // 162
        "la taille du segment est 0x%lx, d�passement des 64 Ko",                        // 162
        "0x%lx �̃Z�O�����g�T�C�Y�� 64Kb ���z���Ă���",         // 162
  },

        // __saveregs is recognized but not supported by Digital Mars C/C++.
  { "bad_kwd",
        "keyword not supported",                        // 163
        "Schl�sselwort wird nicht unterst�tzt",                 // 163
        "mot-cl� non valide",                   // 163
        "�L�[���[�h���T�|�[�g����Ă��Ȃ�",                     // 163
  },

        // The member appears in more than one struct, so you
        // need to specify which it is.
  { "ambig_member",
        "'%s' is a member of '%s' and '%s'",            // 164
        "'%s' ist Glied von '%s' und '%s'",             // 164
        "'%s' est membre de '%s' et de '%s'",           // 164
        "'%s' �� '%s' �� '%s' �̗����̃����o�ɂȂ��Ă���",      // 164
  },

        // Can't have a member of struct X that is of type X
  { "mem_same_type",
        "member '%s' can't be same type as struct '%s'",        // 165
        "Glied '%s' kann nicht vom gleichen Typ sein wie Struct '%s'",  // 165
        "le membre '%s' et la structure '%s' ne doivent pas �tre du m�me type", // 165
        "�����o '%s' �̌^�� struct '%s' �Ɠ����ɂȂ��Ă͂Ȃ�Ȃ�",      // 165
  },

        /* ANSI 3.7.1   */
  { "explicit_param",
        "function definition must have explicit parameter list", /* 144S */
        "Funktionsdefinition ben�tigt explizite Parameterliste", /* 144S */
        "une liste de param�tres explicite doit �tre associ�e � la d�finition de la fonction", /* 144S */
        "�֐���`�ɂ͋�̓I�ȃp�����[�^���X�g���K�v",            /* 144S */
  },

        /* ANSI 3.5.7   */
  { "ext_block_init",
        "external with block scope cannot have initializer",    /* 145S */
        "Externe mit Block-G�ltigkeit kann keinen Initialisierer haben",        /* 145S */
        "les variables externes utilisant la visibilit� de bloc doivent �tre d�pourvues de code d'initialisation",      /* 145S */
        "�u���b�N�X�R�[�v�� external �ɂ͏������q�������Ă͂Ȃ�Ȃ�",   /* 145S */
  },

        /* Precompiled headers can only have declarations, not
           definitions, in them.
         */
  { "data_in_pch",
        "data or code '%s' defined in precompiled header",      /* 146S */
        "Daten oder Code in vorkompiliertem Header definiert",          /* 146S */
        "l'en-t�te pr�compil� contient les donn�es ou le code '%s'",    /* 146S */
        "�v���R���p�C���w�b�_�Ƀf�[�^����`����Ă���",                 /* 146S */
  },

        /* ARM 6.6.3
           A non-void return type was specified for the function,
           but no return expression is given.
         */
  { "no_ret_value",
        "no return value for function '%s'",            // 127S,W
        "Kein R�ckgabewert f�r Funktion '%s'",  // 127S,W
        "pas de valeur de retour pour la fonction '%s'",                // 127S,W
        "�֐� '%s' �̖߂�l���Ȃ�",                             /* 127S */
  },
  { "sizeof_bitfield",
        "can't take sizeof bit field",                  /* 128S */
        "Kann kein Sizeof-Bitfeld aufnehmen",   /* 128S */
        "sizeof non utilisable avec un champ de bits",                  /* 128S */
        "�r�b�g�t�B�[���h�� sizeof ���Ƃ邱�Ƃ͂ł��Ȃ�",       /* 128S */
  },
  { "no_ident_decl",
        "no identifier for declarator",                 /* 120S */
        "Keine Bezeichner f�r Deklarator",              /* 120S */
        "d�claration d�pourvue d'identificateur",                       /* 120S */
        "�錾�q�Ɏ��ʎq���Ȃ�",                         /* 120S */
  },
  { "typesize_gt64k",
        "size of type exceeds 64k",                     /* 121S */
        "Typ gr��er als 64 KB",                 /* 121S */
        "taille du type sup�rieure � 64 Ko",                    /* 121S */
        "�^�̃T�C�Y�� 64k ���z���Ă���",                /* 121S */
  },
  { "noaddress",
        "can't take address of register, bit field, constant or string", /* 103 S */
        "Kann Adresse von Register, Bit-Feld, I-Konstante oder String nicht aufnehmen", /* 103 S */
        "impossible d'enregistrer l'adresse du registre, du champ de bits, de la constante ou de la cha�ne", /* 103 S */
        "���W�X�^�A�r�b�g�t�B�[���h�A�萔����ѕ�����̃A�h���X�͎��Ȃ�", /* 103 S */
  },

  { "bad_struct_use",
        "undefined use of struct or union",             /* 99 S */
        "Undefinierte Verwendung von Struct oder Union",        /* 99 S */
        "utilisation non d�finie de struct ou union",           /* 99 S */
        "struct �܂��� union �̕s���g�p",               /* 99 S */
  },

        /* Occurs in instances like:
                if (a = b)
                while (x = f())
           which are common errors when
                if (a == b)
                while (x == f())
           were intended. To suppress the warning, rewrite as:
                if ((a = b) != NULL)
                while ((x = f()) != NULL)
         */
  { "assignment",
        "possible unintended assignment",               /* 100 W */
        "M�glicherweise unbeabsichtigte Zuweisung",     /* 100 W */
        "pr�sence possible d'une affectation non voulue",               /* 100 W */
//        #pragma dbcs(push,1)
//        "���������̉\��������",                     /* 100 W */
//        #pragma dbcs(pop)
  },
  { "type_mismatch",
        "type mismatch",                                /* 76 S */
        "Typ stimmt nicht �berein",                             /* 76 S */
        "conflit de types",                             /* 76 S */
        "�^���������Ă���",                             /* 76 S */
  },
  { "mult_default",
        "'default:' is already used",                   /* 77 S */
        "'default:' wird bereits benutzt",                      /* 77 S */
        "'default:' d�j� utilis�",                      /* 77 S */
        "'default:' �͊��Ɏg���Ă���",                /* 77 S */
  },
  { "not_switch",
        "not in a switch statement",                    /* 78 S */
        "Nicht in einer Verzweigungsanweisung",                 /* 78 S */
        "pas dans une instruction d'aiguillage",                        /* 78 S */
        "switch �����łȂ�",                            /* 78 S */
  },
        /* Probably means you forgot to declare a function that returns */
        /* a pointer, so the compiler assumed it returns int. Cast int  */
        /* to a long before the pointer cast if you really mean it.     */
  { "int2far",
        "conversion of int to far or handle pointer",   /* 79 S */
        "Konvertierung von Int in Far- oder Handle-Pointer",    /* 79 S */
        "conversion de int en pointeur far ou descripteur",     /* 79 S */
        "int �� far �܂��� handle �|�C���^�ɕϊ�����Ă���",    /* 79 S */
  },
  { "mult_case",
        "case %ld was already used",                    /* 80 S */
        "Case %ld wurde bereits benutzt",                       /* 80 S */
        "le cas %ld a d�j� �t� utilis�",                        /* 80 S */
        "case %ld �͊��Ɏg���Ă���",                  /* 80 S */
  },
        /* A function must precede a ().
           Also occurs if a template declaration is not
           a class template or a function template.
         */
  { "function",
        "function expected",                            /* 64 S */
        "Funktion erwartet",                                    /* 64 S */
        "fonction requise",                             /* 64 S */
        "�֐��łȂ���΂Ȃ�Ȃ�",                       /* 64 S */
  },
  { "ident_abstract",
        "identifier '%s' found in abstract declarator", /* 65 S */
        "Bezeichner in abstraktem Deklarator gefunden", /* 65 S */
        "identificateur d�tect� dans une d�claration abstraite",        /* 65 S */
        "���ې錾�q�Ɏ��ʎq������",                     /* 65 S */
  },
  { "const_init",
        "constant initializer expected",                /* 59 S */
        "Konstanter Initialisierer erwartet",           /* 59 S */
        "initialisation de la constante requise",       /* 59 S */
        "�萔�̏������q�łȂ���΂Ȃ�Ȃ�",             /* 59 S */
  },
        // ARM 7
        // Only in function definitions and function declarations
        // may the decl-specifier-seq be omitted.
        // A decl-specifier-seq is the storage class followed
        // by the type of a declaration.
  { "decl_spec_seq",
        "missing decl-specifier-seq for declaration of '%s'",   /* 61 S */
        "decl-specifier-seq fehlt f�r Deklaration von '%s'",    /* 61 S */
        "s�quence de sp�cification manquante pour la d�claration de '%s'",      /* 61 S */
        "'%s'�̐錾�ɐ錾�q�������Ă���",               /* 61 S */
  },
  { "semi_member",
        "';' expected following declaration of struct member", // 51 S
        "';' erwartet",                                 /* 51 S */
        "';' requis",                                   /* 51 S */
        "';' ���Ȃ���΂Ȃ�Ȃ�",                       /* 51 S */
  },
  { "bitfield",
        "bit field '%s' must be of integral type",      /* 50 S */
        "Feld '%s' mu� vom Typ Integral sein",          /* 50 S */
        "le champ '%s' doit �tre de type int�gral",     /* 50 S */
        "�t�B�[���h '%s' �͐����^�łȂ���΂Ȃ�Ȃ�",   /* 50 S */
  },
  { "bitwidth",
        "%d exceeds maximum bit field width of %d bits",        // 52 S
        "Max. Breite von %d Bits �berschritten",                /* 52 S */
        "d�passement de la largeur autoris�e de %d bits",       /* 52 S */
        "%d �r�b�g�̍ő啝���z���Ă���",                        /* 52 S */
  },
  { "unknown_size",
        "size of %s is not known",                      /* 53 S */
        "Gr��e von %s nicht bekannt",                   /* 53 S */
        "taille de %s inconnue",                        /* 53 S */
        "%s �̃T�C�Y�͒m���Ă��Ȃ�",                  /* 53 S */
  },
  { "bad_member_type",
        "illegal type for '%s' member",                 /* 54 S */
        "Unzul�ssiger Typ f�r Glied '%s'",              /* 54 S */
        "membre '%s' de type non autoris�",             /* 54 S */
        "'%s' �����o�̌^���s��",                        /* 54 S */
  },
  { "id_or_decl",
        "identifier or '( declarator )' expected",      /* 39 S */
        "Bezeichner oder '( declarator )' erwartet",    /* 39 S */
        "identificateur ou '( d�claration )' requis",   /* 39 S */
        "���ʎq�܂��� '( �錾�q )' �łȂ���΂Ȃ�Ȃ�", /* 39 S */
  },
  { "not_param",
        "'%s' is not in function parameter list",               /* 40 S */
        "'%s' ist nicht in der Funktionsparameterliste",        /* 40 S */
        "'%s' ne figure pas dans la liste des param�tres de la fonction", /* 40 S       */
        "'%s' �͊֐��̃p�����[�^���X�g�ɂ͊܂܂�Ă��Ȃ�",      /* 40 S */
  },
  { "param_context",
        "parameter list is out of context",                     /* 41 S */
        "Parameterliste au�erhalb des Kontexts",                /* 41 S */
        "la liste des param�tres est hors contexte",            /* 41 S */
        "�p�����[�^���X�g�̈ʒu�֌W����������",                 /* 41 S */
  },
  { "noprototype",
        "function '%s' has no prototype",               /* 44 S */
        "Funktion '%s' hat keinen Prototyp",            /* 44 S */
        "la fonction '%s' n'a pas de prototype",        /* 44 S */
        "�֐� '%s' �ɂ̓v���g�^�C�v���Ȃ�",             /* 44 S */
  },
  { "datadef",
        "expected data def of '%s', not func def",      /* 45 S */
        "Datendefinition von '%s' erwartet, nicht Funktionsdefinition", /* 45 S */
        "d�finition de donn�es de '%s' requise et non d�finition de fonction",  /* 45 S */
        "�֐���`�ł͂Ȃ��A'%s' �̃f�[�^��`�łȂ���΂Ȃ�Ȃ�",/* 45 S */
  },
  { "noextern",
        "cannot define parameter as extern",                    /* 37 S */
        "Parameter kann nicht als extern definiert werden",     /* 37 S */
        "impossible de d�finir le param�tre comme extern",      /* 37 S */
        "�p�����[�^�� extern �ƒ�`���邱�Ƃ͂ł��Ȃ�",         /* 37 S */
  },
  { "badtag",
        "'%s' is not a correct struct, union or enum tag identifier", /* 28 S */
        "'%s' ist kein korrekter Tag-Bezeichner f�r Struct, Union oder Enum", /* 28 S */
        "'%s' n'est pas une balise struct, union ou enum valide", /* 28 S */
        "'%s' �� struct�Aunion �܂��� enum �̃^�O���ʎq�ł͂Ȃ�", /* 28 S */
  },
  { "nomatch_proto",
        "type of '%s' does not match function prototype", /* 105 S */
        "Typ von '%s' stimmt nicht mit Prototyp der Funktion �berein", /* 105 S */
        "le type de '%s' ne correspond pas au prototype de la fonction", /* 105 S */
        "'%s' �̌^���֐��v���g�^�C�v�Ɩ������Ă���",    /* 105 S */
  },
  { "void_novalue",
        // Also, void& is an illegal type
        // Constructors, destructors and invariants cannot return values.
        /* Functions returning void cannot return values.       */
        "voids have no value; ctors, dtors and invariants have no return value", // 106
        "Voids haben keinen Wert, Ctors und Dtors haben keinen R�ckgabewert", /* 106 */
        "les void sont d�pourvus de valeur, les ctor et dtor ne renvoient pas de valeur", /* 106 */
//        #pragma dbcs(push,1)
//        "void �ɂ͒l���Ȃ��A�\�z�q�A���Ŏq�ɂ͖߂�l���Ȃ�", /* 106 */
//        #pragma dbcs(pop)
  },
        /* Precompiled headers must be compiled with same
           switches as when it is used.
           The precompiled header is ignored, and the header is reparsed.
         */
  { "pch_config",
        "different configuration for precompiled header", // 139 (W22)
        "Abweichende Konfiguration f�r vorkompilierten Header", /* 139 */
        "la configuration de l'en-t�te pr�compil� a chang�", /* 139 */
        "�������I�v�V�����ŃR���p�C�������v���R���p�C���w�b�_���g�p���Ă���", /* 139 */
  },
        // Use -cpp to precompile a header file with C++, as the default
        // is to compile a .h file with the C compiler.
  { "wrong_lang",
        "precompiled header compiled with C instead of C++",    // 182 F
        "Vorkompilierter Header wurde mit C statt mit C++ kompiliert",  // 182 F
        "en-t�te pr�compil� sous C et non sous C++",    // 182 F
  },

        // Define the struct before referencing its members.
  { "not_a_member",
        "'%s' is not a member of undefined class '%s'", // 175
        "'%s' ist nicht Glied des vorausreferenzierten Class '%s'",     // 175
        "'%s' n'est pas membre de la structure r�f�renc�e '%s'",        // 175
  },
  { "not_a_member_alt",
        "'%s' is not a member of undefined class '%s', did you mean '%s'?",
  },

        // ANSI 3.7
        // A static is referred to, but no definition given, i.e.:
        //      static void f();
        //      void g() { f(); }
  { "no_static_def",
        "no definition for static '%s'",                // 172
        "Keine Definition f�r Static '%s'",             // 172
        "la fonction static '%s' n'est pas d�finie",            // 172
        "static '%s' �͒�`����Ă��Ȃ�",               // 172
  },

        // ANSI 3.7
        // An ANSI requirement that there be at least one global
        // symbol defined.
  { "no_ext_def",
        "need at least one external def",               // 173
        "Mindestens eine externe Definition erforderlich",              // 173
        "au moins une d�finition externe est obligatoire",              // 173
        "�Œ�1�� external ��`���K�v",                // 173
  },

  { "decl_0size_bitfield",
        "declarator for 0 sized bit field",             /* 129S */
        "Deklarator f�r Bitfeld mit Gr��e 0",           /* 129S */
        "d�claration d'un champ de bits de taille z�ro",                /* 129S */
        "�T�C�Y 0 �̃r�b�g�t�B�[���h�Ɏ��ʎq�����邱�Ƃ͂ł��Ȃ�",/* 129S     */
  },

        /* An internally generated tag name is used. You should supply a
           tag name for easy debugging and name mangling purposes.
         */
  { "notagname",
        "no tag name for struct or enum",               /* 130W */
        "Kein Tag-Name f�r Struct oder Enum",           /* 130W */
        "struct ou enum d�pourvu de nom de balise",             /* 130W */
        "struct �܂��� enum �Ƀ^�O�����Ȃ�",                    /* 130W */
  },
  { "unnamed_bitfield",
        "can't have unnamed bit fields in unions",      /* 123  */
        "Unbenannte Bit-Felder in Unions nicht zul�ssig",       /* 123  */
        "champs de bits sans nom interdits dans les unions",    /* 123  */
        " union�ɂ͖����r�b�g�t�B�[���h���܂ނ��Ƃ͂ł��Ȃ�",   /* 123  */
  },
        /* Large automatic allocations will probably cause stack overflow */
  { "large_auto",
        "very large automatic",                         /* 124W */
        "Sehr gro�e Automatic-Zuweisung",                       /* 124W */
        "assignation automatique de taille trop importante",                    /* 124W */
        "�����ϐ����傫������",                         /* 124W */
  },
  { "array",
        "array or pointer required before '['",         /* 96 S */
        "Array oder Pointer erforderlich vor '['",              /* 96 S */
        "tableau ou pointeur requis avant '['",         /* 96 S */
        "'[' �̑O�͔z��܂��̓|�C���^�łȂ���΂Ȃ�Ȃ�",       /* 96 S */
  },

        /* ANSI C 3.5.4.2       */
  { "array_dim",
        "array dimension %d must be > 0",                       /* 97   */
        "Array-Dimension mu� > 0 sein",                 /* 97   */
        "la dimension du tableau doit �tre sup�rieure � 0",                     /* 97   */
        "�z��̎������� 0 �ȏ�łȂ���΂Ȃ�Ȃ�",              /* 97   */
  },

  { "pointer",
        "pointer required before '->', '->*' or after '*'",     /* 95 S */
        "Pointer erforderlich vor '->', '->*' oder nach '*'",   /* 95 S */
        "pointeur requis avant '->' ou '->*' et apr�s '*'",     /* 95 S */
        "'->'�A'->*' �̑O����� '*' �̌�̓|�C���^�łȂ���΂Ȃ�Ȃ�",  /* 95 S */
  },
  { "not_variable",
        // The symbol is not a variable, or is not a static variable.
        "'%s' is not a %svariable",                     /* 87 S */
        "'%s' ist keine %s-Variable",                           /* 87 S */
        "'%s' n'est pas une %svariable",                        /* 87 S */
        "'%s' �� %s �ϐ��ł͂Ȃ�",                      /* 87 S */
  },
  { "while",
        "'while (expression)' expected after 'do { statement }'", // 67 S
        "'while' erwartet",                                     /* 67 S */
        "'while' requis",                               /* 67 S */
        "'while' �łȂ���΂Ȃ�Ȃ�",                   /* 67 S */
  },
  { "bad_break",
        "'break' is valid only in a for, do, while or switch statement",        /* 68 S */
        "'break' ist nur g�ltig in Schleife oder Verzweigung",  /* 68 S */
        "'break' autoris� uniquement dans une boucle ou un aiguillage", /* 68 S */
        "'break' �̓��[�v�܂��� switch ���Ɍ���",       /* 68 S */
  },
  { "bad_continue",
        "'continue' is valid only in a for, do or while statement",             /* 69 S */
        "'continue' ist nur g�ltig in einer Schleife",  /* 69 S */
        "'continue' autoris� uniquement dans une boucle",               /* 69 S */
        "'continue' �̓��[�v���Ɍ���",                  /* 69 S */
  },
  { "unknown_tag",
        "undefined tag '%s'",                           /* 70 S */
        "Undefiniertes Tag '%s'",                       /* 70 S */
        "balise '%s' non identifi�e",                           /* 70 S */
        "����^�O '%s'",                                /* 70 S */
  },
  { "unknown_label",
        "undefined label '%s'",                         /* 71 S */
        "Undefiniertes Label '%s'",                             /* 71 S */
        "�tiquette '%s' non identifi�e",                                /* 71 S */
        "���胉�x�� '%s'",                              /* 71 S */
  },
        // Can't subtract 2 pointers if they point to 0 sized objects
        // because a divide by 0 would result.
  { "0size",
        "cannot subtract pointers to objects of 0 size", // 72 S
        "Objekt hat die Gr��e 0",                               /* 72 S */
        "objet de taille z�ro",                         /* 72 S */
        "�I�u�W�F�N�g�̃T�C�Y���[��",                   /* 72 S */
  },
  { "not_struct",
        "not a struct or union type",                   /* 73 S */
        "Nicht vom Typ Struct oder Union",                      /* 73 S */
        "le type n'est pas struct ou union",                    /* 73 S */
        "struct �܂��� union �ł͂Ȃ�",                 /* 73 S */
  },
        /*
           In C++, this can also happen
           when a class member function is forward referenced:
                class Y;                        // forward declaration
                class X { friend void Y::f(); } // error, ARM 11.4
         */
  { "notamember",
        "'%s' is not a member of '%s'",                 /* 74 S */
        "'%s' ist kein Glied des '%s'",                 /* 74 S */
        "'%s' n'appartient pas � la '%s'",              /* 74 S */
        "'%s' �� struct '%s' �̃����o�ł͂Ȃ�",         /* 74 S */
  },
  { "notamember_alt",
        "'%s' is not a member of '%s', did you mean '%s'?",
  },
  { "bad_ptr_arith",
        "illegal pointer arithmetic",                   /* 75 S */
        "Unzul�ssige Pointer-Arithmetik",                       /* 75 S */
        "arithm�tique de pointeur incorrect",                   /* 75 S */
        "�s���|�C���^���Z",                             /* 75 S */
  },
        /* One of:
                1. Templates can only be declared at global scope. ARM 14.1
                2. Function arguments cannot be static or extern.
                3. Auto or register variables cannot be at global scope.
                4. Typedef in conditional declaration
         */
  { "storage_class",
        "%s storage class is illegal in this context",  /* 47 S */
        "Speicherklasse %s in diesem Kontext unzul�ssig",       /* 47 S */
        "classe de stockage %s interdite dans ce contexte",     /* 47 S */
        "�����ł� %s �̋L���N���X�͎g���Ȃ�",           /* 47 S */
  },
  { "storage_class2",
        "%s storage class is illegal for %s",
  },
  { "array_of_funcs",
        "array of functions, references or voids is illegal",   /* 42 S */
        "Array von Funktionen oder Referenzen ung�ltig",        /* 42 S */
        "tableau de fonctions ou de r�f�rences non autoris�",   /* 42 S */
        "�֐��܂��͎Q�Ƃ̔z���錾�ł��Ȃ�",                   /* 42 S */
  },
  { "return_type",
        "can't return arrays, functions or abstract classes",   /* 43 S */
        "R�ckgabe von Arrays, Funktionen oder abstrakten Klassen nicht m�glich",        /* 43 S */
        "renvoi de tableaux, de fonctions ou de classes abstraites impossible", /* 43 S */
        "�z��A�֐��A���ۃN���X��߂�l�Ƃ��邱�Ƃ͂ł��Ȃ�",   /* 43 S */
  },
  { "body",
        "__body statement expected following __in or __out",
  },
  { "return",
        "__in and __out statements cannot contain return's",
  },
  { // not in errormsgs.html yet
    "complex_operands",
        "operator is not defined for complex operands",
  },
  { // C99 6.7.5.2
    "array_qual",
        "type qualifiers and static can only appear in outermost array of function parameter",
  },

  { "tdb",
        "error accessing type database '%s' %d",                // 196
  },
        // Part of syntax for __try block for Structured Exception Handling.
  { "bad_leave",
        "__leave must be within a __try block",         // TX86+0
        "__leave mu� innerhalb eines '__try'-Blocks sein",              // TX86+0
        "__leave doit se trouver dans un bloc __try",           // TX86+0
  },

        // Part of syntax for __try block for Structured Exception Handling.
  { "finally_or_except",
        "__finally or __except expected",                       // TX86+1
        "__finally oder __except erwartet",                     // TX86+1
        "__finally ou __except requis",                 // TX86+1
  },

        // Structured Exception Handling is only for Win32.
  { "try_needs_win32",
        "__try only valid for -mn memory model",                // TX86+2
        "__try nur g�ltig f�r Speichermodell -mn",              // TX86+2
        "__try est utilisable uniquement avec le mod�le de m�moire -mn",                // TX86+2
  },

        // This is part of Structured Exception Handling.
  { "needs_filter",
        "GetExceptionInformation() only valid in exception filter",     // TX86+3
        "GetExceptionInformation() nur g�ltig in Ausnahmefilter",       // TX86+3
        "GetExceptionInformation() utilisable uniquement dans un filtre d'exceptions",  // TX86+3
  },

        // This is part of Structured Exception Handling.
  { "needs_handler",
        "GetExceptionCode() only valid in exception filter or handler", // TX86+4
        "GetExceptionCode() nur g�ltig in Ausnahmefilter oder Handler", // TX86+4
        "GetExceptionCode() utilisable uniquement dans un filtre ou un gestionnaire d'exceptions",      // TX86+4
  },

        // Supported types are:
        //      __declspec(dllimport)
        //      __declspec(dllexport)
        //      __declspec(naked)
        //      __declspec(thread)
  { "bad_declspec",
        "unsupported __declspec type",                  // TX86+5
        "Nichtunterst�tzter __declspec-Typ",                    // TX86+5
        "type __declspec incompatible",                 // TX86+5
  },

        /* Supported based types are:
                __based(__segname("_DATA"))  => __near
                __based(__segname("_STACK")) => __ss
                __based(__segname("_CODE"))  => __cs
        */
  { "bad_based_type",
        "unsupported based type",                       // TX86+6
        "Nichtunterst�tzter Based-Typ",                 // TX86+6
        "type based incompatible",                      // TX86+6
        "���T�|�[�g�� based �^",                        // 167
  },

        // dllimports can only be extern declarations
  { "bad_dllimport",
        "initializer or function body for dllimport not allowed", // TX86+7
        "Initialisierer oder Funktionsrumpf f�r Dllimport nicht zul�ssig", // TX86+7
        "code d'initialisation ou corps de la fonction non autoris� pour dllimport", // TX86+7
  },

        /* _far16 is used only under OS/2 2.0 flat memory model */
  { "far16_model",
        "'_far16' is only valid in -mf memory model",   /* 137  */
        "'_far16' nur g�ltig f�r Speichermodell -mf",   /* 137  */
        "'_far16' valide uniquement dans le mod�le de m�moire -mf",     /* 137  */
        "'_far16' �� -mf ���������f���Ɍ���",           /* 137  */
  },

        /* The compiler cannot generate code for a far16
           function body, only call it.
         */
  { "far16_extern",
        "'_far16' functions can only be extern",        /* 138  */
        "'_far16'-Funktionen k�nnen nur extern sein",   /* 138  */
        "les fonctions '_far16' doivent �tre de type extern",   /* 138  */
        "'_far16' �֐��� extern �łȂ���΂Ȃ�Ȃ�",    /* 138  */
  },

        /* alloca() requires that a special stack frame be set
           up which is in conflict with stack frames that Windows
           requires.
         */
  { "alloca_win",
        "alloca() cannot be used in Windows functions", // 151S
        "alloca() kann nicht in Windows-Funktionen benutzt werden",     // 151S
        "allocal() non autoris� dans les fonctions Windows",    // 151S
        "alloca() �� Windows �֐��ł͎g���Ȃ�",         // 151S
  },

        // Error messages from the inline assembler.

        // The user has given the incorrect number of operands for
        // the instruction.  Tell them the correct number
  { "nops_expected",                                            // 152
        "%d operands expected for the %s instruction, had %d",
        "%d Operanden erwartet f�r die %s-Instruktion",
        "'%d' op�randes l'instruction %s doit comprendre",
        "%d �̃I�y�����h���K�v (����:%s)",
  },


        // The user has specified the incorrect size of operand for the
        // instruction.  For instance:
        //      char c;
        //      __asm push c;
        // This would be illegal because the PUSH instruction does
        // not allow for an 8 bit memory operand.
  { "bad_op",
        "Illegal type/size of operands for the %s instruction", // 153 W
        "Unzul�ssige(r) Typ/Gr��e der Operanden f�r die %s-Instruktion",        // 153 W
        "Type/taille des op�randes incompatible avec l'instruction %s", // 153 W
        "%s ���߂̃I�y�����h�̌^����уT�C�Y���s��",    // 153
  },

        // A non-sensical operand was entered on a floating point instruction
        // for instance:
        //      fdiv    0x50
        // A numeric constant entered into a floating point instrution
  { "bad_float_op",
        "Unknown operand type for this floating point instruction",     // 154
        "Unbekannter Oprendentyp f�r diese Flie�komma-Instruktion",     // 154
        "Type d'op�rande incompatible avec une instruction en virgule flottante",       // 154
        "�����_���߂̃I�y�����h�^�C�v���s��",           // 154
  },
        //
        // This covers illegal operands like [ah], etc.
        //
  { "bad_addr_mode",
        "Illegal addressing mode",                              // 155
        "Unzul�ssiger Adressierungsmodus",                              // 155
        "Mode d'adressage non valide",                          // 155
        "�s���A�h���X���[�h",                           // 155
  },
        //
        // If the ASM keyword is used, an assembler opcode should be the
        // start of each instruction (or a label, or prefix)
        //
  { "opcode_exp",
        "Assembler opcode expected",                            // 156
        "Assembler-Opcode erwartet",                            // 156
        "code op�ration assembleur requis",                             // 156
        "�A�Z���u���̃I�y�R�[�h�łȂ���΂Ȃ�Ȃ�",     // 156
  },
        //
        // When using the LOCK, REP, REPE, REPNE, REPZ instruction
        // prefixes, the opcode must immediately follow them
        //
  { "prefix",
        "Prefix opcode must be followed by an assembler opcode", // 157
        "Assembler-Opcode mu� auf Pr�fix-Opcode folgen", // 157
        "Le code op�ration du pr�fixe doit �tre suivi d'un code op�ration assembleur", // 157
        "�v���t�B�b�N�X�I�y�R�[�h�ɂ̓A�Z���u���̃I�y�R�[�h�������Ȃ���΂Ȃ�Ȃ�", // 157
  },
        //
        // This error message is used when an expression cannot be
        // evaluated by the inline assembler.  For instance adding two vars
        //      dec a+b
        //
  { "bad_operand",
        "Illegal operand",                                      // 158
        "Unzul�ssiger Operand",                                 // 158
        "Op�rande non autoris�e",                                       // 158
        "�s���I�y�����h",                                       // 158
  },
  { "ptr_exp",
        "Expected assembler directive PTR to follow assembler cast", // 159
        "Erwarte Assembler-Anweisung PTR nach Assembler-Cast", // 159
        "Directive assembleur PTR requise apr�s cast assembleur", // 159
        "�A�Z���u���L���X�g�ɃA�Z���u���w�� PTR �������Ȃ���΂Ȃ�Ȃ�", // 159
  },
  { "386_op",
        "Reference to '%s' caused a 386 instruction to be generated", // 160W
        "Referenz auf '%s' bewirkte eine 386-Instruktion", // 160W
        "Instruction 386 g�n�r�e par la r�f�rence � '%'", // 160W
        "'%s' �̎Q�Ƃɂ�� 386 �̖��߂𐶐�����",               // 160W
  },

        // Happens if -Wb flag and there is a segment fixup to DGROUP
  { "ds_ne_dgroup",
        "DS is not equal to DGROUP",                    // 170
        "DS ist ungleich DGROUP",                       // 170
        "D S n'est pas �gal � DGROUP",                  // 170
        "DS �� DGROUP �Ɠ����łȂ�",                    // 170
  },
        // Too many debug info types in one module.
  { "2manytypes",
        "max of %d types in debug info exceeded",               // 192 F
  },
  { "nakedret",
        "__declspec(naked) functions can't have return statements",     // 193
  },

        // Cannot #define, #undef or declare global symbols prior
        // to #include'ing a precompiled header.
        // The precompiled header is not used, and the header is reparsed.
  { "before_pch",
        "symbols or macros defined before #include of precompiled header",      // TX86+8 (W20)
        "Symbole oder Makros definiert vor #include des vorkompilierten Header",        // TX86+8
        "symboles ou macros d�finis avant #include de l'en-t�te pr�compil�",    // TX86+8
  },

        // The #include'ing of a precompiled header must be the first
        // #include, if you are using precompiled headers (-H).
        // The precompiled header is not used, and the header is reparsed.
  { "pch_first",
        "precompiled header must be first #include when -H is used",    // TX86+9 (W21)
  },
  { "thread_and_dllimport",
        "'%s' cannot be both thread and dllimport",             // TX86+10

  },
  { "no_CV3",
        "CV3 debug format is no longer supported",              // TX86+11
  },
  { "mfc",
        "#pragma DMC mfc must be before symbols",
  },

//////////////////////////////////////////////////////////////////
// C++ messages

        // When initializing a reference, the object being used as
        // an initializer must be of the same type or it must be const.
  { "bad_ref",
        "reference must refer to same type or be const",        // 183
        "Referenz mu� sich auf denselben Typ beziehen oder konstant sein",      // 183
        "la r�f�rence doit porter sur le m�me type ou �tre constante",  // 183
  },
        // Function is declared to return a value, but it returns
        // without specifying a value.
  { "implied_ret",
        "implied return of %s at closing '}' does not return value",    // 177S,W
        "Implizierter R�cksprung bei abschlie�ender '}' gibt keinen Wert zur�ck",       // 177S,W
        "le retour impliqu� par l'accolade '}' ne renvoie pas de valeur",       // 177S,W
  },
        /* ++x is overloaded by operator++()
           x++ is overloaded by operator++(int)
         */
  { "obsolete_inc",
        "using operator++() (or --) instead of missing operator++(int)", /* 140W */
        "Verwende operator++() (oder --) anstelle des fehlenden operator++(int)", /* 140W */
        "utilisation de l'op�rateur ++() (ou --) � la place de l'op�rateur manquant ++(entier)", /* 140W */
        "operator++(int) (�܂��� --) ���Ȃ��̂ł����� operator++() ���g�p����", /* 140W */
  },

        /* The member functions must be const or volatile too.  */
  { "cv_arg",
        "can't pass const/volatile object to non-const/volatile member function",       /* 141T */
        "Kann Const/Volatile-Objekt nicht an Non-Const/Volatile-Gliedfunktion �bergeben",       /* 141T */
        "impossible de transmettre un objet constant/volatile � une fonction membre de type diff�rent", /* 141T */
        "const/volatile �̃I�u�W�F�N�g�� const/volatile �łȂ������o�֐��ɓn�����Ƃ��ł��Ȃ�",  /* 141T */
  },
        /* The syntax delete [expr] p; is an anachronism, it
           has been superseded by delete [] p; ARM 5.3.4.
         */
  { "obsolete_del",
        "use delete[] rather than delete[expr], expr ignored",  /* 135W */
        "Verwenden Sie delete[] statt delete[expr], Ausdr. wird ignoriert",     /* 135W */
        "utilisez delete[] � la place de delete[expr], expr ignor�e",   /* 135W */
        "delete[expr] �ł͂Ȃ� delete[] ���g���ׂ� (expr �͖��������)",        /* 135W */
  },
        /* Support for storage management via assignment
           to 'this' is an anachronism and will be removed
           in future versions of the compiler. Use the
           facility for overloading operator new and operator
           delete instead.
         */
  { "assignthis",
        "assignment to 'this' is obsolete, use X::operator new/delete", /* 132W */
        "Zuweisung zu 'this' obsolet, verwenden Sie X::operator new/delete", /* 132W */
        "affectation � 'this' obsol�te, utilisez X::operator new/delete", /* 132W */
        "'this' �ւ̑���̑���� X::operator new/delete ���g���ׂ�", /* 132W */
  },
  { "musthaveinit",
        "trailing parameters must have initializers",
        "Nachfolgende Parameter m�ssen initialisiert werden",
        "les param�tres de fin doivent comporter des codes d'initialisation",
        "�㑱�̃p�����[�^�ɂ͏������q���K�v",
  },

        // ARM 9.6
        // An anonymous union may not have function members.
  { "func_anon_union",
        "function member '%s' can't be in an anonymous union", /* CPP+1 */
        "Funktionsglied '%s' kann nicht in anonymer Union sein", /* CPP+1 */
        "membre de fonction '%s' interdit dans une union anonyme", /* CPP+1 */
        "�֐������o '%s' �𖳖� union �Ɋ܂ނ��Ƃ͂ł��Ȃ�", /* CPP+1 */
  },

        /* Static member functions don't have a this. By the same token,
           you cannot call a non-static member function without an
           instance of the class to get the this pointer from.
           Cannot define a non-static class data member
           outside of a class.
         */
  { "no_instance",
        "no instance of class '%s'",                    /* CPP+2 */
        "Keine Instanz der Klasse '%s'",                        /* CPP+2 */
        "aucune occurrence de la classe '%s'",                  /* CPP+2 */
        "�N���X '%s' �̃C���X�^���X���Ȃ�",                     /* CPP+2 */
  },

  { "no_template_instance",
        "template %s<> is not instantiated",
  },

        // Can only derive from structs or classes
  { "not_class",
        "'%s' is not a struct or a class",              /* CPP+3 */
        "'%s' ist weder Struct noch Klasse",            /* CPP+3 */
        "'%s' n'est pas une structure ou une classe",           /* CPP+3 */
        "'%s' �� struct �ł��N���X�ł��Ȃ�",                    /* CPP+3 */
  },

        /* p->class::member     */
        /* Class must be the same as class p points to or be a public base class of it */
  { "public_base",
        "'%s' must be a public base class of '%s'",     // CPP+4
        "'%s' mu� eine �ffentliche Basisklasse von '%s' sein",  // CPP+4
        "'%s' doit �tre une classe m�re publique de '%s'",      // CPP+4
        "'%s' �� public ��{�N���X�łȂ���΂Ȃ�Ȃ�",          /* CPP+4 */
  },

        /* Identifier with type info appended exceeds 127 chars, which  */
        /* is the max length of an identifier.                          */
  { "identifier_too_long",
        "decorated identifier '%s' is %d longer than maximum of %d",
  },

        /* Function %s is overloaded, and the compiler can't find       */
        /* a function which it can coerce the arguments to match        */
  { "nomatch",
        "no match for function '%s%s'",                         /* CPP+7 */
        "Keine Entsprechung f�r Funktion '%s%s'",                               /* CPP+7 */
        "aucune correspondance pour la fonction'%s%s'",                         /* CPP+7 */
        "�֐� '%s%s' �Ɉ�v������̂��Ȃ�",                     /* CPP+7 */
  },

        /* Not all operators can be overloaded  */
  { "not_overloadable",
        "not an overloadable operator token",           /* CPP+8 */
        "Kein �berlagerbares Operator-Token",           /* CPP+8 */
        "il ne s'agit pas d'un t�moin d'op�rateur chargeable",          /* CPP+8 */
//        #pragma dbcs(push,1)
//        "�I�[�o�[���[�h�\�ȉ��Z�q�ł͂Ȃ�",                   /* CPP+8 */
//        #pragma dbcs(pop)
  },
  { "opovl_function",
        "operator overload must be a function",         /* CPP+9 */
        "Operator-�berlagerung mu� eine Funktion sein",         /* CPP+9 */
        "l'appel par op�rateur doit porter sur une fonction",           /* CPP+9 */
        "���Z�q�̃I�[�o�[���[�h�͊֐��łȂ���΂Ȃ�Ȃ�",       /* CPP+9 */
  },

        /* Operator overloaded functions must be unary, binary or n-ary */
        /* depending on which operator is overloaded. () is n-ary.      */
  { "n_op_params",
        "should be %s parameter(s) for operator",       /* CPP+10 */
        "Es sollten %s Parameter f�r Operator vorhanden sein",  /* CPP+10 */
        "l'op�rateur devrait comporter %s param�tres",  /* CPP+10 */
        "���Z�q�̃p�����[�^���� %s �łȂ���΂Ȃ�Ȃ�",         /* CPP+10 */
  },

  /* C++98 13.5-6 says:
   * An operator function shall either be a non-static member function or be a
   * non-member function and have at least one parameter whose type is a class,
   * a reference to a class, an enumeration, or a reference to an enumeration.
   */
  { "param_class",
        "at least one parameter must be a class, class&, enum or enum&",
        "Mindestens ein Parameter mu� Class oder Class& sein",  /* CPP+11 */
        "au moins un param�tre doit �tre une classe ou une class&",     /* CPP+11 */
        "���Ȃ��Ƃ��P�̃p�����^�[���N���X�������̓N���X�̎Q�ƂłȂ���΂Ȃ�Ȃ�", /* CPP+11 */
  },
  { "class_colcol",
        "'%s' must be a class name preceding '::'",     /* CPP+12 */
        "'%s' mu� ein Klassenname, gefolgt von '::', sein",     /* CPP+12 */
        "'%s' doit �tre un nom de classe suivi de '::'",        /* CPP+12 */
        "'::' �̑O�� '%s' �̓N���X���łȂ���΂Ȃ�Ȃ�",        /* CPP+12 */
  },

        /* When naming members of a base class in a derived class       */
        /* declaration, as in:                                          */
        /*      class abc : def { public: def::a; };                    */
        /* def must be a base class of abc.                             */
  { "base_class",
        "'%s' must be a base class",                    /* CPP+13 */
        "'%s' mu� eine Basisklasse sein",                       /* CPP+13 */
        "'%s' doit �tre une classe m�re",                       /* CPP+13 */
        "'%s' �͊�{�N���X�łȂ���΂Ȃ�Ȃ�",                  /* CPP+13 */
  },

        /* Can only adjust access to members of a base class in a
           derived class to public or protected. ARM 11.3
         */
  { "access_decl",
        "access declaration must be in public or protected section",    /* CPP+14 */
        "Zugriffsdeklaration mu� in �ffentlichem oder gesch�tztem Abschnitt erfolgen",  /* CPP+14 */
        "la d�claration d'acc�s doit se trouver dans une section publique ou prot�g�e", /* CPP+14 */
        "�A�N�Z�X�錾�� public �܂��� protected ���ɂȂ���΂Ȃ�Ȃ�",  /* CPP+14 */
  },

        /* o    not declaring destructors right                         */
        /* o    declaring constructor as virtual or friend              */
        /* o    declaring destructor as friend                          */
        /* o    specifying return value for constructor or destructor   */
  { "bad_ctor_dtor",
        "illegal constructor or destructor or invariant declaration",   // CPP+15
        "Unzul�ssige Constructor- oder Destructor-Deklaration", /* CPP+15 */
        "d�claration de constructeur ou de destructeur non valide",     /* CPP+15 */
//        #pragma dbcs(push,1)
//        "�\�z�q�܂��͏��Ŏq�̐錾���s��",                       /* CPP+15 */
//        #pragma dbcs(pop)
  },

        /* Attempted to reference a member of a class without
           a "this" pointer being available.
         */
  { "no_inst_member",
        "no instance of class '%s' for member '%s'",            /* CPP+16 */
        "Keine Instanz der Klasse '%s' f�r Glied '%s'",         /* CPP+16 */
        "aucune occurrence de la classe '%s' pour le membre %s",                /* CPP+16 */
        "�N���X '%s' �̃C���X�^���X�������o '%s'�ł͎Q�Ƃł��Ȃ�",      /* CPP+16 */
  },

        /* When a class name appears in an expression, the only
           valid tokens that can follow it are :: and (
         */
  { "colcol_lpar",
        "'::' or '(' expected after class '%s'",        /* CPP+17 */
        "'::' oder '(' erwartet nach Klasse '%s'",      /* CPP+17 */
        "'::' ou '(' requis apr�s le nom de classe '%s'",       /* CPP+17 */
        "�N���X '%s' �̎��� '::' �܂��� '(' �łȂ���΂Ȃ�Ȃ�",        /* CPP+17 */
  },

        /* A user-defined type conversion function was declared outside of a class */
  { "conv_member",
        "type conversions must be members",             /* CPP+18 */
        "Typkonvertierungen m�ssen Glieder sein",               /* CPP+18 */
        "les conversions de type doivent �tre des membres",             /* CPP+18 */
        "�^�ϊ��̓����o�łȂ���΂Ȃ�Ȃ�",             /* CPP+18 */
  },

        /* Can't have constructor as a default function parameter       */
  { "ctor_context",
        "can't handle constructor in this context",     /* CPP+19 */
        "Constructor kann in diesem Kontext nicht behandelt werden",    /* CPP+19 */
        "constructeur non utilisable dans ce contexte", /* CPP+19 */
//        #pragma dbcs(push,1)
//        "�����ō\�z�q���w�肵�Ă͂Ȃ�Ȃ�",             /* CPP+19 */
//        #pragma dbcs(pop)
  },

        /* More than one member-initializer appears for member %s.      */
        /* Can't have multiple initializers for the base class          */
  { "seen_init",
        "already seen initializer for '%s'",            /* CPP+20 */
        "Es wurde bereits ein Initialisierer f�r '%s' angegeben",               /* CPP+20 */
        "code d'initialisation de '%s' d�j� d�tect�",           /* CPP+20 */
        "'%s' �̏������q�����ɂ���",            /* CPP+20 */
  },

        /* A base class initializer appears for class %s, but there is  */
        /* no base class.                                               */
        /* The member-initializer syntax is not recognized.             */
        /* Can't have explicit initializer for virtual base class.      */
  { "bad_mem_init",
        "bad member-initializer for '%s'",              /* CPP+21 */
        "Ung�ltiger Glied-Initialisierer f�r '%s'",             /* CPP+21 */
        "code d'initialisation de membre incorrect pour la classe '%s'",                /* CPP+21 */
        "'%s' �̃����o�������q���s��",          /* CPP+21 */
  },
  { "vector_init",
        "vectors cannot have initializers",             /* CPP+22 */
        "Vektoren k�nnen keine Initialisierer haben",           /* CPP+22 */
        "les vecteurs doivent �tre d�pourvus de code d'initialisation",         /* CPP+22 */
        "�x�N�g���ɂ͏������q�������Ă͂Ȃ�Ȃ�",               /* CPP+22 */
  },
  { "del_ptrs",
        "can only delete pointers",                     /* CPP+23 */
        "Nur Pointer k�nnen gel�scht werden",                   /* CPP+23 */
        "seuls les pointeurs peuvent �tre supprim�s",                   /* CPP+23 */
        "delete �̓|�C���^�Ɍ���",                      /* CPP+23 */
  },
  { "ext_inline",
        "storage class for '%s' can't be both extern and inline", /* CPP+24 */
        "Speicherklasse f�r '%s' kann nicht gleichzeitig extern und inline sein", /* CPP+24 */
        "la classe de stockage de '%s' ne peut pas �tre � la fois extern et inline", /* CPP+24 */
        "'%s' �̋L���N���X�͓����� extern �� inline �ɂȂ��Ă��͂Ȃ�Ȃ�", /* CPP+24 */
  },
  { "non_static",
        "operator functions -> () and [] must be non-static members",   /* CPP+25 */
        "Operatorfunktionen -> () und [] m�ssen nicht-statische Glieder sein",  /* CPP+25 */
        "les op�rateurs ->, () et [] doivent �tre des membres non statiques",   /* CPP+25 */
        "operator ->�A()�A����� [] �� static �łȂ������o�łȂ���΂Ȃ�Ȃ�",  /* CPP+25 */
  },

        /* For member initializers for which the member has no constructor, */
        /* there must be exactly 1 parameter. The member is initialized */
        /* by assignment.                                               */
  { "one_arg",
        "one argument req'd for member initializer for '%s'", /* CPP+26 */
        "Ein Argument erforderl. f�r Glied-Initialisierer f�r '%s'", /* CPP+26 */
        "le code d'initialisation des membres de '%s' requiert un argument", /* CPP+26 */
        "'%s' �̃����o�������q�Ɉ���1���K�v",                 /* CPP+26 */
  },
  { "linkage_specs",
        "linkage specs are \"C\", \"C++\", and \"Pascal\", not \"%s\"", // CPP+27
        "Link-Spezifikationen sind \"C\", \"C++\" und \"Pascal\", nicht \"%s\"", // CPP+27
        "les sp�cifications de liaison sont \"C\", \"C++\" et \"Pascal\" et non pas  \"%s\"", // CPP+27
        "�����P�[�W�^�C�v�� \"%s\" �ł͂Ȃ��A\"C\"�A\"C++\"�A�����\"Pascal\" �̂����ꂩ�łȂ���΂Ȃ�Ȃ�", /* CPP+27 */
  },

        /* The member name is private or protected      */
  { "not_accessible",
        "member '%s' of class '%s' is not accessible",          /* CPP+28 */
        "Kein Zugriff auf Glied '%s' der Klasse '%s'",          /* CPP+28 */
        "le membre '%s' de la classe '%s' n'est pas accessible",                /* CPP+28 */
        "�����o '%s' (�N���X '%s')�̓A�N�Z�X�ł��Ȃ�",          /* CPP+28 */
  },

        /* The member name can only be used by member functions and     */
        /* friend functions of the class.                               */
  { "private",
        "member '%s' of class '%s' is private",                 /* CPP+29 */
        "Glied '%s' der Klasse '%s' ist privat",                        /* CPP+29 */
        "le membre '%s' de la classe '%s' est priv�",                   /* CPP+29 */
        "�����o '%s' (�N���X '%s')�� private �ɂȂ��Ă���",     /* CPP+29 */
  },

        // ARM 12.1
        // Copy constructors for class X cannot take an argument of type X.
        // Should use reference to X instead
  { "ctor_X",
        "argument of type '%s' to copy constructor",            // CPP+30
        "Argument vom Typ '%s' f�r Copy Constructor",           // CPP+30
        "utilisez un argument de type '%s' avec le constructeur de copie",              // CPP+30
//        #pragma dbcs(push,1)
//        "�R�s�[�\�z�q�̈����̌^ '%s' ���s��",           // CPP+30
//        #pragma dbcs(pop)
  },

        /* Initializers for static members must be of the form  */
        /*      int classname::member = initializer;            */
  { "static_init_inside",
        "initializer for non-const static member must be outside of class def", /* CPP+31 */
        "Initialiserer f�r statisches Glied mu� au�erh. der Klassendef. sein", /* CPP+31 */
        "le code d'initialisation d'un membre statique doit se trouver en dehors de la d�finition de la classe", /* CPP+31 */
        "static �����o�̏������q�̓N���X�̊O�łȂ���΂Ȃ�Ȃ�", /* CPP+31 */
  },

        // Initializers for const static members, when inside
        // a class definition, must be constant.
  { "in_class_init_not_const",
        "in-class initializer for const %s not constant",
  },

        /* Could not find an unambiguous type conversion        */
  { "ambig_type_conv",
        "ambiguous type conversion",                            /* CPP+32 */
        "Typkonvertierung nicht eindeutig",                             /* CPP+32 */
        "la conversion de type est ambigu�",                            /* CPP+32 */
        "�^�ϊ��������܂�",                             /* CPP+32 */
  },

        /* Cannot directly call a pure virtual function */
  { "pure_virtual",
        "'%s' is a pure virtual function",                      /* CPP+33 */
        "'%s' ist eine reine virtuelle Funktion",                       /* CPP+33 */
        "'%s' est une fonction virtuelle pure",                 /* CPP+33 */
        "'%s' �͏������z�֐�",                          /* CPP+33 */
  },

        // Non-extern consts or references must be initialized.
  { "const_needs_init",
        "const or reference '%s' needs initializer",            // CPP+34
        "Konstante oder Referenz '%s' mu� initialisiert werden",                // CPP+34
        "la constante ou la r�f�rence '%s' doit �tre initialis�e",              // CPP+34
        "const or reference '%s' �� const �܂��͎Q�ƂȂ̂ŏ������q���K�v",              // CPP+34
  },

        /* ARM 3.4      */
  { "main_type",
        "main(), WinMain() or LibMain() cannot be static or inline",    // CPP+35
        "main(), WinMain() oder LibMain() k�nnen nicht 'static' oder 'inline' sein",    // CPP+35
        "main(), WinMain() et LibMain() ne doivent pas �tre de type static ou inline",  // CPP+35
        "main()�AWinMain() ����� LibMain() �� static �ɂ� inline �ɂ����邱�Ƃ͂ł��Ȃ�",      // CPP+35
  },

        /* Cannot find constructor whose parameters match
           the initializers                             */
  { "no_ctor",
        "cannot find constructor for class matching %s::%s%s",  // CPP+36
        "Kein Constructor f�r Klasse entsprechend %s::%s%s gefunden",   // CPP+36
        "impossible de trouver un constructeur correspondant � %s::%s%s",       // CPP+36
//        #pragma dbcs(push,1)
//        "%s::%s%s �ƈ�v����N���X�̍\�z�q��������Ȃ�",      // CPP+36
//        #pragma dbcs(pop)
  },

        /* Base classes cannot appear more than once as a direct base class */
  { "dup_direct_base",
        "duplicate direct base class '%s'",                     /* CPP+37 */
        "Doppelte direkte Basisklasse '%s'",                    /* CPP+37 */
        "classe m�re directe '%s' utilis�e plus d'une fois",                    /* CPP+37 */
        "���ڂ̊�{�N���X '%s' ���d�����Ă���",                 /* CPP+37 */
  },

        /* Can't mix static and virtual storage classes for member functions */
        /* Note that operator new() and operator delete() are static    */
  { "static_virtual",
        "static function '%s' can't be virtual",                /* CPP+38 */
        "Statische Funktion '%s' kann nicht virtuell sein",             /* CPP+38 */
        "la fonction statique '%s' ne doit pas �tre de type virtuel",           /* CPP+38 */
        "static �֐� '%s' �� virtual �ɂ��邱�Ƃ��ł��Ȃ�",             /* CPP+38 */
  },
  { "opnew_type",
        "type must be void *operator new%s(size_t [,..]);",     /* CPP+39 */
        "Typ mu� void *operator new(size_t [,..]); sein",       /* CPP+39 */
        "le type doit �tre void*op�rateur new(size_t [,..]);",  /* CPP+39 */
        "�^�� void *operator new(size_t [,..]); �łȂ���΂Ȃ�Ȃ�",    /* CPP+39 */
  },

        /* Type of operator delete() must be one of:    */
        /*      void operator delete(void *);           */
        /*      void operator delete(void *,size_t);    */
        /*      void operator delete(void *,void *);    */
  { "opdel_type",
        "must be void operator delete%s(void * [,size_t]);",    /* CPP+40 */
        "mu� lauten void operator delete(void * [,size_t]);",   /* CPP+40 */
        "doit �tre void*op�rateur delete(void * [,size_t]);",   /* CPP+40 */
        "void operator delete(void * [,size_t]); �łȂ���΂Ȃ�Ȃ�",   /* CPP+40 */
  },

        /* Syntax for pure virtual function is          */
        /*      virtual func() = 0;                     */
  { "zero",
        "0 expected",                                           /* CPP+41 */
        "0 erwartet",                                           /* CPP+41 */
        "z�ro requis",                                          /* CPP+41 */
        "0 �łȂ���΂Ȃ�Ȃ�",                                         /* CPP+41 */
  },
  { "create_abstract",
        "cannot create instance of abstract class '%s'",        /* CPP+42 */
        "Instanz der abstrakten Klasse '%s' kann nicht erzeugt werden", /* CPP+42 */
        "impossible de cr�er une occurrence de la classe abstraite '%'",        /* CPP+42 */
        "���ۃN���X '%s' �̃C���X�^���X���쐬���邱�Ƃ͂ł��Ȃ�",       /* CPP+42 */
  },

        /* Can't generate X& operator=(X&) if           */
        /*      1. class has a member of a class with   */
        /*         a private operator=()                */
        /*      2. class is derived from a class with   */
        /*         a private operator=()                */
  { "cant_generate",
        "cannot generate %s for class '%s'",            /* CPP+43 */
        "%s kann f�r Klasse '%s' nicht erzeugt werden",         /* CPP+43 */
        "impossible de g�n�rer %s pour la classe '%s'",         /* CPP+43 */
        "%s �𐶐��ł��Ȃ� (�N���X '%s')",              /* CPP+43 */
  },

        /* Can't generate X& operator=(X&) if           */
        /*      1. class has a const member or base     */
        /*      2. class has a reference member         */
  { "cant_generate_const",
        "cannot generate operator=() for class '%s', member '%s' is %s",
  },

        /* Base and member initializers only allowed    */
        /* for functions that are constructors.         */
  { "not_ctor",
        "'%s' is not a constructor",                    /* CPP+44 */
        "'%s' ist kein Constructor",                    /* CPP+44 */
        "'%s' n'est pas un constructeur",                       /* CPP+44 */
//        #pragma dbcs(push,1)
//        "'%s' �͍\�z�q�ł͂Ȃ�",                        /* CPP+44 */
//        #pragma dbcs(pop)
  },
  { "base_memmodel",
        "base class '%s' has different ambient memory model",   /* CPP+45 */
        "Basisklasse '%s' hat andere Speichermodellumgebung",   /* CPP+45 */
        "la classe m�re '%s' n'utilise pas le m�me mod�le de m�moire",  /* CPP+45 */
        "��{�N���X '%s' �̃��������f���Ɩ������Ă���", /* CPP+45 */
  },

        /* Can't have a near reference to far data      */
  { "near2far",
        "'%s' is far",                                  /* CPP+46 */
        "'%s' ist Far",                                 /* CPP+46 */
        "'%s' est de type far",                                 /* CPP+46 */
        "'%s' �� far �ɂȂ��Ă���",                                     /* CPP+46 */
  },

        /* operator->() must return:
            1. a pointer to a class object
            2. an object of a class with operator->() defined
            3. a reference to an object of a class with operator->() defined
           If 2 or 3, then the class cannot be the same as
           the class for which operator->() is a member.
           ARM 13.4.6
         */
  { "bad_oparrow",
        "illegal return type %s for operator->()",              /* CPP+47 */
        "Unzul�ssiger R�ckgabetyp f�r Operator->()",            /* CPP+47 */
        "�l�ment renvoy� incompatible avec l'op�rateur ->[]",           /* CPP+47 */
        "operator->() �̖߂�^���s��",          /* CPP+47 */
  },

        /* Can't redefine default argument for parameter */
        /* even if it's to the same value. Sometimes the */
        /* line number indicated for the error is past   */
        /* the closing brace of the body of the function */
  { "default_redef",
        "redefinition of default value for parameter '%s'",     // CPP+48
        "Redefinition von Standardparametern",          /* CPP+48 */
        "modification de la d�finition du param�tre par d�faut",        // CPP+48
        "�f�t�H���g�p�����[�^���Ē�`�ł��Ȃ�",         /* CPP+48 */
  },

        /* If you define a variable with the same name
         * as a class, that class cannot have any
         * constructors
         * Why?
         * Also, see different usage in symbol.c.
         */
  { "ctor_disallowed",
        "no constructor allowed for class '%s'",        /* CPP+49 */
        "Kein Constructor zul�ssig f�r Klasse '%s'",    /* CPP+49 */
        "constructeur non utilisable avec la classe '%s'",      /* CPP+49 */
//        #pragma dbcs(push,1)
//        "�N���X '%s' �ɂ͍\�z�q���`�ł��Ȃ�", /* CPP+49 */
//        #pragma dbcs(pop)
  },

        /* If multiple classes exist as base classes, and it is         */
        /* ambiguous which is referred to.                              */
  { "ambig_ref_base",
        "ambiguous reference to base class '%s'",       /* CPP+50 */
        "Mehrdeutige Referenz auf Basisklasse '%s'",    /* CPP+50 */
        "r�f�rence � la classe m�re ambigu� '%s'",      /* CPP+50 */
        "��{�N���X '%s' �̎Q�Ƃ������܂�",     /* CPP+50 */
  },

        /* Pure member functions must be virtual, as in: */
        /*      virtual void func() = 0;                 */
  { "pure_func_virtual",
        "pure function must be virtual",                /* CPP+51 */
        "Reine Funktion mu� virtuell sein",             /* CPP+51 */
        "la fonction pure doit �tre virtuelle",         /* CPP+51 */
        "�����֐��͉��z�ɂ����Ȃ���΂Ȃ�Ȃ�",         /* CPP+51 */
  },

        /* Cannot convert a pointer to a virtual base   */
        /* into a pointer to a class derived from it.   */
        /* Cannot create a pointer to a member of a     */
        /* virtual base class.                          */
  { "vbase",
        "'%s' is a virtual base class of '%s'",         /* CPP+52 */
        "'%s' ist eine virtuelle Basisklasse von '%s'",         /* CPP+52 */
        "'%s' est une classe m�re virtuelle de '%s'",           /* CPP+52 */
        "'%s' �� '%s' �̉��z��{�N���X�ɂȂ��Ă���",            /* CPP+52 */
  },

        /* An object of a class with a constructor or   */
        /* a destructor may not be a member of a union. */
  { "union_tors",
        "union members cannot have ctors or dtors",     /* CPP+53 */
        "Union-Glieder k�nnen keine Ctors oder Dtors haben",    /* CPP+53 */
        "les membres d'une union ne doivent pas comporter de ctor ou de dtor",  /* CPP+53 */
//        #pragma dbcs(push,1)
//        "union �ɂ͍\�z�q�܂��͏��Ŏq�̂�����̂��܂ނ��Ƃ͂ł��Ȃ�",   /* CPP+53 */
//        #pragma dbcs(pop)
  },

        /* The second operand of the binary operators   */
        /* .* and ->* must be a pointer to member       */
  { "ptr_member",
        "pointer to member expected to right of .* or ->*",     /* CPP+54 */
        "Pointer auf Glied rechts von .* oder ->* erwartet",    /* CPP+54 */
        "pointeur vers un membre requis � droite de . * ou ->*",        /* CPP+54 */
        ".*�A->* �̎��̓����o�ւ̃|�C���^�łȂ���΂Ȃ�Ȃ�",   /* CPP+54 */
  },

        /* Access declarations in a derived class cannot
           be used to grant access to an
           otherwise inaccessible member of a base class,
           and cannot restrict access to an otherwise
           accessible member of a base class. ARM 11.3  */
  { "change_access",
        "cannot raise or lower access to base member '%s'",     /* CPP+55 */
        "Zugriff auf Basisglied '%s' kann nicht angehoben oder gesenkt werden", /* CPP+55 */
        "impossible d'augmenter ou de baisser le niveau d'acc�s au membre parent '%s'", /* CPP+55 */
        "�x�[�X�����o '%s' �̃A�N�Z�X��ύX�ł��Ȃ�",   /* CPP+55 */
  },

        /*  Cannot convert a pointer to a class X to a pointer
            to a private base class Y unless function is a member or
            a friend of X.
         */
  { "cvt_private_base",
        "cannot convert %s* to a private base class %s*",       /* CPP+56 */
        "%s* kann nicht in eine private Basisklasse %s* konvertiert werden",    /* CPP+56 */
        "impossible de convertir %s* en classe m�re priv�e %s*",        /* CPP+56 */
        "%s* �� private ��{�N���X %s* �ɕϊ��ł��Ȃ�", /* CPP+56 */
  },

        // ARM 9.5
  { "glbl_ambig_unions",
        "global anonymous unions must be static",               // CPP+57
        "Globale anonyme Unions m�ssen statisch sein",          // CPP+57
        "les unions anonymes globales doivent �tre statiques",          // CPP+57
        "�O���[�o���̖��� union �� static �łȂ���΂Ȃ�Ȃ�",          // CPP+57
  },

        /* The member cannot be initialized without a constructor */
  { "const_mem_ctor",
        "member '%s' is const but there is no constructor",     /* CPP+58 */
        "Glied '%s' ist eine Konstante, aber es gibt keinen Constructor",       /* CPP+58 */
        "le membre '%s' est une constante mais aucun constructeur n'est pr�sent",       /* CPP+58 */
//        #pragma dbcs(push,1)
//        "�����o '%s' �� const �Ȃ̂ɍ\�z�q���Ȃ�",      /* CPP+58 */
//        #pragma dbcs(pop)
  },
  { "static_mem_func",
        "member functions cannot be static",                    /* CPP+59 */
        "Gliedfunktionen k�nnen nicht statisch sein",                   /* CPP+59 */
        "les fonctions membres ne doivent pas �tre statiques",                  /* CPP+59 */
        "�����o�֐��� static �ɂȂ��Ă͂Ȃ�Ȃ�",                       /* CPP+59 */
  },

        /* More than one match is found for overloaded function */
  { "overload_ambig",
        "ambiguous reference to symbol",                        /* CPP+60 */
        "Mehrdeutige Referenz auf Funktion",                    /* CPP+60 */
        "r�f�rence ambigu� � la fonction",                      /* CPP+60 */
        "�֐��ւ̎Q�Ƃ������܂�",                       /* CPP+60 */
  },

        /* ARM 13.4.7 only allows declarations of the form:
           operator ++()
           operator ++(int)
           operator --()
           operator --(int)
         */
  { "postfix_arg",
        "argument to postfix ++ or -- must be int",             /* CPP+61 */
        "Argument des Postfix ++ oder -- mu� Int sein",         /* CPP+61 */
        "l'argument de l'op�rateur ++ ou -- doit �tre un entier",               /* CPP+61 */
        "��u�� ++ �܂��� -- �̈����� int �Ɍ���",              /* CPP+61 */
  },
  { "cv_func",
        "static or non-member functions can't be const or volatile", /* CPP+62 */
        "Statische oder Nicht-Glied-Funktionen k�nnen nicht 'const' oder 'volatile' sein", /* CPP+62 */
        "les fonctions statiques ou non membres ne doivent pas �tre de type constant ou volatile", /* CPP+62 */
        "static ����є񃁃��o�֐��� const �܂��� volatile �ɂȂ��Ă��Ă͂Ȃ�Ȃ�", /* CPP+62 */
  },

        /* Cannot specify a storage class or a type when
           adjusting the access to a member of a base class.
           ARM 11.3.
         */
  { "access_class",
        "access declaration of base member '%s::%s' has storage class or type", /* CPP+63 */
        "Kennzeichner oder Typ in Zugriffsdeklaration",         /* CPP+63 */
        "qualificateur ou type pr�sent dans la d�claration d'acc�s",            /* CPP+63 */
        "�A�N�Z�X�錾�ɂ͏C���q����ь^���w�肵�Ă͂Ȃ�Ȃ�",           /* CPP+63 */
  },

        /* Can't adjust access for overloaded function
           that has different access levels. ARM 11.3.
         */
  { "access_diff",
        "overloaded function '%s' has different access levels", /* CPP+64 */
        "�berlagerte Funktion '%s' hat unterschiedl. Zugriffsebenen",   /* CPP+64 */
        "le niveau d'acc�s de la fonction '%s' appel�e est diff�rent",  /* CPP+64 */
        "�I�[�o�[���[�h�֐� '%s' �̃A�N�Z�X���x�����܂��܂�",   /* CPP+64 */
  },

        /* Can't adjust access for base member when a derived
           class defines a member with the same name. ARM 11.3
         */
  { "derived_class_name",
        "a derived class member has the same name '%s'",        /* CPP+65 */
        "Ein abgeleitetes Klassenglied hat denselben Namen: '%s'",      /* CPP+65 */
        "un membre d�riv� de la classe s'appelle �galement '%s'",       /* CPP+65 */
        "�������� '%s' �����h���N���X�����o�����݂���",       /* CPP+65 */
  },

        /* Had a class name preceding the member function
           name
         */
  { "decl_other_class",
        "can't declare member of another class '%s'",           /* CPP+66 */
        "Glied einer weiteren Klasse '%s' kann nicht deklariert werden",                /* CPP+66 */
        "impossible de d�clarer le membre d'une autre classe '%s'",             /* CPP+66 */
        " �ʂ̃N���X '%s' �̃����o��錾�ł��Ȃ�",              /* CPP+66 */
  },
  { "friend_sclass",
        "invalid storage class for friend",                     /* CPP+67 */
        "Ung�ltige Speicherklassse f�r Friend",                 /* CPP+67 */
        "classe de stockage amie non valide",                   /* CPP+67 */
        "friend �ɂ͂��̕ۑ��N���X���g���Ȃ�",                  /* CPP+67 */
  },
  { "friend_type",
        "only classes and functions can be friends",            /* CPP+68 */
        "Nur Klassen und Funktionen k�nnen Friends sein",               /* CPP+68 */
        "seules les classes et les fonctions peuvent �tre des amies",           /* CPP+68 */
        "friend �̓N���X����ъ֐��Ɍ���",                      /* CPP+68 */
  },

        /* Destructors are of the form X::~X()  */
  { "tilde_class",
        "class name '%s' expected after ~",                     /* CPP+69 */
        "Klassenname '%s' erwartet nach ~",                     /* CPP+69 */
        "nom de classe '%s' requis apr�s ~",                    /* CPP+69 */
        "�u~�v�ɃN���X�� '%s' �������Ȃ���΂Ȃ�Ȃ�",                  /* CPP+69 */
  },
  { "not_enum_member",
        "'%s' is not a member of enum '%s'",                    // CPP+70
        "'%s' ist kein Glied von Enum '%s'",                    // CPP+70
        "'%s' n'est pas membre de l'ensemble enum '%s'",                        // CPP+70
        "'%s' �� enum '%s' �̃����o�łȂ�",                     // CPP+87
  },

        // ARM 6.7
        // A goto or case statement has allowed an explicit or implicit
        // initialization of a variable to be skipped.
  { "skip_init",
        "initialization of '%s' is skipped",                    // CPP+71
        "Initialisierung von '%s' wird �bergangen",                     // CPP+71
        "'%s' n'a pas �t� initialis�",                  // CPP+71
        "'%s'�̏������𖳎�",                                   // CPP+71
  },
  { "fwd_ref_base",
        "forward referenced class '%s' cannot be a base class", /* CPP+72 */
        "Vorausreferenzierte Klasse '%s' kann keine Basisklasse sein",  /* CPP+72 */
        "la classe '%s' r�f�renc�e en avant ne doit pas �tre une classe m�re",  /* CPP+72 */
        "�N���X '%s' �͑O���Q�Ƃ���Ă���̂Ŋ�{�N���X�Ƃ��邱�Ƃ͂ł��Ȃ�",   /* CPP+72 */
  },

        // ARM 5.2
        // A type-id in < > is expected following static_cast,
        // const_cast, reinterpret_cast, or dynamic_cast.
  { "lt_cast",
        "'<' expected following cast",                  // CPP+73
        "'<' erwartet nach Cast",                       // CPP+73
        "'<' requis apr�s cast",                        // CPP+73
        "'<' �łȂ���΂Ȃ�Ȃ�",                                       /* CPP+73       */
  },
  { "gt",
        "'>' expected",                                 // CPP+74
        "'>' erwartet",                                 // CPP+74
        "'>' requis",                                   // CPP+74
        "'>' �łȂ���΂Ȃ�Ȃ�",                                       /* CPP+74       */
  },
  { "templ_param_lists",
        "parameter lists do not match for template '%s'", /* CPP+75     */
        "Parameterlisten entsprechen nicht der Schablone '%s'", /* CPP+75       */
        "les listes de param�tres du squelette '%s' ne correspondent pas", /* CPP+75    */
        "�e���v���[�g '%s' �̃p�����[�^���X�g����v���Ȃ�", /* CPP+75   */
  },
        /* A template member function must have a class name
           that is a template.
           A class tag name followed by < must actually be
           a template name.
         */
  { "not_class_templ",
        "'%s' is not a class template",                 /* CPP+76 */
        "'%s' ist keine Klassenschablone",                      /* CPP+76 */
        "'%s' n'est pas le nom d'un squelette de classe",                       /* CPP+76 */
        "'%s' �̓N���X�e���v���[�g�ł͂Ȃ�",                    /* CPP+76 */
  },
  { "bad_templ_decl",
        "malformed template declaration",               /* CPP+77 */
        "Fasche Form der Schablonendeklaration",                /* CPP+77 */
        "d�claration de squelette incorrecte",          /* CPP+77 */
        "�e���v���[�g�錾����������",           /* CPP+77 */
  },

        /* All template-arguments for a function must be type-arguments. ARM 14.4 */
  { "templ_arg_type",
        "template-argument '%s' for function must be a type-argument", // CPP+78
        "Schablonenargument '%s' mu� ein Typargument sein",     /* CPP+78 */
        "l'argument de squelette '%s' doit �tre un argument de type",   /* CPP+78 */
        "�e���v���[�g���� '%s' �͌^�����łȂ���΂Ȃ�Ȃ�",     /* CPP+78 */
  },

        /* ARM 5.3.4    */
  { "adel_array",
        "must use delete[] for arrays",                 /* CPP+79 */
        "F�r Arrays mu� delete[] verwendet werden",                     /* CPP+79 */
        "delete[] obligatoire avec les tableaux",                       /* CPP+79 */
        "�z��ɂ� delete[] ���g��Ȃ���΂Ȃ�Ȃ�",                     /* CPP+79 */
  },

        /* ARM 9.4      */
  { "local_static",
        "local class cannot have static data member '%s'",      /* CPP+80 */
        "Lokale Klasse kann kein statisches Datenglied '%s' haben",     /* CPP+80 */
        "une classe locale ne doit pas comporter de membre de type donn�e statique",    /* CPP+80 */
        "���[�J���N���X�ɂ� static �f�[�^�����o '%s' ���܂ނ��Ƃ͂ł��Ȃ�",     /* CPP+80 */
  },

        /* ARM 12.3.2
           char *operator char *();     // error
           operator char *();           // ok
         */
  { "conv_ret",
        "return type cannot be specified for conversion function", /* CPP+81 */
        "F�r Konvertierungsfunktion kann kein R�ckgabetyp angegeben werden", /* CPP+81 */
        "le type renvoy� ne peut pas �tre associ� � la fonction de conversion", /* CPP+81 */
        "�ϊ��֐��̖߂�^���w�肵�Ă͂Ȃ�Ȃ�", /* CPP+81 */
  },

        /* CPP98 14.8.2
           When instantiated, all template-arguments must have values.
         */
  { "templ_arg_unused",
        "template-argument '%s' has no value in template function specialization", /* CPP+82 */
        "Schablonenargument '%s' nicht benutzt bei Funktionsparametertypen", /* CPP+82 */
        "argument de squelette '%' non utilis� avec les types de param�tres de fonction", /* CPP+82 */
        "�e���v���[�g���� '%s' �͊֐��p�����[�^�^�Ɏg���Ă��Ȃ�", /* CPP+82 */
  },
  { "cant_gen_templ_inst",
        "cannot generate template instance from -XI%s", /* CPP+83 */
        "Schabloneninstanz von -XI%s kann nicht erstellt werden",       /* CPP+83 */
        "impossible de g�n�rer une instance de squelette � partir de -XI%s",    /* CPP+83 */
        "-XI%s ����e���v���[�g�̃C���X�^���X�𐶐��ł��Ȃ�",   /* CPP+83 */
  },

        /* ARM 8.4.3
           Caused by trying to initialize:
           o    a volatile reference to a const
           o    a const reference to a volatile
           o    a plain reference to a const or volatile
         */
  { "bad_ref_init",
        "invalid reference initialization",             /* CPP+84 */
        "Ung�ltige Referenzinitialisierung",            /* CPP+84 */
        "initialisation incorrecte de la r�f�rence",            /* CPP+84 */
        "�Q�Ƃ̏��������s��",           /* CPP+84 */
  },

        /* ARM 12.6.2 Can only initialize non-static members
           in the constructor initializer.
         */
  { "no_mem_init",
        "cannot have member initializer for '%s'",      /* CPP+85 */
        "Gliedinitialisierer f�r '%s' nicht m�glich",   /* CPP+85 */
        "'%s' ne doit pas comporter de membre d'initialisation",        /* CPP+85 */
        "'%s' �Ƀ����o�������q���w��ł��Ȃ�",  /* CPP+85 */
  },
#if 0 // allowed by CPP98
        // ARM 5.3.4
  { "del_ptr_const",
        "cannot delete pointer to const",               /* CPP+86 */
        "Pointer auf Konstante kann nicht gel�scht werden",             /* CPP+86 */
        "impossible de supprimer le pointeur vers la constante",                /* CPP+86 */
        "const �ւ̃|�C���^�� delete �ł��Ȃ�",         /* CPP+86 */
  },
#endif
  { "colcol_exp",
        "'::' expected",                                // CPP+89
        "'::' erwartet",                                // CPP+89
        "'::' requis",                                  // CPP+89
        "'::' ������܂���",                            // CPP+89
  },
        // ARM 15.4
        // void func() throw(int);
        // void func() throw(unsigned); <- error, different specification
  { "exception_specs",
        "Exception specifications must match exactly for each declaration of a function", // CPP+99
        "Ausnahmespezifikationen m�ssen f�r jede Deklaration einer Funktion genau �bereinstimmen", // CPP+99
        "Les sp�cifications d'exception doivent �tre identiques pour toutes les d�clarations d'une fonction", // CPP+99
  },

        // ARM 15.4
        // Can't have void func() throw(int,int);
  { "eh_types",
        "Types may not appear more than once in an exception specification", // CPP+100
        "Typen k�nnen in Ausnahmespezifikation nur einmal auftreten", // CPP+100
        "Les types ne doivent figurer qu'une seule fois dans une sp�cification d'exception", // CPP+100
  },

        // ARM 15.3
        //  o   catch type appears more than once
        //  o   base class appears before derived class
        //  o   ptr/ref to base class appears before ptr/ref derived
  { "catch_masked",
        "Catch type masked by previous catch",          // CPP+101
        "Catch-Typ maskiert durch fr�heren Catch",              // CPP+101
        "Type catch masqu� par catch pr�c�dent",                // CPP+101
  },

        // ARM 15.3
        // catch(...) must appear as the last catch in a list
        // of catch handlers for a try-block.
  { "catch_ellipsis",
        "A '...' handler must be the last one for a try-block", // CPP+102
        "Ein '...'-Handler mu� der letzte in einem Try-Block sein", // CPP+102
        "Le gestionnaire '...' doit �tre le dernier du bloc try", // CPP+102
  },

        // ARM 15.1
        // The normal syntax for a catch is:
        // try { statements } catch (exception-declaration) { statements }
  { "catch_follows",
        "A catch must follow a try-block",                      // CPP+103
        "Ein Catch mu� auf einen Try-Block folgen",                     // CPP+103
        "Un catch ne doit pas suivre un bloc try",                      // CPP+103
  },

        // Cannot throw near classes in large data models, and
        // cannot throw far classes in small data models.
  { "not_of_ambient_model",
        "Cannot throw object of '%s' not of ambient memory model", // CPP+104
        "Kann Objekt von '%s' nicht �bertragen, da nicht vom umgebenden Speichermodell", // CPP+104
        "Throw d'un objet de '%s' impossible, mod�le de m�moire incompatible", // CPP+104
  },
  { "compileEH",
        "Compile all files with -Ae to support exception handling",     // CPP+105
        "Alle Dateien mit -EH kompilieren zur Unterst�tzung der Ausnahmebehandlung",    // CPP+105
        "Compilez tous les fichiers avec -EH pour assurer la gestion des exceptions",   // CPP+105
  },
  { "typeinfo_h",
        "#include <typeinfo.h> in order to use RTTI",           // CPP+106
        "#include <typeinfo.h> f�r Verwendung von RTTI",                // CPP+106
        "#include <typeinfo.h> pour utiliser RTTI",             // CPP+106
  },
  { "compileRTTI",
        "compile all files with -Ar to support RTTI",           // CPP+107
        "Alle Dateien mit -ER kompilieren zur Unterst�tzung von RTTI",          // CPP+107
        "Compilez tous les fichiers avec -ER pour g�rer RTTI",          // CPP+107
  },

        // ARM 5.2.6
        // This is refering to the type specified in a dynamic_cast.
  { "ptr_to_class",
        "type must be a pointer or a reference to a defined class or void*",    // CPP+108
        "Typ mu� Pointer oder Referenz auf definierte Klasse oder void* sein",  // CPP+108
        "le type doit �tre un pointeur ou une r�f�rence indiquant une classe d�finie ou void*", // CPP+108
  },

        // ARM 5.2.6
        // The expression of:
        //      dynamic_cast < type-name > ( expression )
        // must be a pointer.
  { "not_pointer",
        "expression must be a pointer",                 // CPP+109
        "Ausdruck mu� ein Pointer sein",                        // CPP+109
        "l'expression doit �tre un pointeur",                   // CPP+109
  },

        // ARM 5.2.6
        // Invalid use of dynamic_cast.
        // A polymorphic type is a class with at least one virtual function.
  { "ptr_to_polymorph",
        "expression must be a pointer or reference to a polymorphic type",      // CPP+110
        "Ausdruck mu� Pointer oder Referenz auf polymorphen Typ sein",  // CPP+110
        "l'expression doit �tre un pointeur ou une r�f�rence indiquant un type polymorphe",     // CPP+110
  },

        // Template argument list required and is surrounded by <>. ARM 14.1
  { "lt_following",
        "'<' expected following %s",                    // CPP+111
        "'<' erwartet nach %s",                         // CPP+111
        "'<' requis apr�s'%'",                          // CPP+111
  },

        // When expanding a template, a template argument needs
        // a value.
  { "no_type",
        "no type for argument '%s'",                            // CPP+113
  },
  { "templ_default_args",
        "template default args not supported",          // CPP+114
  },

        /* Can't generate X::X(X&) if
         *      1. class has a member of a class with
         *         a private copy constructor
         *      2. class is derived from a class with
         *         a private copy constructor
         */
  { "nogen_cpct",
        "cannot generate copy constructor for class '%s' because of private '%s'",      // CPP+115
  },

        // ARM 8.3
  { "mem_init_following",
        "function body or member initializer expected following declaration of '%s'",   // CPP+116
  },

        // ARM 14.2
  { "semi_template",
        "';' expected following declaration of class template '%s'",    // CPP+117
  },

        // A common error is to forget to close a class definition
        // with a ;
  { "semi_rbra",
        "';' expected following '}' of definition of class '%s'", // CPP+118
  },
        // The macro _ENABLE_ARRAYNEW is predefined to 1 if -Aa is thrown
        // to be used for #if workarounds for various compilers.
  { "enable_anew",
        "use -Aa to enable overloading operator new[] and operator delete[]",   // CPP+120
  },
  { "type_argument",
        "type-argument expected for parameter '%s' of template '%s'", // CPP+121
  },

        // ANSI C++98 14.1
        // For example:
        // template <double d> class A;
  { "param_no_float",
        "non-type template-parameter '%s' may not be a floating point, class, or void type",    // CPP+122
  },

        // C++98 10.3-5
        // "The return type of an overriding function shall be either
        // identical to the return type of the overridden function or
        // covariant with the classes of the functions"
  { "diff_ret_type",
        "return type of overriding function '%s' differs from that of '%s'", // CPP+123
  },

        // ANSI C++ 7.3.2
  { "nspace_alias_semi",
        "';' expected following namespace alias definition",    // CPP+124
  },

        // ANSI C++ 7.3.2
  { "nspace_name",
        "'%s' is not a namespace name",                 // CPP+125
  },
  { "nspace_undef_id",
        "'%s' is not a member of namespace '%s'",               // CPP+126
  },

  { "using_semi",
        "';' expected to close using-%s",                       // CPP+128
  },

        // ANSI C++ 7.3.3
  { "using_member",
        "'%s' is a member, and this is not a member declaration",       // CPP+129
  },
        /* ARM 4.7 and 8.5.3
           A temporary was generated and the reference was
           initialized to that temporary. Since the reference
           was not const, the referenced temporary may change
           its value. This can lead to unexpected behavior. This
           is an error per the ARM, and will be an error in future
           versions of the compiler. ARM 8.4.3
           This is an error, not a warning, if the -A (ANSI C++)
           compiler switch is used.
         */
  { "init2tmp",
        "non-const reference initialized to temporary", /* 60 W */
        "Nicht konstante Referenz als tempor�r initialisiert",  /* 60 W */
        "r�f�rence non constante initialis�e � une valeur temporaire",  /* 60 W */
        "�� const �̎Q�Ƃ��ꎞ�ϐ��ɏ���������",        /* 60 W */
  },
  // CPP98 14.6.3
  // typename should be followed by :: or nested-name-specifier
  { "nested_name_specifier",
        "nested-name-specifier expected following typename",
  },
  // CPP98 14.6.5
  { "no_typename",
        "typename can only be used in templates",
  },
  // CPP98 7.1.2.6
  { "explicit",
        "explicit is only for constructor declarations",
  },
  // CPP98 12.3.1.2
  { "explicit_ctor",
        "no implicit conversion with explicit constructor",
  },
  // CPP98 7.1.1.8
  { "mutable",
        "mutable is only for non-static, non-const, non-reference data members",
  },
  { "typename_expected",
        "%s is expected to be a typename member of %s",
  },
  // Use one scheme or the other
  { "mix_EH",
        "cannot mix C++ EH with NT structured EH",              // CPP+112
        "C++ EH kann nicht mit NT-Strukturiertem EH vermischt werden",          // CPP+112
        "impossible d'utiliser EH de C++ et EH structur� de NT ensemble",               // CPP+112
  },
  // CPP98 14.5.4-1
  { "primary_template_first",
        "Primary template '%s' must be declared before any specializations",
  },
  // CPP98 14.5.4-10 "The template parameter list of a specialization
  // shall not contain default template argument values."
  { "no_default_template_arguments",
        "class template partial specialization parameter lists cannot have defaults",
  },
  // CPP98 14.5.4-9 "The argument list of the specialization shall
  // not be identical to the implicit argument list of the primary
  // template."
  { "identical_args",
        "specialization arguments for template '%s' match primary",
  },
  // CPP98 14.5.4-9: "A partially specialized non-type argument expression shall not
  // involve a template parameter of the partial specialization except when
  // the argument expression is a simple identifier."
  { "not_simple_id",
        "non-type argument expression with template parameter '%s' is not a simple identifier",
  },
  // CPP98 14.5.4.1-1 More than one matching specialization is found,
  // and one is not more specialized than the other.
  { "ambiguous_partial",
        "ambiguous match of class template partial specialization '%s'",
  },
  // CPP98 5.2.10-2 "the reinterpret_cast operator shall not
  // cast away constness."
  { "no_castaway",
        "reinterpret_cast cannot cast away constness",
  },
  // Warn about C style casts.
  { "ccast",
        "C style cast",
  },
  // Need to implement this
  { "covariant",
        "covariant return type of '%s' with multiple inheritance not implemented",
  },
  // CPP98 7.3.1-4 "Every namespace-definition shall appear in the global
  // scope or in a namespace scope."
  { "namespace_scope",
        "namespace definition not in global or namespace scope",
  },
  // CPP98 7.3.1.2-2 "...the definition appears after the point of declaration
  // in a namespace that encloses the declaration's namespace."
  { "namespace_enclose",
        "namespace '%s' does not enclose member '%s' of namespace '%s'",
  },
  // CPP98 7.3.3-5 "A using-declaration shall not name a template-id."
  { "using_declaration_template_id",
        "using-declaration cannot name template-id '%s'",
  },
  // Warning about using obsolete features
  {
    "obsolete",
        "%s is obsolete, us %s instead",
  },
  // CPP98 14.7.2 Explicit instantiation
   { "malformed_explicit_instantiation",
        "unrecognized explicit instantiation",
   },
   { "should_be_static",
        "dynamically initialized global variable '%s' should be static",
   },
   { "member_auto",
        "class member %s cannot have auto storage class",
   },
   { "template_expected",
        "template id expected following template keyword",
   },
   { "no_vla_dtor",
        "variable length arrays cannot have destructors",
   },
   // CPP98 14.1-1
   { "class_expected",
        "'class' expected following 'template <template-parameter-list>'",
   },
   // CPP98 14.3.3-1
   { "class_template_expected",
        "template-template-argument '%s' must be the name of a class template",
   },
   { "declarator_paren_expected",
        "closing ')' of '( declarator )' expected",
   },
   { "simple_dtor",
        "invalid simple type name destructor",
   },
   /* CPP98 15-2 "A goto, break, return, or continue statement can be used to
    * transfer control out of a try block or handler, but not into one."
    */
   { "gotoforward",
        "cannot goto into try block or catch handler at label '%s'",
   },
   /* CPP98 13.4
    */
   { "ptmsyntax",
        "cannot parenthesize pointer to non-static member &(%s)",
   },
   /*
    */
   { "nonlocal_auto",
        "variable '%s' is not accessible from this function",
   },
   /* CPP98 8.3.6-7
    */
   { "nolocal_defargexp",
        "local '%s' cannot be used in default argument expression",
   },
   /* CPP98 7.1.3-4
    */
   { "notypedef",
        "typedef name '%s' cannot be used following class-key",
   },
   /* CPP98 7.1.3-4
    */
   { "noreturntype",
        "return type for function '%s' not specified",
   },
   /* CPP98 11.?
    */
   { "change_access2",
        "cannot change access of member %s::%s",
   },
   /* CPP98 14.3.1-3 "If a declaration acquires a function type through a type
    * dependent on a template-parameter and this causes a declaration that does
    * not use the syntactic form of a function declarator to have function type,
    * the program is ill formed."
    */
   { "acquire_function",
        "member %s cannot acquire function type through dependent template-parameter",
   },
   /* C++98 14.3.2-3 "Addresses of array elements and names or
    * addresses of nonstatic class members are not acceptable
    * template-arguments."
    */
   { "bad_template_arg",
        "'%s' cannot have address of array element or nonstatic class member as template-argument",
   },
   /* C++98 14.5.1-3
    */
   { "template_arg_order",
        "order of arguments must match template parameter list",
   },
    /* CPP98 14.5.4-9 "The type of a template parameter corresponding to a
     * specialized non-type argument shall not be dependent on a parameter
     * of the specialization."
     */
   { "dependent_specialization",
        "template %s has specialized non-type argument dependent on specialization parameter",
   },
   /* C++98 14.5.3-9
    */
   { "friend_partial",
        "friend declaration '%s' cannot declare partial specialization",
   },
   /* C++98 14.6.1-4
    */
   { "template_parameter_redeclaration",
        "redeclaration of template parameter '%s'",
   },
   /* C++98 14.7.3-6
    */
   { "explicit_following",
        "specialization for '%s' must appear before use",
   },
   /* C++98 15.4-1 "An exception-specification shall not appear in a
    * typedef declaration."
    */
   { "typedef_exception",
        "exception specification not allowed for typedef declaration '%s'",
   },


///////////////////////////////////////////////////
// HTML messages

  { "character_entity",
        "unrecognized character entity"
  }

};

///////////////////////////////////////////////////////////////////////////
// Program to generate the tables.

#include <stdio.h>
#include <stdlib.h>

#ifdef ENGLISH_ONLY
#define LANG_CNT 1
#else
#define LANG_CNT 4
#endif

int main()
{
    FILE *fp;
    int i;

    fp = fopen("msgs2.h","w");
    if (!fp)
    {   printf("can't open msgs2.h\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp,"#pragma once\n");
    fprintf(fp,"enum EM\n{");
    for (i = 0; i < sizeof(msgtable) / sizeof(msgtable[0]); i++)
    {
        fprintf(fp,"\tEM_%s=%d,\n",msgtable[i].name,i);
    }
    fprintf(fp,"};\n");

    fclose(fp);

    //////////////////////////////////////
    fp = fopen("msgtbl.h","w");
    if (!fp)
    {   printf("can't open msgs2.c\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "#pragma once\n");
    fprintf(fp,"const char *msgtbl[][%d] =\n{",LANG_CNT);
    for (i = 0; i < sizeof(msgtable) / sizeof(msgtable[0]); i++)
    {   unsigned char *p;
        int j;

        fprintf(fp,"/* %3d */\n",i);
        for (j = 0; j < LANG_CNT; j++)
        {
            switch (j)
            {   case 0: p = (unsigned char *)msgtable[i].msg; break;
                case 1: p = (unsigned char *)msgtable[i].german; break;
                case 2: p = (unsigned char *)msgtable[i].french; break;
                case 3: p = (unsigned char *)msgtable[i].japanese; break;
            }
            if (!p)
            {   fprintf(fp,"\t0,\n");
                continue;
            }
            //if (j == 3)
                //fprintf(fp,"\t#pragma dbcs(push,1)\n");
            fprintf(fp,"\t\"");
            for (; *p; p++)
            {
                switch (*p)
                {
                    case '"':
                        fputc('\\',fp);
                        fputc('"',fp);
                        break;
                    case '\n':
                        fputc('\\',fp);
                        fputc('n',fp);
                        break;
                    default:
                        if (*p < 0x20 || *p >= 0x7F)
                            //fprintf(fp, "\\x%02x", *p);
                            fprintf(fp, "\\%3o", *p);
                        else
                            fputc(*p,fp);
                        break;
                }
            }
            fprintf(fp,"\",\n");
            //if (j == 3)
                //fprintf(fp,"\t#pragma dbcs(pop)\n");
        }
    }
    fprintf(fp,"};\n");

    fclose(fp);

    return EXIT_SUCCESS;
}

