#include <bits/stdc++.h>

using namespace std;
int producedOne[300]={ },total[300]={ },change[300]={ };
int findAns(string s, string s1){
    int ans=1;
    while (s!=""){
        if (s[0]==' '){
            s.erase(0,1);
        } else {
            string s2=s.substr(0,s.find(' '));
            //cout<<s1.find(s2)<<" "<<s1<<" "<<s2<<"\n";
            if (s1.find(' '+s2+' ')>=0 && s1.find(' '+s2+' ')<=s1.length()) {
                ans*=2;
            }
            s.erase(0,s.find(' ')+1);
        }
    }
    if (ans==1)
        return 0;
    else
    return (ans/2);
}
int findAns1(string s, string s1){
    int ans=0;
    while (s!=""){
        if (s[0]==' '){
            s.erase(0,1);
        } else {
            string s2=s.substr(0,s.find(' '));
            //cout<<s1.find(s2)<<" "<<s1<<" "<<s2<<"\n";
            if (s1.find(' '+s2+' ')>=0 && s1.find(' '+s2+' ')<=s1.length()) {
                ans++;
            }
            s.erase(0,s.find(' ')+1);
        }
    }
    return (ans);
}
int main()
{
    int sum=0;
    ifstream file;
    file.open("input.txt");
    int ind=1;
    int curAmount=0,curChange=0;
    for (int i=1;i<=216;i++) {
        total[i]=1;
    }
    while (file){
        string s;
        if(file){
            getline(file,s);
        }
        if (s=="") break;
        int cl=0;
        cl=s.find(':');
        s.erase(0,cl+1);
        string s1=s.substr(0,s.find('|'));
        s.erase(0,s.find('|')+1);
        //int ans=findAns(s1,s+' ');
        int ans1=findAns1(s1,s+' ');
        //cout<<ans1<<" ";
        producedOne[ind]=ans1;
        curChange+=change[ind];
        total[ind]+=curAmount+curChange;
        //cout<<total[ind]<<" ";
        if(producedOne[ind]!=0){
        change[ind+producedOne[ind]+1]-=total[ind];

        curAmount+=total[ind];
        }

        //cout<<curAmount<<"\n";
        sum+=total[ind];
        ind++;
        //sum+=ans;
    }
    //cout<<"---------\n";
    cout<<sum;
    return 0;
}
