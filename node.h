// this header file is for storing data of each batting node
#pragma once
#include <iostream>
#include <string>
using namespace std;
class node{
public:
    string complete;
    string sr;
    string Player;
    string country;
    string Span;
    string Mat;
    string Inns;
    string NO;
    string Runs;
    string HS;
    string Ave;
    string BF;
    string SR;
    string centuries;
    string fifties;
    string ducks;
    string fours;
    string sixes;
    node(){

    }
    // t20 constructor for batting
    node(string sr,string Player,string country,string Span,string Mat,string Inns,string NO,string Runs,string HS,string Ave,string centuries,string fifties,string ducks){
    this->complete=Player+country;
    this->sr=sr;
    this->Player=Player;
    this->country=country;
    this->Span=Span;
    this->Mat=Mat;
    this->Inns=Inns;
    this->NO=NO;
    this->Runs=Runs;
    this->HS=HS;
    this->Ave=Ave;
    this->BF="not available";
    this->SR="not avilable";
    this->centuries=centuries;
    this->fifties=fifties;
    this->ducks=ducks;
    this->fours="not avilable";
    this->sixes="not avilable";
    }
    // odi constructor
    node(string sr,string Player,string country,string Span,string Mat,string Inns,string NO,string Runs,string HS,string Ave,string BF,string SR,string centuries,string fifties,string ducks,string fours,string sixes){
    this->complete=Player+country;
    this->sr=sr;
    this->Player=Player;
    this->country=country;
    this->Span=Span;
    this->Mat=Mat;
    this->Inns=Inns;
    this->NO=NO;
    this->Runs=Runs;
    this->HS=HS;
    this->Ave=Ave;
    this->BF=BF;
    this->SR=SR;
    this->centuries=centuries;
    this->fifties=fifties;
    this->ducks=ducks;
    this->fours=fours;
    this->sixes=sixes;
    }
    // test constructor
    node(string sr,string Player,string country,string Span,string Mat,string Inns,string NO,string Runs,string HS,string Ave,string BF,string SR,string centuries,string fifties,string ducks){
    this->complete=Player+country;
    this->sr=sr;
    this->Player=Player;
    this->country=country;
    this->Span=Span;
    this->Mat=Mat;
    this->Inns=Inns;
    this->NO=NO;
    this->Runs=Runs;
    this->HS=HS;
    this->Ave=Ave;
    this->BF=BF;
    this->SR=SR;
    this->centuries=centuries;
    this->fifties=fifties;
    this->ducks=ducks;
    this->fours="not available";
    this->sixes="not avilable";
    }
    //overloading of boolean comparison operators for sotring data in list
    bool operator==(node nodeEntry)
    {
      return complete == nodeEntry.complete;
    }

    bool operator!=(node nodeEntry)
    {
      return complete != nodeEntry.complete;
    }

    bool operator>(node nodeEntry)
    {
      return complete > nodeEntry.complete;
    }

    bool operator<(node nodeEntry)
    {
      return complete < nodeEntry.complete;
    }

    // << was overloaded for printing and file writing purposes
    friend ostream &operator<<( ostream &output, const node& bat)
    {
      output << bat.sr << " :: " << bat.Player<< " :: " << bat.country<<  " :: " << bat.Span<< " :: " << bat.Mat<< " :: " << bat.Inns<< " :: " << bat.NO<< " :: " << bat.Runs<< " :: " << bat.HS<< " :: " << bat.Ave<< " :: " << bat.BF<< " :: " << bat.SR<< " :: " << bat.centuries<< " :: " << bat.fifties<< " :: " << bat.ducks <<" :: "<< bat.fours<< " :: " << bat.sixes;
      return output;
    };
};
