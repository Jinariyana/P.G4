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
