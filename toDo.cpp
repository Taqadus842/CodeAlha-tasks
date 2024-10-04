#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
    string taskName;
    string description;
    string dueDate;
    bool isCompleted;

public:
    Task(const string& taskName, const string& description, const string& dueDate) {
        this->taskName = taskName;
        this->description = description;
        this->dueDate = dueDate;
        isCompleted = false;
    }

    void displayTask() const {
        cout << "Task: " << taskName << endl;
        cout << "Due: " << dueDate << endl;
        cout << "Description: " << description << endl;
        cout << "Status: " << (isCompleted ? "Completed" : "Not Completed") << endl;
        cout << "-----------------------------" << endl;  
    }

    void markAsCompleted() {
        isCompleted = true;
    }

    bool isTaskCompleted() const {
        return isCompleted;
    }

    string getTaskName() const {
        return taskName;
    }

    void editTask(const string& newName, const string& newDescription, const string& newDueDate) {
        taskName = newName;
        description = newDescription;
        dueDate = newDueDate;
    }
};

class ToDoApp {
    vector<Task> tasks;

public:
    void displayMenu() {
        cout << "\n===== To-Do Application Menu =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display All Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Edit Task" << endl;
        cout << "5. Delete Completed Tasks" << endl;
        cout << "6. Exit" << endl;
        cout << "==================================" << endl;
        cout << "Enter your choice: ";
    }

    void addTask() {
        string name, description, dueDate;

        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter task description: ";
        getline(cin, description);

        cout << "Enter task due date (yyyy-mm-dd): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task Added!" << endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
            return;
        }
        cout << "\nTasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    void markTaskCompleted() {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed." << endl;
            return;
        }
        displayTasks();

        int taskNo;
        cout << "Enter task number to mark as completed: ";
        cin >> taskNo;

        if (taskNo >= 1 && taskNo <= tasks.size()) {
            tasks[taskNo - 1].markAsCompleted();
            cout << "Marked task as completed!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void editTask() {
        if (tasks.empty()) {
            cout << "No tasks to edit." << endl;
            return;
        }
        displayTasks();

        int taskNo;
        cout << "Enter task number to edit: ";
        cin >> taskNo;

        if (taskNo >= 1 && taskNo <= tasks.size()) {
            string newName, newDescription, newDueDate;

            cout << "Enter new task name: ";
            cin.ignore();
            getline(cin, newName);

            cout << "Enter new task description: ";
            getline(cin, newDescription);

            cout << "Enter new task due date (yyyy-mm-dd): ";
            getline(cin, newDueDate);

            tasks[taskNo - 1].editTask(newName, newDescription, newDueDate);
            cout << "Task updated!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void deleteCompletedTasks() {
        for (int i = tasks.size() - 1; i >= 0; --i) {
            if (tasks[i].isTaskCompleted()) {
                tasks.erase(tasks.begin() + i);
                cout << "Deleted completed task: " << i + 1 << endl;
            }
        }
        cout << "Completed tasks deleted!" << endl;
    }
};

int main() {
    ToDoApp app;
    int choice;

    do {
        app.displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                app.addTask();
                break;
            case 2:
                app.displayTasks();
                break;
            case 3:
                app.markTaskCompleted();
                break;
            case 4:
                app.editTask();
                break;
            case 5:
                app.deleteCompletedTasks();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
