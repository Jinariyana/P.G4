#include<iostream>
#include<sstream>
#include<vector>

using namespace std;
int row, col;   
string **ha;

void showHall(auto data){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" | "<<data[i][j]<<" ";
        }
        cout<<" |\n";
    }
}
string ** setUpHall(const int r, const int c){
    
    row = r;
    col = c;
    string **ha = new string *[row];
    for(int i=0;i<row;i++){
        ha[i] = new string[col];
    }
    char k = 'A';
    for(int i=0; i<r; i++){
        stringstream z;
        z<<(i+1);
        string sub = "-";
        for(int j=0; j<c; j++,k++){
            ha[i][j] = k + sub + z.str() + ": AV";
        }
    }
    return ha;
    
}


void choice(){
    cout<<"1/ Set up hall\n";
    cout<<"2/ List all hall\n";
    cout<<"3/ Start Booking\n";
    cout<<"--------------------\n";
}

void bookHall(string **ha, string hallCode){
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            size_t pos = ha[i][j].find(":");
            string data = ha[i][j].substr(0,pos);
            if(hallCode==data){
                cout<<"[!]  Booked successfully on hall: " + data<<endl;
                ha[i][j] = data + ": BO";
                return;
            }
        }
    }
}
void ui(){
    cout<<"=================================\n";
    cout<<"           Hall Booking          \n";
    cout<<"=================================\n";
    choice();
    // 
    int ch;
    cout<<"[+] Insert option: ";cin>>ch;
    switch(ch){
        case 1:{
            int r, c;
            cout<<"Insert row: ";cin>>r;
            cout<<"Insert column: ";cin>>c;
            cout<<"Setup Hall"<<endl;
            ha = setUpHall(r,c);
            showHall(ha);
            break;
        }
        case 2:{
            cout<<"List all hall"<<endl;
            showHall(ha);
            break;
        }
        case 3:{
            cout<<"Start Booing"<<endl;
            // Implement booking function here
            string opt;
            cout<<"[+] Insert Hall number (A-1, B-1,..): ";cin>>opt;
            bookHall(ha, opt);
            break;
        }
        default:{
            cout<<"Invalid option!"<<endl;
            break;
        }
    }
}

int main(){
    while(1){
        ui();
    }
    return 0;
}
