#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"macro_handler.h"
struct macro
{
	char name[50];
	char value[100];
	char arg[20];
	int type;
};
struct macro m[50];
int count=0;
void store_macro(char *line)
{
	char *p;
	int i=0;
	p=strchr(line,' ');
		if(p==NULL)
			return;
	p++;
	while(*p==' ')
		p++;
	while(*p!=' '&&*p!='('&&*p!='\n')
	{
		m[count].name[i++]=*p;
		p++;
	}
	m[count].name[i]='\0';
	if(*p=='(')
	{
		m[count].type=1;
		p++;
		i=0;
		while(*p!=')')
			m[count].arg[i++]=*p++;
		m[count].arg[i]='\0';
		p++;
	}
	else
	{
		m[count].type=0;
	}
	while(*p==' ')
		p++;
	strcpy(m[count].value,p);
	p=strchr(m[count].value,'\n');
	if(p!=NULL)
		*p='\0';
	count++;
}
int search_macro(char *word)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(strcmp(m[i].name,word)==0)
			return i;
	}
	return -1;
}
void replace_argument(char *value,char *arg,char *actual,char *result)
{
	char *p;
	char word[50];
	int i=0;
	result[0]='\0';
	p=value;
	while(*p)
	{
		if(isalpha(*p)||*p=='_')
		{
			i=0;
			while(isalnum(*p)||*p=='_')
				word[i++]=*p++;
			word[i]='\0';
			if(strcmp(word,arg)==0)
				strcat(result,actual);
			else
				strcat(result,word);
		}
		else
		{
			i=strlen(result);
			result[i]=*p;
			result[i+1]='\0';
			p++;
		}
	}
}
void expand_line(char *line,FILE *out)
{
	char word[100];
	char actual[1000];
	char result[300];
	char *p;
	int i,j,index;
	p=line;
	while(*p)
	{
		if(isalpha(*p)||*p=='_')
		{
			i=0;
			while(isalnum(*p)||*p=='_')
                                word[i++]=*p++;
				word[i]='\0';
			index=search_macro(word);
			if(index==-1)
			{
				fputs(word,out);
			}
			else if(m[index].type==0)
			{
				fputs(m[index].value,out);
			}
			else
			{
				while(*p==' ')
					p++;
				if(*p=='(')
				{
					p++;
					j=0;
					while(*p!=')'&&*p!='\0')
						actual[j++]=*p++;
					actual[j]='\0';
					if(*p==')')
						p++;
					replace_argument(m[index].value,m[index].arg,actual,result);
					fputs(result,out);
				}
				else
				{
					fputs(word,out);
				}
			}
		}
		else
		{
			fputc(*p,out);
			p++;
		}
	}
}
void replace_macros(char *input,char *output)
{
	FILE*fp,*out;
	char line[500];
	char *p;
	count=0;
	fp=fopen(input,"r");
	if(fp==NULL)
	{
		printf("input file not found\n");
		return;
	}
	out=fopen(output,"w");
	if(out==NULL)
	{
		printf("output file errror\n");
		fclose(fp);
		return;
	}
	while(fgets(line,sizeof(line),fp))
	{
		p=line;
		while(*p==' '||*p=='\t')
			p++;
		if(strncmp(p,"#define",7)==0&&isspace((unsigned char)p[7]))
		{
			if(count<50)
				store_macro(p);
		}
		else
		{
			expand_line(line,out);
		}
	}
	fclose(fp);
	fclose(out);
	printf("macro substitution completed\n");
}



























































