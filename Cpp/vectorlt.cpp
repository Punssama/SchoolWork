#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
  string ID, name;
  int year;
  double price;
};

Book insertNewBook(Book data) {
  getchar();
  cout << "ID: ";
  getline(cin, data.ID);
  cout << "Name: ";
  getline(cin, data.name);
  cout << "Year: ";
  cin >> data.year;
  cout << "Price: ";
  cin >> data.price;
  return data;
}

vector<Book> inputBooks(int &n) {
  Book b;
  vector<Book> books;
  cout << "Nhap so sach n: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Nhap vao sach thu-" << i + 1 << endl;
    b = insertNewBook(b);
    books.push_back(b);
  }
  return books;
}

void outputBooks(vector<Book> books) {
  cout << "ID\tName\tYear\tPrice\n";
  for (Book b : books) {
    cout << b.ID << "\t" << b.name << "\t" << b.year << "\t" << b.price << endl;
  }
}

int main() {
  int n;
  vector<Book> books;
  books = inputBooks(n);
  outputBooks(books);
}
