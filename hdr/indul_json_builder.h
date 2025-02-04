#pragma once

/* ----- INCLUDES ----- */

#include <stdbool.h>
#include <stdint.h>
#include "parr.h"

/* ----- STRUCTURES ----- */

// Generic data storage
typedef struct data
{
	t_parr	files;
}	t_data;

/* ----- MACROS ----- */

// Executable name
#define EXECUTABLE_NAME	"indul_json_builder"

/* ----- PROTOTYPES ----- */

// check_arguments.c
bool	check_arguments(int argc, char** argv);

// file_opening.c
bool	file_opening(t_data* data, char** file_names, int n_files);

// write_json_file.c
bool	write_json_file(t_data* data);

// free_data.c
void	close_files(t_parr* files);
