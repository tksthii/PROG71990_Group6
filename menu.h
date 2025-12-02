/*
 * menu.h
 * Author: Person 2
 * Description: Menu system for user interface
 * 
 * TODO (Person 2):
 * - Implement menu display and handlers in menu.c
 * - Handle user input validation
 */

#ifndef MENU_H
#define MENU_H

#include "taskList.h"

// TODO (Person 2): Implement these functions in menu.c

// Display the main menu
void displayMainMenu(void);

// Handle user's menu choice
// Parameters:
//   - list: pointer to task list
//   - choice: user's menu selection
//   - running: pointer to flag controlling main loop
void handleMenuChoice(TaskList* list, int choice, int* running);

// Helper: Clear input buffer
void clearInputBuffer(void);

// Helper: Pause and wait for Enter key
void pressEnterToContinue(void);

#endif
