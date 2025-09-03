#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;

void display_menu();
void room_status(bool isbooked[]);
void all_room_status(bool isbooked[],string customer[]);
void room_booking(bool isbooked[],string customer[]);
void check_out(bool isbooked[],string customer[]);
void search_room(bool isbooked[],string customer[]);

void display_menu(){
cout<<"1. View Room Status:"<<endl; 
cout<<"2.Veiw all room."<<endl;
cout<<"3. Book a Room "<<endl;
cout<<"4. Check Out "<<endl;
cout<<"5.Search for room "<<endl;
cout<<"6. Exit"<<endl;
}
void room_status(bool isbooked[]){
    int i;
    cout<<"ENTER THE ROOM NUMBER: ";
    cin>>i;
    if(isbooked[i-1]==0){
        cout<<"ROOM IS AVAILABLE"<<endl;
    }
    else{
        cout<<"ROOM IS NOT AVAILABLE"<<endl;
    }

}
void all_room_status(bool isbooked[],string customer[]){
    int i;
     for(i=0;i<10;i++){
        if(isbooked[i]==1){
            cout<<"ROOM "<<i+1<<": BOOKED."<<"     "<<"CUSTOMER NAME: "<<customer[i]<<endl;
                    }
        else{
            cout<<"ROOM "<<i+1<<" AVAILABLE"<<endl;
        }
     }
}
void room_booking(bool isbooked[],string customer[]){
    int i;
    cout<<"ENTER THE ROOM NUMBER: ";
    cin>>i;
    if(isbooked[i-1]==0){
        cout<<"YOUR ROOM IS BOOKED"<<endl;
        cout<<"ENTER THE NAME: ";
        cin>>customer[i-1];
        isbooked[i-1]=true;

        ofstream outputfile("booking.txt",ios::app);
        outputfile<< "ROOM "<<i+1<<" BOOKED     "<<"  CUSTOMER NAME"<<customer[i-1]<<endl;
        outputfile.close();
        }
    else{
        cout<<"ROOM IS OCCUPIED"<<endl;
    }
}
void check_out(bool isbooked[],string customer[]){
    bool checkout;
    int i;
      int days;
    double rate;
    double charges;
    double amount;
    cout<<"ENTER THE ROOM NUMBER:";
    cin>>i;
    if(isbooked[i-1]==0){
        cout<<"ROOM IS ALREADY AVAILABLE"<<endl;
    }
    else if (isbooked[i-1]==1){
       cout<<"ENTER NUMBER OF DAYS: ";
    cin>>days;
    cout<<"ENTER CHARGES PER NIGHT: ";
    cin>>rate;
    charges=days*rate;
    cout<<"YOUR BILL IS "<<charges;
    cout<<"ENTER AMOUNT PAID: ";
    cin>>amount;
   double  balance=amount-charges;
   cout<<"BALANCE: "<<balance<<endl;
        cout<<"ROOM IS FREE NOW"<<endl;
        isbooked[i]=false;
        ofstream outputfile("checkout.txt",ios::app);
        outputfile<<"  CUSTOMER NAME"<<customer[i-1]<<"    BILL PAID:"<<charges<<"  DAYS STAYED:"<<days<<endl;
        outputfile.close();
    }
    else{
        cout<<"ROOM IS OCCUPIED."<<endl;
    }
}
void search_room(bool isbooked[],string customer[]){
    int i;
    cout<<"ENTER THE ROOM NUMBER:";
    cin>>i;
     if(isbooked[i-1]==0){
        cout<<"ROOM IS AVAILABLE"<<endl;
    }
    else{
        cout<<"ROOM IS NOT AVAILABLE"<<endl;
        cout<<"CUSTOMER NAME: "<<customer[i-1]<<endl;
    }


}

  
int main(){
    int choice;
    bool isbooked[10]={};
    string customer[10]={};
    display_menu();
    do{
    do{
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    }while(choice>6);
    if(choice==1){
        room_status(isbooked);
    }
    else if (choice==2){
        all_room_status(isbooked,customer);
    }
    else if(choice==3){
        room_booking(isbooked,customer);
    }
    else if(choice==4){
        check_out(isbooked,customer);
    }
    else if(choice==5){
        search_room(isbooked,customer);
    }
    
}while(choice!=6);
cout<<"THANK YOU FOR USING!"<<endl;


}