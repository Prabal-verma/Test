//5. WAP TO MERGE TWO SORTED ARRAY //

#include <stdio.h>

int main(){
    int x,y,merged;
    printf("Enter the no. of elements in array 1: \n");
    scanf("%d", &x);
    printf("Enter the no. of elements in array 2: \n");
    scanf("%d", &y);
    int arr1[x];
    int arr2[y];
    printf("Enter your first array: \n");
    for(int i = 0; i<x ;i++){
        scanf("%d", &arr1[i]);
    }
    printf("Enter elements of array2: \n");
    for(int i = 0; i<y ;i++){
        scanf("%d", &arr2[i]);
    }

    merged = x+y;
    int mergearr[merged];
    
    // Copying elements from arr1 to mergearr
    for(int i = 0; i<x; i++){
        mergearr[i] = arr1[i];
    }
    
    // Copying elements from arr2 to mergearr
    for(int i = 0; i< y ; i++){
        mergearr[i+x] = arr2[i];
    }
    
    printf("Merged array is: \n");
    
    // Printing the merged array
    for(int j = 0; j<merged ; j++){
        printf("%d ",mergearr[j]);
    }
    
    return 0;
}
