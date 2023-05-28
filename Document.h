#ifndef DOCUMENT_H
#define DOCUMENT_H
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Document {
public:
	string name;
	int id;
	int license_limit;
	int borrowed_times;
	vector<int>borrow_patron_ID;
};



#endif