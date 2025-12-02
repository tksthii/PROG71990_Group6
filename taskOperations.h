/*
 * TODO:
 * - Implement all CRUD functions in taskOperations.c
 * - Add input validation
 * - Write unit tests
 */

#ifndef TASKOPERATIONS_H
#define TASKOPERATIONS_H

#include "taskList.h"

// Add a new task to the list
// Returns 1 on success, 0 on failure
int addTask(TaskList* list, const char* title, const char* description,
            const char* dueDate, Priority priority);

// Delete a task by ID
// Returns 1 on success, 0 on failure
int deleteTask(TaskList* list, int id);

// Update an existing task by ID
// Returns 1 on success, 0 on failure
int updateTask(TaskList* list, int id);

// Display a single task by ID
// Returns 1 on success, 0 on failure
int displayTaskById(const TaskList* list, int id);

// Helper function: Find task index by ID
// Returns index if found, -1 if not found
int findTaskIndexById(const TaskList* list, int id);

// Helper function: Validate date format (YYYY-MM-DD)
// Returns 1 if valid, 0 if invalid
int isValidDate(const char* date);

#endif
