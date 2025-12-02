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
    // TODO:
    // 1. Loop through list->tasks from 0 to list->count
    // 2. If tasks[i].id == id, return i
    // 3. If not found, return -1
    return -1;
}

// TODO (Person 2): Implement this helper function
// Validate date format (YYYY-MM-DD)
int isValidDate(const char* date) {
    // TODO:
    // 1. Check if length is exactly 10
    // 2. Check if positions 4 and 7 are '-'
    // 3. Check if all other positions are digits
    // 4. Return 1 if valid, 0 if invalid
    return 1; // Placeholder
}

// TODO (Person 2): Implement this function
// Add a new task to the list
int addTask(TaskList* list, const char* title, const char* description,
            const char* dueDate, Priority priority) {
    // TODO:
    // 1. Check if list is full (count >= MAX_TASKS)
    // 2. Validate title is not empty (strlen > 0)
    // 3. Validate date format using isValidDate()
    // 4. Create new task using createTask() with list->nextId
    // 5. Add task to list->tasks[list->count]
    // 6. Increment list->count
    // 7. Increment list->nextId
    // 8. Print success message with task ID
    // 9. Return 1 for success, 0 for failure
    
    printf("Error: addTask not implemented yet\n");
    return 0;
}

// TODO (Person 2): Implement this function
// Delete a task by ID
int deleteTask(TaskList* list, int id) {
    // TODO:
    // 1. Find task index using findTaskIndexById()
    // 2. If not found (index == -1), print error and return 0
    // 3. Display the task to be deleted
    // 4. Ask for confirmation (y/n)
    // 5. If confirmed:
    //    - Shift all tasks after this one left by 1 position
    //    - Decrement list->count
    //    - Print success message
    //    - Return 1
    // 6. If not confirmed, return 0
    
    printf("Error: deleteTask not implemented yet\n");
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
