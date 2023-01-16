// this header file is for storing data of each bowling node
#pragma once
#include <iostream>
#include <string>
using namespace std;
class bowling
{
public:
  string complete;
  string sr;
  string Player;
  string country;
  string Span;
  string Mat;
  string Inns;
  string Balls;
  string Overs;
  string Mdns;
  string Runs;
  string Wkts;
  string Ave;
  string Econ;
  string SR;
  string fourWkts;
  string fiveWkts;
  bowling()
  {
  }
  // constructor for odi bowling
  bowling(string sr, string Player, string country, string Span, string Mat, string Inns, string Balls, string Runs, string Wkts, string Ave, string Econ, string SR, string fourWkts, string fiveWkts)
  {
    this->complete = Player + country;
    this->sr = sr;
    this->Player = Player;
    this->country = country;
    this->Span = Span;
    this->Mat = Mat;
    this->Inns = Inns;
    this->Balls = Balls;
    this->Overs = "not available";
    this->Mdns = "not available";
    this->Runs = Runs;
    this->Wkts = Wkts;
    this->Ave = Ave;
    this->Econ = Econ;
    this->SR = SR;
    this->fourWkts = fourWkts;
    this->fiveWkts = fiveWkts;
  }
  // constructor for t20 bowling
  bowling(string sr, string Player, string country, string Span, string Mat, string Inns, string Overs, string Mdns, string Runs, string Wkts, string Ave, string Econ, string SR, string fourWkts, string fiveWkts)
  {
    this->complete = Player + country;
    this->sr = sr;
    this->Player = Player;
    this->country = country;
    this->Span = Span;
    this->Mat = Mat;
    this->Inns = Inns;
    this->Overs = Overs;
    this->Balls = "not available";
    this->Mdns = Mdns;
    this->Runs = Runs;
    this->Wkts = Wkts;
    this->Ave = Ave;
    this->Econ = Econ;
    this->SR = SR;
    this->fourWkts = fourWkts;
    this->fiveWkts = fiveWkts;
  }
  // overloading of boolean comparison operators for sotring data in list
  bool operator==(bowling bowlingEntry)
  {
    return complete == bowlingEntry.complete;
  }

  bool operator!=(bowling bowlingEntry)
  {
    return complete != bowlingEntry.complete;
  }

  bool operator>(bowling bowlingEntry)
  {
    return complete > bowlingEntry.complete;
  }

  bool operator<(bowling bowlingEntry)
  {
    return complete < bowlingEntry.complete;
  }

  // << was overloaded for printing and file writing purposes
  friend ostream &operator<<(ostream &output, const bowling &bowl)
  {
    output << bowl.sr << " :: " << bowl.Player << " :: " << bowl.country << " :: " << bowl.Span << " :: " << bowl.Mat << " :: " << bowl.Inns << " :: " << bowl.Balls << " :: " << bowl.Overs << " :: " << bowl.Runs << " :: " << bowl.Wkts << " :: " << bowl.Ave << " :: " << bowl.Econ << " :: " << bowl.SR << " :: "<< bowl.fourWkts << " :: " << bowl.fiveWkts;
    return output;
  };
};
