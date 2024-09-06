#include<iostream>
using namespace std;
class Employee{
    public:
    int id;
    string name;
    float salary;
    Employee(int i, string n, float s){
        this->id=i;
        this->name=n;
        this->salary=s;
    }
    void display(){
        cout<<id<<" "<<name<<" "<<salary<<" "<<endl;
    }
};
int main(void){
    Employee e1=Employee(1, "Cheata", 900);//creating an object of employee
    Employee e2=Employee(2, "Seyla",990);
    e1.display();
    e2.display();
    return 0;
}


#include<iostream>
using namespace std;
class Car{
    public:
    string brand;
    string model;
    Car(string b, string m){ //constructor with parameters
        brand=b;
        model=m;
    }
};
int main(){
Car carObj("BMW","X5");//creating an obj
//print value
cout<<carObj.brand<<" "<<carObj.model<<" "<<endl;
return 0;
}







class Employee{
    public:
    Employee(){
        cout<<"Construtor Invoked"<<endl;
    }
    ~Employee(){
        cout<<"Destructor Invoked"<<endl;
    }
};
int main(){
    Employee e1;
    Employee e2;
    return 0;
}
