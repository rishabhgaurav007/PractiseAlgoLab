#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int bt[1001]={0},x,y,max=0,count=0,flag=5;
	int i,a;
	printf("Enter\n1.to insert\n2.to delete\n3.to count the number of nodes\n4.to count the number of leaf nodes\n");
	printf("5.to count the number of non-leaf nodes\n6.to get the height of the binary tree\n7.to check whether the tree is a strictly binary tree or not\n");
	while(1){
		printf("You choose: ");
		scanf("%d",&x);
		switch(x){
			case 1:		//to insert
				printf("Enter the location of node: ");
				scanf("%d",&i);
				printf("Enter the info: ");
				scanf("%d",&y);
				bt[i] = y;
				if(max < i)
					max = i;
				break;
			case 2:		//to delete
				printf("Enter the info you want to delete: ");
				scanf("%d",&y);
				printf("Enter the location: ");
				scanf("%d",&i);
				if(bt[i] == y)
					 bt[i] = 0;
				else
					printf("Wrong Input.\n");
				if(i == max)
					max--;
				break;
			case 3:		//to count the number of nodes
				for(a=1;a<=max;a++){
					if(bt[a] != 0)
						count++;
					else
						continue;
				}
				printf("Number of nodes: %d.\n",count);
				count = 0;
				break;
			case 4:		//to count the number of leaf nodes
				for(a=1;a<=max;a++){
					if(bt[a] != 0 && bt[2*a] == 0 && bt[2*a + 1] == 0)
						count++;
					else
						continue;
				}
				printf("Number of leaf nodes: %d.\n",count);
				count = 0;
				break;
			case 5:		//to count the number of non-leaf nodes
				for(a=1;a<=max;a++){
					if(bt[a] != 0 && bt[2*a] != 0 || bt[2*a + 1] != 0)
						count++;
					else
						continue;
				}
				printf("Number of non-leaf nodes: %d.\n",count);
				count=0;
				break;
			case 6:		//to get the height of the binary tree
				count = log2(max);
				printf("The height of the Binary Tree is %d\n",count);
				break;
			case 7: 	//to check whether the tree is a strictly binary tree or not
				for(a=1;a<=max;a++){
					if(bt[a] != 0){
						if((bt[2*a] == 0 && bt[2*a + 1] == 0)||(bt[2*a] != 0 && bt[2*a + 1] != 0)){
							continue;
						}
					}
					else{
						printf("NO\n");
						flag = 10;
						break;
					}
				}
				if(flag == 5)
					printf("YES\n");
				break;
			default :
				printf("Thank You\n");
		}
		if(x >= 8)
			break;
	}
	return 0;
}

