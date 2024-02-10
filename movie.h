#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <string>
#include <set>

class Movie : public Product {
public:
    Movie(const std::string& category, const std::string& name, double price, int qty, const std::string& genre, const std::string& rating);

    ~Movie();

    std::string displayString() const override;
    void dump(std::ostream& os) const override;
    std::set<std::string> keywords() const override;

private:
    std::string genre_;
    std::string rating_;
};

#endif // MOVIE_H
