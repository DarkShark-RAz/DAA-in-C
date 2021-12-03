#include<stdio.h>
#include<conio.h>
#define n 4

int reach[20];
void dfs(int v, int a[n][n]) {
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v - 1][i - 1] && !reach[i]) {
		printf("\n %d->%d",v,i);
		dfs(i,a);
	}
}
void main() {
	int i,j,count=0;
    int a[n][n] = {{0,1,1,0},
                    {1,0,0,1},
                    {1,0,0,1},
                    {0,1,1,0}};
	dfs(1,a);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
	if(count==n)
	  printf("\n Graph is connected"); else
	  printf("\n Graph is not connected");
	getch();
}