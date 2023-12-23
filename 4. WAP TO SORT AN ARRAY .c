//4. WAP TO SORT AN ARRAY //

#include <stdio.h>


int main(){
    int length;
    printf("Enter the numbers of elements in your array: \n");
    scanf("%d", &length);
    int a[length];
    printf("Enter your arrar: \n");
    for(int i = 0; i<length; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i<length; i++){
        for(int j = 0; j<length-1 ; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i = 0; i<length; i++){
        printf(" %d ",a[i]);
    }
}