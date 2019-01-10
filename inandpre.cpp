/*Assignment-9*/
/*Program to construct a binary tree given Inorder and Postorder traversals*/

#include<stdio.h>
#include<stdlib.h>
typedef struct btnode
{
	char info;
	struct btnode *lchild,*rchild;
}BTNODE;
typedef struct node
{
	char info;
	struct node *next;
}NODE;
NODE *insert_at_end(NODE *head,char item)
{
	NODE *q=head;
	NODE *p=(NODE *)malloc(sizeof(NODE));
	if(q==NULL)
		{
			p->info=item;
			p->next=NULL;
			return p;
		}
	while(q->next!=NULL)
	{
		q=q->next;
	}
	p->info=item;
	p->next=NULL;
	q->next=p;
	return head;
}
BTNODE *construct(NODE *inptr,NODE *postptr,int num)
{
	BTNODE *temp;
	NODE *q;
	int i,j;
	if(num==0)
		return NULL;
	temp=(BTNODE *)malloc(sizeof(BTNODE));
	temp->info=postptr->info;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(num==0)
		return NULL;
	q=inptr;
	for(i=0;q->info!=postptr->info;i++)
		q=q->next;
	temp->lchild=construct(inptr,postptr->next,i);
	for(j=1;j<=i+1;j++)
		postptr=postptr->next;
	temp->rchild=construct(q->next,postptr,num-i-1);
	return temp;
}
void preorder(BTNODE *root)
{
	if(root!=NULL)
	{
		printf("%c ",root->info);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
NODE *reverse(NODE *head)
{
	NODE *p=NULL,*q=head,*r;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	return p;
}
int main()
{
	NODE *inorder=NULL;
	NODE *postorder=NULL;
	BTNODE *head=NULL;
	int n,i;
	char item;
	printf("Enter total number of elements in the tree :");
	scanf("%d",&n);
	printf("\nEnter Inorder traversal elements :");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&item);
		inorder=insert_at_end(inorder,item);
	}
	printf("\nEnter Postorder traversal elements :");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&item);
		postorder=insert_at_end(postorder,item);
	}
	postorder=reverse(postorder);
	head=construct(inorder,postorder,n);
	printf("\nThe preorder traversal of constructed tree is :");
	preorder(head);
	printf("\n");
	return 0;
}

