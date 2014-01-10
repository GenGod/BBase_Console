#include "Password.h"

password::password()
{
	name = "Vasya";
	pass = "0000";
	access = 3;
};
password::password(string name1, string pas, int dfg)
{
	name = name1;
	pass = pas;
	access = dfg;
};
password::password(string name1)
{
	name = name1;
	pass = "0000";
	access = 3;
};
password::password(const password & dfg)
{
	name = dfg.name;
	pass = dfg.pass;
	access = dfg.access;
};
void password::set_access(int ghj)
{
	access = ghj;
}
int password::get_access()
{
	return access;
}
void password::set_name(string name1)
{
	name = name1;
};
string password::get_name()
{
	return name;
};
void password::set_pass(string pas)
{
	pass = pas;
};
string password::get_pas()
{
	return pass;
};
password password::operator=(password pas)
{
	pas.name = name;
	pas.pass = pass;
	pas.access = access;
	return pas;
}
bool password::operator==(vector<password>::iterator rf)
{
	if ((rf->name == this->name) && (rf->pass == this->pass) && (rf->access == this->access))
		return true;
	else return false;
};