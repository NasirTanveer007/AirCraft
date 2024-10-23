#include <iostream>
using namespace std;
#include <string>
// base class
class Directory
{
    // sepcifier
private:
    string Id, Name, Adress, PhoneNo;

public:
    // constructor definition
    Directory()
    {
        Name = "", Id = "", Adress = "", PhoneNo = "";
    }
    // created a function that gets data
    void getdata(string id1, string name1, string adress1, string phoneno1)
    {
        Id = id1;
        Name = name1;
        Adress = adress1;
        PhoneNo = phoneno1;
    }
    // A function Which erase the when user press 0 for not to save
    void erase()
    {
        Id.erase();
        Name.erase();
        Adress.erase();
        PhoneNo.erase();
    }
    /* A function which return try when the string is empty
    created to avoid the display of all the objects and user wants to display all the
    records */
    bool isempty(Directory Students[], int index)
    {
        if (Students[index].Name.empty() && Students[index].Adress.empty() && Students[index].PhoneNo.empty() && Students[index].Id.empty())
        {
            return true;
        }
        return false;
    }
    /*a function which searches the enterd id or name with the already existed name or id
    to prevent user enlist the exited id again*/
    bool search(string Id1)
    {

        if (Id1 == Id || Id1 == Name)
        {
            return true;
        }
        return false;
    }
    // a function which is used to display the record
    void display()
    {
        // for clearing the previous screen

        cout << "===============================================\n";
        cout << "\tTelephone Directory : Record Menue" << endl;
        cout << "===============================================\n";
        // static variable for counting number of records and show
        static int counter;
        counter++;
        cout << "Record No : " << counter << endl;
        cout << "Id : " << Id << endl;
        cout << "Name : " << Name << endl;
        cout << "Adress : " << Adress << endl;
        cout << "PhoneNo : " << PhoneNo << endl;
    }
};
// inherited class
class studentsDirectory : public Directory
{
public:
    Directory Students[100];
    int insertmenue()
    {
        system("CLS");
        // use i integer to get the counter of the loop out of scop
        // flag variable for bool
        int i = 0, flag;
        // is choice for the outer while loop true
        bool ischoice = true;
        // string variable to get data and then initiallized to the objects
        string id1, phone1, name1, adress1;
        // isagain for the inner while true loop
        bool isagain = true;
        while (ischoice)
        {

            while (isagain)
            {
                cout << "===============================================\n";
                cout << "\tTelephone Directory : Insert Menue " << endl;
                cout << "===============================================";
                cout << "\nenter your ID : ";
                // used to prevent mixmaxtch with insertion
                cin.clear();
                cin.sync();
                getline(cin, id1);
                // search loop called
                for (int i = 0; i < 100; i++)
                {
                    if (Students[i].search(id1))
                    {

                        flag = 1;

                        break;
                    }
                }
                if (flag == 1)
                {
                    cout << "id exist Cannot Enter Again" << endl;
                    // beacuse we have to change the flag value again to 0 untill it will remain 1
                    flag = 0;
                    continue;
                }
                else
                {
                    cout << "enter Your name : ";
                    getline(cin, name1);
                    cout << "Enter Adress : ";
                    getline(cin, adress1);
                    cout << "Enter Phone Number : ";
                    getline(cin, phone1);
                    Students[i].getdata(id1, name1, adress1, phone1);
                    char record;
                    int save;
                    cout << "press 1 to save and 0 not to save : " << endl;
                    cin >> save;
                    if (save == 1)
                    {
                        cout << "Record Saved successfylly !" << endl;
                        cout << "Want to insert Another record (y/n) : " << endl;
                        cin >> record;
                        if (record == 'y' || record == 'Y')
                        {
                            i++;
                            continue;
                        }
                        else
                        {

                            break;
                        }
                    }
                    else
                    {
                        Students[i].erase();
                        break;
                    }
                }
            }
            switchmenue();
            return 0;
        }
    }
    // a main menu function
    void MainMenue()
    {
        // for clearing the previous screen
        system("CLS");
        cout << "===============================================\n";
        cout << "\tTelephone Directory : Main Menue " << endl;
        cout << "===============================================" << endl;
        cout << "1) Insert a new student\n2) Update An existing Student\n3) Delete a record\n4) Search for a student (using name or ID)\n5) List directory" << endl;
    }
    /*this function is quite similar data with the insert menue but we craeted this
    when user specifies a record so we get the index number of that object
    */
    void DataGetting(int index)
    {
        // this is for update menue because it have many addition as compared to insert menue;
        int flag;
        bool ischoice = true;
        string id1, phone1, name1, adress1;
        bool isagain = true;
        while (isagain)
        {

            cout << "\nenter your ID : ";
            cin.clear();
            cin.sync();
            getline(cin, id1);
            for (int i = 0; i < 100; i++)
            {
                if (Students[i].search(id1))
                {

                    flag = 1;

                    break;
                }
            }
            if (flag == 1)
            {
                cout << "id exist Cannot Enter Again" << endl;
                // beacuse we have to change the flag value again to 0 untill it will remain 1
                flag = 0;
                continue;
            }
            else
            {
                cout << "enter Your name : ";
                getline(cin, name1);
                cout << "Enter Adress : ";
                getline(cin, adress1);
                cout << "Enter Phone Number : ";
                getline(cin, phone1);
                Students[index].getdata(id1, name1, adress1, phone1);
                cout << "Record Updated Successfully ! " << endl;
                break;
            }
        }
    }
    void switchmenue()
    {

        MainMenue();
        int Choice;
        cout << "Enter Yoour choice : ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
        {
            insertmenue();
        }
        break;
        case 2:
        {
            UpdateMenue();
        }
        break;
        case 3:
        {
            DeleteMenu();
        }
        break;
        case 4:
        {
            SearchMenu();
        }
        break;
        case 5:
        {
            ShowRecords();
        }
        break;
        default:
            cout << "You Entered Invalid Integer Or Wrong choice !";
        }
    }
    // update function
    int UpdateMenue()
    {
        system("CLS");
        bool IsAgainUpdate = true;
        while (IsAgainUpdate)
        {
            cout << "===============================================\n";
            cout << "\tTelephone Directory : Update Menue " << endl;
            cout << "===============================================" << endl;

            string id1;
            cin.clear();
            cin.sync();
            cout << "Enter Your Id or Name : ";
            getline(cin, id1);

            int j;
            int flag = 0;
            for (int i = 0; i < 100; i++)
            {
                if (Students[i].search(id1))
                {
                    j = i;
                    flag = 1;
                    cout << "Current Information is : " << endl;
                    Students[i].display();

                    break;
                }
            }

            if (flag == 1)
            {

                bool isupdate = true;
                char ChoiceUpdate;

                cout << endl;
                cout << "Do you want to update [y/n]?" << endl;
                cin >> ChoiceUpdate;
                if (ChoiceUpdate == 'Y' || ChoiceUpdate == 'y')
                {

                    char ChoiceAnother;
                    DataGetting(j);
                    cout << "Do You want To Update Another Record (Y/N) : ";
                    cin >> ChoiceAnother;
                    if (ChoiceAnother == 'Y' || ChoiceAnother == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        switchmenue();
                        break;
                    }
                }
                else
                {
                    switchmenue();
                    return 0;
                }
            }
            else
            {
                cout << "\nRecord Not Found  Try Again !" << endl;
                int exit;
                cout << "press 1 for Try Again else 2 for exit the program : ";
                cin >> exit;
                if (exit == 1)
                    continue;
                else
                    return 0;
            }
        }
    } // search menu function
    int SearchMenu()
    {
        system("CLS");
        bool IsSeachAgain = true;
        while (IsSeachAgain)
        {
            cout << "===============================================\n";
            cout << "\tTelephone Directory : Search Menu " << endl;
            cout << "===============================================" << endl;
            string id1;
            int flag;
            cout << "\nEnter your ID Or Name : ";
            cin.clear();
            cin.sync();
            getline(cin, id1);
            for (int i = 0; i < 100; i++)
            {
                if (Students[i].search(id1))
                {

                    flag = 1;
                    cout << "Current Information is : " << endl;
                    Students[i].display();

                    break;
                }
            }
            if (flag == 1)
            {
                char SearchAgain;
                cout << "Do You Want To Search Another Record (Y/N) : ";
                cin >> SearchAgain;
                if (SearchAgain == 'Y' || SearchAgain == 'y')
                {
                    continue;
                }
                else
                {
                    switchmenue();
                    return 0;
                }
            }
            else
            {
                cout << "Record Not Found ! Try Again " << endl;
                int exit;
                cout << "press 1 for Try Again else 2 for exit the program : ";
                cin >> exit;
                if (exit == 1)
                    continue;
                else
                    return 0;
            }
        }
    }
    int ShowRecords()
    {
        system("CLS");
        // this loop is to check the all objects which are empty and prevent to display
        for (int i = 0; i < 100; i++)
        {
            if (isempty(Students, i))
            {
                continue;
                // cout<<" ";
            }
            else
            {
                cout << endl;
                Students[i].display();
            }
        }
        cout << "\n\nTotal N NUmber of Records Shown !" << endl;
        char MainMenuChoice;
        cout << "Press M to go main Menu : ";
        cin >> MainMenuChoice;
        if (MainMenuChoice == 'M' || MainMenuChoice == 'm')
        {
            switchmenue();
        }
        else
        {
            return 0;
        }
    }
    int DeleteMenu()
    {
        system("CLS");
        bool DeleteAgain = true;
        while (DeleteAgain)
        {
            cout << "===============================================\n";
            cout << "\tTelephone Directory : Delete Menu " << endl;
            cout << "===============================================" << endl;
            string id1;
            int flag;
            int index;
            cout << "\nEnter your ID Or Name : ";
            cin.clear();
            cin.sync();
            getline(cin, id1);
            for (int i = 0; i < 100; i++)
            {
                if (Students[i].search(id1))
                {

                    index = i;
                    flag = 1;
                    cout << "Current Information is : " << endl;
                    Students[i].display();
                    cout << endl;

                    break;
                }
            }
            if (flag == 1)
            {
                char DeleteRecord;
                cout << "Do You want To delete this Record (Y/N) : " << endl;
                cin >> DeleteRecord;
                if (DeleteRecord == 'Y' || DeleteRecord == 'y')
                {
                    // after getting index use this to initialized that object with
                    // empty string so that in display optin it will never print
                    // accroding to the condition of display menu
                    Students[index].getdata("", "", "", "");
                    cout << "Deleted Successfully !" << endl;
                    char AnotherRecord;
                    cout << "Do You Want To Delete Another Record (Y/N) ";
                    cin >> AnotherRecord;
                    if (AnotherRecord == 'y' || AnotherRecord == 'Y')
                    {
                        continue;
                    }
                    else
                    {
                        switchmenue();
                        return 0;
                    }
                }
                else
                {
                    cout << "Record Not Found Try Again !" << endl;
                    int exit;
                    cout << "press 1 for Try Again else 2 for exit the program : ";
                    cin >> exit;
                    if (exit == 1)
                        continue;
                    else
                        return 0;
                }
            }
        }
    }
};
int main()
{
    // creating object of inheritance class
    studentsDirectory obj;
    // only Switch Menue in driver Function
    obj.switchmenue();
    return 0;
}