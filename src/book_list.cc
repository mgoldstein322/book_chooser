#include "book_list.h"

/**
 * create struct with empty strings
 */
book::book(void) : title(""), author("") {}
/**
 * create struct with these two values
 */
book::book(std::string title, std::string author) : title(title), author(author) {}

/**
 * asignment operator
 */
book book::operator=(book& RHS){
    this->title = RHS.title;
    this->author = RHS.author;
    return *this;
}

const book_t default_book;

/**
 * equality operator
 */
bool book::operator==(book& RHS){
    using namespace std;
    bool res = false;
    if(this->title == RHS.title && this->author != RHS.author){
        cout << "Is " << *this << " the same book as " << RHS << "? [y/n]" << endl;
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y'){
            res = true;
        }
    } else if (this->title == RHS.title && this->author == RHS.author){
        res = true;
    } else {
        res = false;
    }
    return res;
}

/**
 * insertion stream operator
 */
std::ostream& operator<<(std::ostream& os, const book& book){
    using namespace std;
    cout << book.title << " by " << book.author;
    return os;    
}

/**
 * create vector of books given a file containing a list of books
 * @param path string to file containing list
 */
book_list::book_list(const std::string path){
    //
}

/**
 * create combined list given two lists
 * @param list1
 * @param list2
 */
book_list::book_list(book_list& list1, book_list& list2){
    //
}

/**
 * create combined list given vector of books
 * @param list_vec
 */
book_list::book_list(const std::vector<book_t>& list_vec){
    //
}

/**
 * copy constructor
 * @param list 
 */
book_list::book_list(const book_list& list){
    //
}

/**
 * given both partial lists after combining the two given lists,
 * ask which books to keep from each list
 * @param partial1
 * @param partial2
 * @return full final list
 */
book_list book_list::ask_which_books(book_list& partial1, book_list& partial2){
    //
}

/**
 * determine if list contains a given book
 * @param book book to find
 * @return true if found
 */
bool book_list::contains(book_t book){
    bool res = false;
    for(int i = 0; i < this->books.size(); i++){
        if(books[i] == book){
            res = true;
            break;
        }
    }
    return res;
}

/**
 * remove a given book from the list
 * @param book
 */
void remove(book_t& book){
    //
}

/**
 * indexing operator
 * @return copy of book at index location
 */
book_t& book_list::operator[](int i){
    using namespace std;
    if(i < 0 || i > (this->books.size() - 1)){
        cout << "book_list index out of bounds error" << endl;
        return const_cast<book_t&>(default_book);
    } else {
        return this->books[i];
    }
}

/**
 * insertion stream operator
 */
std::ostream& operator<<(std::ostream& os, const book_list& list){
    using namespace std;
    for(int i = 0; i < 10; i++){
        cout << const_cast<book_list&>(list)[i] << '\n';
    }
    cout << flush;
    return os;
}