#include <stdio.h>
#include <string.h>
#include "indul_json_builder.h"
#include "json_constant.h"
#include "file.h"
#include "error.h"

static bool	write_json_file_constant(t_file* file, char* buffer)
{
	fwrite(buffer, sizeof(*buffer), strlen(buffer), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	return (0);
}

static char*	my_itoa(uint32_t n)
{
	static char	buffer[11];
	uint32_t	tmp = n;
	size_t	i = 0;
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	buffer[i + 1] = '\0';
	while (n >= 10)
	{
		buffer[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	buffer[i] = n + '0';
	return (buffer);
}

static bool	write_json_instruction(t_file* file, uint32_t instruction, size_t entity_number)
{
	fwrite(JSON_FILE_ENTITY_NUMBER, sizeof(char), strlen(JSON_FILE_ENTITY_NUMBER),
		file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	char*	buffer = my_itoa(entity_number);
	fwrite(buffer, sizeof(*buffer), strlen(buffer), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	fwrite(JSON_FILE_ENTITY_POS_Y, sizeof(char), strlen(JSON_FILE_ENTITY_POS_Y), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	buffer = my_itoa(entity_number);
	fwrite(buffer, sizeof(*buffer), strlen(buffer), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	fwrite(JSON_FILE_ENTITY_COUNT, sizeof(char), strlen(JSON_FILE_ENTITY_COUNT), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	buffer = my_itoa(instruction);
	fwrite(buffer, sizeof(*buffer), strlen(buffer), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	fwrite(JSON_FILE_ENTITY_TAIL, sizeof(char), strlen(JSON_FILE_ENTITY_TAIL), file->stream);
	if (ferror(file->stream) == 1)
	{
		fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FWRITE,
			ERROR_WRITE_FILE, file->name);
		return (1);
	}
	return (0);
}

bool	write_json_file(t_data* data)
{
	if (write_json_file_constant(&((t_file *)data->files.arr)[OUTFILE], JSON_FILE_HEAD) == 1)
		return (1);
	size_t	entity_number = 0;
	uint32_t	buffer = 0;
	while (1)
	{
		fread(&buffer, sizeof(buffer), 1, ((t_file *)data->files.arr)[INFILE].stream);
		if (ferror(((t_file *)data->files.arr)[INFILE].stream) == 1)
		{
			fprintf(stderr, "%s: %s: %s: \"%s\"\n", EXECUTABLE_NAME, FUNC_FREAD,
				ERROR_READ_FILE, ((t_file *)data->files.arr)[INFILE].name);
			return (1);
		}
		else if (feof(((t_file *)data->files.arr)[INFILE].stream) == 1)
			break;
		if (entity_number > 0
			&& write_json_file_constant(&((t_file *)data->files.arr)[OUTFILE], ",") == 1)
			return (1);
		if (write_json_instruction(&((t_file *)data->files.arr)[OUTFILE], buffer,
			(uint32_t)entity_number) == 1)
			return (1);
		entity_number++;
	}
	return (write_json_file_constant(&((t_file *)data->files.arr)[OUTFILE], JSON_FILE_TAIL));
}
