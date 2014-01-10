#include "fruit.h"

fruit::fruit(void)
	{
		type = "Oranges";
		kol = 1;
		country = "Turkey";
		price = 10;
	}
fruit::fruit(string str, double dob, string stri, double doo)
	{
		type = str;
		kol = dob;
		country = stri;
		price = doo;
	}
string fruit::get_smth()
	{
		return country;
	}
void fruit::set_smth(string stri)
	{
		country = stri;
	}
void fruit::print_msg()
{
	cout << "Enter the name of fruit, the amount in lb, the price for 1 lb of fruit and the country of origin:" << endl << endl;
}

void fruit::ust_smth()
{
	string stri;
	cin >> stri;
	country = stri;
}

fruit fruit::operator=(fruit fru)
	{
		fru.set_type(type);
		fru.set_smth(country);
		fru.set_kol(kol);
		fru.set_price(price);
		return fru;
	}
fruit::~fruit(){}