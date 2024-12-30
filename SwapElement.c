#include <stdio.h>

void swap_elements(int *arr, int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int main(){
    int n,arr[100],pos1,pos2;
    printf("Enter the number of elements (max 100): ");
    scanf("%d",&n);

    if (n<0 || n>100) {
    printf("Error: Number of elements must be between 0 and 100.\n");
    return 1;
    }

    printf("Enter %d numbers: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter first position to swap (0-%d): ",n-1);
    scanf("%d",&pos1);

    printf("Enter second position to swap (0-%d): ",n-1);
    scanf("%d",&pos2);

    if (pos1<0 || pos1>=n || pos2<0 || pos2>=n) {
    printf("Error: Positions must be between 0 and %d.\n", n - 1);
    return 1;
    }

    swap_elements(arr,pos1,pos2);

    printf("After swapping elements at positions %d and %d:\n",pos1,pos2);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

