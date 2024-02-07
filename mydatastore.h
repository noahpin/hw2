
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"

class MyDataStore : public DataStore
{

public:
    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product *p);

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User *u);
    

    /**
     * Adds a product to the cart
     */
    virtual void addProductToUserCart(std::string username, Product *p);

    virtual void viewCart(std::string username);

    virtual void buyCart(std::string username);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product *> search(std::vector<std::string> &terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream &ofile);

private:
    std::vector<Product *> products_;
    std::map<std::string, User *> users_;
    std::map<std::string, std::vector<Product *> > userCart_;
    std::map<std::string, std::set<Product *> > keywords_;
};