//3. WAP TO SEARCH FOR AN ELEMENT IN AN ARRAY

#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int found = 0; // Flag to indicate if the number is found

    // Loop through the array to search for the target number
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = 1;
            printf("Number %d found at index %d.\n", target, i);
            break; // Exit the loop since we found the number
        }
    }

    if (!found) {
        printf("Number %d not found in the array.\n", target);
    }

    return 0;
}
