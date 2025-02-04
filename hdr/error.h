#pragma once

/* ----- MACROS ----- */

// Failing functions
#define FUNC_ACCESS	"access()"
#define FUNC_FOPEN	"fopen()"
#define FUNC_FREAD	"fread()"
#define FUNC_MALLOC	"malloc()"
#define FUNC_FWRITE	"fwrite()"

// Error strings
//	Argument
#define ERROR_TOO_FEW_ARGS	"too few arguments provided (expected arguments : ./indul_json_builder [binary infile] ([json outfile]))"
#define ERROR_TOO_MANY_ARGS	"too many arguments provided (expected arguments : ./indul_json_builder [binary infile] ([json outfile]))"
//	Allocation
#define ERROR_FAILED_ALLOC	"failed memory allocation"
//	File
#define ERROR_FILE_NONEXISTANT	"file does not exist"
#define ERROR_READ_PERM		"file permissions prohibit reading"
#define ERROR_WRITE_PERM	"file permissions prohibit writing"
#define ERROR_OPEN_FILE		"failed to open file"
#define ERROR_READ_FILE		"failed to read file"
#define ERROR_WRITE_FILE	"failed to write to file"
