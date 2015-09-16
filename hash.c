/* This program was written by Ossama Samir Ahmed
**This program hashes the input 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Global variables
char sentence[100];

//function prototypes
int hash(int);
//Main function
int main(void)
{
	//local variables
	int key=0;
	int hashNumber=0;
	printf("Please enter a sentence that doesn't exceed 100 characters:\n");
	scanf("%s",sentence);
	printf("Please enter a hash key to be used in hashing\n");
	scanf("%d",&key);
	hashNumber=hash(key);
	printf("The hashed number for this sentence will be: %d \n",hashNumber);
	return 0;
}

//Hash function
int hash(int key)
{
	int i=0;
	int hashNumber=0;
	while(sentence[i]!= '\0' && i!=100 )
	{
		hashNumber=hashNumber+sentence[i];
		i++;
	}
	int power=hashNumber;
	for(i=1;i<key;i++)
	{
		power=power*hashNumber;
	}
	return power;
}