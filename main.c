/*
 * main.c
 * Author: Person 3
 * Description: Main entry point for To-Do Manager application
 * * TODO (Person 3):
 * - Implement the main loop
 * - Handle program initialization and cleanup
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "taskList.h"
#include "menu.h"
#include <stdlib.h> // Added for general C utilities

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
    
    // Main program loop
    while (running) {
        displayMainMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');  // Clear invalid input
            continue;
        }
        
        handleMenuChoice(&taskList, choice, &running);
    }
    // Exit message
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║         PROGRAM TERMINATED             ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("\n");
    
    return 0;
}