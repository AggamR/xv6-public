/* @(#)getopt.c	2.1 88/08/01 4.0 RPCSRC */

/* this is a public domain version of getopt */

// ORIGINALLY FROM https://github.com/dank101/4.4BSD-Lite2/blob/master/lib/librpc/etc/getopt.c

#ifndef GETOPT_c
#define GETOPT_c
/*LINTLIBRARY*/
#ifndef NULL
#define NULL	0
#endif NULL
#ifndef EOF
#define EOF	(-1)
#endif EOF

typedef unsigned int uint;



// #define strchr index

#include "user.h"

// TODO: stderr instead of 2 | is c char or int?
#define ERR(s, c) printf(2, "%s %d", s, c)

struct opt {
	int opterr;
	int optind;
	int optopt;
	char* optarg;
};

void optinit(struct opt* optstuct) {
	optstuct->opterr = 1;
	optstuct->optind = 1;
}

// int	opterr = 1;
// int	optind = 1;
// int	optopt;
// char	*optarg;

int
getopt(argc, argv, opts, optstuct)
int	argc;
char	**argv, *opts;
struct opt* optstuct;
{
	static int sp = 1;
	register int c;
	register char *cp;

	if(sp == 1)
		if(optstuct->optind >= argc ||
		   argv[optstuct->optind][0] != '-' || argv[optstuct->optind][1] == '\0')
			return(EOF);
		else if(strcmp(argv[optstuct->optind], "--") == NULL) {
			optstuct->optind++;
			return(EOF);
		}
	optstuct->optopt = c = argv[optstuct->optind][sp];
	if(c == ':' || (cp=strchr(opts, c)) == NULL) {
		ERR(": unknown option, -", c);
		if(argv[optstuct->optind][++sp] == '\0') {
			optstuct->optind++;
			sp = 1;
		}
		return('?');
	}
	if(*++cp == ':') {
		if(argv[optstuct->optind][sp+1] != '\0')
			optstuct->optarg = &argv[optstuct->optind++][sp+1];
		else if(++(optstuct->optind) >= argc) {
			ERR(": argument missing for -", c);
			sp = 1;
			return('?');
		} else
			optstuct->optarg = argv[optstuct->optind++];
		sp = 1;
	} else {
		if(argv[optstuct->optind][++sp] == '\0') {
			sp = 1;
			optstuct->optind++;
		}
		optstuct->optarg = NULL;
	}
	return(c);
}

#endif GETOPT_c
