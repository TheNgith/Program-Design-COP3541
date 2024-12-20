#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"

struct guest *add_guest(struct guest *list) {
    struct guest *current_node;
    struct guest *last_node = NULL;
    char phone_number[PHONE_LEN+1];
    
    printf("Enter phone number: ");
    read_line(phone_number, PHONE_LEN);
    
    // Check if the phone had existed in the database
    for (current_node=list; current_node!=NULL; current_node = current_node->next) {
        // The node that does not point to any other node is the last node
        if (current_node->next == NULL) last_node=current_node;
        if (strcmp(current_node->phone, phone_number)==0) {
            printf("guest already exists.");
            return list;
        }
    }

    // Define a new node
    char last[NAME_LEN+1];
    char first[NAME_LEN+1];
    int partysize;
    printf("Enter guest's last name: ");
    read_line(last, NAME_LEN);
    
    printf("Enter guest's first name: ");
    read_line(first, NAME_LEN);

    printf("Enter party size: ");
    scanf("%d", &partysize);
    
    struct guest *new_node;
    new_node = malloc(sizeof(struct guest)); // Allocating memory
    
    strcpy((*new_node).first, first);
    strcpy((*new_node).last, last);
    strcpy((*new_node).phone, phone_number);
    (*new_node).party_size = partysize;
    
    // The newly added node will be the last node, so it points to NULL
    (*new_node).next = NULL; 

    // If there was no node in the list before adding the new node (no last_node found):
    if (last_node != NULL) (*last_node).next = new_node;
    else return new_node;

    return list; 
}

struct guest *remove_guest(struct guest *list) {
    
    // Initializes
    char phone_number[PHONE_LEN+1];
    char last[NAME_LEN+1];
    char first[NAME_LEN+1];
    struct guest *current_node;
    struct guest *previous_node = NULL;

    // Takes inputs
    printf("Enter phone number: ");
    read_line(phone_number, PHONE_LEN);
    printf("Enter guest's last name: ");
    read_line(last, NAME_LEN);
    printf("Enter guest's first name: ");
    read_line(first, NAME_LEN);

    // Check if the guest exists in the database
    for (current_node = list; current_node!=NULL; current_node = current_node->next) { 
        if (
            // Comparing information
            strcmp(current_node->phone, phone_number) == 0 
            && strcmp(current_node->last, last) == 0
            && strcmp(current_node->first, first) == 0
            ) {
                // previous_node != NULL ~ the found node is not the first node
                if (previous_node!=NULL) {
                    (*previous_node).next = (*current_node).next;
                    free(current_node);
                    return list;
                }
                // If the found node is the first node, simply return the next node as the start of the list
                // This also works with list having 1 node (the next node will be NULL, which equivalent to a blank list)
                else {
                    list = (*current_node).next;
                    free(current_node);
                    return list;
                }
            }
            previous_node = current_node;
    }

    // The loop ends without returning --> no found guest
    printf("guest does not exists.");
    return list;
}

void print_list(struct guest *list) {
    struct guest *current_node;
    // Looping through the list and print values in the stated format
    for (current_node=list; current_node!=NULL; current_node = (*current_node).next) {
        printf("%-15s%-20s%-20s%5d\n", 
            (*current_node).phone, 
            (*current_node).last,
            (*current_node).first, 
            (*current_node).party_size);
    }
}

void clear_list(struct guest *list) {
    struct guest *current_node;
    for (;list!=NULL; free(current_node)) {
        current_node = list;
        // Shift the beginning of the list to the second node before deleting the first node
        // until there are no nodes left
        list = (*list).next; 
    }
}
