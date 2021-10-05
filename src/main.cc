#include "book_list.h"
#include <iostream>

void test0(void);
void test1(void);
void test2(void);
void test3(void);

int main(int argc, char** argv){
    using namespace std;
    cout << "run tests" << endl;
    
    test1();
    test2();
    test3();

    return 0;
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