#ifndef MYDATASTORE.H
#define MYDATASTORE.H

#include "datastore.h"
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
    void dump(std::ostream& ofile);
    
    // std::set<std::string> convertToSet(std::vector<std::string> v);

    private:
    std::set<User*> userSet;
    std::set<Product*> productSet;

};

#endif