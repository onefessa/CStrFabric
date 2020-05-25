#include "CString0.hpp"
#include <fstream>
#include<iostream>
#include <string.h>
#include<string>
using namespace std;

const CString0 CString0::operator + (const CString &s){
    CString *tmp = new CString0;
    tmp->f_name  = f_name;
    tmp->str = str + s.str;
    tmp->len = len + s.len;
    return *tmp;
}

int CString0::output() {
    ofstream myfile(this->f_name, ios_base::app);
    if( !myfile.is_open() ) {
        cout<<"Can't open your file"<<this->f_name<<endl;
        return 1;
    }
    else {
        myfile<<str;
        myfile<<"\n\n";
        myfile.close();
    }
return 0;
}
CString0::~CString0(){
   // std::cout<<" ~0 ";
}

