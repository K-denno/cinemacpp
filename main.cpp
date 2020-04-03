#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Customer{
public:
    int seatNumber;
    string userName;
    int amount;
    string type;

    Customer(int seat,string name,string marathon){
        seatNumber=seat;
        userName=name;
        type=marathon;
        if(marathon=="half"){
            amount=5000;
        }else if(marathon=="full"){
            amount=10000;
        }else{
            cout<<"Error:Defaulting to full marathon"<<endl;
            type="full";
            amount=10000;
        }

    }
};
class Seat{
public:
    int number;
    bool occupied;

    Seat(int num,bool occupied){
        number=num;
        occupied=occupied;

    }
};
        string checkseat(int seat){
        //cinema has only 20 seats....This makes sure seatNumber doesn't exceed 20
            if(seat>20){
                return "Only twenty seats available";
            }else{
                return "Seat booking in progress";
            }
        }

int main()
{
    vector<Customer> customers;
    vector<Seat> seats;
    int totalCash=0;
    //prepopulate seats
    for(int i=1;i<=20;i++){
        Seat seat(i,true);
        seats.push_back(seat);
    };

    cout<<"WELCOME TO IMAX"<<endl;
    while(true){
         int option;
        cout<< "Choose one of the following: "<<endl;
        cout<< "\t 1) Book Seat"<<endl;
        cout<< "\t 2) View Empty Seats"<<endl;
        cout<< "\t 3) View Total Cash Made"<<endl;
        cout<< "\t 4) Change Marathon"<<endl;
        cout<< "\t 5) Make Seat Available"<<endl;
        cout<< "\t 6) View Booked Seats"<<endl;
        //get user input for options
        cout<<"Input option -->> ";
        cin>>option;
        if(option==1){
            int seatNumber,possible;
            string name,marathon;
            cout <<"\t \t \t Let's book a seat, shall we "<<endl;
            cout << "Enter name -->> ";
            cin >>name;
            cout << "Enter seat number -->> ";
            cin>>seatNumber;
            cout<< "Enter Marathon -->> ";
            cin >> marathon;
            try{
                if((seatNumber<=20)&&(seats[seatNumber-1].occupied==false)){
                    Customer customer(seatNumber,name,marathon);
                    totalCash+=customer.amount;
                    customers.push_back(customer);
                    seats[seatNumber-1].occupied=true;
                    cout<<"\t\t success:Seat Booked"<<endl;
                }else{
                    cout<<"\t\tFailed:Cant book this seat"<<endl;
                }
            }catch(exception){}

        }else if(option==2){
            cout<<"Available seats"<<endl;
            cout<<"SeatNo.\t\t\t Occupied"<<endl;
            for(int i=0;i<=seats.size()-1;i++){
                if(seats[i].occupied==false){
                    cout <<to_string(seats[i].number)+ "\t\t\tfalse"<<endl;
                }else{
                    cout <<to_string(seats[i].number)+ "\t\t\ttrue"<<endl;
                }
            }

        }
        else if(option==3){
            cout<<"You have a total cash of -->> " + to_string(totalCash) +"/="<<endl;
        }else if(option==4){
            cout<<"\t\t\t Change Marathon"<<endl;
            int seat;
            string marathon,name;
            cout<<"Enter Customer name -->> ";
            cin>>name;
            cout<<"Enter Seat Number --> ";
            cin>>seat;
            for(int i=0;i<customers.size();i++){
                if((customers[i].userName==name)&&(customers[i].seatNumber==seat)){
                    cout<<"Enter New Marathon type --> ";
                    cin>>marathon;
                    customers[i].type = marathon;
                    if(marathon=="half"){
                        totalCash-=5000;
                        customers[i].type="half";
                        customers[i].amount=5000;
                        cout<<"\t\t success:marathon switched to half marathon"<<endl;
                    }else{
                        totalCash+=5000;
                        customers[i].type="full";
                        customers[i].amount=10000;
                        cout<<"\t\t success:marathon switched to full marathon"<<endl;
                    }
                }else{
                    cout<<"\t\t Failed:Invalid Entry"<<endl;
                }
            }

        }else if(option==5){
            cout<<"\t\t\t Make seat available"<<endl;
            int seatnumber;
            cout<<"Input Seat Number -->> ";
            cin>>seatnumber;
            for(int i=0;i<seats.size();i++){
                if(seats[i].number==seatnumber){
                    if (seats[i].occupied==true){
                    seats[i].occupied=false;
                    cout<<"\t\t success:Seat is now Available"<<endl;
                }else{
                    cout<<"\t\t success:Seat is already available"<<endl;
                }
                }else{
                    //cout<<"\t\t Failed:Seat doen't exist"<<endl;
                }
            }

        }else if(option==6){
            cout<<"name\t\tSeatNo.\t\tMarathon\t\tAmount"<<endl;
            for(int i=0;i<customers.size();i++){
                cout<<customers[i].userName+"\t\t"+ to_string(customers[i].seatNumber)+"\t\t"+customers[i].type+"\t\t\t\t"+to_string(customers[i].amount)<<endl;
            }
        }


    }
}
