#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *link;
};
struct stack *top=0;
void push(int x)
{
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
}

void display()
{
	system("cls");
	struct stack *temp;
	temp=top;
	if(temp==0)
	{
		printf("List is empty\n");
	}
	else{
		while(temp!=0)
		{
			printf("The list is  %d\n",temp->data);
			temp=temp->link;
		}
	}
}

void pop()
{
	struct stack *temp;
	temp=top;
	if(top==0)
	{
		printf("The list is empty");
	}
	else{
		top=temp->link;
		free(temp);
	}
}

void peek()
{
	if(top==0)
	{
		printf("Stack is empty");
	}
	else{
		printf("Top element is %d",top->data);
	}
}
void main()
{
	int choice,n;
	int opt=1;
	while(opt)
		{
			system("cls");
	printf("Choose any one of the given option;\n");
	printf("1.Push\n2.Pop\n3.display\n4.Peek\n5.Exit");
	printf("\nEnter you choice	");
	scanf("%d",&choice);
	switch(choice)
	{
		
		case 1:
			system("cls");
			printf("Enter the value you want to push into the stack\n");
			scanf("%d",&n);
			push(n);
			break;
			
		case 2:
			system("cls");
			pop();
			break;
			
		case 3:
			system("cls");
			display();
			break;
			
		case 4:
			system("cls");
			peek();
			break;
		case 5:
			return 0;
		default:
			printf("Enter the valid choice");
	}
	system("pause");
}
}
