#pragma once


#include <windows.h>

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <array>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#define CENTER 8
#define SPACING 37

class Member
{
private:


string member_first, member_last, member_full;
int member_id;
bool borrowing_status; 


public:

	//********* Default Constructor *********//
	Member(void);
	//********* Overload Constructor *********//
	Member(string , string , string , int ,bool );
	//********* Default Destructor *********//
	~Member(void);

	//********* Accessor Functions *********//	

	string Get_First() const;

	string Get_Last() const;

	string Get_Full() const;

	int Get_Member_ID() const;

	bool Get_Borrowing_Status() const;

	//********* Mutator Function *********//	

	void Set_First(string);

	void Set_Last(string);

	void Set_Full(string);

	void Set_Member_ID(int);

	void Set_Borrowing_Status(bool);

	//////////////////////////////////////////////////////Add member function /////////////////////////////////////////////////////////
	void Set_Add_Member (string , string ,int ,bool );

	//**************************************** Loading Members ******************************************\\

	void Read_Member (ifstream &);


	//*********Print Function *********//
	void Print_Member();


	};

