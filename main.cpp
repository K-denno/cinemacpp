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
    vector<Customer> customers; //create an empty list of type customers to create a customer
    vector<Seat> seats; //create an empty list of type Seat to store seats
    int totalCash=0;
    //prepopulate seats
    for(int i=1;i<=20;i++){
    //create the number of seats an keeps their occupied status as false
        Seat seat(i,false);
        seats.push_back(seat); //adds seats to the seats list ie push_back()
    };

    cout <<"********************" <<endl;
    cout <<"*            WELCOME TO IMAX MOVIE THEATER               *"<<endl;
    cout <<"********************" <<endl;

    while(true){
         int option;

        cout <<"**********"<<endl;
        cout <<"*         MAIN MENU          *"<<endl;
        cout <<"**********"<<endl;

        cout<< "Choose one of the following options: "<<endl;
        cout<< "\t 1) Book Seat"<<endl;
        cout<< "\t 2) View Available Seats"<<endl;
        cout<< "\t 3) View Gross Profit"<<endl;
        cout<< "\t 4) Change Marathon Type"<<endl;
        cout<< "\t 5) Make Seat Vacant"<<endl;
        cout<< "\t 6) View Customer details"<<endl;

        //get user input for options
        cout<<"Choose option >> ";
        cin>>option;
        if(option==1){
        //cretae user methods
            int seatNumber,possible; //initialise variales but they are not assigned to any values
            string name,marathon; //initialise variales but they are not assigned to any values
            cout <<"\t============================================================================="<<endl;
            cout <<"\tYou have selected the option to book a seat.Kindly fill in the details below:"<<endl;
            cout <<"\t============================================================================="<<endl;

            cout << "Enter customer name >> ";
            cin >>name; //get user input from user and store in variable name
            cout << "Enter seat number (1-20) >> ";
            cin>>seatNumber; //get user input from user and store in variable seatNumber
            if(seatNumber<=20){
                cout<< "Enter marathon type (half/full) >> ";
                cin >> marathon; //make sure seat number is within require range
            }else{
                cout <<"===================================================================" <<endl;
                cout <<"        FAILED!Pick a range of seats between 1 to 20               "<<endl;
                cout <<"===================================================================" <<endl;
            }
            try{
                if((seatNumber<=20)&&(seats[seatNumber-1].occupied==false)&&((marathon=="half")||(marathon=="full"))){
                    Customer customer(seatNumber,name,marathon);//crae an object from the details entered by the user
                    totalCash+=customer.amount; //edit amount entered by the user add their amount depending on the matrathon they picked
                    customers.push_back(customer);//add customer object to customers list
                    seats[seatNumber-1].occupied=true;// seat the seat6 occupancy to true
                    cout <<"\t====================="<<endl;
                    cout<<"\t Success:Seat Booked "<<endl;
                    cout <<"\t====================="<<endl;
                }else{
                    cout<<"========================================================="<<endl;
                    cout<<"Failed:You cannot book this seat.Kindly book another one."<<endl;
                    cout<<"========================================================="<<endl;
                }
            }catch(exception){}

        }else if(option==2){
            cout<<"==================================="<<endl;
            cout<<"           Available seats         "<<endl;
            cout<<"==================================="<<endl;

            cout<<"SeatNo.\t\t\t Booked"<<endl;
            for(int i=0;i<=seats.size()-1;i++){
            //loops through all seats
                if(seats[i].occupied==false){
                //if seat is not occupied, displayed by the next lin
                    cout <<to_string(seats[i].number)+ "\t\t\tfalse"<<endl;
                }else{
                //displays occupies seats withn the loop
                    cout <<to_string(seats[i].number)+ "\t\t\ttrue"<<endl;
                }
            }

        }
        else if(option==3){
            cout <<"=================================" <<endl;
            cout<<" Gross profit is " + to_string(totalCash) +"/="<<endl; //diplays gross profit from the totalCash variable
            cout <<"=================================" <<endl;

        }else if(option==4){
            cout<<"\t\t\t===================="<<endl;
            cout<<"\t\t\tChange Marathon Type"<<endl;
            cout<<"\t\t\t===================="<<endl;
            int seat,status=0;//status initilised to zero so as differentiate if marathon is changed or failed
            string marathon,name;
            cout<<"Enter Customer name >> ";
            cin>>name; //gets name of customer
            cout<<"Enter Seat Number >> ";
            cin>>seat;//gets seatnumber of user
            for(int i=0;i<customers.size();i++){
                if((customers[i].userName==name)&&(customers[i].seatNumber==seat)){
                    cout<<"Enter New Marathon type >> ";
                    cin>>marathon;
                    customers[i].type = marathon;
                    if(marathon=="half"){
                    //this code runs if the marathin eneterd by the user is half
                        totalCash-=5000;
                        customers[i].type="half";
                        customers[i].amount=5000;
                        status=1;
                        cout<<"\t\t===================================================="<<endl;
                        cout<<"\t\t Success:Marathon type switched to half marathon"<<endl;
                        cout<<"\t\t===================================================="<<endl;

                    }else if(marathon=="full"){
                    //runs if the marathon entered by the user is full
                        totalCash+=5000;
                        customers[i].type="full";
                        customers[i].amount=10000;
                        cout<<"\t\t===================================================="<<endl;
                        cout<<"\t\t Success:Marathon type switched to full marathon"<<endl;
                        cout<<"\t\t===================================================="<<endl;
                        status=1; //if the marathon is chand=ged the status is changed to one to differentiate it with when it is not chaned
                    }
                }else{

                }
            }
            //this checks if the status was changed bacause if the status changed it means a marathon was update if it didnt change the marathon was not updated dued too invalid entre hence the erro message bello is displayed
            if(status!=1){ //status!=1-----> interpreted as if status is not equal to 1
            cout<<status<<endl;
            cout<<"\t\t========================="<<endl;
            cout<<"\t\t Failed:Invalid Entry"<<endl;
            cout<<"\t\t========================="<<endl;
            }

        }else if(option==5){
            cout<<"\t\t\t===================="<<endl;
            cout<<"\t\t\t Make seat available"<<endl;
            cout<<"\t\t\t===================="<<endl;

            int seatnumber;
            string name;
            cout<<"Input Customer name >> ";
            cin>>name; //get name of user and store in variable name
            cout<<"Input Seat Seat Number >> ";
            cin>>seatnumber;
            for(int i=0;i<seats.size();i++){
            //loop through all seats
                if(seats[i].number==seatnumber){//check if seat nubmered entered by user mathes the one the user was sitting on
                    if (seats[i].occupied==true){
                    seats[i].occupied=false;//if the seat checks out from above comment it is made available
                    for(int i=0;i<=customers.size();i++){
                        if(name==customers[i].userName){//this loops throught our list of users
                            customers.erase(customers.begin()+i);//removes the user whose sseat has been made available......isslike the user left the cinema therefore their record is removed
                        }
                    }
                    cout<<"\t\t=================================="<<endl;
                    cout<<"\t\t Success:Seat is now Available"<<endl;
                    cout<<"\t\t=================================="<<endl;
                }else{
                    cout<<"\t\t======================================"<<endl;
                    cout<<"\t\t Success:Seat is already available"<<endl;
                    cout<<"\t\t======================================"<<endl;
                }
                }else{
                    //cout<<"\t\t Failed:Seat doen't exist"<<endl;
                }
            }

        }else if(option==6){
            cout <<"=====================================================================================" <<endl;
            cout<<"Customer's Name\t\tSeatNo. booked\t\tMarathon Type\t\tAmount Paid"<<endl;
            for(int i=0;i<customers.size();i++){
            //loops through all users displaying their details
                cout<<customers[i].userName+"\t\t\t"+ to_string(customers[i].seatNumber)+"\t\t\t"+customers[i].type+" \t\t\t"+to_string(customers[i].amount)<<endl;
            }
        }


    }
}
