#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name; // Название задачи
    string description; // Описание задачи
    string dueDate; //Срок выполнения задачи
    bool completed; // Статус выполнения задачи

    //Отображение информации о задаче
    Task(const string& name = "", const string& description = "", const string& dueDate = "")
        : name(name)
        , description(description)
        , dueDate(dueDate)
        , completed(false)
    {}

    // Отображение информации о задаче
    void displayTask() const
    {
        cout << name << " ("
            << (completed ? "Completed" : "Pending")
            << ") - Due: " << dueDate << endl
            << "   Description: " << description << endl;
    }

    // Отметить задачу как выполненную
    void markCompleted() { completed = true; }
};
