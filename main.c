/*
 * main.c
 * Author: Person 3
 * Description: Main entry point for To-Do Manager application
 * 
 * TODO (Person 3):
 * - Implement the main loop
 * - Handle program initialization and cleanup
 */

#include <stdio.h>
#include "taskList.h"
#include "menu.h"

#define DATA_FILE "tasks.dat"
int main(void) {
    TaskList taskList;
    int running = 1;
    int choice;
    
    // Initialize task list
    initTaskList(&taskList);
    
    // Welcome message
    printf("\n");
    printf("════════════════════════════════════════\n");
    printf("  Welcome to TO-DO MANAGER!\n");
    printf("════════════════════════════════════════\n");
    
   // Try to load existing data
    printf("\nAttempting to load existing tasks...\n");
    loadTasksFromFile(&taskList, DATA_FILE);
    
    // TODO (Person 3): Implement main program loop
    // while (running) {
    //     1. Call displayMainMenu()
    //     2. Read user choice with scanf()
    //     3. Validate input (check if scanf returned 1)
    //     4. If invalid, clear input buffer and show error
    //     5. Call handleMenuChoice() with the choice
    // }
    
    printf("Error: main() not fully implemented yet\n");
    printf("Program structure is ready - implement the TODO items!\n");
    
    return 0;
}
