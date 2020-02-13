/*按格式输入输出（4.1）*/
#include<iostream>
#include<string>

int main()
{
	using namespace std;
	string fname;
	cout << "What is your dirst name?";
	getline(cin, fname);
	string lname;
	cout << "What is your last name?";
	cin >> lname;
	char grade;
	cout << "What letter grade do you deserve?";
	cin >> grade;
	int age;
	cout << "What is your age?";
	cin >> age;

	cout << "name:" << lname << "," << fname<<endl;
	cout << "Grade:" << char (grade + 1)<<endl;
	cout << "Age:" << age << endl;
 	return 0;
}


/*4.2*/
#include<iostream>
#include<string>

int main()
{
	using namespace std;
	string name;
	string dessert;
	cout << "Enter your name:\n";
	getline(cin, name);
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << name << endl;
	cout << dessert << endl;
	return 0;
}
