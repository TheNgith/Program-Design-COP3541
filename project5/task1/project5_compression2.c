//Name: Thinh Nguyen - UID: 38848480
//Description: Program to compress a message base on number of repeated characters

#include <stdio.h>

char to_str(int num) {
    int i;
    char result = '0';
    for (i = 0; i < num; i++) {
        result++;
    }
    return result; //convert integer value to char
}

void compress(char *input, char *output) {
    char *pin, *pout, current_char;
    int count=1;
    pin = input;
    pout = output;
    for (; *(pin) != '\0'; pin++) {
        //starting new character counting
        current_char = *pin;
        count = 1;
        while (*(pin+1)==*pin) {
            count++;
            pin++;
        } //loop breaks when encouter a different character
        if (count == 1) {
            *pout = current_char; //if there is 1 character of a type: keep it as it was
            pout++;
        }
        else if (count == 2) {
            *pout = current_char;
            pout++;
            *pout = current_char; //if there is 2 character of a type: keep it as it was
            pout++;
        } else {
            *pout = to_str(count); //if there is more than 2 character of a type: compress it
            pout++;
            *pout = current_char;
            pout++;
        }       
    }
}

int main() {
    char input[1001], output[1001];
    
    //get input
    printf("Enter message:");
    scanf("%s", input);
    
    compress(input, output);
    
    //print output
    printf("Output: %s", output);
    
    return 0;
}