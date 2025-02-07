#include <stdlib.h>
#include "indul_json_builder.h"
#include "file.h"

void	close_files(t_parr* files)
{
	size_t	i = 0;
	while (i < files->len)
	{
		if (((t_file *)files->arr)[i].stream != NULL)
			fclose(((t_file *)files->arr)[i].stream);
		i++;
	}
	free(files->arr);
}
