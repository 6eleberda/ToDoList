#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name; // �������� ������
    string description; // �������� ������
    string dueDate; //���� ���������� ������
    bool completed; // ������ ���������� ������

    //����������� ���������� � ������
    Task(const string& name = "", const string& description = "", const string& dueDate = "")
        : name(name)
        , description(description)
        , dueDate(dueDate)
        , completed(false)
    {}

    // ����������� ���������� � ������
    void displayTask() const
    {
        cout << name << " ("
            << (completed ? "Completed" : "Pending")
            << ") - Due: " << dueDate << endl
            << "   Description: " << description << endl;
    }

    // �������� ������ ��� �����������
    void markCompleted() { completed = true; }
};
