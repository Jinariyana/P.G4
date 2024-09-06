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







curl \
  -H 'Content-Type: application/json' \
  -d '{
  "contents": [
    {
      "parts": [
        {
          "text": "Input all List Product in c++ code"
        }
      ]
    }
  ]
}' \
  -X POST 'https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=AIzaSyASBQggVtQiwxqf5LT-qtA7bZY5a_3QJZw'
