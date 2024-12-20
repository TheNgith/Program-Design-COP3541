// Name: Thinh Nguyen - UID: 38848480
// Description: Program that output items that are not in both input arrays

#include <stdio.h>

void exclusive_or(int *a, int n1,  int *b, int n2, int *c, int *size) {
    // Initialize variables
    int *p1, *p2, *p3, flag;
    p3 = c; // Point p3 to the first position of c

    // Find unique values in a
    // Thoughout this loop, move pointer from the first position of a (a) to the last (a+n1)
    for (p1=a; p1<(n1+a); p1++) {
        flag = 0; // Status of the loop: 1 if at least 1 match, 0 if no match
        for (p2=b; p2<(n2+b); p2++) { 
            //Thoughout the loop, move pointer from the first position of b (b) to the last (b+n2)
            if (*p1 == *p2) {
                flag = 1;
                break; // If found a match, break immediately to save time
            }
        }
        if (!flag) {
            // Check status and assign value
            *p3 = *p1; // Assign the unique value to the current position in c
            p3++; // Move to the next position in c
            *size = *size + 1; // Increase the size of c
        }
    }

    // Similarly find unique values in b
    for (p2=b; p2<(n2+b); p2++) {
        flag = 0;
        for (p1=a; p1<(n1+a); p1++) {
            if (*p2 == *p1) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            *p3 = *p2;
            p3++;
            *size = *size + 1;
        }
    }
}

int main() {
    // Initialize variables and take inputs
    int n1, n2, size, *p;
    
    // Build array 1
    printf("Enter length of array #1: ");
    scanf("%d", &n1);
    
    int a[n1];
    
    printf("Enter array elements: ");
    //Loop through positions of array a and fill values from input
    for (p = a; p < (n1+a); p++) {
        scanf("%d", p);
    }

    //Build array 2
    printf("Enter length of array #2: ");
    scanf("%d", &n2);
    
    int b[n2], c[n1+n2];
    
    printf("Enter array elements: ");
    //Loop through positions of array b and fill values from input
    for (p = b; p < (n2+b); p++) {
        scanf("%d", p);
    }

    // Execution
    exclusive_or(a, n1, b, n2, c, &size);

    // Print outputs
    printf("Output:");
    for (p=c; p<(c+size); p++) {
        printf(" %d", *p);
    }

    return 0;
}