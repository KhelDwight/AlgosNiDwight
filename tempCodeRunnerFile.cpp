#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// function to merge the sub-arrays
void merge(int a[],int low,int mid ,int high)
{
	int b[20]; //same size of a[]
	int i,j,k;
	i=low,j=mid+1,k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		    b[k++]=a[i++];
		else
		   b[k++]=a[j++]; //copying the elements 
	}
	while (i<=mid)
		b[k++]=a[i++];
	while 
		(j<=high) b[k++]=a[j++];
		for (k=low;k<=high;k++)
	        a[k]=b[k];
}

// merge sort function
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low>=high)
	  return;
	mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
}
int main()
{
    char name[10] [100], s[100];
	    int x [100];
    int i,sort;
	int enter,choice,temp,flag;
	int array[500],j,a;
int k,swap;
printf("How many times to enter?");
scanf("%d",&enter);
    
    for (i=0 ; i<enter ; i++)
    {
		printf("enter name :");
		scanf("%s",&name[i]);
		
        printf( "Enter age     :   ");
        scanf("%d",&x[i]);
        
    }

    
printf("\nSorting of algorith to use:");
printf("\n1. Bubble Sort\n2. Merge Sort\n3. Insertion Sort");
printf("\nSorting choice:");
scanf("%s",&choice);
 scanf("%1[1234]d%*c",&choice);
 	switch(choice)
    {
		case '1':
      	printf("\nBubble Sort\n");
		for(i=0;i<enter-1;i++)
    {
    	for(k=0;k<enter-i-1;k++)
    	{
    		if (x[k]>x[k+1])
    		{
    			swap=x[k];
    			x[k]=x[k+1];
    			x[k+1]=swap;
    			strcpy(s,name[k]);
            	strcpy(name[k],name[k+1]);
            	strcpy(name[k+1],s);
			}
		}
	}
	
		printf("\nNAME\tAGE \n");
	
		for(i=0;i<enter;i++)
		printf("\n%2s\t%4d",name[i], x[i]);
	break;
		
	
	case'2':
	printf("\n Merge Sort");
     mergesort(x,0,enter-1);
    
      	printf("\nNAME\tAGE \n");
	
		for(i=0;i<enter;i++)
			printf("\n%2s\t%4d",name[i], x[i]);
		
		break;
		
		case'3':
			printf("\n Insertion Sort");
    for (i = 0 ; i <= enter - 1; i++) {
    temp = x[i];
    strcpy(s,name[i]);

    for (k = i - 1 ; k >= 0; k--) {
      if (x[k] > temp) {
        x[k+1] = x[k];
        strcpy(name[k+1],name[k]);
        flag = 1;
      }
      else
        break;
    }
    if (flag)
	{
      x[k+1] = temp;
      strcpy(name[k+1],s);
	}
	}
	printf("\nNAME\tAGE \n");
	
		for(i=0; i<enter;i++)
		printf("\n%2s\t%4d",name[i], x[i]);
	break;
		
	}
}