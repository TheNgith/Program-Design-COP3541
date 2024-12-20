//Name: Thinh Nguyen - UID: 38848480
//Description: Program to check if user input is in order

#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Enter input: ");
    int valid = 1;
    int order = 1;
    int ch1 = getchar();
    int ch2 = getchar();
    int ch1_valid, ch2_valid;
    while (ch2 != '\n') {
        ch1_valid = isalpha(ch1); //check if the letter is alphabetical
        ch2_valid = isalpha(ch2);
        if (!(ch1_valid && ch2_valid)) {
            valid = 0;
            break;
        }
        if (ch1 > ch2 && ch2 != '\n') { //check if the further letter is larger
            order = 0;
        }
        ch1 = ch2;
        ch2 = getchar();
    }

    if (valid && order) { //decide the output
        printf("in order");
    } else {
        switch (valid)
        {
        case 0:
            printf("invalid input");
            break;
        case 1:
            printf("not in order");
            break;
        }
    }
}
