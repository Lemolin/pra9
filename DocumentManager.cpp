#include"DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
		Document* d = new Document();
		d->name = name;
		d->id = id;
		d->license_limit = license_limit;
		d->borrowed_times = 0;
		doc[id] = *d;
}

void DocumentManager::addPatron(int patronID) {
	patron.push_back(patronID);
}

int DocumentManager::search(string name) {
	for (auto it = doc.begin(); it != doc.end(); ++it) {
			if (it->second.name == name) {
				return it->first;
			}
		}
		return 0;

}
bool DocumentManager::borrowDocument(int docid, int patronID) {
	bool docValid = false;
		bool validId = false;
		for (auto it = doc.begin(); it != doc.end(); ++it) {
			if (it->first==docid) {
				if (it->second.borrowed_times < it->second.license_limit) {
					it->second.borrowed_times++;
					it->second.borrow_patron_ID.push_back(patronID);

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
	for (auto it = doc.begin(); it != doc.end(); ++it) {
			if (it->first == docid) {
				it->second.borrowed_times--;
				auto iter = remove(it->second.borrow_patron_ID.begin(), it->second.borrow_patron_ID.end(), patronID);
			}
		}


}
