#include "Member.h"

void Center(int);
void Clear_Screen(int);

Member::Member(void)
{
member_id = 0;
borrowing_status = 0;
}

Member::Member(string in_first, string in_last, string in_full, int in_id,bool in_bs)
{
member_first = in_first;
member_last = in_last;
member_full = in_full;
member_id = in_id;
borrowing_status = in_bs;
}

Member::~Member(void)
{
}

	string Member::Get_First() const
	{return member_first;}

	string Member::Get_Last() const
	{return member_last;}

	string Member::Get_Full() const
	{return member_full;}

	bool Member::Get_Borrowing_Status() const
	{return borrowing_status;}

	int Member::Get_Member_ID() const
	{return member_id;}

	void Member::Set_First(string in_first)
	{member_first = in_first;}

	void Member::Set_Last(string in_last)
	{member_last = in_last;}

	void Member::Set_Full(string in_full)
	{member_full = in_full;}

	void Member::Set_Borrowing_Status(bool in_borrowing_status)
	{borrowing_status = borrowing_status;}

	void Member::Set_Member_ID(int in_id)
	{member_id = in_id;}




	void Member::Set_Add_Member (string first_name, string last_name ,int ID,bool borrowing)
	{
		member_full = first_name+" "+last_name;
		member_first = first_name;
		member_last = last_name;
		member_id = ID;
		borrowing_status = borrowing;
	}



//Read member structure/////////////////////////////////////////////////////////
void Member::Read_Member (ifstream &file_in)
{
getline(file_in,member_last,',');
file_in.ignore(10,' ');
getline(file_in,member_first);
file_in >> member_id;
file_in >> borrowing_status;
member_full = member_first+" "+member_last;
file_in.ignore(100,'\n');
}



//////////////////////////////////////////////////////Print member details function /////////////////////////////////////////////////////////
void Member::Print_Member()
{
		Clear_Screen(2);
		Center(CENTER);
		cout <<setw(30)<<"Member full name: " << member_full <<endl;
		Center(CENTER);
		cout<<setw(30)<<"Member first and mittle name: " << member_first<<endl;
		Center(CENTER);
		cout<<setw(30)<<"Member last name: " << member_last<<endl;
		Center(CENTER);
		cout<<setw(30)<<"Member member id: " << member_id<<endl;
		Center(CENTER);
		cout<<setw(30)<<"Member borrowing status: " << borrowing_status<<endl;
		Clear_Screen(2);
}