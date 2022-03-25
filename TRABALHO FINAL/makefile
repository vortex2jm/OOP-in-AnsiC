NAME_PROGRAM = final.exe
CC = gcc
FLAGS = -lm -pedantic -Wall 
C_FILES = $(wildcard *.c)
O_FILES = $(patsubst %.c, %.o, $(C_FILES))

all: $(O_FILES) create_executable

main.o: main.c
	@ echo "\033[1;33m"
	@ echo "Compiling main.c ..."
	@ $(CC) -c $< $(FLAGS)
	@ echo "\033[0m"

%.o: %.c %.h
	@ echo "\033[1;33m"
	@ echo "Compiling $< ..."
	@ $(CC) -c $< $(FLAGS)
	@ echo "\033[0m"

create_executable: 
	@ echo "\033[1;36m"
	@ echo "Creating executable..."
	@ $(CC) -o $(NAME_PROGRAM) $(O_FILES)
	@ echo "\033[0m"

run: 
	@ echo "\033[1;32m"
	@ echo "Running program ..."
	@ echo "\033[0m"
	@ ./$(NAME_PROGRAM)

outf:
	@ echo "\033[1;32m"
	@ echo "Running program & sending output to file..."
	@ echo "\033[0m"
	@ ./$(NAME_PROGRAM)>output.txt

test: clean all run

valgrind: 
	@ echo "\033[1;36m"
	@ echo "Running valgrind ..."
	@ echo "\033[0m"
	@ valgrind ./$(NAME_PROGRAM)

clean: 
	@ echo "\033[1;31m"
	@ echo "Removing temporary files ..."
	@ rm -rf $(NAME_PROGRAM) $(O_FILES) *.txt
	@ clear
	@ echo "\033[0m"