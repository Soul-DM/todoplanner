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

    char input_option;
    int input_id;

    //version
    string version = "v-1.0.0";
    //todoitem list
    list<TodoItem> TodoItems;
    list<TodoItem>::iterator it;

    srand(time(NULL));

    //todoitem loop to show items constantly
    TodoItems.clear();

    //TodoItem test;
    //test.create("this is a test");
    //TodoItems.push_back(test);


    while (1)
    {
        system("cls");
        cout << "todolist,Maker - " << version << endl;
        cout << endl << endl;


        for (it = TodoItems.begin(); it != TodoItems.end(); it++)
        {
            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " | " << it->getDescription() << " | " << completed << endl;

        }
        if (TodoItems.empty())
        {
            cout<<"Add your Todo!"<<endl;

        }
        cout<<"[a]dd a new Todo"<<endl;
        cout<<"[c]omplete a Todo"<<endl;
        cout<<"[q]uit"<<endl;

        cout<<"choice: ";

        cin>>input_option;

        if(input_option == 'q')
        {
            cout<<"YOU TRAITOR!!!"<<endl;
            break;
        } else if(input_option == 'c')
        {
            cout<<"Enter id to mark completed"<<endl;
            cin>>input_id;


            for (it = TodoItems.begin(); it != TodoItems.end(); it++)
        {
           if(input_id == it->getId())
           {
            it->serCompleted(true);
            break;
           }
        }



        }
    }
    return 0;
}