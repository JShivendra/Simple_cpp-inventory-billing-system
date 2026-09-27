#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>	    // for date related functions 
#include <fstream>	   // for file handling
#include <iomanip>    // for formatting output
using namespace std; 
const int size1 = 3;

class item 
{ 
private: 
	string name; 
	int icode; 
	int iprice; 
	int basketquant;
public: 
	item()
	{
		name = " ";
		icode = 0;
		iprice = 0;
		basketquant = 0;
	}
	item(string, int, int);
	void idis1(); 
	int getcode() { return icode; }
	void changequantity(char);
	void display();
	void displayf(ofstream&);
	bool getbasketquant() { return basketquant > 0; }
	int pricing(){ return basketquant * iprice; }
};

item::item(string n, int c, int p) 
{ 
	name = n; 
	icode = c; 
	iprice = p;  
	basketquant = 0;
}

void item::idis1() 
{ 
	cout<<name<<"\t\t\t\t"<<iprice<<"\t\t\t"<<icode<<endl;
} 

void item::changequantity(char c)
{	
	int units;
	if (c == 'b')
		cout << "Enter the number of units you want to buy: ";
	else
		cout << "Enter the number of units you want to discard: ";
	cin >> units;
	if (c == 'b')
		basketquant += units;
	else
		basketquant -= units;
	if (basketquant < 0)
		basketquant = 0;
}


void item::display()					// Displays the items for the invoice with their name, price, number and total price. //
{
		int total_price = iprice * basketquant;
		cout << name << "\t\t\t\t" << iprice << "\t\t\t      " << basketquant << "\t\t\t" << total_price << endl;
}

void item::displayf(ofstream& file)					// Displays the items for the invoice with their name, price, number and total price. //
{
	int total_price = iprice * basketquant;
	file << name << "\t\t\t\t" << iprice << "\t\t\t      " << basketquant << "\t\t\t" << total_price << endl;
}
int grandtotal(item temp_list[])
{
	int total = 0;
	for (int i = 0; i < size1; i++)
	{
		if (temp_list[i].getbasketquant())
		{
			total += temp_list[i].pricing();
		}
	}
	return total;
}
void printbody(item temp_list[], int total)
{
	time_t now = time(nullptr);
	tm ltm;
	localtime_s(&ltm, &now);


	cout << "\n\n\n\n\t\t\t\t\t\t SHIVENDRA FIRMS PVT LTD \n";
	cout << "\n\n";
	cout << "\t\t\t\t\t \t\tINVOICE \n\n";
	cout << "DATE :  " << setfill('0') << setw(2) << ltm.tm_mday << " / " << setw(2) << ltm.tm_mon + 1 << " / " << ltm.tm_year + 1900 << "\t\t\t\t\t\t\t\t Invoice no : XXXXXX \n";
	cout << "\n\n";
	cout << "ITEM NAME \t\t PRICE PER UNIT \t\t      NUMBER \t\t TOTAL PRICE\n";

	for (int i = 0; i < size1; i++)
	{
		if (temp_list[i].getbasketquant())
		{
			temp_list[i].display();
		}
	}
	cout << "\n\n\t\t\t\t\t\t\t\t\t           GRAND TOTAL : " << total << endl;
}

void printfile(item templist[],int total)
{
	time_t now = time(nullptr);
	tm ltm;
	localtime_s(&ltm, &now);

	ofstream file("invoice.txt");

	if (!file)
	{
		cout << "File could not be opened.\n";
		return;
	}

	file << "\t\t\t\t\t\t SHIVENDRA FIRMS PVT LTD\n";
	file << "\n\n";
	file << "\t\t\t\t\t\t INVOICE\n\n";

	file << "DATE : "
		 << setfill('0') << setw(2) << ltm.tm_mday
		 << " / " << setw(2) << ltm.tm_mon + 1
		 << " / " << ltm.tm_year + 1900
		 << "\t\t\t\t\t\t\t Invoice no : XXXXXX\n";

	file << "\n\n";

	file << "ITEM NAME\t\tPRICE PER UNIT\t\tNUMBER\t\tTOTAL PRICE\n";
	for (int i = 0; i < size1; i++)
	{
		if (templist[i].getbasketquant())
		{
			templist[i].displayf(file);
		}
	}
	file << "\n\n\t\t\t\t\t\t\t\t\t           GRAND TOTAL : " << total << endl;




	file.close();

	cout << "File created successfully.\n";

	system("start invoice.txt");
}

void basket(item temp_list[])					// displays the items in the basket with their name, price, number and total price. //
{
	cout << "Your basket contains: \n\n";
	cout << "ITEM NAME \t\t PRICE PER UNIT \t\t     NUMBER \t\t TOTAL PRICE\n";
	for (int i = 0; i < size1; i++)
	{
		if (temp_list[i].getbasketquant())				// get basketquant() returns true if the quantity of the item in the basket is greater than 0, indicating that the item is present in the basket. //
		{
			temp_list[i].display();
		}
	}
}

void idis2(item list_temp[])						// displays the items in the store with their name, price and code. //
{ 
	cout<<"Currently we provide : "<<size1 <<" items \n"; 
	cout<<"Item Name \t\t    item price \t\t    item code \n"; 
	for(int i=0;i<size1;i++) 
	{ 
		list_temp[i].idis1(); 
	} 
}

int check(item templist[], char c)
{
	if (c == 'b')
		cout << "Please enter the item code of the item you wish to buy ";
	else
		cout << "Please enter the item code of the item you wish to discard ";
	int code;
	cin >> code;
	for(int i=0;i<size1;i++)
	{	
		int tempcode = templist[i].getcode();
		if (code == tempcode)
			return i;
	}
	cout << "Invalid code entered. Please try again.\n\n"; // If the code is valid function will return directly and will not reach to this point to indicate an error. //
	return -1;										  // Return -1 to indicate that the code was invalid. //
}

bool choicefunc(char c)
{
	if ( c=='b')	
		cout << "\nDo you wish to buy anything else? (y/n)";
	else 
		cout << "\nDo you wish to discard anything else? (y/n)";
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
		return true;
	else
		return false;
}



int main() 
{ 
	item list[size1]; 
	list[0] = item("Apple", 101, 20);
	list[1] = item("Banana", 102, 15);
	list[2] = item("Orange", 103, 25);

	cout << "Do you wish to see the offerings? (y/n)";
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
		{idis2(list);}
	else
	{
		cout << "Thank you for visiting!";
		exit(0);                                                   // Exit function from cstdlib.h //
	}
	bool running = true;
	while (running)
	{
		cout << "\nEnter your choice from the following options: \n";
		cout << "\n1. Add item";
		cout << "\n2. Discard basket";
		cout << "\n3. Show basket";
		cout << "\n4. Print invoice";
		cout << "\n5. Print invoice in txt format";
		cout << "\n6. Exit \n";
		int run_choice;
		cin >> run_choice;
		cout<<endl;

		switch (run_choice)
		{
			case 1:
			{   
				bool buying = true;
				while (buying)							// loop to allow the user to buy multiple items until they choose not to //
				{
					int code = -1;
					code = check(list, 'b');
					if (code != -1)
						list[code].changequantity('b');    // Increment the quantity of the item in the basket if code is valid //
					buying = choicefunc('b');
				}
				break;
			}
			case 2:
			{
				bool discarding = true;
				while (discarding)							// loop to allow the user to discard multiple items until they choose not to //
				{
					int code = -1;
					code = check(list, 'd');
					if (code != -1)
						list[code].changequantity('d');    // Decrement the quantity of the item in the basket if code is valid //
					discarding = choicefunc('d');
				}
				break;
			}
			case 3 : 
			{
				basket(list);
				break;
			}
			case 4:
			{
				int total = grandtotal(list);
				printbody(list, total);
				break;
			}
			case 5:
			{
				int total = grandtotal(list);
				cout << "print file in txt format";
				printfile(list,total);
				break;
			}
			case 6:
			{
				running = false;
				break;
			}
			
		}
	}
}
