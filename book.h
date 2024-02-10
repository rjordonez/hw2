#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <string>
#include <set>

class Book : public Product {
    public:
    Book(const std::string& category, const std::string& name, double price, int qty, const std::string& authorsName, const std::string& ISBN);

    ~Book();

    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

    private:
    std::string authorsName_;
    std::string ISBN_;


};
#endif