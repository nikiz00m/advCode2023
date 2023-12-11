#include <bits/stdc++.h>

using namespace std;
char pipes[142][142];
int xs,ys;
int pipesNum[142][142],pipesDeepest[142][142],pipesAns[142][142];
pair<int,char> countline[142];
int deepest, endd=0,size1=0,size2=0;
int deepen(int x,int y,int deep) {
    int maxx=0;
    if (pipes[x][y]=='.'){
        return -1;
    }
    if (x==xs && y==ys && deep!=0){
            if (deep==deepest && endd==0) {
                endd=1;
                for (int i=0;i<size1;i++) {
                    for (int j=0;j<size2;j++) {
                        pipesDeepest[i][j]=pipesNum[i][j];
                        pipesDeepest[xs][ys]=1;
                    }
                }
            }
        return deep;
    } else {
        if (x==xs && y==ys){

            if (pipes[xs+1][y]=='|' || pipes[xs+1][y]=='L' || pipes[xs+1][y]=='J'){
                pipesNum[x+1][y]=1;
                int res1=deepen(x+1,y,deep+1);
                pipesNum[x+1][y]=0;
                maxx=max(maxx,res1);
            }
            if (pipes[xs-1][y]=='|' || pipes[xs-1][y]=='F' || pipes[xs-1][y]=='7'){
                pipesNum[x-1][y]=1;
                int res1=deepen(x-1,y,deep+1);
                pipesNum[x-1][y]=0;
                maxx=max(maxx,res1);
            }
            if (pipes[xs][y+1]=='-' || pipes[xs][y+1]=='J' || pipes[xs][y+1]=='7'){
                pipesNum[x][y+1]=1;
                int res1=deepen(x,y+1,deep+1);
                pipesNum[x][y+1]=0;
                maxx=max(maxx,res1);
            }
            if (pipes[xs][y-1]=='-' || pipes[xs][y-1]=='L' || pipes[xs][y-1]=='F'){
                pipesNum[x][y-1]=1;
                int res1=deepen(x,y-1,deep+1);
                pipesNum[x][y-1]=0;
                maxx=max(maxx,res1);
            }
        }
        if (pipes[x][y]=='|') {
            if (pipesNum[x-1][y]==0){
                pipesNum[x-1][y]=1;
                int res1=deepen(x-1,y,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x-1][y]=0;
            }
            if (pipesNum[x+1][y]==0){
                pipesNum[x+1][y]=1;
                int res1=deepen(x+1,y,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x+1][y]=0;
            }
        }
        if (pipes[x][y]=='-') {
            if (pipesNum[x][y-1]==0){
                pipesNum[x][y-1]=1;
                int res1=deepen(x,y-1,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x][y-1]=0;
            }
            if (pipesNum[x][y+1]==0){
                pipesNum[x][y+1]=1;
                int res1=deepen(x,y+1,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x][y+1]=0;
            }
        }
        if (pipes[x][y]=='L') {
            if (pipesNum[x-1][y]==0){
                pipesNum[x-1][y]=1;
                int res1=deepen(x-1,y,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x-1][y]=0;
            }
            if (pipesNum[x][y+1]==0){
                pipesNum[x][y+1]=1;
                int res1=deepen(x,y+1,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x][y+1]=0;
            }
        }
        if (pipes[x][y]=='J') {
            if (pipesNum[x-1][y]==0){
                pipesNum[x-1][y]=1;
                int res1=deepen(x-1,y,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x-1][y]=0;
            }
            if (pipesNum[x][y-1]==0){
                pipesNum[x][y-1]=1;
                int res1=deepen(x,y-1,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x][y-1]=0;
            }
        }
        if (pipes[x][y]=='7') {
            if (pipesNum[x+1][y]==0){
                pipesNum[x+1][y]=1;
                int res1=deepen(x+1,y,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x+1][y]=0;
            }
            if (pipesNum[x][y-1]==0){
                pipesNum[x][y-1]=1;
                int res1=deepen(x,y-1,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x][y-1]=0;
            }
        }
        if (pipes[x][y]=='F') {
            if (pipesNum[x+1][y]==0){
                pipesNum[x+1][y]=1;
                int res1=deepen(x+1,y,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x+1][y]=0;
            }
            if (pipesNum[x][y+1]==0){
                pipesNum[x][y+1]=1;
                int res1=deepen(x,y+1,deep+1);
                maxx=max(res1,maxx);
                pipesNum[x][y+1]=0;
            }
        }
        return maxx;
    }
}
int anss=0;
bool isNotLine() {
    if ((pipes[xs-1][ys]=='-' || pipes[xs-1][ys]=='L' || pipes[xs-1][ys]=='J') && pipesDeepest[xs-1][ys]==1) return true;
    if ((pipes[xs+1][ys]=='-' || pipes[xs+1][ys]=='7' || pipes[xs+1][ys]=='F') && pipesDeepest[xs+1][ys]==1) return true;
    return false;
}
char whatIs(){
    if ((pipes[xs][ys+1]=='-' || pipes[xs][ys+1]=='7' || pipes[xs][ys+1]=='J') && (pipes[xs-1][ys]=='|' || pipes[xs-1][ys]=='F' || pipes[xs-1][ys]=='7') && pipesDeepest[xs-1][ys]==1 && pipesDeepest[xs][ys+1]==1) return 'L';
    if ((pipes[xs][ys-1]=='-' || pipes[xs][ys-1]=='L' || pipes[xs][ys-1]=='F') && (pipes[xs-1][ys]=='|' || pipes[xs-1][ys]=='F' || pipes[xs-1][ys]=='7') && pipesDeepest[xs-1][ys]==1 && pipesDeepest[xs][ys-1]==1) return 'J';
    if ((pipes[xs][ys-1]=='-' || pipes[xs][ys-1]=='L' || pipes[xs][ys-1]=='F') && (pipes[xs+1][ys]=='|' || pipes[xs+1][ys]=='J' || pipes[xs+1][ys]=='L') && pipesDeepest[xs+1][ys]==1 && pipesDeepest[xs][ys-1]==1) return '7';
    if ((pipes[xs][ys+1]=='-' || pipes[xs][ys+1]=='J' || pipes[xs][ys+1]=='7') && (pipes[xs+1][ys]=='|' || pipes[xs+1][ys]=='J' || pipes[xs+1][ys]=='L') && pipesDeepest[xs+1][ys]==1 && pipesDeepest[xs][ys+1]==1) return 'F';
    if(isNotLine()) return '-';
    else return'|';
}

void getSpace1() {
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if (pipesDeepest[i][j]!=1) {
                if (countline[j].first==1){
                    pipesAns[i][j]=1;
                }
            } else {
                if (pipesDeepest[i][j]!=0) {
                        if (pipes[i][j]!='|') {
                            if (pipes[i][j]=='J') {
                                if (countline[j].second=='F')
                                {
                                    countline[j].first=1-countline[j].first;
                                }
                            }
                            if (pipes[i][j]=='L') {
                                if (countline[j].second=='7')
                                {
                                    countline[j].first=1-countline[j].first;
                                }
                            }
                            countline[j].first=1-countline[j].first;
                            countline[j].second=pipes[i][j];

                        }
                }
            }
        }
    }
}
int main()
{
    ifstream file;
    file.open("input.txt");
    int j=0;
    while (file){
        string s;
        getline(file,s);
        if (s!="" && s!=" "){
            s='.'+s+'.';
            j++;
            for (int i=0;i<s.size();i++){
                size2=s.size();
                pipes[j][i]=s[i];
                if (s[i]=='S') {
                    xs=j;
                    ys=i;
                }
            }
        }
    }
    size1=j+2;
    for(int i=0;i<size2;i++){
        pipes[0][i]='.';
        pipes[size1-1][i]='.';
        pipes[i][0]='.';
        pipes[i][size2-1]='.';
    }
    int ans=0;
    ans=deepen(xs,ys,0);
    deepest=ans;
    ans=deepen(xs,ys,0);
    pipes[xs][ys]=whatIs();
    getSpace1();

    for(int i=1;i<size1-1;i++){
        for(int j=1;j<size2-1;j++){
                anss+=pipesAns[i][j];
        }
    }
    cout<<anss;
}
