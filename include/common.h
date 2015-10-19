#pragma once

int read_n_bytes(int fp, void *dest, int offset, int num_bytes);
int write_n_bytes(int fp, void *buf, int offset, int num_bytes);
void hexDump(void *source, int size, int start_offset);
void atoi_array(unsigned char *dest, char **src, int size);
