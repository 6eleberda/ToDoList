#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name = "";          // Ќазвание задачи по умолчанию Ч пуста€ строка
    string description = "";    // ќписание задачи по умолчанию Ч пуста€ строка
    string dueDate = "";        // —рок выполнени€ задачи по умолчанию Ч пуста€ строка
    bool completed = false;
    //ќтображение информации о задаче
  

    // ќтображение информации о задаче
    void displayTask() const
    {
        cout << name << " ("
            << (completed ? "Completed" : "Pending")
            << ") - Due: " << dueDate << endl
            << "   Description: " << description << endl;
    }

    // ќтметить задачу как выполненную
    void markCompleted() { completed = true; }
};
