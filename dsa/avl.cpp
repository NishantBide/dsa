/*
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data sorted
in ascending/ Descending order. Also find how many maximum comparisons may require for
finding any keyword. Use Binary Search Tree for implementation.
*************************************************************************************************/

#include<iostream>	//header file 
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node	//node structure
{
	char data[10];
	char mean[10];
	struct node *left,*right;
	int height;
}node;

node *root,*newnode,*p;

void insert(node *root,node *newnode);
void create()		//create function
{	
	char w[20],m[20],z;
	do
	{
		newnode=(struct node*)malloc(sizeof(struct node));	
		cout<<"Enter word and meaning"<<endl;
		cin>>w>>m;
		strcpy(newnode->data,w);
		strcpy(newnode->mean,m);
		newnode->left=NULL;
		newnode->right=NULL;	
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			insert(root,newnode);
		}
		cout<<"Do you want to add more(y/n)"<<endl;
		cin>>z;
	}while(z!='n');
}


node *LL(node *root);
node *LR(node *root);
node *RR(node *root);
node *RL(node *root);

int ht(node *root)		//function for finding height
{
	int lh,rh;
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->height;
		if(root->right==NULL)
		rh=0;
		else
		rh=1+root->right->height;
	return(lh-rh);
}
void insert(node *root,node *temp)	//inserting value into node
{
	if(strcmp(newnode->data,root->data)<0)                //left subtree
	{
		if(root->left==NULL)
			root->left=newnode;
	  	else
		{
	   		insert(root->left,newnode);
			if(ht(root)==2)
			{	
				if(strcmp(newnode->data,root->left->data)<0)
					root=LL(root);
				else
					root=LR(root);
			}
		}	
	}
	else
	{
		 if(root->right == NULL)                     //right subtree
		 	root->right = newnode;
		 else
	   		insert(root->right,newnode);
			if(ht(root)==-2)
			{
				if(strcmp(newnode->data,root->right->data)>0)
					root=RR(root);
				else
					root=RL(root);
			}
 	}
}

node *rotateleft(node *newnode)	//rotate left
{
	node *y;
	y=newnode->right;
	newnode->right=y->left;
	y->left=newnode;
	newnode->height=ht(newnode);
	y->height=ht(y);
	return(y);
}

node *rotateright(node *newnode)	//rotate right
{
	node *y;
	y=newnode->left;
	newnode->left=y->right;
	y->right=newnode;
	newnode->height=ht(newnode);
	y->height=ht(y);
	return(y);
}

node *LL(node *root)	//left of left
{
	root=rotateleft(root);
	return(root);	
}

node *LR(node *root)	//right of left
{
	root->left=rotateleft(root->left);
	root=rotateright(root);
	return(root);
}

node *RR(node *root)	//right of right
{
	root=rotateright(root);
	return(root);
}

node *RL(node *root)	//left of right
{
	root->right=rotateright(root->right);
	root=rotateleft(root);
	return(root);
}

void display(node *root)	//display tree
{
	if(root!=NULL)	//inorder recursive
 	{
		display(root->left);
		cout<<"\n Key Word :"<<root->data;
		cout<<"\t Meaning :"<<root->mean;
		display(root->right);
	}
}

int search(node *root,char k[10])	//searching in tree
{
	int c=0;
	while(root!=NULL)
 	{
		c++;
  		if(strcmp(k,root->data)==0)
  		{
   			cout<<"\nNo of Comparisons:"<<c;
			return 1;
		}
		if(strcmp(k,root->data)<0)
 	 		root = root->left;
 		if(strcmp(k,root->data)>0)
 	  		root=root->right;
 	}
}	

int update(node *root,char k[20])	//update meaning
{
	while(root!=NULL)
 	{
		if(strcmp(k,root->data)==0)
	    	{		
			cout<<"\nEnter New Meaning of Keyword"<<root->data;
		       	cin>>root->mean;
		 	return 1;
	     	}	
	   	if(strcmp(k,root->data)<0)
	        	root=root->left;
	   	if(strcmp(k,root->data)>0)
	        	root=root->right;
	}
	 return 0;
}

node *min(node *p)	//find minimum
{
	while(p->left!=NULL)
	{
		p=p->left;
		return p;
	}
}
node *del(node *root,char k[20])	//function for deleting root
{
	node *temp;
	if(root==NULL)
	{
		cout<<"\nElement Not Found";
		return root;
	}

 	if(strcmp(k,root->data)<0)
	{	
		root->left=del(root->left,k);
	  	return root;
	}
	if(strcmp(k,root->data)>0)
	{
	  	root->right = del(root->right,k);
	  	return root;
	}	

	if(root->right==NULL&&root->left==NULL)	
	{
	  	temp=root;
	  	free(temp);
	  	return NULL;
	}
 	if(root->right==NULL)			//delete left node
	{
	  	temp=root;
	  	root=root->left;
	  	free(temp);
	  	return root;
	}
	else if(root->left==NULL)		//delete right node
	{
	 	temp=root;
	  	root=root->right;
	 	free(temp);
	  	return root;
	}
	
	temp=min(root->right);         //delete node with two childs
	strcpy(root->data,temp->data);
	root->right=del(root->right,temp->data);
	return root;
	
}

int main()		//main function
{
	char k[20],z;
	int ch;
	do
	{
		cout<<"1.Create a tree\n2.Search a keyword\n3.Update the meaning of keyword\n4.Delete a keyword\n5.Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				create();
				break;
			}
	
			case 2:
			{
				cout<<"Enter word to be searched"<<endl;
				cin>>k;
				search(root,k);
				if(search(root,k)==1)
				cout<<"word found"<<endl;
				else
				cout<<"word not found"<<endl;
				break;
			}
		
			case 3:
			{
				cout<<"Enter word which is to be updated"<<endl;
				cin>>k;
				update(root,k);
				break;			
			}
	
			case 4:
			{
				
				cout<<"Enter word which is to be deleted"<<endl;
				cin>>k;
				del(root,k);
			}
			case 5:
			{
				display(root);
				break;
			}
		}
	cout<<endl;
	cout<<"Do you want to continue(y/n)"<<endl;
	cin>>z;
	}while(z!='n');
}