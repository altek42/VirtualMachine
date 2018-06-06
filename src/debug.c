#include "../include/debug.h"

void showMemory(Memory* mem){
	size_t i;
	size_t width=0;
	size_t height=0;
	printf("\nOffset(h)    ");
	for(width=0;width<16;width++){
		printf("%02X  ", width);
	}
	printf("\n");

	width=0;
	// %#010x
	for(i=0;i<mem->PCS;i++){
		if(width==0){
			printf("\n %08X    ", height);
			height+=0x1;
		}
		width+=1;
		if(width>=16){
			width=0;
		}
		printf("%02X  ", mem->bytecode[i]);
	}
}
