#ifndef FUNCTIONS
#define FUNCTIONS

#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
//#include <sstream>
//#include <memory>
#include<vector>
#include<map>
#include "CString.hpp"
#include "CString0.hpp"
#include "CString1.hpp"

#include "Factory.hpp"
#include "FactoryH.hpp"
#include "FactoryV.hpp"
using namespace std;

void scan(const char *input_file){
    string mode; int sizemass = 2; int i=0;
    char out_name[80];
    string curr;
    CString** mass = new CString* [sizemass];
    ifstream in; in.open(input_file);
    if( !in.is_open() )
        cout<<"Can't open your file "<<input_file;
    else{
        cout<<"open "<<input_file<<"\t\n";
        while(in>>mode){
            in>>out_name;
            in>>curr; //char *curr = (char*)CURR.c_str();
            if(mode=="Hori"){
                cout<<i<<" Read 0 ";
                CString* tmp = new CString0(out_name, curr);
                mass[i] = tmp;
                cout<<mass[i]->f_name<<": "<<mass[i]->str<<"\t"<<(mass[i]->str).length()<<endl; i++;
            }
            else if (mode=="Vert"){
                cout<<i<<" Read 1 ";
                CString* tmp = new CString1(out_name, curr);
                mass[i] = tmp;
                cout<<mass[i]->f_name<<": "<<mass[i]->str<<"\t"<<(mass[i]->str).length()<<endl; i++;
            }
            if(i==sizemass){
               mass=(CString**)realloc(mass, 2*i*sizeof(CString*));
               sizemass *= 2;
            }
        }
        in.close();
        cout<<"----------------------------"<<endl;
        fstream clear_file1("file1", ios::out);
        clear_file1.close();
        fstream clear_file2("file2", ios::out);
        clear_file2.close();
        for(int j=0;j<i;j++){
            cout<<"\nj: "<<j<<"\t"<<mass[j]->f_name<<" "<<(mass[j]->str).length()<<" "<<mass[j]->str<<"\t";
            //cout<<mass[j]->str<<endl;
            mass[j]->output();
            //delete mass[j];
        }
        cout<<"\n_________________________"<<endl;
        for(int j=0; j<sizemass;j++){
           // cout<<j<<" ";
            delete mass[j];
        }
        delete[] mass;
        mass=NULL;
    }
}
int fun(const char* myfileName){
  try{
    map< string, Factory* > factoryMap;
    factoryMap["Hori"] = new FactoryH;
    factoryMap["Vert"] = new FactoryV;
    //const string myfileName = "t2.txt";
    ifstream myfile(myfileName, ios_base::in);
    string MF(myfileName);

    if (!myfile.is_open()) {
        throw invalid_argument("Error! Can't open your " + MF + " file\n");
    }

    vector< CString* > vectorVector;
    string curr; string mode; string out_name;

    while (myfile>> mode) {
        myfile>>out_name;
        myfile>>curr;
        auto curFactory = factoryMap.find(mode);
        if (curFactory == factoryMap.end()) {
            throw invalid_argument("Error! Wrong type of CString in your" + MF + " file\n");
        }
        auto curVect = factoryMap[mode]->Create(curr.length(), out_name);
        (*curVect).str = curr;
        vectorVector.push_back(curVect);
    }
      
      
    // for (auto it = 0; it < factoryMap.size(); it++){
        delete factoryMap["Hori"];
    //}
        delete factoryMap["Vert"];
    //delete[] factoryMap; factoryMap = NULL; //MAP AUTOMATICALLY
      
      
    myfile.close();
    for (const auto& vect : vectorVector) {
        vect->output();
    }
    cout<<"Please, check your datafiles"<<endl;
    return 0;
  }

  catch (const exception& e) {
    cerr << e.what() << endl;
    return 1;
  }
}

#endif

