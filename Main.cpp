#include <iostream> // For cin and cout function
#include <iomanip> // For decimal manipulation
#include <stdlib.h> // For clear screen & exit
#include <cctype> // For checking STRING boolean
#include <sstream> // For converting STRING to INTEGER
#include <string> // For string length
#include <ctime> // For actual date
#include <vector> // For usage of vector
#define _WIN32_WINNT 0x0500 // For full screen
#include <windows.h> // For background and text colours
#include <fstream> // For file handling (export/import data from binary file)

using namespace std;

/*--------------------------------------Declaration of global variables-------------------------*/
string mainKey;
string empKey, adminKey;
string anyKey;
string cKey;
string indexKey;
string response;

//admin
string admin_username, admin_password;
int createdDay, createdMonth, createdYear;

//employee registration
string name;
string gender;
string dobDayStr, dobMonthStr, dobYearStr;
int dobDay, dobMonth, dobYear;
string ic;
string nationality;
string hpNo;
string address;
string dohDayStr, dohMonthStr, dohYearStr;
int dohDay, dohMonth, dohYear;
string jobTitle;
static int empCount;
string id;
string password;

//employee update
string newName;
string newGender;
string newDobDayStr, newDobMonthStr, newDobYearStr;
int newDobDay, newDobMonth, newDobYear;
string newIc;
string newNationality;
string newHpNo;
string newAddress;
string newDohDayStr, newDohMonthStr, newDohYearStr;
int newDohDay, newDohMonth, newDohYear;
string newJobTitle;
string newEmpCount;
string newId;
string newPassword;

//calculators
int nowDay, nowMonth, nowYear;
int doeMonth, doeYear;


/*--------------------------------------Boolean functions---------------------------------------*/
bool isLetters(string input)
{
    for (unsigned int i = 0;i < input.size();i++)
    {
        if (isalpha(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isNumbers(string input)
{
    for (unsigned int i = 0;i < input.size();i++)
    {
        if (isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isSpace(string input)
{
    for (unsigned int i = 0;i < input.size();i++)
    {
        if (isspace(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isPunct(string input)
{
    for (unsigned int i = 0;i < input.size();i++)
    {
        if (ispunct(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isCapital(string input)
{
    for (unsigned int i = 0;i < input.size();i++)
    {
        if (isupper(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isNonCapital(string input)
{
    for (unsigned int i = 0;i < input.size();i++)
    {
        if (islower(input[i]))
        {
            return true;
        }
    }
    return false;
}
/*---------------------------------------------Calculators---------------------*/

void validOfDateCal() {

    // current date/time based on current system
    time_t now = time(0);

    tm* ltm = localtime(&now);
    // various components of tm structure
    nowYear = 1900 + ltm->tm_year; //tm_year means years since 1900
    nowMonth = 1 + ltm->tm_mon; //tm_mon means months since January
    nowDay = ltm->tm_mday; //tm_mday means day of the month
}

void employmentDurationCal(int dohMonth, int dohYear){

    validOfDateCal();

    if (nowMonth >= dohMonth)
    {
        doeMonth = nowMonth - dohMonth;
        doeYear = nowYear - dohYear;
    }
    else /*(nowMonth < dohMonth)*/
    {
        doeMonth = (nowMonth + 12) - dohMonth;
        doeYear = (nowYear - 1) - dohYear;
    } return;
}

/*--------------------------------------Class------------------------------------------*/

class Employee {
private:
    string name;
    string gender;
    int dobDay, dobMonth, dobYear;
    string ic;
    string nationality;
    string hpNo;
    string address;
    int dohDay, dohMonth, dohYear;
    string jobTitle;
    int doeMonth, doeYear;
    int empCount;
    string id;
    string password;
    static string name_EOTM;
    static string id_EOTM;

public:
    Employee(){}

    Employee(string name, string gender, int dobDay, int dobMonth, int dobYear,
        string ic, string nationality, string hpNo, string address,
        int dohDay, int dohMonth, int dohYear, string jobTitle, int empCount,
        string id, string password)
    {

        this->name = name;
        this->gender = gender;
        this->dobDay = dobDay;
        this->dobMonth = dobMonth;
        this->dobYear = dobYear;
        this->ic = ic;
        this->nationality = nationality;
        this->hpNo = hpNo;
        this->address = address;
        this->dohDay = dohDay;
        this->dohMonth = dohMonth;
        this->dohYear = dohYear;
        this->jobTitle = jobTitle;
        this->empCount = empCount;
        this->id = id;
        this->password = password;
    }


    static void updateName_EOTM (string set_name)
    {
        name_EOTM = set_name;
    }

    static void updateId_EOTM (string set_id)
    {
        id_EOTM = set_id;
    }

    void updateName(string name)
    {
        this->name = name;
    }

    void updateGender(string gender)
    {
        this->gender = gender;
    }

    void updateDob(int dobDay, int dobMonth, int dobYear)
    {
        this->dobDay = dobDay;
        this->dobMonth = dobMonth;
        this->dobYear = dobYear;
    }

    void updateIc(string ic)
    {
        this->ic = ic;
    }

    void updateNationality(string nationality)
    {
        this->nationality = nationality;
    }

    void updateHpNo(string hpNo)
    {
        this->hpNo = hpNo;
    }

    void updateAddress(string address)
    {
        this->address = address;
    }

    void updateDoh(int dohDay, int dohMonth, int dohYear)
    {
        this->dohDay = dohDay;
        this->dohMonth = dohMonth;
        this->dohYear = dohYear;
    }

    void updateJobTitle(string jobTitle)
    {
        this->jobTitle = jobTitle;

    }

    void updateId(string id)
    {
        this->id = id;
    }

    void updatePassword(string password)
    {
        this->password = password;
    }

    static string getName_EOTM ()
    {
        return name_EOTM;
    }

    static string getId_EOTM ()
    {
        return id_EOTM;
    }

    string getName() const
    {
        return name;
    }

    string getGender() const
    {
        return gender;
    }

    int getDobDay() const
    {
        return dobDay;
    }

    int getDobMonth() const
    {
        return dobMonth;
    }

    int getDobYear() const
    {
        return dobYear;
    }

    string getIc() const
    {
        return ic;
    }

    string getNationality() const
    {
        return nationality;
    }

    string getHpNo() const
    {
        return hpNo;
    }

    string getAddress() const
    {
        return address;
    }

    int getDohDay() const
    {
        return dohDay;
    }

    int getDohMonth() const
    {
        return dohMonth;
    }

    int getDohYear() const
    {
        return dohYear;
    }

    string getJobTitle() const
    {
        return jobTitle;
    }


    int getEmpCount() const
    {
        return empCount;
    }

    string getId() const
    {
        return id;
    }

    string getPassword() const
    {
        return password;
    }
};
//set static values to null
string Employee :: name_EOTM = "";
string Employee :: id_EOTM = "";

class Admin
{
private:
    string admin_username, admin_password;
    int createdDay, createdMonth, createdYear;

public:
    Admin(string admin_username, string admin_password, int createdDay, int createdMonth , int createdYear)
    {
        this->admin_username = admin_username;
        this->admin_password = admin_password;
        this->createdDay = createdDay;
        this->createdMonth = createdMonth;
        this->createdYear = createdYear;
    }

    string getAdminUsername() const
    {
        return admin_username;
    }

    string getAdminPassword() const
    {
        return admin_password;
    }

    int getCreatedDay() const
    {
        return createdDay;
    }

    int getCreatedMonth() const
    {
        return createdMonth;
    }

    int getCreatedYear() const
    {
        return createdYear;
    }
};

/*---------------------------------------Declaration of vectors----------------------------------------*/
vector <Employee> empRecord;
vector <Admin> admin_list;

/*----------------------------------------Fill vectors functions-------------------------------------------*/
void fillEmpRecord(vector <Employee>& newEmpRecord) {
    Employee newEmp(name, gender, dobDay, dobMonth, dobYear,
                    ic, nationality, hpNo, address,
                    dohDay, dohMonth, dohYear,
                    jobTitle, empCount, id, password);
    newEmpRecord.push_back(newEmp);
}

void fillAdminList (vector <Admin>& newAdmin_list)
{
    time_t t= time(NULL);
    tm *tPtr = localtime(&t);
    createdDay = tPtr->tm_mday;
    createdMonth = (tPtr->tm_mon)+1;
    createdYear = (tPtr->tm_year)+1900;
    Admin new_acc(admin_username, admin_password, createdDay, createdMonth, createdYear);
    newAdmin_list.push_back(new_acc);
}

/*----------------------------------------------Auto Generator-----------------------------------------------*/
static void getEmpCount(char action) {
    if (action == '+') {
        empCount++;
    }
    else
    {
        empCount--;
    } return;
}

string idGenerator (string gender, int dohDay, int dohMonth, int empCount){
    stringstream output, dohDaySen, dohMonthSen ;
    string dohDayStr, dohMonthStr;
    string generatedId;

    if (dohDay < 10)
    {
        dohDaySen << "0" << dohDay ;
    }
    else
    {
        dohDaySen << dohDay;
    }

    if (dohMonth < 10)
    {
        dohMonthSen << "0" << dohMonth;
    }
    else
    {
        dohMonthSen << dohMonth;
    }

    dohDayStr = dohDaySen.str();
    dohMonthStr = dohMonthSen.str();

    if (gender == "MALE")
    {
        output << "M" << dohDayStr << dohMonthStr << "-" << empCount ;
    }
    else /*(gender == "FEMALE)*/
    {
        output << "F" << dohDayStr << dohMonthStr  << "-" << empCount ;
    }
    generatedId = output.str();
    return generatedId;
}

int getIndex_empRecord(vector<Employee>& newEmpRecord, string id_getIndex)
{
    for(int i=0 ; i<newEmpRecord.size() ; i++)
    {
        if (id_getIndex == newEmpRecord[i].getId()){
            return i;
        }
    }
}

int getIndex_adminList(vector<Admin>& newAdmin_list, string username_getIndex)
{
    for(int i=0 ; i<newAdmin_list.size() ; i++)
    {
        if (username_getIndex == newAdmin_list[i].getAdminUsername()){
            return i;
        }
    }
}

/*--------------------------------Bool Check for employee & admin-------------------------------------*/
bool uniqueAdminUsernameCheck (string username_check, const vector <Admin>& newAdmin_list)
{
    for (unsigned int i=0 ; i<newAdmin_list.size() ; i++)
    {
        if (username_check == newAdmin_list[i].getAdminUsername())
        {
            return false;
        }
    } return true;
}

bool uniqueIcCheck (string ic, const vector <Employee>& newEmpRecord)
{
    for (unsigned int i=0 ; i<newEmpRecord.size() ; i++)
    {
        if (ic == newEmpRecord[i].getIc())
        {
            return false;
        }
    } return true;
}

bool employee_idPassword_Check (string id, string password, const vector <Employee>& newEmpRecord)
{
    for (unsigned int i=0 ; i<newEmpRecord.size() ; i++)
    {
        if (id == newEmpRecord[i].getId() && password == newEmpRecord[i].getPassword())
        {
            return true;
        }
    } return false;
}

bool admin_idPassword_Check(const vector <Admin>& newAdmin_list, string admin_username, string admin_password)
{
    for (unsigned int i = 0; i < admin_list.size(); i++)
    {
        if (admin_username == newAdmin_list[i].getAdminUsername() && admin_password == newAdmin_list[i].getAdminPassword())
        {
                return true;
        }
    } return false;
}

bool employee_idCheck (const vector <Employee>& newEmpRecord, string id)
{
    for (unsigned int i = 0; i < empRecord.size(); i++)
    {
        if (id == newEmpRecord[i].getId())
        {
                return true;
        }
    } return false;
}

/*------------------------------------Functions--------------------------------------------------------------*/

const void printAdminList (const vector <Admin>& newAdmin_list)
{
    cout<<"\n\n\n\t\t\t              No        Date created        Admin username"<<endl;
    for(unsigned int i = 0; i < newAdmin_list.size(); i++)
    {
        cout<<"\t\t\t              "<<i+1<<"          "<<newAdmin_list[i].getCreatedDay()<<"/"<<newAdmin_list[i].getCreatedMonth()<<"/"<<newAdmin_list[i].getCreatedYear()<<"            "<<newAdmin_list[i].getAdminUsername()<<endl;
    } return;
}

const void printEmployeeList (const vector <Employee>& newEmpRecord, vector <int>& vector_index)
{
    cout<<"\n\t\t\t             No      Employee id      Employee Name      Job Title"<<endl;
    for(unsigned int i = 0; i < vector_index.size(); i++)
    {
        cout<<"\t\t\t             "<<i+1<<"       "<<newEmpRecord[vector_index[i]].getId()<<"          "<<newEmpRecord[vector_index[i]].getName()<<endl;
    } return;
}

const void printEmployeeList (const vector <Employee>& newEmpRecord)
{
    cout<<"\n\t\t\t             No      Employee ID      Employee Name"<<endl;
    for(unsigned int i = 0; i < empRecord.size(); i++)
    {
        cout<<"\t\t\t             "<<i+1<<"       "<<newEmpRecord[i].getId()<<"          "<<newEmpRecord[i].getName()<<endl;
    } return;
}

const void printViewEmpRecord(vector <Employee>& newEmpRecord, int empIndex ,string displayVar)
{
    system("CLS");
    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "          View "<< displayVar <<" Record           " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

    cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

    cout << "\n\n\n\t\t\t             Name                : " << newEmpRecord[empIndex].getName() << endl;
    cout << "\t\t\t             Gender              : " << newEmpRecord[empIndex].getGender() << endl;
    cout << "\t\t\t             Date of birth       : " << newEmpRecord[empIndex].getDobDay() << "/" << newEmpRecord[empIndex].getDobMonth() << "/" << newEmpRecord[empIndex].getDobYear() << endl;
    cout << "\t\t\t             Identity card number: " << newEmpRecord[empIndex].getIc() << endl;
    cout << "\t\t\t             Nationality         : " << newEmpRecord[empIndex].getNationality() << endl;
    cout << "\t\t\t             Telephone number    : " << newEmpRecord[empIndex].getHpNo() << endl;
    cout << "\t\t\t             Address             : " << newEmpRecord[empIndex].getAddress() << endl;
    cout << "\t\t\t             Date of hire        : " << newEmpRecord[empIndex].getDohDay() << "/" << newEmpRecord[empIndex].getDohMonth() << "/" << newEmpRecord[empIndex].getDohYear() << endl;
    cout << "\t\t\t             Job title           : " << newEmpRecord[empIndex].getJobTitle() << endl;

    return;
}

const void printUpdateEmpRecord (vector <Employee>& newEmpRecord, int empIndex, string displayVar)
{
    system("CLS");
    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

    cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

    cout << "\n\n\n\t\t\t             [1]  Name                : " << newEmpRecord[empIndex].getName() << endl;
    cout << "\t\t\t             [2]  Gender              : " << newEmpRecord[empIndex].getGender() << endl;
    cout << "\t\t\t             [3]  Date of birth       : " << newEmpRecord[empIndex].getDobDay() << "/" << newEmpRecord[empIndex].getDobMonth() << "/" << newEmpRecord[empIndex].getDobYear() << endl;
    cout << "\t\t\t             [4]  Identity card number: " << newEmpRecord[empIndex].getIc() << endl;
    cout << "\t\t\t             [5]  Nationality         : " << newEmpRecord[empIndex].getNationality() << endl;
    cout << "\t\t\t             [6]  Telephone number    : " << newEmpRecord[empIndex].getHpNo() << endl;
    cout << "\t\t\t             [7]  Address             : " << newEmpRecord[empIndex].getAddress() << endl;
    cout << "\t\t\t             [8]  Date of hire        : " << newEmpRecord[empIndex].getDohDay() << "/" << newEmpRecord[empIndex].getDohMonth() << "/" << newEmpRecord[empIndex].getDohYear() << endl;
    cout << "\t\t\t             [9]  Job title           : " << newEmpRecord[empIndex].getJobTitle() << endl;

    return;
}

// Employee registration --------------------------------------------------------------------------------------------------------------------------------------------------------------

void nameReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Name                      : ";
        getline(cin, name);

        if (isLetters(name) && !isNumbers(name) && !isPunct(name) && name.size() > 0 && name.size() < 51)
        {
            for (unsigned int i = 0; i < name.length(); i++)
            {
                name[i] = toupper(name[i]);
            }
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only letters." << endl;
            cout << "\t\t\t\t       Name must be between 0 and 51 characters." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter name." << endl;
            cout << "\t\t\t\t       ";

            getline(cin, anyKey);
        }
    } while (true);
}

void genderReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : ";
        getline(cin, gender);

        for (unsigned int i = 0; i < gender.length(); i++)
        {
            gender[i] = toupper(gender[i]);
        }

        if (isLetters(gender) && !isNumbers(gender) && !isPunct(gender) && !isSpace(gender))
        {

            if (gender == "MALE" | gender == "FEMALE")
            {
                return;
            }
            else
            {
                cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                cout << "\t\t\t\t       Enter only 'Male' OR 'Female'." << endl;
                cout << "\t\t\t\t       Name must be between 0 and 51 characters." << endl;
                cout << "\t\t\t\t       Enter any key to re-enter gender." << endl;
                cout << "\t\t\t\t        ";
                getline(cin, anyKey);
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only 'Male' OR 'Female'." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter gender." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);

        }
    } while (true);
}

void dobReset()
{
dobMain:
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;


        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : ";
        getline(cin, dobDayStr);
        cout << "\t\t\t                             -Month(MM)  : ";
        getline(cin, dobMonthStr);
        cout << "\t\t\t                             -Year (YYYY): ";
        getline(cin, dobYearStr);

        if (!isLetters(dobDayStr) && isNumbers(dobDayStr) && !isPunct(dobDayStr) && !isSpace(dobDayStr) &&
            !isLetters(dobMonthStr) && isNumbers(dobMonthStr) && !isPunct(dobMonthStr) && !isSpace(dobMonthStr) &&
            !isLetters(dobYearStr) && isNumbers(dobYearStr) && !isPunct(dobYearStr) && !isSpace(dobYearStr))
        {
            stringstream(dobDayStr) >> dobDay;
            stringstream(dobMonthStr) >> dobMonth;
            stringstream(dobYearStr) >> dobYear;

            validOfDateCal();

            if (dobDay >= 1 && dobDay <= 31 && dobMonth >= 1 && dobMonth <= 12 && dobYear >= 1000 && dobYear <= 9999
                && dobYear <= (nowYear - 14) && dobYear >= (nowYear - 80) )
            {
                if ((dobDay == 31) && (dobMonth == 4 || dobMonth == 6 || dobMonth == 9 || dobMonth == 11))
                {
                    string monthName;

                    if (dobMonth == 4)
                    {
                        monthName = "April";
                    }
                    else if (dobMonth == 6)
                    {
                        monthName = "June";
                    }
                    else if (dobMonth == 9)
                    {
                        monthName = "September";
                    }
                    else /*(dobMonth == 11)*/
                    {
                        monthName = "November";
                    }
                    cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                    cout << "\t\t\t\t       There's no 31st in " << monthName << "." << endl;
                    cout << "\t\t\t\t       Enter any key to re-enter date of birth." << endl;
                    cout << "\t\t\t\t        ";
                    getline(cin, anyKey);

                    goto  dobMain;
                }

                int x = dobYear % 4;

                if ((x != 0) && (dobDay >= 29 && dobMonth == 2))
                {
                    cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                    cout << "\t\t\t\t       There's no 29th or above in February " << dobYear << "." << endl;
                    cout << "\t\t\t\t       Enter any key to re-enter date of birth." << endl;
                    cout << "\t\t\t\t        ";
                    getline(cin, anyKey);

                    goto dobMain;
                }

                if (dobDay > 29 && dobMonth == 2)
                {
                    cout << "\n\n\t\t\t\t       Invalid input." << endl;
                    cout << "\t\t\t\t       There's no 30th and 31st in February." << endl;
                    cout << "\t\t\t\t       Enter any key to re-enter date of birth." << endl;
                    cout << "\t\t\t\t       ";
                    getline(cin, anyKey);

                    goto dobMain;
                }
                return;
            }
            else
            {
                cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                cout << "\t\t\t\t       Please enter a valid date." << endl;
                cout << "\t\t\t\t       Employee must be 14 years old or older." << endl;
                cout << "\t\t\t\t       Maximum age is 80." << endl;
                cout << "\t\t\t\t       Enter any key to re-enter date of birth." << endl;
                cout << "\t\t\t\t       ";
                getline(cin, anyKey);

                goto dobMain;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only numbers." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter date of birth." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);

            goto dobMain;
        }
    } while (true);
}

void icReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

        cout << "\t\t\t               Identity Card Number      : ";
        getline(cin, ic);

        if (isNumbers(ic) && !isPunct(ic) && !isSpace(ic) && ic.size()>5 && ic.size()<19)
        {
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter a minimum of 6 and maximum of 18 characters without spacing and punctuation." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter identity card number." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);
        }
    } while (true);
}

void nationalityReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

        cout << "\t\t\t               Identity Card Number      : " << ic << endl;

        cout << "\t\t\t               Nationality               : ";
        getline(cin, nationality);

        if (isLetters(nationality) && !isNumbers(nationality) && !isPunct(nationality) && nationality.size() > 0 && nationality.size() < 51)
        {
            for (unsigned int i = 0; i < nationality.length(); i++)
            {
                nationality[i] = toupper(nationality[i]);
            }
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only letters without punctuation." << endl;
            cout << "\t\t\t\t       Nationality must be between 0 and 51 characters." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter nationality." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);
        }
    } while (true);
}

void hpNoReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

        cout << "\t\t\t               Identity Card Number      : " << ic << endl;

        cout << "\t\t\t               Nationality               : " << nationality << endl;

        cout << "\t\t\t               Telephone number          : ";
        getline(cin, hpNo);


        if (!isLetters(hpNo) && isNumbers(hpNo) && !isPunct(hpNo) && !isSpace(hpNo) && hpNo.size() > 5 && hpNo.size() < 16)
        {
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only numbers without spacing and punctuation." << endl;
            cout << "\t\t\t\t       Telephone number must be minimum 5 and maximum 16 numbers long." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter telephone number." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);
        }
    } while (true);
}



void addressReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

        cout << "\t\t\t               Identity Card Number      : " << ic << endl;

        cout << "\t\t\t               Nationality               : " << nationality << endl;

        cout << "\t\t\t               Telephone number          : " << hpNo << endl;

        cout << "\t\t\t               Address                   : ";
        getline(cin, address);

        if (isLetters(address) && isNumbers(address) && address.size() > 0)
        {
            for (unsigned int i = 0; i < address.length(); i++)
            {
                address[i] = toupper(address[i]);
            }
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter a valid address with at least 1 number and 1 letter." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter address." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);
        }
    } while (true);
}

void dohReset()
{
dohMain:
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;


        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

        cout << "\t\t\t               Identity Card Number      : " << ic << endl;

        cout << "\t\t\t               Nationality               : " << nationality << endl;

        cout << "\t\t\t               Telephone number          : " << hpNo << endl;

        cout << "\t\t\t               Address                   : " << address << endl;

        cout << "\t\t\t               Date of hire -Day  (DD)   : ";
        getline(cin, dohDayStr);

        cout << "\t\t\t                            -Month(MM)   : ";
        getline(cin, dohMonthStr);

        cout << "\t\t\t                            -Year (YYYY) : ";
        getline(cin, dohYearStr);


        if (!isLetters(dohDayStr) && isNumbers(dohDayStr) && !isPunct(dohDayStr) && !isSpace(dohDayStr) &&
            !isLetters(dohMonthStr) && isNumbers(dohMonthStr) && !isPunct(dohMonthStr) && !isSpace(dohMonthStr) &&
            !isLetters(dohYearStr) && isNumbers(dohYearStr) && !isPunct(dohYearStr) && !isSpace(dohYearStr))
        {
            stringstream(dohDayStr) >> dohDay;
            stringstream(dohMonthStr) >> dohMonth;
            stringstream(dohYearStr) >> dohYear;

            if (dohDay >= 1 && dohDay <= 31 && dohMonth >= 1 && dohMonth <= 12 && dohYear >= (dobYear + 14))
            {
                if (dohYear > nowYear)
                {
                    cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                    cout << "\t\t\t\t       Hire date cannot be later than today." << endl;
                    cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                    cout << "\t\t\t\t       ";
                    getline(cin, anyKey);

                    goto dohMain;


                }
                else if (dohYear == nowYear)
                {
                    if (dohMonth > nowMonth)
                    {
                        cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                        cout << "\t\t\t\t       Hire date cannot be later than today." << endl;
                        cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                        cout << "\t\t\t\t       ";
                        getline(cin, anyKey);

                        goto dohMain;
                    }
                    else if (dohMonth == nowMonth)
                    {
                        if (dohDay > nowDay)
                        {
                            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                            cout << "\t\t\t\t       Hire date cannot be later than today." << endl;
                            cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                            cout << "\t\t\t\t       ";
                            getline(cin, anyKey);

                            goto dohMain;
                        }
                        else if (dohDay == nowDay){
                            goto dohCheck2;
                        }

                    }
                }
                else /*(dohYear < nowYear)*/
                {
                    goto dohCheck2;
                }

                dohCheck2:

                    if ((dohDay == 31) && (dohMonth == 4 || dohMonth == 6 || dohMonth == 9 || dohMonth == 11))
                    {
                        string monthName;

                        if (dohMonth == 4)
                        {
                            monthName = "April";
                        }
                        else if (dohMonth == 6)
                        {
                            monthName = "June";
                        }
                        else if (dohMonth == 9)
                        {
                            monthName = "September";
                        }
                        else/*(dohMonth == 11)*/
                        {
                            monthName = "November";
                        }
                        cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                        cout << "\t\t\t\t       There's no 31st in " << monthName << "." << endl;
                        cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                        cout << "\t\t\t\t       ";
                        getline(cin, anyKey);

                        goto dohMain;
                    }

                    int x = dohYear % 4;

                    if ((x != 0) && (dohDay >= 29 && dohMonth == 2))
                    {
                        cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                        cout << "\t\t\t\t       There's no 29th or above in February " << dohYear << "." << endl;
                        cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                        cout << "\t\t\t\t       ";
                        getline(cin, anyKey);

                        goto dohMain;
                    }

                    if (dohDay > 29 && dohMonth == 2)
                    {
                        cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                        cout << "\t\t\t\t       There's no 30th and 31st in February." << endl;
                        cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                        cout << "\t\t\t\t       ";
                        getline(cin, anyKey);

                        goto dohMain;
                    }


                return;
            }
            else
            {
                cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                cout << "\t\t\t\t       Please enter a valid date." << endl;
                cout << "\t\t\t\t       Employee must be at least 14 years old to be hired." << endl;
                cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                cout << "\t\t\t\t       ";
                getline(cin, anyKey);

                goto dohMain;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only numbers." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);

            goto dohMain;
        }
    } while (true);
}

void jobTitleReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;


        cout << "\t\t\t               Name                      : " << name << endl;

        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

        cout << "\t\t\t               Identity Card Number      : " << ic << endl;

        cout << "\t\t\t               Nationality               : " << nationality << endl;

        cout << "\t\t\t               Telephone number          : " << hpNo << endl;

        cout << "\t\t\t               Address                   : " << address << endl;

        cout << "\t\t\t               Date of hire -Day  (DD)   : " << dohDay << endl;

        cout << "\t\t\t                            -Month(MM)   : " << dohMonth << endl;

        cout << "\t\t\t                            -Year (YYYY) : " << dohYear << endl;

        cout << "\t\t\t               Job title                 : ";
        getline(cin, jobTitle);

        if (isLetters(jobTitle) && !isNumbers(jobTitle) && !isPunct(jobTitle) && name.size() > 0 && name.size() < 51)
        {
            for (unsigned int i = 0; i < jobTitle.length(); i++)
            {
                jobTitle[i] = toupper(jobTitle[i]);
            }
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
            cout << "\t\t\t\t       Enter only letters." << endl;
            cout << "\t\t\t\t       Enter at least 1 character and maximum of 50 characters." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);

        }
    }while (true);
}

// change password ----------------------------------------------------------------------------------------------------------------------

void passwordReset()
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

        cout << "\t\t\t               Employee ID              : " << id << endl;

        cout << "\n\t\t\t               Enter desired password   : ";
        getline(cin, password);

        if (isLetters(password) && isNumbers(password) && isCapital(password) && isNonCapital(password) && isPunct(password)
            && password.size() > 7 && password.size() < 21 )
        {
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Invalid input.";
            cout << "\n\t\t\t\t       The following conditions must be satisfied to create a password:";
            cout << "\n\t\t\t\t       1. Minimum of 8 characters and maximum of 20 characters.";
            cout << "\n\t\t\t\t       2. Must contain at least 1 uppercase letter.";
            cout << "\n\t\t\t\t       3. Must contain at least 1 lowercase letter.";
            cout << "\n\t\t\t\t       4. Must contain at least 1 number.";
            cout << "\n\t\t\t\t       5. Must contain at least 1 punctuation.";
            cout << "\n\t\t\t\t       Enter any key to re-enter desired password." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);
        }
    } while (true);
}

void changePersonalPassword(vector <Employee>& newEmpRecord, int empIndex){
    changePersonalPasswordMain:
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "          Change Login Password          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t\t       Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t\t       Current password: " ;
        getline(cin, password);

        if (employee_idPassword_Check(empRecord[empIndex].getId(), password, empRecord))
        {
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t       Incorrect current password." << endl;
            cout << "\t\t\t\t       Enter any key to re-enter current password." << endl;
            cout << "\t\t\t\t       ";
            getline(cin, anyKey);

            goto changePersonalPasswordMain;
        }
}

// update employee -------------------------------------------------------------------------------------------------------------------------------------------

void upEmpName(vector <Employee>& newEmpRecord, int empIndex ,string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current name: " << empRecord[empIndex].getName() << endl;
        cout << "\t\t\t             New name    : ";
        getline(cin, newName);

        if (isLetters(newName) && !isNumbers(newName) && !isPunct(newName) && newName.size() > 0 && newName.size() < 51)
        {
            for (unsigned int i = 0; i < newName.length(); i++) {
                newName[i] = toupper(newName[i]);
            } return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter only letters." << endl;
            cout << "\t\t\t\t     Name must be between 0 and 51 characters." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new name." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);

        }
    } while (true);
}

void upEmpGender(vector <Employee>& newEmpRecord, int empIndex ,string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current gender: " << empRecord[empIndex].getGender() << endl;
        cout << "\t\t\t             New gender    : ";
        getline(cin, newGender);

        for (unsigned int i = 0; i < newGender.length(); i++)
        {
            newGender[i] = toupper(newGender[i]);
        }
        if (isLetters(newGender) && !isNumbers(newGender) && !isPunct(newGender) && !isSpace(newGender))
        {
            if (newGender == "MALE" || newGender == "FEMALE")
            {
                return;
            }
            else
            {
                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                cout << "\t\t\t\t     Enter only 'Male' OR 'Female'." << endl;
                cout << "\t\t\t\t     Enter any key to re-enter new gender." << endl;
                cout << "\t\t\t\t     ";
                getline(cin, anyKey);
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter only 'Male' OR 'Female'." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new gender." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);
        }
    } while (true);
}

void upEmpDob(vector <Employee>& newEmpRecord, int empIndex ,string displayVar)
{
    int funcDobDay, funcDobMonth, funcDobYear;
upDobMain:
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current date of birth -Day   (DD)  : " << empRecord[empIndex].getDobDay() << endl;
        cout << "\t\t\t                                   -Month (MM)  : " << empRecord[empIndex].getDobMonth() << endl;
        cout << "\t\t\t                                   -Year  (YYYY): " << empRecord[empIndex].getDobYear() << endl;

        cout << "\n\t\t\t             New date of birth     -Day   (DD)  : ";
        getline(cin, newDobDayStr);
        cout << "\t\t\t                                   -Month (MM)  : ";
        getline(cin, newDobMonthStr);
        cout << "\t\t\t                                   -Year  (YYYY): ";
        getline(cin, newDobYearStr);

        if (!isLetters(newDobDayStr) && isNumbers(newDobDayStr) && !isPunct(newDobDayStr) && !isSpace(newDobDayStr) &&
            !isLetters(newDobMonthStr) && isNumbers(newDobMonthStr) && !isPunct(newDobMonthStr) && !isSpace(newDobMonthStr) &&
            !isLetters(newDobYearStr) && isNumbers(newDobYearStr) && !isPunct(newDobYearStr) && !isSpace(newDobYearStr))
        {
            stringstream(newDobDayStr) >> funcDobDay;
            stringstream(newDobMonthStr) >> funcDobMonth;
            stringstream(newDobYearStr) >> funcDobYear;

            validOfDateCal();

            if (funcDobDay >= 1 && funcDobDay <= 31 && funcDobMonth >= 1 && funcDobMonth <= 12 && funcDobYear >= 1000 && funcDobYear <= 9999
                && funcDobYear <= (nowYear - 14) && funcDobYear >= (nowYear - 80))
            {
                if ((funcDobDay == 31) && (funcDobMonth == 4 || funcDobMonth == 6 || funcDobMonth == 9 || funcDobMonth == 11))
                {
                    string monthName;

                    if (funcDobMonth == 4)
                    {
                        monthName = "April";
                    }
                    else if (funcDobMonth == 6)
                    {
                        monthName = "June";
                    }
                    else if (funcDobMonth == 9)
                    {
                        monthName = "September";
                    }
                    else /*(funcDobMonth == 11)*/
                    {
                        monthName = "November";
                    }
                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                    cout << "\t\t\t\t     There's no 31st in " << monthName << "." << endl;
                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                    cout << "\t\t\t\t     ";
                    getline(cin, anyKey);

                    goto  upDobMain;
                }
                int x = funcDobYear % 4;

                if ((x != 0) && (funcDobDay >= 29 && funcDobMonth == 2))
                {
                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                    cout << "\t\t\t\t     There's no 29th or above in February " << funcDobYear << "." << endl;
                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                    cout << "\t\t\t\t     ";
                    getline(cin, anyKey);

                    goto upDobMain;
                }
                if (funcDobDay > 29 && funcDobMonth == 2)
                {
                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                    cout << "\t\t\t\t     There's no 30th and 31st in February." << endl;
                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                    cout << "\t\t\t\t     ";
                    getline(cin, anyKey);

                    goto upDobMain;
                }
                newDobDay = funcDobDay;
                newDobMonth = funcDobMonth;
                newDobYear = funcDobYear;
                return;
            }
            else
            {
                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                cout << "\t\t\t\t     Please enter a valid date." << endl;
                cout << "\t\t\t\t     Employee must be 14 years old or older." << endl;
                cout << "\t\t\t\t     Maximum age is 80." << endl;
                cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                cout << "\t\t\t\t     ";
                getline(cin, anyKey);

                goto upDobMain;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter only numbers." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);

            goto upDobMain;
        }
    } while (true);
}

void upEmpIc(vector <Employee>& newEmpRecord, int empIndex, string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current identity card number: " << empRecord[empIndex].getIc() << endl;
        cout << "\t\t\t             New identity card number    : ";
        getline(cin, newIc);

        if (isNumbers(newIc) && !isPunct(newIc) && !isSpace(newIc) && newIc.size()>5 && newIc.size()<19)
        {
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter minimum 6 characters without spacing and punctuation." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new identity card number." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);
        }
    } while (true);
}

void upEmpNationality(vector <Employee>& newEmpRecord, int empIndex, string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current nationality: " << empRecord[empIndex].getNationality() << endl;
        cout << "\t\t\t             New nationality    : ";
        getline(cin, newNationality);

        if (isLetters(newNationality) && !isNumbers(newNationality) && !isPunct(newNationality) && newNationality.size() > 0 && newNationality.size() < 51)
        {
            for (unsigned int i = 0; i < newNationality.length(); i++)
            {
                newNationality[i] = toupper(newNationality[i]);
            }
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter only letters without punctuation." << endl;
            cout << "\t\t\t\t     Nationality must be between 0 and 51 characters." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new nationality." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);
        }
    } while (true);
}

void upEmpHpNo(vector <Employee>& newEmpRecord, int empIndex, string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current telephone number: " << empRecord[empIndex].getHpNo() << endl;
        cout << "\t\t\t             New telephone number    : ";
        getline(cin, newHpNo);

        if (!isLetters(newHpNo) && isNumbers(newHpNo) && !isPunct(newHpNo) && !isSpace(newHpNo) && newHpNo.size() > 5 && newHpNo.size() < 16)
        {
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter only numbers without spacing and punctuation." << endl;
            cout << "\t\t\t\t     Telephone number must be minimum 5 and maximum 16 numbers long." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new telephone number." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);
        }
    } while (true);
}

void upEmpAddress(vector <Employee>& newEmpRecord, int empIndex, string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current address: " << empRecord[empIndex].getAddress() << endl;
        cout << "\t\t\t             New address    : ";
        getline(cin, newAddress);

        if (isLetters(newAddress) && isNumbers(newAddress) && newAddress.size() > 0)
        {
            for (unsigned int i = 0; i < newAddress.length(); i++)
            {
                newAddress[i] = toupper(newAddress[i]);
            }
            return;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter address with at least 1 number and 1 letter." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new address." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);
        }
    } while (true);
}

void upEmpDoh(vector <Employee>& newEmpRecord, int empIndex, string displayVar) {
    int funcDohDay, funcDohMonth, funcDohYear;
upDohMain:
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current date of hire -Day  (DD)  : " << empRecord[empIndex].getDohDay() << endl;
        cout << "\t\t\t                                  -Month(MM)  : " << empRecord[empIndex].getDohMonth() << endl;
        cout << "\t\t\t                                  -Year (YYYY): " << empRecord[empIndex].getDohYear() << endl;

        cout << "\n\t\t\t             New date of hire     -Day  (DD)  : ";
        getline(cin, newDohDayStr);
        cout << "\t\t\t                                  -Month(MM)  : ";
        getline(cin, newDohMonthStr);
        cout << "\t\t\t                                  -Year (YYYY): ";
        getline(cin, newDohYearStr);

        validOfDateCal();

        if (!isLetters(newDohDayStr) && isNumbers(newDohDayStr) && !isPunct(newDohDayStr) && !isSpace(newDohDayStr) &&
            !isLetters(newDohMonthStr) && isNumbers(newDohMonthStr) && !isPunct(newDohMonthStr) && !isSpace(newDohMonthStr) &&
            !isLetters(newDohYearStr) && isNumbers(newDohYearStr) && !isPunct(newDohYearStr) && !isSpace(newDohYearStr))
        {
            stringstream(newDohDayStr) >> funcDohDay;
            stringstream(newDohMonthStr) >> funcDohMonth;
            stringstream(newDohYearStr) >> funcDohYear;

            if (funcDohDay >= 1 && funcDohDay <= 31 && funcDohMonth >= 1 && funcDohMonth <= 12 && funcDohYear >= (newDobYear + 14))
            {
                if (funcDohYear > nowYear)
                {
                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                    cout << "\t\t\t\t     Hire date cannot be later than today." << endl;
                    cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                    cout << "\t\t\t\t     ";
                    getline(cin, anyKey);

                    goto upDohMain;
                }
                else if (funcDohYear == nowYear)
                {
                    if (funcDohMonth > nowMonth)
                    {
                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                        cout << "\t\t\t\t     Hire date cannot be later than today." << endl;
                        cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                        cout << "\t\t\t\t     ";
                        getline(cin, anyKey);

                        goto upDohMain;
                    }
                    else if (funcDohMonth == nowMonth)
                    {
                        if (funcDohDay > nowDay)
                        {
                            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                            cout << "\t\t\t\t     Hire date cannot be later than today." << endl;
                            cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                            cout << "\t\t\t\t     ";
                            getline(cin, anyKey);

                            goto upDohMain;
                        }
                        else if (funcDohDay == nowDay){
                            goto dohCheck2;
                        }
                    }
                }
                else /*(funcDohYear < nowYear)*/
                {
                    goto dohCheck2;
                }

                dohCheck2:
                    if ((funcDohDay == 31) && (funcDohMonth == 4 || funcDohMonth == 6 || funcDohMonth == 9 || funcDohMonth == 11))
                    {
                        string monthName;

                        if (funcDohMonth == 4)
                        {
                            monthName = "April";
                        }
                        else if (funcDohMonth == 6)
                        {
                            monthName = "June";
                        }
                        else if (funcDohMonth == 9)
                        {
                            monthName = "September";
                        }
                        else/*(funcDohMonth == 11)*/
                        {
                            monthName = "November";
                        }
                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                        cout << "\t\t\t\t     There's no 31st in " << monthName << "." << endl;
                        cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                        cout << "\t\t\t\t     ";
                        getline(cin, anyKey);

                        goto  upDohMain;
                    }
                    int x = funcDohYear % 4;

                    if ((x != 0) && (funcDohDay >= 29 && funcDohMonth == 2))
                    {
                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                        cout << "\t\t\t\t     There's no 29th or above in February " << funcDohYear << "." << endl;
                        cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                        cout << "\t\t\t\t     ";
                        getline(cin, anyKey);

                        goto upDohMain;
                    }
                    if (funcDohDay > 29 && funcDohMonth == 2)
                    {
                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                        cout << "\t\t\t\t     There's no 30th and 31st in February." << endl;
                        cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                        cout << "\t\t\t\t     ";
                        getline(cin, anyKey);

                        goto upDohMain;
                    }



                    newDohDay = funcDohDay;
                    newDohMonth = funcDohMonth;
                    newDohYear = funcDohYear;
                    return;
            }
            else
            {
                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                cout << "\t\t\t\t     Please enter a valid date." << endl;
                cout << "\t\t\t\t     Employee must be at least 14 years old to be hire." << endl;
                cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
                cout << "\t\t\t\t     ";
                getline(cin, anyKey);

                goto upDohMain;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
            cout << "\t\t\t\t     Enter only numbers." << endl;
            cout << "\t\t\t\t     Enter any key to re-enter new date of hire." << endl;
            cout << "\t\t\t\t     ";
            getline(cin, anyKey);

            goto upDohMain;
        }
    } while (true);
}

void upEmpJobTitle (vector <Employee>& newEmpRecord, int empIndex, string displayVar)
{
    do {
        system("CLS");
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "         Update "<< displayVar <<" Record          " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\t\t\t             Employee ID: " << empRecord[empIndex].getId() << endl;

        cout << "\n\n\n\t\t\t             Current job title: " << empRecord[empIndex].getJobTitle() << endl;
        cout << "\t\t\t             New job title    : ";
        getline(cin, newJobTitle);

        if (isLetters(newJobTitle) && !isNumbers(newJobTitle) && !isPunct(newJobTitle) && newJobTitle.size() > 0 && newJobTitle.size() < 51)
        {
            for (unsigned int i = 0; i < newJobTitle.length(); i++)
            {
                newJobTitle[i] = toupper(newJobTitle[i]);
            }
            return;
        }
        else
        {
        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
        cout << "\t\t\t\t     Enter only letters." << endl;
        cout << "\t\t\t\t     Enter at least 1 character and maximum of 50 characters." << endl;
        cout << "\t\t\t\t     Enter any key to re-enter new job title." << endl;
        cout << "\t\t\t\t     ";
        getline(cin, anyKey);

        }
    }while (true);
}

// search function-----------------------------------------------------------------------------------------------
string printSearchResult_getAction(const vector <Employee>& newEmpRecord, vector <int>& vector_index, int &index_updateEmp, int &index_deleteEmp, string displayVar2)
{
     search_result:

        system("CLS");
        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             "<<char(186) <<               displayVar2                   << char(186) << endl;
        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;
        cout<<"\n\n\n\t\t\t             No      Employee ID      Employee Name"<<endl;
        for(unsigned int i = 0; i < vector_index.size(); i++)
        {
            cout<<"\t\t\t             "<<i+1<<"       "<<newEmpRecord[vector_index[i]].getId()<<"          "<<newEmpRecord[vector_index[i]].getName() << endl;
        }

        cout<<"\n\n\n\t\t\t             Enter '0' to go back to search employee record menu.";
        cout<<"\n\t\t\t             Enter index number for more details.";
        cout<<"\n\t\t\t             ";
        getline(cin, response);

        if (!isLetters(response) && isNumbers(response) && !isPunct(response) && !isSpace(response))
        {
             int index;
             stringstream (response) >> (index);
             if (index == 0)
             {
                 vector_index.clear();
                 return response;
             }
             else if (index > vector_index.size())
             {

                cout<<"\n\n\n\t\t\t             Invalid input.";
                cout<<"\n\t\t\t             Invalid index number.";
                cout<<"\n\t\t\t             Enter any key to re-enter index number.";
                cout<<"\n\t\t\t             ";
                getline(cin, response);

                goto search_result;
             }
             else
             {
                index--;
                int index_Record = vector_index[index];
                printViewEmpRecord(empRecord, index_Record, "Employee");

                cout<<"\n\n\n\t\t\t             Enter 'X' to go back the list.";
                cout<<"\n\t\t\t             Enter 'U' to update record.";
                cout<<"\n\t\t\t             Enter 'D' to delete record.";
                cout<<"\n\t\t\t             Enter any other key to go back to search employee record menu.";
                cout<<"\n\t\t\t             ";
                getline(cin, response);

                if (response == "x" || response == "X")
                {
                    goto search_result;
                }
                else
                {
                    index_deleteEmp = index_Record;
                    index_updateEmp = index_Record;
                    vector_index.clear();
                    return response;
                }
             }
        }
        else
        {
            cout<<"\n\n\n\t\t\t             Invalid input." << endl;
            cout << "\t\t\t             Enter only numbers." << endl;
            cout << "\t\t\t             Enter any key to retry." << endl;
            cout << "\t\t\t             ";
            getline(cin,anyKey);

            goto search_result;
        }
}

vector <int> searchById (const vector <Employee>& newEmpRecord, string id)
{
    vector <int> vector_index;
    for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
    {
        if (id == newEmpRecord[i].getId())
        {
            vector_index.push_back(i);
        }
    } return vector_index;
}

vector <int> searchByJobTitle (const vector <Employee>& newEmpRecord, string jobTitle)
{
    vector <int> vector_index;
    for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
    {
        if ((newEmpRecord[i].getJobTitle()).find(jobTitle) != string::npos)
        {
            vector_index.push_back(i);
        }
    } return vector_index;
}

vector <int> searchByName(const vector <Employee>& newEmpRecord, string name)
{
    vector <int> vector_index;
    for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
    {
        if ((newEmpRecord[i].getName()).find(name) != string::npos)
        {
            vector_index.push_back(i);
        }
    } return vector_index;
}

vector <int> searchByGender(const vector <Employee>& newEmpRecord, string gender)
{
    vector <int> vector_index;
    for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
    {
        if (gender == newEmpRecord[i].getGender())
        {
            vector_index.push_back(i);
        }
    } return vector_index;
}

vector <int> searchByDob(const vector <Employee>& newEmpRecord, int dobDay_search, int dobMonth_search, int dobYear_search, string range_search)
{
    vector <int> vector_index;

    if (range_search == "BEFORE")
    {
        for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
        {
            if (newEmpRecord[i].getDobYear() < dobYear_search)
            {
                vector_index.push_back(i);
            }
            else if (newEmpRecord[i].getDobYear() == dobYear_search)
            {
                if (newEmpRecord[i].getDobMonth() < dobMonth_search)
                {
                    vector_index.push_back(i);
                }
                else if (newEmpRecord[i].getDobMonth() == dobMonth_search)
                {
                    if (newEmpRecord[i].getDobDay() <= dobDay_search)
                    {
                        vector_index.push_back(i);
                    }
                    else
                    { // newEmpRecord[i].getDobDay() > day_search
                        //nothing happen
                    }
                }
                else
                { // newEmpRecord[i].getDobMonth() > month_search
                    //nothing happen
                }
            }
            else
            { // newEmpRecord[i].getDobYear() > year_search
                //nothing happen
            }
        }
        return vector_index;
    }
    //AFTER
    for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
    {
        if (newEmpRecord[i].getDobYear() > dobYear_search)
        {
            vector_index.push_back(i);
        }
        else if (newEmpRecord[i].getDobYear() == dobYear_search)
        {
            if (newEmpRecord[i].getDobMonth() > dobMonth_search)
            {
                vector_index.push_back(i);
            }
            else if (newEmpRecord[i].getDobMonth() == dobMonth_search)
            {
                if (newEmpRecord[i].getDobDay() >= dobDay_search)
                {
                    vector_index.push_back(i);
                }
                else
                { // newEmpRecord[i].getDobDay() > day_search
                    //nothing happen
                }
            }
            else
            { // newEmpRecord[i].getDobMonth() > month_search
                //nothing happen
            }

        }
        else
        { // newEmpRecord[i].getDobYear() > year_search
            //nothing happen
        }
    }return vector_index;
}

vector <int> searchByDoh(const vector <Employee>& newEmpRecord, int dohDay_search, int dohMonth_search, int dohYear_search, string range_search)
{
    vector <int> vector_index;

    if (range_search == "BEFORE")
    {
        for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
        {
            if (newEmpRecord[i].getDohYear() < dohYear_search)
            {
                vector_index.push_back(i);
            }
            else if (newEmpRecord[i].getDohYear() == dohYear_search)
            {
                if (newEmpRecord[i].getDohMonth() < dohMonth_search)
                {
                    vector_index.push_back(i);
                }
                else if (newEmpRecord[i].getDohMonth() == dohMonth_search)
                {
                    if (newEmpRecord[i].getDohDay() <= dohDay_search)
                    {
                        vector_index.push_back(i);
                    }
                    else
                    { // newEmpRecord[i].getDohDay() > day_search
                        //nothing happen
                    }
                }
                else
                { // newEmpRecord[i].getDohMonth() > month_search
                    //nothing happen
                }

            }
            else
            { // newEmpRecord[i].getDohYear() > year_search
                //nothing happen
            }
        }
        return vector_index;
    }
    //AFTER
    for (unsigned int i = 0 ; i < newEmpRecord.size() ; i++)
    {
        if (newEmpRecord[i].getDohYear() > dohYear_search)
        {
            vector_index.push_back(i);
        }
        else if (newEmpRecord[i].getDohYear() == dohYear_search)
        {
            if (newEmpRecord[i].getDohMonth() > dohMonth_search)
            {
                vector_index.push_back(i);
            }
            else if (newEmpRecord[i].getDohMonth() == dohMonth_search)
            {
                if (newEmpRecord[i].getDohDay() >= dohDay_search)
                {
                    vector_index.push_back(i);
                }
                else
                { // newEmpRecord[i].getDohDay() > day_search
                    //nothing happen
                }
            }
            else
            { // newEmpRecord[i].getDohMonth() > month_search
                //nothing happen
            }

        }
        else
        { // newEmpRecord[i].getDohYear() > year_search
            //nothing happen
        }
    }
    return vector_index;
}

void loadEmpRecord(string fileName,vector<Employee>& newEmpRecord)
{
	ifstream loadEmployee(fileName.c_str());
	if(!loadEmployee)
    {
		return;
	}
	else
    {
        string name;
        string gender;
        int dobDay, dobMonth, dobYear;
        string dobDayStr, dobMonthStr, dobYearStr;
        string ic;
        string nationality;
        string hpNo;
        string address;
        int dohDay, dohMonth, dohYear;
        string dohDayStr, dohMonthStr, dohYearStr;
        string jobTitle;
        int empCount;
        string empCountStr;
        string id;
        string password;
        string line;

        while(getline(loadEmployee,line))
        {
            stringstream ss(line);
            getline(ss,name,'<');
            getline(ss,gender,'<');
            getline(ss,dobDayStr,'<'); dobDay = stoi(dobDayStr);
            getline(ss,dobMonthStr,'<'); dobMonth = stoi(dobMonthStr);
            getline(ss,dobYearStr,'<'); dobYear = stoi(dobYearStr);
            getline(ss,ic,'<');
            getline(ss,nationality,'<');
            getline(ss,hpNo,'<');
            getline(ss,address,'<');
            getline(ss,dohDayStr,'<'); dohDay = stoi(dohDayStr);
            getline(ss,dohMonthStr,'<'); dohMonth = stoi(dohMonthStr);
            getline(ss,dohYearStr,'<'); dohYear = stoi(dohYearStr);
            getline(ss,jobTitle,'<');
            getline(ss,empCountStr,'<'); empCount = stoi(empCountStr);
            getline(ss,id,'<');
            getline(ss,password,'<');
            Employee newEmp(name, gender, dobDay, dobMonth, dobYear,
                    ic, nationality, hpNo, address,
                    dohDay, dohMonth, dohYear,
                    jobTitle, empCount, id, password);
            newEmpRecord.push_back(newEmp);
        }
	}
	loadEmployee.close();
	return;
}

void saveEmpRecord(string fileName,vector<Employee>& newEmpRecord)
{
    ofstream saveEmployee;
    saveEmployee.open(fileName.c_str(), ios::trunc);
    const char DELIMITER = '<';
    for (unsigned int i = 0 ; i < empRecord.size(); i++)
    {
        saveEmployee << empRecord[i].getName() << DELIMITER << empRecord[i].getGender() << DELIMITER
                   <<  empRecord[i].getDobDay() << DELIMITER << empRecord[i].getDobMonth() << DELIMITER << empRecord[i].getDobYear() << DELIMITER
                   << empRecord[i].getIc() << DELIMITER << empRecord[i].getNationality() << DELIMITER
                   << empRecord[i].getHpNo() << DELIMITER << empRecord[i].getAddress() << DELIMITER
                   <<  empRecord[i].getDohDay() << DELIMITER << empRecord[i].getDohMonth() << DELIMITER << empRecord[i].getDohYear() << DELIMITER
                   << empRecord[i].getJobTitle() << DELIMITER << empRecord[i].getEmpCount() << DELIMITER
                   << empRecord[i].getId() << DELIMITER << empRecord[i].getPassword() << DELIMITER
                   <<endl;
    }
    saveEmployee.close();
    return;
}

void loadAdminList(string fileName,vector<Admin>& newAdmin_list)
{
	ifstream loadAdmin(fileName.c_str());
	if(!loadAdmin)
    {
		return;
	}
	else
    {
        string admin_username;
        string admin_password;
        int createdDay, createdMonth, createdYear;
        string createdDayStr, createdMonthStr, createdYearStr;
        string line;
        while(getline(loadAdmin,line))
        {
            stringstream ss(line);
            getline(ss,admin_username,'<');
            getline(ss,admin_password,'<');
            getline(ss,createdDayStr,'<'); createdDay = stoi(createdDayStr);
            getline(ss,createdMonthStr,'<'); createdMonth = stoi(createdMonthStr);
            getline(ss,createdYearStr,'<'); createdYear = stoi(createdYearStr);
            Admin new_acc(admin_username, admin_password, createdDay, createdMonth, createdYear);
            newAdmin_list.push_back(new_acc);
        }
	}
	loadAdmin.close();
	return;
}

void saveAdminList(string fileName,vector<Admin>& newAdmin_list)
{
    ofstream saveAdmin;
    saveAdmin.open(fileName.c_str(), ios::trunc);
    const char DELIMITER = '<';
    for (unsigned int i = 0 ; i < newAdmin_list.size(); i++)
    {
        saveAdmin << newAdmin_list[i].getAdminUsername() << DELIMITER << newAdmin_list[i].getAdminPassword() << DELIMITER
                      << newAdmin_list[i].getCreatedDay() << DELIMITER << newAdmin_list[i].getCreatedMonth() << DELIMITER << newAdmin_list[i].getCreatedYear() << DELIMITER
                      <<endl;
    }
    saveAdmin.close();
    return;
}

void loadEOTM (string fileName, vector<Employee>& newEmpRecord)
{
    ifstream load_EOTM(fileName.c_str());
	if(!load_EOTM)
    {
		return;
	}
	else
    {
        string name_EOTM;
        string id_EOTM;
        string line;

        while(getline(load_EOTM,line))
        {
            stringstream ss(line);
            getline(ss,name_EOTM,'<');
            getline(ss,id_EOTM,'<');
            Employee::updateName_EOTM(name_EOTM);
            Employee::updateId_EOTM(id_EOTM);
        }
	}
	load_EOTM.close();
	return;
}

void saveEOTM(string fileName,vector<Employee>& newEmpRecord)
{
    ofstream save_EOTM;
    save_EOTM.open(fileName.c_str(), ios::trunc);
    const char DELIMITER = '<';
    save_EOTM << Employee::getName_EOTM() << DELIMITER << Employee::getId_EOTM() << DELIMITER
              << endl;
    save_EOTM.close();
    return;
}

int main()
{
    loadEmpRecord("temp_emp.txt", empRecord);
    loadAdminList("temp_admin.txt", admin_list);
    loadEOTM("temp_EOTM.txt", empRecord);

    if (admin_list.empty())
    {
        Admin default_acc ("ermsadmin", "admin123",9,9,2020);
        admin_list.push_back(default_acc);
    }

    if (empRecord.empty())
    {
        empCount = empRecord.size();
    }
    else
    {
        int x = empRecord.size() - 1;
        empCount = empRecord[x].getEmpCount();
    }

    do
    {
    main_menu:
        system("CLS");
        mainKey = "0";
        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "            Welcome to ERMS!!            " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

        cout << "\n\t\t\t\t              1. Admin Login          " << endl;
        cout << "\t\t\t\t              2. Employee Login       " << endl;
        cout << "\t\t\t\t              3. Employee Registration" << endl;
        cout << "\t\t\t\t              4. Exit                 " << endl;

        cout << "\n\t\t\t\t              Enter a number: ";
        getline(cin, mainKey);

        if (!isLetters(mainKey) && isNumbers(mainKey) && !isPunct(mainKey) && !isSpace(mainKey))
        {
            if (mainKey == "1")
            {
                int index_updateEmp, index_deleteEmp, index_listEmp;
                admin_login:

                    system ("CLS");
                    cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             "<<char(186) << "               Admin login               " << char(186) << endl;
                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                    cout<<"\n\n\n\t\t\t             Enter username: ";
                    getline(cin, admin_username);

                    if(isPunct(admin_username) && isSpace(admin_username))
                    {
                        string response_adminLogin;
                        cout<<"\n\n\n\t\t\t             Invalid input.";
                        cout<<"\n\t\t\t             No spaces and punctuations are allowed.";
                        cout<<"\n\t\t\t             Enter any key to re-enter username.\n\t\t\t             Enter '0' to go back to main menu.";
                        cout<<"\n\t\t\t             ---> ";
                        getline(cin, response_adminLogin);

                        if(response_adminLogin == "0")
                        {
                            goto main_menu;
                        }
                        else
                        {
                            goto admin_login;
                        }
                    }
                    else
                    {
                        cout<<"\n\t\t\t             Enter password: ";
                        getline(cin, admin_password);

                        if (admin_idPassword_Check(admin_list,admin_username,admin_password))
                        {
                            string current_username = admin_username;
                            string current_password = admin_password;

                            admin_menu:
                                system ("CLS");
                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                cout << "\t\t\t             "<<char(186) << "               Admin Menu                " << char(186) << endl;
                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl << endl;

                                cout<<"\t\t\t\t          1. Update employee record" << endl;
                                cout<<"\t\t\t\t          2. Delete employee record" << endl;
                                cout<<"\t\t\t\t          3. List of employee records" << endl;
                                cout<<"\t\t\t\t          4. Search employee record" << endl;
                                cout<<"\t\t\t\t          5. Set/adjust employee of the month" << endl;
                                cout<<"\t\t\t\t          6. Create new admin account" << endl;
                                cout<<"\t\t\t\t          7. Delete admin account" << endl;
                                cout<<"\t\t\t\t          8. List of admin accounts" << endl;
                                cout<<"\t\t\t\t          9. Exit" << endl;

                                cout<<"\n\t\t\t\t          Enter a number: ";
                                getline(cin, adminKey);

                                if (adminKey == "1")
                                {
                                    update_emp:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "          Update Employee Record         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Enter employee ID: ";
                                        getline(cin, id);

                                    if (employee_idCheck(empRecord, id))
                                    {
                                        index_updateEmp = getIndex_empRecord (empRecord, id);
                                        update_emp_2:

                                            printUpdateEmpRecord(empRecord, index_updateEmp, "Employee");
                                            cout<<"\n\t\t\t             [0]  Exit " << endl;
                                            cout<<"\n\n\t\t\t             Enter an index number to update: ";
                                            string response_updateEmp;
                                            getline(cin, response_updateEmp);

                                        if (response_updateEmp == "1")
                                        {
                                            UpEmpName:
                                                upEmpName(empRecord, index_updateEmp, "Employee");

                                            if (newName == empRecord[index_updateEmp].getName())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New name must be different from current name." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new name." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto UpEmpName;
                                                }
                                            }
                                            else
                                            {
                                                UpEmpName2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current name: " << empRecord[index_updateEmp].getName() << endl;
                                                    cout << "\t\t\t             New name    : " << newName << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                    if (anyKey == "0")
                                                    {
                                                        goto update_emp_2;
                                                    }
                                                    else
                                                    {
                                                        empRecord[index_updateEmp].updateName(newName);

                                                        if (empRecord[index_updateEmp].getId() == Employee::getId_EOTM())
                                                        {
                                                            Employee::updateName_EOTM(newName);
                                                        }

                                                        system ("CLS");
                                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                        cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                        cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                        cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline (cin, anyKey);

                                                        goto update_emp_2;
                                                    }
                                                }
                                                else if (cKey == "N" | cKey == "n")
                                                {
                                                    goto UpEmpName;
                                                }
                                                else
                                                {
                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                    cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                    cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline(cin, anyKey);

                                                    goto UpEmpName2;
                                                }

                                            }

                                        }
                                        else if (response_updateEmp == "2")
                                        {
                                            UpEmpGender:
                                                upEmpGender(empRecord, index_updateEmp, "Employee");

                                            if (newGender == empRecord[index_updateEmp].getGender())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New gender must be different from current gender." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new gender." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t\t     ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0"){
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto UpEmpGender;
                                                }
                                            }
                                            else
                                            {
                                                UpEmpGender2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current gender: " << empRecord[index_updateEmp].getGender() << endl;
                                                    cout << "\t\t\t             New gender    : " << newGender << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Enter any key to proceed." << endl;
                                                        cout << "\t\t\t\t     Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateGender(newGender);
                                                            newDohDay = empRecord[index_updateEmp].getDohDay();
                                                            newDohMonth = empRecord[index_updateEmp].getDohMonth();
                                                            empCount = empRecord[index_updateEmp].getEmpCount();
                                                            newId = idGenerator(newGender, newDohDay, newDohMonth, empCount);
                                                            if (empRecord[index_updateEmp].getId() == Employee::getId_EOTM())
                                                            {
                                                                Employee::updateId_EOTM(newId);
                                                            }
                                                            empRecord[index_updateEmp].updateId(newId);

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n")
                                                    {
                                                        goto UpEmpGender;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto UpEmpGender2;
                                                    }

                                            }
                                        }
                                        else if (response_updateEmp == "3")
                                        {
                                            upEmpDob:
                                                upEmpDob(empRecord, index_updateEmp, "Employee");

                                            if (newDobDay == empRecord[index_updateEmp].getDobDay() && newDobMonth == empRecord[index_updateEmp].getDobMonth()
                                                && newDobYear == empRecord[index_updateEmp].getDobYear())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             Current date of birth must be different from current date of birth." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new date of birth." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto upEmpDob;
                                                }
                                            }
                                            else
                                            {
                                                upEmpDob2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: "<< empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current date of birth -Day   (DD)  : " << empRecord[index_updateEmp].getDobDay() << endl;
                                                    cout << "\t\t\t                                   -Month (MM)  : " << empRecord[index_updateEmp].getDobMonth() << endl;
                                                    cout << "\t\t\t                                   -Year  (YYYY): " << empRecord[index_updateEmp].getDobYear() << endl;

                                                    cout << "\n\t\t\t             New date of birth     -Day   (DD)  : " << newDobDay << endl;
                                                    cout << "\t\t\t                                   -Month (MM)  : " << newDobMonth << endl;
                                                    cout << "\t\t\t                                   -Year  (YYYY): " << newDobYear << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Enter any key to proceed." << endl;
                                                        cout << "\t\t\t\t     Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateDob(newDobDay, newDobMonth, newDobYear);
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: "  << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n")
                                                    {
                                                        goto upEmpDob;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto upEmpDob2;
                                                    }
                                            }
                                        }
                                        else if (response_updateEmp == "4")
                                        {
                                            UpEmpIc:
                                                upEmpIc(empRecord, index_updateEmp, "Employee");

                                            if (uniqueIcCheck(newIc, empRecord))
                                            {
                                                goto UpEmpIc2;
                                            }
                                            else
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New identity card number must be different from identity card number." << endl;
                                                cout << "\t\t\t             New identity card number must not be an existing identity card number." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new identity card number." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto UpEmpIc;
                                                }
                                            }

                                                UpEmpIc2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current identity card number: " << empRecord[index_updateEmp].getIc() << endl;
                                                    cout << "\t\t\t             New identity card number    : " << newIc << endl << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateIc(newIc);
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n") {
                                                        goto UpEmpIc;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto UpEmpIc2;
                                                    }

                                        }
                                        else if (response_updateEmp == "5")
                                        {
                                            upEmpNationality:
                                                upEmpNationality(empRecord, index_updateEmp, "Employee");
                                            if (newNationality == empRecord[index_updateEmp].getNationality())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New nationality must be different from current nationality." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new nationality." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto upEmpNationality;
                                                }
                                            }
                                            else
                                            {
                                                upEmpNationality2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current nationality: " << empRecord[index_updateEmp].getNationality() << endl;
                                                    cout << "\t\t\t             New nationality    : " << newNationality << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateNationality(newNationality);
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n")
                                                    {
                                                        goto upEmpNationality;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto upEmpNationality2;
                                                    }
                                            }


                                        }
                                        else if (response_updateEmp == "6")
                                        {
                                            upEmpHpNo:
                                                upEmpHpNo(empRecord, index_updateEmp, "Employee");
                                            if (newHpNo == empRecord[index_updateEmp].getHpNo())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New telephone number must be different from current telephone number." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new telephone number." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else {
                                                    goto upEmpHpNo;
                                                }
                                            }
                                            else
                                            {
                                                upEmpHpNo2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current telephone number: " << empRecord[index_updateEmp].getHpNo()<< endl;
                                                    cout << "\t\t\t             New telephone number    : " << newHpNo << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateHpNo(newHpNo);
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n")
                                                    {
                                                        goto upEmpHpNo;

                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto upEmpHpNo2;
                                                    }
                                            }


                                        }
                                        else if (response_updateEmp == "7")
                                        {
                                           upEmpAddress:
                                                upEmpAddress(empRecord, index_updateEmp, "Employee");

                                            if (newAddress == empRecord[index_updateEmp].getAddress())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New address must be different from current address." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new address." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto upEmpAddress;
                                                }
                                            }
                                            else
                                            {
                                                upEmpAddress2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current address: " << empRecord[index_updateEmp].getAddress() << endl;
                                                    cout << "\t\t\t             New address    : " << newAddress << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateAddress(newAddress);
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n")
                                                    {
                                                        goto upEmpAddress;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto upEmpAddress2;
                                                    }
                                            }
                                        }
                                        else if (response_updateEmp == "8")
                                        {
                                             upEmpDoh:
                                                newDobDay = empRecord[index_updateEmp].getDobDay();
                                                newDobMonth = empRecord[index_updateEmp].getDobMonth();
                                                newDobYear = empRecord[index_updateEmp].getDobYear(); // retreive dob for comparison in upEmpDoh
                                                upEmpDoh(empRecord, index_updateEmp, "Employee");

                                            if (newDohDay == empRecord[index_updateEmp].getDohDay() && newDohMonth == empRecord[index_updateEmp].getDohMonth()
                                                && newDohYear == empRecord[index_updateEmp].getDohYear())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             Current date of hire must be different from current date of hire." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new date of hire." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto upEmpDoh;
                                                }
                                            }
                                            else
                                            {
                                                upEmpDoh2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current date of hire -Day  (DD)  : " << empRecord[index_updateEmp].getDohDay() << endl;
                                                    cout << "\t\t\t                                  -Month(MM)  : " << empRecord[index_updateEmp].getDohMonth() << endl;
                                                    cout << "\t\t\t                                  -Year (YYYY): " << empRecord[index_updateEmp].getDohYear() << endl;

                                                    cout << "\n\t\t\t             New date of hire     -Day  (DD)  : " << newDohDay << endl;
                                                    cout << "\t\t\t                                  -Month(MM)  : " << newDohMonth << endl;
                                                    cout << "\t\t\t                                  -Year (YYYY): " << newDohYear << endl;

                                                    cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                        if (cKey == "Y" | cKey == "y")
                                                        {
                                                            cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                            cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline(cin, anyKey);

                                                            if (anyKey == "0")
                                                            {
                                                                goto update_emp_2;
                                                            }
                                                            else
                                                            {
                                                                empRecord[index_updateEmp].updateDoh(newDohDay, newDohMonth, newDohYear);
                                                                gender = empRecord[index_updateEmp].getGender();
                                                                empCount = empRecord[index_updateEmp].getEmpCount();
                                                                newId = idGenerator(gender, newDohDay, newDohMonth, empCount);
                                                                if (empRecord[index_updateEmp].getId() == Employee::getId_EOTM())
                                                                {
                                                                    Employee::updateId_EOTM(newId);
                                                                }
                                                                empRecord[index_updateEmp].updateId(newId);

                                                                system("CLS");
                                                                cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                                cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                                cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline (cin, anyKey);
                                                                goto update_emp_2;
                                                            }
                                                        }
                                                        else if (cKey == "N" | cKey == "n")
                                                        {
                                                            goto upEmpDoh;
                                                        }
                                                        else
                                                        {
                                                            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                            cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                            cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline(cin, anyKey);

                                                            goto upEmpDoh2;
                                                        }
                                                }
                                        }
                                        else if (response_updateEmp == "9")
                                        {
                                            upEmpJobTitle:
                                                upEmpJobTitle(empRecord, index_updateEmp, "Employee");

                                            if (newJobTitle == empRecord[index_updateEmp].getJobTitle())
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                cout << "\t\t\t             New job title must be different from current job title." << endl;
                                                cout << "\t\t\t             Enter any key to re-enter new job title." << endl;
                                                cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                cout << "\t\t\t             ";
                                                getline(cin,anyKey);

                                                if (anyKey == "0")
                                                {
                                                    goto update_emp_2;
                                                }
                                                else
                                                {
                                                    goto upEmpJobTitle;
                                                }
                                            }
                                            else
                                            {
                                                upEmpJobTitle2:
                                                    system("CLS");
                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                    cout << "\n\n\n\t\t\t             Current job title: " << empRecord[index_updateEmp].getJobTitle() << endl;
                                                    cout << "\t\t\t             New job title    : " << newJobTitle << endl << endl;

                                                    cout << "\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                    getline(cin, cKey);

                                                    if (cKey == "Y" | cKey == "y")
                                                    {
                                                        cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update employee record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto update_emp_2;
                                                        }
                                                        else
                                                        {
                                                            empRecord[index_updateEmp].updateJobTitle(newJobTitle);
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Employee Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_updateEmp].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Successfully updated employee record!" << endl << endl;

                                                            cout << "\n\n\n\t\t\t\t     Enter any key to go back to update employee record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline (cin, anyKey);

                                                            goto update_emp_2;
                                                        }
                                                    }
                                                    else if (cKey == "N" | cKey == "n")
                                                    {
                                                        goto upEmpJobTitle;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto upEmpJobTitle2;
                                                    }
                                            }
                                        }
                                        else if (response_updateEmp == "0")
                                        {
                                            goto admin_menu;
                                        }
                                        else
                                        {
                                            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                            cout << "\t\t\t\t     Enter only numbers (1-9)."<< endl;
                                            cout << "\t\t\t\t     Enter any key to retry." << endl;
                                            cout << "\t\t\t\t     ";
                                            getline(cin, anyKey);

                                            goto update_emp_2;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"\n\n\n\t\t\t\t     Invalid employee ID!" << endl;
                                        cout<<"\t\t\t\t     Enter any key to re-enter employee ID." << endl;
                                        cout<<"\t\t\t\t     Enter '0' to go back to admin menu." << endl;
                                        cout<<"\t\t\t\t     ";
                                        getline(cin, response);

                                        if(response == "0")
                                        {
                                            goto admin_menu;
                                        }
                                        else
                                        {
                                            goto update_emp;
                                        }
                                    }
                                }
                                else if(adminKey == "2")
                                {
                                delete_emp:
                                    system ("CLS");
                                    cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "          Delete Employee Record         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                    cout<<"\n\n\n\t\t\t             Enter employee ID: ";
                                    getline(cin, id);

                                    if (employee_idCheck(empRecord, id))
                                    {
                                        index_deleteEmp = getIndex_empRecord (empRecord, id);
                                        delete_emp_2:
                                            printViewEmpRecord(empRecord, index_deleteEmp, "Employee");
                                            cout<<"\n\t\t\t             Confirm to delete record?(Y/N): ";
                                            string response_deleteEmp;
                                            getline(cin, response_deleteEmp);

                                            if (response_deleteEmp == "y" || response_deleteEmp == "Y")
                                            {
                                                cout<<"\n\n\n\t\t\t             Enter any key to proceed.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";

                                                getline(cin, response_deleteEmp);
                                                if (response_deleteEmp == "0")
                                                {
                                                    goto admin_menu;
                                                }
                                                else
                                                {
                                                    empRecord.erase(empRecord.begin()+(index_deleteEmp));
                                                    if (empRecord[index_deleteEmp].getId() == Employee::getId_EOTM())
                                                    {
                                                        Employee::updateId_EOTM("");
                                                        Employee::updateName_EOTM("");
                                                    }
                                                    system ("CLS");
                                                    cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             "<<char(186) << "          Delete Employee Record         " << char(186) << endl;
                                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                    cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                    cout<<"\n\n\n\t\t\t             Successfully deleted employee record!";

                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to admin menu." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline (cin, anyKey);

                                                    goto admin_menu;
                                                }
                                            }
                                            else if (response_deleteEmp == "n" || response_deleteEmp == "N")
                                            {
                                                    goto delete_emp;
                                            }
                                            else
                                            {
                                                cout<<"\n\n\n\t\t\t\t     Invalid input." << endl;
                                                cout<<"\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                cout<<"\t\t\t\t     Enter any key to retry." << endl;
                                                cout<<"\t\t\t\t     ";
                                                getline(cin, response);

                                                goto delete_emp_2;
                                            }
                                    }
                                    else
                                    {
                                        cout<<"\n\n\n\t\t\t\t     Invalid employee ID!" << endl;
                                        cout<<"\t\t\t\t     Enter any key to re-enter employee ID." << endl;
                                        cout<<"\t\t\t\t     Enter '0' to go back to admin menu." << endl;
                                        cout<<"\t\t\t\t     ";
                                        getline(cin, response);

                                        if(response == "0")
                                        {
                                            goto admin_menu;
                                        }
                                        else
                                        {
                                            goto delete_emp;
                                        }
                                    }
                                }
                                else if(adminKey == "3")
                                {
                                    emp_list:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "          List of Employee Record        " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        printEmployeeList(empRecord);
                                        cout<<"\n\n\n\t\t\t             Enter an index number for more details." << endl;
                                        cout<<"\t\t\t             Enter '0' to go back to admin menu." << endl;
                                        cout<<"\t\t\t             ";
                                        string response_listEmp;
                                        getline(cin, response_listEmp);

                                    if (!isLetters(response_listEmp) && isNumbers(response_listEmp) && !isPunct(response_listEmp) && !isSpace(response_listEmp))
                                    {
                                        stringstream (response_listEmp) >> (index_listEmp);
                                        if (index_listEmp == 0)
                                        {
                                            goto admin_menu;
                                        }
                                        else if (index_listEmp > empRecord.size())
                                        {
                                            cout<<"\n\n\n\t\t\t             Invalid input.";
                                            cout<<"\n\t\t\t             Enter any key to re-enter index number.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, response_listEmp);

                                            goto emp_list;
                                        }
                                        else
                                        {
                                            index_listEmp--;
                                            printViewEmpRecord(empRecord, index_listEmp, "Employee");

                                            cout<<"\n\n\n\t\t\t             Enter 'U' to update employee record.";
                                            cout<<"\n\t\t\t             Enter 'D' to delete employee record.";
                                            cout<<"\n\t\t\t             Enter 'X' to go back to list of employee.";
                                            cout<<"\n\t\t\t             Enter any other key to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, response);

                                            if (response == "x" || response == "X")
                                            {
                                                goto emp_list;
                                            }
                                            else if (response == "u" || response == "U")
                                            {
                                                index_updateEmp = index_listEmp;
                                                goto update_emp_2;
                                            }
                                            else if (response == "d" || response == "D")
                                            {
                                                index_deleteEmp = index_listEmp;
                                                goto delete_emp_2;
                                            }
                                            else
                                            {
                                                goto admin_menu;
                                            }
                                        }

                                    }
                                    else
                                    {
                                        cout << "\n\n\n\t\t\t             Invalid input." ;
                                        cout << "\n\t\t\t             Enter only numbers." ;
                                        cout << "\n\t\t\t             Enter any key to re-enter index number.";
                                        cout << "\n\t\t\t             " ;
                                        getline(cin, anyKey);

                                        goto emp_list;
                                    }
                                }
                                else if(adminKey == "4")
                                {
                                    vector <int> vector_index;
                                    string displayVar2;
                                    search_emp_record:

                                    system ("CLS");
                                    cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "          Search Employee Record         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl << endl;

                                    cout<<"\t\t\t\t             1. Search by employee ID  "<< endl;
                                    cout<<"\t\t\t\t             2. Search by name         "<< endl;
                                    cout<<"\t\t\t\t             3. Search by gender       "<< endl;
                                    cout<<"\t\t\t\t             4. Search by date of birth"<< endl;
                                    cout<<"\t\t\t\t             5. Search by date of hire "<< endl;
                                    cout<<"\t\t\t\t             6. Search by job title    "<< endl;
                                    cout<<"\t\t\t\t             7. Exit    "<< endl;

                                    cout<<"\n\t\t\t             Enter a number: ";
                                    string response_searchEmp;
                                    getline(cin, response_searchEmp);

                                    if(response_searchEmp == "1")
                                    {
                                        search_id:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "          Search by Employee ID          " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Employee ID: ";
                                        getline(cin, id);

                                        vector_index = searchById(empRecord, id);

                                            if (vector_index.empty())
                                            {
                                                cout<<"\n\n\n\t\t\t             Employee ID does not exist.";
                                                cout<<"\n\t\t\t             Enter any key re-enter employee ID.";
                                                cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, response);

                                                if (response == "0")
                                                {
                                                    goto admin_menu;

                                                }
                                                else if (response == "X" || response == "x"){
                                                    goto search_emp_record;

                                                }
                                                else
                                                {
                                                    goto search_id;

                                                }
                                            }
                                            else
                                            {
                                                system ("CLS");
                                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "          Search by Employee ID          " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                displayVar2 = "          Search by Employee ID          ";

                                                string action_after_search = printSearchResult_getAction(empRecord, vector_index, index_updateEmp, index_deleteEmp, displayVar2);
                                                if (action_after_search == "u" || action_after_search == "U")
                                                {
                                                    vector_index.clear();
                                                    goto update_emp_2;
                                                }
                                                else if (action_after_search == "d" || action_after_search == "D")
                                                {
                                                    vector_index.clear();
                                                    goto delete_emp_2;
                                                }
                                                else
                                                {
                                                    vector_index.clear();
                                                    goto search_emp_record;
                                                }
                                            }
                                    }
                                    else if(response_searchEmp == "2")
                                    {
                                        search_name:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "             Search by Name              " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Employee Name: ";
                                        getline(cin, name);

                                        if ( !isNumbers(name) && isLetters(name) && !isPunct(name) ){

                                        for (unsigned int i = 0; i < name.length(); i++)
                                        {
                                            name[i] = toupper(name[i]);
                                        }

                                        vector_index = searchByName(empRecord, name);

                                            if (vector_index.empty())
                                            {
                                                cout<<"\n\n\n\t\t\t             Employee name does not exist.";
                                                cout<<"\n\t\t\t             Enter any key re-enter employee name.";
                                                cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, response);

                                                if (response == "0")
                                                {
                                                    goto admin_menu;

                                                }
                                                else if (response == "X" || response == "x"){
                                                    goto search_emp_record;

                                                }
                                                else
                                                {
                                                    goto search_name;
                                                }
                                            }
                                            else
                                            {
                                                system ("CLS");
                                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "             Search by Name              " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                displayVar2 = "             Search by Name              ";

                                                string action_after_search = printSearchResult_getAction(empRecord, vector_index, index_updateEmp, index_deleteEmp, displayVar2);
                                                if (action_after_search == "u" || action_after_search == "U")
                                                {
                                                    vector_index.clear();
                                                    goto update_emp_2;
                                                }
                                                else if (action_after_search == "d" || action_after_search == "D")
                                                {
                                                    vector_index.clear();
                                                    goto delete_emp_2;
                                                }
                                                else
                                                {
                                                    vector_index.clear();
                                                    goto search_emp_record;
                                                }
                                            }

                                            }
                                            else{
                                                cout<<"\n\n\n\t\t\t             Invalid input.";
                                                cout<<"\n\t\t\t             Enter only letters without punctuation.";
                                                cout<<"\n\t\t\t             Enter any key re-enter employee name.";
                                                cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, response);

                                                if (response == "0")
                                                {
                                                    goto admin_menu;

                                                }
                                                else if (response == "X" || response == "x"){
                                                    goto search_emp_record;

                                                }
                                                else
                                                {
                                                    goto search_name;
                                                }

                                            }
                                    }
                                    else if(response_searchEmp == "3")
                                    {
                                        search_gender:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "             Search by Gender            " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Employee Gender: ";
                                        getline(cin, gender);

                                        for (unsigned int i = 0; i < gender.length(); i++)
                                        {
                                            gender[i] = toupper(gender[i]);
                                        }

                                        if (gender == "MALE" || gender == "FEMALE"){

                                            vector_index = searchByGender(empRecord, gender);

                                            if (vector_index.empty())
                                            {
                                                cout<<"\n\n\n\t\t\t             Employee gender does not exist.";
                                                cout<<"\n\t\t\t             Enter any key re-enter employee gender.";
                                                cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, response);

                                                if (response == "0")
                                                {
                                                    goto admin_menu;

                                                }
                                                else if (response == "X" || response == "x"){
                                                    goto search_emp_record;

                                                }
                                                else
                                                {
                                                    goto search_gender;

                                                }
                                            }
                                            else
                                            {
                                                system ("CLS");
                                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "            Search by Gender             " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                displayVar2 = "            Search by Gender             ";

                                                string action_after_search = printSearchResult_getAction(empRecord, vector_index, index_updateEmp, index_deleteEmp, displayVar2);
                                                if (action_after_search == "u" || action_after_search == "U")
                                                {
                                                    vector_index.clear();
                                                    goto update_emp_2;
                                                }
                                                else if (action_after_search == "d" || action_after_search == "D")
                                                {
                                                    vector_index.clear();
                                                    goto delete_emp_2;
                                                }
                                                else
                                                {
                                                    vector_index.clear();
                                                    goto search_emp_record;
                                                }
                                            }

                                            }else{

                                                cout<<"\n\n\n\t\t\t             Invalid input.";
                                                cout<<"\n\t\t\t             Enter only 'MALE' or 'FEMALE'.";
                                                cout<<"\n\t\t\t             Enter any key re-enter employee gender.";
                                                cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, response);

                                                if (response == "0")
                                                {
                                                    goto admin_menu;

                                                }
                                                else if (response == "X" || response == "x"){
                                                    goto search_emp_record;

                                                }
                                                else
                                                {
                                                    goto search_gender;

                                                }

                                            }

                                    }
                                    else if(response_searchEmp == "4")
                                    {
                                        search_dob:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "          Search by Date of Birth        " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Enter date of birth -Day(DD)    : ";
                                        getline(cin, dobDayStr);
                                        cout<<"\t\t\t                                 -Month(MM)  : ";
                                        getline(cin, dobMonthStr);
                                        cout<<"\t\t\t                                 -Year(YYYY) : ";
                                        getline(cin, dobYearStr);

                                        validOfDateCal();

                                        if (!isLetters(dobDayStr) && isNumbers(dobDayStr) && !isPunct(dobDayStr) && !isSpace(dobDayStr) &&
                                            !isLetters(dobMonthStr) && isNumbers(dobMonthStr) && !isPunct(dobMonthStr) && !isSpace(dobMonthStr) &&
                                            !isLetters(dobYearStr) && isNumbers(dobYearStr) && !isPunct(dobYearStr) && !isSpace(dobYearStr))
                                        {
                                            stringstream(dobDayStr) >> dobDay;
                                            stringstream(dobMonthStr) >> dobMonth;
                                            stringstream(dobYearStr) >> dobYear;

                                            validOfDateCal();

                                            if (dobDay >= 1 && dobDay <= 31 && dobMonth >= 1 && dobMonth <= 12 && dobYear >= 1000 && dobYear <= 9999
                                                && dobYear <= (nowYear - 14) && dobYear >= (nowYear - 80) )
                                            {
                                                if ((dobDay == 31) && (dobMonth == 4 || dobMonth == 6 || dobMonth == 9 || dobMonth == 11))
                                                {
                                                    string monthName;

                                                    if (dobMonth == 4)
                                                    {
                                                        monthName = "April";
                                                    }
                                                    else if (dobMonth == 6)
                                                    {
                                                        monthName = "June";
                                                    }
                                                    else if (dobMonth == 9)
                                                    {
                                                        monthName = "September";
                                                    }
                                                    else /*(dobMonth == 11)*/
                                                    {
                                                        monthName = "November";
                                                    }
                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                    cout << "\t\t\t\t     There's no 31st in " << monthName << "." << endl;
                                                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline(cin, anyKey);

                                                    goto  search_dob;
                                                }

                                                int x = dobYear % 4;

                                                if ((x != 0) && (dobDay >= 29 && dobMonth == 2))
                                                {
                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                    cout << "\t\t\t\t     There's no 29th or above in February " << dobYear << "." << endl;
                                                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline(cin, anyKey);

                                                    goto search_dob;
                                                }

                                                if (dobDay > 29 && dobMonth == 2)
                                                {
                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                    cout << "\t\t\t\t     There's no 30th and 31st in February." << endl;
                                                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline(cin, anyKey);

                                                    goto search_dob;
                                                }
                                                //

                                                search_dob_2:

                                                system ("CLS");
                                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "          Search by Date of Birth        " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                cout<<"\n\n\n\t\t\t             Enter date of birth -Day(DD)    : " << dobDay;
                                                cout<<"\n\t\t\t                                 -Month(MM)  : " << dobMonth;
                                                cout<<"\n\t\t\t                                 -Year(YYYY) : " << dobYear;

                                                cout<<"\n\n\t\t\t             Choose(BEFORE/AFTER) the date: ";
                                                string range_dob;
                                                getline(cin, range_dob);

                                                for (unsigned int i = 0; i < range_dob.length(); i++) {
                                                    range_dob[i] = toupper(range_dob[i]);
                                                }

                                                if (range_dob == "BEFORE" || range_dob == "AFTER")
                                                {
                                                    vector_index = searchByDob(empRecord, dobDay, dobMonth, dobYear, range_dob);
                                                    if (vector_index.empty())
                                                    {
                                                        cout<<"\n\n\n\t\t\t             Employee date of birth does not exist.";
                                                        cout<<"\n\t\t\t             Enter any key re-enter employee date of birth.";
                                                        cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                        cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                        cout<<"\n\t\t\t             ";
                                                        getline(cin, response);

                                                        if (response == "0")
                                                        {
                                                            goto admin_menu;

                                                        }
                                                        else if (response == "X" || response == "x"){
                                                            goto search_emp_record;

                                                        }
                                                        else
                                                        {
                                                            goto search_dob;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        system ("CLS");
                                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "          Search by Date of Birth        " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                        displayVar2 = "          Search by Date of Birth        ";

                                                        string action_after_search = printSearchResult_getAction(empRecord, vector_index, index_updateEmp, index_deleteEmp, displayVar2);
                                                        if (action_after_search == "u" || action_after_search == "U")
                                                        {
                                                            vector_index.clear();
                                                            goto update_emp_2;
                                                        }
                                                        else if (action_after_search == "d" || action_after_search == "D")
                                                        {
                                                            vector_index.clear();
                                                            goto delete_emp_2;
                                                        }
                                                        else
                                                        {
                                                            vector_index.clear();
                                                            goto search_emp_record;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                cout<<"\n\n\n\t\t\t             Invalid input.";
                                                cout<<"\n\t\t\t             Enter only 'BEFORE' or 'AFTER.";
                                                cout<<"\n\t\t\t             Enter any key to retry.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, anyKey);

                                                 // call user to enter only after/before
                                                goto search_dob_2;
                                                }
                                            }
                                            else
                                            {
                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                cout << "\t\t\t\t     Employee must be 14 years old or older." << endl;
                                                cout << "\t\t\t\t     Maximum age is 80." << endl;
                                                cout << "\t\t\t\t     Enter any key to re-enter date of birth." << endl;
                                                cout << "\t\t\t\t     ";
                                                getline(cin, anyKey);

                                                goto search_dob;
                                            }
                                        }
                                        else
                                        {
                                            cout<<"\n\n\n\t\t\t             Invalid input.";
                                            cout<<"\n\t\t\t             Enter only numbers.";
                                            cout<<"\n\t\t\t             Enter any key to re-enter date of birth.";
                                            cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                            cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, anyKey);

                                            if(anyKey == "X" || anyKey == "x"){
                                                goto search_emp_record;

                                            }
                                            else if (anyKey == "0"){
                                                goto admin_menu;

                                            }
                                            else
                                            {
                                                goto search_dob;
                                            }


                                        }
                                    }
                                    else if(response_searchEmp == "5")
                                    {
                                        search_doh:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "          Search by Date of Hire         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Enter date of hire  -Day(DD)    : ";
                                        getline(cin, dohDayStr);
                                        cout<<"\t\t\t                                 -Month(MM)  : ";
                                        getline(cin, dohMonthStr);
                                        cout<<"\t\t\t                                 -Year(YYYY) : ";
                                        getline(cin, dohYearStr);

                                        validOfDateCal();

                                        if (!isLetters(dohDayStr) && isNumbers(dohDayStr) && !isPunct(dohDayStr) && !isSpace(dohDayStr) &&
                                            !isLetters(dohMonthStr) && isNumbers(dohMonthStr) && !isPunct(dohMonthStr) && !isSpace(dohMonthStr) &&
                                            !isLetters(dohYearStr) && isNumbers(dohYearStr) && !isPunct(dohYearStr) && !isSpace(dohYearStr))
                                        {
                                            stringstream(dohDayStr) >> dohDay;
                                            stringstream(dohMonthStr) >> dohMonth;
                                            stringstream(dohYearStr) >> dohYear;

                                            validOfDateCal();

                                            if (dohDay >= 1 && dohDay <= 31 && dohMonth >= 1 && dohMonth <= 12 && dohYear >= 1000 && dohYear <= 9999)
                                            {
                                                if (dohYear > nowYear)
                                                {
                                                    cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                                                    cout << "\t\t\t\t       Hire date cannot be later than today." << endl;
                                                    cout << "\t\t\t\t       Enter any key to re-enter date of hire." << endl;
                                                    cout << "\t\t\t\t       ";
                                                    getline(cin, anyKey);

                                                    goto search_doh;


                                                }
                                                else if (dohYear == nowYear)
                                                {
                                                    if (dohMonth > nowMonth)
                                                    {
                                                        cout << "\n\n\n\t\t\t\t      Invalid input." << endl;
                                                        cout << "\t\t\t\t      Hire date cannot be later than today." << endl;
                                                        cout << "\t\t\t\t      Enter any key to re-enter date of hire." << endl;
                                                        cout << "\t\t\t\t       ";
                                                        getline(cin, anyKey);

                                                        goto search_doh;
                                                    }
                                                    else if (dohMonth == nowMonth)
                                                    {
                                                        if (dohDay > nowDay)
                                                        {
                                                            cout << "\n\n\n\t\t\t\t      Invalid input." << endl;
                                                            cout << "\t\t\t\t      Hire date cannot be later than today." << endl;
                                                            cout << "\t\t\t\t      Enter any key to re-enter date of hire." << endl;
                                                            cout << "\t\t\t\t       ";
                                                            getline(cin, anyKey);

                                                            goto search_doh;
                                                        }
                                                        else if (dohDay == nowDay){
                                                            goto search_doh_2;
                                                        }

                                                    }
                                                }
                                                else /*(dohYear < nowYear)*/
                                                {
                                                    goto search_doh_2;
                                                }


                                                search_doh_2:

                                                if ((dohDay == 31) && (dohMonth == 4 || dohMonth == 6 || dohMonth == 9 || dohMonth == 11))
                                                {
                                                    string monthName;

                                                    if (dohMonth == 4)
                                                    {
                                                        monthName = "April";
                                                    }
                                                    else if (dohMonth == 6)
                                                    {
                                                        monthName = "June";
                                                    }
                                                    else if (dohMonth == 9)
                                                    {
                                                        monthName = "September";
                                                    }
                                                    else/*(dohMonth == 11)*/
                                                    {
                                                        monthName = "November";
                                                    }
                                                        cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                        cout << "\t\t\t\t     There's no 31st in " << monthName << "." << endl;
                                                        cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin, anyKey);

                                                        goto search_doh;
                                                }

                                                int x = dohYear % 4;

                                                if ((x != 0) && (dohDay >= 29 && dohMonth == 2))
                                                {
                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                    cout << "\t\t\t\t     There's no 29th or above in February " << dobYear << "." << endl;
                                                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline(cin, anyKey);

                                                    goto search_doh;
                                                }

                                                if (dohDay > 29 && dohMonth == 2)
                                                {
                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                    cout << "\t\t\t\t     There's no 30th and 31st in February." << endl;
                                                    cout << "\t\t\t\t     Enter any key to re-enter new date of birth." << endl;
                                                    cout << "\t\t\t\t     ";
                                                    getline(cin, anyKey);

                                                    goto search_doh;
                                                }
                                                //

                                                search_doh_3:

                                                system ("CLS");
                                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "          Search by Date of Hire         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                cout<<"\n\n\n\t\t\t             Enter date of hire  -Day(DD)    : " << dohDay;
                                                cout<<"\n\t\t\t                                 -Month(MM)  : " << dohMonth;
                                                cout<<"\n\t\t\t                                 -Year(YYYY) : " << dohYear;

                                                cout<<"\n\n\t\t\t             Choose(BEFORE/AFTER) the date: ";
                                                string range_doh;
                                                getline(cin, range_doh);

                                                for (unsigned int i = 0; i < range_doh.length(); i++) {
                                                    range_doh[i] = toupper(range_doh[i]);
                                                }

                                                if (range_doh == "BEFORE" || range_doh == "AFTER")
                                                {
                                                    vector_index = searchByDoh(empRecord, dohDay, dohMonth, dohYear, range_doh);
                                                    if (vector_index.empty())
                                                    {
                                                        cout<<"\n\n\n\t\t\t             Employee date of hire does not exist.";
                                                        cout<<"\n\t\t\t             Enter any key re-enter employee date of hire.";
                                                        cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                                        cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                        cout<<"\n\t\t\t             ";
                                                        getline(cin, response);

                                                        if (response == "0")
                                                        {
                                                            goto admin_menu;

                                                        }
                                                        else if (response == "X" || response == "x"){
                                                            goto search_emp_record;

                                                        }
                                                        else
                                                        {
                                                            goto search_doh;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        system ("CLS");
                                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "          Search by Date of Hire         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                        displayVar2 = "          Search by Date of Hire         ";

                                                        string action_after_search = printSearchResult_getAction(empRecord, vector_index, index_updateEmp, index_deleteEmp, displayVar2);
                                                        if (action_after_search == "u" || action_after_search == "U")
                                                        {
                                                            vector_index.clear();
                                                            goto update_emp_2;
                                                        }
                                                        else if (action_after_search == "d" || action_after_search == "D")
                                                        {
                                                            vector_index.clear();
                                                            goto delete_emp_2;
                                                        }
                                                        else
                                                        {
                                                            vector_index.clear();
                                                            goto search_emp_record;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                cout<<"\n\n\n\t\t\t             Invalid input.";
                                                cout<<"\n\t\t\t             Enter only 'BEFORE' or 'AFTER.";
                                                cout<<"\n\t\t\t             Enter any key to retry.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, anyKey);
                                                // call user to enter only after/before
                                                goto search_doh_3;
                                                }
                                            }
                                            else
                                            {
                                                cout << "\n\n\n\t\t\t             Invalid input.";
                                                cout << "\n\t\t\t             Hire date cannot be later than today.";
                                                cout << "\n\t\t\t             Enter any key to re-enter date of hire.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, anyKey);

                                                goto search_doh;
                                            }
                                        }
                                        else
                                        {
                                            cout<<"\n\n\n\t\t\t             Invalid input.";
                                            cout<<"\n\t\t\t             Enter only numbers.";
                                            cout<<"\n\t\t\t             Enter any key to re-enter date of hire.";
                                            cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                            cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, anyKey);

                                            if(anyKey == "X" || anyKey == "x"){
                                                goto search_emp_record;

                                            }
                                            else if (anyKey == "0"){
                                                goto admin_menu;

                                            }
                                            else
                                            {
                                                goto search_doh;
                                            }

                                        }
                                    }
                                    else if(response_searchEmp == "6")
                                    {
                                    search_job_title:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "            Search by Job Title          " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Job Title: ";
                                        getline(cin, jobTitle);

                                        if (!isNumbers(jobTitle) && isLetters(jobTitle) && !isPunct(jobTitle)){

                                        for (unsigned int i = 0; i < jobTitle.length(); i++) {
                                            jobTitle[i] = toupper(jobTitle[i]);
                                        }

                                        vector_index = searchByJobTitle(empRecord, jobTitle);

                                        if (vector_index.empty())
                                        {
                                            cout<<"\n\n\n\t\t\t             Employee job title does not exist.";
                                            cout<<"\n\t\t\t             Enter any key re-enter employee job title.";
                                            cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                            cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, response);

                                            if (response == "0")
                                            {
                                                goto admin_menu;

                                            }
                                            else if (response == "X" || response == "x"){
                                                goto search_emp_record;

                                            }
                                            else
                                            {
                                                goto search_job_title;
                                            }
                                        }
                                        else
                                        {
                                            system ("CLS");
                                            cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             "<<char(186) << "           Search by Job Title           " << char(186) << endl;
                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                            displayVar2 = "           Search by Job Title           ";

                                            string action_after_search = printSearchResult_getAction(empRecord, vector_index, index_updateEmp, index_deleteEmp, displayVar2);
                                            if (action_after_search == "u" || action_after_search == "U")
                                            {
                                                vector_index.clear();
                                                goto update_emp_2;
                                            }
                                            else if (action_after_search == "d" || action_after_search == "D")
                                            {
                                                vector_index.clear();
                                                goto delete_emp_2;
                                            }
                                            else
                                            {
                                                vector_index.clear();
                                                goto search_emp_record;
                                            }
                                        }

                                        }else
                                        {
                                            cout<<"\n\n\n\t\t\t             Invalid input.";
                                            cout<<"\n\t\t\t             Enter only letters without punctuation.";
                                            cout<<"\n\t\t\t             Enter any key re-enter employee job title.";
                                            cout<<"\n\t\t\t             Enter 'X' to go back to search employee record menu.";
                                            cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, response);

                                            if (response == "0")
                                            {
                                                goto admin_menu;

                                            }
                                            else if (response == "X" || response == "x"){
                                                goto search_emp_record;

                                            }
                                            else
                                            {
                                                goto search_job_title;
                                            }


                                        }

                                    }
                                    else if (response_searchEmp == "7"){
                                        goto admin_menu;

                                    }
                                    else{
                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                        cout << "\t\t\t             Enter only numbers." << endl;
                                        cout << "\t\t\t             Enter any key to retry." << endl;
                                        cout << "\t\t\t             Enter '0' to go back to admin menu." << endl;
                                        cout << "\t\t\t             ";
                                        getline(cin,anyKey);

                                        if (anyKey == "0"){
                                            goto admin_menu;

                                        }
                                        else{
                                            goto search_emp_record;

                                        }

                                    }
                                }
                                else if(adminKey == "5")
                                {
                                    system ("CLS");
                                    cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "     Set/Adjust Employee of the Month    " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                    cout<<"\n\n\n\t\t\t             Current employee of the month: "<< Employee::getName_EOTM() << " - " << Employee::getId_EOTM() << endl;
                                    cout<<"\n\n\n\t\t\t             Enter any key to continue setting/adjusting employee of the month.";
                                    cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                    cout<<"\n\t\t\t             ";
                                    getline(cin, response);

                                set_emp_of_month:

                                    if (response != "0")
                                    {
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "     Set/Adjust Employee of the Month    " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Current employee of the month: "<< Employee::getName_EOTM() << " - " << Employee::getId_EOTM() << endl;

                                        cout<<"\n\t\t\t             Enter employee ID of NEW employee of the month: ";
                                        getline(cin, id);

                                        admin_setEOTM_yesORno:
                                        for (unsigned int i = 0 ; i < empRecord.size() ; i++)
                                        {
                                            if (id == empRecord[i].getId())
                                            {
                                                system ("CLS");
                                                cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "     Set/Adjust Employee of the Month    " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                cout<<"\n\n\n\t\t\t             New employee of the month: "<< empRecord[i].getName() <<" - "<< empRecord[i].getId() << endl;

                                                cout<<"\n\t\t\t             Confirm to set him/her as employee of the month?(Y/N): ";
                                                getline(cin, response);

                                                if (response == "y" || response == "Y")
                                                {
                                                    cout<<"\n\n\n\t\t\t             Enter any key to proceed.";
                                                    cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                    cout<<"\n\t\t\t             ";
                                                    getline(cin, response);

                                                    if (response == "0")
                                                    {
                                                        goto admin_menu;
                                                    }

                                                    else
                                                    {
                                                        Employee::updateName_EOTM(empRecord[i].getName());
                                                        Employee::updateId_EOTM(empRecord[i].getId());
                                                        system ("CLS");
                                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "     Set/Adjust Employee of the Month    " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                        cout<<"\n\n\n\t\t\t             Successfully set/adjusted employee of the month!";


                                                        cout<<"\n\n\n\t\t\t             Enter any key to go back to admin menu.";
                                                        cout<<"\n\n\n\t\t\t             ";
                                                        getline(cin, anyKey);

                                                        goto admin_menu;
                                                    }
                                                }
                                                else if (response == "n" || response == "N")
                                                {
                                                    goto set_emp_of_month;
                                                }
                                                else
                                                {
                                                    cout<<"\n\n\n\t\t\t             Invalid input.";
                                                    cout<<"\n\t\t\t             Enter only 'Y' or 'N'.";
                                                    cout<<"\n\t\t\t             Enter any key to retry.";
                                                    cout<<"\n\t\t\t             ";
                                                    getline(cin, anyKey);

                                                    goto admin_setEOTM_yesORno;
                                                }
                                            }
                                        } // No match for emp id
                                        cout<<"\n\n\n\t\t\t             Invalid employee ID!";
                                        cout<<"\n\t\t\t             Enter any key to re-enter employee ID.";
                                        cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                        cout<<"\n\t\t\t             ";
                                        getline(cin, response);

                                        if (response == "0")
                                        {
                                            goto admin_menu;
                                        }
                                        else
                                        {
                                            goto set_emp_of_month;
                                        }
                                    }
                                    else
                                    {
                                        goto admin_menu;
                                    }
                                }
                                else if(adminKey == "6")
                                {
                                    create_admin:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "           Create Admin Account          " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Employee ID: ";
                                        getline(cin, id);
                                        cout<<"\n\t\t\t             Password: ";
                                        getline(cin, password);

                                        if (employee_idPassword_Check(id,password,empRecord))
                                        {
                                            cout<<"\n\t\t\t             New admin username: ";
                                            getline(cin, admin_username);

                                            cout<<"\n\t\t\t             New admin password: ";
                                            getline(cin, admin_password);

                                            if (uniqueAdminUsernameCheck(admin_username, admin_list))
                                            {
                                                add_admin_yes_or_no:
                                                cout<<"\n\t\t\t             Confirm to create new admin account?(Y/N): ";
                                                getline(cin, response);

                                                if (response == "y" || response == "Y")
                                                {
                                                    cout<<"\n\n\n\t\t\t             Enter any key to proceed.";
                                                    cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                    cout<<"\n\t\t\t             ";
                                                    getline(cin, response);

                                                    if (response == "0")
                                                    {
                                                        goto admin_menu;

                                                    }
                                                    else
                                                    {
                                                        system ("CLS");
                                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "           Create Admin Account          " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;
                                                        fillAdminList(admin_list);
                                                        cout<<"\n\n\n\t\t\t             Successfully created new admin account!";

                                                        cout<<"\n\n\n\t\t\t             Enter any key to go back to admin menu.";
                                                        cout<<"\n\t\t\t             ";
                                                        getline(cin, anyKey);

                                                        goto admin_menu;
                                                    }
                                                }
                                                else if (response == "n" || response == "N")
                                                {
                                                    goto create_admin;

                                                }
                                                else
                                                {
                                                    cout << "\n\n\n\t\t\t             Invalid input.";
                                                    cout << "\n\t\t\t             Enter only 'Y' or 'N'.";
                                                    cout << "\n\t\t\t             Enter any key to retry.";
                                                    getline(cin,anyKey);

                                                    goto add_admin_yes_or_no;
                                                }
                                            }
                                            else
                                            {
                                                cout<<"\n\n\n\t\t\t             Existed admin username.";
                                                cout<<"\n\t\t\t             Enter any key to go back to creating new admin account.";
                                                cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                cout<<"\n\t\t\t             ";
                                                getline(cin, response);

                                                if (response == "0"){
                                                    goto admin_menu;

                                                }
                                                else
                                                {
                                                    goto create_admin;
                                                }
                                            }


                                        }
                                        else
                                        {
                                            cout<<"\n\n\n\t\t\t             Invalid employee ID or password.";
                                            cout<<"\n\t\t\t             You must be an employee in order to register an admin account.";
                                            cout<<"\n\t\t\t             Enter any key to go back to creating new admin account.";
                                            cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, response);

                                            if (response == "0"){
                                                goto admin_menu;

                                            }
                                            else
                                            {
                                                goto create_admin;
                                            }
                                        }
                                }
                                else if(adminKey == "7")
                                {
                                    delete_admin:
                                        system ("CLS");
                                        cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "           Delete Admin Account          " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t             Admin username: ";
                                        getline(cin, admin_username);
                                        cout<<"\n\t\t\t             Admin password: ";
                                        getline(cin, admin_password);

                                        if (admin_username == "ermsadmin" && admin_password == "admin123")
                                        {
                                            cout<<"\n\n\n\t\t\t             You are not allow to delete the default admin account.";
                                            cout<<"\n\t\t\t             Enter any key to re-enter admin username and password.";
                                            cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                            cout<<"\n\t\t\t             ";
                                            getline(cin, response);
                                            if (response == "0")
                                            {
                                                goto admin_menu;
                                            }
                                            else
                                            {
                                                goto delete_admin;
                                            }
                                        }
                                        else
                                        {
                                            if (admin_idPassword_Check(admin_list,admin_username, admin_password))
                                            {
                                                delete_admin_yes_or_no:
                                                    cout<<"\n\t\t\t             Confirm to delete admin account?(Y/N): ";
                                                    getline(cin, response);

                                                    if (response == "y" || response == "Y")
                                                    {
                                                        cout<<"\n\n\n\t\t\t             Enter any key to proceed.";
                                                        cout<<"\n\t\t\t             Enter '0' to go back to admin menu.";
                                                        cout<<"\n\t\t\t             ";
                                                        getline(cin, response);

                                                        if (response == "0")
                                                        {
                                                            goto admin_menu;
                                                        }
                                                        else
                                                        {
                                                            int index_deleteAdmin = getIndex_adminList(admin_list, admin_username);
                                                            admin_list.erase(admin_list.begin()+(index_deleteAdmin));
                                                            system ("CLS");
                                                            cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             "<<char(186) << "           Delete Admin Account          " << char(186) << endl;
                                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                                            cout<<"\n\n\n\t\t\t             Successfully deleted an admin account!";

                                                            cout<<"\n\n\n\t\t\t             Enter any key to go back to admin/main menu.";
                                                            cout<<"\n\t\t\t             ";
                                                            getline(cin, anyKey);

                                                            if (current_username == admin_username && current_password == admin_password)
                                                            {
                                                                goto main_menu;
                                                            }
                                                            else
                                                            {
                                                                goto admin_menu;
                                                            }
                                                        }
                                                    }
                                                    else if (response == "n" || response == "N")
                                                    {
                                                        goto delete_admin;
                                                    }
                                                    else
                                                    {
                                                        cout << "\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             Enter only 'Y' or 'N'." << endl;
                                                        cout << "\t\t\t             Enter any key to retry." << endl;
                                                        getline(cin, anyKey);

                                                        goto delete_admin_yes_or_no;
                                                    }
                                            }
                                            else
                                            {
                                                cout<<"\n\n\n\t\t\t             Invalid username or password!" << endl;
                                                cout<<"\t\t\t             Enter any key to re-enter username and password." << endl;
                                                cout<<"\t\t\t             Enter '0' to go back to admin menu." << endl;
                                                cout<<"\t\t\t             ";
                                                getline(cin, response);

                                                if(response == "0")
                                                {
                                                    goto admin_menu;
                                                }
                                                else
                                                {
                                                    goto delete_admin;
                                                }
                                            }
                                        }
                                }
                                else if(adminKey == "8")
                                {
                                    system ("CLS");
                                    cout << "\t\t\t             "<<char(201);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(187) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "           List of Admin Accounts        " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             "<<char(200);      for(int i=0; i<41; i++){cout << char(205);}      cout << char(188) << endl;

                                    printAdminList(admin_list);
                                    cout<<"\n\n\n\t\t\t             Enter any key to go back to admin menu.";
                                    cout<<"\n\t\t\t             ";
                                    getline(cin, anyKey);

                                    goto admin_menu;
                                }
                                else if(adminKey == "9")
                                {
                                    do{
                                        system("CLS");
                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "             Exit Admin Menu             " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                        cout<<"\n\n\n\t\t\t\t       Confirm to exit admin menu? (Y/N): ";
                                        getline(cin, cKey);

                                            if(cKey == "Y" || cKey == "y")
                                            {
                                                goto main_menu;
                                            }
                                            else if (cKey == "N" || cKey == "n")
                                            {
                                                goto admin_menu;
                                            }
                                            else
                                            {
                                                cout<<"\n\n\n\t\t\t             Invalid input." << endl;
                                                cout<<"\t\t\t             Enter only 'Y' or 'N'." << endl;
                                                cout<<"\t\t\t             Enter any key to retry." << endl;
                                                cout<<"\t\t\t             ";
                                                getline(cin, anyKey);
                                            }
                                        } while(cKey != "Y" && cKey != "y" && cKey != "N" && cKey != "n" );
                                }
                                else
                                {
                                    cout<<"\n\n\n\t\t\t             Invalid input." << endl;
                                    cout<<"\t\t\t             Enter only numbers (1-9)." << endl;
                                    cout<<"\t\t\t             Enter any key to retry." << endl;
                                    cout<<"\t\t\t             ";
                                    getline(cin, anyKey);

                                    goto admin_menu;
                                }
                        }
                        else
                        {
                            cout<<"\n\n\n\t\t\t             Invalid username or password!" << endl;
                            cout<<"\t\t\t             Enter any key to re-enter username and password." << endl;
                            cout<<"\t\t\t             Enter '0' to go back to main menu." << endl;
                            cout<<"\t\t\t             ";
                            getline(cin, response);

                            if(response == "0")
                            {
                                goto main_menu;
                            }
                            else
                            {
                                goto admin_login;
                            }
                        }

                    }
            }
            else if (mainKey == "2")
            {
                do {
                empLoginMain:

                system("CLS");
                cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                cout << "\t\t\t             " << char(186) << "             Employee Login              " << char(186) << endl;
                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188)  << endl;

                cout << "\n\n\n\t\t\t               Enter employee ID: ";
                getline(cin, id);

                cout << "\n\t\t\t               Enter password   : ";
                getline(cin, password);

                    if (employee_idPassword_Check(id, password, empRecord))
                    {
                        int index_empAccess = getIndex_empRecord (empRecord, id);
                        string current_employee_login_id = id;

                        employee_menu:
                            system("CLS");
                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                            cout << "\t\t\t             " << char(186) << "              Employee Menu              " << char(186) << endl;
                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

                            cout << "\t\t\t\t            1. View personal record" << endl;
                            cout << "\t\t\t\t            2. Update personal record" << endl;
                            cout << "\t\t\t\t            3. Get certificate of employment" << endl;
                            cout << "\t\t\t\t            4. View employee of the month" << endl;
                            cout << "\t\t\t\t            5. Change login password" << endl;
                            cout << "\t\t\t\t            6. Exit" << endl;

                            cout << "\n\t\t\t\t            Enter a number: ";
                            getline(cin, empKey);

                            if (!isLetters(empKey) && isNumbers(empKey) && !isPunct(empKey) && !isSpace(empKey))
                            {
                                if (empKey == "1")
                                {
                                    printViewEmpRecord(empRecord,index_empAccess,"Personal");
                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to employee menu." << endl;
                                    cout << "\t\t\t\t     ";
                                    getline(cin, anyKey);

                                    goto employee_menu;
                                }
                                else if (empKey == "2")
                                {
                                updateMain:
                                        printUpdateEmpRecord(empRecord,index_empAccess,"Personal");
                                        cout << "\n\n\n\t\t\t\t     Enter index number to update." << endl;
                                        cout << "\t\t\t\t     Enter '0' to go back to employee menu." << endl;
                                        cout << "\t\t\t\t     ";
                                        getline(cin, indexKey);

                                        if (!isLetters(indexKey) && isNumbers(indexKey) && !isPunct(indexKey) && !isSpace(indexKey))
                                        {
                                            if (indexKey == "0")
                                            {
                                                goto employee_menu;
                                            }
                                            else if (indexKey == "1")
                                            {
                                                upPersonalNameMain:
                                                    upEmpName(empRecord,index_empAccess,"Personal");

                                                    if (newName == empRecord[index_empAccess].getName())
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New name must be different from current name." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new name." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalNameMain;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        upPersonalName2Main:
                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current name: " << empRecord[index_empAccess].getName() << endl;
                                                            cout << "\t\t\t             New name    : " << newName << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                                cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateName(newName);

                                                                    if (current_employee_login_id == Employee::getId_EOTM())
                                                                    {
                                                                        Employee::updateName_EOTM(newName);
                                                                    }

                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);

                                                                    goto updateMain;
                                                                }
                                                            }
                                                            else if (cKey == "N" | cKey == "n")
                                                            {
                                                                goto upPersonalNameMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalName2Main;
                                                            }
                                                    }
                                            }
                                            else if (indexKey == "2")
                                            {
                                                upPersonalGenderMain:
                                                    upEmpGender(empRecord, index_empAccess, "Personal");

                                                    if (newGender == empRecord[index_empAccess].getGender())
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New gender must be different from current gender." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new gender." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t\t     ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalGenderMain;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        upPersonalGender2Main:

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current gender: " << empRecord[index_empAccess].getGender() << endl;
                                                            cout << "\t\t\t             New gender    : " << newGender << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Enter any key to proceed." << endl;
                                                                cout << "\t\t\t\t     Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateGender(newGender);
                                                                    newDohDay = empRecord[index_empAccess].getDohDay();
                                                                    newDohMonth = empRecord[index_empAccess].getDohMonth();
                                                                    empCount = empRecord[index_empAccess].getEmpCount();
                                                                    newId = idGenerator(newGender, newDohDay, newDohMonth, empCount);
                                                                    empRecord[index_empAccess].updateId(newId);

                                                                    if (current_employee_login_id == Employee::getId_EOTM())
                                                                    {
                                                                        Employee::updateId_EOTM(newId);
                                                                    }

                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);

                                                                    goto updateMain;
                                                                }

                                                            }
                                                            else if (cKey == "N" | cKey == "n") {
                                                                goto upPersonalGenderMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalGender2Main;
                                                            }

                                                    }
                                            }
                                            else if (indexKey == "3")
                                            {
                                                upPersonalDobMain:
                                                    upEmpDob(empRecord, index_empAccess, "Personal");

                                                    if (newDobDay == empRecord[index_empAccess].getDobDay() && newDobMonth == empRecord[index_empAccess].getDobMonth()
                                                        && newDobYear == empRecord[index_empAccess].getDobYear())
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New date of birth must be different from current date of birth." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new date of birth." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalDobMain;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        upPersonalDob2Main:

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: "<< empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current date of birth -Day   (DD)  : " << empRecord[index_empAccess].getDobDay() << endl;
                                                            cout << "\t\t\t                                   -Month (MM)  : " << empRecord[index_empAccess].getDobMonth() << endl;
                                                            cout << "\t\t\t                                   -Year  (YYYY): " << empRecord[index_empAccess].getDobYear() << endl;

                                                            cout << "\n\t\t\t             New date of birth     -Day   (DD)  : " << newDobDay << endl;
                                                            cout << "\t\t\t                                   -Month (MM)  : " << newDobMonth << endl;
                                                            cout << "\t\t\t                                   -Year  (YYYY): " << newDobYear << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Enter any key to proceed." << endl;
                                                                cout << "\t\t\t\t     Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateDob(newDobDay, newDobMonth, newDobYear);
                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                    cout << "\t\t\t             Employee ID: "  << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);

                                                                    goto updateMain;
                                                                }
                                                            }
                                                            else if (cKey == "N" | cKey == "n")
                                                            {
                                                                goto upPersonalDobMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalDob2Main;
                                                            }
                                                    }
                                            }
                                            else if (indexKey == "4")
                                            {
                                                upPersonalICMain:
                                                    upEmpIc(empRecord, index_empAccess, "Personal");

                                                    if (uniqueIcCheck(newIc, empRecord)){
                                                        goto upPersonalIC2Main;
                                                    }
                                                    else
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New identity card number must be different from current identity card number." << endl;
                                                        cout << "\t\t\t             New identity card number must not be an existing identity card number." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new identity card number." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalICMain;
                                                        }
                                                    }


                                                        upPersonalIC2Main:

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current identity card number: " << empRecord[index_empAccess].getIc() << endl;
                                                            cout << "\t\t\t             New identity card number    : " << newIc << endl << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                                cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t             ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateIc(newIc);
                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);
                                                                    goto updateMain;
                                                                }
                                                            }
                                                            else if (cKey == "N" | cKey == "n")
                                                            {
                                                                goto upPersonalICMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalIC2Main;
                                                            }

                                            }
                                            else if (indexKey == "5")
                                            {
                                                upPersonalNationalityMain:
                                                    upEmpNationality(empRecord, index_empAccess, "Personal");

                                                    if (newNationality == empRecord[index_empAccess].getNationality())
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New nationality must be different from current nationality." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new nationality." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalNationalityMain;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        upPersonalNationality2Main:

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current nationality: " << empRecord[index_empAccess].getNationality() << endl;
                                                            cout << "\t\t\t             New nationality    : " << newNationality << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                                cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t             ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateNationality(newNationality);
                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);

                                                                    goto updateMain;
                                                                }
                                                            }
                                                            else if (cKey == "N" | cKey == "n")
                                                            {
                                                                goto upPersonalNationalityMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalNationality2Main;
                                                            }
                                                    }
                                            }
                                            else if (indexKey == "6")
                                            {
                                                upPersonalHpNoMain:
                                                    upEmpHpNo(empRecord, index_empAccess, "Personal");

                                                    if (newHpNo == empRecord[index_empAccess].getHpNo())
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New telephone number must be different from current telephone number." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new telephone number." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalHpNoMain;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        upPersonalHpNo2Main:

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current telephone number: " << empRecord[index_empAccess].getHpNo()<< endl;
                                                            cout << "\t\t\t             New telephone number    : " << newHpNo << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                                cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateHpNo(newHpNo);
                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);

                                                                    goto updateMain;
                                                                }
                                                            }
                                                            else if (cKey == "N" | cKey == "n")
                                                            {
                                                                goto upPersonalHpNoMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalHpNo2Main;
                                                            }
                                                    }
                                            }
                                            else if (indexKey == "7")
                                            {
                                                upPersonalAddressMain:
                                                    upEmpAddress(empRecord, index_empAccess, "Personal");

                                                    if (newAddress == empRecord[index_empAccess].getAddress())
                                                    {
                                                        cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                        cout << "\t\t\t             New address must be different from current address." << endl;
                                                        cout << "\t\t\t             Enter any key to re-enter new address." << endl;
                                                        cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                        cout << "\t\t\t             ";
                                                        getline(cin,anyKey);

                                                        if (anyKey == "0")
                                                        {
                                                            goto updateMain;
                                                        }
                                                        else
                                                        {
                                                            goto upPersonalAddressMain;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        upPersonalAddress2Main:

                                                            system("CLS");
                                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                            cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                            cout << "\n\n\n\t\t\t             Current address: " << empRecord[index_empAccess].getAddress() << endl;
                                                            cout << "\t\t\t             New address    : " << newAddress << endl;

                                                            cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                            getline(cin, cKey);

                                                            if (cKey == "Y" | cKey == "y")
                                                            {
                                                                cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                                cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                if (anyKey == "0")
                                                                {
                                                                    goto updateMain;
                                                                }
                                                                else
                                                                {
                                                                    empRecord[index_empAccess].updateAddress(newAddress);
                                                                    system("CLS");
                                                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188)<< endl;

                                                                    cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                    cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                    cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline (cin, anyKey);

                                                                    goto updateMain;
                                                                }
                                                            }
                                                            else if (cKey == "N" | cKey == "n")
                                                            {
                                                                goto upPersonalAddressMain;
                                                            }
                                                            else
                                                            {
                                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline(cin, anyKey);

                                                                goto upPersonalAddress2Main;
                                                            }
                                                    }
                                            }
                                            else if (indexKey == "8")
                                            {
                                                upPersonalDohMain:
                                                    newDobDay = empRecord[index_empAccess].getDobDay();
                                                    newDobMonth = empRecord[index_empAccess].getDobMonth();
                                                    newDobYear = empRecord[index_empAccess].getDobYear();
                                                    upEmpDoh(empRecord, index_empAccess, "Personal");

                                                        if (newDohDay == empRecord[index_empAccess].getDohDay() && newDohMonth == empRecord[index_empAccess].getDohMonth()
                                                            && newDohYear == empRecord[index_empAccess].getDohYear())
                                                        {
                                                            cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                            cout << "\t\t\t             New date of hire must be different from current date of hire." << endl;
                                                            cout << "\t\t\t             Enter any key to re-enter new date of hire." << endl;
                                                            cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                            cout << "\t\t\t             ";
                                                            getline(cin,anyKey);

                                                            if (anyKey == "0")
                                                            {
                                                                goto updateMain;
                                                            }
                                                            else
                                                            {
                                                                goto upPersonalDohMain;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            upPersonalDoh2Main:

                                                                system("CLS");
                                                                cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                cout << "\n\n\n\t\t\t             Current date of hire -Day  (DD)  : " << empRecord[index_empAccess].getDohDay() << endl;
                                                                cout << "\t\t\t                                  -Month(MM)  : " << empRecord[index_empAccess].getDohMonth() << endl;
                                                                cout << "\t\t\t                                  -Year (YYYY): " << empRecord[index_empAccess].getDohYear() << endl;

                                                                cout << "\n\t\t\t             New date of hire     -Day  (DD)  : " << newDohDay << endl;
                                                                cout << "\t\t\t                                  -Month(MM)  : " << newDohMonth << endl;
                                                                cout << "\t\t\t                                  -Year (YYYY): " << newDohYear << endl;

                                                                cout << "\n\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                                getline(cin, cKey);

                                                                if (cKey == "Y" | cKey == "y")
                                                                {
                                                                    cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                                    cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline(cin, anyKey);

                                                                    if (anyKey == "0")
                                                                    {
                                                                        goto updateMain;
                                                                    }
                                                                    else
                                                                    {
                                                                        empRecord[index_empAccess].updateDoh(newDohDay, newDohMonth, newDohYear);
                                                                        gender = empRecord[index_empAccess].getGender();
                                                                        empCount = empRecord[index_empAccess].getEmpCount();
                                                                        newId = idGenerator(gender, newDohDay, newDohMonth, empCount);
                                                                        empRecord[index_empAccess].updateId(newId);

                                                                        if (current_employee_login_id == Employee::getId_EOTM())
                                                                        {
                                                                            Employee::updateId_EOTM(newId);
                                                                        }

                                                                        system("CLS");
                                                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                        cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                        cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                        cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                        cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                        cout << "\t\t\t\t     ";
                                                                        getline (cin, anyKey);

                                                                        goto updateMain;
                                                                    }
                                                                }
                                                                else if (cKey == "N" | cKey == "n")
                                                                {
                                                                    goto upPersonalDohMain;
                                                                }
                                                                else
                                                                {
                                                                    cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                                    cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                                    cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                                    cout << "\t\t\t\t     ";
                                                                    getline(cin, anyKey);

                                                                    goto upPersonalDoh2Main;
                                                                }
                                                        }
                                            }
                                            else if (indexKey == "9")
                                            {
                                                upPersonalJobTitleMain:
                                                    upEmpJobTitle(empRecord, index_empAccess, "Personal");

                                                if (newJobTitle == empRecord[index_empAccess].getJobTitle())
                                                {
                                                    cout << "\n\n\n\t\t\t             Invalid input." << endl;
                                                    cout << "\t\t\t             New job title must be different from current job title." << endl;
                                                    cout << "\t\t\t             Enter any key to re-enter new job title." << endl;
                                                    cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                    cout << "\t\t\t             ";
                                                    getline(cin,anyKey);

                                                    if (anyKey == "0")
                                                    {
                                                        goto updateMain;
                                                    }
                                                    else
                                                    {
                                                        goto upPersonalJobTitleMain;
                                                    }
                                                }
                                                else
                                                {
                                                    upPersonalJobTitle2Main:

                                                        system("CLS");
                                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                        cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                        cout << "\n\n\n\t\t\t             Current job title: " << empRecord[index_empAccess].getJobTitle() << endl;
                                                        cout << "\t\t\t             New job title    : " << newJobTitle << endl << endl;

                                                        cout << "\t\t\t             Confirm to proceed changes?(Y/N): ";
                                                        getline(cin, cKey);

                                                        if (cKey == "Y" | cKey == "y")
                                                        {
                                                            cout << "\n\n\n\t\t\t             Enter any key to proceed." << endl;
                                                            cout << "\t\t\t             Enter '0' to go back to update personal record menu." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline(cin, anyKey);

                                                            if (anyKey == "0")
                                                            {
                                                                goto updateMain;
                                                            }
                                                            else
                                                            {
                                                                empRecord[index_empAccess].updateJobTitle(newJobTitle);
                                                                system("CLS");
                                                                cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "         Update Personal Record          " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                                cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                                cout << "\t\t\t             Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                                cout << "\n\n\n\t\t\t             Successfully updated personal record!" << endl << endl;

                                                                cout << "\n\n\n\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                                cout << "\t\t\t\t     ";
                                                                getline (cin, anyKey);

                                                                goto updateMain;
                                                            }
                                                        }
                                                        else if (cKey == "N" | cKey == "n")
                                                        {
                                                            goto upPersonalJobTitleMain;
                                                        }
                                                        else
                                                        {
                                                            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                            cout << "\t\t\t\t     Enter only 'Y' or 'N'." << endl;
                                                            cout << "\t\t\t\t     Enter any key to retry." << endl;
                                                            cout << "\t\t\t\t     ";
                                                            getline(cin, anyKey);

                                                            goto upPersonalJobTitle2Main;
                                                        }
                                                    }
                                            }
                                            else
                                            {
                                                cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                                cout << "\t\t\t\t     Enter only numbers from 1 to 9." << endl;
                                                cout << "\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                                cout << "\t\t\t\t     ";
                                                getline (cin, anyKey);

                                                goto updateMain;
                                            }
                                        }
                                        else
                                        {
                                            cout << "\n\n\n\t\t\t\t     Invalid input." << endl;
                                            cout << "\t\t\t\t     Enter any key to go back to update personal record menu." << endl;
                                            cout << "\t\t\t\t     ";
                                            getline (cin, anyKey);

                                            goto updateMain;
                                        }
                                }
                                else if (empKey == "3")
                                {
                                    do
                                    {

                                        employmentDurationCal(empRecord[index_empAccess].getDohMonth(), empRecord[index_empAccess].getDohYear());

                                        string monthStr, yearStr;
                                        if (doeMonth <= 1)
                                        {
                                            monthStr = "month";
                                        }
                                        else
                                        {
                                            monthStr = "months";
                                        }

                                        if (doeYear <=1)
                                        {
                                            yearStr = "year";

                                        }else
                                        {
                                            yearStr = "years";
                                        }

                                        system("CLS");
                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "        Certificate of Employment        " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                        cout << "\n\n\n\t\t\t\t       To whom it may concern:" << endl << endl;

                                        cout << "\t\t\t\t       This is to certify that " << empRecord[index_empAccess].getName() << " has been " << endl;
                                        cout << "\t\t\t\t       " << "employed with us as " << empRecord[index_empAccess].getJobTitle() << " for " << doeYear  << endl;
                                        cout << "\t\t\t\t       " << yearStr << " and " << doeMonth  << " " << monthStr << " from " << empRecord[index_empAccess].getDohYear()<< " to " << nowYear << "." << endl <<endl;


                                        cout << "\t\t\t\t       This certificate is being issued upon" << endl;
                                        cout << "\t\t\t\t       his/her request for whatever purposes" << endl;
                                        cout << "\t\t\t\t       it may serve." << endl;

                                        cout << "\n\n\n\t\t\t\t       Enter 'X' to print certificate of employment." << endl;
                                        cout << "\t\t\t\t       Enter '0' to go back to employee menu." << endl;
                                        cout << "\t\t\t\t       ";
                                        getline(cin, anyKey);

                                            if (anyKey == "X" || anyKey == "x")
                                            {
                                                system("CLS");
                                                cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "        Certificate of Employment        " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                cout << "\n\n\n\t\t\t\t       Certificate of employment is printing......" << endl << endl;

                                                cout << "\t\t\t\t       Please check your printing device." << endl;

                                                cout << "\n\n\n\t\t\t\t       Enter any key to go back to employee menu." << endl;
                                                cout << "\t\t\t\t       ";
                                                getline(cin,anyKey);

                                                goto employee_menu;
                                            }
                                            else if (anyKey == "0")
                                            {
                                                goto employee_menu;
                                            }
                                            else
                                            {
                                                cout << "\n\n\n\t\t\t\t       Invalid input." << endl;
                                                cout << "\t\t\t\t       Enter only 'X' or '0'." << endl;
                                                cout << "\t\t\t\t       Enter any key to retry." << endl;
                                                cout << "\t\t\t\t       " << endl;
                                                getline(cin, anyKey);

                                            }
                                    } while( anyKey != "X" && anyKey != "x" && anyKey != "0");
                                }
                                else if (empKey == "4")
                                {
                                    system("CLS");
                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "          Employee of the Month          " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

                                    cout << "\t\t\t\t       Current employee of the month: " << Employee::getName_EOTM() << endl << endl;

                                    cout << "\n\n\n\t\t\t\t       Enter any key to go back to employee menu." << endl;
                                    cout << "\t\t\t\t       ";
                                    getline(cin, anyKey);

                                    goto employee_menu;
                                }
                                else if (empKey == "5")
                                {
                                    changePersonalPassword(empRecord, index_empAccess);
                                    changePersonalPassword2Main:
                                        system("CLS");
                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "          Change Login Password          " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                        cout << "\t\t\t\t       Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                        cout << "\n\n\n\t\t\t\t       Current password: " << empRecord[index_empAccess].getPassword() << endl;
                                        cout << "\t\t\t\t       New password    : " ;
                                        getline(cin, newPassword);

                                        if (isLetters(newPassword) && isNumbers(newPassword) && isCapital(newPassword) && isNonCapital(newPassword)
                                        && isPunct(newPassword) && newPassword.size() > 7 && newPassword.size() < 21 )
                                        {

                                            changePersonalPassword3Main:
                                                system("CLS");
                                                cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "          Change Login Password          " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                cout << "\t\t\t\t       Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                cout << "\n\n\n\t\t\t\t       Current password: " << empRecord[index_empAccess].getPassword() << endl;
                                                cout << "\t\t\t\t       New password    : " << newPassword << endl;

                                                cout<<"\n\t\t\t\t       Confirm to proceed changes? (Y/N): ";
                                                getline(cin, cKey);

                                                if (cKey == "Y" || cKey == "y")
                                                {
                                                    cout << "\n\n\n\t\t\t\t       Enter any key to proceed." << endl;
                                                    cout << "\t\t\t\t       Enter any key to go back to employee menu." << endl;
                                                    cout << "\t\t\t\t       ";
                                                    getline(cin, anyKey);

                                                    if (anyKey == "0")
                                                    {
                                                        goto employee_menu;
                                                    }
                                                    else
                                                    {
                                                        empRecord[index_empAccess].updatePassword(newPassword);

                                                        system("CLS");
                                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "          Change Login Password          " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                                                        cout << "\t\t\t\t       Employee ID: " << empRecord[index_empAccess].getId() << endl;

                                                        cout<<"\n\n\n\t\t\t\t       Successfully changed login password!"<< endl << endl;

                                                        cout << "\n\n\n\t\t\t\t       Enter '0' to go back to employee menu." << endl;
                                                        cout << "\t\t\t\t       ";
                                                        getline(cin, anyKey);

                                                        goto employee_menu;
                                                    }
                                                }
                                                else if(cKey == "N" || cKey == "n")
                                                {
                                                    goto changePersonalPassword2Main;
                                                }
                                                else
                                                {
                                                    cout<<"\t\t\t\tInvalid input."<< endl;
                                                    cout<<"\t\t\t\tEnter only 'Y' or 'N'."<< endl;
                                                    cout << "\n\t\t\t\t      ";
                                                    getline(cin, anyKey);

                                                    goto changePersonalPassword3Main;
                                                }
                                        }
                                        else
                                        {
                                            cout << "\n\n\n\t\t\t\t       Invalid input.";
                                            cout << "\n\t\t\t\t       The following conditions must be satisfied to create a new password:";
                                            cout << "\n\t\t\t\t       1. Minimum of 8 characters and maximum of 20 characters.";
                                            cout << "\n\t\t\t\t       2. Must contain at least 1 uppercase letter.";
                                            cout << "\n\t\t\t\t       3. Must contain at least 1 lowercase letter.";
                                            cout << "\n\t\t\t\t       4. Must contain at least 1 number.";
                                            cout << "\n\t\t\t\t       5. Must contain at least 1 punctuation.";
                                            cout << "\n\t\t\t\t       Enter any key to re-enter new password.";
                                            cout << "\n\t\t\t\t       Enter '0' to go back to employee menu.";
                                            cout << "\n\t\t\t\t       ";
                                            getline(cin,anyKey);

                                            if(anyKey == "0")
                                            {
                                                goto employee_menu;
                                            }
                                            else
                                            {
                                                goto changePersonalPassword2Main;
                                            }
                                        }
                                }
                                else if (empKey == "6")
                                {
                                    do
                                    {
                                        system("CLS");
                                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "            Exit Employee Menu           " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl ;

                                        cout<<"\n\n\n\t\t\t\t       Confirm to exit employee menu? (Y/N): ";
                                        getline(cin, cKey);

                                            if(cKey == "Y" || cKey == "y")
                                            {
                                                goto main_menu;
                                            }
                                            else if (cKey == "N" || cKey == "n")
                                            {
                                                goto employee_menu;
                                            }
                                            else
                                            {
                                                cout << "\n\n\n\t\t\t               Invalid input." << endl;
                                                cout << "\t\t\t               Enter only 'Y' or 'N'." << endl;
                                                cout << "\t\t\t               Enter any key to retry." << endl;
                                                cout << "\t\t\t               ";
                                                getline(cin,anyKey);
                                            }
                                    } while (cKey != "Y" && cKey != "y" && cKey != "N" && cKey != "n" );


                                }
                                else
                                {
                                    cout << "\n\n\n\t\t\t               Invalid number." << endl;
                                    cout << "\t\t\t               Enter only numbers from 1-6." << endl;
                                    cout << "\t\t\t               Enter any key to retry." << endl;
                                    cout << "\t\t\t               ";
                                    getline (cin, anyKey);

                                    goto employee_menu;
                                }

                            }
                            else
                            {
                                cout << "\n\n\n\t\t\t               Invalid input." << endl;
                                cout << "\t\t\t               Enter only numbers." << endl;
                                cout << "\t\t\t               Enter any key to retry." << endl;
                                cout << "\t\t\t               ";
                                getline (cin, anyKey);

                                goto employee_menu;
                            }
                    }
                    else
                    {
                        cout << "\n\n\n\t\t\t               Invalid employee ID or password." << endl;
                        cout << "\t\t\t               Enter any key to retry." << endl;
                        cout << "\t\t\t               Enter '0' to go back to main menu." << endl;
                        cout << "\t\t\t               ";
                        getline (cin, anyKey);

                        if (anyKey == "0")
                        {
                            goto main_menu;
                        }
                        else
                        {
                            goto empLoginMain;
                        }
                    }
                } while (cKey != "Y" && cKey != "y" && cKey != "N" && cKey != "n" && anyKey != "0");
            }
            else if (mainKey == "3")
            {
                registerMain:
                do {
                    getEmpCount('+');
                    nameReset();
                    genderReset();
                    dobReset();
                    icReset();
                    nationalityReset();
                    hpNoReset();
                    addressReset();
                    dohReset();
                    jobTitleReset();

                    if (uniqueIcCheck (ic, empRecord))
                    {
                        system("CLS");
                        cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                        cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                        cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                        cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

                        cout << "\t\t\t               Name                      : " << name << endl;

                        cout << "\t\t\t               Gender(Male/Female)       : " << gender << endl;

                        cout << "\t\t\t               Date of birth -Day  (DD)  : " << dobDay << endl;
                        cout << "\t\t\t                             -Month(MM)  : " << dobMonth << endl;
                        cout << "\t\t\t                             -Year (YYYY): " << dobYear << endl;

                        cout << "\t\t\t               Identity Card Number      : " << ic << endl;

                        cout << "\t\t\t               Nationality               : " << nationality << endl;

                        cout << "\t\t\t               Telephone number          : " << hpNo << endl;

                        cout << "\t\t\t               Address                   : " << address << endl;

                        cout << "\t\t\t               Date of hire -Day  (DD)   : " << dohDay << endl;
                        cout << "\t\t\t                            -Month(MM)   : " << dohMonth << endl;
                        cout << "\t\t\t                            -Year (YYYY) : " << dohYear << endl;

                        cout << "\t\t\t               Job title                 : "  << jobTitle << endl;

                        cout << "\n\n\t\t\t               Enter any key to proceed with registration. " << endl;
                        cout << "\t\t\t               Enter '0' discard registration to go back to main menu. " << endl;
                        cout << "\t\t\t               ";
                        getline(cin, anyKey);

                        if (anyKey == "0")
                        {
                            getEmpCount('-');
                            goto main_menu;
                        }
                        else
                        {
                            register2Main:
                            do
                            {
                                id = idGenerator(gender, dohDay, dohMonth, empCount);
                                passwordReset();

                                register3Main:
                                    system("CLS");
                                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

                                    cout << "\t\t\t               Employee ID              : " << id << endl << endl;

                                    cout << "\t\t\t               Enter desired password   : " << password << endl << endl;

                                    cout << "\t\t\t               Confirm to register?(Y/N): ";
                                    getline(cin, cKey);

                                    if (cKey == "Y" | cKey == "y")
                                    {
                                        cout << "\n\n\n\t\t\t               Enter any key to proceed with registration. " << endl;
                                        cout << "\t\t\t               Enter '0' discard registration to go back to main menu. " << endl;
                                        cout << "\t\t\t               ";
                                        getline(cin, anyKey);

                                        if (anyKey == "0")
                                        {
                                            getEmpCount('-');
                                            goto main_menu;
                                        }
                                        else
                                        {
                                            fillEmpRecord(empRecord);
                                            system("CLS");
                                            cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             " << char(186) << "          Employee Registration          " << char(186) << endl;
                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                                            cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl << endl;

                                            cout << "\t\t\t               Successfully registered employee!" << endl << endl;

                                            cout << "\t\t\t               Employee ID              : " << id << endl;

                                            cout << "\n\n\t\t\t               Enter any key to go back to main menu."<< endl;
                                            cout << "\t\t\t               ";
                                            getline (cin, anyKey);
                                            goto main_menu;
                                        }

                                    }
                                    else if (cKey == "N" || cKey == "n")
                                    {
                                        goto register2Main;
                                    }
                                    else
                                    {
                                        cout << "\n\n\n\t\t\t               Invalid input." << endl;
                                        cout << "\t\t\t               Enter only 'Y' or 'N'." << endl;
                                        cout << "\t\t\t               Enter any key to retry."<< endl;
                                        cout << "\t\t\t               ";
                                        getline (cin, anyKey);

                                        goto register3Main;
                                    }
                            } while (anyKey != "0");
                        }
                    }
                    else
                    {
                        getEmpCount('-');
                        cout << "\n\n\n\t\t\t               Existed employee identity card number." << endl;
                        cout << "\t\t\t               Enter any key to retry registration." << endl;
                        cout << "\t\t\t               Enter '0' to go back to main menu." << endl;
                        cout << "\t\t\t               ";
                        getline (cin, anyKey);

                        if (anyKey == "0")
                        {
                            goto main_menu;
                        }
                        else
                        {
                            goto registerMain;
                        }
                    }
                } while (anyKey != "0");
            }
            else if (mainKey == "4")
            {
                do
                {
                    system("CLS");
                    cout << "\t\t\t             " << char(201);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(187) << endl;
                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             " << char(186) << "                Exit ERMS                " << char(186) << endl;
                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             " << char(186) << "                                         " << char(186) << endl;
                    cout << "\t\t\t             " << char(200);      for (int i = 0; i < 41; i++) { cout << char(205); }      cout << char(188) << endl;

                    cout<<"\n\n\n\t\t\t               Confirm to exit ERMS? (Y/N): ";
                    getline(cin, cKey);

                        if(cKey == "Y" || cKey == "y")
                        {
                            cout<<"\n\n\n\t\t\t               Save all data and changes made? (Y/N): ";
                            getline(cin, cKey);

                            if (cKey == "Y" || cKey == "y")
                            {
                                saveEmpRecord("temp_emp.txt", empRecord);
                                saveAdminList("temp_admin.txt", admin_list);
                                saveEOTM("temp_EOTM.txt", empRecord);

                                cout<<"\n\n\n\t\t\t               Thank you for using ERMS."<<endl;
                                cout <<"\t\t\t               All data and changes are saved."<<endl;
                                return 0;
                            }
                            else if (cKey == "N" || cKey == "n")
                            {
                                cout<<"\n\n\n\t\t\t               Thank you for using ERMS."<<endl;
                                cout <<"\t\t\t               No data or changes are saved."<<endl;
                                return 0;
                            }
                            else
                            {
                                cout << "\n\n\n\t\t\t               Invalid input." << endl;
                                cout << "\t\t\t               Enter only 'Y' or 'N'." << endl;
                                cout << "\t\t\t               Enter any key to retry exiting system." << endl;
                                cout << "\t\t\t               ";
                                getline(cin, anyKey);
                            }
                        }
                        else if (cKey == "N" || cKey == "n")
                        {
                            goto main_menu;
                        }
                        else
                        {
                            cout << "\n\n\n\t\t\t               Invalid input." << endl;
                            cout << "\t\t\t               Enter only 'Y' or 'N'." << endl;
                            cout << "\t\t\t               Enter any key to retry exiting system." << endl;
                            cout << "\t\t\t               ";
                            getline(cin, anyKey);
                        }
                } while(cKey != "Y" && cKey != "y" && cKey != "N" && cKey != "n" );
            }
            else
            {
                cout << "\n\n\n\t\t\t               Invalid number." << endl;
                cout << "\t\t\t               Enter only numbers from 1-4." << endl;
                cout << "\t\t\t               Enter any key to retry entering number." << endl;
                cout << "\t\t\t               ";
                getline(cin, anyKey);

                goto main_menu;
            }
        }
        else
        {
            cout << "\n\n\n\t\t\t               Invalid input." << endl;
            cout << "\t\t\t               Enter only numbers." << endl;
            cout << "\t\t\t               Enter any key to retry entering number." << endl;
            cout << "\t\t\t               ";
            getline(cin, anyKey);

            goto main_menu;
        }
    } while (mainKey != "1" && mainKey != "2" && mainKey != "3" && mainKey != "4");
}
