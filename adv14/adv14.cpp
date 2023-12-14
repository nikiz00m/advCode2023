#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
vector<string> ver(vector<string> s) {
    vector<string> ss;
    for (int i=0;i<s[0].length();i++) {
        string s1="";
        for(int j=0;j<s.size();j++) {
            s1=s1+s[s.size()-1-j][i];
        }
        ss.push_back(s1);
    }
    return ss;
}   
int countAns(vector<string> s) {
    int size= s.size();
    int ans=0;
    for (int i=0;i<s[0].size(); i++){
        int lastSolid=-1, curAmount=0; 
        for(int j=0; j<size;j++){
            if (s[j][i]=='O') {
                ans+=size-j;
            }
        }
    }
    return ans;
} 
vector<string> tilt(vector<string> s) {
    vector<string> copp=s;
    int size= s.size();
    
    for (int i=0;i<s[0].size(); i++){
        int lastSolid=-1, curAmount=0; 
        for(int j=0; j<size;j++){
            if (copp[j][i]=='O') {
                copp[j][i]='.';
                copp[lastSolid+1+curAmount][i]='O';
                curAmount++;
            } else {
                if (copp[j][i]=='#') {
                    curAmount=0;
                    lastSolid=j;
                }
            }
        }
    }
    return copp;
}
vector<string> cycle(vector<string> s) {
    vector<string> copp=s;
    copp=tilt(copp);
    copp=tilt(ver(copp));
    copp=tilt(ver(copp));
    copp=tilt(ver(copp));
    copp=ver(copp);
    return copp;
}
string trn(vector<string> s) {
    string ss="";
    for (int i=0;i<s.size();i++) {
        ss=ss+s[i];
    }
    return ss;
}
vector<string> dtrn(string s) {
    vector<string> ss;
    string sc=s;
    int size=sqrt(s.length());
    for(int i =0;i<size;i++){
        ss.push_back(sc.substr(0,size));
        sc.erase(0,size);
    }
    return ss;
}
pair<int,int> findCycle(vector<string> m) {
    int p1=0,p2=0;

    while(true) {
        if (p1>=m.size() || p2>=m.size()) {
            return make_pair(-1,-1);
            break;
        }
        p1++;
        p2+=2;
        if(m[p1]==m[p2]) {
            break;
        }
    }
    
    return make_pair(p1,p2-p1);
}
int main()
{
    ifstream file;
    ofstream file1;
    file.open("input.txt");
    file1.open("output.txt");
    vector<string> pict1;
    while (file) {
        
        string s;
        getline(file, s);
        if (s!="" && s!="\n") {
            pict1.push_back(s);
        }
    }
    int lastans=countAns(pict1);
    vector<string> cycle1;
    pair<int,int> p;
    for(int i=0;i<1000000000;i++) {
        pict1=cycle(pict1);
        cycle1.push_back(trn(pict1));
        /*for(int j=0;j<pict1.size();j++) {
            for(int jj=0;jj<pict1[0].length();jj++) {
                file1<<pict1[j][jj];
            }
            file1<<"\n";
        }*/
        //file1<<countAns(pict1)<<"\n";
        p=findCycle(cycle1);
        if (p.first!=-1) {
            break;
        }
        
    }
    //cout<<p.first<<" "<<p.second<<" "<<p.first+((1000000000-p.first)%p.second)<<"\n";
    file1<<countAns(dtrn(cycle1[p.first-1+((1000000000-p.first)%p.second)]));
}
