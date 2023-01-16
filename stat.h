    
// This file conatins some stats functions for getting stats through player name and country
#include <iostream>
#include "avl.h"
#include "node.h"
#include "bowling.h"
using namespace std;
int statSelectorBatting();
int statSelectorBowling();
    template<typename o>
    // to search by player and country
AVLNode<o>* searchPlayerByNameAndCountry(AVLNode<o> *a,string complete){
    AVLNode<o> *loc=a;
    AVLNode<o> *ploc=NULL;
    int count=0;
    while (loc!=NULL && count<15 )
    {  count++;
    cout<<count;
        if(loc->key.complete==complete)
        break;
        ploc=loc;
        if(complete >loc->key.complete ){
            loc=loc->right;
        }
        else if(complete <loc->key.complete){
            loc=loc->left;
        }  
    }
    if(loc->key.complete==complete){
        return loc;
    }
    else{
        return NULL;
    }
}
// to get batting stats of a particular batsman
void statOfABatsman(AVLNode<node> *root,string complete,int format){
    AVLNode<node> *node= searchPlayerByNameAndCountry(root,complete);
    if(node==NULL){
        cout<< "This Players Data is not Available"<<endl;
    }
    else{
    int stat=statSelectorBatting();
        if(stat==1)
            cout<<complete<<" has played during "<<node->key.Span<<endl;
        else if (stat==2)
            cout<<complete<<" has played "<<node->key.Mat<<" Matches"<<endl;
        else if (stat==3)
            cout<<complete<<" has batted in "<<node->key.Inns<<" Innings"<<endl;
        else if (stat==4)
            cout<<complete<<" remained in "<<node->key.NO<<" Innings"<<endl;
        else if (stat==5)
            cout<<complete<<" has scored "<<node->key.Runs<<" Runs"<<endl;
        else if (stat==6)
            cout<<complete<<" has highest score of "<<node->key.Runs<<" Runs"<<endl;
        else if (stat==7)
            cout<<complete<<" has batting average of "<<node->key.Ave<<endl;
        else if (stat==8)
            cout<<complete<<" has faced "<<node->key.BF<<" Balls"<<endl;
        else if (stat==9 && format!=3)
            cout<<complete<<" has Strike Rate of "<<node->key.SR<<endl;
        else if (stat==10 && format!=3)
            cout<<complete<<" has "<<node->key.centuries<<" centuries"<<endl;
        else if (stat==11)
            cout<<complete<<" has "<<node->key.fifties<<" fifities"<<endl;
        else if (stat==12)
            cout<<complete<<" has "<<node->key.ducks<<" ducks"<<endl;
        else if (stat==13 && format==2)
            cout<<complete<<" has hit "<<node->key.fours<<" fours "<<endl;
        else if (stat==14 && format==2)
            cout<<complete<<" has hit "<<node->key.sixes<<"sixes"<<endl;
        else
            cout<<"Data not Available for this stat"<<endl;   
    }


}
// to get batting stats of a particular batsman
void statOfABowler(AVLNode<bowling> *root,string complete,int format){
    AVLNode<bowling> *bowling= searchPlayerByNameAndCountry(root,complete);
    if(bowling==NULL){
        cout<< "This Players Data is not Available"<<endl;
    }
    else{
    int stat=statSelectorBowling();
        if(stat==1)
            cout<<complete<<" has played during "<<bowling->key.Span<<endl;
        else if (stat==2)
            cout<<complete<<" has played "<<bowling->key.Mat<<" Matches"<<endl;
        else if (stat==3)
            cout<<complete<<" has bowled in "<<bowling->key.Inns<<" Innings"<<endl;
        else if (stat==4 && format==2)
            cout<<complete<<" has bowled "<<bowling->key.Overs<<" Overs"<<endl;
        else if (stat==5 && format==2)
            cout<<complete<<" has bowled "<<bowling->key.Mdns<<" Maidens"<<endl;
        else if (stat==6 && format==1)
            cout<<complete<<" has bowled  "<<bowling->key.Balls<<" Balls"<<endl;
        else if (stat==7)
            cout<<complete<<" has conceded "<<bowling->key.Runs<<" Runs"<<endl;
        else if (stat==8)
            cout<<complete<<" has taken "<<bowling->key.Wkts<<" wickets"<<endl;
        else if (stat==9)
            cout<<complete<<" has bowling average of of "<<bowling->key.Ave<<endl;
        else if (stat==10)
            cout<<complete<<" has bowling economy of "<<bowling->key.Econ<<endl;
        else if (stat==11)
            cout<<complete<<" has bowling strike rate of "<<bowling->key.SR<<endl;
        else if (stat==12)
            cout<<complete<<" has "<<bowling->key.fourWkts<<" four wicket hauls"<<endl;
        else if (stat==13)
            cout<<complete<<" has "<<bowling->key.fiveWkts<<" five wicket hauls "<<endl;
        else
            cout<<"Data not Available for this stat"<<endl;   
    }
}
// stat selector for batsman
int statSelectorBatting(){
    int stat=0;
    cout<<"which of the following stat are you interested in?";
    cout<<"1.Span 2.Mat 3.Inns 4.NotOuts 5.Runs 6.HS 7.Ave "<<endl<<"8.BallsFaced 9.SR 10.100s 11.50s 12.ducks 13.4s 14.6s"<<endl;
    cin>>stat;
    if (stat<=0 || stat>14){
        cout<<"invalid selection"<<endl;
        stat=statSelectorBatting();
    }
    return stat;
}
// stat selector for bowler
int statSelectorBowling(){
    int stat;
    cout<<"which of the following stat are you interested in?";
    cout<<"1.Span 2.Mat 3.Inns 4.Overs 5.Mdns 6.Balls"<<endl<<" 7.Runs 8.Wkts 9.Ave 10.Economy 11.SR 12.4 wkts 13.5 wckts"<<endl;
    cin>>stat;
    if (stat<=0 || stat>13){
        cout<<"invalid selection"<<endl;
        stat=statSelectorBowling();
    }
    return stat;
}
  