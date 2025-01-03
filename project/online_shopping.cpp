
// #include <iostream>
// using namespace std;

// // Function prototype
// float onlineShopping();

// int main() {
//     char startValue;
//     char choiceAgain;
    
//     do {
//         cout << "Please Press 's' to Start Shopping :      " << endl;
//         cin >> startValue;
        
//         if (startValue == 's' || startValue == 'S') {
//             float totalAmount = onlineShopping();
//             cout << "Total Bill Amount: " << totalAmount << endl;
//             cout << "Do you want to shop again, y or n:  b" << endl;
//             cin >> choiceAgain;
//         } else {
//             cout << "You have entered a wrong option, please try again." << endl;
//             choiceAgain = 'y'; // Continue the loop to ask for start value again
//         }
//     } while (choiceAgain == 'y' || choiceAgain == 'Y');
    
//     cout << "Thank you for shopping!" << endl;
//     return 0;
// }

// float onlineShopping() {
//     char choice;
//     int item;
//     int qty;
//     float billAmount = 0.0;
    
//     cout << "=============================Welcome to Online Shopping============" << endl;
//     cout << "------Please follow the instructions--------------------------------" << endl;
//     cout << "(1). Please enter 'm' to order mobile phones" << endl;
//     cout << "(2). Please enter 'l' to order laptop" << endl;
//     cout << "(3). Please enter 'd' to order desktop" << endl;
//     cout << "(4). Please enter 's' to order speaker" << endl;
//     cout << "(5). Please enter 'h' to order headphone" << endl;
//     cin >> choice;
    
//     if (choice == 'm' || choice == 'M') {
//         cout << "==== Mobile Detail =====" << endl;
//         cout << "(1). Apple   => price: 40000" << endl;
//         cout << "(2). Android => price: 5000" << endl;
//         cout << "(3). Samsung => price: 20000" << endl;
//         cout << "(4). Huawei  => price: 30000" << endl;
//         cin >> item;
        
//         switch (item) {
//             case 1:
//                 cout << "Enter Quantity: " << endl;
//                 cin >> qty;
//                 billAmount += qty * 40000;
//                 break;
//             case 2:
//                 cout << "Enter Quantity: " << endl;
//                 cin >> qty;
//                 billAmount += qty * 5000;
//                 break;
//             case 3:
//                 cout << "Enter Quantity: " << endl;
//                 cin >> qty;
//                 billAmount += qty * 20000;
//                 break;
//             case 4:
//                 cout << "Enter Quantity: " << endl;
//                 cin >> qty;
//                 billAmount += qty * 30000;
//                 break;
//             default:
//                 cout << "You have entered a wrong option." << endl;
//                 break;
//         }
//     }

// void addCartOrBuy(){
//     int choice;
//     cout<<"1. Add to Cart. "<<endl;
//     cout<<"2. Buy          "<<endl;
//     cin>>choice;


// }
    
//     return billAmount;
// }







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
float onlineShopping(vector<CartItem> &cart);
void addCartOrBuy(float price, const string &itemName, int quantity, vector<CartItem> &cart);
void showCart(const vector<CartItem> &cart);

int main() {
    char startValue;
    char choiceAgain;
    vector<CartItem> cart; // Cart to store items
    
    do {
        cout << "Please Press 's' to Start Shopping: " << endl;
        cin >> startValue;
        
        if (startValue == 's' || startValue == 'S') {
            float totalAmount = onlineShopping(cart);
            cout << "Do you want to shop again, y or n: ";
            cin >> choiceAgain;
        } else {
            cout << "You have entered a wrong option, please try again." << endl;
            choiceAgain = 'y'; // Continue the loop to ask for start value again
        }
    } while (choiceAgain == 'y' || choiceAgain == 'Y');
    
    cout << "Thank you for shopping!" << endl;
    showCart(cart); // Show cart contents at the end
    return 0;
}

float onlineShopping(vector<CartItem> &cart) {
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
    addCartOrBuy(price, itemName, qty, cart);
    
    return totalAmount;
}

void showCart(const vector<CartItem> &cart) {
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }
}

void addCartOrBuy(float price, const string &itemName, int quantity, vector<CartItem> &cart) {
    int choice;
    cout << "Item: " << itemName << ", Price: " << price << ", Quantity: " << quantity << endl;
    cout<<"Please choose one "<<endl;
    cout<<"--------------------------------"<<endl;
    cout << "1. Add to Cart" << endl;
    cout << "2. Buy Now" << endl;
    cout<<"--------------------------------"<<endl;
    cin >> choice;
    
    if (choice == 1) {
        // Add item to cart
        CartItem item;
        item.itemName = itemName;
        item.quantity = quantity;
        item.price = price;
        cart.push_back(item);
        showCart(cart);
        cout << "Item added to cart successfully." << endl;

       

    } else if (choice == 2) {
        cout << "Item bought successfully." << endl;
        // Additional code to handle immediate purchase can be added here
    } else {
        cout << "Invalid choice. No action taken." << endl;
    }


    cout << "==== Your Cart ====" << endl;
    float totalCartAmount = 0;
    for (const auto &item : cart) {
        cout << "Item Name: " << item.itemName << ", Quantity: " << item.quantity 
             << ", Price per unit: " << item.price << ", Total Price: " << item.price * item.quantity << endl;
        totalCartAmount += item.price * item.quantity;
    }
    cout << "Total Cart Amount: " << totalCartAmount << endl;
}













// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstdlib>
// #include <algorithm>
// #include <iomanip> // For formatting output
// #include <windows.h> // For Windows-specific console manipulation

// using namespace std;

// class Product {
// public:
//     int id;
//     string name;
//     float price;
//     string description;
//     string category;

//     Product(int id, const string& name, float price, const string& description, const string& category)
//         : id(id), name(name), price(price), description(description), category(category) {}
// };

// // Function to get the width of the console
// int getConsoleWidth() {
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     int columns;
//     GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//     columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//     return columns;
// }

// // Function to print centered text with tabs
// void printCenteredWithTabs(const string& text, int consoleWidth) {
//     int padding = (consoleWidth - text.length()) / 2;
//     int tabs = padding / 8;
//     cout << string(tabs, '\t') << text << endl;
// }

// // Function to format price to two decimal places
// string formatPrice(float price) {
//     ostringstream oss;
//     oss << fixed << setprecision(2) << price;
//     return oss.str();
// }

// // Function to display products by pages
// void displayPage(const vector<Product>& products, int pageNumber, int itemsPerPage, int consoleWidth) {
//     int start = (pageNumber - 1) * itemsPerPage;
//     int end = min(start + itemsPerPage, static_cast<int>(products.size()));

//     // Print some newlines before the content for vertical centering
//     cout << string(5, '\n');

//     if (start >= products.size()) {
//         printCenteredWithTabs("Page number out of range.", consoleWidth);
//         return;
//     }
    

//     printCenteredWithTabs("Displaying page " + to_string(pageNumber) + ":", consoleWidth);

//     for (int i = start; i < end; ++i) {
//         const Product& product = products[i];
//         string productInfo = "|ID:" + to_string(product.id) + " | Name: " + product.name +
//                              " | Price: $" + formatPrice(product.price) +
//                              " | Description: " + product.description +
//                              " | Types: " + product.category;
//         printCenteredWithTabs(" ____________________________________________________________________________", consoleWidth);
//         printCenteredWithTabs(productInfo, consoleWidth);
//     }
//     cout << endl;
// }

// // Calculate the total number of pages
// int calculateTotalPages(const vector<Product>& products, int itemsPerPage) {
//     return (products.size() + itemsPerPage - 1) / itemsPerPage;
// }

// // Function to search a product by ID
// void searchProductById(const vector<Product>& products, int id, int consoleWidth) {
//     auto it = find_if(products.begin(), products.end(), [id](const Product& p) { return p.id == id; });
//     if (it != products.end()) {
//         printCenteredWithTabs("Product found:", consoleWidth);
//         string productInfo = "|ID:" + to_string(it->id) + " | Name: " + it->name +
//                              " | Price: $" + formatPrice(it->price) +
//                              " | Description: " + it->description +
//                              " | types: " + it->category;
//         printCenteredWithTabs(productInfo, consoleWidth);
//     } else {
//         printCenteredWithTabs("Product with ID " + to_string(id) + " not found.", consoleWidth);
//     }
// }

// // Function to display products by category
// void displayProductsByCategory(const vector<Product>& products, const string& category, int consoleWidth) {
//     vector<Product> filteredProducts;
//     copy_if(products.begin(), products.end(), back_inserter(filteredProducts),
//             [&category](const Product& p) { return p.category == category; });
//     if (filteredProducts.empty()) {
//         printCenteredWithTabs("No products found in category: " + category, consoleWidth);
//     } else {
//         printCenteredWithTabs("Products in Type: " + category, consoleWidth);
//         for (const auto& product : filteredProducts) {
//             string productInfo = "|ID:" + to_string(product.id) + " | Name: " + product.name +
//                                  "| Price: $" + formatPrice(product.price) +
//                                  "| Description: " + product.description +
//                                  "| Type :" + product.category;
//             printCenteredWithTabs(" ____________________________________________________________________________", consoleWidth);
//             printCenteredWithTabs(productInfo, consoleWidth);
//         }
//     }
// };

// class CartItem {
// public:
//     int id;
//     string name;
//     int quantity;
//     float price;

//     CartItem(int id, const string& name, int quantity, float price)
//         : id(id), name(name), quantity(quantity), price(price) {}

//     float totalPrice() const {
//         return quantity * price;
//     }
// };

// class Cart {
// private:
//     vector<CartItem> items;

// public:
//     void addItem(const CartItem& item) {
//         items.push_back(item);
//     }

//     void displayCart() const {
//         if (items.empty()) {
//             cout << "Your cart is empty." << endl;
//             return;
//         }

//         cout << "==== Your Cart ====" << endl;
//         float totalAmount = 0;
//         for (const auto& item : items) {
//             cout << "ID: " << item.id << " | Name: " << item.name
//                  << " | Quantity: " << item.quantity
//                  << " | Price per unit: $" << formatPrice(item.price)
//                  << " | Total Price: $" << formatPrice(item.totalPrice()) << endl;
//             totalAmount += item.totalPrice();
//         }
//         cout << "Total Cart Amount: $" << formatPrice(totalAmount) << endl;
//     }

//     void clear() {
//         items.clear();
//     }



//     void userBuy(vector<Product>& products, Cart& cart) {
//     int id;
//     int qty;
//     char choice;

//     cout << "Enter ID of the product you want to buy: ";
//     cin >> id;

//     auto it = find_if(products.begin(), products.end(), [id](const Product& p) { return p.id == id; });
//     if (it == products.end()) {
//         cout << "Product with ID " << id << " not found." << endl;
//         return;
//     }

//     cout << "Enter Quantity: ";
//     cin >> qty;

//     cout << "Do you want to add this item to your cart or buy it now?" << endl;
//     cout << "Enter 'a' to add to cart or 'b' to buy now: ";
//     cin >> choice;

//     if (choice == 'a') {
//         cart.addItem(CartItem(id, it->name, qty, it->price));
//         cout << "Item added to cart." << endl;
//     } else if (choice == 'b') {
//         float totalPrice = qty * it->price;
//         cout << "You have bought " << qty << " " << it->name
//              << "(s) for a total of $" << formatPrice(totalPrice) << endl;
//     } else {
//         cout << "Invalid choice." << endl;
//     }
// }

// };


// int main() {
//     vector<Product> products = {
//         {1, "Banana", 0.3, "A healthy fruit.", "fruit"},
//         {2, "Orange", 0.5, "A sweet fruit.", "fruit"},
//         {3, "Mango", 1, "A tropical fruit.", "fruit"},
//         {4, "Pineapple", 1.6, "A juicy fruit.", "fruit"},
//         {5, "Coconut", 1.5, "Sweet water.", "drink"},
//         {6, "Avocado", 1, "Yummy and sweet.", "fruit"},
//         {7, "Papaya", 1.5, "Sweet.", "fruit"},
//         {8, "Kiwi", 0.7, "Juicy fruit.", "fruit"},
//         {9, "Apple", 0.8, "Sweet and fragile.", "fruit"},
//         {10, "Plum", 0.5, "Juicy and sweet.", "fruit"},
//         {11, "Sting", 0.5, "Energy drink.", "drink"},
//         {12, "Karabav", 0.5, "Energy drink.", "drink"},
//         {13, "Red-bull", 0.5, "Energy drink.", "drink"},
//         {14, "Monster", 2, "Energy drink.", "drink"},
//         {15, "Pepsi", 0.5, "Soft drink.", "drink"},
//         {16, "Sprite", 0.5, "Soft drink.", "drink"},
//         {17, "Water", 0.3, "Healthy drink.", "drink"},
//         {18, "Kit-Kat", 1, "Snack.", "Snack"},
//         {19, "Chocolate", 2, "Snack.", "Snack"},
//         {20, "Brownie", 1, "Snack.", "snack"},
//         {21, "beer", 2, "drink.", "drink"},
//         {32, "Hotdog", 1, "snack.", "snack"},
//         {33,"chip", 1  , "snack.", "snack"},
//         {34,"chees", 2  , "snack.", "snack"},
//         {35,"fries", 1  , "snack.", "snack"},
//     };
//     int itemsPerPage = 5;
//     int totalPages = calculateTotalPages(products, itemsPerPage);
//     int currentPage = 1;
//     int consoleWidth = getConsoleWidth();
//     while (true) {
//         system("cls"); // Clear the console screen
//         displayPage(products, currentPage, itemsPerPage, consoleWidth);
//          printCenteredWithTabs("Page " + to_string(currentPage) + " of " + to_string(totalPages), consoleWidth);
//          printCenteredWithTabs("Enter |n| for next page.\t\t\t", consoleWidth);
//          printCenteredWithTabs("Enter |p| for previous page.\t\t\t", consoleWidth);
//          printCenteredWithTabs("Enter |c| search by types.\t\t\t", consoleWidth);
//          printCenteredWithTabs("Enter |q| to quit.\t\t\t\t\t\t\t\t\t\t\t\t", consoleWidth);
//         char command;
//         cout<<"\t\tEnter option :";cin >> command;
        
//         if (command == 'n') {
//             if (currentPage < totalPages) {
//                 currentPage++;
//             } else {
//                 printCenteredWithTabs("You are on the last page.", consoleWidth);
//                 system("pause");
//             }
//         } else if (command == 'p') {
//             if (currentPage > 1) {
//                 currentPage--;
//             } else {
//                 printCenteredWithTabs("You are on the first page.", consoleWidth);
//                 system("pause");
//             }
//         } else if (command == 'c') {
//             string category;
//             cout << "Enter Type of products: ";
//             cin.ignore();
//             getline(cin, category);
//             system("cls");
//             displayProductsByCategory(products, category, consoleWidth);
//             system("pause");
//         } else if (command == 'q') {
//             break;
//         } else {
//             printCenteredWithTabs("Invalid command.", consoleWidth);
//             system("pause");
//         }
//     }

//      system("cls");
//     cout << "==== Final Cart ====" << endl;
//     Cart cart;
//     cart.displayCart();

//     return 0;
// }
