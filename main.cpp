#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// We have used Arrays to store item information
string itemCode[] = {
    // The following are item codes for each item
    "A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3", "F1", "F2", "G1", "G2"
};

string itemCategory[] = {
    // The categories are
    "Case", "Case", "RAM", "RAM", "RAM", "Main Hard Disk Drive", "Main Hard Disk Drive", "Main Hard Disk Drive",
    "Solid State Drive", "Solid State Drive", "Second Hard Disk Drive", "Second Hard Disk Drive", "Second Hard Disk Drive",
    "Optical Drive", "Optical Drive", "Operating System", "Operating System"
};

string itemDescription[] = {
    // The following are the item descriptions of the codes above
    "A1 Compact", "A2 Tower", "B1 8 GB", "B2 16 GB", "B3 32 GB", "C1 1 TB HDD", "C2 2 TB HDD", "C3 4 TB HDD",
    "D1 240 GB SSD", "D2 480 GB SSD", "E1 1 TB HDD", "E2 2 TB HDD", "E3 4 TB HDD", "F1 DVD/Blu-Ray Player",
    "F2 DVD/Blu-Ray Re-writer", "G1 Standard Version", "G2 Professional Version"
};

double itemPrice[] = {
    75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00
};

// Function to display available items
void displayItems() {
    cout << "Available Items:\n";
    for (int i = 0; i < 17; i++) {
        cout << "Category: " << itemCategory[i] << "\n";
        cout << "Item Code: " << itemCode[i] << "\n";
        cout << "Description: " << itemDescription[i] << "\n";
        cout << "Price: $" << itemPrice[i] << "\n";
    }
}

int main() {
    cout <<"AICP Internship Week 1 task";

    // Basic set of components price
    double basicComponentsPrice = 200.0;

    // Variables to store user choices
    string selectedCase, selectedRAM, selectedHDD;
    int additionalItemsCount;

    // Display available items
    displayItems();

    // User selects one case, one RAM, and one HDD
    cout << "Select one case (Enter item code): ";
    cin >> selectedCase;
    cout << "Select one RAM (Enter item code): ";
    cin >> selectedRAM;
    cout << "Select one Main Hard Disk Drive (Enter item code): ";
    cin >> selectedHDD;

    // Calculate the total price
    double totalPrice = basicComponentsPrice;
    for (int i = 0; i < 17; i++) {
        if (itemCode[i] == selectedCase || itemCode[i] == selectedRAM || itemCode[i] == selectedHDD) {
            totalPrice += itemPrice[i];
        }
    }

    // Display the chosen items and the current total price
    cout << "\nChosen Items:\n";
    cout << "Case: " << selectedCase << " - " << itemDescription[find(itemCode, itemCode + 17, selectedCase) - itemCode] << " ($" << itemPrice[find(itemCode, itemCode + 17, selectedCase) - itemCode] << ")\n";
    cout << "RAM: " << selectedRAM << " - " << itemDescription[find(itemCode, itemCode + 17, selectedRAM) - itemCode] << " ($" << itemPrice[find(itemCode, itemCode + 17, selectedRAM) - itemCode] << ")\n";
    cout << "Main Hard Disk Drive: " << selectedHDD << " - " << itemDescription[find(itemCode, itemCode + 17, selectedHDD) - itemCode] << " ($" << itemPrice[find(itemCode, itemCode + 17, selectedHDD) - itemCode] << ")\n";
    cout << "Current Total Price: $" << totalPrice << endl;

   // Option to add more items

char addMoreItems;
cout << "Do you want to purchase additional items? (Y/N): ";
cin >> addMoreItems;



if (addMoreItems == 'Y' || addMoreItems == 'y') {
    string selectedItem;

    do {
        cout << "Enter the item code of the additional item you want to purchase: ";
        cin >> selectedItem;

        for (int i = 0; i < 17; i++) {
            if (itemCode[i] == selectedItem) {
                totalPrice += itemPrice[i];
                cout << "Added Item: " << selectedItem << " - " << itemDescription[i] << " ($" << itemPrice[i] << ")\n";
                additionalItemsCount++;
                break;
            }
        }

        cout << "Do you want to add another item? (Y/N): ";
        cin >> addMoreItems;

    } while ((addMoreItems == 'Y' || addMoreItems == 'y') && additionalItemsCount < 2); // Allow up to two additional items
}


    // Apply discounts based on the number of additional items
    double discount = 0.0;
    if (additionalItemsCount == 1) {
        discount = 0.05 * totalPrice; // 5% discount for one additional item
    } else if (additionalItemsCount >= 2) {
        discount = 0.10 * totalPrice; // 10% discount for two or more additional items
    }

    totalPrice -= discount;

    // Display the amount of money saved and the updated total price
    cout << "Amount Saved: $" << discount << endl;
    cout << "Updated Total Price: $" << totalPrice << endl;

    return 0;
}
