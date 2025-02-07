#include <unistd.h>
#include "indul_json_builder.h"
#include "file.h"
#include "error.h"

static bool	check_files_access(int n_files, char** file_names)
{
	if (access(file_names[INFILE], F_OK) != 0)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_ACCESS,
			ERROR_FILE_NONEXISTANT, file_names[INFILE]);
		return (1);
	}
	else if (access(file_names[INFILE], R_OK) != 0)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_ACCESS,
			ERROR_READ_PERM, file_names[INFILE]);
		return (1);
	}
	else if (n_files == 2 && access(file_names[OUTFILE], F_OK) != 0)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_ACCESS,
			ERROR_FILE_NONEXISTANT, file_names[OUTFILE]);
		return (1);
	}
	else if (n_files == 2 && access(file_names[OUTFILE], W_OK) != 0)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_ACCESS,
			ERROR_WRITE_PERM, file_names[OUTFILE]);
		return (1);
	}
	else
		return (0);
}

bool	check_arguments(int n_files, char** file_names)
{
	if (n_files < 1)
	{
		fprintf(stderr, "%s: %s\n", EXECUTABLE_NAME, ERROR_TOO_FEW_ARGS);
		return (1);
	}
	else if (n_files > 2)
	{
		fprintf(stderr, "%s: %s\n", EXECUTABLE_NAME, ERROR_TOO_MANY_ARGS);
		return (1);
	}
	else
		return (check_files_access(n_files, file_names));
}
