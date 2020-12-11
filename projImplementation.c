//#include <string.h>
//#include <stdbool.h>
//#include<stdio.h>
#include "projHeader.h"
//#include<stdlib.h>
/*
 * projImplementation.c
 *
 *  Created on: May 1, 2018
 *      Author: Kevin Williams
 */

int krgetline(char s [],int lim)
{
	char c;
	int i;

	for(i = 0; i<lim-1 &&(c=getchar())!= EOF && c!='\n'; i++)
	{
		s[i]=c;
		if(c=='\n')

		{
			s[i]=c;
			i++;
		}
	}
	s[i]='\0';
	return i;

}

bool mystrcmp(char s[],char t[])
{
	for(int i=0; s[i]==t[i];i++)
		if(!s[i])
			return true;
	return false;
}

int mystrlen(char s[])
{
	int count =0;
	while(s[count]!='\0')
	{
		count++;
	}
	return count;
}


int parseint(char s[])
{
	int i =0;
	int total = 0;
	while(s[i]!='\0')
	{
		total = 10*total + (s[i]-'0');
		i++;
	}
	return total;
}

bool isnumeric(char s[])
{
	int i = 0;
	while(s[i])
	{
		//printf("\nchar in isnumeric %c", s[i]);
		//fflush(stdout);
		if((s[i]<'0')||(s[i]>'9'))
		{
			return false;
		}
		i++;
	}
	return true;
}

