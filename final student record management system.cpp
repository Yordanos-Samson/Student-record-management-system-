#include <iostream>
#include <string>

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int id;
    string department;
    Student* next;
};

// Function to create a new student record
Student* createRecord(string name, int id, string department) {
    Student* newStudent = new Student;
    newStudent->name = name;
    newStudent->id = id;
    newStudent->department = department;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student record
void insertRecord(Student*& head, string name, int id, string department) {
    Student* newStudent = createRecord(name, id, department);

    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    cout << "Record inserted successfully." << endl;
}

// Function to delete a student record
void deleteRecord(Student*& head, string name) {
    if (head == NULL) {
        cout << "Record not found. List is empty." << endl;
        return;
    }

    if (head->name == name) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Record deleted successfully." << endl;
        return;
    }

    Student* prev = NULL;
    Student* curr = head;
    while (curr != NULL && curr->name != name) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Record not found." << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Record deleted successfully." << endl;
}

// Function to display all student records
void showRecords(Student* head) {
    if (head == NULL) {
        cout << "No records found." << endl;
        return;
    }

    Student* temp = head;
    cout << "Student Records:" << endl;
    while (temp != NULL) {
    	cout<<" "<<endl;
        cout << "Name: " << temp->name << ", ID: " << temp->id << ", Department: " << temp->department << endl;
        temp = temp->next;
    }
}

// Function to search for a student record by name
void searchRecord(Student* head, string name) {
    if (head == NULL) {
        cout << "Record not found. List is empty." << endl;
        return;
    }

    Student* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Record found:" << endl;
            cout << "Name: " << temp->name << ", ID: " << temp->id << ", Department: " << temp->department << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found." << endl;
}

void developer_info()
{
     cout<<"======STUDENT Record Management System DEVELOPMENT======\n\n";
     cout<<"===============\n";
     cout<<"1. Yordanos Samson\n\n";
     cout<<"2. Elsabet Wondifraw\n\n";
     cout<<"PRESS ANY KEY BACK TO MANU";

}

int main() {
    Student* head = NULL;
    int choice;
    string name, department;
    int id;

    while (true) {
        system("cls");
        cout << "\nStudent Record Management System\n";
        cout << "1. Student Members info\n";
        cout << "2. Insert Student Record\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Show All Student Records\n";
        cout << "5. Search Student Record by Name\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	case 1:
        		  {
				  developer_info();
        		  break;}
            case 2:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter department: ";
                cin >> department;
                insertRecord(head, name, id, department);
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                deleteRecord(head, name);
                break;
            case 4:
                showRecords(head);
                break;
            case 5:
                cout << "Enter name to search: ";
                cin >> name;
                searchRecord(head, name);
                break;
            case 6:
                // Free memory (not necessary for this simple example, but good practice)
                while (head != NULL) {
                    Student* temp = head;
                    head = head->next;
                    delete temp;
                }
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << ""<<endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

