#define _CRT_SECURE_NO_WARNINGS


#include <fstream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include "Header.h"

template<class T>
void swapt(T &fru, T &fgh)
{
	T rtg;
	fru.set_type(rtg.get_type());
	fru.set_kol(rtg.get_kol());
	fru.set_price(rtg.get_price());
	fru.set_smth(rtg.get_smth());
	fru.set_type(fgh.get_type());
	fru.set_kol(fgh.get_kol());
	fru.set_price(fgh.get_price());
	fru.set_smth(fgh.get_smth());
	fgh.set_type(rtg.get_type());
	fgh.set_kol(rtg.get_kol());
	fgh.set_price(rtg.get_price());
	fgh.set_smth(rtg.get_smth());
}

void print_smth(vector<fruit> fru)
{
	vector<fruit>::iterator ou = fru.begin();
	for (ou; ou != fru.end(); ou++)
		cout << *ou;
}

void print_smth(vector<ovos> ovo)
{
	vector<ovos>::iterator ou = ovo.begin();
	for (ou; ou != ovo.end(); ou++)
		cout << *ou;
}

vector<fruit>::iterator search_smth(vector<fruit>& ovo, string str)
{
	vector<fruit>::iterator hj=ovo.end();
	vector<fruit>::iterator it = ovo.begin();
	for (it; it != ovo.end(); it++)
	{
		if (it->get_type() == str)
		{
			hj=it;
			break;
		}
	}
	return hj;
}

vector<ovos>::iterator search_smth(vector<ovos>& ovo,string str)
{
	vector<ovos>::iterator it = ovo.begin();
	for (it; it != ovo.end(); it++)
	{
		if (it->get_type() == str)
		{
			return it;
			break;
		}
	}
}

void delete_smth(vector<ovos>& vovos)
{
	int f;
	int b = 0;
	string str;
	while (1)
	{
		cout << "Enter the name of vegetable to delete:\n";
		cin >> str;
		vector<ovos> ::iterator iy = vovos.begin();
		iy = search_smth(vovos, str);
		if (iy != vovos.end())
		{
			int hg = (iy - vovos.begin());
			swapt(vovos[hg], vovos.back());
			vovos.pop_back();
		}
		else cout << "Vegetable not found." << endl;
		cout << "1. Back to menu\n2. Delete more vegetable\n"<<endl;
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  b++;
				  break;
		}
		case 2: break;
		}
		if (b!=0)
		break;
	}
}

void delete_smth(vector<fruit>& vfru)
{
	int f;
	int a = 0;
	string str;
	cout << vfru[0];
	while (1)
	{
		cout << "Enter the name of fruit to delete:\n";
		cin >> str;
		vector<fruit> ::iterator is = vfru.begin();
		is = search_smth(vfru, str);
		if (is != vfru.end())
		{
			int hg = (is - vfru.begin());
			swapt(vfru[hg], vfru.back());
			vfru.pop_back();
		}
		else cout << "Fruit not found." << endl;
		cout << "1. Back to menu\n2. Delete more fruit\n" << endl;
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  a++;
				  break;
		}
		case 2: break;
		}
		if (a!=0)
		break;
	}
}

void add_smth(vector<ovos>& vovos)
{
	int g=0;
	double dod;
	bool r;
	string str;
	while (1)
	{
		ovos gu;
		gu.print_msg();
		cin >> str;
	    gu.set_type(str);
		cin >> dod;
		gu.set_kol(dod);
		cin >> dod;
		gu.set_price(dod);
		cin >> r;
		gu.set_smth(r);
		vovos.push_back(gu);
		int f;
		cout << "1. Back to menu\n2.Add more vegetable\n";
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  g++;
				  break;
		}
		case 2: break;
		}
		if (g != 0)
			break;
	}
}

//template <class T>
void add_smth(vector<fruit>& vfru)
{
	double dod;
	string str;
	int d = 0;
	while (1)
	{
		fruit fu;
		fu.print_msg();
		cin >> str;
			fu.set_type(str);
			cin >> dod;
			fu.set_kol(dod);
			cin >> dod;
			fu.set_price(dod);
			cin >> str;
			fu.set_smth(str);
		vfru.push_back(fu);
		int f;
		cout << "1. Back to menu\n2.Add more fruit\n";
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  d++;
				  break;
		}
		case 2: break;
		}
		if (d != 0)
			break;
	}
}

template <class T>
void file_save(vector<T>& vovos, int right, string username)
{
	switch (right)
	{
	case 1:
	{
			  char* ch;
			  wchar_t* wch;
			  string put = "C:\\BBase\\Premium\\";
			  string put2 = put;
			  put += username;
			  string name_p;
			  int hu = put.capacity();
			  vector<T>::iterator uy = vovos.begin();
			  CreateDirectoryW(L"C:\\BBase", NULL);
			  CreateDirectoryW(L"C:\\BBase\\Premium\\", NULL);
			  ch = new char[hu];
			  wch = new wchar_t[hu];
			  strcpy(ch, put.c_str());
			  for (int i = 0; i < hu; i++)
				  MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, &ch[i], 1, &wch[i], 1);
			  CreateDirectoryW(wch, NULL);
			  put += "\\";
			  cout << "Enter filename to save a data (if it does not exist, one will be created):" << endl;
			  cin >> name_p;
			  put += name_p;
			  ofstream out(put);
			  for (uy; uy != vovos.end(); uy++)
			  {
				  out << uy->get_type();
				  out << " ";
				  out << uy->get_kol();
				  out << " ";
				  out << uy->get_price();
				  out << " ";
				  out << uy->get_smth();
				  out << "\n";
			  }
			  cout << "Data has been successfully saved!\n";
			  out.close();
			  break;
	}
	case 2:
	{
			  cout << "In free version you can't save more than 30 items!\n";
			  vector<T>::iterator uy = vovos.begin();
			  int j = 0;
			  CreateDirectoryW(L"C:\\BBase", NULL);
			  string name_p;
			  string put = "C:\\BBase\\Gewonlich\\";
			  cout << "Enter filename to save a data (if it does not exist, one will be created)" << endl;
			  cin >> name_p;
			  put += name_p;
			  ofstream out(put);
			  for (uy; uy != vovos.end(); uy++)
			  {
				  out << uy->get_type() << " " << uy->get_kol() << " " << uy->get_price() << " " << uy->get_smth() << "\n";
				  if (j < 10)
					  j++;
				  else break;
			  }
			  cout << "Data has been successfully saved!\n";
			  out.close();
			  break;
	}
	case 3:
	{
			  cout << "You can't save data to disk in the trial version!";
			  break;
	}
	}
}

vector<fruit> load_file(int right)
{
	vector<fruit> vovos;
	string put;
	string str, dfg;
	double dod, dob;
	fruit voso;
	cout << "Enter path to file as: C:\\Folder_Name\\File_Name.dba\n";
	cin >> put;
	ifstream in(put);
	if (!in)
	{
		cout << "File not found!\n";
	}
	else
	{
		switch (right)
		{
		case 1:
		{
				  while (in)
				  {
					  in >> str >> dod >> dob >> dfg;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(dfg);
					  vovos.push_back(voso);
				  }
				  vovos.pop_back();
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 2:
		{
				  cout << "In free version you can't load more than 10 items from the file." << endl;
				  int j = 0;
				  while (in)
				  {
					  in >> str >> dod >> dob >> dfg;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(dfg);
					  vovos.push_back(voso);
					  if (j < 9)
						  j++;
					  else break;
				  }
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 3:
		{
				  cout << "In trial version you can load from the file one item only." << endl;
				  in >> str >> dod >> dob >> dfg;
				  voso.set_type(str);
				  voso.set_kol(dod);
				  voso.set_price(dob);
				  voso.set_smth(dfg);
				  vovos.push_back(voso);
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		}
	}
	in.close();
	return vovos;
}

vector<ovos> load_file(double right2)
{
	vector<ovos> vovos;
	string put;
	int right = int(right2);
	string str;
	double dob, dod;
	bool boo;
	ovos voso;
	cout << "Enter path to file as: C:\\Folder_Name\\File_Name.dba\n";
	cin >> put;
	ifstream in(put);
	if (!in)
	{
		cout << "File not found!\n";
	}
	else
	{
		switch (right)
		{
		case 1:
		{
				  while (in)
				  {
					  in >> str >> dod >> dob >> boo;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(boo);
					  vovos.push_back(voso);
				  }
				  vovos.pop_back();
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 2:
		{
				  cout << "In free version you can't load more than 10 items from the file." << endl;
				  int j = 0;
				  while (in)
				  {
					  in >> str >> dod >> dob >> boo;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(boo);
					  vovos.push_back(voso);
					  if (j < 9)
						  j++;
					  else break;
				  }
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 3:
		{
				  cout << "In trial version you can load from the file one item only." << endl;
				  in >> str >> dod >> dob >> boo;
				  voso.set_type(str);
				  voso.set_kol(dod);
				  voso.set_price(dob);
				  voso.set_smth(boo);
				  vovos.push_back(voso);
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		}
	}
	in.close();
	return vovos;
}
void menu(vector<ovos>& vovos, vector<fruit>& vfru, int right, string user_name)
{
	int h;
	int t = 0;
	double right2 = right;
	while (1)
	{
		cout << "What you want to do?\n1. Add a new vegetable\n2. Add a new fruit\n3. Delete an existing vegetable\n4. Delete an existing fruit\n5. Find a vegetable in BBase\n6. Find a ftuit in BBase\n7. Save BBase of vegetables to disk\n8. Save BBase of fruits to disk\n9. Load BBase of vegetables from the disk\n10. Load BBase of fruits from the disk\n11. Show BBase of vegetables on the screen\n12. Show BBase of fruits on the screen\n13. Exit the program\n" << endl;
		cin >> h;
		switch (h)
		{
		case 1:
		{
				  add_smth(vovos);
				  break;
		}
		case 2:
		{
				  add_smth(vfru);
				  break;
		}
		case 3:
		{
				  delete_smth(vovos);
				  break;
		}
		case 4:
		{
				  delete_smth(vfru);
				  break;
		}
		case 5:
		{
				  string str;
				  int f;
				  while (1)
				  {
					  cout << "Enter name of vegetable to search:\n" << endl;
					  cin >> str;
					  vector<ovos>::iterator ut = search_smth(vovos, str);
					  if (ut != vovos.end())
					  {
						  cout << "Change information about it?\n1.Yes\n2.No\n3.Return to menu\n\n\n";
						  cin >> f;
						  switch (f)
						  {
						  case 1:
						  {
									while (1)
									{
										int k;
										cout << "What would you like to change?\n1.The name\n2.The price (1 lb)\n3.GMO\n4.Amount (in lb)\n5. Return to previous menu\n\n\n";
										cin >> k;
										switch (k)
										{
										case 1:
										{
												  cout << "Enter new vegetable name: \n";
												  ut->ust_string();
										}
										case 2:
										{
												  cout << "Enter new vegetable price:\n";
												  ut->ust_double();
										}
										case 3:
										{
												  cout << "Enter a new indicator of presence of GMOs (1 - yes, 0 - no)\n";
												  ut->ust_bool();
										}
										case 4:
										{
												  cout << "Enter new vegetable amount (in lb)\n";
												  ut->ust_doub();
										}
										case 5: break;
										}
									}
						  }
						  case 2: break;
						  case 3: break;
						  }
					  }
				  }
				  break;
		}
		case 6:
		{
				  string str;
				  int f;
				  while (1)
				  {
					  cout << "Enter name of fruit to search:\n" << endl;
					  cin >> str;
					  vector<fruit>::iterator ut = search_smth(vfru, str);
					  if (ut != vfru.end())
					  {
						  cout << "Change information about it?\n1.Yes\n2.No\n3.Return to menu\n\n\n";
						  cin >> f;
						  switch (f)
						  {
						  case 1:
						  {
									while (1)
									{
										int k;
										cout << "What would you like to change?\n1.The name\n2.The price (1 lb)\n3.Country of origin\n4.Amount (in lb)\n5. Return to previous menu\n\n\n";
										cin >> k;
										switch (k)
										{
										case 1:
										{
												  cout << "Enter new fruit name: \n";
												  ut->ust_string();
										}
										case 2:
										{
												  cout << "Enter new fruit price:\n";
												  ut->ust_double();
										}
										case 3:
										{
												  cout << "Enter new fruit country of origin\n";
												  ut->ust_smth();
										}
										case 4:
										{
												  cout << "Enter new fruit amount (in lb)\n";
												  ut->ust_doub();
										}
										case 5: break;
										}
									}
						  }
						  case 2: break;
						  case 3: break;
						  }
					  }
				  }
				  break;
		}
		case 7:
		{
				  file_save(vovos, right, user_name);
				  break;
		}
		case 8:
		{
				  file_save(vfru, right, user_name);
				  break;
		}
		case 9:
		{
				  vovos = load_file(right2);
				  break;
		}
		case 10:
		{
				   vfru = load_file(right);
				   break;
		}
		case 11:
		{
				   print_smth(vovos);
				   break;
		}
		case 12:
		{
				   print_smth(vfru);
				   break;
		}
		case 13:
		{
				   t++;
				   break;
		}
		}
		if (t!=0)
		break;
	}
}
void reg(vector<password>& vpas)
{
	string sdf, dfg;
	int fgh;
	password gi;
	cout << "New User Registration:\nEnter your username, password and program version(1 - Premium, 2 - Free, 3 - Trial): " << endl;
	cin >> sdf;
	gi.set_name(sdf);
	cin >> dfg;
	gi.set_pass(dfg);
	cin >> fgh;
	gi.set_access(fgh);
	vpas.push_back(gi);
}

int main()
{
	vector<password> vpas;
	vector<password>::iterator bh;
	vector<ovos> vovos;
	vector<fruit> vfru;
	fruit gu;
	ovos gy;
	password gi;
	string sdf,dfg;
	int asd = 0;
	int h;
    int xcv = 0;
	CreateDirectoryW(L"C:\\BBase", NULL);
	CreateDirectoryW(L"C:\\BBase\\Pass", NULL);
	ifstream in("C:\\BBase\\Pass\\key.serd");
	while (in)
	{
		string str1, str2;
		int fgh;
		in >> str1 >> str2 >> fgh;
		gi.set_name(str1);
		gi.set_pass(str2);
		gi.set_access(fgh);
		vpas.push_back(gi);
	}
	if (vpas.capacity())
	{
		vpas.pop_back();
	}
	while (1)
	{
		if (!vpas.capacity())
		{
			reg(vpas);
		}
		else
		{
			vector<password>::iterator hj = vpas.end();
			vector<password>::iterator it = vpas.begin();
			cout << "Authorization:\n1. Register\n2. Log into existing account\n " << endl;
			cin >> h;
			switch (h)
			{
			case 1:
			{
					  reg(vpas);
					  break;
			}
			case 2:
			{
					  while (1)
					  {
						  cout << "Enter username and password: " << endl;
						  cin >> sdf;
						  cin >> dfg;
						  for (it; it != vpas.end(); it++)
						  {
							  if ((it->get_name() == sdf) && (it->get_pas() == dfg))
							  {
								  hj = it;
							  }
						  }
						  if (hj != vpas.end())
						  {
							  menu(vovos, vfru, hj->get_access(), hj->get_name());
							  vector<password>::iterator uy = vpas.begin();
							  ofstream out("C:\\BBase\\Pass\\key.serd");
							  for (uy; uy != vpas.end(); uy++)
							  {
								  out << uy->get_name();
								  out << " ";
								  out << uy->get_pas();
								  out << " ";
								  out << uy->get_access();
								  out << "\n";
							  }
							  asd++;
							  break;
						  }
						  else
						  {
							  cout << "Invalid username and/or password. Try again. Maybe, you want return to main menu?" << endl << "1. Return to main menu\n2. Try again\n";
							  int asg;
							  cin >> asg;
							  if (asg == 1)
								  xcv++;
						  }
						  if (xcv != 0)
							  break;
					  }
					  break;
			}
			}
		}
		if (asd != 0)
		break;
	}
	return 0;
}