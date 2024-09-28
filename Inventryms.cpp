#include<iostream>
#include<string>
using namespace std;

struct item {
    public:
    int id, quantity;
    float price;
    string name;
};

class inventory {
    public:
    item items[100]; // array of size 100
    int itemcount;

    public:
        inventory() : itemcount(0) {}

    void additems(int id, string name, int quantity, float price) {
        if (itemcount < 100) {
            items[itemcount].id = id; 
            items[itemcount].name = name; 
            items[itemcount].quantity = quantity; 
            items[itemcount].price = price; 
            itemcount++;
            cout << "Items Added Successfully!!\n";
        } else {
            cout << "Inventory is Full!!!\n";
        }
    }

    void displayitems() {
        if (itemcount == 0) {
            cout << "Inventory is Empty!!\n";
            return;
        }
        for (int i = 0; i < itemcount; i++) {
            cout << "ID: " << items[i].id 
                 << " Name: " << items[i].name 
                 << " Quantity: " << items[i].quantity 
                 << " Price: " << items[i].price << '\n';
        }
    }

    void searchbyId(int id) {
        for (int i = 0; i < itemcount; i++) {
            if (items[i].id == id) {
                cout << "\nItem Found ID: " << items[i].id 
                     << " \nName: " << items[i].name 
                     << " \nQuantity: " << items[i].quantity 
                     << " \nPrice: " << items[i].price << '\n';
                return;
            }
        }
        cout << "Item Not Found!!\n";
    }

    void searchbyName(string name) {
        bool found = false; 
        for (int i = 0; i < itemcount; i++) {
            if (items[i].name == name) {
                cout << "\nItem Found Name: " << items[i].name 
                     << " \nID: " << items[i].id 
                     << " \nQuantity: " << items[i].quantity 
                     << " \nPrice: " << items[i].price << '\n';
                found = true; 
            }
        }
        if (!found) {
            cout << "Item Not Found!!\n"; 
        }
    }
};

int main() {
    inventory inv;
    int id, choice, quantity;
    float price;
    string name;

    while (true) {
        cout << "--INVENTORY MANAGEMENT SYSTEM--\n";
        cout << "1. Add Items\n";
        cout << "2. Display Items\n";
        cout << "3. Search Items By Id\n";
        cout << "4. Search Items By Name\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice:\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Item Id:\n";
                cin >> id;
                cout << "Enter Item Name:\n";
                cin >> name;
                cout << "Enter Item Quantity:\n";
                cin >> quantity;
                cout << "Enter Item Price:\n";
                cin >> price;
                inv.additems(id, name, quantity, price);
                break;
            case 2:
                inv.displayitems();
                break;
            case 3:
                cout << "Enter Item Id:\n";
                cin >> id;
                inv.searchbyId(id);
                break;
            case 4:
                cout << "Enter Item Name:\n";
                cin >> name;
                inv.searchbyName(name);
                break;
            case 5:
                cout << "Thank You!!!\n";
                return 0; 
            default:
                cout << "Invalid Choice!! Please Try Again\n";
        }
    }

    return 0;
}

