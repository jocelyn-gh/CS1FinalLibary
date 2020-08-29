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

#define RETRY 4
#define FILE_AMOUT 2
#define Book_Array 100
#define MEMBER_ARRAY 20
#define MENU_1 7
#define MENU_2 9
#define CENTER 8
#define SPACING 37

#define BASECOLOR 15 //7 Gray 15 White
#define USERCOLOR1 11 // Light Blue-teal
#define USERCOLOR2 13 // Pink ^\_/^

class Book
{


private:
	string book_title,author_full,author_first, author_last, book_isbn;
	float book_price;
	int borrower_id;
	bool book_availability;
	

public:



	//********* Default Constructor *********//
	Book(void);

	//********* Overload Constructor *********//
	Book(string ,string ,string ,string ,float ,bool ,int);


	//********* Default Destructor *********//
	~Book(void);

	//********* Accessor Functions *********//	
	string Get_Title() const;

	string Get_First() const;

	string Get_Last() const;

	string Get_Full() const;

	string Get_ISBN() const;

	float Get_Price() const;

	int Get_ID() const;

	bool Get_Availability() const;

	//********* Mutator Function *********//	

	void Set_Title(string);

	void Set_First(string);

	void Set_Last(string);

	void Set_Full(string);

	void Set_ISBN(string);

	void Set_Price(float);

	void Set_ID(int);

	void Set_Availability(bool);

	void Set_Add_Book(string,string,string,string,float);

	//**************************************** Loading Books ******************************************\\
	//Read book structure/////////////////////////////////////////////////////////
	void Read_Book (ifstream &);

	//**************************************** Printing Books ******************************************\\

	void Print_Book();
	
};

