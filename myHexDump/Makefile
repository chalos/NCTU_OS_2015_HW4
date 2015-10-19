
CC = gcc

CFLAGS = -lm -I../include/ -DPARTITION_START=2048*512 -Wall

# gdb
CFLAGS += -g

OUTPUT = myHexDump
OBJ	=	common	\
		myHexDump

$(OUTPUT): $(addsuffix .o, $(OBJ))
	mkdir -p ../out/
	$(CC) -o ../out/$@ $^ $(CFLAGS)

%.o: ../%.c 
	$(CC) -c -o $@ $< $(CFLAGS)
	
clean:
	rm -f *.o
	rm -f ../*.o
	rm -r ../out/

cleanobj:
	rm *.o
