#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <queue>
#include <map>
#include "product_parser.h"
#include "user.h"
class MyDataStore: public DataStore{
    public:
    MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     * use setIntersection function from util.h or setUniion from util.h
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    bool userNameContains(const std::string& username);
    void dump(std::ostream& ofile);
    void addToCart(const std::string& username, Product* product);
    void viewCart(const std::string& username);
    void buyCart(const std::string& username);
    
    private:
    std::map<std::string, User*> userMap;
    std::set<Product*> productSet;
    std::map<std::string, std::queue<Product*>> userCarts;
    std::queue<Product*> tempStorage;
};

#endif