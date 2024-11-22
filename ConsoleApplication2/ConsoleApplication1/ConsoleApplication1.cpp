#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100; 

struct TodoList {
    string tasks[MAX_TASKS]; 
    int taskCount = 0; 
 
    void addTask(string task) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount] = task; 
            cout << "Task added: " << task << endl;
            taskCount++; 
        }
        else {
            cout << "Task list is full!" << endl;
        }
    }
    
    void removeTask(int index) {
        if (index >= 0 && index < taskCount) { 
            cout << "Task deleted: " << tasks[index] << endl;
            
            for (int i = index; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--; 
        }
        else {
            cout << "Incorrect index!" << endl;
        }
    }
    
    void displayTasks() {
        if (taskCount == 0) { 
            cout << "The task list is empty." << endl;
            return;
        }

        cout << "Task list:" << endl;
        for (int i = 0; i < taskCount; i++) {
            cout << i << ": " << tasks[i] << endl; 
        }
    }
};

int main() {
    TodoList todoList; 
    int choice; 
    string task;
    int index; 

  
    while (true) {
        cout << "\n1. Add a task\n2. Remove a task\n3. Show tasks\n0. Exit\nSelect an option: ";
        cin >> choice; 
        cin.ignore(); 

        
        if (choice == 1) {
            cout << "Enter the task: ";
            getline(cin, task); 
            todoList.addTask(task); 
        }
        else if (choice == 2) {
            todoList.displayTasks(); 
            cout << "Enter the index of the task to be deleted: ";
            cin >> index; 
            todoList.removeTask(index); 
        }
        else if (choice == 3) {
            todoList.displayTasks(); 
        }
        else if (choice == 0) {
            cout << "Exiting the program." << endl; 
            break; 
        }
        else {
            cout << "Incorrect choice, try again." << endl; 
        }
    }

    return 0; 
}