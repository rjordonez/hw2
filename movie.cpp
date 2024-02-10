#include "movie.h"
#include <sstream>

using namespace std;

Movie::Movie(const std::string& category, const std::string& name, double price, int qty, const std::string& genre, const std::string& rating) 
    : Product(category, name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

string Movie::displayString() const {
    stringstream ss;
    ss << name_ << "\n" << "Genre: " << genre_ << "Rating: " << rating_ << " Price: " << price_ << " Qty: " << qty_;
    return ss.str();
}

void Movie::dump(ostream& os) const {
    Product::dump(os); 
    os << "Genre: " << genre_ << endl;
}
set<string> Movie::keywords() const {
    set<string> kw;
    kw.insert(name_);
    kw.insert(genre_);
    return kw;
}

