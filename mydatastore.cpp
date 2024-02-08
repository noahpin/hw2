#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"
#include "mydatastore.h"
using namespace std;

MyDataStore::~MyDataStore() {
    for(int i = 0; i < products_.size(); i++) {
        delete products_[i];
    }
    for(map<string, User *>::iterator it = users_.begin(); it != users_.end(); ++it) {
        delete it->second;
    }
}

/**
 * Adds a product to the data store
 */

void MyDataStore::addProduct(Product *p)
{
    products_.push_back(p);
    // check the products keywords and add it to the keywords_ map
    set<string> keywords = p->keywords();
    for (set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it)
    {
        string keyword = *it;

        keywords_[keyword].insert(p);
    }
}

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User *u)
{
    users_.insert(make_pair(u->getName(), u));
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product *> MyDataStore::search(std::vector<std::string> &terms, int type)
{
    std::set<Product *> hits;

    for (int i = 0; i < terms.size(); i++) 
    {
        string term = terms[i];
        set<Product *> productsOfTerm = keywords_[term];
        if(i == 0) {
            hits = productsOfTerm;
        } else {
            if(type == 0) {
                hits = setIntersection(hits, productsOfTerm);
            } else {
                hits = setUnion(hits, productsOfTerm);
            }
        }
    }
    vector<Product *> hitsVector;
    for(set<Product *>::iterator it = hits.begin(); it != hits.end(); ++it) {
        hitsVector.push_back(*it);
    }
    return hitsVector;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream &ofile)
{
    ofile << "<products>" << endl;
    for (int i = 0; i < products_.size(); i++)
    {
        products_[i]->dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    for (map<string, User *>::iterator it = users_.begin(); it != users_.end(); ++it)
    {
        it->second->dump(ofile);
    }
    ofile << "</users>" << endl;
}

/**
 * This derived class may define non-virtual functions to
 * do other specific commands that the menu supports.
 * It might be a good idea to have one member function in this
 * class that corresponds to and performs each command from the menu options.
 */


void MyDataStore::addProductToUserCart(std::string username, Product *p) {
    userCart_[username].push_back(p);
}
void MyDataStore::viewCart(std::string username){
    vector<Product *> cart = userCart_[username];
    for(int i = 0; i < cart.size(); i++) {
      cout << "Item " << i + 1 << endl;
        cout << cart[i]->displayString() << endl;
    }

}
void MyDataStore::buyCart(std::string username){
    vector<Product *> cart = userCart_[username];
    vector<Product *> resultCart;
    for(int i = 0; i < cart.size(); i++) {
        if(cart[i]->getQty() > 0 && users_[username]->getBalance() >= cart[i]->getPrice()) {
            cart[i]->subtractQty(1);
            users_[username]->deductAmount(cart[i]->getPrice());
        }else {
          resultCart.push_back(cart[i]);
        }
    }
    userCart_[username].clear();
    for(int i = 0; i < resultCart.size(); i++) {
      userCart_[username].push_back(resultCart[i]);
    }

}

bool MyDataStore::userExists(string username) {
  map<string, User *>::iterator it;
  it = users_.find(username);
  if(it != users_.end()) {// found
    return true;
  }
  return false;
}