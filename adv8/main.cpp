#include <bits/stdc++.h>
#include <numeric>
using namespace std;
string order;

map<string,pair<string,string> > mapp;
void parse(string s){
    mapp[s.substr(0,3)]=make_pair(s.substr(7,3),s.substr(12,3));
    //cout<<s.substr(0,3)<<"-"<<s.substr(7,3)<<"-"<<s.substr(12,3)<<"\n";
    return;
}
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long  lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
long long per(string s){
    long long ans=0;
    string test=s;
    int i=0;
    while (true) {
            ans++;
        if (order[i]=='L'){
            string neww=mapp[test].first;
            test=neww;
        } else {
            string neww=mapp[test].second;
            test=neww;
        }
        i++;
        if (i==order.length()) i=0;
        if (test[2]=='Z') return ans;
    }
}
vector<string> starts;
int main()
{
    ifstream file;
    file.open("input.txt");
    getline(file,order);
    while(file) {
        string s;
        getline(file,s);
        if (s!="\n" && s!=""){
            parse(s);
        }
        if (s[2]=='A') {
            starts.push_back(s.substr(0,3));
        }
    }
    //cout<<"ord=="<<order;
    int i=0,ans=0;
    //cout<<starts.size();
    //cout<<starts[0]<<"shoooo";
    long long anss=lcm(per(starts[0]),lcm(per(starts[1]),lcm(per(starts[2]),lcm(per(starts[3]),lcm(per(starts[4]),per(starts[5]))))));
    cout<<anss;
    /*while( true ) {
        ans++;
        int endd=0;
        if (order[i]=='L'){
                for (int j=0;j<starts.size();j++)
                {
                    string neww = mapp[starts[j]].first;
                    if (neww[3]!='Z') endd=1;
                    starts[j]=neww;
                    //cout<<neww<<" ";
                }
        } else {
            for (int j=0;j<starts.size();j++)
            {
                    string neww=mapp[starts[j]].second;
                    if (neww[3]!='Z') endd=1;
                    starts[j]=neww;
                    //cout<<neww<<" ";
            }
        }
        i++;
        cout<<endd;
        cout<<"\n";

        if (i==order.length()) i=0;
        if (!endd){
            break;
        }
        //cout<<cur<<" "<<ans<<"\n";
    }*/
}
