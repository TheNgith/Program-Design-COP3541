// Name: Thinh Nguyen - UID: 38848480
// Description: Program that calculates total active seconds of a smart escalator

#include <stdio.h>

int active_seconds(int arrival[], int n) {
    int extra, total = 10;
    int *p;
    
    // Calculate active time
    for (p = (arrival + 1); p < (arrival + n); p++) {
        
        // Compute how much time the next person is behind the previous
        extra = *p - *(p - 1);
        
        if (extra < 10) {
            // If the next person was in before the previous was out
            
            total += extra;
            // Active time will be extended by the time difference between their enters

        } else {
            // If the next person was in after the previous was out
            
            total += 10; 
            // Active time will be capped at 10, the escalator is not active in between their enters
        }
    };
    return total;
}

int main() {
    // Take inputs
    int n;
    
    printf("Enter number of people: ");
    scanf("%d", &n);

    int *p, arrival[n];

    printf("Enter arrival times: ");
    for (p = arrival; p < (n+arrival); p++) {
        scanf("%d", p);
    }
    
    // Print result
    int result = active_seconds(arrival, n);
    printf("Active seconds: %d\n", result);
    
    return 0;
}

