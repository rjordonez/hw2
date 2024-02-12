#include "MyDataStore.h"
#include "util.h"
#include "product_parser.h"

MyDataStore::MyDataStore(){}
MyDataStore::~MyDataStore(){
for(Product* p : productSet) {
    delete p;
}
productSet.clear(); 

for(std::pair<const std::string, User*> &pair : userMap) {
    delete pair.second;
}
userMap.clear(); 

for(std::pair<const std::string, std::queue<Product*>> &pair : userCarts) {
    std::queue<Product*>& cart = pair.second;
    while (!cart.empty()) {
        cart.pop(); 
}
}
}
void MyDataStore::addProduct(Product* p)
{
    productSet.insert(p);
}
void MyDataStore::addUser(User* newUser)
{
    if (newUser == nullptr) {
        
        return;
    }

    std::string username = newUser->getName();
    
    
    if (userMap.find(username) != userMap.end()) {
       
        return;
    }

    userMap[username] = newUser;

    userCarts[newUser->getName()] = std::queue<Product*>();
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::set<Product*> resultSet;
    if (type == 0) { 
    std::vector<std::set<Product*>> termSets;

    for (std::vector<std::string>::const_iterator termIt = terms.begin(); termIt != terms.end(); ++termIt) {
        std::string lowerCaseTerm = *termIt;
        std::transform(lowerCaseTerm.begin(), lowerCaseTerm.end(), lowerCaseTerm.begin(), ::tolower);

        std::set<Product*> termSet;

        for (std::set<Product*>::iterator prodIt = productSet.begin(); prodIt != productSet.end(); ++prodIt) {
            Product* product = *prodIt;
            const std::set<std::string>& keywords = product->keywords();

            bool termFound = false;
            for (const std::string& keyword : keywords) {
                std::string lowerCaseKeyword = keyword;
                std::transform(lowerCaseKeyword.begin(), lowerCaseKeyword.end(), lowerCaseKeyword.begin(), ::tolower);

                if (lowerCaseKeyword.find(lowerCaseTerm) != std::string::npos) {
                    termFound = true;
                    break;  
                }
            }

            if (termFound) {
                termSet.insert(product);
            }
        }

        termSets.push_back(termSet);
    }

    if (!termSets.empty() && termSets.size() == terms.size()) {
        resultSet = termSets.front();

        for (size_t i = 1; i < termSets.size(); ++i) {
            resultSet = setIntersection(resultSet, termSets[i]);
        }
    } 
}


    else if (type == 1) {
        for (Product* product : productSet) {
            const std::set<std::string>& keywords = product->keywords();

            for (const std::string& term : terms) {
                if (keywords.find(term) != keywords.end()) {
                    resultSet.insert(product);
                    break; 
                }
            }
        }
    }

    return std::vector<Product*>(resultSet.begin(), resultSet.end());
}
bool MyDataStore::userNameContains(const std::string& username) {
    std::map<std::string, User*>::iterator it = userMap.find(username);
    return it != userMap.end();

}
void MyDataStore::dump(std::ostream& ofile) {

    ofile << "<products>" << std::endl;
    for (Product* product : productSet) {
        product->dump(ofile);
    }
    ofile << "</products>\n<users>" << std::endl;
    
    for(std::pair<const std::string, User*> &pair : userMap) {
    pair.second->dump(ofile);
  }
    ofile << "</users>" << std::endl;

}
void MyDataStore::addToCart(const std::string& username, Product* product) {
        userCarts[username].push(product);
    }

void MyDataStore::viewCart(const std::string& username) {
        if (userCarts.find(username) == userCarts.end()) {
            std::cout << "Invalid username" << std::endl;
            return;
        }

        std::queue<Product*> tempCart = userCarts[username];  // Make a copy to preserve the original cart
        int count = 1;
        while (!tempCart.empty()) {
            std::cout << "Item "<< count << std::endl << tempCart.front()->displayString() << std::endl;
            tempCart.pop();
            count++;
        }
    }
void MyDataStore::buyCart(const std::string& username) {

    if (userCarts.find(username) == userCarts.end()) {
        std::cout << "Invalid username" << std::endl;
        return;
    }


    std::queue<Product*>& cart = userCarts[username];

 
    std::map<std::string, User*>::iterator userIter = userMap.find(username);
    if (userIter == userMap.end()) {
        std::cout << "User not found in userMap" << std::endl;
        return;
    }


    User* user = userIter->second;

    while (!cart.empty()) {
        Product* product = cart.front();
        cart.pop();
        if (product->getQty() > 0 && user->getBalance() >= product->getPrice()) {
           
            product->subtractQty(1); 
            user->deductAmount(product->getPrice());
        } else {
            
            tempStorage.push(product);
        }
    }

    while (!tempStorage.empty()) {
        cart.push(tempStorage.front());
        tempStorage.pop();
    }
}