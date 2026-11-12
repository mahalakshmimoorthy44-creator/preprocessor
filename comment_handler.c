#include<stdio.h>
#include"comment_handler.h"
void remove_comments(char *input,char *output)
{
	FILE *fp,*out;
	int ch,next;
	int flag=0;
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
	while((ch=fgetc(fp))!=EOF)
	{
		if(flag==0)
		{
			if(ch=='/')
			{
				next=fgetc(fp);
				if(next=='/')
				{
					flag=1;
				}
				else if(next=='*')
				{
					flag=2;
				}
				else
                                {
                                fputc(ch,out);
				if(next!=EOF)
					ungetc(next,fp);
			}
		} 
		else
		{
			fputc(ch,out);
		}
	}
	else if(flag==1)
	{
		if(ch=='\n')
		{
			fputc('\n',out);
			flag=0;
		}
	}
	else if(flag==2)
	{
		if(ch=='*')
		{
			next=fgetc(fp);
			if(next=='/')
			{
				flag=0;
			}
			else if(next!=EOF)
			{
				ungetc(next,fp);
			}
		}
	}
	}
	fclose(fp);
	fclose(out);
	printf("commemnt removed successfully\n");
}

