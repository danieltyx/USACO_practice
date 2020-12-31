#include"bits/stdc++.h"
using namespace std;
struct Card{
    string s_num;
    int num;
    char suit;
    int suit_num;
    bool operator< (const Card y) const
      {
        if(num != y.num)
        {
              return num<y.num;
        }
        return suit_num > y.suit_num;
      }
};
Card c[100];
//C>D>H>S
vector<int> vc;
string print_card_number(int x)
{
    string b = "";
    if(x>1 && x<=9) b = to_string(x);
    else if(x==10) b = "T";
    else if(x==11) b = "J";
    else if(x==12) b = "Q";
    else if(x==13) b = "K";
    else if(x==1)  b = "A";
    return b;
}
void run()
{
    string aa;
    string b[6];
    cin>>aa;
    Card a;
    if(aa[0]=='T') a.num = 10;
    else if(aa[0]=='J') a.num = 11;
    else if(aa[0]=='Q') a.num = 12;
    else if(aa[0]=='K') a.num = 13;
    else if(aa[0]=='A') a.num = 1;
    else a.num = aa[0]-'0';
    a.suit = aa[1];
    for(int i=0;i<=4;i++)
    {
        string temp;
        cin>>temp;
        c[i].s_num = temp[0];
        c[i].suit = temp[1];
        if(c[i].suit == 'C') c[i].suit_num = 4;
        else if(c[i].suit == 'D') c[i].suit_num = 3;
        else if(c[i].suit == 'H') c[i].suit_num = 2;
        else if(c[i].suit == 'S') c[i].suit_num = 1;
    }
    for(int i=0;i<=4;i++)
    {
        if(c[i].s_num == "T") c[i].num = 10;
        else if(c[i].s_num == "J") c[i].num = 11;
        else if(c[i].s_num == "Q") c[i].num = 12;
        else if(c[i].s_num == "K") c[i].num = 13;
        else if(c[i].s_num == "A") c[i].num = 1;
        else c[i].num = stoi(c[i].s_num);
    }
    for(int i=0;i<=4;i++)
    {
       if(c[i].suit == a.suit)
       {
           if(c[i].num > a.num)vc.push_back(i);
       }
    }
    if(!vc.empty())
    {
        int minn = 99;
        int mini;
        int l = (int)vc.size();
        for(int i=0; i<l; i++)
        {
            if(c[vc[i]].num < minn)
            {
                minn = c[vc[i]].num;
                mini = vc[i];
            }
        }
        string final_num = print_card_number(c[mini].num);
        cout<<final_num<<c[mini].suit<<endl;
        return;
    }
    for(int i=0;i<=4;i++)
    {
       if(c[i].suit == a.suit)
       {
           vc.push_back(i);
       }
    }
    if(!vc.empty())
    {
        int minn = 99;
        int mini;
        int l = (int)vc.size();
        for(int i=0; i<l; i++)
        {
            if(c[vc[i]].num < minn)
            {
                minn = c[vc[i]].num;
                mini = vc[i];
            }
        }
        string final_num =  print_card_number(c[mini].num);
        cout<<final_num<<c[mini].suit<<endl;
        return;
    }
    sort(c,c+4);
    cout<<c[0].s_num<<c[0].suit<<endl;
    return;
}

void cleanit()
{
    vc.clear();
}
int main()
{
    run();
    cleanit();
    run();
    cleanit();
    run();
    cleanit();
    run();
    cleanit();
    run();
}


/*
2H 3S 4D AH 9H AC
7D 3D 8H 5S KC AD
TS AH AC AD JC QH
8C 3D 4H 9S TD QS
AS KD TC 5H 5D 6C

 */
/*
1.  9H
2.  AD
3.  AC
4.  3D
 5. 5D
*/
