#ifndef CSTRING1_HPP
#define CSTRING1_HPP

#include "CString.hpp"
#include <fstream>
using namespace std;

class CString1: public CString
{
public:
    CString1(): CString(){};
    CString1(const int dlina, const string& FileName): CString(dlina, FileName){};
    CString1 (const string& pstr): CString (pstr){};
    CString1(const string& FileName, const string& new_str): CString(FileName, new_str){};
    CString1(const string& FileName, const CString& s): CString(FileName, s) {};
    CString1(const CString& s): CString(s){};
    virtual ~CString1();

    const CString1 operator +(const CString &s);
    using CString::operator =;
   // void out();
    int output() override final;
};
#endif


