#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
//#include <ncurses.h>
//structure to represent an object of set
typedef struct{
               int value;
               struct rep *repptr;  //struct node is given to identify for compiler because rep is declared below
               struct node *next;
              }node;
              
              
//structure to represent header node              
typedef struct{
               node *head;
               node *tail;
              }rep; 
 
//structure to represent key and set representative                           
typedef struct{
               int key;
               rep *repptr;
               struct nodaddr *next;
               }nodaddr;
       
nodaddr *ndr=0; //list to store keys and set representative

void main()
{
void makeset();
rep *find(int );
void unionset(int ,int );
makeset(10);
makeset(20);
makeset(30);
makeset(40);
printf("find(10)=%x\n",find(10));
printf("find(20)=%x\n",find(20));
printf("find(30)=%x\n",find(30));
printf("find(40)=%x\n",find(40));
unionset(10,20);
printf("After union of 10 and 20 find(20)=%x\n",find(20));
unionset(30,40);
printf("After union of 30 and 40 find(40)=%x\n",find(40));
unionset(20,40);
printf("After union of 20 and 40 find(40)=%x\n",find(40));

//getche();
}

//function to create a set for an object
void makeset(int a)
{
//create a set reference
nodaddr *t=(nodaddr *)malloc(sizeof(nodaddr));
//create a new set
rep *newset=(rep *)malloc(sizeof(rep));
//initialise head and tail
newset->head=(node *)malloc(sizeof(node));//newset->head=(node *)malloc(sizeof(rep));
newset->tail=newset->head;
//fill values
newset->head->value=a;
newset->head->repptr=newset;
newset->head->next=0;

//to store set representative pointer and key in linked
t->repptr=newset;
t->key=a;
t->next=ndr;
ndr=t;

}


//function to return pointer of the set representaive
//of the set containing x

rep *find(int x)
{
nodaddr *t=ndr;
while(t!=0 && t->key!=x)
   t=t->next;
return t->repptr;   
}

//to find union of two sets corresponding to objective given
void unionset(int key1,int key2)
{
rep *set1,*set2;
nodaddr *t=ndr;
node *t1;
set1=find(key1);
set2=find(key2);
//change the representative pointer of set containing key2
//to that of key1
while(t!=0)
{
  if(t->repptr==set2)
     t->repptr=set1;//making set representatives same 
  t=t->next;   
}
//changing the header pointer of objects of set2 to set1
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;
set1->tail=set2->tail;
free(set2);
}


                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
