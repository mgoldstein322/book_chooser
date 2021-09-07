#include "book_list.h"

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

/**
 * equality operator
 */
bool book::operator==(book& RHS){
    return this->title == RHS.title && this->author == RHS.author;
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
book_list::book_list(const book_list& list1, const book_list& list2){
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
    //
}