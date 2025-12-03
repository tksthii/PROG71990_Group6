/*
 * taskList.c
 * Author: 
 * Description: Implementation of task list management and file I/O
 */

#include "taskList.h"
#include <stdio.h>
#include <string.h>

// TODO (Person 1): Implement this function
// Initialize the task list to empty state
void initTaskList(TaskList* list) {
    // TODO:
    // - Set count to 0
    // - Set nextId to 1
    list->count = 0;
    list->nextId = 1;
}

// TODO (Person 1): Implement this function
// Return the current number of tasks
int getTaskCount(const TaskList* list) {
    // TODO: Return list->count
    return 0;
}

// TODO (Person 1): Implement this function
// Return the next available task ID
int getNextId(const TaskList* list) {
    // TODO: Return list->nextId
    return 1;
}

// TODO (Person 1): Implement this function
// Save all tasks to a file
// File format suggestion:
// Line 1: nextId
// Line 2: count
// Lines 3+: id|title|description|dueDate|priority|isCompleted
int saveTasksToFile(const TaskList* list, const char* filename) {
    // TODO:
    // 1. Open file for writing using fopen(filename, "w")
    // 2. Check if file opened successfully (if NULL, return 0)
    // 3. Write nextId on first line
    // 4. Write count on second line
    // 5. Loop through all tasks and write each one (use | as delimiter)
    // 6. Close the file using fclose()
    // 7. Print success message
    // 8. Return 1 for success
    
    printf("Error: saveTasksToFile not implemented yet\n");
    return 0;
}

// TODO (Person 1): Implement this function
// Load tasks from a file
int loadTasksFromFile(TaskList* list, const char* filename) {
    // TODO:
    // 1. Open file for reading using fopen(filename, "r")
    // 2. If file doesn't exist, print info message and return 0
    // 3. Initialize the list using initTaskList()
    // 4. Read nextId from first line using fscanf()
    // 5. Read count from second line
    // 6. Loop count times:
    //    - Read each task using fscanf with format matching save format
    //    - Store in list->tasks array
    // 7. Close the file
    // 8. Print success message with number of tasks loaded
    // 9. Return 1 for success
    
    printf("Info: No existing data file found. Starting fresh.\n");
    return 0;
}
