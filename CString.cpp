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
    f_name = FileName;
    fstream clear_file(FileName, ios::out);
    clear_file.close();
    len = dlina;
    char arr[dlina+1];
    str = string(arr);
}

CString::CString(const string& FileName, const string& new_str){
   // str = new string; f_name = new string;
    f_name = FileName;
    fstream clear_file(FileName, ios::out);
    clear_file.close();

    str = new_str;
    len = new_str.length();
}
CString::CString(const CString& s) {
    //str = new string; f_name = new string;
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
    //str = new string;
    len = 1;
    f_name = "test.txt";// = new char[20];
    fstream clear_file(f_name, ios::out);
    clear_file.close();

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
    //delete[] str;
    //str = NULL;
    len = 0;
    //cout<<" ~str"<<endl;
}
CString&  CString::operator = (const CString& s){
    //delete[] str;
    //str = new string;
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
