#include "binary_tree.h"

site::site() {
	data = NULL;
	left = NULL;
	right = NULL;
	parent = NULL;
}
site::site(int _data) {
	data = _data;
	left = NULL;
	right = NULL;
	parent = NULL;
}
site::~site() {
}
void site::setdata(int _data) {
	data = _data;
}
void site::setleft(site* _site) {
	left = _site;
}
void site::setright(site* _site) {
	right = _site;
}
void site::setparent(site* _site) {
	parent = _site;
}
site* site::getleft() {
	return left;
}
site* site::getright() {
	return right;
}
site* site::getparent() {
	return parent;
}
int site::getdata() {
	return data;
}
bool site::operator==(const site &_site) {
	if (data == _site.data) return 1;
	else return 0;
}
bool site::operator!=(const site &_site) {
	if (data != _site.data) return 1;
	else return 0;
}
bool site::operator>(const site &_site) {
	if (data > _site.data) return 1;
	else return 0;
}
bool site::operator<(const site &_site) {
	if (data < _site.data) return 1;
	else return 0;
}
bool site::operator>=(const site &_site) {
	if (data >= _site.data) return 1;
	else return 0;
}
bool site::operator<=(const site &_site) {
	if (data <= _site.data) return 1;
	else return 0;
}
binary_tree::binary_tree() {
	head = new site();
}
binary_tree::~binary_tree() {

}
void binary_tree::add(int _data) {
	site *temp, *current, *parent_;

	/***********************************************
	*  allocate node for data and insert in tree  *
	***********************************************/

	/* find temp's parent */
	current = head;
	parent_ = NULL;
	while (current) {
		if (_data == current->getdata()) return;
		parent_ = current;
		if (_data < current->getdata()) current = current->getleft();
		else current = current->getright();
	}

	/* setup new node */
	temp = new site(_data);
	temp->setparent(parent_);

	/* insert temp in tree */
	if (parent_)
		if (temp->getdata() < parent_->getdata())
			parent_->setleft(temp);
		else
			parent_->setright(temp);
	else
		head = temp;
	return;
}
site* binary_tree::search(int _data) {
	/*******************************
	*  find node containing data  *
	*******************************/
	site *current = head;
	while (current != NULL)
		if (_data == current->getdata())
			return (current);
		else
			if (_data < current->getdata()) current = current->getleft();
			else current = current->getright();
			return NULL;
}
void binary_tree::del(site *z) {
	site *x, *y;

	/*****************************
	*  delete node z from tree  *
	*****************************/

	/* y will be removed from the parent chain */
	if (!z || z == NULL) return;

	/* find tree successor */
	if (z->getleft() == NULL || z->getright() == NULL)
		y = z;
	else {
		y = z->getright();
		while (y->getleft() != NULL) y = y->getleft();
	}

	/* x is y's only child */
	if (y->getleft() != NULL)
		x = y->getleft();
	else
		x = y->getright();

	/* remove y from the parent chain */
	if (x) x->setparent(y->getparent());
	if (y->getparent())
		if (y == y->getparent()->getleft())
			y->getparent()->setleft(x);
		else
			y->getparent()->setright(x);
	else
		head = x;

	/* y is the node we're removing */
	/* z is the data we're removing */
	/* if z and y are not the same, replace z with y. */
	if (y != z) {
		y->setleft(z->getleft());
		if (y->getleft()) y->getleft()->setparent(y);
		y->setright(z->getright());
		if (y->getright()) y->getright()->setparent(y);
		y->setparent(z->getparent());
		if (z->getparent())
			if (z == z->getparent()->getleft())
				z->getparent()->setleft(y);
			else
				z->getparent()->setright(y);
		else
			head = y;
		delete z;
	}
	else {
		delete y;
	}
}
void binary_tree::writetree() {

}