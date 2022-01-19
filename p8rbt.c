#include<stdio.h>
#include<stdlib.h>


struct node
{
int key;
char color;
struct node *par;
struct node *left;
struct node *right;
};

void main()
{
struct node* left_rotate(struct node*,struct node*);
struct node* right_rotate(struct node*,struct node*);
struct node* rbinsert_fixup(struct node*,struct node*);
struct node* rb_insert(struct node*,struct node*);
void inorder(struct node*);
struct node *t=0,*z,*k1,*k2;
int i,n,key;
printf("Enter number of elements to insert:\n");
scanf("%d",&n);
printf("Enter numbers:");
for(i=0;i<n;i++)
{
scanf("%d",&key);
z=(struct node*)malloc(sizeof(struct node));
z->key=key;
t=rb_insert(t,z);
}
//clrscr();
printf("SORTED RB TREE ELEMENTS:");
printf("\n");
inorder(t);
//printf("\n");
//k2=t->left;
//t=left_rotate(t,k2);
//printf("\n");
//inorder(t);
/*k2=t->left;
t=right_rotate(t,k2);
printf("\n");
inorder(t);
*/

}

//rotating node left
//root may change so need to return new root
//hence return type as struct node

struct node* left_rotate(struct node  *t,struct node *x)
{
struct node *y=x->right;
x->right=y->left; //left subtree of y is assigned as right subtree of x
if(y->left!=NULL)//case of left sub tree of y exists
 {
 y->left->par=x;
 }
y->par=x->par;
if(x->par==NULL)//case of x is root node
  t=y;
else if(x==x->par->right)//to check whether x is left child or right child of its parent
  x->par->right=y;
else
  x->par->left=y;
       
y->left=x;//making parent child relation between x and y
x->par=y;
return t; //returning new root
}

//function for right rotation
struct node* right_rotate(struct node*t,struct node*x)
{
struct node* y=x->left;//making y as left subtree of x
x->left=y->right;
if(y->right!=NULL)//cse of right of y is not null
  y->right->par=x;
y->par=x->par;
if(x->par==NULL)//if x is root node
 t=y;
else if(x==x->par->left)//x is left child or right child of its parent
  x->par->left=y;
else
  x->par->right=y;
y->right=x;//making x as right child of x and parent x as y
x->par=y;
return t;//returning new root
} 

//function for fixing nodes and colors
struct node* rbinsert_fixup(struct node *t,struct node *z)
{
struct node *y;
//if(z!=t){//sample1//CORRECTION HERE BY HOD
while(z->par!=NULL && z->par->color=='R')//newly inserted node and its parent are same color//sample2
{
   if(z->par==z->par->par->left)//parent of new node is left child of its grand parent
   {
    y=z->par->par->right;//setting y as right child of grand parent
      //CORRECTION HERE BY HOD
      if(y!=NULL && y->color=='R')//case of uncle y red
      {
       z->par->color='B';
       y->color='B';
       z->par->par->color='R';
       z=z->par->par;
       //if(z==)
      }
      
      
      else
      {
       if(z==z->par->right)//case of uncle y black and newnode is right child of its parent
       {
        z=z->par; //newnode and its parent interchanging roles
        t=left_rotate(t,z);
       }
        z->par->color='B';
        z->par->par->color='R';
        t=right_rotate(t,z->par->par);
      
      }
    }
    else //case of parent of new node is right child of grand parent
    {
      y=z->par->par->left;//making y as left child of its grandparent
      if(y->color=='R')//case of uncle y red
      {
       z->par->color='B';
       y->color='B';
       z->par->par->color='R';
       
       z=z->par->par;
      }
      else
      { 
        if(z==z->par->left)//case of uncle y black and new node is left child of its parent
        {
          z=z->par;//newnode and its parent interchanging roles
          t=right_rotate(t,z);
        }
        z->par->color='B';
        z->par->par->color='R';
        t=left_rotate(t,z->par->par);
        
      }
    }
}//end of while
//}
t->color='B';
return t;
} //end of fixup
      
      
//to insert a node z in rb tree t

struct node* rb_insert(struct node *t,struct node *z)
{
struct node *y=0,*x;
x=t; 
while(x!=0)//loop to find the position to insert
{
  y=x;
  if(z->key<x->key)
     x=x->left;
  else
     x=x->right;
        
}
//y will be the parent of new node to insert
z->par=y;
if(y==NULL)//case of empty tree
  t=z;
  //t->par->color='B';}//sample1
else if(z->key<y->key)//checking whether left or right
   y->left=z;
else
   y->right=z;
      
//making left and right of new node null
//making color of newnode as red      
z->left=NULL;
z->right=NULL;
z->color='R';
//FIXING NODES AND THEIR COLORS
t=rbinsert_fixup(t,z);
return t;
        
}//end of rb_insert

//function  to traverse tree

void inorder(struct node *x)
{
if(x!=NULL)
{
 inorder(x->left);
 printf("%d(%c)",x->key,x->color);
 inorder(x->right);
}
}       






























