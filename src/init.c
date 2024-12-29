#include <stdio.h>

#define DISC_SPACE (2 * 1024 * 1024)
int main(){
	FILE * fptr;
	int x[] = {1,2,3}; 
	if ((fptr = fopen("daFileSystemBinary.bin", "wb+")) == NULL) {
		printf("da disk failed: electric boogaloo \n");
	}	
	fwrite(x, sizeof(int), 3, fptr);
	fclose(fptr);

}
/*
boolean allocateBlocks(){


}*/
