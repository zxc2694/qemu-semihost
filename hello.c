#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h> 
#include <time.h>

#define range 42

int main(void)
{
	FILE * fd ;
	int a[10], r[10];
	char i,j;
	int sum;
	srand(time(NULL));

	printf("\n");
	printf("This is a lottery game by semihost system\n");
	printf("Select six number (rang: 0 ~ 42 ):\n");
	printf("Please key in  your number:\n");
	
	fd = fopen("My_lottery.txt","a");  
	fprintf(fd ,"=================================\n\n");
	fprintf(fd ,"This is your number:\n");
	for(i=0;i<6;i++)
	{
		scanf("%d" ,&a[i]);
		fprintf(fd , "%d  ",a[i]);
	}
	fprintf(fd ,"\n\n");
	for(i=0;i<6;i++)
	{
		r[i]=rand()%range+1; 
	}
	fprintf(fd ,"This is random number:\n");
	for(i=0;i<6;i++)
	{
		fprintf(fd ,"%d  ",r[i]);
	}
	for(j=0;j<6;j++)
	{
		for(i=0;i<6;i++)
		{
			if(r[j]==a[i])
			sum=sum+1;
		}
	}
	fprintf(fd ,"\n\n");
	if(sum>0)
	{
		printf("Luckly! you win lottery in %d number...\n\n",sum);
		fprintf(fd,"Luckly! you win lottery in %d number...\n\n",sum);
	}
	else
	{
		printf("Oh! you are unfortunate...");
		fprintf(fd,"Oh! you are unfortunate...");
	}
	fprintf(fd ,"\n\n");
	return 0;

}



