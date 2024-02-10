#include "clothing.h"
#include <sstream>

using namespace std;
Clothing::Clothing(const std::string& category, const std::string& name, double price, int qty, const std::string &brand, const std::string& size) : Product(category, name, price, qty), brand_(brand), size_(size){}
Clothing::~Clothing(){}

string Clothing::displayString() const {
    stringstream ss;
    ss << name_ << "\n" << "Brand: " << brand_ << " Size: " << size_ << " Price: " << price_ << " Qty: " << qty_;
    return ss.str();
}

void Clothing::dump(ostream& os) const {
    Product::dump(os); 
    os << "Brand: " << brand_ << endl;
}
set<string> Clothing::keywords() const {
    set<string> kw;
    kw.insert(name_);
    kw.insert(brand_);
    return kw;
}