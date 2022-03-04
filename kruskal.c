#include<stdio.h>
int n,ne=1, u,v,min=999,mincost=0,ru,rv,i,j;
int p[9],cost[9][9];
//find the set reference
int find(int u)
{
while(p[u])
u=p[u];
return u;

}
//union of 2 sets
void uni(int ru,int rv)
{
p[rv]=ru;

}


void main()
{

printf("\nenter the number of nodes\n");
scanf("%d",&n);
printf("\nenter the adjacency cost matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)//if no edge implies weight infinite
cost[i][j]=999;
}
}
printf("the mincost spannning tree\n");
while(ne<n)
{
min=999;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(cost[i][j]<min)
{
min=cost[i][j];
u=i;
v=j;
}
}
}
ru=find(u);
rv=find(v);
if(ru!=rv)
{
uni(ru,rv);
printf("%d edge(%d %d):%d\n",ne++,u,v,min);
mincost=mincost+min;
}
cost[u][v]=cost[v][u]=999;
}
printf("\nmincost=%d\n",mincost);
}
