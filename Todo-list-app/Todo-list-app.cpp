#include <iostream> // For input/output
#include <vector> // for using vectors
#include <fstream> // Required for getline
#include <string> // File handling

using namespace std;

//Function Prototypes
void showMenu() {

	cout << "\n==== TO-DO LIST MENU =====\n";
	cout << "1. Add a Task \n";
	cout << "2. View a task \n";
	cout << "3. Delete a task \n";
	cout << "4. Save Tasks \n";
	cout << "5. Exit\n";
	cout << "Enter your choice: ";
}


void addTask(vector<string>& tasks) {

	cin.ignore(); //clear previous newline characters
	cout << "Enter a task: ";

	string task;
	getline(cin, task);

	if (!task.empty()) {
		tasks.push_back(task);
		cout << "Task added successfully! \n";
	}
	else {
		cout << "Task cannot be empty. try again.\n";
	}
}

void viewTask(const vector<string>& tasks) {
	if (tasks.empty()) {
		cout << "No tasks available.\n";
		return;
	}
	for (size_t i = 0; i < tasks.size(); i++) {
		cout << i + 1 << ". " << tasks[i] << endl;
	}
}
void deleteTask(vector<string>& tasks) {

	if (tasks.empty()) {
		cout << "No tasks to delete!\n";
		return;
	}


}

void saveTasksToFile(const vector<string>& tasks) {


}
void loadTasksFromFile(vector<string>& tasks){


}

int main() {

	vector<string> tasks; //store tasks in memory
	loadTasksFromFile(tasks); //load tasks at the start

	int choice;
	do {
		showMenu();
		cin >> choice;
			
			switch (choice) {
				case 1: addTask(tasks); break;
				case 2: viewTask(tasks); break;
				case 3: deleteTask(tasks); break;
				case 4: saveTasksToFile(tasks); break;
				case 5: cout << "Exiting...\n"; break;
				default: cout << "Invalid choice! Try Again \n";
		}
	} while (choice != 0);

	return 0;
}