// #include<iostream>
// #include<fstream>
// #include<string.h>
// using namespace std;

// void registerUser(){
//     string ruserId, ruserPassword, rid, rpass;
//     system("cls");
//     cout<<"|------Please Register Your Account-------|"<<endl;
//     cout<<"           USERNAME: ";
//     cin>>ruserId;
//     cout<<"           PASSWORD: ";
//     cin>>ruserPassword;
//     ofstream f1("records.txt", ios::app);
//     if (f1.is_open()) {
//     f1<<ruserId<<" "<<ruserPassword<<endl;k
//     f1.close();
//     cout<<" Register Successfully. "<<endl;
// }else{
//     cout<<"Please try again!"<<endl;
// }
// }

// void login(){
//     bool count= false;
//     string userId, userPassword,id,pass;
//     cout<<"|          Please Login Your Account         | "<<endl;
//     cout<<"           USERNAME:                     ";
//     cin>>userId;
//     cout<<"           PASSWORD:                     ";
//     cin>>userPassword;
//     ifstream input("users.txt");
//     while(input>>id>>pass){
//         if(id==userId && pass==userPassword){
//             count=true;
//             system("cls");
//             break;
//         }
//     }
//     input.close();
//     if(count==true){
//         cout <<userId << "  Your Login is Successful. " << endl;
//     } else {
//         cout << "  Your Login is Incorrect. Please try again!! " << endl;
//     }
// }

// void forgot(){
//     int option;
//     cout<<"|       1. Search Id by Username           |"<<endl;
//     cout<<"|       2. Go Back to the Menu             |"<<endl;
//     cout<<"Please Enter Your Option: ";
//     cin>>option;
//     switch(option){
//         case 1:{
//             bool count= false;            string suserId, sid, spass;
//             cout<<"USERNAME:                    ";
//             cin>>suserId;
//             ifstream f2("records.txt");
//             while(f2>>sid>>spass){

//                 if(sid==suserId){
//                     count=true;
//                 }
//                 if(count==true){
//                     cout<<" Your Account is Found.    "<<endl;
//                     cout<<"Your PassWord is :         "<<spass;
//                     cout<<endl;
//                 }else{
//                     cout<<" Sorry ! Your Account is Not Found.     "<<endl;
//                 }
//             }
//         break;
//         }
//         case 2:{
       
//         break;
//         }
//         default:
//             cout<<"Please try Again!  "<<endl;
//     }
    
// }

// int main(){
//     system("cls");
//     int choice;
//     do{
//     cout<<"__________________________________________________"<<endl;
//     cout<<"                     |Menu|                       "<<endl;
//     cout<<"__________________________________________________"<<endl;
//     cout<<"|  1. Register                  |"<<endl;
//     cout<<"|  2. Login                     |"<<endl;
//     cout<<"|  3. Forgot Password           |"<<endl;
//     cout<<"|  4. Exit                      |"<<endl;
//       cout<<" Please Enter Your Choice: ";
//       cin>>choice;
//       switch(choice){
//         case 1:{
//             registerUser();
//             break;
//         }
//         case 2:{
//             login();
//             break;
//         }
//         case 3:{
//             forgot();
//             break;
//         }
//         case 4:{
//             cout<<"Thank you"<<endl;
//             break;
//         }
//         default:
//             cout<<"Try Again!"<<endl;
        
//         }
//     } while(choice  !=4);
      
//     return 0;
// }







// curl \
//   -H 'Content-Type: application/json' \
//   -d '{
//   "contents": [
//     {
//       "parts": [
//         {
//           "text": "Input all List Product in c++ code"
//         }
//       ]
//     }
//   ]
// }' \
//   -X POST 'https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=AIzaSyASBQggVtQiwxqf5LT-qtA7bZY5a_3QJZw'








#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For system("cls") or system("clear")
using namespace std;

// Structure for users and products
struct User {
    string username;
    string password;
};

struct Product {
    string name;
    double price;
    int quantity;
};

// Global vectors to store user data and products
vector<User> users;
vector<Product> products;

// Clear screen function (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Sleep function (cross-platform)

// Function to display the main menu
void firstMenu() {
    clearScreen();
    cout << "=====================================================================================================================================" << endl;
    cout << "                                   1. Login                                                                                          " << endl;
    cout << "                                   2. List all Products                                                                              " << endl;
    cout << "                                   3. Add Products to Cart                                                                           " << endl;
    cout << "                                   4. Order Product                                                                                  " << endl;
    cout << "                                   5. Admin Login                                                                                    " << endl;
    cout << "                                   0. Exit                                                                                           " << endl;
    cout << "=====================================================================================================================================" << endl;
    cout << "Please Enter Your Choice: ";
}

// Function to register a new user
void registerUser() {
    clearScreen();
    cout << "|------Please Register Your Account-------|" << endl;
    string userId, userPassword;
    cout << "           USERNAME: ";
    cin >> userId;
    cout << "           PASSWORD: ";
    cin >> userPassword;

    // Check if user already exists
    for (const auto& user : users) {
        if (user.username == userId) {
            cout << "Username already exists. Please try a different username." << endl;
            return;
        }
    }

    // Add new user to vector
    users.push_back({userId, userPassword});
    cout << "......................................................" << endl;
    cout << " You completed your Account Successfully. " << endl;
}

// Function to log in a user
void login() {
    clearScreen();
    string userId, userPassword;
    cout << "                 [+2]. Login Account                                     " << endl;
    cout << "           USERNAME:                     ";
    cin >> userId;
    cout << "           PASSWORD:                     ";
    cin >> userPassword;

    bool found = false;
    for (const auto& user : users) {
        if (user.username == userId && user.password == userPassword) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << userId << "  Your Login is Successful." << endl;
    } else {
        cout << "  Your Login is Incorrect. Please try again!! " << endl;
    }
}

// Function to handle forgotten passwords
void forgot() {
    clearScreen();
    int option;
    cout << "|       1. Search Id by Username           |" << endl;
    cout << "|       2. Go Back to the Menu             |" << endl;
    cout << "Please Enter Your Option: ";
    cin >> option;

    switch (option) {
        case 1: {
            string suserId;
            cout << "USERNAME: ";
            cin >> suserId;

            bool found = false;
            for (const auto& user : users) {
                if (user.username == suserId) {
                    found = true;
                    cout << "Your Account is Found." << endl;
                    cout << "Your Password is: " << user.password << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Sorry! Your Account is Not Found." << endl;
            }
            break;
        }
        case 2:
            // Go back to the previous menu
            break;
        default:
            cout << "Invalid option. Please try again!" << endl;
    }
}

// Admin Functions
void adminMenu();
void addProduct() {
    clearScreen();
    string name;
    double price;
    int quantity;

    cout << "Enter Product Name: ";
    cin >> name;
    cout << "Enter Product Price: ";
    cin >> price;
    cout << "Enter Product Quantity: ";
    cin >> quantity;

    products.push_back({name, price, quantity});
    cout << "Product added successfully!\n";
    adminMenu();
}

void viewProducts() {
    clearScreen();
    if (products.empty()) {
        cout << "No products available." << endl;
    } else {
        cout << "----------------------------" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i + 1 << ". Name: " << products[i].name
                 << " | Price: $" << products[i].price
                 << " | Quantity: " << products[i].quantity << endl;
        }
        cout << "----------------------------" << endl;
    }
}

void removeProduct() {
    viewProducts();
    if (!products.empty()) {
        int productNumber;
        cout << "Enter the product number to remove: ";
        cin >> productNumber;

        if (productNumber > 0 && productNumber <= products.size()) {
            products.erase(products.begin() + (productNumber - 1));
            cout << "Product removed successfully.\n";
        } else {
            cout << "Invalid product number.\n";
        }
    }

    adminMenu();
}

// Function to display admin menu
void adminMenu() {
    clearScreen();
    cout << "================= Admin Menu =================" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. View Products" << endl;
    cout << "3. Remove Product" << endl;
    cout << "0. Logout" << endl;
    cout << "===============================================" << endl;
    cout << "Please Enter Your Choice: ";

    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            viewProducts();
          
            adminMenu();
            break;
        case 3:
            removeProduct();
            break;
        case 0:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid option. Please try again!" << endl;
            adminMenu();
    }
}

// Function for Admin login
void adminLogin() {
    clearScreen();
    string adminUsername = "admin";
    string adminPassword = "admin123";
    string inputUsername, inputPassword;

    cout << "Admin Username: ";
    cin >> inputUsername;
    cout << "Admin Password: ";
    cin >> inputPassword;

    if (inputUsername == adminUsername && inputPassword == adminPassword) {
        cout << "Admin login successful!" << endl;
     
        adminMenu();
    } else {
        cout << "Invalid admin credentials!" << endl;
    
    }
}

// Function to display the login/register menu
void secondMenu() {
    clearScreen();
    cout << "......................................................................................................" << endl;
    cout << "                                        [+1]. Register Account                                        " << endl;
    cout << "                                        [+2]. Login Account                                           " << endl;
    cout << "                                        [+3]. Forgot Password                                         " << endl;
    cout << "                                        [+0]. Exit                                                    " << endl;
    cout << "......................................................................................................" << endl;
    cout << "Please Enter your Choice: ";
}

// Function to manage login, register, and forgot password
void loginRegisterUser() {
    int option;
    do {
        secondMenu();
        cin >> option;
        switch (option) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                forgot();
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again!" << endl;
        }
    } while (option != 0);
}

// Main function
int main() {
    int option;
    do {
        firstMenu();
        cin >> option;
        switch (option) {
            case 1:
                loginRegisterUser();
                break;
            case 2:
                viewProducts();
                
                break;
            case 3:
                // Add to cart logic here
                cout << "This feature is under construction..." << endl;
             
                break;
            case 4:
                // Order product logic here
                cout << "This feature is under construction..." << endl;
           
                break;
            case 5:
                adminLogin();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again!" << endl;
            ;
        }
    } while (option != 0);

    return 0;
}





// #include <iostream>
// #include <vector>
// #include <string>
// #include <conio.h> // For getch function (for Windows) or you can remove it if using cross-platform
// #include <cstdlib> // For system("cls") or system("clear")
// #include <chrono>
// #include <thread> // For cross-platform sleep

// using namespace std;

// struct User {
//     string username;
//     string password;
// };

// // Global vector to store user data
// vector<User> users;
// vector<Product> products;


// void adminMenu();
// void addProduct() {
//     string name;
//     double price;
//     int quantity;

//     cout << "Enter Product Name: ";
//     cin >> name;
//     cout << "Enter Product Price: ";
//     cin >> price;
//     cout << "Enter Product Quantity: ";
//     cin >> quantity;

//     products.push_back({name, price, quantity});
//     cout << "Product added successfully!\n";
//     adminMenu();
// }

// void viewProducts() {
//     if (products.empty()) {
//         cout << "No products available." << endl;
//     } else {
//         cout << "----------------------------" << endl;
//         for (size_t i = 0; i < products.size(); ++i) {
//             cout << i + 1 << ". Name: " << products[i].name
//                  << " | Price: $" << products[i].price
//                  << " | Quantity: " << products[i].quantity << endl;
//         }
//         cout << "----------------------------" << endl;
//     }
// }

// void removeProduct() {
//     viewProducts();
//     if (!products.empty()) {
//         int productNumber;
//         cout << "Enter the product number to remove: ";
//         cin >> productNumber;

//         if (productNumber > 0 && productNumber <= products.size()) {
//             products.erase(products.begin() + (productNumber - 1));
//             cout << "Product removed successfully.\n";
//         } else {
//             cout << "Invalid product number.\n";
//         }
//     }

//     adminMenu();
// }

// // Function to display admin menu
// void adminMenu() {
//     cout << "================= Admin Menu =================" << endl;
//     cout << "1. Add Product" << endl;
//     cout << "2. View Products" << endl;
//     cout << "3. Remove Product" << endl;
//     cout << "0. Logout" << endl;
//     cout << "===============================================" << endl;
//     cout << "Please Enter Your Choice: ";

//     int choice;
//     cin >> choice;
//     switch (choice) {
//         case 1:
//             addProduct();
//             break;
//         case 2:
//             viewProducts();
          
//             adminMenu();
//             break;
//         case 3:
//             removeProduct();
//             break;
//         case 0:
//             cout << "Logging out...\n";
//             break;
//         default:
//             cout << "Invalid option. Please try again!" << endl;
//             adminMenu();
//     }
// }

// // Function for Admin login
// void adminLogin() {
//     string adminUsername = "admin";
//     string adminPassword = "admin123";
//     string inputUsername, inputPassword;

//     cout << "Admin Username: ";
//     cin >> inputUsername;
//     cout << "Admin Password: ";
//     cin >> inputPassword;

//     if (inputUsername == adminUsername && inputPassword == adminPassword) {
//         cout << "Admin login successful!" << endl;
     
//         adminMenu();
//     } else {
//         cout << "Invalid admin credentials!" << endl;
    
//     }
// }




// void firstMenu() {
  
//     cout << "=====================================================================================================================================" << endl;
//     cout << "                                   1. Login                                                                                          " << endl;
//     cout << "                                   2. List all Products                                                                              " << endl;
//     cout << "                                   3. Add Products to Cart                                                                           " << endl;
//     cout << "                                   4. Order Product                                                                                  " << endl;
//     cout << "                                   5. Setting                                                                                        " << endl;
//     cout << "                                   6. Admin                                                                                          " << endl;
//     cout << "                                   0. Exit                                                                                          " <<endl;
//     cout << "=====================================================================================================================================" << endl;
//     cout << "Please Enter Your Choice: ";
// }

// void registerUser() {

//     cout << "|------Please Register Your Account-------|" << endl;
//     string userId, userPassword;
//     cout << "           USERNAME: ";
//     cin >> userId;
//     cout << "           PASSWORD: ";
//     cin >> userPassword;

   
//     for (const auto& user : users) {
//         if (user.username == userId) {
//             cout << "Username already exists. Please try a different username." << endl;
//             return;
//         }
//     }

  
//     users.push_back({userId, userPassword});
//     cout << "......................................................" << endl;
//     cout << " You completed your Account Successfully. " << endl;
// }


// void login() {
//     string userId, userPassword;
//     cout << "                 [+2]. Login Account                                     " << endl;
//     cout << "           USERNAME:                     ";
//     cin >> userId;
//     cout << "           PASSWORD:                     ";
//     cin >> userPassword;

//     bool found = false;
//     for (const auto& user : users) {
//         if (user.username == userId && user.password == userPassword) {
//             found = true;
//             break;
//         }
//     }

//     if (found) {
//         cout << userId << "  Your Login is Successful." << endl;
//     } else {
//         cout << "  Your Login is Incorrect. Please try again!! " << endl;
//     }
// }

// void forgotPassword() {
//     int option;
//     cout << "|       1. Search Id by Username           |" << endl;
//     cout << "|       2. Go Back to the Menu             |" << endl;
//     cout << "Please Enter Your Option: ";
//     cin >> option;

//     switch (option) {
//         case 1: {
//             string suserId;
//             cout << "USERNAME: ";
//             cin >> suserId;

//             bool found = false;
//             for (const auto& user : users) {
//                 if (user.username == suserId) {
//                     found = true;
//                     cout << "Your Account is Found." << endl;
//                     cout << "Your Password is: " << user.password << endl;
//                     break;
//                 }
//             }

//             if (!found) {
//                 cout << "Sorry! Your Account is Not Found." << endl;
//             }
//             break;
//         }
//         case 2:
//             firstMenu();
//             break;
//         default:
//             cout << "Invalid option. Please try again!" << endl;
//     }
// }

// void secondMenu() {
 
//     cout << "......................................................................................................" << endl;
//     cout << "                                        [+1]. Register Account                                        " << endl;
//     cout << "                                        [+2]. Login Account                                           " << endl;
//     cout << "                                        [+3]. Forgot Password                                         " << endl;
//     cout << "                                        [+0]. Exit                                                    " << endl;
//     cout << "......................................................................................................" << endl;
//     cout << "Please Enter your Choice: ";
// }

// void loginRegisterUser() {
//     int option;
//     do {
//         secondMenu();
//         cin >> option;
//         switch (option) {
//             case 1:
//                 registerUser();
//                 break;
//             case 2:
//                 login();
//                 break;
//             case 3:
//                 forgotPassword();
//                 break;
//             case 0:
//                 cout << "Returning to main menu..." << endl;
//                 break;
//             default:
//                 cout << "Invalid option. Please try again!" << endl;
//         }
//     } while (option != 0);
// }
// int main() {
//     int choice;
//     do {
//         firstMenu();
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 loginRegisterUser();
//                 break;
//             case 2:
//                 // List all products functionality (not implemented)
//                 break;
//             case 3:
//                 // Add products to cart functionality (not implemented)
//                 break;
//             case 4:
//                 // Order product functionality (not implemented)
//                 break;
//             case 5:
//                 // Settings functionality (not implemented)
//                 break;
//             case 6:
//             adminLogin();
//             adminMenu();   
//             case 0:
//                 cout << "Exiting the program. Thank you!" << endl;
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again!" << endl;
//         }
//     } while (choice != 0);

//     return 0;
// }