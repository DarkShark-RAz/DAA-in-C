#include<stdio.h>

void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n; i++){
        int min_ind = i;
        
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_ind];
        arr[min_ind]=temp;
    }
    
    
}

int main() {
	int a[] = {2, 1, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);
	selectionSort(a, n);
	for(int i = 0;i < n; i++){
	    printf("%d ",a[i]);
	}
	return 0;
}