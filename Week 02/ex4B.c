#include <stdio.h>
#include <string.h>

int main(int argc,char*argv[])
{
  FILE *fptr1;
  char str[200];
  fptr1=fopen(argv[1],"r");
  while(!feof(fptr1))
    {
      fread(str,sizeof(char),100,fptr1);
      printf("%ld\n",strlen(str));
      str[strlen(str)+1]='\0';
      printf("%s",str);
    }
  printf("\n");
  fclose(fptr1);
}
