#ifndef CSTRING_H
#define CSTRING_H
#include<string>
using namespace std;

class CString
{
public:
    string str;
    int len;
    string f_name;

    CString();
    CString(const int dlina, const string& FileName);
    CString (const string& pstr);
    CString(const string& FileName, const string& new_str);
    CString(const CString& s);
    CString(const string& FileName, const CString& s);
    virtual ~CString();

    void SetZero();
    //void out();
    CString&  operator = (const CString& s);
    virtual int output() = 0;
};
#endif



