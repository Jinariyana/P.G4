#include <iostream>
#include <windows.h> // For Sleep function
#include <conio.h>
using namespace std;

void Menu() {
    cout << "_________________________|" << endl;
    cout << "|      User Setting      |" << endl;
    cout << "|------------------------|" << endl;
    cout << "| 1. Register            |" << endl;
    cout << "| 2. Contact Us          |" << endl;
    cout << "| 3. Change Password     |" << endl;
    cout << "| 4. Add New Account     |" << endl;
    cout << "| 5. Log Out             |" << endl;
    cout << "|________________________|" << endl;
}

class Setting {
private:
    string username;
    string email;
    string newpassword;
    string password;

public:
    Setting() : username(""), email(""), newpassword(""), password("") {}

    void Input() {
        cout << "____________________" << endl;
        cout << "Enter username: "; cin.ignore(); getline(cin, username);
        cout << "Enter email: "; getline(cin, email);
        cout << "Enter Password: "; getline(cin, password);
        cout << "____________________" << endl;
    }

    void ChangePassword() {
        cout << "Enter old password: ";
        string old_password;
        cin >> old_password;
        if (old_password == password) {
            cout << "Enter new password: ";
            cin >> newpassword;
        } else {
            cout << "Password incorrect!" << endl;
        }
    }

    void ContactUs() {
        cout << "______________________________" << endl;
        cout << "|     Contact Us             |" << endl;
        cout << "| Email: weffefeof@gmail.com |" << endl;
        cout << "| Phone: 093738333           |" << endl;
        cout << "| Facebook: www.facebook.com |" << endl;
        cout << "|_____________________________" << endl;
    }

    void AddNewAcc() {
        cout << "____________________" << endl;
        cout << "Create New Account" << endl;
        // cout << "____________________" << endl;
        Input();
    }

    void Display() {
        cout << "========>| WELCOME|<========" << endl;
        Sleep(2000);
        system("cls");
        int choice;
        // do {
        a:
            Menu();
            
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // Clear the newline character from input buffer
            switch (choice) {
                case 1:
                    Input();
                    break;
                case 2:
                    ContactUs();
                    break;
                case 3:
                    ChangePassword();
                    break;
                case 4:
                    AddNewAcc();
                    break;
                case 5:
                    exit(0);
                default:
                    cout << "Invalid choice, please try again." << endl;
                    break;
            }
            getch();
            system("cls"); // Clear the console screen
            goto a;
            
            

        // } while (choice != 4);
    }
};

int main() {
    system("cls");
    Setting s;
    s.Display();
    return 0;
}
