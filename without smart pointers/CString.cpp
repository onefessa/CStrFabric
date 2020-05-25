#include "CString.hpp"
#include<string.h>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

CString::CString(){
   SetZero();
}
/*
CString::CString(int dlina) {
    str = new char[dlina];
    len = dlina;
    strcpy(f_name, "test.txt");
    //f_name = new char[20];
}*/
CString :: CString(const int dlina, const string& FileName){
    fstream clear_file(FileName, ios::out);
    clear_file.close();
    len = dlina;
    f_name = FileName;
    str.resize(dlina);
}

CString::CString(const string& FileName, const string& new_str){
    f_name = FileName;
    fstream clear_file(FileName, ios::out);
    clear_file.close();

    str = new_str;
    len = new_str.length();
}
CString::CString(const CString& s) {
    str = s.str;
    f_name = s.f_name;
    len = s.len;
}
CString::CString (const string& pstr){
    SetZero();
    str = pstr;
    len = pstr.length();
}
void CString::SetZero() {
    len = 0;
    f_name = "test.txt";// = new char[20];
    fstream clear_file(f_name, ios::out);
    clear_file.close();
    //str.resize(0);
}
CString::CString(const string& FileName, const CString& s) {
   // str = new string; f_name = new string;
    str = s.str;
    f_name = FileName;
    fstream clear_file(FileName, ios::out);
    clear_file.close();

    len = s.len;
}
CString::~CString() {
    len = 0;
   // cout<<" ~str"<<endl;
}
CString&  CString::operator = (const CString& s){
    len = s.len;
    str = s.str;
    f_name = s.f_name;
    return *this;
}
/*
void CString::out(){
        cout<<str<<" ";
}
*/
