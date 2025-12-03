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

// Handle Update Task
void handleUpdateTask(TaskList* list) {
    int id;
    
    printf("\n=== Update Task ===\n");
    printf("Enter Task ID to update: ");
    scanf("%d", &id);
    
    updateTask(list, id);
}

// Handle View Single Task
void handleViewSingle(TaskList* list) {
    int id;
    
    printf("\n=== View Single Task ===\n");
    printf("Enter Task ID: ");
    scanf("%d", &id);
    
    displayTaskById(list, id);
}

// Handle View by Range/Filter
void handleViewByRange(TaskList* list) {
    int filterChoice;
    
    printf("\n=== View Tasks by Filter ===\n");
    printf("1. By Priority\n");
    printf("2. By Status (Completed/Pending)\n");
    printf("3. By Date Range\n");
    printf("Enter choice: ");
    scanf("%d", &filterChoice);
    
    switch(filterChoice) {
        case 1: {
            int priority;
            printf("Enter Priority (1=Low, 2=Medium, 3=High): ");
            scanf("%d", &priority);
            displayTasksByPriority(list, stringToPriority(priority));
            break;
        }
        case 2: {
            int status;
            printf("Enter Status (0=Pending, 1=Completed): ");
            scanf("%d", &status);
            displayTasksByStatus(list, status);
            break;
        }
        case 3: {
            char startDate[MAX_DATE], endDate[MAX_DATE];
            printf("Start Date (YYYY-MM-DD): ");
            scanf("%10s", startDate);
            printf("End Date (YYYY-MM-DD): ");
            scanf("%10s", endDate);
            displayTasksByDateRange(list, startDate, endDate);
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
}

// Handle Search
void handleSearch(TaskList* list) {
    char keyword[100];
    
    printf("\n=== Search Tasks ===\n");
    printf("Enter keyword to search: ");
    getchar();  // Clear newline
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = 0;
    
    searchTasksByKeyword(list, keyword);
}

// Handle menu choice
void handleMenuChoice(TaskList* list, int choice, int* running) {
    switch(choice) {
        case 1:
            clearInputBuffer();
            handleAddTask(list);
            pressEnterToContinue();
            break;
            
        case 2:
            handleDeleteTask(list);
            pressEnterToContinue();
            break;
            
        case 3:
            handleUpdateTask(list);
            pressEnterToContinue();
            break;
            
        case 4:
            handleViewSingle(list);
            pressEnterToContinue();
            break;
            
        case 5:
            handleViewByRange(list);
            pressEnterToContinue();
            break;
            
        case 6:
            displayAllTasks(list);
            pressEnterToContinue();
            break;
            
        case 7:
            handleSearch(list);
            pressEnterToContinue();
            break;
            
        case 8:
            saveTasksToFile(list, DATA_FILE);
            pressEnterToContinue();
            break;
            
        case 9:
            loadTasksFromFile(list, DATA_FILE);
            pressEnterToContinue();
            break;
            
        case 0:
            printf("\nSave before exit? (y/n): ");
            clearInputBuffer();
            char save;
            scanf(" %c", &save);
            if (save == 'y' || save == 'Y') {
                saveTasksToFile(list, DATA_FILE);
            }
            printf("\nThank you for using To-Do Manager! Goodbye!\n");
            *running = 0;
            break;
            
        default:
            printf("\nInvalid choice! Please try again.\n");
            pressEnterToContinue();
    }
}
