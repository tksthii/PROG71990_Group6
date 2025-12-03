/*
 * taskOperations.c
 * Author: Person 2
 * Description: Implementation of CRUD operations
 */

#include "taskOperations.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// TODO (Person 2): Implement this helper function
// Find the array index of a task with given ID
int findTaskIndexById(const TaskList* list, int id) {
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            return i;
        }
    }
    return -1;
}

// TODO (Person 2): Implement this helper function
// Validate date format (YYYY-MM-DD)
int isValidDate(const char* date) {
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return 0;
    }
    return 1;
}

// TODO (Person 2): Implement this function
// Add a new task to the list
int addTask(TaskList* list, const char* title, const char* description,
            const char* dueDate, Priority priority) {
    // Check if list is full
    if (list->count >= MAX_TASKS) {
        printf("Error: Task list is full!\n");
        return 0;
    }
    if (strlen(title) == 0) {
    printf("Error: Title cannot be empty!\n");
    return 0;
}
    if (!isValidDate(dueDate)) {
    printf("Error: Invalid date format! Use YYYY-MM-DD\n");
    return 0;
}
   // After validations:
   Task newTask = createTask(list->nextId, title, description, dueDate, priority); 
   list->tasks[list->count] = newTask;
    list->count++;
    list->nextId++;
    printf(" Task added successfully! (ID: %d)\n", newTask.id);
    return 1;
}

// TODO (Person 2): Implement this function
// Delete a task by ID
int deleteTask(TaskList* list, int id) {
    int index = findTaskIndexById(list, id);
    
    if (index == -1) {
        printf("Error: Task with ID %d not found!\n", id);
        return 0;
    }
    printf("\nAre you sure you want to delete this task?\n");
    printTaskHeader();
    printTask(&list->tasks[index]);
    printf("\nConfirm? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);

    if (confirm != 'y' && confirm != 'Y') {
        
    printf("Deletion cancelled.\n");
    return 0;
}
    for (int i = index; i < list->count - 1; i++) {
    list->tasks[i] = list->tasks[i + 1];
}
    list->count--;
    printf("Task deleted successfully!\n");
    return 1;
}

// TODO (Person 2): Implement this function
// Update an existing task
int updateTask(TaskList* list, int id) {
    int index = findTaskIndexById(list, id);
    
    if (index == -1) {
        printf("Error: Task with ID %d not found!\n", id);
        return 0;
    }
    
    Task* task = &list->tasks[index];
    
    printf("\n=== Update Task (ID: %d) ===\n", id);
    printf("Current details:\n");

    printf("Title: %s\n", task->title);
    printf("Description: %s\n", task->description);
    printf("Due Date: %s\n", task->dueDate);
    printf("Priority: %s\n", priorityToString(task->priority));
    printf("Status: %s\n", task->isCompleted ? "Done" : "Pending");
    
    printf("\nWhat would you like to update?\n");
    printf("1. Title\n");
    printf("2. Description\n");
    printf("3. Due Date\n");
    printf("4. Priority\n");
    printf("5. Status\n");
    printf("0. Cancel\n");
    printf("Choice: ");

    int choice;
    scanf("%d", &choice);
    getchar();
    return 0;

    char buffer[MAX_DESC];
    int priority, status;

    switch(choice) {
    case 1:
        printf("New title: ");
        fgets(buffer, MAX_TITLE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if (strlen(buffer) > 0) {
            strncpy(task->title, buffer, MAX_TITLE - 1);
            printf("✓ Title updated!\n");
        }
        break;

    case 2:
        printf("New description: ");
        fgets(buffer, MAX_DESC, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        strncpy(task->description, buffer, MAX_DESC - 1);
        printf("✓ Description updated!\n");
    break;
}

// TODO (Person 2): Implement this function
// Display a single task by ID with full details
int displayTaskById(const TaskList* list, int id) {
    // TODO:
    // 1. Find task using findTaskIndexById()
    // 2. If not found, print error and return 0
    // 3. Print detailed task information:
    //    - ID
    //    - Title
    //    - Description
    //    - Due Date
    //    - Priority
    //    - Status
    // 4. Return 1 for success
    
    printf("Error: displayTaskById not implemented yet\n");
    return 0;
}
