CC = gcc
default: Search_Engine_Project
Search_Engine_Project: search_engine.o
	$(CC) -o Search_Engine_Project search_engine.o -lm
search_engine.o: search_engine.c
	$(CC) -c search_engine.c -lm
clean: 
	$(RM) Search_Engine_Project *.o *~