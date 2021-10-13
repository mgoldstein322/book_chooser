#include "book_list.h"
#include <iostream>
#include <utility>

typedef enum argument_status {
    PARSE_FAILURE = 0,
    PARSE_TWO_PATHS,
    PARSE_ONE_PATH,
} arg_status_e;

/**
 * Parse commmand line arguments
 * @param argc number of arguments
 * @param argv string arguments
 * @param arg_list reference to pair that lists will be placed in
 * @return failure if status is some kind of failure, or whether there is one or two paths given
 */
arg_status_e parse_args(int, char**, std::pair<book_list, book_list>&);

void test0(void);
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

int main(int argc, char** argv){
    using namespace std;
#ifndef DEBUG
    // read inputs
    pair<book_list, book_list> arg_lists;
    arg_status_e arg_stat = parse_args(argc, argv, arg_lists);
    if(arg_stat == PARSE_FAILURE){
        return 1;
    } else if(arg_stat == PARSE_ONE_PATH) {
        // determine book priority
        arg_lists.first.determine_priority();
        // sort in priority order
        arg_lists.first.sort();

        // TODO: determine accepatnce bands
        int num_bands = arg_lists.first.size();

    } else if(arg_stat == PARSE_TWO_PATHS){
        // create combined list
        book_list combined_list0(arg_lists.first, arg_lists.second);

        combined_list0.ask_which_books_to_keep(arg_lists.first, arg_lists.second);

        cout << "Combined list:\n" << combined_list0 << endl;
    }
#else
    cout << "run tests" << endl;
    test1();
    test2();
    test3();
    test4();
#endif
    return 0;
}

arg_status_e parse_args(int argc, char** argv, std::pair<book_list, book_list>& arg_lists){
    using namespace std;
    arg_status_e status = PARSE_FAILURE;
    if (argc == 2) {
        book_list new_list(argv[1]);
        arg_lists.first = new_list;
        status = PARSE_ONE_PATH;
    } else if (argc == 3) {
        book_list list1(argv[1]), list2(argv[2]);
        arg_lists.first = list1;
        arg_lists.second = list2;
        status = PARSE_TWO_PATHS;
    } else {
        cout << "Must provide arguments in the following format:\n";
        cout << "book_chooser <path_to_list>\n";
        cout << "OR\n";
        cout << "book_chooser <path-to-list1> <path-to-list2>" << endl;
    }
    return status;
}

void test0(void){
    using namespace std;
    cout << "Test 0: Pass bad path and bad list" << endl;

    book_list list("../tests/list0.txt");
}

void test1(void){
    using namespace std;

    cout << "Test 1: Read list and print" << endl;

    book_list list1("../tests/list1.txt");
    
    cout << "List 1:\n" << flush;
    cout << list1 << endl;

    book_list list2("../tests/list2.txt");
    
    cout << "List 2:\n" << flush;
    cout << list2 << endl;
}

void test2(void){
    using namespace std;

    cout << "Test 2: Copy constructor and print" << endl;

    book_list list1("../tests/list1.txt");
    
    cout << "List 1:\n" << flush;
    cout << list1 << endl;

    book_list list2(list1);
    
    cout << "List 2:\n" << flush;
    cout << list2 << endl;
}

void test3(void){
    using namespace std;

    cout << "Test 3: Combine lists and print" << endl;

    book_list list1("../tests/list1.txt");
    
    cout << "List 1:\n" << flush;
    cout << list1 << endl;

    book_list list2("../tests/list2.txt");
    
    cout << "List 2:\n" << flush;
    cout << list2 << endl;

    book_list list3(list1, list2);

    cout << "List 3:\n" << flush;
    cout << list3 << endl;
}

void test4(void){
    using namespace std;

    cout << "Test 4: Load list and determine priority and test sorting" << endl;

    book_list list1("../tests/list1.txt");

    list1.determine_priority();

    list1.sort();

    cout << list1 << endl;
}