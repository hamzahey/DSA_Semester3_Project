#include <iostream>
#include <string>
#include <fstream>
#include<bits/stdc++.h>
#include "stat.h"
#include "hash.h"
using namespace std;
void readFile(string file,int mode,int format,int option);
AVLNode<node> *a=NULL;  
AVLNode<bowling> *al=NULL;
HashTable1<node> hashBat(550);
HashTable1<bowling> hashBowling(550);
    //This is main menu function that displays all possible options for user 
void MainMenu(){
    int mode=0;
    int format=0;
    string file;
    cout<<"welcome to cricket analyst"<<endl;
    // ask for mode selection
    while ((mode<=0 && mode!=3 && mode<=2))
    {
    cout<<"what are you interested in?"<<endl;
    cout<<"press 1 for bowling"<<endl;
    cout<<"press 2 for batting"<<endl;
    cout<<"press 3 to exit"<<endl;
    cin>>mode;
    if (mode!=1 && mode!=2 && mode!=3)
    cout<<"select valid options from 1 or 2"<<endl;
    }
    // exit
    if (mode==3)
            return;
    // batting mode
    else if(mode==2)
    {
        cout<<"which format you are interested in"<<endl<<"1.ODI 2.T20 3.Test"<<endl;
        cin>>format;
        // format selection
        if (format==1)
        file="ODI data.csv";
        else if(format==2)
        file="t20.csv";
        else if(format==3)
        file="test.csv";
        else
        {
            cout<<"invalid selecttion"<<endl;
            MainMenu();
        }
        // search option
        cout<<"What do you desire?"<<endl;
        int option;
        string playername;
        string secondnamewithcountry;
        string name;
        string passer;
        cout<<"1.Search Player by Name and Country"<<endl;
        cout<<"2.Search Players by No of Matches"<<endl;
        cout<<"3.Search Players by No of Innings"<<endl;
        cout<<"4.Search Players by No of centuries"<<endl;
        cout<<"5.Search Players by No of fifties"<<endl;
        cout<<"6.Search Players by No of ducks"<<endl;
        if(format!=3)
        cout<<"7.Search Players by Strike rate above some value"<<endl;
        cout<<"8.Search Players by Average above some particular"<<endl;
        cout<<"9.Search players by highest score"<<endl;
        cin>>option;
        readFile(file,mode,format,option);
        if(option==1){
            cout<<"enter first name of player";
            cin>>playername;
            cout<<"second name with country as name(country)";
            cin>>secondnamewithcountry;
            if(secondnamewithcountry[0]!='(')
            playername=playername+" "+secondnamewithcountry;
            else
            playername=playername+secondnamewithcountry;
            statOfABatsman(a,playername,format);
        }
        else if(option==2){
            int matches;
            cout<<"enter no of matches";
            cin>>matches;
            hashBat.searchByQuantity(matches);
        }
        else if(option==3){
            int innings;
            cout<<"enter no of innings";
            cin>>innings;
            hashBat.searchByQuantity(innings);
        }
        else if(option==4){
            int centuries;
            cout<<"enter no of centuries";
            cin>>centuries;
            hashBat.searchByQuantity(centuries);
        }
        else if(option==5){
            int fifties;
            cout<<"enter no of fifties";
            cin>>fifties;
            hashBat.searchByQuantity(fifties);
        }
        else if(option==6){
            int ducks;
            cout<<"enter no of ducks";
            cin>>ducks;
            hashBat.searchByQuantity(ducks);
        }
        else if(option==7 && format!=3){
            int strikerate;
            cout<<"enter minnimum strike rate";
            cin>>strikerate;
            hashBat.searchByQuantity(strikerate);
        }
        else if(option==8){
            int average;
            cout<<"enter minnimum average";
            cin>>average;
            hashBat.searchByQuantity(average);
        }
        else if(option==9){
            int highestscore;
            cout<<"enter minnimum highest score";
            cin>>highestscore;
            hashBat.searchByQuantity(highestscore);
        }
        else{
            cout<<"invalid selection";
            MainMenu();
        }
    }
    // bowling mode
    else if(mode==1)
    {   
        // format selection
        cout<<"which format you are interested in"<<endl<<"1.ODI 2.T20"<<endl;
        cin>>format;
        if (format==1)
        file="Bowling_ODI.csv";
        else if(format==2)
        file="Bowling_t20.csv";
        else
        {
            cout<<"invalid selecttion"<<endl;
            MainMenu();
        }
        // search option
        cout<<"What do you desire?"<<endl;
        cout<<"1.Search Player by Name and Country"<<endl;
        cout<<"2.Search Players by No of Matches"<<endl;
        cout<<"3.Search Players by No of Innings"<<endl;
        cout<<"4.Search Players by No of Wickets"<<endl;
        cout<<"5.Search Players by No of four wicket hauls"<<endl;
        cout<<"6.Search Players by No of five wicket hauls"<<endl;
        cout<<"7.Search Players by bowling average below particular"<<endl;
        cout<<"8.Search Players by bowling strike rate bewlow particular"<<endl;
        cout<<"9.Search Players by bowling economy bewlow particular"<<endl;
        int option;
        string playername;
        string secondnamewithcountry;
        string name;
        string passer;
        cin>>option;
        readFile(file,mode,format,option);
        if(option==1){
            cout<<"enter first name of player";
            cin>>playername;
            cout<<"second name with country as naem(country)";
            cin>>secondnamewithcountry;
            if(secondnamewithcountry[0]!='(')
            playername=playername+" "+secondnamewithcountry;
            else
            playername=playername+secondnamewithcountry;
            statOfABowler(al,playername,format);
        }
        else if(option==2){
            int matches;
            cout<<"enter no of matches";
            cin>>matches;
            hashBowling.searchByQuantity(matches);
        }
        else if(option==3){
            int innings;
            cout<<"enter no of innings";
            cin>>innings;
            hashBowling.searchByQuantity(innings);
        }
        else if(option==4){
            int wickets;
            cout<<"enter no of wickets";
            cin>>wickets;
            hashBowling.searchByQuantity(wickets);
        }
        else if(option==5){
            int fourwkts;
            cout<<"enter no of four wickets";
            cin>>fourwkts;
            hashBowling.searchByQuantity(fourwkts);
        }
        else if(option==6){
            int fivewkts;
            cout<<"enter no of fiveWkts";
            cin>>fivewkts;
            hashBowling.searchByQuantity(fivewkts);
        }
        else if(option==7){
            int average;
            cout<<"enter maximum average";
            cin>>average;
            hashBowling.searchByQuantitymax(average);
        }
        else if(option==8){
            int strikerate;
            cout<<"enter maximum strikerate";
            cin>>strikerate;
            hashBowling.searchByQuantitymax(strikerate);
        }
        else if(option==9){
            int economy;
            cout<<"enter maximum economy";
            cin>>economy;
            hashBowling.searchByQuantitymax(economy);
        
        }
        else{
            cout<<"invalid selection";
            MainMenu();
        }
    }
    else
    MainMenu();
    // ask wheteher user wants to go on with program or exit
    int carryOn;
    cout<<"Do you want to carry on with stats?if yes enter 1 but if no enter any number"<<endl;
    cin>>carryOn;
    if(carryOn==1)
    MainMenu();
    else
    return;
}
    // read file accordingly
    void readFile(string file,int mode,int format,int option){
        node *n;
        bowling *bowl;
        string ex;
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
        string fourWkts;
        string fiveWkts;
        string Balls;
        string Overs;
        string Mdns;
        string Wkts;
        string Econ;
            int count=0;
            int i=2;
    ifstream File(file);
    // reading file for batting
    if (mode==2)
    {
            if(File.is_open()){
                while(!File.eof()){
                    if (count==0)
                    {
                        string temp;
                        getline(File,temp);
                        count=1;
                    }
                    else
                    {
                        getline(File,sr,',');
                        getline(File,Player,',');
                        getline(File,country,',');
                        getline(File,Span,',');
                        getline(File,Mat,',');
                        getline(File,Inns,',');
                        getline(File,NO,',');
                        getline(File,Runs,',');
                        getline(File,HS,',');
                        getline(File,Ave,',');
                        if(format==1 ||format==2){
                        getline(File,BF,',');
                        getline(File,SR,',');
                        }
                        getline(File,centuries,',');
                        getline(File,fifties,',');
                        getline(File,ducks,',');
                        if (format==2){                        
                        getline(File,fours,',');
                        getline(File,sixes,',');
                        }
                        getline(File,ex,'\n');
                        // storing data for odi
                        if (format==1)
                        n=new node(sr,Player,country,Span,Mat,Inns,NO,Runs,HS,Ave,BF,SR,centuries,fifties,ducks);
                        // storing data for test
                        else if(format==3)
                        n=new node(sr,Player,country,Span,Mat,Inns,NO,Runs,HS,Ave,centuries,fifties,ducks);
                        // storing data for t20
                        else if(format==2)
                        n=new node(sr,Player,country,Span,Mat,Inns,NO,Runs,HS,Ave,BF,SR,centuries,fifties,ducks,fours,sixes);
                        // insert into avl tree  by using player and country name as sorting base
                        if(option==1)
                        a=insert(a,*n,n->complete);
                        // insert into hashtable according to num of matches
                        else if(option==2)
                        hashBat.insert(*n,stoi(n->Mat));
                        // insert into hashtable according to num of innings
                        else if(option==3)
                        hashBat.insert(*n,stoi(n->Inns));
                        // insert into hashtable according to num of centuries
                        else if(option==4)
                        hashBat.insert(*n,stoi(n->centuries));
                        // insert into hashtable according to num of fifties
                        else if(option==5)
                        hashBat.insert(*n,stoi(n->fifties));
                        // insert into hashtable according to num of ducks
                        else if(option==6)
                        hashBat.insert(*n,stoi(n->ducks));
                        // insert into hashtable according to strikerate
                        else if(option==7 && format!=3)
                        hashBat.insert(*n,stoi(n->SR));
                        // insert into hashtable according to average
                        else if(option==8)
                        hashBat.insert(*n,stoi(n->Ave));
                        // insert into hashtable according to highest score
                        else if(option==9)
                        hashBat.insert(*n,stoi(n->HS));
                        // cout<<i++<<endl;
                    }
                }  
            }
            else
            {
                cout<<"Error";
            }
    }
    // read file for bowling
    else{
        if(File.is_open()){
                while(!File.eof()){
                    if (count==0)
                    {
                        string temp;
                        getline(File,temp);
                        count=1;
                    }
                    else
                    {
                        getline(File,sr,',');
                        getline(File,Player,',');
                        getline(File,country,',');
                        getline(File,Span,',');
                        getline(File,Mat,',');
                        getline(File,Inns,',');
                        if(format==1)
                        getline(File,Balls,',');
                        if(format==2){
                        getline(File,Overs,',');
                        getline(File,Mdns,',');
                        }
                        getline(File,Runs,',');
                        getline(File,Wkts,',');
                        getline(File,Ave,',');
                        getline(File,Econ,',');
                        getline(File,SR,',');
                        getline(File,fourWkts,',');
                        getline(File,fiveWkts,',');
                        getline(File,ex,'\n');
                        // this is for odi bowling
                        if (format==1)
                        bowl=new bowling(sr,Player,country,Span,Mat,Inns,Balls,Runs,Wkts,Ave,Econ,SR,fourWkts,fiveWkts);
                        // this is for t20 bowling
                        else if(format==2)
                        bowl=new bowling(sr,Player,country,Span,Mat,Inns,Balls,Runs,Wkts,Ave,Econ,SR,fourWkts,fiveWkts);
                        // insert into avl tree  by using player and country name as sorting base
                        if(option==1)
                         al=insert(al,*bowl,bowl->complete);
                        // insert into hashtable according to num of matches
                        else if(option==2)
                        hashBowling.insert(*bowl,stoi(bowl->Mat));
                        // insert into hashtable according to num of innings
                        else if(option==3)
                        hashBowling.insert(*bowl,stoi(bowl->Inns));
                        // insert into hashtable according to num of wickets
                        else if(option==4)
                        hashBowling.insert(*bowl,stoi(bowl->Wkts));
                        // insert into hashtable according to num of four wckt hauls
                        else if(option==5)
                        hashBowling.insert(*bowl,stoi(bowl->fourWkts));
                        // insert into hashtable according to num of five wckt hauls
                        else if(option==6)
                        hashBowling.insert(*bowl,stoi(bowl->fiveWkts));
                        // insert into hashtable according to average
                        else if(option==7)
                        hashBowling.insert(*bowl,stoi(bowl->Ave));
                        // insert into hashtable according to strikerate
                        else if(option==8)
                        hashBowling.insert(*bowl,stoi(bowl->SR));
                        // insert into hashtable according to economy
                        else if(option==9)
                        hashBowling.insert(*bowl,stoi(bowl->Econ));
                    }
                }  
            }
            else
            {
                cout<<"Error";
            }
    }
    }
   