#include<iostream>
#include<iomanip>
using namespace std;
void menu() {
    cout<<"--------------------------------Employee Managment System----------------------"<<endl;
    cout << "1. Add Employee." << endl;
    cout << "2. Update Employee." << endl;
    cout << "3. Delete Employee." << endl;
    cout << "4. Sort Employee accending by salary." << endl;
    cout << "5. Display Employee." << endl;
    cout << "6. Search Employee." << endl;
    cout << "0. Exit." << endl;
    cout<<"========================"<<endl;
    cout << "Enter Your Option: ";
} ko

int employeeId[100];
string employeeName[100];
float employeeSalary[100];
int employeeCount=0;

//1. Add 
void addEmployee() {
    cout<<"========Add Employee========"<<endl;
    employeeId[employeeCount]=employeeCount+1;
    cout<<"Enter Id Employee: ";
    cin>>employeeId[employeeCount];
    cin.ignore();
    cout<<"Enter Name Employee: ";
    getline(cin,employeeName[employeeCount]);
    cout<<"Enter Salary Employee: ";
    cin>>employeeSalary[employeeCount];
    employeeCount++;
    cout<<"-------------------"<<endl;
    cout<<"You Add Employee Successfully."<<endl;
}


//2.Update
void updateEmployee() {
    int updateId;
    cout << "Enter Employee Id to update: ";
    cin >> updateId;
    cin.ignore();  

    bool found = false;  
    for (int i = 0; i < employeeCount; i++) {
        if (employeeId[i] == updateId){
            cout << "Enter New Name Employee: ";
            getline(cin, employeeName[i]);
            
            cout << "Enter New Salary Employee: ";
            cin >> employeeSalary[i];
            cin.ignore();  
            
            cout << "---------------------------------" << endl;
            cout << "Updated Employee Successfully!" << endl;
            found = true;  
            break;
        }
    }
    
    if (!found) {
        cout << "Employee not found." << endl; 
    }
}
//3.Delete
void deleteEmployee() {
    int deleteId;
    cout<<"Enter Id Employee to delete: ";
    cin>>deleteId;
    for(int i=0;i<employeeCount;i++){
        if(employeeId[i]==deleteId){
            for(int j=i;j<employeeCount-1;j++){
                employeeId[j]=employeeId[j+1];
                employeeName[j]=employeeName[j+1];
                employeeSalary[j]=employeeSalary[j+1];
             }
             employeeCount--;
             cout<<"Employee deleted Successfully!"<<endl;
        }
    }





}
//4.Sort
void sortEmployee() {
    for (int i = 0; i < employeeCount ; i++) {
        for (int j = 0; j < employeeCount-1; j++) {
            if (employeeSalary[j] > employeeSalary[j+1]) {
                float tempSalary = employeeSalary[j];
                employeeSalary[j] = employeeSalary[j+1];
                employeeSalary[j+1] = tempSalary;
                int tempId = employeeId[j];
                employeeId[j] = employeeId[j+1];
                employeeId[j+1] = tempId;
                string tempName = employeeName[j];
                employeeName[j] = employeeName[j+1];
                employeeName[j+1] = tempName;
            }
        }
    }
    cout << "Employees sorted by salary completed!"<<endl;
 
}





//5.display
void displayEmployee() {
    cout<<"======Display Employee========"<<endl;
    cout<<setw(5)<<"Id"<<setw(25)<<"Name"<<setw(25)<<"Salary"<<endl;
    for(int i=0;i<employeeCount;i++){
        cout<<setw(5)<<employeeId[i]<<setw(25)<<employeeName[i]<<setw(25)<<employeeSalary[i]<<endl;
    }
    cout<<"Employee Total: "<<employeeCount<<endl;
}



//6.Search
void searchEmployee(){
 int searchId;
 cout<<"Enter Id Employee to Search: ";
 cin>>searchId;
 for(int i=0;i<employeeCount;i++){
    if(employeeId[i]==searchId){
  cout<<setw(5)<<"Id"<<setw(25)<<"Name"<<setw(25)<<"Salary"<<endl;
  cout<<setw(5)<<employeeId[i]<<setw(25)<<employeeName[i]<<setw(25)<<employeeSalary[i]<<endl;
    }
    }
    
 }

int main() {
    system("cls");
    int opt;
    do {
        menu();
        cin >> opt;
        switch (opt) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                sortEmployee();
                break;
            case 5:
                displayEmployee();
                break;
            case 6:
              searchEmployee();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Choose again!" << endl;
        }
    } while (opt != 0);

    return 0;
}




