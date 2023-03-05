#include <stdio.h>
#include <math.h>
#define SIZE 20

int CheckifSorted(int array[],int n)
{
	if(n==1||n==0)
	{
		return 1;
	}
	
	if(array[n-2]>array[n-1])
	{
		return 0;
	}
	
	else 
	
	{
		return (CheckifSorted(array,n-1));
	}
}

void bubblesort(int array[],int size)
{
	int m,placeholder;
	
	m=CheckifSorted(array,size);
	
	while(m==0)
	{
		for(int i=0;i<size;i++)
		{
			if(array[i+1]<array[i])
			{
				placeholder=array[i];
				array[i]=array[i+1];
				array[i+1]=placeholder;
			}
		}
		m=CheckifSorted(array,size);
	}
}

int recursive_Bin_Search(int array[],int T,int L,int R)
{
	int index,m=floor((L+R)/2);
	
	if(array[m]==T)
	{
		index=m;
		return(index);
	}
	
	if(L>R)
	{
		return -1;
	}
	
	if(array[m]>T)
	{
		return(recursive_Bin_Search(array,T,L,m-1));
	}
	
	else
	{
		return(recursive_Bin_Search(array,T,m+1,R));
	}
	
}

int main()
{
	int array[SIZE]={671,200,394,489,464,958,701,482,394,42,312,489,182,257,185,957,969,72,614,42},T,index;
	
	bubblesort(array,SIZE);
	
	printf("\nThe array to be Searched is:\n");
	
	for(int i=0;i<SIZE;i++)
	{
		printf("%d ",array[i]);
	}
	
	printf("\n\nInput the target value:\n");
	
	scanf("%d",&T);
	
	index=recursive_Bin_Search(array,T,0,SIZE-1);
	
	if(index==-1)
	{
		printf("\nThe search was unsuccessful\n");
	}
	
	else
	{
		printf("\nThe target value was found in index %d of the array.\n",index);
	}
	
	return 0;
}
