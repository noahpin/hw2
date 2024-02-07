#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
    Product(category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
}

Book::~Book()
{

}
void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}

std::string Book::displayString() const {
    string s = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
    return s;
}

std::set<std::string> Book::keywords() const {
    //words from title, author, isbn
    set<string> titleWords = parseStringToWords(name_);
    set<string> authorWords = parseStringToWords(author_);
    
    set<string> keywords = setUnion(titleWords, authorWords);
    keywords.insert(isbn_);
    return keywords;
}