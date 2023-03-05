#include <stdio.h>

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

int main()
{
	int size;
	
	printf("\nInput the size of the array:\n");
	
	scanf("%d",&size);
	
	int array[size];
	
	for(int i=0;i<size;i++)
	{
		printf("\nInput element number %d of the array:  ",i);
		scanf("%d",&array[i]);
	}
	
	printf("\nThe unsorted array is as follows:\n");
	
	for(int j=0;j<size;j++)
	{
		printf("%d ",array[j]);
	}
	
	printf("\n");
	
	bubblesort(array,size);
	
	printf("\n");
	
	printf("\nThe sorted array is as follows:\n");
	
	for(int k=0;k<size;k++)
	{
		printf("%d ",array[k]);
	}
	
	return 0;
}

