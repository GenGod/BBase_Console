#include "sybd.h"

sybd::sybd()
{
	type = "Lettuce";
	kol = 1;
	price = 10;
}
sybd::sybd(string str, double dob, double doo)
{
	type = str;
	kol = dob;
	price = doo;
}
void sybd::set_price(double doo){ price = doo; }
double sybd::get_price(){ return price; }
void sybd::set_type(string str){ type = str; }
string sybd::get_type(){ return type; }
void sybd::set_kol(double dob){ kol = dob; }
double sybd::get_kol(){ return kol; }
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
void sybd::ust_double()
{
	double dod;
	cin >> dod;
	set_price(dod);
}
sybd::~sybd(void){}