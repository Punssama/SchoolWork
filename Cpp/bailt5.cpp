#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct product {
  string id, name, brand;
};

product ProductInfo(product p) {
  cout << "ID: ";
  getline(cin, p.id);
  cout << "Name: ";
  getline(cin, p.name);
  cout << "Brand: ";
  getline(cin, p.brand);
  return p;
}

vector<product> inputProduct(vector<product> p) {
  product ps;
  char t;
  do {
    ps = ProductInfo(ps);
    p.push_back(ps);
    cout << "Nhap tiep (Y/N)? : ";
    cin >> t;
    cin.ignore();
  } while (tolower(t) != 'n');

  return p;
}

void outputProducts(vector<product> &p) {
  cout << "ID\tName\tBrand\n";
  for (product product : p) {
    cout << product.id << "\t" << product.name << "\t" << product.brand << endl;
  }
}
void outputProductsbyBrand(vector<product> &p) {
  string brand;
  cout << "Nhap vao hang: ";
  getline(cin, brand);
  cout << "ID\tName\tBrand\n";
  for (product product : p) {
    if (product.brand == brand) {
      cout << product.id << "\t" << product.name << "\t" << product.brand
           << endl;
    }
  }
}

int main() {
  vector<product> p;
  p = inputProduct(p);
  outputProducts(p);
  outputProductsbyBrand(p);
}
