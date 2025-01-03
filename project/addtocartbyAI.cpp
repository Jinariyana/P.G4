#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store cart item details
struct CartItem {
    string itemName;
    int quantity;
    float price;
};

// Function prototypes
float onlineShopping(vector<CartItem>& cart, vector<CartItem>& boughtItems);
void addCartOrBuy(float price, const string& itemName, int quantity, vector<CartItem>& cart, vector<CartItem>& boughtItems);
void showCart(const vector<CartItem>& cart);
void showBoughtItems(const vector<CartItem>& boughtItems);

int main() {
    char startValue;
    char choiceAgain;
    vector<CartItem> cart; // Cart to store items
    vector<CartItem> boughtItems; // List of bought items
    
    do {
        cout << "Please Press 's' to Start Shopping: " << endl;
        cin >> startValue;
        
        if (startValue == 's' || startValue == 'S') {
            float totalAmount = onlineShopping(cart, boughtItems);
            cout << "Do you want to shop again, y or n: ";
            cin >> choiceAgain;
        } else {
            cout << "You have entered a wrong option, please try again." << endl;
            choiceAgain = 'y'; // Continue the loop to ask for start value again
        }
    } while (choiceAgain == 'y' || choiceAgain == 'Y');
    
    cout << "Thank you for shopping!" << endl;
    showCart(cart); // Show cart contents at the end
    showBoughtItems(boughtItems); // Show purchased items at the end

    return 0;
}

float onlineShopping(vector<CartItem>& cart, vector<CartItem>& boughtItems) {
    char choice;
    int item;
    int qty;
    float price = 0.0;
    string itemName;
    
    cout << "=============================Welcome to Online Shopping============" << endl;
    cout << "------Please follow the instructions--------------------------------" << endl;
    cout << "(1). Please enter 'm' to order mobile phones" << endl;
    cout << "(2). Please enter 'l' to order laptop" << endl;
    cout << "(3). Please enter 'd' to order desktop" << endl;
    cout << "(4). Please enter 's' to order speaker" << endl;
    cout << "(5). Please enter 'h' to order headphone" << endl;
    cout<<"Choose letter you want: ";
    cin >> choice;
    
    if (choice == 'm' || choice == 'M') {
        cout << "==== Mobile Detail =====" << endl;
        cout << "(1). Apple   => price: 40000" << endl;
        cout << "(2). Android => price: 5000" << endl;
        cout << "(3). Samsung => price: 20000" << endl;
        cout << "(4). Huawei  => price: 30000" << endl;

        cin >> item;
        
        switch (item) {
            case 1: price = 40000; itemName = "Apple"; break;
            case 2: price = 5000; itemName = "Android"; break;
            case 3: price = 20000; itemName = "Samsung"; break;
            case 4: price = 30000; itemName = "Huawei"; break;
            default:
                cout << "You have entered a wrong option." << endl;
                return 0;
        }
    } else if (choice == 'l' || choice == 'L') {
        cout << "==== Laptop Detail =====" << endl;
        cout << "(1). Dell    => price: 60000" << endl;
        cout << "(2). HP      => price: 55000" << endl;
        cout << "(3). Lenovo  => price: 50000" << endl;
        cout << "(4). Apple   => price: 90000" << endl;
        cin >> item;
        
        switch (item) {
            case 1: price = 60000; itemName = "Dell"; break;
            case 2: price = 55000; itemName = "HP"; break;
            case 3: price = 50000; itemName = "Lenovo"; break;
            case 4: price = 90000; itemName = "Apple"; break;
            default:
                cout << "You have entered a wrong option." << endl;
                return 0;
        }
    } else if (choice == 'd' || choice == 'D') {
        cout << "==== Desktop Detail =====" << endl;
        cout << "(1). HP      => price: 40000" << endl;
        cout << "(2). Dell    => price: 45000" << endl;
        cout << "(3). Lenovo  => price: 35000" << endl;
        cout << "(4). Asus    => price: 50000" << endl;
        cin >> item;
        
        switch (item) {
            case 1: price = 40000; itemName = "HP"; break;
            case 2: price = 45000; itemName = "Dell"; break;
            case 3: price = 35000; itemName = "Lenovo"; break;
            case 4: price = 50000; itemName = "Asus"; break;
            default:
                cout << "You have entered a wrong option." << endl;
                return 0;
        }
    } else if (choice == 's' || choice == 'S') {
        cout << "==== Speaker Detail =====" << endl;
        cout << "(1). Bose    => price: 10000" << endl;
        cout << "(2). JBL     => price: 8000" << endl;
        cout << "(3). Sony    => price: 7000" << endl;
        cout << "(4). Philips => price: 6000" << endl;
        cin >> item;
        
        switch (item) {
            case 1: price = 10000; itemName = "Bose"; break;
            case 2: price = 8000; itemName = "JBL"; break;
            case 3: price = 7000; itemName = "Sony"; break;
            case 4: price = 6000; itemName = "Philips"; break;
            default:
                cout << "You have entered a wrong option." << endl;
                return 0;
        }
    } else if (choice == 'h' || choice == 'H') {
        cout << "==== Headphone Detail =====" << endl;
        cout << "(1). Bose    => price: 15000" << endl;
        cout << "(2). Sony    => price: 12000" << endl;
        cout << "(3). JBL     => price: 10000" << endl;
        cout << "(4). Sennheiser => price: 20000" << endl;
        cin >> item;
        
        switch (item) {
            case 1: price = 15000; itemName = "Bose"; break;
            case 2: price = 12000; itemName = "Sony"; break;
            case 3: price = 10000; itemName = "JBL"; break;
            case 4: price = 20000; itemName = "Sennheiser"; break;
            default:
                cout << "You have entered a wrong option." << endl;
                return 0;
        }
    } else {
        cout << "You have entered a wrong option." << endl;
        return 0;
    }
    
    cout << "Enter Quantity: " << endl;
    cin >> qty;
    
    float totalAmount = qty * price;
    addCartOrBuy(price, itemName, qty, cart, boughtItems);
    
    return totalAmount;
}

void showCart(const vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }
    cout << "==== Your Cart ====" << endl;
    float totalCartAmount = 0;
    for (const auto& item : cart) {
        cout << "Item Name: " << item.itemName << ", Quantity: " << item.quantity 
             << ", Price per unit: " << item.price << ", Total Price: " << item.price * item.quantity << endl;
        totalCartAmount += item.price * item.quantity;
    }
    cout << "Total Cart Amount: " << totalCartAmount << endl;
}

void showBoughtItems(const vector<CartItem>& boughtItems) {
    if (boughtItems.empty()) {
        cout << "No items have been bought yet." << endl;
        return;
    }
    cout << "==== Your Bought Items ====" << endl;
    float totalBoughtAmount = 0;
    for (const auto& item : boughtItems) {
        cout << "Item Name: " << item.itemName << ", Quantity: " << item.quantity 
             << ", Price per unit: " << item.price << ", Total Price: " << item.price * item.quantity << endl;
        totalBoughtAmount += item.price * item.quantity;
    }
    cout << "Total Bought Amount: " << totalBoughtAmount << endl;
}

void addCartOrBuy(float price, const string& itemName, int quantity, vector<CartItem>& cart, vector<CartItem>& boughtItems) {
    int choice;
    cout << "Do you want to add to the cart or buy now? (1 to Add to Cart, 2 to Buy Now): ";
    cin >> choice;
    
    CartItem newItem = { itemName, quantity, price };
    
    if (choice == 1) {
        cart.push_back(newItem);
        cout << "Item added to cart!" << endl;
    } else if (choice == 2) {
        boughtItems.push_back(newItem);
        cout << "Item bought!" << endl;
    } else {
        cout << "Invalid option!" << endl;
    }
}
