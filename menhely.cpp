#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Allat{
	string nev;
	string faj;
	string kor;
	string szin;
};

istream& operator>>(istream& in, Allat& a) {
    in >> a.nev >> a.faj >> a.kor >> a.szin;
    return in;
}

void operator<<(ostream& out, Allat& a) {
	cout << a.nev << ": " <<a.faj<< ", " << a.kor << ", " << a.szin <<endl;
}

string operator==(struct Allat& a, string s) {
      if (s == "név") {
            return a.nev;
      }
      else if (s == "kor") {
            return a.kor;
      }
      else if (s == "szín") {
            return a.szin;
      }
      else if (s == "faj") {
            return a.faj;
      }
      else return "";
}

void keres(vector<Allat> v) {
    string attr,ert;
	cout<<"Attributum: ";
	cin>>attr;
	cout<<"Ertek: ";
	cin>>ert;
	int db = 0;
	for (Allat a : v) {
            string mezo = (a==attr);
            if (mezo == ert) {
                  cout<<a;
		  db++;
            }
	}
	cout << "A rekordok szama: " << db << endl;
}



int main() {
	ifstream in("menhely.txt");
    	vector<Allat> v;
    	Allat a;
	while (in>>a) {
		v.push_back(a);
	}
    	keres(v);
    	in.close();

	return 0;
}
