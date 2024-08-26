#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Expense {
    string category;
    double amount;
};

void addExpense(vector<Expense>& expenses) {
    Expense exp;
    cout << "Enter category: ";
    getline(cin, exp.category);
    cout << "Enter amount: ";
    cin >> exp.amount;
    cin.ignore();  
    expenses.push_back(exp);
}
void subtractExpense(vector<Expense>& expenses) {
    string category;
    double amount;
    cout << "Enter category to subtract from: ";
    getline(cin, category);
    cout << "Enter amount to subtract: ";
    cin >> amount;
    cin.ignore(); 
    bool found = false;
    for (auto& exp : expenses) {
        if (exp.category == category) {
            exp.amount -= amount;
            if (exp.amount < 0) exp.amount = 0;  
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Category not found" << endl;
    }
}
void showSummary(const vector<Expense>& expenses) {
    double total = 0;
    cout << "Expenses: " << endl;
    for (const auto& exp : expenses) {
        cout << exp.category << ": " << exp.amount << endl;
        total += exp.amount;
    }
    cout << "Total: " << total << endl;
}

int main() {
    vector<Expense> expenses;
    string command;
    cout << "Hello, and welcome to Tanisha's personal finance chatbot." << endl;
    cout << "To add a category please type 'add' " << endl;
    cout << "To subtract a category please type 'subtract' " << endl;
    cout << "To get the summary of expenses  please type 'summary' " << endl;
    while (true) {
        cout << "Enter command: ";
        getline(cin, command);

        if (command == "add") {
            addExpense(expenses);
        } else if (command == "subtract") {
            subtractExpense(expenses);
        } else if (command == "summary") {
            showSummary(expenses);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command. Try 'add', 'subtract', 'summary', or 'exit'.\n";
        }
    }
    return 0;
}