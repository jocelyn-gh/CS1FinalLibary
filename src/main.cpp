

/*---------------------------------------------------*
~ Programmer : 	Jocelyn          				    ~
~ Course     : 	Computer Science 101    			~
~ Fnished   : 	Thursday 12/13/12					~
\*---------------------------------------------------*

                -'''''-.
             .'      #  `.
            :             :
           :   #           :
           :      _/|      :
            :   =/_/   #  :
             `._/ |     .'
           (   /  ,|...-'
            \_/^\/||   
            _/~  `''~`` `_
     __/  -'/  --._ |'__
   /________/--  -` ~|'


				//Program statement\\
			*library management system*

--------------------------------------------------------------
simple library management system to manage books, members and provide library services.
--------------------------------------------------------------




////////////////////////////////////////////////////////////////////////////////////////////
Loading data///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
At the start of the program load the data, list of books and members, from 2 files. 
Prompt user the file name that contains the member’s information and store them into an array of member info structure, 
and then prompt for the file name containing the data for the library book book.



				Member file Format							Sample

				Last, First Name							Smith, John Adam
				Member ID borrowing status					123456 0
				Last, First Name							Winston Jr., James
				Member ID borrowing status					123457 1




				Book file								Sample

				Title of book								Story of Mars
				Author										Hanson, James 
				ISBN Price 									123A2345V 12.50 
				Availability	Member ID					1 -1			
			
				Title of book								Home of the Warrior
				Author										Johnsen, Nancy
				ISBN Price									144R3333G 21.75
				Availability	Member ID					0 123457	


////////////////////////////////////////////////////////////////////////////////////////////
Menu///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
Once the data is loaded then display a sign in screen to display the following menu options

1) Search the member list for a member (prompt for member’s last name)
2) Register a new members (add them to member list)
3) Remove a member from the member list
4) Add more books to the book from a data file
5) Remove books from book list
6) Exit (Quit the program and update both member file and book file)


The service menu will have the following options:
1) Request to borrow a book
2) Return a book
3) Request to transfer a book from another library
4) Print a list of available books to borrow
5) Print a alphabetically sorted list of library book (Title)
6) Print the details of a book (Prompt user for the title)
7) Print titles of books by an author(prompt user for author’s last name)
8) Donate books to the library (add them to the book list)
9) Exit (return to the sign in screen)		

////////////////////////////////////////////////////////////////////////////////////////////
Functions//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\Utility Functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

		(Ask_File_Name)
			i) Ask for file name of X type
			ii) return changed name with .txt

		(Open_Check_File)
			i) Open file
			ii) Check if file is there or not
			iii) Return true or false

		(Split_Full_String)
		i)   Take full word
		ii)  find ","
		iii) Left string is last word
		iv)  Right sting is first word
		v)   return both first and last word.


		(Find_String_Array)
			i)  Loop though array intell the inputed name and the targeted name are equal.
			ii) Retrun True if member is found, false if not.

		(Ckeck_Room_Array)
			i)  Check if there is room to add
			ii) Retrun True if there is room, return false if not.

		(Yes_No_Check)
			i)  Ask if user Y or N.
			ii) Retrun true if Y, return false if N.

		(Set_Add_Book)
			i)   Prompt user the Title of book.
			ii)  Prompt user the Author.
			iii) Prompt user the ISBN Price.
			iv)  Prompt user the Availability.
			v)   Borrower Id will default 0.


		(Add_String_To_Array)
			i)	 Run (Check_String)
			ii)  Run (Find_String_Array)
			iii) Add to the last avaiable spot of array.

		(Remove_Structure_From_Array)
			i)	 Run (Check_String)
			ii)	 Run (Find_String_Array)
			iii) Replace target string with "".

		(Check_Borrowing_Status)
			i) In a loop, check the borrowing status of member loged in.

		(Check_Availability)
			i) In a loop, check the availability of the book.

		(Print_Book_Array)
			i) In a loop, print the Detals of all the books in the array for each index.

		(Available_Books)
			a)Run (Check_Borrowing_Status)
			b)Transfur book into new array
			c)Stop loop when the array is reached, return size of new array

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\loading Functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


		(Read_Member_Temp)Read file and write the structure in to the member structure array from ther file.
			i) Get Full Author's name
				a) Run (Split_Full_String)	
			ii) Get Member Id and borrowing status
								
		(Read_File_Into_Member_Structure_Array)
			i) Run (Read_Member_Temp)
			ii) Close file

		(Read_Book) Read file and write put the structure in to the book structure array from ther file.
			i)  Get Title of book
			ii) Get Full Author's name
				a) Run (Split_Full_String)					
			iii)Get ISBN, Price, Availability, and Borrower Id


		(Read_File_Into_Book_Structure_Array) 
			i)  Run (Read_Book)
			ii) Close file
		
		(Print_Member_Array_Into_File)
			i) In a loop, print the structure in to file from the array.

		(Print_Book_Into_File)
			i) In a loop, print the structure in to file from the array.





\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\Menu 1 Functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
1) Log in as member
2) Register a new members (add them to member list)
3) Search the member list for a member (prompt for member’s last name)
4) Remove a member from the member list
5) Add more books to the book from a data file
6) Remove books from book list
7) Exit (Quit the program and update both member file and book file)
/////////////////////////////////////////////////////////////////////////////
	(Print_Collie_Menu1)
		i) Print menu 1

	Menu1_Login) Search the member list for a member. 
		i)  Prompt user the member’s name.
		ii) Run (Find_String_Array)
			a)retry if fail (4 retrys)
		iii)  Prompt user the member’s ID.
		iv) Run (Find_String_Array)
			a)retry if fail (4 retrys)

	Menu1_Register_Member) Register a new members (add them to member list).
		i)   Prompt user the member’s first and last name to add.
		ii)  Run (Add_Member_Structure_From_Array) ( SwiftPaw, Gry)

function-> Menu1_Search_Member) Search the member list for a member. 
		i)  Prompt user the member’s name.
		ii) Run (Find_String_Array)

	Menu1_Remove_Member) Remove a member from the member list.
		i)   Prompt user the member’s name to remove.
		ii)  Run (Double_Check)
		iii) Run (Remove_Member_Structure_From_Array)


	Menu1_Add_Book) Add more books to the book from a data file.
		i)		Run (Set_Add_Book)
		ii)		Run	(Ckeck_Room_Array)
		iii)	Run (Add_Book_Structure_From_Array)


	Menu1_Remove_Book) Remove books from book list.
		i)   Prompt user the book’s name to remove.
		ii)  Run (Double_Check)
		iii) Run (Remove_Book_Structure_From_Array)

	Menu1_Update_Exit) Exit (Quit the program and update both member file and book file).
		i)	 Run (Open_Check_File)				[member file]
		ii)  Run (Print_Member_Array_Into_File) [member file]
		iii) Run (Open_Check_File)				[book file]
		iv)  Run (Print_Book_Into_File)	[book file]
		v)	 Print a nice goodbye messge
		vi)  Run (Collie_Tag)
		vii) Exit program




\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\Menu 2 Functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ 
1) Borrow a book
2) Return a book
3) Request to transfer a book from another library
4) Print a list of available books to borrow
5) Print a alphabetically sorted list of library book (Title)
6) Print the details of a book (Prompt user for the title)
7) Print titles of books by an author(prompt user for author’s last name)
8) Donate books to the library (add them to the book list)
9) Exit (return to the sign in screen)
/////////////////////////////////////////////////////////////////////////////

	(Print_Collie_Menu2)
		i) Print menu 2

	Menu2_Borrow_Book) Search the member list for a member. 
		i)  Prompt user the books’s title.
		ii) Run (Find_String_Array)
		iii) Run (Check_Borrowing_Status)
		iv) Run(Check_Availability)
		v)  Change bool of the book to 0

	Menu2_Return_Book) Search the member list for a member. 
		i)  Prompt user the books’s title.
		ii) Run (Find_String_Array)
		iii) Run (Check_Borrowing_Status)
		iv) Run (Check_Availability)
		v)  Change bool of the book to 1

	Menu2_Transfer_Book) Request to transfer a book from another library
		i)    Prompt user the books’s title.
		ii)   Run (Find_String_Array)						(Old Libary)
		iii)  Promp user for file name of libary.
		vi)   Run (Open_Check_File)							(Old Libary)
		v)    Run (Read_Book)					(NewLibary)
		vi)   Run (Find_String_Array)						(NewLibary)
		vii)  Run (Add_Book_Structure_From_Array)		(Old Libary)
		viii) Run (Remove_Book_Structure_From_Array)	(NewLibary)
		viv)  Run (Print_Book_Into_File)				(NewLibary)

	Menu2_Print_Book_List) Print a list of available books to borrow
		i)	 Run (Available_Books)
		ii)  Run (Sort_Book_Array_Alp)
		iii) Run (Print_Book_Array)

	Menu2_Print_Alp_Book_List) Print a alphabetically sorted list of library book (Title)
		i)  Run (Sort_Book_Array_Alp)
		ii) Run (Print_Book_Array)

	Menu2_) Print the details of a book (Prompt user for the title)
		i)   Run (Find_String_Array)
		iii) Run (Print_Book_Array)

	Menu2_) Print titles of books by an author(prompt user for author’s last name)
		i)  Run (Sort_Book_Array_Alp)
		ii) Run (Print_Book_Array)

	Menu2_) Donate books to the library (add them to the book list)
		i)   Prompt user how many books to add.
		ii)	 In a loop
			a)Run Add(Book
			b)Run (Add_Book_Structure_From_Array)

	Menu2_Back_Menu) Exit (return to the sign in screen)
		i)  Run (Yes_No_Check)
		ii) Retrn False

////////////////////////////////////////////////////////////////////////////////////////////
MAIN///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


I) Run Welcome sign logo 
	a) Run Print_Collie_Sig()

II)	Load in files, run Load_Files()

III) In a loop that makes at least one loop first,
	a) Run Menu_1_Main()
		i)  if returns true
		ii) if returns false close loop
	b) Run Menu_2_Main()

VI) Exit


--------------------------------------------------------------
*/





//Header
#include <windows.h>

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <array>
#include <fstream>
#include <vector>
#include <sstream>

#include "Book.h"
#include "Member.h"


using namespace std;


#define RETRY 4
#define MENU_1 7
#define MENU_2 9
#define CENTER 8
#define SPACING 37

#define BASECOLOR 15 //7 Gray 15 White
#define USERCOLOR1 11 // Light Blue-teal
#define USERCOLOR2 13 // Pink ^\_/^


///Function Prototypes//////////////

//Utility Functions
bool Check_Int_Cin(int &);
bool Check_Float_Cin(float &);
bool Check_Float_Char(char &);

void Sub_Retry(int &);
void Clear_Screen(int);
bool Check_Member_Full_Name_ID(int , string, vector<Member> &);
bool Check_Member_Infromation (vector<Member> & ,string &, int &);

void Ask_File_Name(string &);
bool Open_Check_File(ifstream &, string);
bool Ask_Yes_No_Check();
int Get_Member_Full_Name(string ,Member );
int Get_Num_array(int ,vector<int>);
int Select_Book(vector<Book> & ,string, int &);
int Find_Member_Full_Name_ID(string ,Member ,int );
int Find_Member_ID_Index(int ,Member ,int );
int Assign_Member_ID(vector<Member> & ,int);
string Get_Lowercase_String (string );
string Get_ID_Member_Full_Name(int , vector<Member> & ,int);

void B_Sort_Member_ID(vector<Member> &);
void B_Sort_Book_Any(vector<Book> & ,int );

void Center(int);
void Print_Decale_One(int ,string ,char ,string ,int );
void Print_Collie_Sig();
void Print_Books(vector<Book> & ,int );
void Print_Available_Books (vector<Book> & ,int );
bool Print_Book_Titles_Author_Last(vector<Book> & ,int ,string );
bool Print_Books_Title(vector<Book> & ,int ,string );


bool Check_book_ISBN (int,vector<Book> &);
//bool Check_Book_Availability(vector<Book> & );

//Loading Functions
void Load_Files (ifstream &file_in,vector<string> &file_name_vec,vector<Member> & member_vec,vector<Book> & book_vec);
void Read_File_Into_Member_Structure_Array(ifstream &, vector<Member> &);
void Print_Member_Into_File(ofstream &,vector<Member> &);
void Read_File_Into_Book_Structure_Array (ifstream &, vector<Book> &);
void Print_Book_Into_File(ofstream & , vector<Book> &);
void Read_Add_File_Into_Book_Structure_Array (ifstream &, vector<Book> &);

//Menu 1 Functions
void Print_Collie_Menu1();
bool Menu_1_Main (vector<Member> & ,vector<Book> & ,string &,vector<string> &,ofstream &);
bool Menu1_Login (vector<Member> & , string &);
bool Menu1_Register_Member(vector<Member> &);
bool Add_Books_File (vector<Book> &);
void Menu1_Search (vector<Member> &);
bool Menu1_Remove_Member (vector<Member> &);
bool Menu1_Update_Exit(vector<string> &,vector<Member> & ,vector<Book> & ,ofstream &);
bool Menu1_Remove_Book (vector<Book> & ,vector<Member> &);

//Menu 2 Functions
void Print_Collie_Menu2 (string);
void Menu_2_Main (vector<Member> & ,vector<Book> & ,string ,vector<string> &);
void Menu2_Borrow_Book(vector<Book> & book_vec,vector<Member> & member_vec,int loged_in_member_ID,int loged_in_index);
void Menu2_Return_Book(vector<Book> & book_vec,vector<Member> & member_vec,int loged_in_member_ID,int loged_in_index);
void Add_Book_Library2_File (vector<Book> &  ,string );
bool Menu2_Print_Books_Alpha_Title(vector<Book> &);
void Menu2_Print_Book_Title(vector<Book> &);

void Menu2_Print_Books_Author_Last(vector<Book> &);
void Menu2_Add_Books (vector<Book> &);

/////////////////////////////////////



	  //*********************************************************************************************\\
	 //**************************************** Main function ****************************************\\
	//*************************************************************************************************\\



int main()
{



//Normal
string file_name, loged_in_member;
ifstream file_in; 
ofstream file_out;
bool pass=true;


//Arrays
vector<string> file_name_vec;
vector<Member> member_vec;
vector<Book> book_vec;




////////////////////////////////////////////////////////
//////Main Code////////////////////////////////////////
//////////////////////////////////////////////////////
cout<<left;

	
Print_Collie_Sig();

Load_Files (file_in,file_name_vec,member_vec,book_vec);


do{
	pass = Menu_1_Main (member_vec,book_vec,loged_in_member,file_name_vec,file_out);
	if(pass)
	{
		Menu_2_Main (member_vec,book_vec,loged_in_member,file_name_vec);
	}
}while(pass);


return 0;
}




	  //***************************************************************************************************\\
	 //**************************************** Utility Functions ******************************************\\
	//*******************************************************************************************************\\

////////////////////////////////////////////////////// Check cin function /////////////////////////////////////////////////////////
bool Check_Int_Cin(int &input_int)
{
string string_temp;
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin, string_temp);
SetConsoleTextAttribute(hConsole, BASECOLOR);

stringstream myStream(string_temp);
if (myStream >> input_int)
	return false;

Clear_Screen(2);
Center(CENTER);
cout << "Bad input, integers only." << endl;
return true;
}

////////////////////////////////////////////////////// Check cin function /////////////////////////////////////////////////////////
bool Check_Float_Cin(float &input_int)
{
string string_temp;
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin, string_temp);
SetConsoleTextAttribute(hConsole, BASECOLOR);

stringstream myStream(string_temp);
if (myStream >> input_int)
	return false;

Clear_Screen(2);
Center(CENTER);
cout << "Bad input, integers only." << endl;
return true;
}

////////////////////////////////////////////////////// Check cin function /////////////////////////////////////////////////////////
bool Check_Float_Char(char &in_char)
{
string string_temp;
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin, string_temp);
SetConsoleTextAttribute(hConsole, BASECOLOR);

if (string_temp.length() == 1)
{
	in_char = string_temp[0];
	return false;
}

Clear_Screen(2);
Center(CENTER);
cout << "Bad input, characters only." << endl;
return true;
}



////////////////////////////////////////////////////// Center function /////////////////////////////////////////////////////////
void Center(int wall_spacing)
{
cout << setw(wall_spacing)<<"";
}

////////////////////////////////////////////////////// Print Decale one function /////////////////////////////////////////////////////////
void Print_Decale_One(int wall_spacing, string start, char fill, string end, int length)
{

cout << setw(wall_spacing)<<""<< setw(length) << setfill(fill) << start << end << setfill(' ') << endl;
}

////////////////////////////////////////////////////// Retry function /////////////////////////////////////////////////////////
void Sub_Retry(int &retrys)
{
Center(CENTER);
cout << "You have " << retrys << " many retrys left, please try again.";
Clear_Screen(2);
retrys--;
}

////////////////////////////////////////////////////// Clear screen function /////////////////////////////////////////////////////////
void Clear_Screen(int ammout)
{	
cout << string(ammout, '\n');	
}
////////////////////////////////////////////////////// Ask File Name function /////////////////////////////////////////////////////////
void Ask_File_Name(string &file_name)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		getline(cin, file_name);
		SetConsoleTextAttribute(hConsole, BASECOLOR);
			
			file_name = file_name+".txt";
}

////////////////////////////////////////////////////// Open and check file function /////////////////////////////////////////////////////////
bool Open_Check_File(ifstream &file_in, string fileName)
{

file_in.open(fileName.c_str());

if(file_in.fail())
{
	Center(CENTER);
	cout << "file : " << fileName << " was not there." << endl;
	file_in.close();
	return false;
}
else
{
	Center(CENTER);
	cout << "file : " << fileName << " was opned." << endl;
	return true;
}

}


////////////////////////////////////////////////////// Split full name function /////////////////////////////////////////////////////////
void Split_Full_String(string &full_string, string &first_string, string &last_string)
{
int separator;

separator = full_string.find(", ");
first_string = full_string.substr(separator+2,50);
last_string  = full_string.substr(0,separator);
full_string = first_string+" "+last_string;
}

////////////////////////////////////////////////////// Ask Yes No function /////////////////////////////////////////////////////////
bool Ask_Yes_No_Check()
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors
char yes_no;
bool repeat = true;

	do{
		cout << "<Y/N> :";
		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		Check_Float_Char(yes_no);
		SetConsoleTextAttribute(hConsole, BASECOLOR);
		switch(yes_no)
		{
		case'y':
		case'Y':
			return true;

		case'n':
		case'N':
			return false;

		default:
			Center(CENTER);
			cout << "You didn't hit Y or N"<<endl;
			Center(CENTER);
			cout << "but Collie Tech would like you to retry. : ";
			repeat = true;
			break;
		}
	}while(repeat);

SetConsoleTextAttribute(hConsole, USERCOLOR2);
cout << "Error"<<endl;
SetConsoleTextAttribute(hConsole, BASECOLOR);

return false;
}


////////////////////////////////////////////////////// Check Nummber Array function /////////////////////////////////////////////////////////
int Get_Num_array(int in_num,vector<int> num_vec)
{
int found=0,size=num_vec.capacity();
for(int i=0; i<size; i++)
{
	if(in_num == num_vec[i])
		found++;
}
return found;
}

////////////////////////////////////////////////////// Check Member Full Name function /////////////////////////////////////////////////////////
int Get_Member_Full_Name(string in_string, vector<Member> & member_vec)
{
int found=0,size = member_vec.size();
for(int i=0; i<size; i++)
{
	if(Get_Lowercase_String(in_string) == Get_Lowercase_String(member_vec[i].Get_Full()))
		found++;
}
return found;
}

////////////////////////////////////////////////////// Select Book function /////////////////////////////////////////////////////////
int Select_Book(vector<Book> & book_vec,string book_title,int &index)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors


int j=0,size = book_vec.size();
vector<int> indexA;


	
	for (int i=0 ; i<size; i++)
	{
	
		if(Get_Lowercase_String(book_title) == Get_Lowercase_String(book_vec[i].Get_Title()))
		{	
			Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
			Center(CENTER);
			cout <<setw(30)<<"Book Index: " <<i<<endl;
			book_vec[i].Print_Book();
			indexA.push_back(i);
			index = i;
			j++;
		}
	}

	Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
	if(j==0)
	{
		Center(CENTER);
		cout << "No books found."<<endl;
		return -1;
	}
			if(j>1)
			{
				Center(CENTER);
				cout << "Pick a book: ";
				
				if(Check_Int_Cin(index))
					return -1;
				else if(!Get_Num_array(index,indexA))
				{
					Center(CENTER);
					cout << "no book slected."<<endl;
					return -1;
				}
			}
			if(!book_vec[index].Get_Availability())
			{
				
				Center(CENTER);
				cout << book_vec[index].Get_Title() <<" is being barrowed."<<endl<<endl;
				return -1;
			}
return index;
}
/*
////////////////////////////////////////////////////// Check Book Availability function /////////////////////////////////////////////////////////
bool Check_Book_Availability(vector<Book> & book_vec)
{
if(!book_vec.capacity())
{
	Center(CENTER); cout << "There is no books in the libary."<<endl;
	return true;
}
return false;
}
*/
////////////////////////////////////////////////////// Find Member ID from Full Name  function /////////////////////////////////////////////////////////
int Find_Member_Full_Name_ID(string in_string, vector<Member> & member_vec)
{
int size = member_vec.size();
for(int i=0; size; i++)
{
	if(Get_Lowercase_String(in_string) == Get_Lowercase_String(member_vec[i].Get_Full()))
			return member_vec[i].Get_Member_ID();
}
return -1;
}

////////////////////////////////////////////////////// Find Member Full Name from ID function /////////////////////////////////////////////////////////
string Get_ID_Member_Full_Name(int ID, vector<Member> & member_vec)
{
int size = member_vec.size();
for(int i=0; size; i++)
{
	if(ID == member_vec[i].Get_Member_ID())
			return member_vec[i].Get_Full();
}
return "";
}

////////////////////////////////////////////////////// Find Member Index from ID function /////////////////////////////////////////////////////////
int Find_Member_ID_Index(int in_int, vector<Member> & member_vec)
{
int size = member_vec.size();
for(int i=0; size; i++)
{
	if(in_int == member_vec[i].Get_Member_ID())
		return i;
}
return -1;
}

////////////////////////////////////////////////////// Find Book Index from ID function /////////////////////////////////////////////////////////
int Find_Book_Member_ID_Index(int in_int,vector<Book> & book_vec)
{
int size = book_vec.size();
for(int i=0; i<size; i++)
{	
	if(in_int == book_vec[i].Get_ID())
		return i;
}
return -1;
}

////////////////////////////////////////////////////// Assign Member ID function /////////////////////////////////////////////////////////
int Assign_Member_ID(vector<Member> & member_vec)
{


int size = member_vec.size();
if(member_vec.empty())
	return 1;
else
{
	int i=0;
	while(i<(size-1) && member_vec[i].Get_Member_ID()!=0)
	{
		if(member_vec[i].Get_Member_ID() != (member_vec[i+1].Get_Member_ID())+1)
			 return member_vec[i].Get_Member_ID()-1;
		i++;
	}
}
return (member_vec[0].Get_Member_ID())+1;
}


////////////////////////////////////////////////////// Make string lower case function /////////////////////////////////////////////////////////
string Get_Lowercase_String (string in_string)
{
int size = in_string.size();
  for( int i=0 ; i < size ; ++i ) 
	  in_string[i] = tolower(in_string[i]);

return in_string;
}

////////////////////////////////////////////////////// Check Member Full Name ID function /////////////////////////////////////////////////////////
bool Check_Member_Full_Name_ID(int in_int, string in_string, vector<Member> & member_vec)
{
int size = member_vec.size();
for(int i=0; i<size; i++)
{
	if(Get_Lowercase_String(in_string) == Get_Lowercase_String(member_vec[i].Get_Full()))
		if(in_int == member_vec[i].Get_Member_ID())
			return true;
}
return false;
}


////////////////////////////////////////////////////// Check Infromation function /////////////////////////////////////////////////////////

bool Check_Member_Infromation (vector<Member> & member_vec,string &member_fullname, int &Member_ID)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

	Center(CENTER);
	cout << setw(SPACING) << "Please member full name" << ": ";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	getline(cin,member_fullname);
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	Clear_Screen(2);
	if(Get_Member_Full_Name(member_fullname, member_vec))
	{
		{
			Center(CENTER);
			cout << setw(SPACING) <<"Please enter member ID" << ": ";			
			Check_Int_Cin(Member_ID);
			cout << endl;

			if(Check_Member_Full_Name_ID(Member_ID,member_fullname,member_vec))
			{
				member_fullname = Get_ID_Member_Full_Name(Member_ID,member_vec);
				return true;
			}
			else
			{
				Center(CENTER);
				cout << "Wrong ID." <<endl;
				return false;
			}
		}
	}
	else
	{
		Center(CENTER);
		cout << "User dose not exist." <<endl;
		return false;
	}

}


////////////////////////////////////////////////////// Sort Member by ID function /////////////////////////////////////////////////////////
void B_Sort_Member_ID(vector<Member> & member_vec)
{
	Member Temp;
	int size = member_vec.size();
	bool flag;
	do{
		size --;
		flag = false;
		for (int i = 0 ; i < size; i++)
			if(member_vec[i].Get_Member_ID() < member_vec[i+1].Get_Member_ID())
			{
				Temp = member_vec[i];
				member_vec[i] = member_vec[i+1];
				member_vec[i+1] = Temp;
				flag = true;
			}
	}while(flag);
}

////////////////////////////////////////////////////// Sort Books by any type function /////////////////////////////////////////////////////////
void B_Sort_Book_Any(vector<Book> & book_vec,int type)
{
	Book Temp;
	int size = book_vec.size();
	bool flag,data;
	do{
		size--;
		flag = false;
		data = false;
		for (int i = 0 ; i < size; i++)
		{
			switch (type)
			{
			case 0:
				if(book_vec[i].Get_First() > book_vec[i+1].Get_First())
					data = true;
				break;

			case 1:
				if(book_vec[i].Get_Full() > book_vec[i+1].Get_Full())
					data = true;
				break;

			case 2:
				if(book_vec[i].Get_Last() > book_vec[i+1].Get_Last())
					data = true;
				break;

			case 3:
				if(book_vec[i].Get_Availability() > book_vec[i+1].Get_Availability())
					data = true;
				break;

			case 4:
				if(book_vec[i].Get_ISBN() > book_vec[i+1].Get_ISBN())
					data = true;
				break;

			case 5:
				if(book_vec[i].Get_Price() > book_vec[i+1].Get_Price())
					data = true;
				break;

			case 6:
				if(book_vec[i].Get_Title() > book_vec[i+1].Get_Title())
					data = true;
				break;

			case 7:
				if(book_vec[i].Get_ID() > book_vec[i+1].Get_ID())
					data = true;
				break;

			default:
				cout<<" Error, wrong value"<<endl;
					flag = false;
				break;
			}

			if(data)
			{
				Temp = book_vec[i];
				book_vec[i] = book_vec[i+1];
				book_vec[i+1] = Temp;
				flag = true;
			}
		}
	}while(flag);
}


////////////////////////////////////////////////////// Check book ISBN function /////////////////////////////////////////////////////////
bool Check_book_ISBN (string ISBN,vector<Book> & book_vec)
{
int size = book_vec.size();
for(int i=0; i < size; i++)
{
	if(ISBN == book_vec[i].Get_ISBN())
	{
		return true;
	}
}
return false;

}




////////////////////////////////////////////////////// Print Available Books function /////////////////////////////////////////////////////////
void Print_Available_Books(vector<Book> & book_vec)
{
	
int size = book_vec.size();
Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
for(int i=0; i<size ; i++)
	if(book_vec[i].Get_Availability())
	{
		book_vec[i].Print_Book();
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
	}
}


////////////////////////////////////////////////////// Print Books function /////////////////////////////////////////////////////////
void Print_Books(vector<Book> & book_vec)
{
int size = book_vec.size();
Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
for(int i=0; i<size ; i++)
	{
		book_vec[i].Print_Book();
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
	}
}

////////////////////////////////////////////////////// Print Books buy Author's last name function /////////////////////////////////////////////////////////
bool Print_Book_Titles_Author_Last(vector<Book> & book_vec,string in_author_last)
{
int i;
int size = book_vec.size();
Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
for(i=0; i<size ; i++)
	if(Get_Lowercase_String (book_vec[i].Get_Last()) == Get_Lowercase_String(in_author_last))
	{
		Center(CENTER);
		cout << book_vec[i].Get_Title() << endl;
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
	}
if(!i)
	return false;

return true;
}

////////////////////////////////////////////////////// Print Books buy Author's last name function /////////////////////////////////////////////////////////
bool Print_Books_Title(vector<Book> & book_vec,string in_title)
{
int i;
int size = book_vec.size();
Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
for(i=0; i<size ; i++)
	if(Get_Lowercase_String (book_vec[i].Get_Title()) == Get_Lowercase_String (in_title))
	{
		book_vec[i].Print_Book();
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
	}
if(!i)
	return false;

return true;
}



////////////////////////////////////////////////////// Collie Sig function /////////////////////////////////////////////////////////
void Print_Collie_Sig()
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

int Collie=20;



			Clear_Screen(5);
			SetConsoleTextAttribute(hConsole, USERCOLOR2);
			cout<<setw(16+Collie)<<""<<""<<"-'''''-."<<endl;
			cout<<setw(13+Collie)<<""<<".'      #  `."<<endl;
			cout<<setw(12+Collie)<<""<<":             :"<<endl;
			cout<<setw(11+Collie)<<""<<":   #           :"<<endl;
			cout<<setw(11+Collie)<<""<<":      _/|      :"<<endl;
			cout<<setw(12+Collie)<<""<<":   =/_/   #  :"<<endl;
			cout<<setw(13+Collie)<<""<<"`._/ |     .'"<<endl;
			cout<<setw(10+Collie)<<""<<"(   /  ,|...-'"<<endl;
			cout<<setw(11+Collie)<<""<<"[_/^}/|* __"<<endl;
			cout<<setw(9+Collie)<<""<<"_/~  `''~`` @_"<<endl;
			cout<<setw(5+Collie)<<""<<"__/  -'/  --._ |'@___"<<endl;
			cout<<setw(3+Collie)<<""<<"/________/--  -` ~|'"<<endl;

			cout<<setw(10+Collie)<<endl<<endl<<""<<"|=Collie Tech=|";
			SetConsoleTextAttribute(hConsole, BASECOLOR);
			Clear_Screen(5);
}




	  //***************************************************************************************************\\
	 //**************************************** Loading Functions ******************************************\\
	//*******************************************************************************************************\\

void Load_Files (ifstream &file_in,vector<string> &file_name_vec,vector<Member> & member_vec,vector<Book> & book_vec)
{

string names[2]={"members file","books file"};
string temp_name;

int i=0;

	do{
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );		
		Center(CENTER); cout<< "(excluding the file extension)" << endl;		
		Center(CENTER); cout << "Please put the file name for the " << setw(15)<< names[i] << ": ";
		Ask_File_Name(temp_name);
		if(Open_Check_File(file_in,temp_name))
		{	
			switch(i)
			{
			case 0:
				Read_File_Into_Member_Structure_Array (file_in,member_vec);
				break;
			case 1:
				Read_File_Into_Book_Structure_Array (file_in,book_vec);
				break;
			}
		i++;
		file_name_vec.push_back(temp_name);
		}
		else
		{
			Clear_Screen(5);
			cout << "You have failed, collie tech would love you to please try again."<< endl;
		}
		
	}while(i<FILE_AMOUT);
Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
}



////////////////////////////////////////////////////// Read into member structure array function /////////////////////////////////////////////////////////
void Read_File_Into_Member_Structure_Array (ifstream &file_in,vector<Member> & member_vec)
{
	Member temp_member;

	temp_member.Read_Member(file_in);
	member_vec.push_back(temp_member);
		
		
	
	

	while(!file_in.eof())
	{

		
			temp_member.Read_Member(file_in);
			member_vec.push_back(temp_member);
	}

	file_in.close();
	member_vec.pop_back();
	B_Sort_Member_ID(member_vec);


}

void Print_Member_Into_File(ofstream &file_out,vector<Member> & member_vec)
{
Member temp;
file_out << showpoint << setprecision(2);


int i=0;
int size = member_vec.size();
while(i<size)
{		
	temp = member_vec[i];
	file_out << temp.Get_Last()<<", "<< temp.Get_First() << endl;
	file_out << temp.Get_Member_ID() <<" "<< temp.Get_Borrowing_Status() << endl;
	i++;

}
file_out.close();
}



////////////////////////////////////////////////////// Read into book structure array function /////////////////////////////////////////////////////////
void Read_File_Into_Book_Structure_Array (ifstream &file_in, vector<Book> & book_vec)
{
	Book temp_book;
	temp_book.Read_Book(file_in);
	book_vec.push_back(temp_book);
	

	while(!file_in.eof())
	{

		
		temp_book.Read_Book(file_in);
		book_vec.push_back(temp_book);
	}
	file_in.close();
	book_vec.pop_back();

}

////////////////////////////////////////////////////// Read add into book structure array function /////////////////////////////////////////////////////////
void Read_Add_File_Into_Book_Structure_Array (ifstream &file_in, vector<Book> & book_vec)
{
	Book temp_book;

	temp_book.Read_Book(file_in);
	book_vec.push_back(temp_book);

	while(!file_in.eof())
	{
		temp_book.Read_Book(file_in);
		book_vec.push_back(temp_book);
	}
	file_in.close();
	book_vec.pop_back();
}

void Print_Book_Into_File(ofstream &file_out,vector<Book> &book_vec)
{
Book temp;
file_out << showpoint << setprecision(4);


int i=0;
int size = book_vec.size();
while(i<size)
{	
	temp = book_vec[i];
	file_out << temp.Get_Title() << endl;
	file_out << temp.Get_Last()<<", "<< temp.Get_First() << endl;
	file_out << temp.Get_ISBN() <<" "<< temp.Get_Price() <<" "<< temp.Get_Availability() <<" "<< temp.Get_ID() << endl;
	i++;
}
file_out.close();
}
		



	  //***************************************************************************************************\\
	 //**************************************** Menu 1 Functions *******************************************\\
	//*******************************************************************************************************\\

//////////////////////////////////////////////////////Print Menu 1 function /////////////////////////////////////////////////////////

void Print_Collie_Menu1()
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors
int Collie=10;

	Clear_Screen(5);
	SetConsoleTextAttribute(hConsole, BASECOLOR);
    cout<<setw(Collie)<<""<<" _________________________________________________________ "<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||";
	SetConsoleTextAttribute(hConsole, USERCOLOR2); 
	cout<<"          Gry's fountain of knowledge library";
	SetConsoleTextAttribute(hConsole, BASECOLOR);  cout<<"          ||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||.--.    .-._                        .----.             ||"<<endl;
    cout<<setw(Collie)<<""<<"|||==|____| |H|___            .---.___|....|_____.--.___ ||"<<endl;
    cout<<setw(Collie)<<""<<"|||AO|====| | |xxx|           |+++|=-=|_  _|-=+=-|==|---|||"<<endl;
	cout<<setw(Collie)<<""<<"|||==|Hear| | |   |           |   |   |_}{_|White|  | ^ |||"<<endl;
	cout<<setw(Collie)<<""<<"|||  |ding| | |   |      .--. |   |=-=|_}{_|-=+=-|<3| ^ |||"<<endl;
    cout<<setw(Collie)<<""<<"|||  |E--Z| | |   |_____( oo )|   |   |    |Fang^|  | ^ |||"<<endl;
    cout<<setw(Collie)<<""<<"|||==|====| |H|xxx|      |[]| |+++|=-=|....|-=+=-|==|---|||"<<endl;
	cout<<setw(Collie)<<""<<"||`--^----'-^-^---'      {,,} '---^---^----^-----^--^---^||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
	cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||                                                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  1) Log in as member                                  ||"<<endl;
    cout<<setw(Collie)<<""<<"||  2) Register                                          ||"<<endl;
    cout<<setw(Collie)<<""<<"||  3) Search for member                                 ||"<<endl;
    cout<<setw(Collie)<<""<<"||  4) Remove a member from the member list              ||"<<endl;
    cout<<setw(Collie)<<""<<"||  5) Add more books to the book from a data file       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  6) Remove books from book list                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  7) Save and quit                                     ||"<<endl;
	cout<<setw(Collie)<<""<<"||_______________________________________________________||"<<endl;
    cout<<setw(Collie)<<""<<"||                                                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||               ____                  .-.__.-----. .---.||"<<endl;
    cout<<setw(Collie)<<""<<"||              |====|.---.   __   .---| |XX|<(*)>|_|^^^|||"<<endl;
    cout<<setw(Collie)<<""<<"||            /(|[WG]||III|__|..|__|:x:|=|  |Blood|=| Q |||"<<endl;
    cout<<setw(Collie)<<""<<"||           /*(|====||   |++|  |==|   | |  |  &  | | R |||"<<endl;
    cout<<setw(Collie)<<""<<"||          /**(|====||   |  |..|  |:x:|=|  |choco| | Y |||"<<endl;
    cout<<setw(Collie)<<""<<"||_________|***(|^[]^||   |  |  |  |   | |  |late | | Z |||"<<endl;
    cout<<setw(Collie)<<""<<"||         (___)|====||[I]|DK|..|==|:x:|=|XX|<(*)>|=|^^^|||"<<endl;
    cout<<setw(Collie)<<""<<"||              `----^^---^--^--'--^---^-^--^-----^-^---^||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||_______________________________________________________||"<<endl;
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	Clear_Screen(5);
}


//////////////////////////////////////////////////////Menu 1 function /////////////////////////////////////////////////////////
bool Menu_1_Main(vector<Member> & member_vec,vector<Book> & book_vec,string &loged_in_member,vector<string> &file_name_vec,ofstream &file_out)
{
	
	int	menu_choice=0;
	Clear_Screen(100);
	while(menu_choice!=MENU_1)
	{	
		Print_Collie_Menu1();
		Clear_Screen(5);
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );	
		Center(CENTER); cout << setw(SPACING) << "Please slect a choice" << ": ";

		if(Check_Int_Cin(menu_choice))
			menu_choice=0;

		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );

		switch(menu_choice)
		{

			case 0:
				break;

			case 1:
				if(book_vec.empty())
				{
					Center(CENTER);
					cout << "There are no books in the libary."<<endl;
					Center(CENTER);
					cout << "Would you like to add books?: ";
					if(Ask_Yes_No_Check())
					{
						Center(CENTER); Menu2_Add_Books (book_vec);
					}
				}
				else if(Menu1_Login (member_vec,loged_in_member))
					return true;
				break;
			case 2:
				Menu1_Register_Member(member_vec);
				break;

			case 3:
				Menu1_Search (member_vec);
				break;
				
			case 4:
				Menu1_Remove_Member (member_vec);
				break;
				
			case 5:
				Add_Books_File (book_vec);
				break;
				
			case 6:
				Menu1_Remove_Book(book_vec,member_vec);
				break;

			case 7:
				if(Menu1_Update_Exit (file_name_vec,member_vec,book_vec,file_out))			
					return false;
				else
					menu_choice = 0;
					break;

			default:
				Center(CENTER); cout << "not a valid option, please try again."<<endl;
				break;
		}
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
	}

cout << "Error";
return false;
}


////////////////////////////////////////////////////// Log in function /////////////////////////////////////////////////////////



bool Menu1_Login (vector<Member> & member_vec, string &member_fullname)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors
int member_ID=0;


int retrys=RETRY-1;
while(retrys>=0)
{	

	if(Check_Member_Infromation (member_vec,member_fullname,member_ID))
	{
		Center(CENTER); Print_Decale_One(0 ,"#" ,'~' ,"#" ,60 );
		Center(CENTER+10); cout << "You have logined in. Welcome ";
		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		cout<< member_fullname;
		SetConsoleTextAttribute(hConsole, BASECOLOR);
		cout<<"." << endl; 
		Center(CENTER); Print_Decale_One(0 ,"#" ,'~' ,"#" ,60 );
		return true;
	}
	else
	{
		Sub_Retry(retrys);
	}

}
		Center(CENTER); cout << "You have failed to many times, exiting...";
		return false;
}



////////////////////////////////////////////////////// Register member function /////////////////////////////////////////////////////////
bool Menu1_Register_Member (vector<Member> & member_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

string full,member_fist_name, member_member_last;
int ID;
Member temp_member;


Center(CENTER); cout << setw(SPACING) << "Please enter first and mittle names" << ": ";

SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin,member_fist_name);
SetConsoleTextAttribute(hConsole, BASECOLOR);


Center(CENTER); cout << setw(SPACING) << "Please enter your last name" << ": ";
SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin,member_member_last); 
SetConsoleTextAttribute(hConsole, BASECOLOR);

Clear_Screen(2);
Center(CENTER); cout <<setw(SPACING) << "Is this correct? press N to go back" << ": ";
if(Ask_Yes_No_Check())
{
ID = (Assign_Member_ID(member_vec));

temp_member.Set_Add_Member(member_fist_name,member_member_last,ID,0);
member_vec.push_back(temp_member);

B_Sort_Member_ID(member_vec);
Center(CENTER); cout << setw(SPACING) << "Your ID is" << ": ";

SetConsoleTextAttribute(hConsole, USERCOLOR1);
cout<< ID;
SetConsoleTextAttribute(hConsole, BASECOLOR);

Clear_Screen(2);
return true;
}

return false;
}




//////////////////////////////////////////////////////Search for member function /////////////////////////////////////////////////////////
void Menu1_Search (vector<Member> & member_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

string member_fullname;
int members;


Center(CENTER); cout << "Please enter the first and last name : ";

SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin,member_fullname);
SetConsoleTextAttribute(hConsole, BASECOLOR);


members=Get_Member_Full_Name(member_fullname, member_vec);

	if(members>0)
	{
		if(members==0)
		{
			Center(CENTER); cout << "Member found"<<endl;
		}
		else
		{
			Center(CENTER); cout << members <<" members found with the same name as ";
			SetConsoleTextAttribute(hConsole, USERCOLOR1);
			cout << member_fullname;
			SetConsoleTextAttribute(hConsole, BASECOLOR); 
			cout<<"."<<endl;
		}
	}
	else
		{Center(CENTER); cout << "Member not found"<<endl;}


}


////////////////////////////////////////////////////// Remove member function /////////////////////////////////////////////////////////
bool Menu1_Remove_Member (vector<Member> & member_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors
string member_fullname;
int index, size=member_vec.size();

if(member_vec.empty())
{
	cout << "Array is empty, can't remove any members"<<endl;
	return false;
}
Center(CENTER);
cout << setw(SPACING-10) << "Are you shure?" << ":"; 
if(Ask_Yes_No_Check())
{
	Center(CENTER);
	cout << setw(SPACING-10) << "Print name list?" << ":"; 
	if(Ask_Yes_No_Check())
	{
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
		for (int i=0 ; i<size; i++)
			if(member_vec[i].Get_Member_ID() > 0)
			{
				member_vec[i].Print_Member();
				Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
			}
	}


	if(Check_Member_Infromation(member_vec,member_fullname,index))
	{	
		index = Find_Member_ID_Index(index,member_vec);
		if(member_vec[index].Get_Borrowing_Status())
		{
			cout << member_fullname << " still has a book checked out, can not remove."<<endl;
			return false;
		}
		else
		{
			Center(CENTER);
			cout << member_vec[index].Get_Full()<<" : ";
			SetConsoleTextAttribute(hConsole, USERCOLOR1);
			cout<<member_vec[index].Get_Member_ID();
			SetConsoleTextAttribute(hConsole, BASECOLOR);
			
			cout<<" was removed from Gry's libary."<<endl;
			member_vec.erase(member_vec.begin()+index);
			B_Sort_Member_ID(member_vec);		
			Clear_Screen(2);
			return true;
		}
	}
}
return false;
}


////////////////////////////////////////////////////// Add more books to the book from a data file function /////////////////////////////////////////////////////////
bool Add_Books_File (vector<Book> & book_vec)
{

string file_name;
ifstream file_in;

int retrys=RETRY-1;

	do{
		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );		
		Center(CENTER); cout << "(excluding the file extension)" << endl;		
		Center(CENTER); cout << "Please put the file name for the books file ";
		Ask_File_Name(file_name);
		if(Open_Check_File(file_in,file_name))
		{
				
				Read_Add_File_Into_Book_Structure_Array (file_in,book_vec);
				Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
				return true;
		}
		else
				Sub_Retry(retrys);

		
	}while(retrys>=0);

return false;

}



////////////////////////////////////////////////////// Remove book function /////////////////////////////////////////////////////////

bool Menu1_Remove_Book (vector<Book> & book_vec,vector<Member> & member_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

string book_title;
int index;
if(book_vec.empty())
{
	Center(CENTER);
	cout << "There are no books in the libary, can't remove any books."<<endl;
	return false;
}

Center(CENTER);
cout << setw(SPACING) <<"Are you shure?" << ": "; 
if(Ask_Yes_No_Check())
{

	Center(CENTER);
	cout <<setw(SPACING)<<"Book's title"<<": ";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	getline(cin,book_title);
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	
			
		if(Select_Book(book_vec,book_title,index)!=-1)				
			if(Check_book_ISBN(book_vec[index].Get_ISBN(),book_vec))
			{
				Center(CENTER);
				cout << book_vec[index].Get_Title()<<" by "<<book_vec[index].Get_Full()<<" was removed from Gry's libary."<<endl;
				book_vec.erase(book_vec.begin()+index);
				B_Sort_Book_Any(book_vec,1);			
				Clear_Screen(2);
				return true;
			}
}


Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
return false;
}


////////////////////////////////////////////////////// Menu1 Update and Exit /////////////////////////////////////////////////////////

bool Menu1_Update_Exit(vector<string> &file_name_vec,vector<Member> & member_vec,vector<Book> & book_vec,ofstream &file_out)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors
int i=0;

string names[2]={"members file","books file"};
string temp;
Center(CENTER);
cout << setw(SPACING) << "Are you shure you want to leave?" << ":";
if(Ask_Yes_No_Check())
{
	do{
		Clear_Screen(2);
		Center(CENTER);
		cout << "New file for " << setw(SPACING-13);
		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		cout << names[i];
		SetConsoleTextAttribute(hConsole, BASECOLOR);
		cout << ":";
		if(Ask_Yes_No_Check())
		{	
		Center(CENTER);
		cout << "(excluding the file extension)" << endl;
		Center(CENTER);
		cout <<  "input file name for the " << setw(SPACING-17) << names[i] << ":";


		Ask_File_Name(file_name_vec[i]);

		}

		file_out.open(file_name_vec[i].c_str());
		switch(i)
		{
			case 0:
				B_Sort_Member_ID(member_vec);				
				Print_Member_Into_File(file_out,member_vec);
				break;
			case 1:
				B_Sort_Book_Any(book_vec,1);
				Print_Book_Into_File(file_out,book_vec);
				
				break;
		}
	i++;
	}while(i<FILE_AMOUT);
	return true;
}

return false;
}


 	  //***************************************************************************************************\\
	 //**************************************** Menu 2 Functions *******************************************\\
	//*******************************************************************************************************\\

//////////////////////////////////////////////////////Print Menu 2 function /////////////////////////////////////////////////////////
 void Print_Collie_Menu2(string member_fullname)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors
int Collie=10;

	Clear_Screen(5);
	SetConsoleTextAttribute(hConsole, BASECOLOR);
    cout<<setw(Collie)<<""<<" _________________________________________________________ "<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
	cout<<setw(Collie)<<""<<"||";
	SetConsoleTextAttribute(hConsole, USERCOLOR2); 
	cout<<"          Gry's fountain of knowledge library";
	SetConsoleTextAttribute(hConsole, BASECOLOR);  cout<<"          ||"<<endl;
	cout<<setw(Collie)<<""<<setw(16)<<"||"<<"User: "<< setw(35);
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	cout<<member_fullname;
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	cout << "||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
	cout<<setw(Collie)<<""<<"||  .--.____.-._                  .----.            `*,'#||"<<endl;
	cout<<setw(Collie)<<""<<"||  |==|====| |H|___  ___ .---.___|....|_____.--.___  #*.||"<<endl;
    cout<<setw(Collie)<<""<<"||  |  |Howl| | |xxx||-x-||+++|=^=|_  _|-=+=-|==|---|  *`||"<<endl;
	cout<<setw(Collie)<<""<<"||  |==| of | | |* *||x-x||   |   |_}{_|  C++|  | # |    ||"<<endl;
	cout<<setw(Collie)<<""<<"||  |  |Wolf| | | # ||-x-||   |=^=|_}{_|for  |  | * |    ||"<<endl;
    cout<<setw(Collie)<<""<<"||  |  |Gard| | |* *||x-x||   |   |    | pups|  | @ |    ||"<<endl;
    cout<<setw(Collie)<<""<<"||__|==|====| |H|xxx||-x-||+++|=^=|....|-=+=-|==|---|____||"<<endl;
	cout<<setw(Collie)<<""<<"||  `--^----'-^-^---^^---^'---^---^----^-----^--^---^    ||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
	cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||                                                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  1) Borrow a book                                     ||"<<endl;
    cout<<setw(Collie)<<""<<"||  2) Return a book                                     ||"<<endl;
    cout<<setw(Collie)<<""<<"||  3) Request to transfer a book from another library   ||"<<endl;
    cout<<setw(Collie)<<""<<"||  4) Print a list of available books to borrow         ||"<<endl;
    cout<<setw(Collie)<<""<<"||  5) Print a alphabetically sorted list of books       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  6) Print the details of a book                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  7) Print titles of books by an author                ||"<<endl;
    cout<<setw(Collie)<<""<<"||  8) Donate books to the library                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||  9) Return to the sign in screen                      ||"<<endl;
	cout<<setw(Collie)<<""<<"||_______________________________________________________||"<<endl;
	cout<<setw(Collie)<<""<<"||                                                       ||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
	cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||    ____      _____                  .-.__.------. .--.||"<<endl;
    cout<<setw(Collie)<<""<<"||  xX..:::`   |-----|.---.   __   .---| |XX|<(**)>|_|<>|||"<<endl;
	cout<<setw(Collie)<<""<<"|| Xx...:::::` |Wolf ||III|__|..|  |:x:|#|  |Tails |=|==|||"<<endl;
	cout<<setw(Collie)<<""<<"||XXx++-,:::::`|Magic||   |{}|  |  |   | |  |  Of  | |==|||"<<endl;
	cout<<setw(Collie)<<""<<"||XXxx++--,:::`|-----||---|  |..|  |:x:|#|  |lycan | |==|||"<<endl;
	cout<<setw(Collie)<<""<<"|| XXXxx+++-:` |#***#||   |  |  |  |   | |  |thropy| |==|||"<<endl;
	cout<<setw(Collie)<<""<<"|| _xXXXxxx `__|-----||[I]|{}|..|__|:x:|#|XX|<(**)>|=|<>|||"<<endl;
    cout<<setw(Collie)<<""<<"||     X--`    `-----^^---^--^--'   `--^-^--^------^-^--^||"<<endl;
    cout<<setw(Collie)<<""<<"||-------------------------------------------------------||"<<endl;
    cout<<setw(Collie)<<""<<"||_______________________________________________________||"<<endl;

	Clear_Screen(5);
}
////////////////////////////////////////////////////// Menu 2 function /////////////////////////////////////////////////////////

void Menu_2_Main (vector<Member> & member_vec,vector<Book> & book_vec, string loged_in_member,vector<string> &file_name_vec)
{

int loged_in_member_ID =  Find_Member_Full_Name_ID(loged_in_member,member_vec),
	loged_in_index = Find_Member_ID_Index(loged_in_member_ID,member_vec);

			int menu_choice = 0;
			while(menu_choice!=MENU_2)
			{
				
				Print_Collie_Menu2(loged_in_member);
				Clear_Screen(5);
				Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
				Center(CENTER);
				cout << setw(SPACING) <<"Please slect a choice" << ": ";

			if(Check_Int_Cin(menu_choice))
				menu_choice = 0;
				Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );

				switch(menu_choice)
				{				
					case 0:
						break;

					case 1:
						Menu2_Borrow_Book(book_vec,member_vec,loged_in_member_ID,loged_in_index);
						break;
						
					case 2:
						Menu2_Return_Book(book_vec,member_vec,loged_in_member_ID,loged_in_index);
						break;
					
					case 3:
						Add_Book_Library2_File (book_vec,file_name_vec[1]);
						break;
				
					case 4:
						Print_Available_Books (book_vec);
						break;
				
					case 5:
						Menu2_Print_Books_Alpha_Title(book_vec);
						break;
				
					case 6:
						Menu2_Print_Book_Title(book_vec);
						break;
				
					case 7:
						Menu2_Print_Books_Author_Last(book_vec);
						break;
				
					case 8:
						Menu2_Add_Books (book_vec);
						break;

					case 9:
						Center(CENTER);
						cout << "Are you shure you want to return to main menu and log out :";
						if(Ask_Yes_No_Check())
						{
							Center(CENTER);
							cout << "Returning to main menu and loging out."<<endl;
						}
						break;

					default:
						Center(CENTER); cout << "not a valid option, please try again."<<endl;
						break;
				}

			}
 }
////////////////////////////////////////////////////// Borrow Book function /////////////////////////////////////////////////////////
void Menu2_Borrow_Book(vector<Book> & book_vec,vector<Member> & member_vec,int loged_in_member_ID,int loged_in_index)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

int index,book_index;
string book_title;

if(member_vec[loged_in_index].Get_Borrowing_Status())
{
	book_index=Find_Book_Member_ID_Index(loged_in_member_ID,book_vec);
	if(book_index!=-1)
	{
	Center(CENTER); cout << "You allready have ";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	cout<<book_vec[book_index].Get_Title();
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	cout<<".";
	Clear_Screen(1);
	Center(CENTER); cout << "You can only have one book checked out at a time."<<endl;
	}
	else
	{
		Center(CENTER); cout << "Error: Book is not in libary."<<endl;
	}
}
else
{
		Center(CENTER); cout << "Please enter Book's title: ";
		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		getline(cin,book_title);
		SetConsoleTextAttribute(hConsole, BASECOLOR);
	

	if(Select_Book(book_vec,book_title,index)!=-1)
	{
		book_vec[index].Set_ID(loged_in_member_ID);
		book_vec[index].Set_Availability(0);
		member_vec[loged_in_index].Set_Borrowing_Status(1);
		Center(CENTER);
		cout <<"You are now barrowing "; 
		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		cout <<book_vec[index].Get_Title();
		SetConsoleTextAttribute(hConsole, BASECOLOR);	
		cout<<". This book is due in 1 moon cycle."<<endl<<endl;
	}
}
}

////////////////////////////////////////////////////// Return Book function /////////////////////////////////////////////////////////
void Menu2_Return_Book(vector<Book> & book_vec,vector<Member> & member_vec,int loged_in_member_ID,int loged_in_index)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

int book_index;
if(!member_vec[loged_in_index].Get_Borrowing_Status())
{
	Center(CENTER); cout << "You don't have a book to return ";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	cout<<member_vec[loged_in_index].Get_Full();
	SetConsoleTextAttribute(hConsole, BASECOLOR);		
	cout<<"."<<endl;
}
else
{
	book_index=Find_Book_Member_ID_Index(loged_in_member_ID,book_vec);
	if(book_index!=-1)
	{
		Center(CENTER);
		cout<< setw(SPACING) <<"Are you shure you want to return"<<": ";
		SetConsoleTextAttribute(hConsole, USERCOLOR1);
		cout<<book_vec[book_index].Get_Title();
		SetConsoleTextAttribute(hConsole, BASECOLOR);
		cout<< " : ";
		if(Ask_Yes_No_Check())
		{
			book_vec[book_index].Set_ID(-1);
			book_vec[book_index].Set_Availability(1);
			member_vec[loged_in_index].Set_Borrowing_Status(0);
			Center(CENTER);
			cout<<"You have now returned ";
			SetConsoleTextAttribute(hConsole, USERCOLOR1);
			cout<<book_vec[book_index].Get_Title();
			SetConsoleTextAttribute(hConsole, BASECOLOR);
			cout<<"."<<endl;
		}
	}
	else
	{
		Center(CENTER); cout << "Error: Book is not in libary."<<endl;
	}
}
}


////////////////////////////////////////////////////// Request to transfer a book from another library function /////////////////////////////////////////////////////////
void Add_Book_Library2_File (vector<Book> & book_vec,string in_file_name)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

string file_name,book_title;
ifstream file_in;
ofstream file_out;
vector<Book> book_vec_temp;

int book_temp_size=0,index=0;
bool flag;


		Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );		
		Center(CENTER); cout << "(excluding the file extension)" << endl;		
		Center(CENTER); cout << setw(SPACING) <<"Please put the file name for the books file" << ": ";
		Ask_File_Name(file_name);
		if(file_name==in_file_name)
		{
			Center(CENTER); cout << "Can't be the same file as the one allready in use." << endl;		
		}
		else if(Open_Check_File(file_in,file_name))
		{
			Read_File_Into_Book_Structure_Array (file_in,book_vec_temp);
			
			flag = true;
			do{
					Print_Available_Books (book_vec_temp);
					Center(CENTER); cout << setw(SPACING) <<"Book's title" << ": ";
					getline(cin,book_title);
				if(Select_Book(book_vec_temp,book_title,index)!=-1)
				{
					
					
					
					book_vec.push_back(book_vec_temp[index]);
//					book_vec_temp.erase(index);
					B_Sort_Book_Any(book_vec_temp,1);
					
				}
				else
				{
				Center(CENTER); cout << "Book ";
				SetConsoleTextAttribute(hConsole, USERCOLOR1);
				cout<<book_title;
				SetConsoleTextAttribute(hConsole, BASECOLOR);
				cout<<" not found."<<endl;
				}
				Center(CENTER); cout << "Exit to menu?: ";
				if(Ask_Yes_No_Check())
				{		
					Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
					flag = false;
				}
				}while(flag);
		}

file_out.open(file_name.c_str());
B_Sort_Book_Any(book_vec,1);
Print_Book_Into_File(file_out,book_vec_temp);
}



////////////////////////////////////////////////////// Print Available Books function /////////////////////////////////////////////////////////

////////////////////////////////////////////////////// Print Books Alphabetically function /////////////////////////////////////////////////////////
bool Menu2_Print_Books_Alpha_Title(vector<Book> & book_vec)
{
B_Sort_Book_Any(book_vec,6);
Print_Books (book_vec);
return true;
}

////////////////////////////////////////////////////// Print A Book function /////////////////////////////////////////////////////////
void Menu2_Print_Book_Title(vector<Book> & book_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

string book_title;
int j=0;

	Center(CENTER);
	cout << setw(SPACING) <<"Book's title" << ": ";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	getline(cin,book_title);
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	

if(!Print_Books_Title(book_vec,book_title))
{
	Center(CENTER); cout << "No books found by the title "<< book_title << ".";
	Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
}


}

////////////////////////////////////////////////////// Print Books by Author's Last name function /////////////////////////////////////////////////////////
void Menu2_Print_Books_Author_Last(vector<Book> & book_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

string author_last;
Center(CENTER); cout << setw(SPACING) <<"Please put in author's Last name"<<": ";
SetConsoleTextAttribute(hConsole, USERCOLOR1);
getline(cin,author_last);
SetConsoleTextAttribute(hConsole, BASECOLOR);

B_Sort_Book_Any(book_vec, 6);

if(!Print_Book_Titles_Author_Last(book_vec,author_last))
{
	Center(CENTER); cout << "No books found by ";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	cout<<author_last;
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	cout<<"."<<endl;
	Print_Decale_One(5 ,"||" ,'-' ,"||" ,70 );
}

}


////////////////////////////////////////////////////// Add books function /////////////////////////////////////////////////////////
void Menu2_Add_Books (vector<Book> & book_vec)
{
// Colors
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Colors

Book temp_book;

string names[5]={"title of book","author's first and middle names","author's last name","ISBN","Price"};
string title_of_book,author_fist_name, author_member_last,ISBN;
float price;
bool flag;



	flag = true;
	do{
			int i=0;
			do{
				Center(CENTER);
				cout <<setw(SPACING)<<names[i]<<": ";

					switch(i)
					{
					case 0:
						SetConsoleTextAttribute(hConsole, USERCOLOR1);
						getline(cin,title_of_book);
						SetConsoleTextAttribute(hConsole, BASECOLOR);						
						break;
					case 1:
						SetConsoleTextAttribute(hConsole, USERCOLOR1);
						getline(cin,author_fist_name);
						SetConsoleTextAttribute(hConsole, BASECOLOR);
						break;
					case 2:
						SetConsoleTextAttribute(hConsole, USERCOLOR1);
						getline(cin,author_member_last);
						SetConsoleTextAttribute(hConsole, BASECOLOR);						
						break;
					case 3:
						SetConsoleTextAttribute(hConsole, USERCOLOR1);
						getline(cin,ISBN);
						SetConsoleTextAttribute(hConsole, BASECOLOR);						
						if(Check_book_ISBN (ISBN,book_vec))
						{
							Center(CENTER); cout << "Book ISBNs can't be the same"<<endl;
							i--;		
						}
						break;
					case 4:
						if(Check_Float_Cin(price))
							i--;
						break;
					}
					i++;
			}while(i<5);

		Center(CENTER); cout << "Is this correct? ";
		if(Ask_Yes_No_Check())
		{
			temp_book.Set_Add_Book(title_of_book,author_fist_name,author_member_last,ISBN,price);
			book_vec.push_back(temp_book);
			Clear_Screen(2);
		}
		Center(CENTER); cout << "Go to main menu? ";
		if(Ask_Yes_No_Check())
		{
			flag=false;
		}
	}while(flag);
}