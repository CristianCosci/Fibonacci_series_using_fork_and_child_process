CC = gcc
CFLAGS = -Werror -Wall -pedantic 
OBJ = fibonacci.o 

.PHONY : clean

%.o : %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

fibonacci : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

main : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean : 
	@ echo "rimozione file compilati"
	@ rm *.o
	@ if [ -e fibonacci ]; then rm fibonacci; fi
	@ if [ -e main ]; then rm main; fi
