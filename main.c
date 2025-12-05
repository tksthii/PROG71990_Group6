/*
 * main.c
 * Author: Person 3
 * Description: Main entry point for To-Do Manager application
 * * TODO (Person 3):
 * - Implement the main loop
 * - Handle program initialization and cleanup
 */

#include <stdio.h>
#include "taskList.h"
#include "menu.h"
#include <stdlib.h> // Added for general C utilities

#define DATA_FILE "tasks.dat"

int main(void) {
    TaskList taskList;
    int running = 1;
    int choice;

    // TODO (Person 3): Implement program initialization
    // 1. Call initTaskList() to initialize the task list
    initializeTaskList(&taskList); // Assuming 'initializeTaskList' is the name of the function implemented in taskOperations.c/taskList.h

    // 2. Print welcome message
    printf("========================================\n");
    printf("       Welcome to To-Do Manager         \n");
    printf("========================================\n");

    // 3. Try to load existing tasks from file
    //    Call loadTasksFromFile(&taskList, DATA_FILE)
    loadTasksFromFile(&taskList, DATA_FILE);

    // TODO (Person 3): Implement main program loop
    while (running) {
        // 1. Call displayMainMenu()
        displayMainMenu();

        // 2. Read user choice with scanf()
        // 3. Validate input (check if scanf returned 1)
        if (scanf("%d", &choice) != 1) {
            // 4. If invalid, clear input buffer and show error
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            pressEnterToContinue();
            continue; // Restart the loop
        }

        // 5. Call handleMenuChoice() with the choice
        handleMenuChoice(&taskList, choice, &running);
    }

    return 0;
}