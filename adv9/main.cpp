#include <bits/stdc++.h>
using namespace std;

int findNext(vector<int> mass) {
    vector<int> nextt;
    int endd=0;
    for (int i=1;i<mass.size();i++) {
        nextt.push_back(mass[i]-mass[i-1]);
        if ((mass[i]-mass[i-1]) != 0){
            endd=1;
        }
    }
    if (endd==0)
    {
        return mass[mass.size()-1];
    } else {
        return mass[mass.size()-1]+findNext(nextt);
    }
}
int findprev(vector<int> mass) {
    vector<int> nextt;
    int endd=0;
    for (int i=1;i<mass.size();i++) {
        nextt.push_back(mass[i]-mass[i-1]);
        if ((mass[i]-mass[i-1]) != 0){
            endd=1;
        }
    }
    if (endd==0)
    {
        return mass[0];
    } else {
        return mass[0]-findprev(nextt);
    }
}
int convert(string s) {
    long long ans=0;
    if (s=="")
        return -1;
    int minn=1;
    if (s[0]=='-'){
        minn=-1;
        s.erase(0,1);
    }
    while(s!=""){
        if (isdigit(s[0])) {
            ans=ans*10+(s[0]-'0');
        }
        s.erase(0,1);
    }

    return ans*minn;
}
int main()
{
    ifstream file;
    file.open("input.txt");
    int ans=0;
    while(file)
    {
        string s;
        getline(file,s);

        s=s+' ';
        vector<int> linne;
        if (s!=" " && s!=""){
          while (s!="" && s!=" "){
            string num=s.substr(0,s.find(' '));
            s.erase(0,s.find(' ')+1);
            linne.push_back(convert(num));
          }
          //ans+=findNext(linne);
          ans+=findprev(linne);
        }

    }
    cout<<ans;
}
