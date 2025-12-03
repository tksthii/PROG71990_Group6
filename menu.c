/*
 * menu.c
 * Author: Person 2
 * Description: Implementation of menu system and user interface
 */

#include "menu.h"
#include "taskOperations.h"
#include "display.h"
#include <stdio.h>
#include <string.h>

#define DATA_FILE "tasks.dat"

// TODO (Person 2): Implement this helper function
// Clear the input buffer
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// TODO (Person 2): Implement this helper function
// Wait for user to press Enter
void pressEnterToContinue(void) {
    // TODO:
    // 1. Print "Press Enter to continue..."
    // 2. Call clearInputBuffer()
}

// TODO (Person 2): Implement this function
// Display the main menu with all options
void displayMainMenu(void) {
    // TODO: Print the menu with these options:
    // 1. Add New Task
    // 2. Delete Task
    // 3. Update Task
    // 4. View Single Task
    // 5. View Tasks by Range/Filter
    // 6. View All Tasks
    // 7. Search Tasks
    // 8. Save to File
    // 9. Load from File
    // 0. Exit
    
    printf("\n=== TO-DO MANAGER ===\n");
    printf("Menu not implemented yet\n");
    printf("Enter choice: ");
}

// TODO (Person 2): Implement these handler functions

void handleAddTask(TaskList* list) {
    // TODO:
    // 1. Print "=== Add New Task ==="
    // 2. Prompt for title (use fgets)
    // 3. Prompt for description
    // 4. Prompt for due date
    // 5. Prompt for priority (1-3)
    // 6. Call addTask() with the input
}

void handleDeleteTask(TaskList* list) {
    // TODO:
    // 1. Print "=== Delete Task ==="
    // 2. Prompt for task ID
    // 3. Call deleteTask() with the ID
}

void handleUpdateTask(TaskList* list) {
    // TODO:
    // 1. Print "=== Update Task ==="
    // 2. Prompt for task ID
    // 3. Call updateTask() with the ID
}

void handleViewSingle(TaskList* list) {
    // TODO:
    // 1. Print "=== View Single Task ==="
    // 2. Prompt for task ID
    // 3. Call displayTaskById() with the ID
}

void handleViewByRange(TaskList* list) {
    // TODO:
    // 1. Print "=== View Tasks by Filter ==="
    // 2. Show sub-menu:
    //    - 1. By Priority
    //    - 2. By Status
    //    - 3. By Date Range
    // 3. Get user choice
    // 4. Call appropriate display function (from Person 3)
}

void handleSearch(TaskList* list) {
    // TODO:
    // 1. Print "=== Search Tasks ==="
    // 2. Prompt for keyword
    // 3. Call searchTasksByKeyword() (from Person 3)
}

// TODO (Person 2): Implement this main handler function
// Handle the user's menu choice
void handleMenuChoice(TaskList* list, int choice, int* running) {
    // TODO: Use switch statement to handle each choice:
    // Case 1: Call handleAddTask()
    // Case 2: Call handleDeleteTask()
    // Case 3: Call handleUpdateTask()
    // Case 4: Call handleViewSingle()
    // Case 5: Call handleViewByRange()
    // Case 6: Call displayAllTasks() (from Person 3)
    // Case 7: Call handleSearch()
    // Case 8: Call saveTasksToFile() (from Person 1)
    // Case 9: Call loadTasksFromFile() (from Person 1)
    // Case 0: Ask to save, then set *running = 0 to exit
    // Default: Print "Invalid choice"
    
    // After each case (except 0), call pressEnterToContinue()
    
    printf("Error: handleMenuChoice not implemented yet\n");
}
