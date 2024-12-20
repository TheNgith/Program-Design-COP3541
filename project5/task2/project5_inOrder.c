//Name: Thinh Nguyen - UID: 38848480
//Description: Program to check if user input is in order - accepts command line input

#include <stdio.h>
#include <ctype.h>

int inOrder(char *input) {
    int valid = 1;
    int order = 1;
    char *p;
    p = input;
    int ch1 = *p;
    p++;
    int ch2 = *p;
    p++;
    int ch1_valid, ch2_valid;
    while (ch2 != '\0') {
        ch1_valid = isalpha(ch1); //check if the letter is alphabetical
        ch2_valid = isalpha(ch2);
        if (!(ch1_valid && ch2_valid)) {
            valid = 0;
            break;
        }
        if (tolower(ch1) > tolower(ch2) && ch2 != '\0') { //check if the further letter is larger
            order = 0;
            break;
        }
        ch1 = ch2;
        ch2 = *p;
        p++;
    }
    if (valid && order) return 1; //return status code
    else {
        if (valid) return 0;
        else return -1;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("invalid input\n"); //check if the number of input is 2
        return 0;
    }

    int status = inOrder(argv[1]);
    switch (status)
    {
    case 1:
        printf("in order\n");
        break;
    case 0:
        printf("not in order\n");
        break;
    case -1:
        printf("invalid input\n");
        break;
    }
    return 0;
}
