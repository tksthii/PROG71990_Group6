/*
 * task.h
 * Author: Person 1
 * Description: Task ADT - defines the task structure and basic operations
 * 
 * TODO (Person 1):
 * - Review and modify task structure if needed
 * - Implement all functions in task.c
 */

#ifndef TASK_H
#define TASK_H

#define MAX_TITLE 100
#define MAX_DESC 256
#define MAX_DATE 11

// Priority levels
typedef enum {
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3
} Priority;

// Task structure
typedef struct {
    int id;
    char title[MAX_TITLE];
    char description[MAX_DESC];
    char dueDate[MAX_DATE];  // Format: YYYY-MM-DD
    Priority priority;
    int isCompleted;  // 0 = not done, 1 = done
} Task;

// TODO (Person 1): Implement these functions in task.c

// Create a new task with given parameters
Task createTask(int id, const char* title, const char* description, 
                const char* dueDate, Priority priority);

// Print task in table format
void printTask(const Task* task);

// Print table header
void printTaskHeader(void);

// Convert priority enum to string
const char* priorityToString(Priority p);

// Convert integer to priority enum
Priority stringToPriority(int p);

#endif
