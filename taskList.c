/*
 * taskList.c
 * Author: Lynn
 * Description: Implementation of task list management and file I/O
 */

#include "taskList.h"
#include <stdio.h>
#include <string.h>

// Initialize the task list to empty state
void initTaskList(TaskList* list) {
   
    list->count = 0;
    list->nextId = 1;
}


// Return the current number of tasks
int getTaskCount(const TaskList* list) {
    // TODO: Return list->count
    return list->count;
}


// Return the next available task ID
int getNextId(const TaskList* list) {
    // TODO: Return list->nextId
    return list->nextId;
}

int saveTasksToFile(const TaskList* list, const char* filename) {
    
    FILE* file = fopen("taskmanager.txt", "w");
    if(file == NULL)
    {
        printf("Error: Failed to open the file.\n");
        return 0;
    }
    fprintf(file, "%d\n", list->nextId);
    fprintf(file, "%d\n", list->count);
    for(int i = 0; i < list->count; i++)
    {
        const Task* task = &list->tasks[i];
        fprintf(file, "%d|%s|%s|%s|%d|%d\n",
                task->id,
                task->title,
                task->description,
                task->dueDate,
                task->priority,
                task->isCompleted);
    }
    fclose(file);
    printf("Success: Tasks saved to %s\n", filename);
    return 1;
}


// Load tasks from a file
int loadTasksFromFile(TaskList* list, const char* filename) {
    
    FILE* file = fopen("taskmanager.txt", "r");
    if(file == NULL)
    {
        printf("Info: No existing data file found. Starting fresh.\n");
        return 0;
    }
    initTaskList(list);
    fscanf(file, "%d\n", &list->nextId);
    fscanf(file, "%d\n", &list->count);
    for(int i = 0; i < list->count; i++)
    {
        Task* task = &list->tasks[i];// Get pointer to current task
        fscanf(file, "%d|%[^|]|%[^|]|%[^|]|%d|%d\n",
               &task->id,
               task->title,
               task->description,
               task->dueDate,
               (int*)&task->priority,
               &task->isCompleted);
    }
    fclose(file);
    printf("Success: Loaded %d tasks from %s\n", list->count, "taskmanager.txt");

    return 1;
}
