#include "Book.h"

//Utility Functions

void Center(int);
void Clear_Screen(int);


Book::Book(void) 
{
	book_price = 0;
	book_availability = false;
	borrower_id = -1;
}


Book::Book(string in_title,string in_first,string in_last,string in_isbn,float in_price,bool in_availability,int in_id)
{
	book_title = in_title;
	author_first = in_first;
	author_last = in_last;
	author_full = in_first+" "+in_last;
	book_isbn = in_isbn;
	book_price = in_price;
	book_availability = in_availability;
	borrower_id = in_id;
}


Book::~Book(void)
{
}


	string Book::Get_Title() const 
	{return book_title;}

	string Book::Get_First() const
	{return author_first;}

	string Book::Get_Last() const
	{return author_last;}

	string Book::Get_Full() const
	{return author_full;}

	string Book::Get_ISBN() const
	{return book_isbn;}

	float Book::Get_Price() const
	{return book_price;}

	bool Book::Get_Availability() const
	{return book_availability;}

	int Book::Get_ID() const
	{return borrower_id;}


	void Book::Set_Title(string in_title)
	{book_title = in_title;}

	void Book::Set_First(string in_first)
	{author_first = in_first;}

	void Book::Set_Last(string in_last)
	{author_last = in_last;}

	void Book::Set_Full(string in_full)
	{author_full = in_full;}

	void Book::Set_ISBN(string in_isbn)
	{book_isbn = in_isbn;}

	void Book::Set_Price(float in_price)
	{book_price = in_price;}

	void Book::Set_Availability(bool in_availability)
	{book_availability = in_availability;}

	void Book::Set_ID(int in_id)
	{borrower_id = in_id;}

//////////////////////////////////////////////////////Add book function /////////////////////////////////////////////////////////
void Book::Set_Add_Book(string in_book_title,string in_author_first,string in_author_last,string in_ISBN,float in_price)
{
book_title=in_book_title;
author_full = in_author_first+" "+in_author_last;
author_first=in_author_first;
author_last=in_author_last;
book_isbn=in_ISBN;
book_price=in_price;
book_availability=1;
borrower_id = -1;
}



//**************************************** Loading Books ******************************************\\
//Read book structure/////////////////////////////////////////////////////////
void Book::Read_Book(ifstream &file_in)
{
getline(file_in,book_title);
getline(file_in,author_last,',');
file_in.ignore(10,' ');
getline(file_in,author_first);	
author_full = author_first+" "+author_last;
file_in >> book_isbn >> book_price >> book_availability >> borrower_id;
file_in.ignore(100,'\n');
}


//**************************************** Printing Books ******************************************\\
//////////////////////////////////////////////////////Print book titles function /////////////////////////////////////////////////////////
void Book::Print_Book()
{
		Clear_Screen(2);
		Center(CENTER);
		cout <<setw(30)<<"Book's title: " <<book_title<<endl;
		Center(CENTER);
		cout<<setw(30)<<"Author's full name: " << author_full<<endl;
		Center(CENTER);
		cout<<setw(30)<<"Book ISBN: " << book_isbn<<endl;
		Center(CENTER);
		cout<<setw(30)<<"Book availability: ";
		if(book_availability)
			 cout<< "Checked in." <<endl;
		else
			cout<< "Checked out." <<endl;
		Clear_Screen(2);
}