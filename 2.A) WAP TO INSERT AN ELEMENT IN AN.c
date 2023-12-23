//2.A) WAP TO INSERT AN ELEMENT IN AN ARRAY //

#include<stdio.h>

int main(){
    int n,pos,val;
    printf("Enter the no. of elements present in array: \n");
    scanf("%d", &n);
    int arr[n+1]; // Increase the size of your array by 1
    printf("Enter your array: \n");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("OOPS! You forgot an element to insert. \nEnter the position of forgotten element: \n");
    scanf("%d", &pos);
    printf("Enter the value:\n");
    scanf("%d", &val);

    // Now updating the array.

    for(int i = n; i>=pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = val;
    
    printf("Array is updated now. Your new array is: \n");
    for(int i = 0; i<=n;i++){
        printf(" %d ", arr[i]);
    }
    
    return 0;
}