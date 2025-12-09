/*
 * display.h
 * Author: Person 3
 * Description: Display and search operations
 * 
 * TODO (Person 3):
 * - Implement all display and search functions in display.c
 * - Format output nicely
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "taskList.h"

// TODO (Person 3): Implement these functions in display.c

// Display all tasks in the list
void displayAllTasks(const TaskList* list);

// Display tasks filtered by priority
void displayTasksByPriority(const TaskList* list, Priority priority);

// Display tasks filtered by status (completed or pending)
void displayTasksByStatus(const TaskList* list, int isCompleted);

// Display tasks within a date range
void displayTasksByDateRange(const TaskList* list, const char* startDate, const char* endDate);

// Search for tasks by keyword in title or description
void searchTasksByKeyword(const TaskList* list, const char* keyword);

#endif
