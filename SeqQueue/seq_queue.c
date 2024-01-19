#include"seq_queue.h"

void init_queue(seq_queue* q)
{
	q->base=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	assert(q!=NULL);
	q->front=q->rear=0;
	q->size=0;
}

void show_queue(seq_queue* q)
{
	for(int i=0;i<q->size;i++)
		printf("%d->",q->base[i]);
	printf("rear\n");
}

void en_queue(seq_queue* q,ElemType x)
{
	if(q->rear>=MAXSIZE)
	{
		printf("cant en_queue.\n");
		return ;
	}
	q->base[q->rear]=x;
	q->rear++;
	q->size++;
}

void de_queue(seq_queue* q)
{
	if(q->rear==q->front)
	{
		printf("cant de_queue.\n");
		return ;	
	}
	q->front++;
	q->size--;
}

int length(seq_queue* q)
{
	return q->size;
}


void get_head(seq_queue* q,ElemType* x)
{
	if(q->front==q->rear)
	{
		printf("cant get head.\n");
		return ;
	}
	*x=q->base[q->front];
}


void clear_queue(seq_queue* q)
{
	q->front=q->rear=0;
	q->size=0;
}


void destory_queue(seq_queue* q)
{
	clear_queue(q);
	free(q->base);
	q->base=NULL;
	q->size=0;
}
