#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name = "";          // �������� ������ �� ��������� � ������ ������
    string description = "";    // �������� ������ �� ��������� � ������ ������
    string dueDate = "";        // ���� ���������� ������ �� ��������� � ������ ������
    bool completed = false;
    //����������� ���������� � ������
  

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
