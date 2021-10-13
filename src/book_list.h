#include <vector>
#include <string>
#include <iostream>
#include <fstream>

typedef struct book book_t;
struct book {
    public:
        std::string title;
        std::string author;
        int rank = 0;

        /**
         * create struct with empty strings
         */
        book(void);

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
        bool operator==(book& RHS) const;

        /**
         * equality operator
         */
        bool operator==(const book& RHS) const;

        /**
         * less than operator
         */
        bool operator<(book& RHS) const;

        /**
         * insertion stream operator
         */
        friend std::ostream& operator<<(std::ostream& os, const book& book);
};

class book_list {
    private:
        std::vector<book_t> books;

        /**
         * determine if list contains a given book
         * @param book book to find
         * @return true if found
         */
        bool contains(book_t& book) const;

        /**
         * print only books without a priority assigned
         */
        void print_no_priority(void) const;

        /**
         * mark the book with the priority
         * @param selection number passed in by the user
         * @param temp pointer where book will be placed
         * @return true if nothing found
         */
        bool parse_selection(int selection, book_t **temp);

        /**
         * recursive call of sort - will pivot based on last index always
         * @param low starting index
         * @param high ending index
         */
        void sort_rec(int low, int high);

        /**
         * partition function to break books vector
         * @param low starting index
         * @param high ending index
         * @return partition index - last index of the lower partition
         */
        int partition(int low, int high);

        /**
         * reset all priorities to 0
         */
        void reset(void);
    
    public:
        /**
         * create empty vector
         */
        book_list(void);

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
        book_list(book_list& list1, book_list& list2);

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

        /**
         * given both partial lists after combining the two given lists,
         * ask which books to keep from each list
         * @param partial1
         * @param partial2
         */
        void ask_which_books_to_keep(book_list& partial1, book_list& partial2);

        /**
         * determine priority for the books in this list
         */
        void determine_priority(void);

        /**
         * remove a given book from the list
         * @param book
         */
        void remove(book_t& book);

        /** 
         * sort books in ascending order of priority value
         */
        void sort(void);

        /**
         * get size of list
         * @return list size
         */
        size_t size(void) const;

        /**
         * indexing operator
         * @return reference to book at index location
         */
        book_t& operator[](int i);

        /**
         * assignment operator
         * @param RHS book_list being copied from
         * @return reference to book_list after assignment
         */
        book_list& operator=(book_list& RHS);

        /**
         * insertion stream operator
         */
        friend std::ostream& operator<<(std::ostream& os, const book_list& list);
};