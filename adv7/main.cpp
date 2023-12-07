#include <bits/stdc++.h>
#include <map>;
using namespace std;

struct game{
    string hand;
    int bid;
    int type;
};
vector<game> games;
long long countType(string s){
    map<char,int> h;
    h[s[0]]++;
    h[s[1]]++;
    h[s[2]]++;
    h[s[3]]++;
    h[s[4]]++;
    int joke=h['J'];
    h['J']=0;
    long long sum=0,maxx=max(h[s[0]],max(h[s[1]],max(h[s[2]],max(h[s[3]],h[s[4]]))));
    for(int i=0;i<=4;i++){
        if (h[s[i]]!=0){
            if (h[s[i]]==maxx)
            {h[s[i]]+=joke; joke=0;}
            sum=sum*10+h[s[i]];
            h[s[i]]=0;
        }
    }
    //cout<<sum<<"--"<<s<<"\n";
    if (sum==5 || joke==5) return 7;
    if (sum==14 || sum==41) return 6;
    if (sum==23 || sum==32) return 5;
    if (sum==113 || sum==131 || sum==311) return 4;
    if (sum==221 || sum==212 || sum== 122) return 3;
    if (sum==1112 || sum== 1121 || sum==1211 || sum==2111) return 2;
    return 1;
}
long long convert(string s) {
    long long ans=0;
    if (s=="")
        return -1;
    while(s!=""){
        if (isdigit(s[0])) {
            ans=ans*10+(s[0]-'0');
        }
        s.erase(0,1);
    }
    return ans;
}

map<char,int>cards;

bool com(game a, game b){
    if (a.type==b.type) {
        int i=0;
        while (a.hand[i]==b.hand[i]){
            i++;
        }
        return cards[a.hand[i]]<cards[b.hand[i]];
    }
    return a.type<b.type;
}
int main()
{
    cards['A']=13;
    cards['K']=12;
    cards['Q']=11;
    cards['J']=0;
    cards['T']=9;
    cards['9']=8;
    cards['8']=7;
    cards['7']=6;
    cards['6']=5;
    cards['5']=4;
    cards['4']=3;
    cards['3']=2;
    cards['2']=1;
    ifstream file;
    file.open("input.txt");
    while(file){
        string s;
        getline(file,s);
        if (s==" " || s==""){
            break;
        }
        game g;
        g.hand=s.substr(0,5);
        s.erase(0,6);
        g.bid=convert(s);
        g.type=countType(g.hand);
        games.push_back(g);
    }
    sort(games.begin(),games.end(),com);
    long long ans=0;
    for (int i=0;i<games.size();i++){
            //cout<<games[i].hand<<"-"<<games[i].bid<<"-"<<games[i].type<<"\n";
        ans+=(i+1)*games[i].bid;
    }
    cout<< ans;
}
