#include<stdio.h>
#include<conio.h>
#define n 4

int q[20],visited[20],i,j,f=0,r=-1;
void bfs(int v, int a[n][n]) {
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++], a);
	}
}
void main() {
    int a[n][n] = {{0,1,1,0},
             {1,0,0,1},
             {1,0,0,1},
             {0,1,1,0}};

	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}

    int sv = 1;
	bfs(sv,a);
	printf("\n The node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(visited[i])
	   printf("%d\t",i); else
	   printf("\n Bfs is not possible");
	getch();
}