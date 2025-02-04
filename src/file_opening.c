#include <stdlib.h>
#include "indul_json_builder.h"
#include "file.h"
#include "error.h"

bool	file_opening(t_data* data, char** file_names, int n_files)
{
	data->files.len = 2;
	data->files.arr = malloc(data->files.len * sizeof(t_file));
	if (data->files.arr == NULL)
	{
		data->files.len = 0;
		fprintf(stderr, "%s: %s: %s\n", EXECUTABLE_NAME, FUNC_MALLOC, ERROR_FAILED_ALLOC);
		return (1);
	}
	((t_file *)data->files.arr)[INFILE].name = file_names[INFILE];
	if (n_files == 2)
		((t_file *)data->files.arr)[OUTFILE].name = file_names[OUTFILE];
	else
		((t_file *)data->files.arr)[OUTFILE].name = DEFAULT_OUTFILE;
	((t_file *)data->files.arr)[INFILE].stream =
		fopen(((t_file *)data->files.arr)[INFILE].name, "r");
	((t_file *)data->files.arr)[OUTFILE].stream =
		fopen(((t_file *)data->files.arr)[OUTFILE].name, "w");
	if (((t_file *)data->files.arr)[INFILE].stream == NULL)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FOPEN,
			ERROR_OPEN_FILE, ((t_file *)data->files.arr)[INFILE].name);
		return (1);
	}
	else if (((t_file *)data->files.arr)[OUTFILE].stream == NULL)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FOPEN,
			ERROR_OPEN_FILE, ((t_file *)data->files.arr)[OUTFILE].name);
		return (1);
	}
	else
		return (0);
}
