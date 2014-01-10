#pragma once

#include "sybd.h"

class ovos : public sybd
{
private:
	string type;
	double kol;
	bool gmo;
	double price;
public:
	ovos(void);
	ovos(string str, double dob, bool boo, double doo);
	void print_msg();
	void set_smth(bool boo);
	bool get_smth();
	void ust_bool();
	friend ostream& operator<<(ostream& output, ovos fru)
	{
		output << "Type: ";
		output << fru.get_type();
		output << " \n";
		output << "How many: ";
		output << fru.get_kol();
		output << " lb \nGMO: ";
		if (fru.get_smth() == 0)
			output << "no GMO";
		else
			output << "GMOs are present";
		output << "\nPrice is: ";
		output << fru.get_price();
		output << " \n\n\n";
		return output;
	}
	ovos operator=(ovos vo);
	bool operator==(vector<ovos>::iterator rf);
	~ovos(void);
};