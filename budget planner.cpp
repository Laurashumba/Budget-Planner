#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

struct Transaction {
    string date;
    string description;
    double amount;
    string category;
};

vector<Transaction> transactions;
unordered_map<string, double> budget;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addTransaction() {
    Transaction transaction;
    
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> transaction.date;
    
    cout << "Enter description: ";
    cin >> transaction.description;
    
    cout << "Enter amount: ";
    cin >> transaction.amount;
    
    cout << "Enter category: ";
    cin >> transaction.category;

    transactions.push_back(transaction);
    cout << "Transaction added successfully.\n";
}

void setBudget() {
    cout << "Enter budget for each category:\n";

    for (const auto& category : transactions) {
        double budgetAmount;
        cout << "Enter budget for " << category.category << ": ";
        cin >> budgetAmount;

        budget[category.category] = budgetAmount;
    }
}

void displayBudgetSummary() {
    cout << "Budget Summary:\n";

    for (const auto& entry : budget) {
        double totalExpenses = 0.0;

        for (const auto& transaction : transactions) {
            if (transaction.category == entry.first) {
                totalExpenses += transaction.amount;
            }
        }

        cout << "Category: " << entry.first << ", Budget: " << entry.second
                  << ", Expenses: " << totalExpenses << ", Remaining Budget: "
                  << entry.second - totalExpenses << "\n";
    }
}

void displayFinancialSummary() {
    double totalIncome = 0.0;
    double totalExpenses = 0.0;

    for (const auto& transaction : transactions) {
        if (transaction.amount > 0) {
            totalIncome += transaction.amount;
        } else {
            totalExpenses += transaction.amount;
        }
    }

    cout << "Financial Summary:\n";
    cout << "Total Income: " << totalIncome << "\n";
    cout << "Total Expenses: " << totalExpenses << "\n";
    cout << "Net Balance: " << totalIncome + totalExpenses << "\n";
}

int main() {
    while (true) {
        cout << "Options:\n";
        cout << "1. Add Transaction\n";
        cout << "2. Set Budget\n";
        cout << "3. Display Budget Summary\n";
        cout << "4. Display Financial Summary\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                setBudget();
                break;
            case 3:
                displayBudgetSummary();
                break;
            case 4:
                displayFinancialSummary();
                break;
            case 5:
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again.\n";
                clearInputBuffer();
        }
    }

    return 0;
}
