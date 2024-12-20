#include <stdio.h>
#include <string.h>

struct Animal {
    char name[101];
    char species[101];
    char gender[101];
    int age;
    double weight;
};

int cmpfunc (const struct Animal *animal1, const struct Animal *animal2) {
    int species_comparing_result = strcmp((*animal1).species, (*animal2).species);
    // If the animals are of the same species, compare their age
    if (species_comparing_result!=0) return species_comparing_result;
    else return ((*animal1).age - (*animal2).age);
}

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
                  &animals[numAnimals].weight) == 5) { // fscanf returns number of scanned value
        numAnimals++; // if successfully read 5 attributes of an animal then increment count
    }

    qsort(animals, numAnimals, sizeof(struct Animal), cmpfunc);

    // Search for and write matching animals to the output file
    int i;
    struct Animal result_array[200];
    int result_count = 0;
    for (i = 0; i < numAnimals; i++) {
        if (strcmp(animals[i].species, species_input) == 0 &&
            strcmp(animals[i].gender, gender_input) == 0) {
                // Copy search result to the result_array
                strcpy(result_array[result_count].name, animals[i].name);
                strcpy(result_array[result_count].species, animals[i].species);
                strcpy(result_array[result_count].gender, animals[i].gender);
                result_array[result_count].age = animals[i].age;
                result_array[result_count].weight = animals[i].weight;
                result_count++;
        }
    }
    
    // Write sorted database to the result file
    for (i = 0; i < numAnimals; i++) {
        fprintf(outputFile, "%s %d %s %.2lf %s\n", 
        animals[i].species, 
        animals[i].age, 
        animals[i].name, 
        animals[i].weight, 
        animals[i].gender);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Output file name: results.txt\n");

    return 0;
}
