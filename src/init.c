#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "bitmap.h"

#define DISC_SPACE (2 * 1024 * 1024)
bool allocateBlocks(FILE *F);


int main(){
	FILE * fptr;
	if ((fptr = fopen("daFileSystemBinary.bin", "wb+")) == NULL) {
		printf("da disk failed: electric boogaloo \n");
	}	
	if(!allocateBlocks(fptr)){
		printf("failed to allocate blocks \nterminating program \n");
		return -1;
	}
	initalizeBitMap(fptr);









	fclose(fptr);

}
bool allocateBlocks(FILE *F){
	size_t offset = 512;
	fseek(F, offset, SEEK_SET);
	uint16_t sentinel = 0xBEEF;
	fwrite(&sentinel, sizeof(uint16_t), 1, F);
	offset = 400;
	fseek(F, offset, SEEK_CUR);
	fwrite(&sentinel, sizeof(uint16_t), 1, F);
	offset = 65536;
	fseek(F, offset, SEEK_CUR);
	fwrite(&sentinel, sizeof(uint16_t), 1, F);
	//subtracting those values since cur_seek pointer is positioned at the end of 
	//inode table + the size of the int as well so - 8 more
	fseek(F, DISC_SPACE - 65536 - 512 - 400 - 8, SEEK_CUR);
	fwrite(&sentinel, sizeof(uint16_t),1,F);
	printf("file has been written \n");
	return true;
}
