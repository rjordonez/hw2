#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include <string>
#include <set>

class Clothing : public Product {
    public:
    Clothing(const std::string& category, const std::string& name, double price, int qty, const std::string &brand, const std::string& size);

    ~Clothing();

    std::set<std::string> keywords() const override;
    std::string displayString() const override;
    void dump(std::ostream& os) const override;

    private:
    std::string brand_;
    std::string size_;


};
#endif