#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void traverse(const vector<int>& badge, const vector<string>& name, const vector<int>& stock, const vector<int>& price) {
    for (int i = 0; i < badge.size(); i++) {
        cout << badge[i] << ". " << name[i] << ": " << price[i] << " Rupees, Stock: " << stock[i] << endl;
    }
}

void Del(vector<int>& badge, vector<string>& name, vector<int>& stock, vector<int>& price, int index) {
    // Ensure the index is valid
    if (index < 0 || index >= badge.size()) {
        cout << "Invalid index!" << endl;
        return;
    }

    // Shift elements to the left
    for (int i = index; i < badge.size() - 1; i++) {
        badge[i] = badge[i + 1];
        name[i] = name[i + 1];
        stock[i] = stock[i + 1];
        price[i] = price[i + 1];
    }

    // Remove the last element from each vector
    badge.pop_back();
    name.pop_back();
    stock.pop_back();
    price.pop_back();

    cout << "Product deleted successfully!" << endl;
}

void Search(const vector<int>& badge, const vector<string>& name, const vector<int>& stock, const vector<int>& price) {
    string searchOption;
    cout << "Search by (Name, Price, Stock): ";
    cin >> searchOption;

    if (searchOption == "Name") {
        string searchName;
        cout << "Enter product name to search: ";
        cin.ignore(); // Ignore leftover newline
        getline(cin, searchName);

        bool found = false;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] == searchName) {
                cout << badge[i] << ". " << name[i] << ": " << price[i] << " Rupees, Stock: " << stock[i] << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No product found with the name: " << searchName << endl;
        }
    } else if (searchOption == "Price") {
        int searchPrice;
        cout << "Enter product price to search: ";
        cin >> searchPrice;

        bool found = false;
        for (int i = 0; i < price.size(); i++) {
            if (price[i] == searchPrice) {
                cout << badge[i] << ". " << name[i] << ": " << price[i] << " Rupees, Stock: " << stock[i] << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No product found with the price: " << searchPrice << endl;
        }
    } else if (searchOption == "Stock") {
        int searchStock;
        cout << "Enter product stock to search: ";
        cin >> searchStock;

        bool found = false;
        for (int i = 0; i < stock.size(); i++) {
            if (stock[i] == searchStock) {
                cout << badge[i] << ". " << name[i] << ": " << price[i] << " Rupees, Stock: " << stock[i] << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No product found with the stock: " << searchStock << endl;
        }
    } else {
        cout << "Invalid search option!" << endl;
    }
}

void Sort(vector<int>& badge, vector<string>& name, vector<int>& stock, vector<int>& price) {
    string sortOption;
    cout << "Enter Sort Method (Price, Stock): ";
    cin >> sortOption;

    // Create a vector of indices
    vector<int> indices(price.size());
    for (int i = 0; i < indices.size(); i++) {
        indices[i] = i;
    }

    if (sortOption == "Price") {
        // Sort indices based on prices
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return price[a] < price[b];
        });
    } else if (sortOption == "Stock") {
        // Sort indices based on stock
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return stock[a] < stock[b];
        });
    } else {
        cout << "Invalid sort option!" << endl;
        return;
    }

    // Create temporary vectors to hold sorted values
    vector<int> sorted_badge;
    vector<string> sorted_name;
    vector<int> sorted_stock;
    vector<int> sorted_price;

    for (int index : indices) {
        sorted_badge.push_back(badge[index]);
        sorted_name.push_back(name[index]);
        sorted_stock.push_back(stock[index]);
        sorted_price.push_back(price[index]);
    }

    // Update original vectors with sorted values
    badge = sorted_badge;
    name = sorted_name;
    stock = sorted_stock;
    price = sorted_price;

    cout << "Products sorted successfully!" << endl;
}

int main() {
    // Inventory management system:
    vector<int> product_badge_number = {1, 2, 3, 4, 5};
    vector<string> name = {"Toy Car", "Hairbrush", "Water Bottle", "Bucket", "Bag"};
    vector<int> stock = {24, 35, 68, 12, 15};
    vector<int> price = {250, 35, 450, 395, 890};
    
    string command;
    int badge;
    int newstock, newprice;
    string newname;
    string update;

    while (true) {
        cout << "Enter command (List, Detail, Update, Add, Delete, Search, Sort, End): ";
        cin >> command;

        if (command == "End") {
            cout << "Goodbye!" << endl;
            break;
        } else if (command == "List") {
            traverse(product_badge_number, name, stock, price);
        } else if (command == "Detail") {
            cout << "Enter Badge Number: ";
            cin >> badge;

            // Validate badge number
            if (badge > 0 && badge <= name.size()) {
                cout << "Name: " << name[badge - 1] << endl;
                cout << "Price: " << price[badge - 1] << endl;
                cout << "Stock: " << stock[badge - 1] << endl;
            } else {
                cout << "Invalid Badge Number!" << endl;
            }
        } else if (command == "Update") {
            cout << "Enter Product Badge Number: ";
            cin >> badge;

            // Validate badge number
            if (badge > 0 && badge <= name.size()) {
                cout << "Enter Detail to be Updated (Name, Stock, Price): ";
                cin >> update;

                if (update == "Name") {
                    cout << "Enter New Name: ";
                    cin.ignore();  // Ignore leftover newline
                    getline(cin, name[badge - 1]);  // Get full name input
                } else if (update == "Stock") {
                    cout << "Enter New Stock: ";
                    cin >> stock[badge - 1];
                } else if (update == "Price") {
                    cout << "Enter New Price: ";
                    cin >> price[badge - 1];
                } else {
                    cout << "Invalid Update Field!" << endl;
                }
            } else {
                cout << "Invalid Badge Number!" << endl;
            }
        } else if (command == "Add") {
            cout << "Enter Name of Product: ";
            cin.ignore();  // Ignore leftover newline
            getline(cin, newname);  // Get full name input

            cout << "Enter Price of Product: ";
            cin >> newprice;

            cout << "Enter Stock of Product: ";
            cin >> newstock;

            // Adding new product details to vectors
            product_badge_number.push_back(product_badge_number.size() + 1);
            name.push_back(newname);
            price.push_back(newprice);
            stock.push_back(newstock);

            cout << "Product Added Successfully!" << endl;
        } else if (command == "Delete") {
            cout << "Enter Badge Number: ";
            cin >> badge;
            Del(product_badge_number, name, stock, price, badge - 1);
        } else if (command == "Search") {
            Search(product_badge_number, name, stock, price);
        } else if (command == "Sort") {
            Sort(product_badge_number, name, stock, price);
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
