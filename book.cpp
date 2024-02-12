#include "book.h"
#include "util.h"
#include <sstream>

using namespace std;
Book::Book(const std::string& category, const std::string& name, double price, int qty, const std::string& authorsName, const std::string& ISBN) : Product(category, name, price, qty), authorsName_(authorsName), ISBN_(ISBN){}
Book::~Book(){}

string Book::displayString() const {
    stringstream ss;
    ss << name_ << "\n" << "Author: " << authorsName_ << " ISBN: " << ISBN_ << std::endl << price_ << " "<<qty_<<" left.";
    return ss.str();
}

void Book::dump(ostream& os) const {
    Product::dump(os); 
    os << ISBN_ << "\n" << authorsName_ << "\n";
}
set<string> Book::keywords() const {
    std::set<std::string> keywords;
    std::set<std::string> nameKeywords = parseStringToWords(name_);
    std::set<std::string> authorKeywords = parseStringToWords(authorsName_);

    keywords = setUnion(nameKeywords, authorKeywords);

    keywords.insert(ISBN_);

    return keywords;
}