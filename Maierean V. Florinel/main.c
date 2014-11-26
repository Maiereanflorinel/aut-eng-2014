#include <stdio.h>
#include <stdlib.h>
#define infinity 999

//Implementation of Dijkstra's algorithm
void dijkstra(int n,int v,int cost[10][10],int dist[])
{
    int i,u,count,w,flag[10],min;
    for(i=1; i<=n; i++)
        flag[i]=0,dist[i]=cost[v][i];
    count=2;
    while(count<=n)
    {
        min=99;
        for(w=1; w<=n; w++)
            if(dist[w]<min && !flag[w])
                min=dist[w],u=w;
        flag[u]=1;
        count++;
        for(w=1; w<=n; w++)
            if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
                dist[w]=dist[u]+cost[u][w];
    }
}

void main()
{
    int n,v,i,j,cost[10][10],dist[10];

    printf("\n Enter the number of nodes:");
    scanf("%d",&n);
    printf("\n Enter the cost matrix:\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=infinity;
        }
    printf("\n Enter the source matrix:");
    scanf("%d",&v);
    dijkstra(n,v,cost,dist);
    printf("\n Shortest path:\n");
    for(i=1; i<=n; i++)
        if(i!=v)
            printf("%d->%d,cost=%d\n",v,i,dist[i]);
}



//Implementation of Floyd's Algorithm
/*
int min(int,int);
void floyds(int p[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    if(i==j)
     p[i][j]=0;
    else
     p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
}
int min(int a,int b)
{
 if(a<b)
  return(a);
 else
  return(b);
}

void main()
{
 int p[10][10],w,n,e,u,v,i,j;;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 printf("\n Enter the number of edges:\n");
 scanf("%d",&e);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   p[i][j]=999;
 }
 for(i=1;i<=e;i++)
 {
  printf("\n Enter the end vertices of edge %d with it's weight \n",i);
  scanf("%d%d%d",&u,&v,&w);
  p[u][v]=w;
 }
 printf("\n Matrix :\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }
 floyds(p,n);
 printf("\n Transitive closure:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",p[i][j]);
  printf("\n");
 }
 printf("\n The shortest paths are:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   if(i!=j)
    printf("\n <%d,%d>=%d",i,j,p[i][j]);
  }

}*/
//Implementation of Prim
/*
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
void main()
{
 printf("\n Enter the number of nodes:");
 scanf("%d",&n);
 printf("\n Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 visited[1]=1;
 printf("\n");
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
   for(j=1;j<=n;j++)
    if(cost[i][j]<min)
     if(visited[i]!=0)
     {
      min=cost[i][j];
      a=u=i;
      b=v=j;
     }
  if(visited[u]==0 || visited[v]==0)
  {
   printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
   mincost+=min;
   visited[b]=1;
  }
  cost[a][b]=cost[b][a]=999;
 }
 printf("\n Minimun cost=%d",mincost);
}*/
