// Name: Hung Tran
// USF ID: U00526311
// Description: This program includes functionalities for managing and tracking the guest list for a local restaurant. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
	char phone[PHONE_LEN+1];
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int party_size;
	struct guest *next;
};


struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct guest *new_list = NULL;  
  printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = add_guest(new_list);
                break;
      case 'p': print_list(new_list);
                break;
      case 'q': clear_list(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}


struct guest *add_guest(struct guest *list) {
  char phone[PHONE_LEN+1];
  // Prompt for and read the new guest's phone number
  printf("Enter phone number: ");
  read_line(phone, PHONE_LEN);
  
  // Check if the phone number already exists in the list
  struct guest *p;
  for (p = list; p != NULL; p = p->next) {
    if (strcmp(p->phone, phone) == 0) {
      printf("guest already exists.");
      return list;
    }
  }

  // Allocate memory for the new guest and store the phone number
  struct guest *new_guest = malloc(sizeof(struct guest));
  strcpy(new_guest->phone, phone);

  // Prompt for and read the remaining details of the new guest
  printf("Enter guest's last name: ");
  read_line(new_guest->last, NAME_LEN);

  printf("Enter guest's first name: ");
  read_line(new_guest->first, NAME_LEN);

  printf("Enter party size: ");
  scanf("%d", &new_guest->party_size);

  // Set new_guest->next to NULL
  new_guest->next = NULL;
  // If the initial list is NULL, return new_guest
  if (list == NULL) {
    return new_guest;
  }
  // Otherwise, loop through the list until the last guest is found
  for (p = list; p->next != NULL; p = p->next);
  // Set the last guest's next pointer to new_guest
  p->next = new_guest;
  // Return the initial list
  return list;
}


void print_list(struct guest *list) {
  struct guest *p;
  // Loop through the list
  for (p = list; p != NULL; p = p->next) {
    // Print the details of each guest
    printf("%-15s%-20s%-20s%5d\n", p->phone, p->last, p->first, p->party_size);
  }
}


void clear_list(struct guest *list) {
  struct guest *p;
  while (list != NULL) {
    p = list; // Keep a reference to the current guest
    list = list->next; // Move the list pointer to the next guest
    free(p); // Free the memory allocated for the current guest
  }
  // After the loop, list is NULL, so all guests have been freed
}


int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}