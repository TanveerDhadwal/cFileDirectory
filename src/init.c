#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


#define DISC_SPACE (2 * 1024 * 1024)
bool allocateBlocks(FILE *F);


int main(){
	FILE * fptr;
	if ((fptr = fopen("daFileSystemBinary.bin", "wb+")) == NULL) {
		printf("da disk failed: electric boogaloo \n");
	}	
	allocateBlocks(fptr);








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
	printf("file has been written");
	return true;



}
