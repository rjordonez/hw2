#include "mydatastore.h"
#include "util.cpp"
#include <algorithm>
MyDataStore::MyDataStore()
{
}
void MyDataStore::addProduct(Product* p)
{
    productSet.insert(p);
}
void MyDataStore::addUser(User* a)
{
    userSet.insert(a);
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{

    // std::set<std::string> cSet = convertToSet(terms);
    // if(type == 0)
    // {
    //     for (std::set<Product>::iterator it = productSet.begin(); it != productSet.end(); ++it) 
    //     {
    //         setIntersection(cSet, (*it)->keywords());
    //     }
    // }
    // else if (type == 1)
    // {

    // }
    std::vector<std::set<Product*>> termSets;
    for (const std::string& term : terms) {
        std::set<Product*> termSet;
        for (Product* product : productSet) {
            if (product->keywords().find(term) != product->keywords().end()) {
                termSet.insert(product);
            }
        }
        if (!termSet.empty()) {
            termSets.push_back(termSet);
        }
    }

    std::set<Product*> resultSet;
    if (type == 0 && !termSets.empty()) {  // AND search
        resultSet = termSets.front();
        for (auto it = termSets.begin() + 1; it != termSets.end(); ++it) {
            resultSet = setIntersection(resultSet, *it);
        }
    } else if (type == 1) {  // OR search
        for (const auto& termSet : termSets) {
            resultSet = setUnion(resultSet, termSet);
        }
    }

    return std::vector<Product*>(resultSet.begin(), resultSet.end());

}
// std::set<std::string> convertToSet(const std::vector<std::string>& v) {
//     std::set<std::string> s(v.begin(), v.end());

//     return s;
// }
void MyDataStore::dump(std::ostream& ofile) {
    // Dump all products
    ofile << "Products:" << std::endl;
    for (Product* product : productSet) {
        product->dump(ofile);
    }

    // Dump all users
    ofile << "Users:" << std::endl;
    for (User* user : userSet) {
        user->dump(ofile);
    }
}