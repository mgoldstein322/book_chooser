#include <vector>
#include <string>
#include <iostream>
#include <fstream>

typedef struct book book_t;
struct book {
    public:
        std::string title;
        std::string author;

        /**
         * create struct with these two values
         */
        book(std::string title, std::string author);

        /**
         * asignment operator
         */
        book operator=(book& RHS);

        /**
         * equality operator
         */
        bool operator==(book& RHS);
};

class book_list {
    private:
        std::vector<book_t> books;

        /**
         * given both partial lists after combining the two given lists,
         * ask which books to keep from each list
         * @param partial1
         * @param partial2
         * @return full final list
         */
        book_list ask_which_books(book_list& partial1, book_list& partial2);

        /**
         * determine if list contains a given book
         * @param book book to find
         * @return true if found
         */
        bool contains(book_t book);

    
    public:
        /**
         * create vector of books given a file containing a list of books
         * @param path string to file containing list
         */
        book_list(const std::string path);

        /**
         * create combined list given two lists
         * @param list1
         * @param list2
         */
        book_list(const book_list& list1, const book_list& list2);

        /**
         * create combined list given vector of books
         * @param list_vec
         */
        book_list(const std::vector<book_t>& list_vec);

        /**
         * copy constructor
         * @param list 
         */
        book_list(const book_list& list);
};