#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"file_inclusion.h"
void copy_header(FILE *header,FILE *out)
{
	char ch;
	while((ch=fgetc(header))!=EOF)
	{
		fputc(ch,out);
	}
	fclose(header);
}
void file_inclusion(char *input,char *output)
{
	FILE *fp,*out, *header;
	char line[500];
	char filename[100];
	char *p,*q;
	fp=fopen(input,"r");
	if(fp==NULL)
	{
		printf("input file not found\n");
		return;
	}
	out=fopen(output,"w");
	if(out==NULL)
	{
		printf("output file error\n");
		fclose(fp);
		return;
	}
	while(fgets(line,sizeof(line),fp))
	{
		p=line;
		while(isspace((unsigned char)*p))
			p++;
		if(strncmp(p,"#include",8)==0)
		{
			p=strchr(p,'"');
			if(p!=NULL)
			{
				p++;
				q=strchr(p,'"');
				if(q!=NULL)
				{
					*q='\0';
					strcpy(filename,p);
                                        printf("header filename:%s\n",filename);
					header=fopen(filename,"r");
					if(header!=NULL)
					{
						copy_header(header,out);
					}
					else
					{
						printf("header file not found:%s\n",filename);
					}
					continue;
				}
			}
		}
		fputs(line,out);
	}
	fclose(fp);
	fclose(out);
	printf("file inclusion completed\n");
}


