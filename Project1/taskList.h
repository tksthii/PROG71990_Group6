/*
 * taskList.h
 * Author: Person 1
 * Description: Task list management and file I/O operations
 * 
 * TODO (Person 1):
 * - Implement all functions in taskList.c
 * - Handle file I/O operations carefully
 */

#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"

#define MAX_TASKS 100

// Task list structure
typedef struct {
    Task tasks[MAX_TASKS];
    int count;
    int nextId;
} TaskList;

// TODO (Person 1): Implement these functions in taskList.c

// Initialize an empty task list
void initTaskList(TaskList* list);

// Get current task count
int getTaskCount(const TaskList* list);

// Get next available ID
int getNextId(const TaskList* list);

// Save all tasks to file
// Returns 1 on success, 0 on failure
int saveTasksToFile(const TaskList* list, const char* filename);

// Load tasks from file
// Returns 1 on success, 0 on failure
int loadTasksFromFile(TaskList* list, const char* filename);

#endif
