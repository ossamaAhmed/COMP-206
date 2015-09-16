/* This program was written by Ossama Samir Ahmed
**This program is an improvment over Ceaser's method by taking 3 keys instead of 1
*/
#include <stdio.h>
#include <stdlib.h>
//Global variables
char sentence[100];
//function prototypes
void blockCeasarFunction(int, int, int);
int checkCase(char);
//main function
int main(void)
{
	//local variables
	int firstKey=0;
	int secondKey=0;
	int thirdKey=0;
	printf("Please enter a sentence that doesn't exceed 100 characters:\n");
	fgets(sentence,100,stdin);
	printf("Please enter three integers to ceasar your text\n");
	scanf("%d %d %d",&firstKey,&secondKey,&thirdKey);
	printf("Done");
	blockCeasarFunction(firstKey,secondKey,thirdKey);
	printf("Then the cyphered text is: %s \n",sentence);
	return 0;
}
void blockCeasarFunction(int x,int y,int z)
{
	int i=0;
	int temp=0;
	while(sentence[i]!='\0')
	{
		temp=checkCase((sentence[i]));
		if((i%3) == 0 && temp !=0)
		{
			sentence[i]=sentence[i]+x;
		}
		else if((i%3)==1 && temp !=0)
		{
			sentence[i]=sentence[i]+y;
		}
		else if((i%3)==2 && temp !=0)
		{
			sentence[i]=sentence[i]+z;
		}
		if(sentence[i]>90 && temp ==2)
		{
			sentence[i]=((sentence[i])%90)+64;
		}
		else if(sentence[i]<65 && temp ==2)
		{
			sentence[i]=91-((65-sentence[i])%65);
		}
		else if(sentence[i]>122 && temp ==1)
		{
			sentence[i]=((sentence[i])%122)+96;
		}
		else if(sentence[i]<97 && temp ==1)
		{
			sentence[i]=123-((97-sentence[i])%97);
		}
		i++;
	}	
}
//checks the case of the letter passed to it and returns 0 if it's not a letter
int checkCase(char x)
{
	if(x>96 && x< 123)
	{
		return 1;
	}
	else if(x >64 && x< 91)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}