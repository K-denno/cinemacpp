#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Student {        // The class
  public:          // Access specifier
    string name;  // Attribute
    string gender;
    string course;
    int mark;  // Attribute
    int age;      // Attribute
    Student(string name,string gender,int age,string course,int marks) { // Constructor with parameters
      age=age;
      gender=gender;
      name=name;
      course=course;
      mark=marks;
    }

};


int main()
{
    vector<int> ages;
    vector<string> names;
    vector<int> marks;
    vector<string> genders;
    vector<string> courses;
    while(true){
    cout <<"[+]***************************Heeeeey Welcome******************************[+]"<<endl;
    cout<< "Pick an option"<<endl;
    cout<< "1) Add new User"<<endl;
    cout<< "2) View All students"<<endl;
    cout<< "3) Edit marks"<<endl;
    cout<< "4) Get Samples"<<endl;

    int option;
    cout << "option >> ";
    cin >> option;
    if(option==1){
        string nam,course;
        int ag,grade;
        string gendr;
        cout<< "Add New User >> "<<endl;
        cout<< "Enter name >> ";
        cin>>nam;
        cout<< "Enter gender >> ";
        cin>>gendr;
        cout<< "Enter age >> ";
        cin>>ag;
        cout<< "Enter course >> ";
        cin>>course;
        cout<< "Enter mark >> ";
        cin>>grade;
        Student student(nam,gendr,ag,course,grade);
        ages.push_back(ag);
        names.push_back(nam);
        genders.push_back(gendr);
        courses.push_back(course);
        marks.push_back(grade);
    }else if(option==2){
        cout << "\n \n Here's a list of students"<<endl;
        cout << "N0.**********NAME**********AGE**********Gender**********COURSE**********MARK"<<endl;
        for(int i=0;i<names.size();i++){
        cout<<"\n"<<endl;
        cout<<"["+ to_string(i) + "]          "+ names[i] +"          " + to_string(ages[i] )+"               "+ genders[i] + "               "+ courses[i] + "               "+ to_string(marks[i])  <<endl;
        cout<<"\n"<<endl;
        };
    }else if(option==4){
        vector<int> randomNumbers;
        for(int i=0;i<5;i++){
            int result=1 + (rand() % names.size());
            randomNumbers.push_back(result);
        };
        int avg;
        for(int i=0;i<randomNumbers.size()-1;i++){
            cout<<"\n"<<endl;
            cout<<"["+ to_string(i) + "]          " + to_string(ages[randomNumbers[i]])+"               "+ genders[randomNumbers[i]] + "               "+ courses[randomNumbers[i]] + "               "+ to_string(marks[randomNumbers[i]])  <<endl;
            cout<<"\n"<<endl;
            avg+=marks[i];
        }

        int average = avg/randomNumbers.size()-1;
        cout << "Average performance was "+ average<< endl;
    }else if(option==3){
        string findname;

        int foundIndex;
        cout << "Enter name of student>> ";
        cin>> findname;
        for (int i=0;i<names.size();i++){
            if(findname==names[i]){
                string newname;
                int mark;
                cout << "Enter new name for " + names[i]+" >> ";
                cin>>newname;
                cout << "Enter new marks for " + to_string(marks[i]) +" in "+ courses[i]+ " >> ";
                cin>>mark;
                names[i]=newname;
                marks[i]=mark;

                cout<<"Marks succesfully editted"<<endl;

            }else{
                cout << " Invalid entry " << endl;
            }
        };

    }


    }
    return 0;

}

