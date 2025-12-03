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
    // More coming
    return 0;
}

// TODO (Person 2): Implement this function
// Update an existing task
int updateTask(TaskList* list, int id) {
    // TODO:
    // 1. Find task using findTaskIndexById()
    // 2. If not found, print error and return 0
    // 3. Display current task details
    // 4. Show menu of what can be updated:
    //    - 1. Title
    //    - 2. Description
    //    - 3. Due Date
    //    - 4. Priority
    //    - 5. Status
    //    - 0. Cancel
    // 5. Get user choice
    // 6. Based on choice, update the appropriate field
    // 7. Validate input where necessary
    // 8. Print success message
    // 9. Return 1 for success
    
    printf("Error: updateTask not implemented yet\n");
    return 0;
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
