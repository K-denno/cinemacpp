#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Student {        // The class
  public:          // Access specifier
    string name;  // Attribute
    string course;
    int midsem;
    int endsem;  // Attribute
    int assignment;      // Attribute
    Student(string name,string course,int midsem,int endsem,int assignment) { // Constructor with parameters
     name=name;
     course=course;
     midsem=midsem;
     endsem=endsem;
     assignment=assignment;
    }

};


int main()
{
    vector<string> names;
    vector<string> courses;
    vector<int> midsemester;
    vector<int> assignments;
    vector<int> endsemester;
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
        int mid,ass,endsem;
        string gendr;
        cout<< "Adding New Student "<<endl;
        cout<< "Enter name >> ";
        cin>>nam;
        cout<< "Enter course >> ";
        cin>>course;
        cout<< "Enter mid sem mark >> ";
        cin>>mid;
        cout<< "Enter assignment mark >> ";
        cin>>ass;
        cout<< "Enter end sem mark >> ";
        cin>>endsem;
        Student student(nam,course,mid,endsem,ass);
        names.push_back(nam);
        courses.push_back(course);
        midsemester.push_back(mid);
        endsemester.push_back(endsem);
        assignments.push_back(ass);
    }else if(option==2){
        cout << "\n \n Here's a list of students"<<endl;
        cout << "N0.**********NAME**********COURSE**********MID SEM**********ASSIGNMENT**********END SEM"<<endl;
        for(int i=0;i<names.size();i++){
        cout<<"\n"<<endl;
        cout<<"["+ to_string(i) + "]          "+ names[i] +"          " +courses[i] +"              "+ to_string(midsemester[i] ) + "               "+ to_string(assignments[i]) + "               "+ to_string(endsemester[i])  <<endl;
        cout<<"\n"<<endl;
        };
    }else if(option==4){
        vector<int> randomNumbers;
        for(int i=0;i<=1;i++){
            int result=1 + (rand() % names.size());
            randomNumbers.push_back(result);
        };
        int avgmid,avgass,avgend;
        for(int i=0;i<randomNumbers.size()-1;i++){
            cout << "N0.**********NAME**********COURSE**********MID SEM**********ASSIGNMENT**********END SEM"<<endl;
            cout<<"\n"<<endl;
            cout<<"["+ to_string(i) + "]          " + names[randomNumbers[i]] +"               "+ courses[randomNumbers[i]] + "               "+to_string(midsemester[randomNumbers[i]])  + "               "+ to_string(assignments[randomNumbers[i]])+ "               "+ to_string(endsemester[randomNumbers[i]])    <<endl;
            cout<<"\n"<<endl;
            avgmid+=midsemester[i];
            avgass+=assignments[i];
            avgend+=endsemester[i];
        }
        cout << "Average mid sem performance was "+  avgmid/randomNumbers.size()-1<< endl;
        cout << "Average assignment performance was "+ avgass/randomNumbers.size()-1<< endl;
        cout << "Average end sem performance was "+ avgend/randomNumbers.size()-1<< endl;
    }else if(option==3){
        string findname;
        int foundIndex;
        cout << "Enter name of student>> ";
        cin>> findname;
        for (int i=0;i<names.size();i++){
            if(findname==names[i]){
                string newname;
                int mid,endsem,ass;
                cout << "Enter new name for " + names[i]+" >> ";
                cin>>newname;
                cout << "Enter new mid-sem for " + to_string(midsemester[i]) +" in "+ courses[i]+ " >> ";
                cin>>mid;
                cout << "Enter new assignment for " + to_string(assignments[i]) +" in "+ courses[i]+ " >> ";
                cin>>ass;
                cout << "Enter new end sem for " + to_string(endsemester[i]) +" in "+ courses[i]+ " >> ";
                cin>>endsem;
                names[i]=newname;
                midsemester[i]=mid;
                assignments[i]=ass;
                endsemester[i]=endsem;
                cout<<"Marks succesfully editted"<<endl;

            }else{
                cout << " Invalid entry " << endl;
            }
        };

    }


    }
    return 0;

}

