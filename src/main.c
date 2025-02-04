#include "indul_json_builder.h"

int	main(int argc, char** argv)
{
	if (check_arguments(argc - 1, &argv[1]) == 1)
		return (1);
	t_data	data = {0};
	if (file_opening(&data, &argv[1], argc - 1) == 1)
	{
		close_files(&data.files);
		return (1);
	}
	else if (write_json_file(&data) == 1)
	{
		close_files(&data.files);
		return (1);
	}
	close_files(&data.files);
	return (0);
}
