#pragma once
#include <iostream>

using namespace std;

class site {
private:
	int data;
	site* left;
	site* right;
	site* parent;
public:
	site();
	site(int _data);
	~site();
	void setdata(int _data);
	void setleft(site* _site);
	void setright(site* _site);
	void setparent(site* _site);
	site* getleft();
	site* getright();
	site* getparent();
	int getdata();
	bool operator==(const site &_site);
	bool operator!=(const site &_site);
	bool operator>(const site &_site);
	bool operator<(const site &_site);
	bool operator>=(const site &_site);
	bool operator<=(const site &_site);
};

class binary_tree {
public:
	site* head;
	binary_tree();
	~binary_tree();
	void add(int _data);
	site* search(int _data);
	void del(site *z);
	void writetree();
};