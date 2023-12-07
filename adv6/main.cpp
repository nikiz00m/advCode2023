#include <bits/stdc++.h>

using namespace std;
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
long long tim[4],dist[4];
int main()
{
    ifstream file;
    file.open("input.txt");
    string t,d;
    getline(file,t);
    getline(file,d);
    long long timm=0,distt=0;
    for(int i =0;i<t.length();i++) {
        if (isdigit(t[i])){
            timm=timm*10+(t[i]-'0');
        }
    }

    for(int i =0;i<d.length();i++) {
        if (isdigit(d[i])){
            distt=distt*10+(d[i]-'0');
        }
    }
    int i=0;
    /*while (t!="" && d!=""){
        while (t[0]==' '){
            t.erase(0,1);
        }
        while (d[0]==' '){
            d.erase(0,1);
        }
        tim[i]=convert(t.substr(0,t.find(' ')));
        dist[i]=convert(d.substr(0,d.find(' ')));
        t.erase(0,t.find(' ')+1);
        d.erase(0,d.find(' ')+1);
        i++;
    }*/
    long long ans=0;
    for (int j=0;j<=timm;j++){
                //cout<<j<<" "<<tim[i]<<" "<<(tim[i]-j)*j<<" "<<dist[i]<<" \n";
            if (j*(timm-j)>=distt) ans++;
    }
      cout<<ans;
}
