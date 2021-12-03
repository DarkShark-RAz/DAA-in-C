#include <stdio.h>
#include <math.h>

struct node
{
    int weight,value;
    double ratio;
};

void heapify(struct node arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2;
	if (l < n && arr[l].ratio > arr[largest].ratio) 
		largest = l; 

	if (r < n && arr[r].ratio > arr[largest].ratio) 
		largest = r; 

	if (largest != i) 
	{ 
        struct node temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp; 
		heapify(arr, n, largest); 
	} 
} 

void buildheap(struct node arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);
}
void heapSort(struct node arr[], int n) 
{  
	buildheap(arr,n); 

	for (int i=n-1; i>0; i--) 
	{ 
        struct node temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp; 
		heapify(arr, i, 0); 
	} 
} 

int main(){

    struct node arr[100];
    int n, capacity;
    scanf("%d %d",&n,&capacity);
    double tot = 0.0;

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i].weight);
    }
    
        for(int i = 0; i < n; i++){
        scanf("%d",&arr[i].value);
        arr[i].ratio = (double)arr[i].value/arr[i].weight;
    }
    
    heapSort(arr,n);

    for(int i = n-1; n>=0; i--){
        if(arr[i].weight <= capacity){
            capacity-= arr[i].weight;
            tot+= arr[i].value;
        }
		else
		{
			tot += capacity * arr[i].ratio;
            break;
		}
    }
    printf("%.2lf\n",tot);
    return 0;
}

