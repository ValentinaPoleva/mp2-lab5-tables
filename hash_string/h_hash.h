#pragma once
#include "h_node.h"


#define DEFAULT_TABLE_SIZE 256

class htable {
public:
	node* table;
	int size;
	htable();
	htable(int _size);
	~htable();
	int hash(string _key);
	void insert(node* _node);
	void insert(string _key, T _data);
	node* search(string _key);
	void del(string _key);
	void writetab();
};

htable::htable() {
	size = DEFAULT_TABLE_SIZE;
	table = new node[size];
	for (int i = 0; i < size; i++)
		table[i].setnext(NULL);
}
htable::htable(int _size) {
	size = _size;
	table = new node[size];
	for (int i = 0; i < size; i++)
		table[i].setnext(NULL);
}

htable::~htable() {
	node *temp, *tmp;
	for (int i = 0; i < size; i++) {
		temp = table[i].getnext();
		while (temp != NULL) {
			tmp = temp;
			temp = temp->getnext();
			delete tmp;
		}
	}
	delete[] table;
}

int htable::hash(string _key) {
	int i, ln, sum = 0;
	ln = _key.length();
	for (i = 0; i < ln; i++) sum += (int)_key[i]; 
	return sum % size;
}

void htable::insert(node* _node) {
	int key;
	key = hash(_node->getkey());

	_node->setnext(table[key].getnext());
	table[key].setnext(_node);
}

void htable::insert(string _key, T _data) {
	node* _node = new node;
	
	int key;
	_node->setkey(_key);
	_node->setdata(_data);
	key = hash(_node->getkey());

	_node->setnext(table[key].getnext());
	table[key].setnext(_node);
}

node* htable::search(string _key) {
	int key = hash(_key);
	node *temp = table[key].getnext();
	while ((temp->getkey() != _key) && (temp->getnext() != NULL)) {
		temp = temp->getnext();
	}
	if (temp->getkey() == _key)
		return temp;
	else
		return NULL;
}

void htable::del(string _key) {
	node *temp = table[hash(_key)].getnext()->getnext();
	node *prev = table[hash(_key)].getnext();
	if (prev->getkey() == _key) {
		table[hash(_key)].setnext(temp);
		delete prev;
		return;
	}
	else {
		while ((temp->getkey() != _key) || (temp->getnext() != NULL)) {
			temp = temp->getnext();
			prev = prev->getnext();  
		}

		if (temp->getkey() == _key) {
			prev->setnext(temp->getnext());
			delete temp;
			return;
		}
		else
			return;
	}
}

void htable::writetab() {
	int i;
	node *temp;
	for (i = 0; i < size; i++) {
		temp = table[i].getnext();
		if (temp == NULL) continue;
		cout << "table[" << i << "]: ";
		while (temp != NULL) {
			cout << temp->getdata() << ' ';
			temp = temp->getnext();
		}
		cout << endl;
	}
}