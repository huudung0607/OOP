#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
class quannet {
private:
	string username, pass, name, in, out;
	int totalMinutes;
public:
	quannet() {}
	quannet(string username, string pass, string name, string in, string out)
	{
		this->username = username;
		this->pass = pass;
		this->name = name;
		this->in = in;
		this->out = out;
		calculateTotalMinutes();
	}
	int getGio()
	{
		stringstream ss(in), sss(out);
		string giovo, phutvo, giora, phutra;
		getline(ss, giovo, ':');
		getline(ss, phutvo, ':');
		getline(sss, giora, ':');
		getline(sss, phutra, ':');
		int gio1 = stoi(giovo);
		int gio2 = stoi(phutvo);
		int gio3 = stoi(giora);
		int gio4 = stoi(phutra);
		return gio3 - gio1;
	}
	void calculateTotalMinutes() {
		int startH, startM, endH, endM;
		char colon;
		istringstream inStream(in);
		istringstream outStream(out);
		inStream >> startH >> colon >> startM;
		outStream >> endH >> colon >> endM;
		totalMinutes = (endH * 60 + endM) - (startH * 60 + startM);
	}
	int getPhut()
	{
		stringstream ss(in), sss(out);
		string giovo, phutvo, giora, phutra;
		getline(ss, giovo, ':');
		getline(ss, phutvo, ':');
		getline(sss, giora, ':');
		getline(sss, phutra, ':');
		int gio1 = stoi(giovo);
		int gio2 = stoi(phutvo);
		int gio3 = stoi(giora);
		int gio4 = stoi(phutra);
		return gio4 - gio2;
	}
	string getUsername()
	{
		return username;
	}
	int gettotalMinutes()
	{
		return totalMinutes;
	}
	void print()
	{
		int gio = getGio();
		int phut = getPhut();
		if (phut < 0)
		{
			phut = phut + 60;
			gio--;
		}
		cout << username << " " << pass << " " << name << " " << gio << " gio " << phut << " phut" << endl;
	}
};
bool cmp(quannet x, quannet y)
{
	if (x.gettotalMinutes() != y.gettotalMinutes())
	{
		return x.gettotalMinutes() > y.gettotalMinutes();
	}
	return x.getUsername() < y.getUsername();
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<quannet> v;
	for (int i = 0; i < n; i++)
	{
		string username, pass, name, in, out;
		getline(cin, username);
		getline(cin, pass);
		getline(cin, name);
		getline(cin, in);
		getline(cin, out);
		quannet net(username, pass, name, in, out);
		v.push_back(net);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		x.print();
	}
}
