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
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}

// TODO (Person 2): Implement this function
// Display the main menu with all options
// Display main menu
void displayMainMenu(void) {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║       TO-DO MANAGER SYSTEM             ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("  1. Add New Task\n");
    printf("  2. Delete Task\n");
    printf("  3. Update Task\n");
    printf("  4. View Single Task\n");
    printf("  5. View Tasks by Range/Filter\n");
    printf("  6. View All Tasks\n");
    printf("  7. Search Tasks\n");
    printf("  8. Save to File\n");
    printf("  9. Load from File\n");
    printf("  0. Exit\n");
    printf("════════════════════════════════════════\n");
    printf("Enter choice: ");
}

// TODO (Person 2): Implement these handler functions
// Handle Add Task
void handleAddTask(TaskList* list) {
    char title[MAX_TITLE];
    char description[MAX_DESC];
    char dueDate[MAX_DATE];
    int priorityChoice;
    
    printf("\n=== Add New Task ===\n");
    
    printf("Title: ");
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = 0;
    
    printf("Description: ");
    fgets(description, MAX_DESC, stdin);
    description[strcspn(description, "\n")] = 0;
    
    printf("Due Date (YYYY-MM-DD): ");
    scanf("%10s", dueDate);
    
    printf("Priority (1=Low, 2=Medium, 3=High): ");
    scanf("%d", &priorityChoice);
    
    Priority priority = stringToPriority(priorityChoice);
    addTask(list, title, description, dueDate, priority);
}

// Handle Delete Task
void handleDeleteTask(TaskList* list) {
    int id;
    
    printf("\n=== Delete Task ===\n");
    printf("Enter Task ID to delete: ");
    scanf("%d", &id);
    
    deleteTask(list, id);
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
