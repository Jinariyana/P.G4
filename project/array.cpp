#include <iostream>

using namespace std;

void printArray(string name[], float salary[], int size){
    cout << "Employee Name\t\tSalary" << endl;
    for(int i=0; i<size; i++){
        cout << name[i] << "\t\t" << salary[i] << endl;
    }
    cout << endl;
}

int main(){
    system("cls");
    string employeeNames[] ={
        "John",
        "Doe",
        "Jane",
        "Alex",
        "Mary"
    };
    float employeeSalaries[] = {
        1000.50,
        4000.75,
        2000.75,
        5000.25,
        3000.25
    };

    int sizeTotal = sizeof(employeeNames);
    int sizeElement = sizeof(employeeNames[0]);
    int numberElements = sizeTotal / sizeElement;

    cout << "Original array: " << endl;
    printArray(employeeNames, employeeSalaries, numberElements);
    for(int i=0;i<numberElements;i++){
    	for(int j=0;j<numberElements-1;j++){
    		if(employeeNames[j]<employeeNames[j+1] && employeeSalaries[j]>employeeSalaries[j+1]){
                
    			string temp= employeeNames[j];
    			float temps=employeeSalaries[j];
    			employeeNames[j]=employeeNames[j+1];
    			employeeSalaries[j]=employeeSalaries[j+1];
    			employeeNames[j+1]=temp;
    			employeeSalaries[j+1]=temps;
			}
		}
	}
    // code for sort employee salaries in ascending order
    // write code here
    
    cout << "Sorted array: " << endl;
    printArray(employeeNames, employeeSalaries, numberElements);
    return 0;
}