#include <iostream>
using namespace std;

typedef int T;

struct CNode {
	T elem;
	CNode* next;
};

struct CList {
	CNode* cursor;
};

void clistInit(CList& list) {
	list.cursor = NULL;
}

bool clistIsEmpty(CList& list) {
	return list.cursor == NULL;
}

T clistFront(CList& list) {
	if (clistIsEmpty(list)) throw runtime_error("Danh sach rong");
	return list.cursor->next->elem;
}

T clistBack(CList& list) {
	if (clistIsEmpty(list)) throw runtime_error("Danh sach rong");
	return list.cursor->elem;
}

void clistMoveNext(CList& list) {
	if (!clistIsEmpty(list))
		list.cursor = list.cursor->next;
}

void clistInsert(CList& list, T e) {
	CNode* v = new CNode;
	v->elem = e;
	if (list.cursor == NULL) {
		v->next = v;
		list.cursor = v;
	}
	else {
		v->next = list.cursor->next;
		list.cursor->next = v;
	}
}

void clistRemove(CList& list) {
	if (clistIsEmpty(list)) return;
	CNode* old = list.cursor->next;
	if (old == list.cursor) 
		list.cursor = NULL;
	else
		list.cursor->next = old->next;
	delete old;
}

void clistDestroy(CList& list) {
	while (!clistIsEmpty(list))
		clistRemove(list);
}

void clistPrint(CList& list) {
	if (clistIsEmpty(list)) {
		cout << "Danh sach rong\n";
		return;
	}
	CNode* start = list.cursor->next;
	CNode* p = start;
	do {
		cout << p->elem << " ";
		p = p->next;
	} while (p != start);
	cout << endl;
}


int main() {
	CList list;
	clistInit(list);

	int n;
	cout << "Nhap so luong phan tu n = "; cin >> n;

	for (int i=0; i<n; i++) {
		T x;
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		clistInsert(list, x);
	}

	cout << "Danh sach: ";
	clistPrint(list);

	T k;
    cout << "Nhap vao phan tu k: ";
    cin >> k;
	clistInsert(list, k);
    cout << "Danh sach sau khi them phan tu " << k << " vao la: ";
    clistPrint(list);
    
	clistRemove(list);
	cout<<"Danh sach sau khi xoa la: ";
	clistPrint(list);

	clistMoveNext(list);
	cout<<"Danh sách sau khi di chuyen curson: ";
	clistPrint(list);
	
	cout << "Phan tu tai cursor: " << clistBack(list) << endl;
	cout << "Phan tu sau cursor: " << clistFront(list) << endl;

	clistDestroy(list);
	return 0;
}
