#Include "mySort.h"

void merge(int array[], int l,int m, int r)
	{
		int nL = m-l+1;
		int nR = r-m;
		int L[nL],R[nR];
		int i ,j ,k ;// i is the counter for the left array, and j is the counter for the right array

		for(i = 0;i < nL;i++){
			myCopy(&array[l+i],&L[i]);//L[i]=array[l+i];
		}

		for(j = 0;j < nL;j++){
			myCopy(&array[m+j+1],&R[j]);//R[j]=array[m+j+1];
		}

		i=0;
		j=0;
		k=l;

		while(i < nL && j < nR){

			if(myCompare(R[j],L[i])>=0){

				myCopy(&L[i],&array[k]);
				i++;

			}

			else{

				myCopy(&R[j],&array[k]);
				j++;

			}

			k++;

		}

		while(i < nL){

			myCopy(&L[i],&array[k]);
			i++;
			k++;

		}

		while(i < nR){

			myCopy(&R[i],&array[k]);
			j++;
			k++;

		}

	}

void mySort(int array[], unsigned int first, unsigned int last)
    {
		if(first<last){
			int m = first+(last-first)/2;
			mySort(array,first,m);
			mySort(array,m+1,last);
			merge(array,first,m,last);
		}
		
		else{
			return;
		}
    }
