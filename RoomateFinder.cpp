/*
Title: Roommate Finder

Specification:
This system will provide you with numerous compatible roommate options based on mutual criteria.
Roommate Finder is roommate search service where you can find and rent great places & people 
to share a home with.

Created By: Sima Jazaa Mohammed

*/

#include <iostream>
#include <string>
using namespace std;
//Declaring class Location
class Location{	
	private:
		//Attribute
		string State;
		string City;
		string Sreetname;
		int    Streetnumber;
		int    Housenumber;	
	public:
		//Default Constructor
		Location() {}	
		//Constructor
		Location( string st , string ci , string stname, int stnum , int hnum ){
			State=st;
			City=ci;
			Sreetname=stname;
			Streetnumber=stnum;}
	
		//Accessor Function
		string getState(){return State;}
		string getCity(){return City;}
		string getSreetname(){return Sreetname;	}
		int getStreetnumber(){return Streetnumber;}
		int getHousenumber(){return  Housenumber;}		
};
		

//Declaring Class Contract
class Contract{
	private:
		string contract_id;
		string contract_time;
		string contract_type;
		string Client_Name;
		int Client_Age;
		string Client_Gender;
		string Client_Job;
		string Client_Phone;
		string Client_Email;
		public:
	//Default Constructor
	Contract() {}
	//Constructor
	Contract(string i,string t,string ty )
	{ contract_id=i; contract_time=t; contract_type=ty;}
	Contact(string i,string t,string ty,string n ,int a,string g, string j,string ph,string e)
	{contract_id=i; contract_time=t; contract_type=ty; Client_Name=n;  Client_Age=a; Client_Gender=g; 
	Client_Job=j; Client_Phone=ph; Client_Email=e;}
	//Friend ( Overloaded >> operator. Gives cin the ability to  store user input directly into  Contract objects.)    
	friend istream &operator >> (istream &input, Contract &obj){
		cout<<"Please Enter Your Details:\n";
		cout<<"Name: "; input>>obj.Client_Name;
		cout<<"Age: "; input>>obj.Client_Age;
		cout<<"Gender: "; input>>obj.Client_Gender;
		cout<<"Job: "; input>>obj.Client_Job;
		cout<<"Phone Number: "; input>>obj.Client_Phone;
		cout<<"Email: "; input>>obj.Client_Email;
		return input;}
	//Accessor
	string getcontractTime(){return  contract_time;}
	string getContract_id(){return contract_id;}
	string getContract_type(){return contract_type;}
	string getClient_Name(){return Client_Name;}
	int getClient_Age(){return Client_Age;}
	string getClient_Job(){return Client_Job;}
	string getClient_Phone(){return Client_Phone;}
	string getClient_Email(){return Client_Email;}
	string getClient_Gender(){return Client_Gender;}

};

	

//Declaring class House
class Accommodation{
	
	private:
		//Attribute
		Location *place;		//Aggregation
		Contract *Agreement;	//Aggregation
		
	public:
		//Default Constructor
	Accommodation(){}
	
	void setAccommodationAddress(Location* C){
		place=C;
	}
	void setAccommodationContract(Contract* N){
		Agreement=N;
	}
	//Virtual will contribute to criteria 'Polymorphism'
	virtual double  getPayment(){return 0;}
	virtual void showRentAccommodation(){};

		//Function to Display Address.
	void DisplayAddress(){
		cout<<"Accommodation Address\n"	;
		cout<<"***********************************************************************************************************\n";
		cout<<"State: "<<place->getState()<<endl;
		cout<<"City: "<<place->getCity()<<endl;
		cout<<"Streetname is ("<<place->getSreetname()<<") and ";
		cout<<"Street Number is("<<place->getStreetnumber()<<"), Accommodation Number is ("<<place->getHousenumber()<<").\n\n";}
		//Function to dispay Contract Information
		void printContractinfo(){
			cout<<"Contract Information\n";
			cout<<"#####################\n";
			cout<<"Contract Number: "<<Agreement->getContract_id()<<endl;
			cout<<"Contract Time: "<<Agreement->getcontractTime()<<endl;
			cout<<"Contact Type: "<<Agreement->getContract_type()<<endl;
			}
		
		};


class House: public Accommodation //Inheritance
{	protected:
		//Attribute
		string typeAccommodation;
		double Area;
		int numberRooms;
		double RentPrice;
		
	public:
		//Constructor 
		House (string typeA, double A, int numR, double RentP){
			typeAccommodation=typeA;
			Area=A;
			numberRooms=numR;
			RentPrice=RentP;}
			
		double getPayment(){return RentPrice;}	
		
		//Function to show the Information of House
		void showRentAccommodation(){
		cout<<"The "<<typeAccommodation<<" has an area of "<<Area<<" meter square which include ";
		cout<<numberRooms<<" rooms. "<<"The Price is "<<getPayment()<<"$\n";}
};

class Appartment: public Accommodation //Inheritance
{	protected:
	//Attribute
		string typeAccommodation;
		double Area;
		int numberRooms;
		double servicePrice;
		double RentPrice;
	public:
		//Default Constructor
		Appartment(){}
		//Constructor
		Appartment (string typeA, double A, int numR, double serP, double RentP){
			typeAccommodation=typeA;
			Area=A;
			numberRooms=numR;
			servicePrice=serP;
			RentPrice=RentP;}
		
		double getPayment(){return RentPrice+servicePrice;}
		
		//Function to show the Information of House
		void showRentAccommodation(){
		cout<<"The "<<typeAccommodation<<" has an area of "<<Area<<" meter square which include ";
		cout<<numberRooms<<" rooms.\n";
		cout<<"The Rent Price is ("<<RentPrice<<"$)";
		cout<<" While the Services Price of the Appartment is ("<<servicePrice<<"$)\n";
		cout<<"The Total Price is "<<getPayment()<<"$\n";}	};	

//Declaring class Contact
class Contact{
	private:
	//Attribute
	string Phone;
	string Email;
	public:
	//Default constructor
	Contact() {}
	//Constructor
	Contact(string P,string E)
	{ Phone=P; Email=E;}
	string getPhone(){return Phone;	}
	//Accessor
	string getEmail(){return Email;}
};
	
//Declaring class Roommates
class Roommates{
	private:
		//Attribute
		string Name;
		string Gender;
		int Age;
		string Job;
		string rent;
		Contact  info;//Compostion
		Contract Sign;//Compostion
		Accommodation *Detail;//Association 
	public:
		//Default constructor
		Roommates () {}
		//Constructor
		Roommates(string Name,string Gender,int Age,string Job,string rent, string Phone,string Email,
		string contract_id, string contract_time,string contract_type) 
		{ this->Name=Name;
		this->rent=rent;
		this-> Gender=Gender;
		this-> Job=Job;
		this-> Age=Age;
		this->info=Contact(Phone,Email);
		this->Sign=Contract(contract_id,contract_time,contract_type);}

		void Rent(Accommodation *D) 
		{ Detail=D;}
		//Accessor Function
		string getName ()
		{ return Name;}
		string getGender()
		{ return Gender;}
		int getAge(){return Age;}
		string getJob()
		{ return Job;}
		
	//Friend (Overloaded << operator. Gives cout the ability to directly display Roommates objects.)    
	friend ostream &operator << (ostream &output, const Roommates &obj){
		output<<"Roomate Information\n";
		output<<"~~~~~~~~~~~~~~~~~~~\n";
		output<<"Name: "<<obj.Name<<endl;
		output<<"Gender: "<<obj.Gender<<endl;
		output<<"Age: "<<obj.Age<<endl;
		output<<"Job: "<<obj.Job<<endl;
		output<<"Looking For: "<<obj.rent<<endl;
		return output;}
		
		//Function to Display Contact Informaton.
		void printContactinfo(){
			cout<<"\nContact Information\n";
			cout<<"-------------------\n";
			cout<<"Phone: "<<info.getPhone()<<endl;
			cout<<"Email: "<<info.getEmail()<<endl;		}
			
		//Function to Display Contract Informaton.
		void printContractinfo(){
			cout<<"Contract Information\n";
			cout<<"#####################\n";
			cout<<"Contract Number: "<<Sign.getContract_id()<<endl;
			cout<<"Contract Time: "<<Sign.getcontractTime()<<endl;
			cout<<"Contact Type: "<<Sign.getContract_type()<<endl;
			}
			void showRent(){Detail->showRentAccommodation();} 	};

//menu			
int menu(){
	int choice;
   
    cout << endl;
    cout << "--------- Menu------------" << endl;
    //Display Output
	cout<<"What do you want to seacrh?\n\n";
	cout<<"1.Look for a Roommate \n";
	cout<<"2.Look for Accommodation\n";
	cout<<"3.Quit Menu\n";
   
    cout << endl;
	cout<<"Enter your choice from the menu:" ;
	cin>>choice; //Enter a choice.   
    return choice;
}
 int main(){ 
 	//Display outputs
 	cout <<"\t\t\t\t~*~*~*~   WELCOME TO ROOMMATE FINDER   ~*~*~*~"<<"\n\n";
	cout <<"\t\t\t\t  'Hey you, looking for a roommate?'"<<"\n";
	cout <<" \t\t\t\t            ** OK **\t\t"<<"\n";
	cout <<"\t\t\t\t-We will help you to find the PERFECT ROOMMATE."<<"\n";
	cout <<"\t\t\t\t-And the IDEAL HOUSE for you.\t\t"<<"\n\n\n";
	
	
	
//Declare 5 Arrays of Roommate
Roommates Array[5]={
	Roommates ("Hanar Ahmed","Female" ,20 ,"HR assistant" ," Roommate to share Accommodation with","07506667788","Hanar74@gmail.com","001","1 Year","Roommate and Rental Agreement"),
	Roommates ("Roza Faraj" ,"Female" ,23 ,"Programming Coordinator" ," Roommate to share Accommodation with","07713243211","Roza34@gmail.com","002","8 Months","Roommate and Rental Agreement" ),
	Roommates ("Tre Anwar" ,"Female" ,20 ,"Student"  ,"  Roommate to share Accommodation with","07704562343","Banu99@gmail.com","003","5 Months","Roommate and Rental Agreementt"),
	Roommates ("Ali Anwar " ,"Male" ,21 ,"Student "    ," Roommate and Accommodation","07709898988","Ali881@gmail.com","004","2 Years","Roommate Agreement" ),
	Roommates ("Dara Azad " ,"Male" ,24 ,"Accountant" ," Roommate and Accommodation","07508976633","Dara17@gmail.com","005","4 Months","Roommate Agreement" )};

 //Dynamically assigning 3 instance memory              
Appartment *one=new Appartment("Appartment",100, 3,150,100);
Appartment *two=new Appartment("Appartment",150, 4,150,200);
House *three=new House("House",200, 5,300);	
//Assign each element of array 
Array[0].Rent(one);
Array[1].Rent(two);
Array[2].Rent(three);


//Declare 5 Arrays 
Appartment aa("Appartment",200, 4,200,250);
Appartment bb("Appartment",200,5, 220,300);
House cc("House",200,6,500);
House dd("House",150,4,270);
Appartment ee("Appartment",120,3, 100,100);

Accommodation *All[5]={&aa,&bb,&cc,&dd,&ee};

//Dynamically assigning 5 instance memory of Location             		   	
Location *A=new Location ("Sulaymaniyah" , "Slemani" ,"Baxan street",22,2);
Location *B=new Location ("Sulaymaniyah" , "Slemani" ,"IbrahemAhmad street",34,5);
Location *C=new Location ("Sulaymaniyah" , "Slemani" ,"Ashti Street",27,5);
Location *D=new	Location ("Sulaymaniyah" , "Slemani" ,"Kwrsat street",99,8);
Location *E=new Location ("Sulaymaniyah" , "Slemani" ,"Salm street",79,88);
//Assign each element of array for setAccommodationAddress
All[0]->setAccommodationAddress(A);
All[1]->setAccommodationAddress(B);
All[2]->setAccommodationAddress(C);
All[3]->setAccommodationAddress(D);
All[4]->setAccommodationAddress(E);

//Dynamically assigning 5 instance memory of Contract 
Contract *Z=new Contract("006","7 Months","Rental Agreement");
Contract *Y=new Contract("007","4 Months","Rental Agreement");
Contract *X=new Contract("008","11 Months","Rental Agreement");
Contract *V=new Contract("009","2 Years","Rental Agreement");
Contract *P=new Contract("010","1 Year","Rental Agreement");
//Assign each element of array for setAccommodationContract
All[0]->setAccommodationContract(Z);
All[1]->setAccommodationContract(Z);
All[2]->setAccommodationContract(Z);
All[3]->setAccommodationContract(Z);
All[4]->setAccommodationContract(Z);

Contract Client;//object of Contract	
	int choice=0;
	while (choice != 3){
    choice = menu();
    //Respond to the menu according to your choice by using Switch.
	switch(choice)
	{
	case 1:
		cout<<"\n\nCurrently We have 5 Roommates available. \n";
		//Using For Loop to display Rommmates
		for (int i=0;i<5;i++){
			cout<<endl<<(i+1)<<". ";
			//Using Operator << to dislay Array
		cout<<Array[i];				}
			
	 	cout<<"\n Choose to see Contact Information of the Roommate that you want: \n";
	 	int n;
	 	//Enter your Choice
	 	cin>>n;
		Array[n-1].printContactinfo();
		cout<<endl;
		//Display Information using if statement
		if (n<3){cout<<"\nDo you want to see Accommodation Details? (Y/N)";
		char u;
		cin>>u;
		if(u=='Y' || u=='y'){Array[n-1].showRent();} }
		
		cout<<"\nDo you want to see Contract Details? (Y/N)";
		char u;
		cin>>u;
		if(u=='Y' || u=='y'){Array[n-1].printContractinfo(); 
		cout<<"\nDo you want to sign this Contract?(Y/N) ";
		cin>>u;
		if(u=='Y' || u=='y'){cin>>Client;	}}
		
	//Diplay all the information you have chosen	
cout<<"\n\nDo you want to see all information of the Roommate you have choosen? (Y/N)";
		cin>>u;
		if(u=='Y' || u=='y'){
		cout<<"\n\n"<<Array[n-1]; 
		Array[n-1].printContactinfo();
		cout<<"\n";
		if (n<3 ){ 
		Array[n-1].showRent();cout<<"\n";
		Array[n-1].printContractinfo();cout<<"\n";
		}else 	Array[n-1].printContractinfo();}  
	
	break;
	
	case 2:
	cout<<"\n\nCurrently We have 5 Accommodation available to Rent \n";
		//Using For Loop to display Address of Accommodation
		for (int v=0;v<5;v++){ cout<<(v+1)<<". ";	All[v]->DisplayAddress();	}	
				
	 	cout<<"\nChoose to see Price and Details of the Accommodation that you want Rent :";
	 	int o;
	 	//Enter your Choice
	 	cin>>o;
		All[o-1]->showRentAccommodation();
		cout<<endl;
			cout<<"Do you want to see Contract Details? (Y/N)";
		char j;
		cin>>j;
		if(j=='Y' || j=='y'){All[o-1]->printContractinfo(); 
		cout<<"\nDo you want to sign this Contract?(Y/N) ";
		cin>>j;
		if(j=='Y' || j=='y'){cin>>Client;	}}
		//Display Accommodation Information
cout<<"\n\nDo you want to see all information of the Accommodation you have choosen? (Y/N)";
		char c;
		cin>>c;
		if(c=='Y' || c=='y'){
		cout<<"\n\n"; All[o-1]->DisplayAddress();cout<<endl;
		All[o-1]->showRentAccommodation();cout<<endl;
		All[o-1]->printContractinfo();}	
		
	break;
	case 3:
		//Display Output
	cout<<"Program Ending"<<endl;
	break;
	//Display Output
	default: cout<<"Invalid Choice";
	}
}
	
 return 0;
 }
