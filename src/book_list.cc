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
    this->rank = RHS.rank;
    return *this;
}

/**
 * less than operator
 */
bool book::operator<(book& RHS) const{
    return this->rank <= RHS.rank;
}

const book_t default_book;

/**
 * equality operator
 */
bool book::operator==(book& RHS) const{
    using namespace std;
    bool res = false;
    if((this->title == RHS.title && this->author != RHS.author) || 
    (this->title != RHS.title && this->author == RHS.author)){
        cout << "Is " << *this << " the same book as " << RHS << "? [y/n]" << endl;
        char answer;
        cin >> answer;
        cout << endl;
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
 * equality operator
 */
bool book::operator==(const book& RHS) const{
    using namespace std;
    bool res = false;
    if(this->title == RHS.title && this->author != RHS.author){
        cout << "Is " << *this << " the same book as " << RHS << "? [y/n]" << endl;
        char answer;
        cin >> answer;
        cout << endl;
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
 * create empty vector
 */
book_list::book_list(void){}

/**
 * create vector of books given a file containing a list of books
 * @param path string to file containing list
 */
book_list::book_list(const std::string path){
    using namespace std;
    // open file at path
    ifstream file;
    file.open(path);
    if(file){
        // pull in each line to parse
        string line;
        string delimiter(" by ");
        while(getline(file, line)){
            // determine if line is valid
            int pos = line.find(delimiter);
            if(pos != string::npos) {
                // insert book into list
                string title = line.substr(0, pos);
                string author = line.substr(pos + 4);
                book_t element(title, author);
                this->books.push_back(element);
            } else {
                // exit with error
                cout << "Book format error: write to file like \'<title> by <author>\'" << endl;
                file.close();
                exit(1);
            }
        }
    } else {
        cout << "File path: " << path << " is bad." << endl;
        file.close();
        exit(1);
    }
    file.close();
}

/**
 * create combined list given two lists
 * @param list1
 * @param list2
 */
book_list::book_list(book_list& list1, book_list& list2){
    using namespace std;
    book_t temp;
    // find duplicates in lists
    if(list1.size() >= list2.size()){
        for(int i = 0; i < list1.size(); i++){
            temp = list1[i];
            if(list2.contains(temp)){
                this->books.push_back(temp);
            }
        }
    } else {
        for(int i = 0; i < list2.size(); i++){
            temp = list2[i];
            if(list1.contains(temp)){
                this->books.push_back(temp);
            }
        }
    }
    // remove duplicates from lists to create partial lists
    for(int i = 0; i < this->books.size(); i++){
        list1.remove(this->books[i]);
        list2.remove(this->books[i]);
    }
}

/**
 * create list given vector of books
 * @param list_vec
 */
book_list::book_list(const std::vector<book_t>& list_vec){
    for(int i = 0; i < list_vec.size(); i++){
        this->books.push_back(list_vec[i]);
    }
}

/**
 * copy constructor
 * @param list 
 */
book_list::book_list(const book_list& list){
    for(int i = 0; i < list.size(); i++){
        this->books.push_back(const_cast<book_list&>(list)[i]);
    }
}

/**
 * determine if list contains a given book
 * @param book book to find
 * @return true if found
 */
bool book_list::contains(book_t& book) const{
    bool res = false;
    for(int i = 0; i < this->books.size(); i++){
        if(book == books[i]){
            res = true;
            break;
        }
    }
    return res;
}

/**
 * print only books without a priority assigned
*/
void book_list::print_no_priority(void) const{
    using namespace std;
    int size = this->books.size();
    int print_num = 1;
    for (int i = 0; i < size; i++) {
        if (this->books[i].rank == 0) {
            cout << '(' << print_num << ')' << ' ' << this->books[i] << '\n';
            ++print_num;
        } else continue;
    }
    cout << flush;
}

/**
 * mark the book with the priority
 * @param selection number passed in by the user
 * @param temp pointer where book will be placed
 * @return true if nothing found
 */
bool book_list::parse_selection(int selection, book_t **temp){
    // subtract 1 from selection to match indices more easily
    --selection;
    /* loop through books, counting how many books have been passed that don't have priorities set yet
    when count matches selection, the book is found */
    int count = 0, size = this->books.size();
    for (int i = 0; i < size; ++i) {
        *temp = &this->books[i];
        if ((*temp)->rank != 0) {
            continue;
        } else {
            if (count != selection) {
                ++count;
            } else return false;
        }
    }
    return true;
}

/**
 * recursive call of sort
 * @param low starting index
 * @param high ending index
 */
void book_list::sort_rec(int low, int high){
    // TODO: thoroughly test
    if (low == high){
        // collapse execution tree
        return;
    } else {
        // divide and conquer
        int pi = partition(low, high);

        this->sort_rec(low, pi - 1);
        this->sort_rec(pi + 1, high);
    }
}

/**
 * partition function to break books vector - will pivot based on last index always
 * @param low starting index
 * @param high ending index
 * @return partition index - last index of the lower partition
 */
int book_list::partition(int low, int high){
    // save pivot value
    book_t pivot = this->books[high];
    int pi = low - 1;

    // iterate through array
    for (int j = low; j < high - 1; j++) {
        // increment pi if books[j] < pivot
        book_t temp = this->books[j];
        if (temp < pivot) {
            ++pi;
            // swap books[pi] and books[j]
            this->books[j] = this->books[pi];
            this->books[pi] = temp;
        }
    }
    // swap the pivot value with the value at the pivot index after incrementing pi one more time
    ++pi;
    book_t temp = this->books[pi];
    this->books[pi] = this->books[high];
    this->books[high] = temp;

    return pi;
}

/**
 * reset all priorities to 0
 */
void book_list::reset(void){
    int size = this->books.size();
    for(int i = 0; i < size; i++){
        this->books[i].rank = 0;
    }
}

/**
 * given both partial lists after combining the two given lists,
 * ask which books to keep from each list
 * @param partial1
 * @param partial2
 */
void book_list::ask_which_books_to_keep(book_list& partial1, book_list& partial2){
    //TODO:
}

/**
 * determine priority for the books in this list
 */
void book_list::determine_priority(void){
    using namespace std;
    int size = this->books.size();
    int priorities_assigned = 0;
    while(priorities_assigned != size){
        if (priorities_assigned == (size - 1)) {
            // mark last book with lowest priority
            for (int i = 0; i < this->books.size(); i++) {
                book_t &temp = this->books[i];
                if (temp.rank == 0) {
                    continue;
                } else {
                    temp.rank = ++priorities_assigned;
                }
            }
            cout << "Is this the order you want? [y/n]" << endl;
            this->sort();
            cout << *this << endl;
            char response = 0;
            cin >> response;
            if (response == 'y' || response == 'Y') {
                continue;
            } else if (response == 'n' || response == 'N') {
                priorities_assigned = 0;
            }
        } else {
            // TODO: determine why priority values are so high and why the final priority is not being set
            // determine which string to print out and print it
            string prompt = ((priorities_assigned == 0) ? "Which book should have the highest priority? [1, 2, 3, ...]" :
            "What is the next book in priority order? [1, 2, 3, ...]");
            cout << prompt << endl;
            this->print_no_priority();
            // take input and determine validity
            int selection;
            cin >> selection;
            while (selection > (this->books.size() - priorities_assigned) || selection < 1) {
                cout << "Please choose a valid number" << endl;
                cin >> selection;
            }
            // determine which book was selected
            book_t *temp = nullptr;
            bool result = this->parse_selection(selection, &temp);
            if(result){
                cout << "Selection error" << endl;
                exit(1);
            }
            temp->rank = ++priorities_assigned;
        }
    }
}

/**
 * remove a given book from the list
 * @param book
 */
void book_list::remove(book_t& book){
    // find book position
    int i = 0;
    for(; i < this->books.size(); i++){
        if(this->books[i] == book) break;
    }
    // confirm book was found
    if(i == (this->books.size() - 1)){
        this->books.pop_back();
    } else if(i < this->books.size()){
        // move book to end of list
        book_t temp = this->books[i];
        this->books[i] = this->books[this->books.size() - 1];
        this->books[this->books.size() - 1] = temp;
        // remove element
        this->books.pop_back();
    }
}

/** 
 * sort books in ascending order of priority value
 * performs quicksort algorithm
 */
void book_list::sort(void){
    this->sort_rec(0, this->books.size() - 1);
}

/**
 * get size of list
 * @return list size
 */
size_t book_list::size(void) const{
    return this->books.size();
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
 * assignment operator
 * @param RHS book_list being copied from
 * @return reference to book_list after assignment
 */
book_list& book_list::operator=(book_list& RHS){
    this->books.clear();
    int size = RHS.size();
    for(int i = 0; i < size; i++){
        this->books.push_back(RHS[i]);
    }
    return *this;
}

/**
 * insertion stream operator
 */
std::ostream& operator<<(std::ostream& os, const book_list& list){
    using namespace std;
    for(int i = 0; i < list.size(); i++){
        cout << '(' << (i + 1) << ") " << const_cast<book_list&>(list)[i] << '\n';
    }
    cout << flush;
    return os;
}