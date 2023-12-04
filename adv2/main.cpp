#include <bits/stdc++.h>

using namespace std;
struct game1{
    int red;
    int blue;
    int green;
    int ind;
};
game1 parse1(string s){
    int i=5;
    int gInd=0;
    while(s[i]!=':')
    {
        gInd=10*gInd + (s[i]-'0');
        i++;
        //cout<<"stuck";
    };
    //cout << gInd<<" "<<i<<"\n";
    i+=2;
    int curDig=0,mr=0,mb=0,mg=0;
    int l=s.length();
   while (i<l){
        while (s[i]!=';') {
                if (i>=l) {
                    break;
                }
                //cout<<s[i]<<" now\n";
          if(isdigit(s[i])) {
            curDig=curDig*10+(s[i]-'0');
            //cout<<curDig<<" "<<s[i]<<" "<<i<<"\n";
            i++;
          } else
          {
              if(s[i]==' '){
                    //curDig=0;
                i++;
                //cout<<"2";
              } else {
                if (s[i]=='g'){
                    if(mg<curDig)
                        {
                            mg=curDig;
                        }
                    curDig=0;
                    i+=5;
                    //cout<<"g"<<mg<<"\n";
                } else {
                    if (s[i]=='r') {
                        if(mr<curDig)
                        {
                            mr=curDig;
                        }
                        curDig=0;
                        i+=3;
                        //cout<<"r"<<mr<<"\n";
                    } else {
                        if (s[i]=='b') {
                            if(mb<curDig)
                        {
                            mb=curDig;
                        }
                            curDig=0;
                            i+=4;
                            //cout<<"b"<<mb<<"\n";
                        } else {
                            curDig=0;
                            i++;
                            //cout<<"6";
                        }
                    }
                }
              }
          }
        }
        i++;
   }
    game1 g;
    g.blue=mb;
    g.red=mr;
    g.green=mg;
    g.ind=gInd;
    return g;
}
int main()
{
    ifstream file;
    file.open("input.txt");
    long long sum=0;
    for (int i=0;i<100;i++) {
        string s;
        if(file){getline(file,s);
        cout<<s<<"\n";
        if (s==""){
            break;
        }
        game1 g=parse1(s);
        cout<<"res game r"<<g.red<<" b"<<g.blue<<" g"<<g.green<<"\n";
        sum+=g.blue*g.green*g.red;
        }
    }
    cout<<sum;
    return 0;
}
