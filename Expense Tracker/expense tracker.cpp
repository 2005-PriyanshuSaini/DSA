#include <iostream>
#include <string>

using namespace std;

// Define a struct for an expense
struct Expense {
    string description;
    double amount;
    Expense* next;
};

// Define a class for the expense tracker
class ExpenseTracker {
private:
    Expense* head;

public:
    ExpenseTracker() : head(nullptr) {}

    // Add a new expense
    void addExpense(const string& description, double amount) {
        Expense* newExpense = new Expense();
        newExpense->description = description;
        newExpense->amount = amount;
        newExpense->next = head;
        head = newExpense;
    }

    // Show all expenses
    void showExpenses() const {
        if (head == nullptr) {
            cout << "No expenses to show." << endl;
            return;
        }
        Expense* current = head;
        while (current != nullptr) {
            cout << "Description: " << current->description << ", Amount: $" << current->amount << endl;
            current = current->next;
        }
    }

    // Get the total amount of expenses
    double getTotal() const {
        double total = 0.0;
        Expense* current = head;
        while (current != nullptr) {
            total += current->amount;
            current = current->next;
        }
        return total;
    }

    // Delete an expense by description
    void deleteExpense(const string& description) {
        if (head == nullptr) {
            cout << "No expenses to delete." << endl;
            return;
        }

        Expense* current = head;
        Expense* previous = nullptr;

        while (current != nullptr && current->description != description) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Expense with description '" << description << "' not found." << endl;
            return;
        }

        if (previous == nullptr) {
            head = head->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout << "Expense with description '" << description << "' deleted." << endl;
    }

    // Destructor to free the allocated memory
    ~ExpenseTracker() {
        Expense* current = head;
        while (current != nullptr) {
            Expense* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;
    string description;
    double amount;

    do {
        cout << "\nExpense Tracker Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. Show Expenses" << endl;
        cout << "3. Get Total" << endl;
        cout << "4. Delete Expense" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter description: ";
            cin.ignore(); // To ignore the leftover newline character in the buffer
            getline(cin, description);
            cout << "Enter amount: ";
            cin >> amount;
            tracker.addExpense(description, amount);
            break;
        case 2:
            tracker.showExpenses();
            break;
        case 3:
            cout << "Total expenses: $" << tracker.getTotal() << endl;
            break;
        case 4:
            cout << "Enter description of the expense to delete: ";
            cin.ignore(); // To ignore the leftover newline character in the buffer
            getline(cin, description);
            tracker.deleteExpense(description);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
