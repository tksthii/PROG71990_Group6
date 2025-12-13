/*
 * display.c
 * Author: Person 3
 * Description: Implementation of display and search operations
 */

#include "display.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // Included for general string utilities if needed, though most are in string.h

 // --- ASSUMED EXTERNAL DEFINITIONS (for internal use) ---
 // Note: These definitions assume Task and TaskList structure from the project context.
 // For example, assuming Task struct members like title, description, dueDate, etc.

 // Helper function to convert Priority enum to a string for display headers.
 // (This is often required if printTaskHeader/printTask don't handle it directly)
static const char* priorityToString(Priority p) {
    switch (p) {
    case LOW: return "LOW";
    case MEDIUM: return "MEDIUM";
    case HIGH: return "HIGH";
    default: return "UNKNOWN";
    }
}
// -------------------------------------------------------


// TODO (Person 3): Implement this helper function
// Convert string to lowercase for case-insensitive search
void toLowerCase(char* str) {
    // TODO: Loop through string and convert each character to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        // Use tolower for conversion; cast to unsigned char is good practice for ctype functions
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

// TODO (Person 3): Implement this function
// Display all tasks in a formatted table
void displayAllTasks(const TaskList* list) {
    // TODO:
    // 1. Check if list is empty (count == 0)
    if (list->count == 0) {
        // 2. If empty, print "No tasks found" and return
        printf("No tasks found.\n");
        return;
    }
    // 3. Print header (e.g., "=== ALL TASKS ===")
    printf("\n=== ALL TASKS (%d Total) ===\n", list->count);

    // 4. Call printTaskHeader() (from Person 1)
    printTaskHeader();

    // 5. Loop through all tasks and call printTask() for each
    for (int i = 0; i < list->count; i++) {
        printTask(&list->tasks[i]);
    }

    // 6. Print footer line
    printf("----------------------------------------\n");
}

// TODO (Person 3): Implement this function
// Display tasks filtered by priority level
void displayTasksByPriority(const TaskList* list, Priority priority) {
    int matchCount = 0;

    // 1. Print header with priority level
    printf("\n=== TASKS with Priority: %s ===\n", priorityToString(priority));

    // 2. Print table header
    printTaskHeader();

    // 3. Loop through tasks
    for (int i = 0; i < list->count; i++) {
        // 4. If task.priority matches, print the task
        if (list->tasks[i].priority == priority) {
            printTask(&list->tasks[i]);
            matchCount++;
        }
    }

    // 5. Count how many tasks match (done in loop)
    // 6. Print "Found X task(s)"
    printf("----------------------------------------\n");
    printf("Found %d task(s) with %s priority.\n", matchCount, priorityToString(priority));

    if (matchCount == 0) {
        printf("No tasks found with %s priority.\n");
    }
}

// TODO (Person 3): Implement this function
// Display tasks filtered by completion status
void displayTasksByStatus(const TaskList* list, int isCompleted) {
    int matchCount = 0;
    const char* statusStr = isCompleted ? "Completed" : "Pending";

    // 1. Print header ("Completed" or "Pending")
    printf("\n=== %s TASKS ===\n", statusStr);

    // 2. Print table header
    printTaskHeader();

    // 3. Loop through tasks
    for (int i = 0; i < list->count; i++) {
        // 4. If task.isCompleted matches status, print the task
        if (list->tasks[i].isCompleted == isCompleted) {
            printTask(&list->tasks[i]);
            matchCount++;
        }
    }

    // 5. Count matches (done in loop)
    // 6. Print "Found X task(s)"
    printf("----------------------------------------\n");
    printf("Found %d %s task(s).\n", matchCount, statusStr);

    if (matchCount == 0) {
        printf("No %s tasks found.\n", statusStr);
    }
}

// TODO (Person 3): Implement this function
// Display tasks within a date range
void displayTasksByDateRange(const TaskList* list, const char* startDate, const char* endDate) {
    int matchCount = 0;

    // 1. Print header with date range
    printf("\n=== TASKS Due Between %s and %s ===\n", startDate, endDate);

    // 2. Print table header
    printTaskHeader();

    // 3. Loop through tasks
    for (int i = 0; i < list->count; i++) {
        const char* dueDate = list->tasks[i].dueDate;

        // 4. Compare task.dueDate with startDate and endDate
        // If startDate <= task.dueDate (strcmp result >= 0) AND task.dueDate <= endDate (strcmp result <= 0), print the task
        if (strcmp(dueDate, startDate) >= 0 && strcmp(dueDate, endDate) <= 0) {
            printTask(&list->tasks[i]);
            matchCount++;
        }
    }

    // 5. Count matches
    // 6. Print "Found X task(s)"
    printf("----------------------------------------\n");
    printf("Found %d task(s) in date range.\n", matchCount);

    if (matchCount == 0) {
        printf("No tasks found in the specified date range.\n");
    }
}

// TODO (Person 3): Implement this function
// Search for tasks by keyword (case-insensitive)
void searchTasksByKeyword(const TaskList* list, const char* keyword) {
    int matchCount = 0;

    // 1. Check if keyword is empty
    if (keyword == NULL || keyword[0] == '\0') {
        printf("Error: Search keyword cannot be empty.\n");
        return;
    }

    // Prepare a lowercase copy of the search keyword (Assuming max keyword length is less than 100)
    char lowerKeyword[100];
    strncpy(lowerKeyword, keyword, sizeof(lowerKeyword) - 1);
    lowerKeyword[sizeof(lowerKeyword) - 1] = '\0';
    toLowerCase(lowerKeyword);

    // 2. Print header "Search Results for: [keyword]"
    printf("\n=== Search Results for: \"%s\" ===\n", keyword);

    // 3. Print table header
    printTaskHeader();

    // 4. Loop through tasks:
    for (int i = 0; i < list->count; i++) {
        const Task* currentTask = &list->tasks[i];

        // --- Create lowercase copies for case-insensitive search ---
        // VLA used here assuming title and description size from Task struct (e.g. 100/256)
        // If VLA is not supported or sizes are unknown, dynamic memory allocation would be safer.
        // Assuming currentTask->title is max 100 and description max 256 for buffer size calculation
        char lowerTitle[100]; // Assume max size based on common Task struct
        char lowerDescription[256]; // Assume max size based on common Task struct

        // Copy and convert Title
        strncpy(lowerTitle, currentTask->title, sizeof(lowerTitle) - 1);
        lowerTitle[sizeof(lowerTitle) - 1] = '\0';
        toLowerCase(lowerTitle);

        // Copy and convert Description
        strncpy(lowerDescription, currentTask->description, sizeof(lowerDescription) - 1);
        lowerDescription[sizeof(lowerDescription) - 1] = '\0';
        toLowerCase(lowerDescription);

        // - Use strstr() to check if keyword is in title or description
        if (strstr(lowerTitle, lowerKeyword) != NULL || strstr(lowerDescription, lowerKeyword) != NULL) {
            // - If found, print the task
            printTask(currentTask);
            matchCount++;
        }
    }

    // 5. Count matches
    // 6. Print "Found X task(s)"
    printf("----------------------------------------\n");
    printf("Found %d task(s) matching keyword \"%s\".\n", matchCount, keyword);

    if (matchCount == 0) {
        printf("No tasks found matching the keyword.\n");
    }
}