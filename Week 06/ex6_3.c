#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define Max 100
#define MaxDanhBa 100
#define SoLuong 10

typedef struct DanhBa
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;

int search(address r[],int n,char *key)
{
  int i,j;
  address tempr;
  for(i=0;i<n;i++)
    if(strcmp(key,r[i].name)==0)
      {
	if(i>0)
	  {
	    tempr=r[i];
	    for(j=0;j<i;j++)
	      r[j+1]=r[j];
	    r[0]=tempr;
	  }
	return i;
      }
    return -1;
}


int main()
{
  address danhBa[MaxDanhBa];
  int i;
  int ViTri;
  char str[Max],ten[Max];
  FILE *fptr;
  fptr=fopen("danhBa.txt","r");
  for(i=0;i<SoLuong;i++)
    {
      fgets(str,100,fptr);
      fgets(danhBa[i].name,100,fptr);
      danhBa[i].name[strlen(danhBa[i].name)-1]='\0';
      printf("\n%d:%s\n",i,danhBa[i].name);
      fgets(danhBa[i].tel,100,fptr);
      danhBa[i].tel[strlen(danhBa[i].tel)-1]='\0';
      fgets(danhBa[i].mail,100,fptr);
      danhBa[i].mail[strlen(danhBa[i].mail)-1]='\0';
    }
  printf("Ban muon tim ten nao:");
  __fpurge(stdin);
  gets(ten);
  //printf("%s:%ld\n",ten,strlen(ten));
  __fpurge(stdin);
  ViTri=search(danhBa,SoLuong,ten);
  printf("%d\n",ViTri);
  if(ViTri==-1)
    printf("Khong co ten nay\n");
  else
    {
      printf("%s\n",danhBa[0].name);
      printf("%s\n",danhBa[0].tel);
      printf("%s\n",danhBa[0].mail);
    }
  fclose(fptr);
}
