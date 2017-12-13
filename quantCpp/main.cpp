//
//  main.cpp
//  CppQuantFinance
//
//  Created by Geyijie on 12/12/2017.
//  Copyright © 2017 Geyijie. All rights reserved.
//

#include <iostream>
#include "vanillaOption.h"
#include <vector>
#include <list>
#include<algorithm>
using namespace std;

struct Vector {
    int sz; // number of elements
    double* elem; // pointer to elements
};

void vector_init(Vector& v, int s) {
    v.elem = new double[s]; // allocate an array of s doubles
    v.sz = s;
    
}

double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v,s); // allocate s elements for v
    for (int i=0; i!=s; ++i)
        cin>>v.elem[i]; // read into elements
    double sum = 0;
    for (int i=0; i!=s; ++i)
        sum+=v.elem[i]; // take the sum of the elements
    return sum;
}

template<typename T>
class Less_than {
     // value to compare against
    public:
    const T val;
    Less_than(const T& v) :val(v) { }
    bool operator()(const T& x) const {
        return x<val;
        
    } // call operator
    
};



int count_x(char* p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
    if (p==nullptr) return 0; int count = 0;
    for (; *p!=0; ++p){
        cout << *p << endl;
        if (*p==x)
            ++count;
    }
    
    return count;
    
}

template<typename T>
void g(T x)
{
    cout << x << " ";
    
}

void f(){
    
}

template<typename T, typename... Tail>
void f(T head, Tail... tail){
    g(head);
    f(tail...);
}


struct Entry {
    string name;
    int number;
    
};

ostream& operator<<(ostream& os, const Entry& e) {
    return os << "{\"" << e.name << "\", " << e.number << "}";
    
}

istream& operator>>(istream& is, Entry& e)
// read { "name" , number } pair. Note: formatted with { " " , and }
{
    char c, c2;
    if (is>>c && c=='{' && is>>c2 && c2=='"') { // start with a { "
        string name; // the default value of a string is the empty string: ""
        while (is.get(c) && c!='"') // anything before a " is part of the name
            name+=c;
        
        if (is>>c && c==',') {
            int number = 0;
            if (is>>number>>c && c=='}') { // read the number and a }
                e = {name,number}; // assign to the entry
                return is;
            }
            
        }
    }
    is.setf(ios_base::failbit); // register the failure in the stream
    return is;
}

template<typename T>
void print_book(const vector<T>& book) {
    for (int i = 0; i!=book.size(); ++i)
        cout << book[i] << '\n';
}

void print_book_2(const list<Entry>& book) {
    for (const auto& x : book) // for "auto" see §2.2.2
        cout << x << '\n';
}

bool compare(const Entry& x, const Entry& y)
{
    return x.name<y.name; // order Entrys by their names
    
}

bool compare_2(const Entry& x, const Entry& y)
{
    return x.name==y.name; // order Entrys by their names
    
}

void f(vector<Entry>& vec, list<Entry>& lst) {
    list<Entry>::iterator it;
    sort(vec.begin(),vec.end(),compare); // use < for order
    print_book(vec);
    it = unique_copy(vec.begin(),vec.end(),lst.begin(),compare_2); // don’t copy adjacent equal elements
    lst.resize(std::distance(lst.begin(), it));
}

bool myfunction (int i, int j) {
    return (i==j);
}


int main(int argc, const char * argv[]) {
    // insert code here...
//    VanillaOption v;
//    cout << v.calc_put_price() <<endl;
//    char* p = "azsdabcde";
//    char x = 'a';
//    cout << count_x(p, x) << endl;
    //cout << read_and_sum(5) << endl;
//    Less_than<int> lti(42);
//    Less_than<string> lts ("Backus");
//    cout << lti.val << endl;
//    cout << lts.val << endl;
    
//    cout << "first: ";
//    f(1,2.2,"hello");
//    cout << "\nsecond: ";
//    f(0.2,'c',"yuck!",0,1,2);
//    cout << "\n";
//    for (Entry ee; cin>>ee; ) // read from cin into ee
//        cout << ee << '\n'; // write ee to cout
    
    vector<Entry> phone_book = {
        {"David Hume",123456},
        {"Karl Popper",24567},
        {"Karl Popper",245672},
        {"Bertrand Arthur William Russell",345678},
        {"Bertrand Arthur William Russell",34544678}
    };

    list<Entry> lst(5);
    f(phone_book,lst);
    
    cout << phone_book.size() << endl;
    print_book_2(lst);
    
    
//    int myints[] = {10,20,20,20,30,30,20,20,10};
//    std::vector<int> myvector (9);                            // 0  0  0  0  0  0  0  0  0
//
//    // using default comparison:
//    std::vector<int>::iterator it;
//    it=std::unique_copy (myints,myints+9,myvector.begin());   // 10 20 30 20 10 0  0  0  0
//    //                ^
//    print_book(myvector);
//    std::sort (myvector.begin(),it);                          // 10 10 20 20 30 0  0  0  0
//    //                ^
//    print_book(myvector);
//    // using predicate comparison:
//    it=std::unique_copy (myvector.begin(), it, myvector.begin(), myfunction);
//    // 10 20 30 20 30 0  0  0  0
//    //          ^
//
//    myvector.resize( std::distance(myvector.begin(),it) );    // 10 20 30
//
//    // print out content:
//    std::cout << "myvector contains:";
//    for (it=myvector.begin(); it!=myvector.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';
    return 0;
}
