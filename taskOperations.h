/*
 * This module provides all CRUD (Create, Read, Update, Delete) operations
 * for managing tasks in the To-Do Manager application.
 */

#ifndef TASKOPERATIONS_H
#define TASKOPERATIONS_H

#include "taskList.h"

// CRUD Operations
int addTask(TaskList* list, const char* title, const char* description,
            const char* dueDate, Priority priority);

int deleteTask(TaskList* list, int id);

int updateTask(TaskList* list, int id);

int displayTaskById(const TaskList* list, int id);

// Helper functions
int findTaskIndexById(const TaskList* list, int id);
int isValidDate(const char* date);

#endif