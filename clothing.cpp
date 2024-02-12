#include "clothing.h"
#include "util.h"
#include <sstream>

using namespace std;
Clothing::Clothing(const std::string& category, const std::string& name, double price, int qty, const std::string &brand, const std::string& size) : Product(category, name, price, qty), brand_(brand), size_(size){}
Clothing::~Clothing(){}

string Clothing::displayString() const {
    stringstream ss;
    ss << name_ << "\n" << "Size: " << size_ <<" Brand: " << brand_ << std::endl << price_ << " " << qty_ << "left.";
    return ss.str();
}

void Clothing::dump(ostream& os) const {
    Product::dump(os); 
    os << size_ << "\n" << brand_ << "\n";
}
set<string> Clothing::keywords() const {
    set<string> kw;
    kw.insert(name_);
    kw.insert(brand_);
    return kw;
    std::set<std::string> keywords;
    std::set<std::string> nameKeywords = parseStringToWords(name_);
    std::set<std::string> sizeKeywords = parseStringToWords(size_);
    std::set<std::string> brandKeywords = parseStringToWords(brand_);


    keywords = setUnion(nameKeywords, sizeKeywords);
    keywords = setUnion(keywords, brandKeywords);

    return keywords;
}