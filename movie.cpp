#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
    Product(category, name, price, qty)
{
    genre_ = genre;
    rating_ = rating;
}

Movie::~Movie()
{

}
void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}

std::string Movie::displayString() const {
    string s = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
    return s;
}

std::set<std::string> Movie::keywords() const {
    //words from title, author, isbn
    set<string> keywords = parseStringToWords(name_);
    keywords.insert(convToLower(genre_));
    return keywords;
}