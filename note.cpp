// #include<iostream>
// #include<fstream>
// #include<string.h>
// using namespace std;

// void firstMenu(){
//     cout<<"====================================================================================================================================="<<endl;
//     cout<<"                                   1. Login                                                                                          "<<endl;
//     cout<<"                                   2. List all Products                                                                              "<<endl;
//     cout<<"                                   3. Add Products to Cart                                                                           "<<endl;
//     cout<<"                                   4. Order Product                                                                                  "<<endl;
//     cout<<"                                   5. Setting                                                                                        "<<endl;
//     cout<<"                                   0. Exit                                                                                           "<<endl;
//     cout<<"====================================================================================================================================="<<endl;
//     cout<<"Please Enter Your Choice: ";
// }
//     string userId, userPassword, id, pass;
// void registerUser(){
//     system("cls");
//     cout<<"|------Please Register Your Account-------|"<<endl;
//     cout<<"           USERNAME: ";
//     cin>>userId;
//     cout<<"           PASSWORD: ";
//     cin>>userPassword;
//     ofstream f1("records.txt", ios::app);
//     if (f1.is_open()) {
//     f1<<userId<<" "<<userPassword<<endl;
//     f1.close();
//     cout<<"......................................................"<<endl;
//     cout<<" You completed your Accoung Successfully. "<<endl;
// }else{
//     cout<<"Please try again!"<<endl;
// }
// }

// void login(){
//     bool count = false;
//     string  userPassword,id;
//     cout<<"                 [+2]. Login Account                                     "<<endl;
//     cout<<"           USERNAME:                     ";
//     cin>>userId;
//     cout<<"           PASSWORD:                     ";
//     cin>>userPassword;
//     ifstream input("records.txt");
//     while(input>>id>>pass){
//         if(id==userId && pass==userPassword){
//             count=true;
//             system("cls");
//             break;
//         }
//     }
//     if(count==true){
//         cout <<userId << "  Your Login is Successful. " << endl;
//     } else {
//         cout << "  Your Login is Incorrect. Please try again!! " << endl;
//     }
//     input.close();
// }

// void forgot(){
//     int option;
//     cout<<"|       1. Search Id by Username           |"<<endl;
//     cout<<"|       2. Go Back to the Menu             |"<<endl;
//     cout<<"Please Enter Your Option: ";
//     cin>>option;
//     switch(option){
//         case 1:{
//             bool found = false;  // Use 'found' instead of 'count' for clarity
//             string suserId, sid, spass;
//             cout << "USERNAME: ";
//             cin >> suserId;

//             ifstream f2("records.txt");
//             if (f2.is_open()) {
//                 while (f2 >> sid >> spass) {
//                     if (sid == suserId) {
//                         found = true;
//                         cout << "Your Account is Found." << endl;
//                         cout << "Your Password is: " << spass << endl;
//                         break;  // Exit loop after finding the user
//                     }
//                 }
//                 f2.close();
//             } else {
//                 cout << "Error opening file." << endl;
//             }

//             if (!found) {
//                 cout << "Sorry! Your Account is Not Found." << endl;
//             }
//             break;
//         }
//         case 2:
//             // Go back to the previous menu
//             break;
//         default:
//             cout << "Invalid option. Please try again!" << endl;
//     }
// }




            
// //         break;
// //         }
// //         case 2:{
       
// //         break;
// //         }
// //         default:
// //             cout<<"Please try Again!  "<<endl;
// //     }
    
// // }

//  void secondMenu(){
//     cout<<"......................................................................................................"<<endl;
//     cout<<"                                        [+1]. Register Account                                        "<<endl;
//     cout<<"                                        [+2]. Login Account                                           "<<endl;
//     cout<<"                                        [+3]. Forgot Password                                         "<<endl;
//     cout<<"                                        [+0]. Exit                                                    "<<endl;
//     cout<<"......................................................................................................"<<endl;
//     cout<<"Please Enter your Choice: ";
//  }

//  void loginRegisterUser(){
//     int option;
//     do{
//     secondMenu();
//     cin>>option;
//     switch(option){
//         case 1: {
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
//         case 0:{
//             cout<<" Please Enter Again!!"<<endl;
//             break;
//         }
//         default:
//         cout<<"Please Enter Again!! ";
//     }
//     }while( option!=3);
//  }  
 
   
// int main(){
//     system("cls");
//     int choice;
//     firstMenu();
//     do{
//         cin>>choice;
//     switch(choice){
//         case 1:{
//         loginRegisterUser();
//         break;
//         }
//         case 2:{
//             break;
//         }
//         case 3:{
//             break;
//         }
//         case 4:{
//             break;
//         }
//         case 5:{
//             break;
//         }
//         case 0:{
//             break;
//         }
//         default:
//         cout<<"Please Try Again!!";
//     }
//     }while(choice !=5);
//     return 0;
// }





#include <iostream>
#include <fstream>


using namespace std;
using namespace qrcodegen;

void generateQRCode(const string& data, const string& filename) {
    // Create a QR Code with the given data
    const QrCode::Ecc errCorrLvl = QrCode::Ecc::LOW;  // Error correction level
    const QrCode qr = QrCode::encodeText(data.c_str(), errCorrLvl);

    // Write the QR Code to a PPM file (a simple image format)
    ofstream ofs(filename, ios::binary);
    if (!ofs) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    const int size = qr.getSize();
    ofs << "P6\n" << size << ' ' << size << "\n255\n";
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            const bool isBlack = qr.getModule(x, y);
            const unsigned char color = isBlack ? 0 : 255;
            ofs.write(reinterpret_cast<const char*>(&color), 1);  // R
            ofs.write(reinterpret_cast<const char*>(&color), 1);  // G
            ofs.write(reinterpret_cast<const char*>(&color), 1);  // B
        }
    }
}

int main() {
    // Define the payment data to be encoded
    string paymentData = "https://example.com/pay?amount=10.00&currency=USD";  // Replace with actual payment URL or data

    // Generate the QR code and save it as a PPM file
    generateQRCode(paymentData, "payment_qr.ppm");

    cout << "QR code generated and saved as payment_qr.ppm" << endl;
    return 0;
}
