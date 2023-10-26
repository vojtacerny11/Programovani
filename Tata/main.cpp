#include <iostream>
using namespace std;

class Obdelnik {
	int sirka, vyska;
	public:
		Obdelnik (int a, int b);
		void nastav_hodnoty(int a, int b);
		int obsah() {return sirka * vyska;}
};

Obdelnik::Obdelnik (int a, int b) {
	Obdelnik::sirka = a;
	Obdelnik::vyska = b;
}

void Obdelnik::nastav_hodnoty (int a, int b) {
	Obdelnik::sirka = a;
	Obdelnik::vyska = b;
	cout << "Nastavil jsem nove hodnoty obdelniku (" << a << ", " << b << ")!" << endl;
}

int main(){
	int x, y;
	Obdelnik obd(0, 0);
	while (true) {
		cout << endl << "Zadejte sirku: "; // Type a number and press enter
		cin >> x; // Get user input from the keyboard
		cout << "Zadejte vysku: "; // Type a number and press enter
		cin >> y; // Get user input from the keyboard
		obd.nastav_hodnoty(x, y);
		cout << "Obsah obdelniku je: " << obd.obsah() << endl;
	}
	return 0;
}


//konec