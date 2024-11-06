#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

// Определение структуры ToDoList
struct ToDoList {
    Task tasks[100]; // Массив задач
    int taskCount; // Количество задач в списке

    // Конструктор для инициализации количества задач
    ToDoList() : taskCount(0) {}

    // Отображение меню
    void displayMenu()
    {
        cout
            << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Edit Task\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------" "\n";
    }

    // Добавить новую задачу
    void addTask()
    {
        if (taskCount >= 100) {
            cout << "Task list is full!" << endl;
            return;
        }
        string name;
        string description;
        string dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        tasks[taskCount++] = Task(name, description, dueDate);
        cout << "Task added successfully!" << endl;
    }

    //  Удалить задачу
    void deleteTask()
    {
        if (taskCount == 0) {
            cout << "No tasks to delete" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". " << tasks[i].name
                << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= taskCount) {
            for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1]; // Сдвиг задач влево
            }
            --taskCount;
            cout << "Task deleted successfully" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Показать все задачи
    void displayTasks()
    {
        if (taskCount == 0) {
            cout << "No tasks to display" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    // Отметить задачу как выполненную
    void markTaskCompleted()
    {
        if (taskCount == 0) {
            cout << "No tasks to mark as completed!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". " << tasks[i].name
                << endl;
        }
        cout << "Enter the task number to mark as completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= taskCount) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed" << endl;
        }
        else {
            cout << "Invalid task number" << endl;
        }
    }

    // Редактировать задачу
    void editTask()
    {
        if (taskCount == 0) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". " << tasks[i].name << endl;
        }
        cout << "Enter the task number to edit: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= taskCount) {
            Task& task = tasks[taskNumber - 1];
            string name, description, dueDate;
            cout << "Enter new task name (current: "
                << task.name << "): ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new task description (current: "
                << task.description << "): ";
            getline(cin, description);
            cout << "Enter new task date (current: "
                << task.dueDate << "): ";
            getline(cin, dueDate);

            task.name = name;
            task.description = description;
            task.dueDate = dueDate;
            cout << "Task updated successfully" << endl;
        }
        else {
            cout << "Invalid task number" << endl;
        }
    }

    // Запуск приложения списка задач
    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                markTaskCompleted();
                break;
            case 5:
                editTask();
                break;
            case 6:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again" << endl;
            }
        } while (choice != 6);
    }
};