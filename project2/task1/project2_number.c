//Name: Thinh Nguyen - UID: 38848480
//Description: Program that check if a number contains 3 and divided by 3

#include <stdio.h>

int main() {

    int num;
    printf("Enter input: ");
    scanf("%d", &num);

    int include_3 = 0;
    int multiple_3 = (num % 3 == 0); //check if divide by 3

    int last_digit;

    while (num != 0) { //loop to go through each digit
        last_digit = num % 10;
        if (last_digit == 3) {
            include_3 = 1;
            break; //break immediately when found the first digit 3
        };
        num /= 10;
    }

    if (include_3 && multiple_3) {
        printf("yes");
    } else {
        printf("no");
    }

    return 0;
}