#include<stdio.h>
 
struct bit//defining structure for bit operation
{
unsigned char x:1;
} ;

int u[]={1,2,3,4,5,6,7,8,9},size=9;

void main()
{
void setcreate(struct bit[],int);
void setdisplay(struct bit[]);
void setunion(struct bit[],struct bit[],struct bit[]);
void setinter(struct bit[],struct bit[],struct bit[]);
void setdif(struct bit[],struct bit[],struct bit[]);
int x,y;
//assigining zeros to all 9 positions of 3 sets
struct bit a[9]={0};
struct bit b[9]={0};
struct bit c[9]={0};
printf("enter the size of first set\n");
scanf("%d",&x);
printf("enter %d elements for first set\n ",x);
setcreate(a,x);
printf("enter the size of second set\n");
scanf("%d",&y);
printf("enter %d elements for second set\n ",x);
setcreate(b,y);
printf("the union of sets is:\n");
setunion(a,b,c);
printf("the intersection of sets is:\n");
setinter(a,b,c);
printf("difference of sets is:\n");
setdif(a,b,c);
}

//function to create  a set
void setcreate(struct bit a[],int m)
{
int j,i,k,d;
   for(i=0;i<m;i++)
   {
    scanf("%d",&d);
    for(j=0;j<size;j++)
      {
       if(d==u[j])//checking whether that element belongs to universal set
       {
         a[j].x=1;//assiging 1 to corresponding poition of set
         break;
         }
      }                    
   } 
}


void setdisplay(struct bit a[])
{
int j,i,k,d;
   printf("{ ");
    for(j=0;j<size;j++)
      {
       if(a[j].x==(unsigned char)1)//print the value in universal set corresponds to each 1 in sets
       printf("%d,",u[j]);
         
      }
      printf(" }\n");
return;                          
}

      
void setunion(struct bit a[],struct bit b[], struct bit c[])
{
int i,k;
     for(i=0;i<size;i++)
     {
     c[i].x=a[i].x | b[i].x;//performing bitwise OR operation bw 2 sets

     }
setdisplay(c);
return;
}



void setinter(struct bit a[],struct bit b[], struct bit c[])
{
int i,k;
     for(i=0;i<size;i++)
     {
     c[i].x=a[i].x & b[i].x;//performing bitwise AND operation bw 2 sets

     }
setdisplay(c);
return;
}


void setdif(struct bit a[],struct bit b[], struct bit c[])
{

int i,k;
     for(i=0;i<size;i++)
     {
     c[i].x=a[i].x & !(b[i].x);//performing bitwise and with a and complement of b

     }
setdisplay(c);
}






























