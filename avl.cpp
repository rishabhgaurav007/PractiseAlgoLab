#include<stdio.h>
#include<stdlib.h>
typedef struct avl{
	struct avl *left,*right;
	int info,height;
}AVL;
int height(AVL *N){
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b){
	return (a > b)? a : b;
}
AVL *rightRotate(AVL *y){
	AVL *x=y->left;
	AVL *temp=x->right;
	x->right=y;
	y->left=temp;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}
AVL *leftRotate(AVL *x){
	AVL *y=x->right;
	AVL *temp=y->left;
	y->left=x;
	x->right=temp;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return y;
}
AVL *newnode(int key){
	AVL *p=(AVL *)malloc(sizeof(AVL));
	p->left=NULL;
	p->right=NULL;
	p->height=1;
	p->info=key;
	return p;
}
int balance_factor(AVL *node){
	if(node==NULL)
		return 0;
	return height(node->left)-height(node->right);
}
AVL *inorder_successor(AVL *root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}
AVL *insert(AVL *root,int key){
	int bf;
	if(root==NULL)
		return(newnode(key));
	if(key<root->info)
		root->left=insert(root->left,key);
	else if(key>root->info)
		root->right=insert(root->right,key);
	else
		return root; //Equal keys are not allowed in BST
	root->height=1+max(height(root->left),height(root->right));
	bf=balance_factor(root);
	if(bf>1 && key<root->left->info)
		return rightRotate(root); //LL case
	if(bf<-1 && key>root->right->info)
		return leftRotate(root); //RR case
	if(bf >1 && key>root->left->info){
		root->left=leftRotate(root->left);
		return rightRotate(root); //LR case
	}
	if(bf<-1 && key<root->right->info){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
AVL * delete(AVL *root,int key){
	int bf;
	if(root==NULL){
		return NULL;
	}
	else if(key<root->info)
		root->left=delete(root->left,key);
	else if(key>root->info)
		root->right=delete(root->right,key);
	else{
		if(root->left==NULL){
			AVL *temp=root->right;
			root=temp;
			free(temp);
		}
		else if(root->right==NULL){
			AVL *temp=root->left;
			root=temp;
			free(temp);
		}
/*if( (root->left == NULL) || (root->right == NULL) ){
		AVL *temp = root->left ? root->left : root->right;

// No child case
		if (temp == NULL){
			temp = root;
			root = NULL;
		}
		else // One child case
			*root = *temp;
 // Copy the contents of
// the non-empty child
		free(temp);
} */
else
{
AVL *temp=inorder_successor(root->right);
root->info=temp->info;
root->right=delete(root->right,temp->info);
}
}

if(root==NULL)
return root;
root->height=1+max(height(root->left),height(root->right));
bf=balance_factor(root);
if(bf>1 && balance_factor(root->left)>=0)
return rightRotate(root); //LL case
if(bf>1 && balance_factor(root->left)<0)
{
root->left=leftRotate(root->left);
return rightRotate(root); //LR case
}
if(bf<-1 && balance_factor(root->right)<=0)
return leftRotate(root); //RR case
if(bf<-1 && balance_factor(root->right)>0)
{
root->right=rightRotate(root->right);
return leftRotate(root);
}
return root;
}
void preOrder(AVL *root)
{
if(root != NULL)
{
printf("%d ", root->info);
preOrder(root->left);
preOrder(root->right);
}
}
void main()
{
AVL *root=NULL;
int option,item;
printf("1.Insert a node into AVL Tree");
printf("\n2.Delete a node from the AVL Tree");

printf("\n3.Display the preorder traversal");
printf("\n4.Exit");
while(1)
{
printf("\nEnter Your option :");
scanf("%d",&option);
switch(option)
{
case 1 :
printf("\nEnter the No. you want to insert :");
scanf("%d",&item);
root=insert(root,item);
break;
case 2 :
printf("\nEnter the No. to be deleted :");
scanf("%d",&item);
root=delete(root,item);
break;
case 3 :
printf("\nPreorder Traversal of AVL tree :");
preOrder(root);
break;
case 4 :
		exit(1);
		}
	}
}

