#include"DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
	d->name = name;
	d->id = id;
	d->license_limit = license_limit;
	d->borrowed_times = 0;
}

void DocumentManager::addPatron(int patronID) {
	patron.push_back(patronID);
}

int DocumentManager::search(string name) {
	for (vector<Document>::iterator it = doc.begin(); it != doc.end(); it++) {
		if ((*it).name == name) {
			return (*it).id;
		}
	}
	return 0;

}
bool DocumentManager::borrowDocument(int docid, int patronID) {
	bool docValid = false;
	bool validId = false;
	for (vector<Document>::iterator it = doc.begin(); it != doc.end(); it++) {
		if ((*it).id == docid) {
			if ((*it).borrowed_times < (*it).license_limit) {
				(*it).borrowed_times++;
				(*it).borrow_patron_ID.push_back(patronID);
				docValid = true;
			}
		}
	}
	for (vector<int>::iterator it = patron.begin(); it != patron.end(); it++) {
		if ((*it) == patronID) {
			validId = true;
		}
	}

	if (docValid == true && validId == true) {
		return true;
	}
	else {
		return false;
	}
}

void DocumentManager::returnDocument(int docid, int patronID) {
	for (vector<Document>::iterator it = doc.begin(); it != doc.end(); it++) {
		if ((*it).id == docid) {
			(*it).borrowed_times--;
			auto iter = remove((*it).borrow_patron_ID.begin(), (*it).borrow_patron_ID.end(), patronID);
		}
	}


}