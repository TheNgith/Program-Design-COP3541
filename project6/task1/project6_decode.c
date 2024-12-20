#include <stdio.h>
#include <string.h>


int decode(char words[][101], int num_words, char *result) {
    int i;
    
    // Save the first letter of each word to result array
    for (i = 0; i < num_words; i++) *(result+i) = words[i][0];
    *(result+i) = '\0'; //cut the string
    return 0;
}


int main() {
    // Get input and compute output file name
    printf("Enter the file name: ");
    
    char output[101] = "decoded_";
    char input[101];
    scanf("%s", input);
    strcat(output, input);

    // Initialize necessary variables
    FILE* pFile;
    
    char words[1000][101];
    int wordcount = 0;
    char decoded_str[1001];

    // Open input file and append words to the words array
    pFile = fopen(input, "r");
    do {
        fscanf(pFile, "%s", words[wordcount]);
    } while (strlen(words[wordcount++]) > 0);
    // Stop when encounter a word whose length = 0 (reached the EOF) 
    fclose(pFile);

    // Run decode func,
    // Decrement wordcount because it included the ending empty character
    decode(words, --wordcount, decoded_str);

    pFile = fopen(output, "w");
    fputs(decoded_str, pFile);
    fclose(pFile);

    printf("Ouput file name:\n%s", output);

    return 0;
}
