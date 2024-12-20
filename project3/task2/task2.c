//Name: Thinh Nguyen - UID: 38848480
//Description: Program that calculates total active seconds of a smart escalator

#include <stdio.h>

int active_seconds(int arrival[], int n) {
    int extra, total = 10;
    
    // Calculate active time
    for (int i = 1; i < n; i++) {
        extra = arrival[i] - arrival[i-1];
        if (extra < 10) {
            total += extra;
        } else {
            total += 10;
        }
    };
    return total;
}

int main() {
    // Take inputs
    int n;
    
    printf("Enter number of people: ");
    scanf("%d", &n);

    int arrival[n];

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }
    
    // Print result
    int result = active_seconds(arrival, n);
    printf("Active seconds: %d\n", result);
    
    return 0;
}

