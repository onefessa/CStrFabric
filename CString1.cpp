#include "CString1.hpp"
#include <fstream>
#include<iostream>
#include <string.h>
#include<string>
using namespace std;

const CString1 CString1::operator + (const CString &s){
    CString *tmp = new CString1;
   // delete tmp->f_name;
    tmp->f_name  = f_name;
   // delete tmp->str; tmp->str = new string;
    tmp->str = str + s.str;
    tmp->len = len + s.len;
    return *tmp;
}
int CString1::output() {
    ofstream myfile(this->f_name, ios_base::app);
    if( !myfile.is_open() ) {
        cout<<"Can't open your file"<<this->f_name<<endl;
        return 1;
    }
    else {
        for (auto iter = str.begin(); iter != str.end(); iter++){
            myfile << *iter << "\n";
        }
       // myfile<<str;
        myfile<<"\n";
        myfile.close();
    }
return 0;
}
CString1::~CString1(){
   // std::cout<<" ~1 ";
}
