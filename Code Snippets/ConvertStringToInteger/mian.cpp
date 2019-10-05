#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

void test_stoi();

void test_atoi();

void test_sstream();

using namespace std;

int main(){
    test_stoi();
    test_atoi();
    test_sstream();
    return 0;
}

void test_atoi() {
    cout << "======ATOI======" << endl;
    int i;
    char buffer[256];
//    char buffer[2];
    printf ("Enter a number: ");
    fgets (buffer, 256, stdin);
    i = atoi (buffer);
    printf ("The value entered is %d. Its double is %d.\n",i,i*2);
}

void test_stoi() {
    cout << "======STOI======" << endl;
    string str_dec = "2001, A Space Odyssey";
    string str_hex = "40c3";
    string str_bin = "-10010110001";
    string str_auto = "0x7f";

    string::size_type sz;   // alias of size_t


    int i_dec = stoi (str_dec,&sz);
    int i_hex = stoi (str_hex,nullptr,16);
    int i_bin = stoi (str_bin,nullptr,2);
    int i_auto = stoi (str_auto,nullptr,0);

    cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
    cout << str_hex << ": " << i_hex << '\n';
    cout << str_bin << ": " << i_bin << '\n';
    cout << str_auto << ": " << i_auto << '\n';
}

void test_sstream(){
    cout << "=====Stream=====" << endl;
    string num = "-123";
    stringstream stream(num);
    int re = 0;
    stream >> re;
    cout << re;
}
