// 2.B) WAP TO DELETE AN ELEMENT IN AN ARRAY //

#include <stdio.h>

int main(){
    int n,pos;
    printf("Enter the no. of elements present in the Array: \n");
    scanf("%d", &n);
    int array[n];
    printf("Enter your array: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", & array[i]);
    }
    printf("Entered array is: \n");
    for(int i = 0; i<n; i++){
        printf(" %d ", array[i]);
    }

    // Now deleting the element
    printf("\n");
    printf("Enter the position of element to be deleted: \n");
    scanf("%d", &pos);

    if(pos >=n+1){
        printf("Deletion not possible.\n");
    }else{
        for(int i = pos-1;i<n-1;i++){
            array[i] = array[i+1];
        }printf("Resultant array is: \n");
    }
    for(int i = 0; i<n-1; i++){
        printf(" %d ", array[i]);
    }
}
// check deletion  for idx>n //