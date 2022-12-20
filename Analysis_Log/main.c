#include<stdio.h>
#include <string.h>

#define FILENAME "log.txt"
#define MAXLENGTHFILE 5000

char filestr[MAXLENGTHFILE];

int fileToSTR(char* str)
{
	int status;
	FILE *fp = NULL;

	fp = fopen(FILENAME, "r");

	if (fp == NULL)
	{
		printf("File does not exist\n");
		return -1;
	}
	status = fread(str, MAXLENGTHFILE, 1, fp);

	fclose(fp);
	fp = NULL;
	return status;
}


void cau1(char* str)
{
	int sobantin = 0;
	FILE *fp = NULL;

	fp = fopen(FILENAME, "r");

	while(1)
	{
		char w[300];
		if (fgets(w, 300, fp) == NULL)
		{
			break;
		}
		if (strstr(w, "\"cmd\":\"set\"" ) != NULL)
		{
			sobantin++;
			printf("%s", w);
		}
	}

	fclose(fp);
	fp = NULL;

	printf("So ban tin: %d\n", sobantin);
}

void cau2()
{
	char input[50];
	gets(input);
	int i = 0;
	while (i < 50) 
	{
		input[i] = tolower(input[i]);
		i ++;
	}
	printf("%s", input);
	int sobantin_guidi = 0;
	FILE *fp = NULL;

	fp = fopen(FILENAME, "r");

	while(1)
	{
		char w[300];
		if (fgets(w, 300, fp) == NULL)
		{
			break;
		}
		if (strstr(w, "\"cmd\":\"set\"") != NULL && strstr(w, input) != NULL)
		{
			sobantin_guidi++;
			printf("%s", w);
		}
	}

	fclose(fp);
	fp = NULL;
	printf("So ban tin gui di la: %d\n", sobantin_guidi);
}

int main()
{
	fileToSTR(filestr);
	cau1(filestr);
	cau2(filestr);
	return 0;
}