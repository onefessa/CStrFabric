#ifndef AUTOTEST
#define AUTOTEST

#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void autotest(){
cout<<"Test 0: ";
    int c=0;
    string r = "one";
    string a = "o";
    string b = "ne";
    CString0 m (a);  //cout<< m.str<<" is_A "<<a<<endl;
    CString0 n (b);  //cout<< n.str<<" is_B "<<b<<endl;
    CString0 k; //cout<< k.str<<" is_K"<<endl;
    k = m + n;  //cout<< k.str<<" is_K+ "<<r<<endl;
    //int len = (m.str.lenght() >= n.str.lenght())? m.str.lenght() : n.str.lenght();
    if(!(k.str == r)){
        cout << "\n"<<k.str<< " != "<<r<<endl;
        c++;
    }
    //delete[] r; //r = NULL;
    if(c==0) std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 1: ";
    CString1 q (a);
    CString1 w (b);
    CString1 z;
    z = q + w;
    c=0;
    if(!(k.str==r)){
        cout << k.str<< " != "<<r<<endl;
        c++;
    }
    if(c==0) std::cout<<"Ok"<<std::endl;
    else std::cout<<"Failed"<<std::endl;

std::cout<<"Test 2: ";
    fstream clear_file("test.txt", ios::out);
    clear_file.close();
    string Filename = "test.txt";// char *Filename = (char*)CURR.c_str();
    CString0 x_(a);
    x_.f_name = "test.txt";
                    //cout<<"\nx_\t"<<(x_.f_name).length()<<" "<<x_.f_name<<" "<<(x_.str).length()<<" "<<x_.str<<endl;
    CString1 X_(a); X_.f_name =  Filename;
                    //cout<<"X_\t"<<(X_.f_name).length()<<" "<<X_.f_name<<" "<<(X_.str).length()<<" "<<X_.str<<endl;
    CString0 x(Filename, b);
                    //cout<<"x\t"<<(x.f_name).length()<<" "<<x.f_name<<" "<<(x.str).length()<<" "<<x.str<<endl;
    CString1 X(Filename, "two");
                    //cout<<"X\t"<<(X.f_name).length()<<" "<<X.f_name<<" "<<(X.str).length()<<" "<<X.str<<endl;
    CString0 x1("test.txt", a);
                    //cout<<"x1\t"<<(x1.f_name).length()<<" "<<x1.f_name<<" "<<(x1.str).length()<<" "<<x1.str<<endl;
    CString0 X3("test.txt", "three");
                    //cout<<"X3\t"<<(X3.f_name).length()<<" "<<X3.f_name<<" "<<(X3.str).length()<<" "<<X3.str<<endl;
    if ((x_.f_name == "test.txt")&&(x_.str  == "o")
        &&(X_.f_name == "test.txt")&&(X_.str == "o")
        &&(x.f_name == "test.txt")&&(x.str == "ne")
        &&(X.f_name  == "test.txt")&&(X.str == "two")
        &&(x1.f_name  == "test.txt")&&(x1.str == "o")
        &&(X3.f_name  == "test.txt")&&(X3.str == "three"))
            cout<<"Ok"<<endl;
    else cout<<"Failed"<<endl;

cout<<"Test 3: ";
    CString0 f1(x);// cout<<f1.f_name<<" (=test.txt) :  "<<f1.str<<" (=ne)"<<endl;
    if ((f1.f_name =="test.txt")&&(f1.str == "ne"))
         cout<<"Ok"<<endl;
    else cout<<"Failed"<<endl;

cout<<"Test 4: ";
    CString1 k1("three");
    CString1 K("t1.txt", k1); //cout<<"\n"<<K.f_name<<" (=t1.txt) :  "<<K.str<<" (=three)"<<endl;
    if ((K.f_name == "t1.txt")&&(K.str == "three"))
         cout<<"Ok"<<endl;
    else cout<<"Failed"<<endl;

cout<<"Test 5: ";
    CString0 k2("test.txt", "three");
    CString1 K2("t1.txt", k2); //cout<<"\n"<<K.f_name<<" (=t1.txt) :  "<<K.str<<" (=three)"<<endl;
    if ((K2.f_name == "t1.txt")&&(K2.str == "three")
        &&(k2.f_name == "test.txt")&&(k2.str == "three"))
         cout<<"Ok"<<endl;
    else cout<<"Failed"<<endl;

    x_.output();
    x.output();
    X_.output();
    X.output();
    X3.output();
cout<<"_________________"<<endl;
}
#endif

