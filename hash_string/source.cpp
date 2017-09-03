#include "h_hash.h"

using namespace std;


void main(void) {
	htable tab(8);

	tab.insert("a", 10);
	tab.insert("b", 20);
	tab.insert("c", 30);
	tab.insert("d", 40);
	tab.insert("e", 50);
	tab.insert("ef", 60);

	cout << "Hashtable:" << endl;
	tab.writetab();

	cout << endl;

	cout << "Find d: " << tab.search("d")->getdata() << endl;

	cout << endl;

	cout << "Hashtable without 1:" << endl;
	tab.del("b");
	tab.del("c");
	tab.writetab();
}