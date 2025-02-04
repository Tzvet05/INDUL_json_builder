#pragma once

/* ----- INCLUDES ----- */

#include <stdio.h>

/* ----- ENUMERATIONS ----- */

// Files
enum
{
	INFILE = 0,
	OUTFILE
};

/* ----- MACROS ----- */

#define DEFAULT_OUTFILE	"out.json"

/* ----- STRUCTURES ----- */

// File
typedef struct file
{
	char*	name;
	FILE*	stream;
}	t_file;
