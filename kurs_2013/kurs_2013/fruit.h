#pragma once

#include "sybd.h"

class fruit : public sybd
{
private:
	string type;
	double kol;
	string country;
	double price;
public:
	fruit(void);
	fruit(string str, double dob, string stri, double doo);
	void print_msg();
	void ust_smth();
	string get_smth();
	void set_smth(string stri);
	friend ostream& operator<<(ostream& output, fruit fru)
	{
		output << "Type: ";
		output << fru.get_type();
		output << " \n";
		output << "How many: ";
		output << fru.get_kol();
		output << " êã \nCountry of origin: ";
		output << fru.get_smth();
		output << "\nPrice is: ";
		output << fru.get_price();
		output << " \n\n\n";
		return output;
	}
	fruit operator=(fruit fru);
	~fruit(void);
};