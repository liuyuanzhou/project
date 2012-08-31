#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE *fp = NULL;
	if(access("trace.txt",F_OK) == -1)
	{
		printf("trace.txt does not exist,need to create!\n");
		fp = fopen("trace.txt","w+");
	}
	else
	{
		printf("trace.txt already exists!\n");
		fp = fopen("trace.txt","a");
	}
	fputs("first add string!\n",fp);
	fclose(fp);
	return 1;
}
