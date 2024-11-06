#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_TASKS = 100;
const int MAX_TITLE = 50;
const int MAX_DATE = 20;
const int MAX_DESC = 100;

struct Task {
    char title[MAX_TITLE];
    char dueDate[MAX_DATE];
    char description[MAX_DESC];
    bool isCompleted = false;
};
