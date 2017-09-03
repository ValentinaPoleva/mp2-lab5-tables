#pragma once
#ifndef __h_node_h_
#define __h_node_h_
#include <string.h>
#include <iostream>

using namespace std;

typedef int T;

struct keypol {
	string k; //key
	T d;	  //data
};

class node {
protected:
	keypol data;
	node* next;
public:
	node();
	node(string _key);
	node(string _key, T _data);
	~node();
	void setdata(T _data);
	T getdata();
	void setkey(string _key);
	string getkey();
	void setnext(node* _next);
	node* getnext();
};
#endif

node::node() {
	data.d = T();
	data.k = '\0';
	next = NULL;
}

node::node(string _key) {
	data.d = T();
	data.k = _key;
	next = NULL;
}

node::node(string _key, T _data) {
	data.d = _data;
	data.k = _key;
	next = NULL;
}

node::~node() {

}

void node::setdata(T _data) {
	data.d = _data;
}

T node::getdata() {
	return data.d;
}

void node::setkey(string _key) {
	data.k = _key;
}

string node::getkey() {
	return data.k;
}

void node::setnext(node* _next) {
	next = _next;
}

node* node::getnext() {
	return next;
}