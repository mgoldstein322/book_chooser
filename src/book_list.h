#include <vector>
#include <string>
#include <iostream>
#include <fstream>

typedef struct book book_t;
struct book {
    std::string title;
    std::string author;

    /**
     * create struct with these two values
     */
    book_t(std::string title, std::string author);
};

class book_list {
    private:
        std::vector<book_t> books;
    
    public:
        /**
         * create vector of books given a file containing a list of books
         */
        book_list(std::string path);
};