#include <stdio.h>
#include <string.h>

struct Animal {
    char name[101];
    char species[101];
    char gender[101];
    int age;
    double weight;
};

int main() {
    char species_input[101];
    char gender_input[101];

    // Input species and gender from the user
    printf("Enter species: ");
    scanf("%s", species_input);
    printf("Enter gender: ");
    scanf("%s", gender_input);

    FILE *inputFile = fopen("animals.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file");
        return 1;
    }

    FILE *outputFile = fopen("results.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file");
        fclose(inputFile);
        return 1;
    }

    struct Animal animals[200];
    int numAnimals = 0;

    // Read animals from the input file
    while (fscanf(inputFile, "%s %s %s %d %lf",
                  animals[numAnimals].name,
                  animals[numAnimals].species,
                  animals[numAnimals].gender,
                  &animals[numAnimals].age,
                  &animals[numAnimals].weight) == 5) {
        numAnimals++;
    }

    // Search for and write matching animals to the output file
    int i;
    for (i = 0; i < numAnimals; i++) {
        if (strcmp(animals[i].species, species_input) == 0 &&
            strcmp(animals[i].gender, gender_input) == 0) {
            fprintf(outputFile, "%s %d %.2lf\n",
                    animals[i].name, animals[i].age, animals[i].weight);
        }
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Output file name: results.txt\n");

    return 0;
}
