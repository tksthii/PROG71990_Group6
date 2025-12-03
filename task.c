/*
 * task.c
 * Author: Person 1
 * Description: Implementation of Task ADT operations
 */

#include "task.h"
#include <stdio.h>
#include <string.h>

// TODO (Person 1): Implement this function
// Create a new task with the given parameters
// Remember to use strncpy for safe string copying
Task createTask(int id, const char* title, const char* description, 
                const char* dueDate, Priority priority) {
                      // TODO: Initialize all fields of the task struct
    // - Set id
    // - Copy title (use strncpy for safety)
    // - Copy description
    // - Copy dueDate
    // - Set priority
    // - Set isCompleted to 0 (not completed)
    Task task;// Declare a Task variable
    task.id = id;
    strncpy(task.title, title, MAX_TITLE - 1);
    task.title[MAX_TITLE - 1] = '\0'; // Ensure null-termination
    strncpy(task.description, description, MAX_DESC - 1);
    task.description[MAX_DESC - 1] = '\0'; // Ensure null-termination
    strncpy(task.dueDate, dueDate, MAX_DATE - 1);
    task.dueDate[MAX_DATE - 1] = '\0'; // Ensure null-termination
    task.priority = priority;
    task.isCompleted = 0; // Not completed by default

    return task;
}

// TODO (Person 1): Implement this function
// Print a header line for the task table
void printTaskHeader(void) {
    // TODO: Print column headers
    // Suggested format: ID | Title | Due Date | Priority | Status
    // Use printf with proper spacing
}

// TODO (Person 1): Implement this function
// Print a single task in table format
void printTask(const Task* task) {
    // TODO: Print task information in table format
    // Match the format used in printTaskHeader()
    // Use priorityToString() and check isCompleted for status
}

// TODO (Person 1): Implement this function
// Convert priority enum to string
const char* priorityToString(Priority p) {
    // TODO: Use switch statement to return appropriate string
    // LOW -> "Low"
    // MEDIUM -> "Medium"
    // HIGH -> "High"
    return "Unknown";
}

// TODO (Person 1): Implement this function
// Convert integer to priority enum
Priority stringToPriority(int p) {
    // TODO: Validate input (1-3) and return appropriate Priority
    // Default to MEDIUM if invalid
    return MEDIUM;
}
