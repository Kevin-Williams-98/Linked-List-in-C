#include "Node.h"
#include "projHeader.h"



/*
 * projMain.c
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 */
//void f1(int x)
//	{
//		printf("inside f1, val of x is %i\n",x);
//	}
//
//float avg(int num, ...)
//{
//	va_list va;
//	float sum = 0.0;
//	va_start(va,num);
//
//	for(int i =0;i<num;i++)
//	{
//		sum+= va_arg(va,num);
//	}
//
//	va_end(va);
//
//	return sum/num;
//}
//
#include <stdarg.h>


//    //struct Node *name1;
//
//    //name1.data= "abc";
//
//
//
//
////	//char *s;
////	strcpy(s,"hello");
////
////	s = malloc(sizeof(char)*10);
////
////	free(s);
////
////	//s = strdup("hello");
////	//free(s);
//
//
//
//int x= 10;
//int y=9;
//float f = 19.89;
//
////printf("hello %")
//
//
//printf("world %f\n",avg(2,9,6));
//printf("world %f\n",avg(2,9,6));


	int main(int argc, char* argv[])
	{
		//this is for reading input file
		struct node *headq = NULL;
		struct node *heads = NULL;
		char s[3] = " \n";
		char *token;
		int count = 0;
		int ncount = 0;
		int numlines = 0;
		int d = 0;

		for(int i = 0; i < argc - 1; i++)
		{
			if(mystrcmp(argv[i], "-f"))//this is to see if -f is there and then read the text file
				count = i;
			if(mystrcmp(argv[i], "-n"))//this is to tell if -n is there and get how many lines by adding 1
				ncount = i;
			if(mystrcmp(argv[i], "-d"))//this is to tell if -d is there
				d = i;
		}
		if(mystrcmp(argv[count], "-f") == true)
		{
			char buff[80];
			FILE *fp = fopen(argv[count + 1],"r");
			if(ncount != 0)
			{
				while((fgets(buff, 80, fp) != NULL) &&  numlines < atoi(argv[ncount + 1]))
				{
					token = strtok(strdup(buff),s);
					while(token != NULL)
					{
						headq = enqueue(headq, token);
						heads = push(heads, token);
						token = strtok(NULL, s);
					}
					numlines++;
				}
			}
			else{
				while((fgets(buff, 80, fp) != NULL))
				{
					token = strtok(strdup(buff),s);
					while(token != NULL)
					{
						headq = enqueue(headq, token);
						heads = push(heads, token);
						token = strtok(NULL, s);
					}
				}
			}
		}
		else
		{
			char buff[80];
			if(ncount != 0){
				while(numlines < atoi(argv[ncount + 1]) && (fgets(buff, 80, stdin) != NULL))
				{
					token = strtok(strdup(buff),s);
					while(token != NULL)
					{
						headq = enqueue(headq, token);
						heads = push(heads, token);
						token = strtok(NULL, s);
					}
					numlines++;
				}
			}
			else{
				while((fgets(buff, 80, stdin) != NULL))
				{
					token = strtok(strdup(buff),s);
					while(token != NULL)
					{
						headq = enqueue(headq, token);
						heads = push(heads, token);
						token = strtok(NULL, s);
					}
				}
			}
		}
		if(d != 0)
		{
			printf("This is the queue list: \n");
			printlist(headq);
			printf("This is the stack list: \n");
			printlist(heads);
			heads = deletenode(heads, argv[d + 1]);
			headq = deletenode(headq, argv[d + 1]);
		}

		printf("This is the queue list: \n");
		printlist(headq);
		printf("This is the stack list: \n");
		printlist(heads);
		heads = deletelist(heads);
		headq = deletelist(headq);
		printf("This is the queue list after deletion: \n");
		printlist(headq);
		printf("This is the stack list after deletion: \n");
		printlist(heads);
		if(heads == NULL)
			printf("headq is null\n");
		if(headq == NULL)
			printf("headq is null");

//
   return 0;

}
