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
	cout << "\n===Your Tasks===\n";
	for (size_t i = 0; i < tasks.size();i++) {
		cout << i + 1 << ". " << tasks[i] << endl;
	}
	//ask user for the task number
	cout << "\nEnter the number of the task you want to delete: \n";
	int taskNumber;
	cin >> taskNumber;

	//validate user imput

	if (cin.fail() || taskNumber < 1 || taskNumber > tasks.size()) {
		cin.clear(); //Clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard bad input
		cout << "\n===invalid task number!===\n";
		return;
	}

	//Erase task from vector

	tasks.erase(tasks.begin() + (taskNumber - 1));

	cout << "\n=== Task deleted ===\n";

}

void saveTasksToFile(const vector<string>& tasks) {

	ofstream file("tasks.txt"); //Open the file
	if (!file) { //checks if the file is opened
		cout << "Error: Could not open the file...";
		return;
	}
	for (const string& task : tasks) {
		file << task << endl; //Write each task to the file
	}
	file.close();
	cout << "Tasks Saved";
}

void loadTasksFromFile(vector<string>& tasks){

	ifstream file("tasks.txt");

	if (!file) {
		return;
	}
	
	string task;
	while (getline(file, task)) {//read task line by line
		if (!task.empty()) { //ignore empty line
			tasks.push_back(task);
		}
	}
	file.close();

	cout << "tasks loaded\n";
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