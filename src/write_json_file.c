#include <stdio.h>
#include "indul_json_builder.h"
#include "file.h"
#include "error.h"

bool	write_json_file(t_data* data)
{
	uint32_t	buffer;
	while (1)
	{
		fread(&buffer, 1, sizeof(uint32_t), ((t_file *)data->files.arr)[INFILE].stream);
		if (ferror(((t_file *)data->files.arr)[INFILE].stream) == 1)
		{
			fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FREAD,
				ERROR_READ_FILE, ((t_file *)data->files.arr)[INFILE].name);
			return (1);
		}
		else if (feof(((t_file *)data->files.arr)[INFILE].stream) == 1)
			return (0);
		;// write instr to json
	}
	return (0);
}
