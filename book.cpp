#include "book.h"
#include <sstream>

using namespace std;
Book::Book(const std::string& category, const std::string& name, double price, int qty, const std::string& authorsName, const std::string& ISBN) : Product(category, name, price, qty), authorsName_(authorsName), ISBN_(ISBN){}
Book::~Book(){}

string Book::displayString() const {
    stringstream ss;
    ss << name_ << "\n" << "Authors Name: " << authorsName_ << " ISBN: " << ISBN_ << " Price: " << price_ << " Qty: " << qty_;
    return ss.str();
}

void Book::dump(ostream& os) const {
    Product::dump(os); 
    os << "Authors Name: " << authorsName_ <<  " ISBN: " << ISBN_ <<  endl;
}
set<string> Book::keywords() const {
    set<string> kw;
    kw.insert(name_);
    kw.insert(authorsName_);
    kw.insert(ISBN_);
    return kw;
}