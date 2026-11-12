#include<stdio.h>
#include"comment_handler.h"
#include"macro_handler.h"
#include"file_inclusion.h"
int main(int argc,char *argv[])
{
if(argc!=2)
{
printf("usage: ./mypreprocesor input.c\n");
return 1;
}
remove_comments(argv[1],"temp.c");
file_inclusion("temp.c","temp1.c");
replace_macros("temp1.c","output.i");
printf("preprocessing completed\n");
return 0;
}

