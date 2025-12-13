#include "task.h"
#include <stdio.h>
#include <string.h>


// Create a new task with the given parameters
Task createTask(int id, const char* title, const char* description, 
                const char* dueDate, Priority priority) {
                     
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

void printTaskHeader(void) {

    printf("%-4s | %-20s | %-12s | %-8s | %-10s\n",
           "ID", "Title", "Due Date", "Priority", "Status");
    printf("-------------------------------------------------------------\n");
    // Use printf with proper spacing
    printf("%-4s | %-20s | %-12s | %-8s | %-10s\n",
           "ID", "Title", "Due Date", "Priority", "Status");// Column headers
    printf("-------------------------------------------------------------\n");// Separator line
}


// Print a single task in table format
void printTask(const Task* task) {
    // Use priorityToString() and check isCompleted for status
    const char* status;
    if(task->isCompleted)
    {
        status = "Completed";
    
    }
    else{
        status = "Pending";
    }
    printf("%-4s | %-20s | %-12s | %-8s | %-10s\n",
       task->id,task->title,task->dueDate,priorityToString(task->priority),status);
}

// Convert priority enum to string
const char* priorityToString(Priority p) {
    // LOW -> "Low"
    // MEDIUM -> "Medium"
    // HIGH -> "High"
    switch(p)
    {
        case LOW:
            return "Low";

        case MEDIUM:
            return "Medium";

        case HIGH:
            return "High";
        
        default:
            return "Unknown";
        
    }
    
}

// Convert integer to priority enum
Priority stringToPriority(int p) {
    // Default to MEDIUM if invalid
    switch(p)
    {
        case 1:
            return LOW;

        case 2:
            return MEDIUM;
        
        case 3:
            return HIGH;
        
        default:
            return MEDIUM;
    }
    
   
}
