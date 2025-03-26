##
## EPITECH PROJECT, 2025
## my_pv
## File description:
## Makefile
##

# File containing the source code
SRC = mini_pv.c

# Compile .c to .o from SRC
OBJ = $(SRC:.c=.o)

# Use main flags to detect bad practices
CFLAGS = -Wall -Wextra -Werror

# Name of the binary
NAME = mini_pv

# Compile the project with GCC and the previous rules
all:	$(OBJ)
		gcc $(CFLAGS) $(OBJ) -o $(NAME)

# Remove object files
clean:
	rm -rf $(OBJ)

# Remove object files and the executable
fclean: clean
	rm -rf $(NAME)

# Clean with the previous rules and rebuild
re: fclean all

# Clean and check for coding style errors
cs: fclean
	coding-style .
	cat coding-style-reports.log
	rm -rf coding-style-reports.log

# Rule to explain how to use Make
help:
	@echo "Available targets:"
	@echo "make            - Compile the project"
	@echo "make clean      - Remove object files"
	@echo "make fclean     - Remove object files and executable"
	@echo "make re         - Clean and rebuild"
	@echo "make help       - Show this help message"
