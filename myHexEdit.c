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
	int fp, start, size;
	unsigned char *buffer;
	
	if(argc < 4)
	{
		perror("Usage: ./myHexEdit IMAGE START HEX_VALUE1 [HEX_VALUE2 ..]");
		exit(-1);
	}
	
	start = atoi(argv[2]);
	size = argc - 3;
	
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
	
	atoi_array(buffer, argv+3, size);
	
	if(write_n_bytes(fp, buffer, size, start) == -1)
	{
		perror("Error writing image");
		free(buffer);
		exit(-1);
	}
	
	free(buffer);
	
	return 0;
}
