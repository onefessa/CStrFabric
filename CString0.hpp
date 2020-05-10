#ifndef CSTRING0_HPP
#define CSTRING0_HPP

#include "CString.hpp"
#include<iostream>
#include"fstream"
#include<string>
using namespace std;

class CString0: public CString
{
public:
    CString0(): CString(){};
    CString0(const int dlina, const string& FileName): CString(dlina, FileName){};
    CString0 (const string& pstr): CString (pstr){};
    CString0(const string& FileName, const string& new_str): CString(FileName, new_str){};
    CString0(const string& FileName, const CString& s): CString(FileName, s) {};
    CString0(const CString& s):CString(s){};
    virtual ~CString0();
    //void out();
    const CString0 operator +(const CString &s);
    using CString::operator =;
    int output() override final;
};
#endif


