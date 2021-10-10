#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int count=0,i=1;
struct node *head, *temp,*newnode;
void create()
{
	head=0;
	int choice=1;
	while(choice)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:	");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		printf("Do you want to continue (0/1)");
		scanf("%d",&choice);
		count++;
	}
}
void display()
{
	temp=head;
	while(temp!=0)
	{
		printf("The data is %d \n",temp->data);
		temp=temp->next;
	}
}

void addatbeg()
{
	struct node *temp;
	temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data you need to add at the beginning");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
	count++;
}

void addatend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:\t");
	scanf("%d",&newnode->data);
	newnode->next=0;
	temp=head;
	while(temp->next!=0)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	count++;
}

void addatpos()
{
	int pos,i=1;
	temp=head;
	printf("Enter the position where you have to add the data:	");
	scanf("%d",&pos);
	if(count<pos)
	{
		printf("Invalid position:");
	}
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data you want to add at specified position:	");
		scanf("%d",&newnode->data);
		newnode->next=temp->next;
		temp->next=newnode;
		count++;
	}
}

void deleteatbeg()
{
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
	count--;
}

void deleteatend()
{
	struct node *temp,*prevnode;
	temp=head;
	while(temp->next!=0)
	{
		prevnode=temp;
		temp=temp->next;
	}
	if(temp==head)
	{
		head=0;
	}
	else{
		prevnode->next=0;
	}
	free(temp);
	count--;
	
}

void deleteatpos()
{
	int pos;
	struct node *nextnode,*temp;
	temp=head;
	printf("Enter the position:	");
	scanf("%d",&pos);
	if(pos>count)
	{
		printf("Invalid position");
	}
	else
	{
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		nextnode=temp->next;
		temp->next=nextnode->next;
		free(nextnode);
		count--;
	}
}

void reverse()
{
	struct node *prevnode,*nextnode,*currentnode;
	nextnode=currentnode=head;
	while(nextnode!=0)
	{
	nextnode=nextnode->next;
	currentnode->next=prevnode;
	prevnode=currentnode;
	currentnode=nextnode;
	}
		head=prevnode;
}
void count()
{
	printf("%d/n",count);
}
void main()
{
	while(1)
	{
	system("cls");
	int option;
	printf("1.Create\n2.Display\n3.Add\n4.Delete\n5.Reverse\n6.Length of the linked list");
	printf("\nEnter Your choice:\t");
	scanf("%d",&option);
	switch(option){
		case 1:
				
			create();
			break;
		case 2:
			system("cls");
			display();
			break;
		case 3:
			system("cls");
			int a;
			printf("1.Add at the Beggining\n2.Add at the end.\n3.Add at particular position.");
			scanf("%d",&a);
			switch(a)
			{
				case 1:
					system("cls");
					addatbeg();
					break;
					
				case 2:
					system("cls");
					addatend();
					break;
					
				case 3:
					system("cls");
					addatpos();
					break;
			}
			break;
		case 4:
			system("cls");
			int b;
			printf("1.Delete at the Beggining\n2.Delete at the end.\n3.Delete at particular position.");
			scanf("%d",&b);
			switch(b)
			{
				case 1:
					system("cls");
					deleteatbeg();
					break;
					
				case 2:
					system("cls");
					deleteatend();
					break;
					
				case 3:
					system("cls");
					deleteatpos();
					break;
			}
			break;
		case 5:
			system("cls");
			reverse();
			break;
			
		case 6:
			system("cls");
			count();
			break;
}
	system("pause");
}
}
