//start of planner
#include<iostream>
#include<string>
#include<list>
#include<ctime>
using namespace std;


//TodItem class number 1 
class TodoItem {
private:
    int id;
    string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(string new_description) {
        //generates random integer from 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }


    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

};

//main integer
int main()
{
    //version
    string version = "v-1.0.0";
    //todoitem list
    list<TodoItem> TodoItems;
    list<TodoItem>::iterator it;

    srand(time(NULL));

    //todoitem loop to show items constantly
    TodoItems.clear();

    TodoItem test;
    test.create("this is a test");
    TodoItems.push_back(test);


    while (1)
    {
        system("cls");
        cout << "todolist,Maker - " << version << endl;
        cout << endl << endl;


        for (it = TodoItems.begin(); it != TodoItems.end(); it++)
        {
            cout << it->getId() << " | " << it->getDescription() << " | " << it->isCompleted() << endl;

        }

        break;
    }





    return 0;
}
