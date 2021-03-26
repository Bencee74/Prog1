#include "std_lib_facilities.h"

using namespace std;

struct Person
{
private:
	string first_name;
	string last_name;
	int age;

public:
	string get_first_name() const { return first_name;} 
	string get_last_name() const { return last_name; }
	int get_age() const { return age; }
	void set_first_name(string name) { first_name = name; }
	void set_last_name(string name) { last_name = name; }
	void set_age(int x) { age = x; }

	Person() {}
	Person(string first, string last, int x) {
		first_name = first;
		last_name = last;
		age = x;
	}
};

	ostream& operator<< (ostream& os, Person& p) {
		os << "Name: " << p.get_first_name() << " " << p.get_last_name() << ", age: " << p.get_age();
		return os;
	}

	istream& operator>> (istream& is, Person& p) {
		string first;
		string last;
		int x;
		is >> first >> last;

		for(auto i : first) {
			if (!isalpha(i)) {
				error("Invalid name");
			}
		}
		p.set_first_name(first);

		for (auto i : last) {
			if (!isalpha(i)) {
				error("Invalid name");
			}
		}

		p.set_last_name(last);

		is >> x;

		if (x < 0 || x > 150) {
			error("Invalid age");
		}
		else {
			p.set_age(x);
		}

		return is;
	}
int main()
{
	/* Person person;
	person.name = "Goofy";
	person.age = 63;
	cout << "Name: " << person.name << " Age: " << person.age << endl; */

	Person p;

	cout << "Give your full name and age\n";
	cin >> p;
	cout << p << endl;

	cout << "Give full names with their ages\n";
	vector<Person> v;
	int current = 0;
	Person p2;

	while(cin >> p2) {
		v.push_back(p2);
		cout << v[current] << endl;
		current += 1;
	}


	return 0;
}
