#include "mySort.h"

void mySort(int array[], unsigned int first,unsigned int last)
    {
		
		int key,j;

		for(int i=first+1;i <= last;i++){

			key=array[i];
			j = i-1;
			
			while(j>=0 && myCompare(array[j],key) > 0){
			
				myCopy(&array[j],&array[j+1]);
				j--;

			}
			myCopy(&key,&array[j+1]);
			
		}
    }


