#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>




void* align_malloc(int size,int n);

void aligned_free(void* ptr);

int main()
{
 /* ?\n;||(or) e &&(and)*/



	char* ptr = (char*)align_malloc(1000,4);
	if((int)ptr % 4 == 0){
		printf("%d\n",ptr);
	}
	aligned_free(ptr);

 return 0;
}


void* align_malloc(int size,int n){

	void* ptr;
	while(1){
		ptr = malloc(sizeof(void) * size);
		if((int)ptr % n != 0){
			aligned_free(ptr);
			continue;
		}
		break;
	}
	return ptr;
}


void aligned_free(void *ptr){
	free(ptr);
}
