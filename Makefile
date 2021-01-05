CC = gcc
FLAGS = -Wall -g

all:  txtfind isort 
	
txtfind: txtFind.c
	$(CC) $(FLAGS) txtFind.c -o txtfind

isort: iSort.c
	$(CC) $(FLAGS) iSort.c -o isort

.PHONY: clean all 

clean: 
	rm txtfind isort
