/*
 * display.c
 * Author: Person 3
 * Description: Implementation of display and search operations
 */

#include "display.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// TODO (Person 3): Implement this helper function
// Convert string to lowercase for case-insensitive search
void toLowerCase(char* str) {
    // TODO: Loop through string and convert each character to lowercase
}

// TODO (Person 3): Implement this function
// Display all tasks in a formatted table
void displayAllTasks(const TaskList* list) {
    // TODO:
    // 1. Check if list is empty (count == 0)
    // 2. If empty, print "No tasks found" and return
    // 3. Print header (e.g., "=== ALL TASKS ===")
    // 4. Call printTaskHeader() (from Person 1)
    // 5. Loop through all tasks and call printTask() for each
    // 6. Print footer line
    
    printf("Error: displayAllTasks not implemented yet\n");
}

// TODO (Person 3): Implement this function
// Display tasks filtered by priority level
void displayTasksByPriority(const TaskList* list, Priority priority) {
    // TODO:
    // 1. Print header with priority level
    // 2. Print table header
    // 3. Loop through tasks
    // 4. If task.priority matches, print the task
    // 5. Count how many tasks match
    // 6. Print "Found X task(s)"
    
    printf("Error: displayTasksByPriority not implemented yet\n");
}

// TODO (Person 3): Implement this function
// Display tasks filtered by completion status
void displayTasksByStatus(const TaskList* list, int isCompleted) {
    // TODO:
    // 1. Print header ("Completed" or "Pending")
    // 2. Print table header
    // 3. Loop through tasks
    // 4. If task.isCompleted matches status, print the task
    // 5. Count matches
    // 6. Print "Found X task(s)"
    
    printf("Error: displayTasksByStatus not implemented yet\n");
}

// TODO (Person 3): Implement this function
// Display tasks within a date range
void displayTasksByDateRange(const TaskList* list, const char* startDate, const char* endDate) {
    // TODO:
    // 1. Print header with date range
    // 2. Print table header
    // 3. Loop through tasks
    // 4. Compare task.dueDate with startDate and endDate
    //    Hint: Use strcmp() - dates in YYYY-MM-DD format compare correctly
    //    If startDate <= task.dueDate <= endDate, print the task
    // 5. Count matches
    // 6. Print "Found X task(s)"
    
    printf("Error: displayTasksByDateRange not implemented yet\n");
}

// TODO (Person 3): Implement this function
// Search for tasks by keyword (case-insensitive)
void searchTasksByKeyword(const TaskList* list, const char* keyword) {
    // TODO:
    // 1. Check if keyword is empty
    // 2. Print header "Search Results for: [keyword]"
    // 3. Print table header
    // 4. Loop through tasks:
    //    - Convert task title to lowercase (make a copy first)
    //    - Convert task description to lowercase
    //    - Convert keyword to lowercase
    //    - Use strstr() to check if keyword is in title or description
    //    - If found, print the task
    // 5. Count matches
    // 6. Print "Found X task(s)"
    
    printf("Error: searchTasksByKeyword not implemented yet\n");
}
