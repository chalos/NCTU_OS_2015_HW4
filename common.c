#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#include <common.h>

int read_n_bytes(int fp, void *dest, int num_bytes, int offset)
{
	/** OFFSET FROM BEGINING OF PARTITION WHERE THE INFO RESIDES */ 
	if (/*add your code here*/)
	{
		perror("Seek error");
		return -1;
	}
	
	/** READ BYTES */
	if (/*add your code here*/)
	{
		perror("Read error");
		return -1;
	}

	return 0;
}

int write_n_bytes(int fp, void *buf, int num_bytes, int offset) 
{
	/** OFFSET FROM BEGINING OF PARTITION WHERE THE INFO RESIDES */ 
	if (/*add your code here*/)
	{
		perror("Seek error");
		return -1;
	}

	/** WRITE BYTES */
	if (/*add your code here*/)
	{
		perror("Read error");
		return -1;
	}

	return 0;
}

void hexDump(void *source, int size, int start_offset) 
{
	int i,j;
	int start = 0 + start_offset;
	
	unsigned char *checker = (unsigned char*)malloc(size);
	memcpy(checker, source, size);
	
	/************
	 *  HEADER  *
	 ************/
	printf("address\t");
	for(i=0; i<16; i++) 
		printf("%2X ", i);
	printf(" ");
	for(i=0; i<16; i++) 
		printf("%X", i);
	printf("\n");
	
	for(i=0; i<size; i++) 
	{
		/********
		 * DATA *
		 ********/
		if(i % 16 == 0) printf("%07x\t", start+i);
		printf("%02x ", checker[i]);
		
		/********************
		 * REFERENCE VALUES *
		 ********************/
		if((i+1)% 16 == 0) 
		{
			printf("|");
			for(j=i-15; j<=i; j++) 
			{
				if(checker[j] >= 0x20 && checker[j] <= 0x7E)
					printf("%c", checker[j]);
				else 
					printf(".");
			}
			printf("|\n");
		}
	}
	
	printf("\n");
	
	free(checker);
}


void atoi_array(unsigned char *dest, char **src, int size) 
{
	int i;
	for(i=0; i<size; i++) {
		dest[i] = atoi(src[i]);
	}
}
