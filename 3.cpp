#include <iostream>
#include <string.h>
#include <vector>
#define MaxLength 100
using namespace std;

///-----------CLASS 1-----------
class Pharmacy
{
private:
    char type[10];
public:
    Pharmacy ();
    Pharmacy (char t[]);
    Pharmacy (Pharmacy &);
    ~Pharmacy ();
    virtual void display ();
    virtual char* get_type ();
    virtual void set_type (char* t);
    virtual void operator = (const Pharmacy& A);
    friend istream& operator >>(istream& input, Pharmacy& A);
    friend ostream& operator << (ostream& output, Pharmacy& A);
    virtual void read();
};
///-----------CONSTRUCTORS & DESTRUCTOR-----------
Pharmacy::Pharmacy()
{
    cout << endl << "Initialization constructor without parameters Pharmacy." << endl;
    type[0] = '\0';
}
Pharmacy::Pharmacy(char t[])
{
    cout << endl << "Initialization constructor with parameters Pharmacy." << endl;
    strcpy(type, t);
}
Pharmacy::Pharmacy(Pharmacy &A)
{
    cout << endl << "Copy constructor Pharmacy." << endl;
    strcpy(type, A.type);
}
Pharmacy::~Pharmacy()
{
    cout << endl << "Destructor Pharmacy." << endl;
}
///------------METHODS & OPERATORS---------------
void Pharmacy::display()
{
    cout << endl << type << endl;
}
char* Pharmacy::get_type()
{
    return type;
}
void Pharmacy::set_type(char *t)
{
    strcpy(type, t);
}
void Pharmacy::operator=(const Pharmacy &A)
{
    strcpy(type, A.type);
}
void Pharmacy::read()
{
    cout << "Pharmacy type (online/shop): ";
    char* TYPE = new char[MaxLength];
    cin >> TYPE;
    try
    {
        if(strcmp(TYPE, "online") != 0 && strcmp(TYPE, "shop") != 0)
            throw TYPE;
    }
    catch(char* TYPE)
    {
        cout << "Incorrect! TYPE: online/shop! " << endl;
        cin >> TYPE;
    }
    strcpy(type, TYPE);
    delete[]TYPE;
}
istream& operator >> (istream &input, Pharmacy &A)
{
    A.read();
    return input;
}
ostream& operator << (ostream &output, Pharmacy &A)
{
    A.display();
    return output;
}


///-----------CLASS 2-----------
class OnlinePharmacy:virtual public Pharmacy
{
private:
    char* web_address;
    int nr_visitors;
    int discount;
public:
    OnlinePharmacy ();
    OnlinePharmacy (char address[], int viz, int dis, char Type[]);
    OnlinePharmacy (OnlinePharmacy &A);
    ~OnlinePharmacy ();
    void display ();
    char* get_type ();
    void set_type (char* t);
    int get_visitors();
    const OnlinePharmacy& operator = (const OnlinePharmacy& A);
    friend istream &operator >> (istream& input, OnlinePharmacy &A);
    friend ostream &operator << (ostream& output, OnlinePharmacy &A);
    void read();
};
///------------CONSTRUCTORS & DESTRUCTOR------------
OnlinePharmacy::OnlinePharmacy()
{
    cout << endl << "Initialization constructor without parameters OnlinePharmacy." << endl;
    web_address = new char[MaxLength];
    web_address[0] = '\0';
    nr_visitors = 0;
    discount = 0;
}
OnlinePharmacy::OnlinePharmacy(char address[], int viz, int dis, char Type[]):Pharmacy(Type), nr_visitors(viz), discount(dis)
{
    cout << endl << "Initialization constructor with parameters OnlinePharmacy." << endl;
    web_address = new char[strlen(address)];
    strcpy(web_address, address);
}
OnlinePharmacy::OnlinePharmacy(OnlinePharmacy &A):Pharmacy(A.get_type()), nr_visitors(A.nr_visitors), discount(A.discount)
{
    cout << endl << "Copy constructor OnlinePharmacy." << endl;
    delete[]web_address;
    web_address = new char[strlen(A.web_address)];
    strcpy(web_address, A.web_address);
}
OnlinePharmacy::~OnlinePharmacy()
{
    cout << endl << "Destructor OnlinePharmacy." << endl;
    delete[]web_address;
}
///------------METHODS & OPERATORS-------------
char* OnlinePharmacy::get_type()
{
    return Pharmacy::get_type();
}
void OnlinePharmacy::set_type(char* t)
{
    this->Pharmacy::set_type(t);
}
int OnlinePharmacy::get_visitors()
{
    return nr_visitors;
}
const OnlinePharmacy& OnlinePharmacy::operator=(const OnlinePharmacy& A)
{
    delete[]web_address;
    web_address = new char[strlen(A.web_address)];
    strcpy(web_address, A.web_address);
    nr_visitors = A.nr_visitors;
    discount = A.discount;
    return *this;
}
void OnlinePharmacy::display()
{
    cout << endl << "<Pharmacy Online>:   ";
    cout << "Web address: " << web_address << "; ";
    cout << "Number of visitors: " << nr_visitors<<"; ";
    cout << "Discount: " << discount << ". ";
}
void OnlinePharmacy::read()
{
    set_type("online");
    cout << endl << "Web address: ";
    char* address = new char[MaxLength];
    cin >> address;
    strcpy(web_address, address);
    cout << endl << "Number of visitors: ";
    cin >> nr_visitors;
    try
    {
        if(nr_visitors < 0)
            throw nr_visitors;
    }
    catch(int vizitatori)
    {
        cout << endl << "Number of visitors must be > 0!!" << endl;
        cout << "Enter nr_visitors: ";
        cin >> nr_visitors;
    }
    cout << endl << "Discount: ";
    cin >> discount;
    try
    {
        if(discount < 0)
            throw discount;
    }
    catch(int discount)
    {
        cout << endl << "Discount must be > 0!!" << endl;
        cout << "Enter discount: ";
        cin >> discount;
    }
}
istream& operator >>(istream& input, OnlinePharmacy &A)
{
    A.read();
    return input;
}
ostream& operator << (ostream& output, OnlinePharmacy &A)
{
    A.display();
    return output;
}

///-----------CLASS 3-----------
class PharmacyShop:public Pharmacy
{
private:
    char* name;
    int nr_employees;
    int monthly_profit;
public:
    PharmacyShop ();
    PharmacyShop (char nume[], int employees, int profit, char Type[]);
    PharmacyShop (PharmacyShop &A);
    ~PharmacyShop ();
    const PharmacyShop& operator = (const PharmacyShop& A);
    friend istream &operator >> (istream& input, PharmacyShop &A);
    friend ostream &operator << (ostream& output, PharmacyShop &A);
    void display ();
    char* get_type ();
    void set_type (char*);
    void read();
};
///----------CONSTRUCTORS & DESTRUCTOR------------
PharmacyShop::PharmacyShop()
{
    cout << "Initialization constructor without parameters PharmacyShop." << endl;
    name = new char[MaxLength];
    name[0] = '\0';
    nr_employees = 0;
    monthly_profit = 0;
}
PharmacyShop::PharmacyShop(char nume[], int employees, int profit, char Type[]):Pharmacy(Type), nr_employees(employees), monthly_profit(profit)
{
    cout << endl << "Initialization constructor with parameters PharmacyShop." << endl;
    name = new char[strlen(nume)];
    strcpy(name, nume);
}
PharmacyShop::PharmacyShop(PharmacyShop &A):Pharmacy(A.get_type()), nr_employees(A.nr_employees), monthly_profit(A.monthly_profit)
{
    cout << endl << "Copy Constructor PharmacyShop." << endl;
    delete[]name;
    name = new char[strlen(A.name)];
    strcpy(name, A.name);
}
PharmacyShop::~PharmacyShop()
{
    cout << endl << "Destructor PharmacyShop." << endl;
    delete[]name;
}
///-----------METHODS & OPERATORS----------
char* PharmacyShop::get_type()
{
    return Pharmacy::get_type();
}
void PharmacyShop::set_type(char* t)
{
    this->Pharmacy::set_type(t);
}
const PharmacyShop& PharmacyShop::operator=(const PharmacyShop& A)
{
    delete[]name;
    name = new char[strlen(A.name)];
    strcpy(name, A.name);
    nr_employees = A.nr_employees;
    monthly_profit = A.monthly_profit;
    return *this;
}
void PharmacyShop::display()
{
    cout << endl << "<PharmacyShop>:   ";
    cout << "Name: " << name << "; ";
    cout << "Numar employees: " << nr_employees << "; ";
    cout << "Profit lunar" << monthly_profit << ". ";
}
void PharmacyShop::read()
{
    set_type("shop");
    cout << endl << "Name: ";
    cin >> name;
    cout << endl << "Nr employees: ";
    cin >> nr_employees;
    try
    {
        if(nr_employees < 0)
            throw nr_employees;
    }
    catch(int employees)
    {
        cout << endl << "Nr_employees must be > 0!!" << endl;
        cout << "Enter nr_employees: ";
        cin >> nr_employees;
    }
    cout << endl << "Profit lunar: ";
    try
    {
        if(monthly_profit < 0)
            throw monthly_profit;
    }
    catch(int profit)
    {
        cout << endl << "The profit must be > 0!!" << endl;
        cout << "Enter profit: ";
        cin >> monthly_profit;
    }
    cin >> monthly_profit;
}
istream& operator >> (istream& input, PharmacyShop &A)
{
    A.read();
    return input;
}
ostream& operator << (ostream& output, PharmacyShop &A)
{
    A.display();
    return output;
}


///-----------CLASS 4-----------
template <class T>
class PharmacyManagement
{
private:
    T* pharmacy_series[100];
    int nr_pharmacies;
    const char* id;
public:
    PharmacyManagement ();
    PharmacyManagement (char ID[]);
    PharmacyManagement (const PharmacyManagement &A);
    ~PharmacyManagement ();
    void display(ostream &);
    void read(istream &);
    PharmacyManagement& operator += (Pharmacy &A);
    void operator = (const PharmacyManagement &A);
};
///----------CONSTRUCTORS & DESTRUCTOR---------
template<class T>
PharmacyManagement<T>::PharmacyManagement()
{
    cout << endl << "Initialization constructors without parameters PharmacyManagement. " << endl;
    nr_pharmacies = 0;
}
template<class T>
PharmacyManagement<T>::PharmacyManagement(char ID[])
{
    cout << endl << "Initialization constructors with parameters PharmacyManagement. " << endl;
    nr_pharmacies = 0;
    char *aux = new char[strlen(ID) + 1];
    strcpy(aux, ID);
    id = aux;
}
template<class T>
PharmacyManagement<T>::PharmacyManagement(const PharmacyManagement &A)
{
    cout << "Copy constructor PharmacyManagement. " << endl;
    nr_pharmacies = A.nr_pharmacies;
    for(int i = 0; i < nr_pharmacies; i++)
        pharmacy_series[i] = A.pharmacy_series[i];
    char *aux = new char[strlen(A.id) + 1];
    strcpy(aux, A.id);
    id = aux;
}
template<class T>
PharmacyManagement<T>::~PharmacyManagement()
{
    cout << endl << "Destructor PharmacyManagement. " << endl;
    delete[]pharmacy_series;
    delete[]id;
    nr_pharmacies = 0;
}
///--------METHODS & OPERATORS----------
template<class T>
void PharmacyManagement<T>::display(ostream &output)
{
    output << endl << "PHARMACY MANAGEMENT:" << endl;
    output << endl << "Pharmacy ID: ";
    output << id;
    output << endl << "Number of pharmacies from series: ";
    output << nr_pharmacies;
    output << endl << "Pharmacies: ";
    for(int i = 0; i < nr_pharmacies; i++)
    {
        pharmacy_series[i]->display();
        cout << endl;
    }
}
template<class T>
void PharmacyManagement<T>::read(istream &input)
{
    cout << "Number of pharmacies: ";
    input >> nr_pharmacies;
    for(int i = 0; i < nr_pharmacies; i++)
    {
        int x;
        cout << endl << "Enter the pharmacy type(1-online; 2-shop): ";
        cin >> x;
        if(x == 1)
        {
            pharmacy_series[i] = new OnlinePharmacy;
            pharmacy_series[i]->read();
        }
        else
        {
            pharmacy_series[i] = new PharmacyShop;
            pharmacy_series[i]->read();
        }
    }
}
template <class T>
PharmacyManagement<T>& PharmacyManagement<T>::operator += (Pharmacy &A)
{
	nr_pharmacies++;
	if(strcmp(A.get_type(), "online") == 0)
    {
        pharmacy_series[nr_pharmacies] = new OnlinePharmacy;
        pharmacy_series[nr_pharmacies] = &A;
    }
    else
    {
        pharmacy_series[nr_pharmacies - 1] = new PharmacyShop;
        pharmacy_series[nr_pharmacies - 1] = &A;
    }
	pharmacy_series[nr_pharmacies - 1] = &A;
	return *this;
}
template <class T>
void PharmacyManagement<T>::operator = (const PharmacyManagement &A)
{
    nr_pharmacies = A.nr_pharmacies;
    for(int i = 0; i < nr_pharmacies; i++)
        pharmacy_series[i] = A.pharmacy_series[i];
    char *aux = new char[strlen(A.id) + 1];
    strcpy(aux, A.id);
    id = aux;
}
istream& operator >> (istream& input, PharmacyManagement<Pharmacy> &A)
{
    A.read(input);
    return input;
}
ostream& operator << (ostream& output, PharmacyManagement<Pharmacy> &A)
{
    A.display(output);
    return output;
}
int main()
{
    OnlinePharmacy z;
    cin >> z;
    cout << z;
    PharmacyManagement<Pharmacy> a("CATENA");
    cin >> a;
    PharmacyShop b;
    cin >> b;
    a += b;
    a +=z;
    PharmacyManagement<Pharmacy> c("PUNKT");
    c = a;
    cout << c;
    return 0;
}
