//Name: Thinh Nguyen - UID: 38848480
//Description: Program to manage party bookings using linked list

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
  struct guest *current_node;
  struct guest *last_node;
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


void print_list(struct guest *list){
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

void clear_list(struct guest *list){
 struct guest *current_node;
 for (;list!=NULL; free(current_node)) {
  current_node = list;
  // Shift the beginning of the list to the second node before deleting the first node
  // until there are no nodes left
  list = (*list).next; 
 }
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
