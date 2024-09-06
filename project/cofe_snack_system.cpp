#include<iostream>
#include<string>
using namespace std;
class Drink{
    protected:
      string id;
      string name;
      float price;
      int qty;
    public:
       Drink(string i = "", string n = "", int q = 0, float p = 0.0) : id(i), name(n), qty(q), price(p) {}
      
     void input(){
        cout<<"Enter Id:                  ";
        cin>>id;
        cin.ignore();
        cout<<"Enter Type of Drink:        ";
        getline(cin,name);
        cout<<"Enter Qty:                  ";
        cin>>qty;
        cout<<"Enter Price of Drink:        ";
        cin>>price;
    }
     float total(){
        return price*qty;
    }
    void setId(string i){  id=i ;}
    void setName(string n){ name=n;}
    void setQty(int q){ qty=q ;}
    void setPrice(float p){ price=p;}
    
    string getId(){ return id;}
    string getName(){return name;}
    int getQty(){return qty;}
    float getPrice(){ return price;}


    
    void printIn(){
        cout<<"Id:                   "<<id<<endl;
        cout<<"Type of Drink:        "<<name<<endl;
        cout<<"Qty of Drink :        "<<qty<<endl;
        cout<<"Price of Drink:       "<<price<<endl;
        cout<<"********************************"<<endl;
        cout<<"Total Drink:          "<<total()<<endl;
    }

};
class Snack{
    protected:
      string id;
      string name;
      int qty;
      float price;
    public:
        Snack(string i = "", string n = "", int q = 0, float p = 0.0) : id(i), name(n), qty(q), price(p) {}
       void input(){
       
        cout<<"Enter Id:                  ";
        cin>>id;
        cin.ignore();
        cout<<"Enter Type of Snack:        ";
        getline(cin,name);
        cout<<"Enter Qty:                  ";
        cin>>qty;
        cout<<"Enter Price of Snack:        ";
        cin>>price;
    }
       float total(){
        return qty*price;
       }

    void setId(string i){  id=i ;}
    void setName(string n){ name=n;}
    void setQty(int q){ qty=q ;}
    void setPrice(float p){ price=p;}
    
    string getId(){ return id;}
    string getName(){return name;}
    int getQty(){return qty;}
    float getPrice(){ return price;}

    

    void printIn(){
        cout<<endl;
        cout<<"Id:                   "<<id<<endl;
        cout<<"Type of Snack:        "<<name<<endl;
        cout<<"Qty of snack :        "<<qty<<endl;
        cout<<"Price of Snack:       "<<price<<endl;
        cout<<"*****************************"<<endl;
        cout<<"Total Snack:          "<<total()<<endl;
        cout<<endl;
    }
    };


class Buyer: public Drink, public Snack{
    public:
      Buyer():Drink(),Snack(){}
      // Constructor with parameters for both base classes
      Buyer(string di, string dn, int dq, float dp, string si, string sn, int sq, float sp)
        : Drink(di, dn, dq, dp), Snack(si, sn, sq, sp) {}

      void input(){
        cout<<"------------Input for Drink--------"<<endl;
        Drink::input();
        cout<<"------------Input for Snack---------"<<endl;
        Snack::input();
      }
      float total(){
        return Drink::total()+ Snack::total();
      }
      void print(){
    cout<<endl;
    cout<<"|-------------Show for Drink---------|"<<endl;
      Drink::printIn();
      cout<<endl;
      cout<<"|-------------Show for Snack---------|"<<endl;
      Snack::printIn();
      }
      void printIn(){
        cout<<"Total:       "<<total()<<endl;
      }
};




int main(){
    system("cls");
    Buyer b;
    b.input();
    b.print();
    b.printIn();
    return 0;
}




