#include <stdio.h>
#define MaxLength 100
#define Max 100

typedef struct
{
  char name[Max];
  char tel[Max];
  char mail[Max];
}address;
typedef address ElementType;

typedef struct
{
  ElementType Elements[MaxLength];//Store the elements
  int Front, Rear;
}Queue;

void MakeNull_Queue(Queue *Q)
{
  Q->Front=-1;
  Q->Rear=-1;
}

int Empty_Queue(Queue Q)
{
  return Q.Front==-1;
}

int Full_Queue(Queue Q)
{
  return (Q.Rear-Q.Front+1)==MaxLength;
}

void EnQueue(ElementType X,Queue *Q)
{
  if(!Full_Queue(*Q))
    {
      if (Empty_Queue(*Q))
	Q->Front=0;
      Q->Rear=Q->Rear+1;
      Q->Elements[Q->Rear]=X;
    }
  else printf("Queue is full\n");
}

ElementType DeQueue(Queue *Q)
{
  ElementType data;
  data=Q->Elements[Q->Front];
  if(!Empty_Queue(*Q))
    {
      Q->Front=Q->Front+1;
      if (Q->Front > Q->Rear)
	MakeNull_Queue(Q);// Queue trở thành rỗng
    }
  else printf("Queue is empty!\n");
  return data;
}

int main()
{
  int i;
  char str[100];
  Queue Q;
  ElementType X;
  MakeNull_Queue(&Q);
  FILE *fptr1,*fptr2;
  fptr1=fopen("danhBa.txt","r");
  fptr2=fopen("danhBaSaoChep.txt","w+");
  while(!feof(fptr1))
    {
      fgets(str,100,fptr1);
      fgets(X.name,100,fptr1);
      fgets(X.tel,100,fptr1);
      fgets(X.mail,100,fptr1);
      EnQueue(X,&Q);
    }
  i=1;
  while(!Empty_Queue(Q))
    {
      X=DeQueue(&Q);
      fprintf(fptr2,"\n%d\n",i);
      fputs(X.name,fptr2);
      fputs(X.tel,fptr2);
      fputs(X.mail,fptr2);
      i++; 
    }
  fclose(fptr2);
  fclose(fptr1);
}
