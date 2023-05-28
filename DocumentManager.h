#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include"Document.h"

class DocumentManager {
private:
	vector<Document>doc;
	vector<int>patron;
	Document* d;

public:
	void addDocument(string name, int id, int license_limit);

	void addPatron(int patronID);

	int search(string name); 

	bool borrowDocument(int docid, int patronID); 

	void returnDocument(int docid, int patronID);
};


#endif
