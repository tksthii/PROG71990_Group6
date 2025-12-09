#ifndef MENU_H
#define MENU_H

#include "taskList.h"

// Menu display and handling
void displayMainMenu(void);
void handleMenuChoice(TaskList* list, int choice, int* running);

// Input helpers
void clearInputBuffer(void);
void pressEnterToContinue(void);

// Internal handler functions (called by handleMenuChoice):
void handleAddTask(TaskList* list);
void handleDeleteTask(TaskList* list);
void handleUpdateTask(TaskList* list);
void handleViewSingle(TaskList* list);
void handleViewByRange(TaskList* list);
void handleSearch(TaskList* list);

#endif
