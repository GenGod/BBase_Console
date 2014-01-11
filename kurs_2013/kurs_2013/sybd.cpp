#include "sybd.h"

sybd::sybd()
{
	type = "Lettuce";
	kol = 1;
	price = 10;
	shelf_life = 3;
}
sybd::sybd(string str, double dob, double doo, double shelf_lif)
{
	type = str;
	kol = dob;
	price = doo;
	shelf_life = shelf_lif;
}
void sybd::set_price(double doo){ price = doo; }
double sybd::get_price(){ return price; }
void sybd::set_type(string str){ type = str; }
string sybd::get_type(){ return type; }
void sybd::set_kol(double dob){ kol = dob; }
double sybd::get_kol(){ return kol; }
void sybd::set_shelf_life(double shelf_lif){ shelf_life = shelf_lif; }
double sybd::get_shelf_life(){ return shelf_life; }
void sybd::ust_string()
{
	string str;
	cin >> str;
	set_type(str);
}
void sybd::ust_doub()
{
	double dod;
	cin >> dod;
	set_kol(dod);
}
void sybd::ust_dooo()
{
	cout << "Enter new shelf life: " << endl;
	double dod;
	cin >> dod;
	set_shelf_life(dod);
}
void sybd::ust_double()
{
	double dod;
	cin >> dod;
	set_price(dod);
}
sybd::~sybd(void){}