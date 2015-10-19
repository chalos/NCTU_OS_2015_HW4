#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#include <common.h>

int main(int argc, char **argv) 
{
	int fp, start, end, size;
	unsigned char *buffer;
	
	if(argc != 4)
	{
		perror("Usage: ./myHexDump IMAGE START OFFSET");
	}
	
	start = atoi(argv[2]) & 0xFFFFFFF0;
	end = atoi(argv[2])+atoi(argv[3]);
	end = ((end&0x0F)==0x0F)?end:(end | 0x0F);
	size = end - start + 1;
	
	buffer = (unsigned char*) malloc(size);
	if(buffer == NULL) 
	{
		perror("Error allocating memory");
		exit(-1);
	}
	
	/** OPEN the looper or images using System API */
	/** REMIND: you will need O_NONBLOCK as flag */
	if ((fp = /*add your code here*/) == -1)
	{
		perror("Error opening image");
		free(buffer);
		exit(-1);
	}
	
	if(read_n_bytes(fp, buffer, size, start) == -1)
	{
		perror("Error reading image");
		free(buffer);
		exit(-1);
	}
	
	hexDump(buffer, size, start);
	
	free(buffer);
	
	return 0;
}
