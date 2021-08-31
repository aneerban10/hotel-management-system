#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<strings.h>

using namespace std;

///////////////////////////GLOBAL VARIABLES///////////////////////////


int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int years_difference, days_difference;
int months_total;
int reg_year = 365;
int acsgl=10,acdbl=10,acdmty=10;
int nacsgl=10,nacdbl=10,nacdmty=10;

//////////////////////////CLASS DECLARATION///////////////////////////

class hotel
{

	int room_no;
	char name[50];
	char address[100];
	char phone[10];
	int type;
	int first_day,first_month,first_year;
	int second_day,second_month,second_year;

	public:
	void main_menu();	//to display the main menu
	void add();		//to book a room
	void available();
	void display();		//to display the customer record
	void rooms();		//to display alloted rooms
	void bill();		//to make bill
	int check(int);		//to check room status
	void modify(int);	//to modify the record
	void delete_rec(int);	//to delete the record
	void delete_all();      //to delete all the records
};

///////////////////////MEMBER FUNCTIONS DETAILS//////////////////////
void hotel::main_menu()
{
	int choice;

	while(choice!=9)
	{

		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\t* MAIN MENU *";
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Book A Room";
		cout<<"\n\t\t\t2.Rooms Available";
		cout<<"\n\t\t\t3.Customer Record";
		cout<<"\n\t\t\t4.Rooms Allotted";
		cout<<"\n\t\t\t5.Modify Record";
		cout<<"\n\t\t\t6.Delete Record";
		cout<<"\n\t\t\t7.Delete ALL Records";
		cout<<"\n\t\t\t8.Make Bill";
		cout<<"\n\t\t\t9.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{

			case 1:	add();
				break;

			case 2: available();
				break;

			case 3:	display();
				break;
			case 4: rooms();
				break;
			case 5: int r;
				cout<<"\n\t\t\t\t4.Modifying Record";
				cout<<"\n\n Enter room no: ";
				cin>>r;
				modify(r);
				break;
			case 6:
				cout<<"\n\\t\t\t5.Deleting Record";
				cout<<"\n\n Enter room no: ";
				cin>>r;
				delete_rec(r);
				break;

			case 7: delete_all();
				break;

			case 8: bill();
				break;

			case 9: break;

			default: {
				  cout<<"\n\n\t\t\tWrong choice!!!";
				  cout<<"\n\t\t\tPress any key to continue!!";
				  getch();
				  }
		}
	}
}

void hotel::add()
{


	int r,flag;
	ofstream fout("Record.dat",ios::app);

	cout<<"\n\t\t\t 1.Book Room";

	cout<<"\n Enter Customer Details";
	cout<<"\n **********************";
	cout<<"\n\n Following Room No exist in this hotel";
	cout<<"\n 1. AC Singles: Room No 01 to Room No 10: Cost Rs. 150";
	cout<<"\n 2. AC Doubles: Room No 11 to Room No 20: Cost Rs. 200";
	cout<<"\n 3. AC Dormitory: Room No 21 to Room No 30: Cost Rs. 300";
	cout<<"\n 4. NON AC Singles: Room No 31 to Room No 40: Cost Rs. 50";
	cout<<"\n 5. NON AC Doubles: Room No 41 to Room No 50: Cost Rs. 100";
	cout<<"\n 6. NON AC Dormitory: Room No 51 to Room No 60: Cost Rs. 150";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);

	if(flag==1)
		cout<<"\n Sorry..!!!Room is already booked";
	else if(flag==-1)
		cout<<"\n Sorry..!!!Please Choose from given codes only";
	else
	{

			room_no=r;
			cout<<" Name: ";
			cin>>name;
			cout<<" Address: ";
			cin>>address;
			cout<<" Phone No: ";
			cin>>phone;
			if(r>50&&r<=60)
			{
			type=6;
			nacdmty--;
			}
			else if(r>40&&r<=50)
			{
			type=5;
			nacdbl--;
			}
			else if(r>30&&r<=40)
			{
			type=4;
			nacsgl--;
			}
			else if(r>20&&r<=30)
			{
			type=3;
			acdmty--;
			}
			else if(r>10&&r<=20)
			{
			type=2;
			acdbl--;
			}
			else if(r>0&&r<=10)
			{
			type=1;
			acsgl--;
			}
			cout<<"\nEnter Date of Entry:: "<<endl;
			cout<<"Day: ";
			cin>>first_day;
		if(first_day > 31 || first_day <= 0)
		{
			cout<<"Incorrect day entered"<<endl;
			cin.ignore();

		}
		cout<<"Month: ";
		cin>>first_month;
		if(first_month > 12 || first_month <= 0)
		{
			cout<<"Incorrect Month entered"<<endl;
			cin.ignore();
		}
		cout<<"Year: ";
		cin>>first_year;
		if(first_year > 9999 || first_year < 0)
		  {
		cout<<"Incorrect Year Entered"<<endl;
		cin.ignore();
		  }


			  cout<<"Type is: "<<type;
			fout.write((char*)this,sizeof(hotel));
			cout<<"\nRoom is booked!!!";



	}
	cout<<"\nPress any key to continue!!";
	getch();
	fout.close();
}

void hotel::available()
{

	int totac=acsgl+acdbl+acdmty;
	int totnac=nacsgl+nacdbl+nacdmty;

	cout<<"\n\nNo of AC Rooms Available: "<<totac;
	cout<<"\n\t1. Single: "<<acsgl;
	cout<<"\n\t2. Double: "<<acdbl;
	cout<<"\n\t3. Dormitory: "<<acdmty;
	cout<<"\n\nNo of Non AC Rooms Available: "<<totnac;
	cout<<"\n\t1. Single: "<<nacsgl;
	cout<<"\n\t2. Double: "<<nacdbl;
	cout<<"\n\t3. Dormitory: "<<nacdmty;
	cout<<"\n\n\n\t\t\tPress any key to continue!!";
	getch();

}
void hotel::display()
{


	ifstream fin("Record.dat",ios::in);
	int r,flag;
	cout<<"\n\t\t\t 2.Customer Record";
	cout<<"\n\n Enter room no: ";
	cin>>r;

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Customer Details";
			cout<<"\n ****************";
			cout<<"\n\n Room no: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			cout<<"\n Date of Entry: ";
			cout<<first_day<<"."<<first_month<<"."<<first_year;
			cout<<"\n Type of Room: ";
			cout<<type;
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant!!";

	cout<<"\n Press any key to continue!!";
	getch();
	fin.close();

}

void hotel::rooms()
{


	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t3. Rooms Allotted";
	cout<<"\n\t\t\t**************************";

	 cout<<"\n\n Room No.";
	 cout<<setw(12)<<"Name";
	 cout<<setw(22)<<"Address";
	 cout<<setw(22)<<"Phone No";
	fin.read((char*)this,sizeof(hotel));
	while(!fin.eof())
	{



		cout<<"\n\n";
		cout<<room_no<<setw(20)<<name<<setw(22)<<address<<setw(22)<<phone;
	  fin.read((char*)this,sizeof(hotel));
	}


	cout<<"\n\n\n\t\t\tPress any key to continue!!";
	getch();
	fin.close();
}

int hotel::check(int r)
{
	int flag=0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(r>0&&r<=60)
		{

			if(room_no==r)
			{
			flag=1;
			break;
			}
		}
		else
		{
			cout<<"\nSelect from room no 1-60";
			flag=-1;
			break;
		}
	}

	fin.close();
	return(flag);
}

void hotel::modify(int r)
{


	long pos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);

	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{

			int change;
			char more;

			int newday,newmonth,newyear;

	    do{

			cout<<"\n\n 1.Name";
			cout<<"\n 2.Address";
			cout<<"\n 3.Phone ";
			cout<<"\n 4.No change";

			cout<<"\n What do you want to edit:  ";

			  cin>>change;
			 switch(change)
			{


			      case 1: cout<<"\n Enter the new name: ";
				       gets(name);
					  break;
			       case 2: cout<<"\n Enter new Address: ";
				       gets(address);
					  break;
			       case 3: cout<<"\n Enter new Phone No.:  ";
				       gets(phone);
					  break;
			       case 4: break;

			       default: cout<<"please enter from 1 or 2 or 3";
			 }
			   cout<<"\n do you want to change any other details(y/n)";
			  cin>>more;

		 }while(more=='y'||more=='Y');


			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Record is modified!!";
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant!!";

	file.close();
}

void hotel::delete_rec(int r)
{

	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone No: "<<phone;
			cout<<"\n Type: "<<type;
			cout<<"\n Do you want to delete this record(y/n): ";
			cin>>ch;

			if(ch=='n')
			fout.write((char*)this,sizeof(hotel));

			if(type==1)
			acsgl++;
			else if(type==2)
			acdbl++;
			else if(type==3)
			acdmty++;
			else if(type==4)
			nacsgl++;
			else if(type==5)
			nacdbl++;
			else if(type==6)
			nacdmty++;
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(hotel));
	}

	fin.close();
	fout.close();

	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant!!";
	else
	{
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
}

void hotel::delete_all()
{
	ofstream Del;
	char sure;
	cout<<"\n\t\t\t 6.Deleting All Records";
	cout<<"\n\n Are You Sure To DELETE ALL RECORDS: ";
	cin>>sure;
	if(sure=='y'||sure=='Y')
	{
	Del.open("Record.dat",ios::out|ios::trunc);
	acsgl=10,acdbl=10,acdmty=10,nacsgl=10,nacdbl=10,nacdmty=10;
	cout<<"ALL Records Deleted";
	getch();
	}
	else
	{
	cout<<"No Records Deleted";
	getch();
	}
}
void hotel::bill()
{

	ifstream fin("Record.dat",ios::in);
	int r,flag;
	cout<<"\n\t\t\t\t7.Bill";
	cout<<"\nEnter room no: ";
	cin>>r;

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{

			cout<<"\n\n Customer Details";
			cout<<"\n ****************";
			cout<<"\n\n Room no: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			cout<<"\n Type of Room is: "<<type;
			cout<<"\n Date of Entry";
			cout<<first_day<<"."<<first_month<<"."<<first_year;

		    cout<<"\n Enter Day of Exit:: \n";

		    cout<<" Day: ";
		    cin>>second_day;
		    if(second_day > 31 || second_day <= 0)
		  {
			cout<<"Incorrect day entered"<<endl;
			cin.ignore();

		  }
		    cout<<" Month: ";
		    cin>>second_month;
		    if(second_month > 12 || second_month <= 0)
		  {
			cout<<"Incorrect Month entered"<<endl;
			cin.ignore();
		  }
		    cout<<" Year: ";
		    cin>>second_year;
		    if(second_year > 9999 || second_year < 0)
		    {
			cout<<"Incorrect Year Entered"<<endl;
			cin.ignore();
		    }
				//Years//

	if(first_year == second_year)
	{
	    years_difference = 0;
	}
	else
	{
	    if(first_year % 4 == 0 && first_year % 100 != 0 || first_year % 400 == 0)
	      {
		 if(second_year % 4 == 0 && second_year % 100 != 0 || second_year % 400 == 0)			{
			if(first_year > second_year)
				{
				years_difference = (first_year - second_year) * (reg_year) + 2;
				}
				else
				{
				years_difference = (second_year - first_year) * (reg_year) + 2;
				}
				if(second_month > first_month)
				{
				if(days_in_months[first_month - 1] > days_in_months[1])
					{
					--years_difference;
					}
				}
			}
			else
			{
				if(first_year > second_year)
				{
					years_difference = (first_year - second_year) * (reg_year) + 1;
				}
				else
				{
					years_difference = (second_year - first_year) * (reg_year) + 1;
				}
				if(first_month > second_month)
				{
					if(days_in_months[second_month - 1] > days_in_months[1])
					{
						--years_difference;
					}
				}
			}
		}
		else
		{
			if(first_year > second_year)
			{
				years_difference = (first_year - second_year) * (reg_year);
			}
			else
			{
				years_difference = (second_year - first_year) * (reg_year);
			}
		}
	}

				//Months//

	if(first_month == second_month)
	{
		months_total = 0;
	}
	else
	{
		if(first_month > second_month)
		{
			for(int i = (first_month - 1); i > (second_month - 1); i--)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
		else
		{
			for(int i = (first_month - 1); i < (second_month - 1); i++)
			{
				static int months_total_temp = 0;
				months_total_temp += days_in_months[i];
				months_total = months_total_temp;
			}
		}
	}

				//Days//

	int days_total;

	if (first_day == second_day)
	{
		days_difference = 0;
		days_total = (years_difference + months_total) - days_difference;
	}
	else
	{
		if(first_day > second_day)
		{
			days_difference = first_day - second_day;
			days_total = (years_difference + months_total) - days_difference;
		}
		else
		{
			days_difference = second_day - first_day;
			days_total = (years_difference + months_total) + days_difference;
		}
	}

				//In Between Leap Years//

	if(first_year == second_year)
	{
	}
	else
	{
		if(first_year > second_year)
		{
			for(int i = (second_year + 1); i < first_year; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout<<endl;
					cout<<i<<endl;
					++days_total;
				}
			}
		}
		else
		{
			for(int i = (first_year + 1); i < second_year; i++)
			{
				if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
				{
					cout<<endl;
					cout<<i<<endl;
					++days_total;
				}
			}
		}
	}

	double final=0;
	cout<<"\n\n\t\t\t       *****BILL*****\n\n";
	cout<<"*******************************************************************************";
	cout<<"\n\n Total Days: "<<days_total<<endl;


	cout<<"\n\n THE COST BEFORE ANY DISCOUNT IS: Rs. ";

		fin.read((char*)this,sizeof(hotel));
	switch(type)
	{
	case 1: final=150*days_total;
		cout<<final;
		cout<<"\n\n";
		break;
	case 2: final=200*days_total;
		cout<<final;
		cout<<"\n\n";
		break;
	case 3: final=300*days_total;
		cout<<final;
		cout<<"\n\n";
		break;
	case 4: final=50*days_total;
		cout<<final;
		cout<<"\n\n";
		break;
	case 5: final=10*days_total;
		cout<<final;
		cout<<"\n\n";
		break;
	case 6: final=150*days_total;
		cout<<final;

		cout<<"\n\n";
		break;
	default:break;
	}

	cout<<"\n The discount on your stay is as follows";
	cout<<"\n More than 100 days- 5% ";
	cout<<"\n More than 200 days- 10% ";
	cout<<"\n More than 300 days- 20% ";

	cout<<"\n The Finalised cost after your discount is: Rs ";

	if(days_total>=300)
	cout<<final-(0.2*final);
	else if(days_total>=200)
	cout<<final-(0.1*final);
	else if(days_total>=100)
	cout<<final-(0.05*final);
	else
	cout<<final;

			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant!!";

	cout<<"\n Press any key to continue!!";
	getch();
	fin.close();

}
int main()
{
	hotel h;
	cout<<"\n\t\t\t****************************";
	cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
	cout<<"\n\t\t\t****************************";
	cout<<"\n\n\t\t Made By:";
	cout<<"ANSHUMAN SAHOO AND ANEERBAN CHOWDHURY";
	cout<<"\n\n\t\t\t Press any key to continue!!";
	getch();
	h.main_menu();

	return 0;

 }

