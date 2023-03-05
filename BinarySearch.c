#include <stdio.h>
#include <math.h>
#define SIZE 20

int CheckifSorted(int array[],int n)
{
	if(n==0||n==1)
	{
		return 1;
	}
	
	if(array[n-1]<array[n-2])
	{
		return 0;
	}
	
	return(CheckifSorted(array,n-1));
}

int selectsort(int array[],int size,int k)
{
	int min,placeholder,index_of_min,m;
	
	min=array[k];
	
	index_of_min=k;
	
	for(int i=k+1;i<size;i++)
	{
		if(array[i]<min)
		{
			min=array[i];
			index_of_min=i;
		}
		
	}
	
	if(index_of_min!=k)
	{
	placeholder=array[k];
	
	array[k]=min;
	
	array[index_of_min]=placeholder;
	}
	
	m=CheckifSorted(array,size);
	
	if(m==0)
	{
		return (selectsort(array,size,k+1));
	}
	
		else 
		
			{
				return 1;
			}
}

int Binary_Srch(int array[],int T)
{
	int m,L=0,R=SIZE-1;
	
	while(L<=R)
	{
		m=floor((R+L)/2);
		
		if(array[m]>T)
		{
			R=m-1;
		}
		
		if(array[m]<T)
		{
			L=m+1;
		}
		
		if(array[m]==T)
		{
			return(m);
		}
	}
	
	return -1;
	
}

int main()
{
	int array[SIZE]={671,200,394,489,464,958,701,482,394,42,312,489,182,257,185,957,969,72,614,42},T,index;
	
	selectsort(array,SIZE,0);
	
	printf("\nThe array to be Searched is:\n");
	
	for(int i=0;i<SIZE;i++)
	{
		printf("%d ",array[i]);
	}
	
	printf("\n\nInput the target value:\n");
	
	scanf("%d",&T);
	
	index=Binary_Srch(array,T);
	
	if(index==-1)
	{
		printf("\nThe Search was unsuccessful\n");
	}
	
	else
	{
		printf("\nThe target value was found in index %d of the array.\n",index);
	}
	
	return 0;
}
