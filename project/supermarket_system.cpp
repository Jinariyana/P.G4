#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a Product structure
struct Product {
    int code;
    string name;
    float price;
    float discount;

    void display() const {
        cout << "Code: " << code << ", Name: " << name << ", Price: $" << price << ", Discount: " << discount << "%" << endl;
    }
};

class Shopping {
private:
    vector<Product> products; // Store products in a vector

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove();
    void list();
    void receipt();

    // Helper functions
    Product* findProductByCode(int code);
    void displayProducts() const;
};

void Shopping::menu() {
    int choice;

    while (true) {
        cout << "----------------------------------------------" << endl;
        cout << " *                                            *" << endl;
        cout << " *       Supermarket Menu                     *" << endl;
        cout << " *                                            *" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Buyer" << endl;
        cout << "3. Exit" << endl;
        cout << "===============" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                administrator();
                break;
            case 2:
                buyer();
                break;
            case 3:
                cout << "Exiting the application. Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void Shopping::administrator() {
    int choice;
    while (true) {
        cout << "********  | Administrator Menu  |  **********" << endl;
        cout << "[1]. Add the Product." << endl;
        cout << "[2]. Modify the Product." << endl;
        cout << "[3]. Delete the Product." << endl;
        cout << "[4]. List Products." << endl;
        cout << "[5]. Back to Main Menu." << endl;
        cout << "Please Enter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                remove();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                menu();
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void Shopping::buyer() {
    int choice;
    while (true) {
        cout << "***********| Buyer Menu |**********" << endl;
        cout << "[1]. Buy the Product." << endl;
        cout << "[2]. Back to Main Menu." << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                receipt();
                break;
            case 2:
                menu();
                return;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void Shopping::add() {
    Product newProduct;
    cout << "Enter Product Code: ";
    cin >> newProduct.code;
    cout << "Enter Product Name: ";
    cin.ignore(); // To ignore the newline character left by previous input
    getline(cin, newProduct.name);
    cout << "Enter Product Price: ";
    cin >> newProduct.price;
    cout << "Enter Product Discount: ";
    cin >> newProduct.discount;

    products.push_back(newProduct);
    cout << "Product added successfully." << endl;
}

void Shopping::edit() {
    int code;
    cout << "Enter Product Code to Edit: ";
    cin >> code;

    Product* product = findProductByCode(code);
    if (product) {
        cout << "Editing Product: ";
        product->display();
        cout << "Enter New Name: ";
        cin.ignore(); // To ignore the newline character left by previous input
        getline(cin, product->name);
        cout << "Enter New Price: ";
        cin >> product->price;
        cout << "Enter New Discount: ";
        cin >> product->discount;
        cout << "Product updated successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

void Shopping::remove() {
    int code;
    cout << "Enter Product Code to Remove: ";
    cin >> code;

    auto it = remove_if(products.begin(), products.end(), [code](const Product& p) {
        return p.code == code;
    });

    if (it != products.end()) {
        products.erase(it, products.end());
        cout << "Product removed successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

void Shopping::displayProducts() const {
    if (products.empty()) {
        cout << "No products available." << endl;
        return;
    }
    cout << "Available Products:" << endl;
    for (const auto& product : products) {
        product.display();
    }
}

Product* Shopping::findProductByCode(int code) {
    auto it = find_if(products.begin(), products.end(), [code](const Product& p) {
        return p.code == code;
    });
    return (it != products.end()) ? &(*it) : nullptr;
}

void Shopping::receipt() {
    int code;
    cout << "Enter Product Code to Buy: ";
    cin >> code;

    Product* product = findProductByCode(code);
    if (product) {
        cout << "Product Details: ";
        product->display();
        float totalPrice = product->price - (product->price * (product->discount / 100));
        cout << "Total Price after Discount: $" << totalPrice << endl;
    } else {
        cout << "Product not foundv." << endl;
    }
}

int main() {
    Shopping s;
    s.menu();
    return 0;
}





