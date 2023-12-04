#include <bits/stdc++.h>

using namespace std;
int lines=0,n=140;
string arr1[200];
int arr2[200][200];
bool isnot(char ch){
    if (ch=='.' || (((ch-'0')<=10) && (ch-'0')>=0)){
        return false;
    }
    return true;
}
int checkk(int i, int j){
    int cnt=0,summ=1;
    int deg=10,num=0;
    if(isdigit(arr1[i-1][j]) && ((arr2[i-1][j])==0)){
        cnt++;
        int ii=i-1;
        int jj=j;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;
            arr2[ii][jj+1]=cnt;
            jj++;
            cout<<num<<"1 "<<ii<<" "<<jj<<"\n";
        }
        cout<<num<<"\n";
        jj=j;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            cout<<"11 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        cout<<num<<" ";
        num=0;
    }
    if(isdigit(arr1[i-1][j-1]) && ((arr2[i-1][j-1])==0)){
        cnt++;
        int ii=i-1;
        int jj=j-1;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;

            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"2 "<<ii<<" "<<jj<<"\n";
        }
        jj=j-1;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"22 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    if(isdigit(arr1[i-1][j+1]) && ((arr2[i-1][j+1])==0)){
        cnt++;
        int ii=i-1;
        int jj=j+1;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;
            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"3 "<<ii<<" "<<jj<<"\n";
        }
        jj=j+1;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"33 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    if(isdigit(arr1[i][j+1]) && ((arr2[i][j+1])==0)){
        cnt++;
        int ii=i;
        int jj=j+1;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;

            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"4 "<<ii<<" "<<jj<<"\n";
        }
        jj=j+1;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"44 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    if(isdigit(arr1[i][j-1]) && ((arr2[i][j-1])==0)){
        cnt++;
        int ii=i;
        int jj=j-1;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;

            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"5 "<<ii<<" "<<jj<<"\n";
        }
        jj=j-1;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"55 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    if(isdigit(arr1[i+1][j]) && ((arr2[i+1][j])==0)){
        cnt++;
        int ii=i+1;
        int jj=j;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;
            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"6 "<<ii<<" "<<jj<<"\n";
        }
        jj=j;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"66 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    if(isdigit(arr1[i+1][j-1]) && ((arr2[i+1][j-1])==0)){
        cnt++;
        int ii=i+1;
        int jj=j-1;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;
            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"7 "<<ii<<" "<<jj<<"\n";
        }
        jj=j-1;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"77 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    if(isdigit(arr1[i+1][j+1]) && ((arr2[i+1][j+1])==0)){
        cnt++;
        int ii=i+1;
        int jj=j+1;
        num=(arr1[ii][jj]-'0');
        arr2[ii][jj]=cnt;
        while(isdigit(arr1[ii][jj+1])){
            num=num*10+(arr1[ii][jj+1]-'0');
            deg*=10;
            arr2[ii][jj+1]=cnt;
            jj++;
            //cout<<"8 "<<ii<<" "<<jj<<"\n";
        }
        jj=j+1;
        while(isdigit(arr1[ii][jj-1])){
            num=deg*(arr1[ii][jj-1]-'0')+num;
            deg*=10;
            arr2[ii][jj-1]=cnt;
            jj--;
            //cout<<"88 "<<ii<<" "<<jj<<"\n";
        }
        deg=10;
        summ*=num;
        num=0;
    }
    for (int jj=0;jj<=141;jj++) {
        arr2[i][jj]=0;
        arr2[i-1][jj]=0;
        arr2[i+1][jj]=0;
    }
    if (cnt==2) {
        return summ;
    }
    return 0;
}
int main()
{
    ifstream file;
    string ss="";
    for (int i=0; i<140;i++) {
        ss=ss+'.';
    }
    arr1[0]=ss;
    arr1[141]=ss;
    file.open("input.txt");
    while(file) {
        string s;
        if(file) {getline(file,s);};
        //cout<<s<<"\n";
        arr1[lines+1]='.'+s+'.';
        if (arr1[lines]!="") {lines++;};
    }
    int curDig=0,sum=0;
    bool isin=false;
    for (int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
              arr2[i][j]=0;
        }
    }
    long long ans=0;
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (arr1[i][j]=='*'){
                int cc=checkk(i,j);
                ans+=cc;
                cout<<" ind:"<<i<<" "<<j<<" "<<cc<<"\n";
            }
        }
    }
    /*
    for (int i=1;i<=n;i++){
            if (isin){
                sum+=curDig;
            }
            curDig=0;
            isin=false;
        for(int j=1;j<=n;j++){
            if(isdigit(arr1[i][j])) {
                curDig=curDig*10+(arr1[i][j]-'0');
                if((arr1[i-1][j]!='.') && (isnot(arr1[i-1][j]))){
                    isin=true;
                }
                if((arr1[i-1][j-1]!='.') && (isnot(arr1[i-1][j-1]))){
                    isin=true;
                }
                if((arr1[i-1][j+1]!='.') && (isnot(arr1[i-1][j+1]))){
                    isin=true;
                }
                if((arr1[i][j+1]!='.') && (isnot(arr1[i][j+1]))){
                    isin=true;
                }
                if((arr1[i][j-1]!='.') && (isnot(arr1[i][j-1]))){
                    isin=true;
                }
                if((arr1[i+1][j]!='.') && (isnot(arr1[i+1][j]))){
                    isin=true;
                }
                if((arr1[i+1][j-1]!='.') && (isnot(arr1[i+1][j-1]))){
                    isin=true;
                }
                if((arr1[i+1][j+1]!='.') && (isnot(arr1[i+1][j+1]))){
                    isin=true;
                }
            } else {
                if(isin) {
                    sum+=curDig;
                    cout<<curDig<<"\n";
                }
                isin=false;
                curDig=0;
            }
        }
    }
    if (isin){
                sum+=curDig;
            }
            curDig=0;
            isin=false;
*/
    cout<< ans;
    return 0;
}
