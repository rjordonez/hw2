#include "movie.h"
#include "util.h"
#include <sstream>

using namespace std;

Movie::Movie(const std::string& category, const std::string& name, double price, int qty, const std::string& genre, const std::string& rating) 
    : Product(category, name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

string Movie::displayString() const {
    stringstream ss;
    ss << name_ << "\n" << "Genre: " << genre_ << " Rating: " << rating_ << std::endl << price_ << " "<<  qty_ << " left.";
    return ss.str();
}

void Movie::dump(ostream& os) const {
    Product::dump(os); 
    os << genre_ <<"\n"<<rating_<< "\n";
}
set<string> Movie::keywords() const {
    
    std::set<std::string> keywords;
    std::set<std::string> nameKeywords = parseStringToWords(name_);
    std::set<std::string> genreKeywords = parseStringToWords(genre_);
    std::set<std::string> ratingKeywords = parseStringToWords(rating_);


    keywords = setUnion(nameKeywords, genreKeywords);
    keywords = setUnion(keywords, ratingKeywords);
    

    
    return keywords;
}

