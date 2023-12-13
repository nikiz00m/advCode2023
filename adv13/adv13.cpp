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
map<int,int> refmap(vector<string> s){
    map<int,int> ans;
    map<string, vector<int> > incl;
    /*for(int i =0;i<s.size();i++){
        cout<<s[i]<<"!\n";
    }*/
    for (int i=0;i<s.size();i++) {
        string s1=s[i];
        if (incl.find(s1) == incl.end())
            {
                vector<int> emp;
                emp.push_back(i);
                incl.insert({s1,emp});
            }
            else
            {   
                vector<int> nempt=incl[s1];
                for(int j=0;j<nempt.size();j++) {
                    int reff = i+nempt[j];
                    if (reff % 2 == 1) {
                        reff--;
                        reff/=2;
                        //cout<<nempt[j]<<" "<<i<<" "<<s[nempt[j]]<<" sho  "<<s[i]<<"\n";
                        if (ans.find(reff)==ans.end())
                        ans.insert({reff,0});
                        ans[reff]++;
                    }
                }
                nempt.push_back(i);
                incl.erase(s1);
                incl.insert({s1,nempt});
                
            }
    }
    return ans;
}
pair<int,int> isSmudge(vector<string> s, int line) {
    int i=0;
    int isit=0;
    int smline=-1,smpos=-1;
    int check1=0;
    while (line-i>=0 && line+i+1<s.size() && check1<=1) {
        if (s[line-i]!=s[line+i+1]) {
            for(int j=0;j<s[0].length();j++) {
                if (s[line-i][j]!=s[line+i+1][j]) {
                    smline=line-i;
                    smpos=j;
                    check1++;
                }
                if (check1>=2) {
                    break;
                }
            }
        }
        
        i++;
    }
    if (check1==1) {
            isit=1;
    }
    if (isit) return make_pair(smline,smpos);
    else
    return {-1,-1};
}
int main()
{
    ifstream file;
    ofstream file1;
    file.open("input.txt");
    file1.open("output.txt");
    long long ans=0;
    int i=0;
    vector<string> pict1;
    while (file) {
        
        string s;
        getline(file, s);
        if (s!="" && s!="\n") {
            pict1.push_back(s);
        } else {
            int isFound=0; 
            vector<string> pict2= ver(pict1);
            map<int,int> ref = refmap(pict1);
            map<int,int> ref1 = refmap(pict2);
            int smline1,smline2;

            for(auto& ii:ref) {
                int line=ii.first, amount=ii.second;
                int size1=pict1.size();
                int minn=min(line+1, (size1-line-1));
                if (minn-1 == amount) {
                    pair<int,int> smudge = isSmudge(pict1,line);
                    if (smudge.first!= -1 ) {
                        smline1=smudge.first;
                        smline2=smudge.second;
                        pict1[smudge.first][smudge.second]= pict1[line*2+1-smudge.first][smudge.second];
                        pict2[smudge.second][pict1.size()-smudge.first-1] = pict1[line*2+1-smudge.first][smudge.second];
                        isFound=1;
                        break;
                    }
                }
            }
            if (!isFound) {
                for(auto& ii:ref1) {
                    int line=ii.first, amount=ii.second;
                    int size2=pict2.size();
                    int minn=min(line+1, (size2-line-1));
                    if (minn-1 == amount) {
                        pair<int,int> smudge = isSmudge(pict2,line);
                        if (smudge.first!= -1 ) {
                            smline1=pict1.size()-1-smudge.second;
                            smline2=smudge.first;
                            pict2[smudge.first][smudge.second]= pict2[line*2+1-smudge.first][smudge.second];
                            pict1[pict1.size()-1-smudge.second][smudge.first] = pict2[line*2+1-smudge.first][smudge.second];
                            isFound=1;
                            break;
                        }
                    }
                }    
            }

            if (!isFound) {
                pair<int,int> smudge = isSmudge(pict1,0);
                if (smudge.first!=-1) {
                    smline1=0;
                    smline2=smudge.second;
                    pict1[0][smudge.second]= pict1[1][smudge.second];
                    pict2[smudge.second][pict1.size()-1] = pict1[1][smudge.second];
                    isFound=1;
                } else {
                    smudge = isSmudge(pict1,pict1.size()-2);
                    if (smudge.first!=-1) {
                        smline1=pict1.size()-2;
                        smline2=smudge.second;
                        pict1[pict1.size()-2][smudge.second]= pict1[pict1.size()-1][smudge.second];
                        pict2[smudge.second][1] = pict1[pict1.size()-1][smudge.second];
                        isFound=1;
                    }
                }
            }
            if (!isFound) {
                pair<int,int> smudge = isSmudge(pict2,0);
                if (smudge.first!=-1) {
                    smline1=pict1.size()-1-smudge.second;
                    smline2=smudge.first;
                    pict2[0][smudge.second]= pict2[1][smudge.second];
                    pict1[pict1.size()-1-smudge.second][0] = pict2[1][smudge.second];
                    isFound=1;
                } else {
                    smudge = isSmudge(pict2,pict2.size()-2);
                    if (smudge.first!=-1) {
                        smline1=pict1.size()-1-smudge.second;
                        smline2=pict2.size()-2;
                        pict2[pict2.size()-2][smudge.second]= pict2[pict2.size()-1][smudge.second];
                        pict1[pict1.size()-1-smudge.second][pict2.size()-2] = pict2[pict2.size()-1][smudge.second];
                        isFound=1;
                    }
                }
            }
            /*for(int ii=0;ii<pict1.size();ii++) file1<<pict1[ii]<<"\n";
            file1<<"----\n";
            for(int ii=0;ii<pict2.size();ii++) file1<<pict2[ii]<<"\n";
            file1<<"\n";*/
            ref.clear();
            ref1.clear();
            ref = refmap(pict1);
            ref1 = refmap(pict2);

            for (auto& ii : ref) {
                    int line = ii.first, amount=ii.second;
                    int size1 = pict1.size();
                    int minn=min(line+1, (size1-line-1));
                    if (minn == amount) {
                        if (smline1<=minn+line && smline1>=line-minn+1){
                           ans+=100*(line+1);
                        }
                    }
            }
            for (auto& ii : ref1) {
                    int line = ii.first, amount=ii.second;
                    int size1 = pict2.size();
                    int minn=min(line+1, (size1-line-1));
                    if (minn == amount) {
                        if (smline2<=minn+line && smline2>=line-minn+1) {
                            ans+=1*(line+1);
                        }
                    }
                }
            pict1.clear();
        }
    }
    file1<<ans;
}
