//6. WAP TO STORE THE MARKS OBTAINED BY 10 STUDENTS IN 5 COURSES IN A 2-D ARRAY

// subjects = PCMBE

#include<stdio.h>

int main(){
    int marks[10][5];
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=2; j++){
                printf("Enter marks of student: %d \n", i);
            scanf("%d", &marks[i][j]);
        }
    }
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=2; j++){
            printf("Marks of student: %d \n", i);
            printf(" %d \n", marks[i][j]);
        }
    }
}