# Make parameters

NAME =		indul_json_builder

COMPILER =	clang

CFLAG =		-Wall -Wextra -Werror

# Directories

HDR_DIR =	hdr/
SRC_DIR =	src/
OBJ_DIR =	obj/

# Colors

COLOR_DEFAULT =		\033[0m
COLOR_GREEN =		\033[1;38;5;2m
COLOR_BLUE =		\033[1;38;5;4m
COLOR_WHITE =		\033[1;38;5;15m

# Source code

SRC =	main.c \
	check_arguments.c \
	file_opening.c \
	write_json_file.c \
	free_data.c

# Compiled objects

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Compilation

$(NAME) : $(OBJ)
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_GREEN)Executable ($(NAME)) compiled.$(COLOR_DEFAULT)"
	@ $(COMPILER) $(CFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@ $(COMPILER) $(CFLAG) -I $(HDR_DIR) -c $^ -o $@

# Build directories

$(OBJ_DIR) :
	@ mkdir -p $@

# Rules

all : $(NAME)

fclean :
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_BLUE)Objects cleaned.$(COLOR_DEFAULT)"
	@ rm -rf $(OBJ_DIR)
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_BLUE)Executable ($(NAME)) cleaned.$(COLOR_DEFAULT)"
	@ rm -f $(NAME)

clean :
	@ echo "$(COLOR_WHITE)[$(NAME)] - $(COLOR_BLUE)Objects cleaned.$(COLOR_DEFAULT)"
	@ rm -rf $(OBJ_DIR)

re : fclean all

.PHONY : all fclean clean re
