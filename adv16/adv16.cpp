#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;


ifstream file;
ofstream file1;

struct cell {
    char ch;
    int N1,W1,E1,S1;
    bool isVisited=false;
};

cell mass[112][112];
void clear1() {
    for(int i=1;i<112;i++) {
        for(int j=1;j<112;j++) {
            mass[i][j].isVisited=false;
            mass[i][j].N1=0;
            mass[i][j].W1=0;
            mass[i][j].E1=0;
            mass[i][j].S1=0;
        }
    }
}
char countSide(char way) {
    if (way=='N') return 'S';
    if (way=='S') return 'N';
    if (way=='E') return 'W';
    if (way=='W') return 'E';
}
void light(int x,int y, char way) {
    char side=countSide(way);
    //file1<<mass[x][y].ch<<" "<<x<<" "<<y<<" "<<way<<endl;
    int visited;
    if (side=='N') visited=mass[x][y].N1;
    if (side=='S') visited=mass[x][y].S1;
    if (side=='W') visited=mass[x][y].W1;
    if (side=='E') visited=mass[x][y].E1;
    if (visited!=1){
        if (mass[x][y].ch=='.') {
            if (side=='N') mass[x][y].N1=1;
            if (side=='S') mass[x][y].S1=1;
            if (side=='W') mass[x][y].W1=1;
            if (side=='E') mass[x][y].E1=1;
            mass[x][y].isVisited=true;
            if (way=='N') light(x-1, y, way);
            if (way=='S') light(x+1,y,way);
            if (way=='W') light(x,y-1,way);
            if (way=='E') light(x,y+1,way);
        }
        if (mass[x][y].ch=='-') {
            if (side=='N') mass[x][y].N1=1;
            if (side=='S') mass[x][y].S1=1;
            if (side=='W') mass[x][y].W1=1;
            if (side=='E') mass[x][y].E1=1;
            mass[x][y].isVisited=true;
            if (way=='N' || way=='S') {light(x, y-1, 'W'); light(x,y+1,'E');};
            if (way=='W') light(x,y-1,way);
            if (way=='E') light(x,y+1,way);
        }
        if (mass[x][y].ch=='|') {
            if (side=='N') mass[x][y].N1=1;
            if (side=='S') mass[x][y].S1=1;
            if (side=='W') mass[x][y].W1=1;
            if (side=='E') mass[x][y].E1=1;
            mass[x][y].isVisited=true;
            if (way=='W' || way=='E') {light(x-1, y, 'N'); light(x+1,y,'S');};
            if (way=='N') light(x-1,y,way);
            if (way=='S') light(x+1,y,way);
        }
        if (mass[x][y].ch=='/') {
            if (side=='N') mass[x][y].N1=1;
            if (side=='S') mass[x][y].S1=1;
            if (side=='W') mass[x][y].W1=1;
            if (side=='E') mass[x][y].E1=1;
            mass[x][y].isVisited=true;
            if (way=='N') light(x, y+1, 'E');
            if (way=='S') light(x,y-1, 'W');
            if (way=='W') light(x+1,y, 'S');
            if (way=='E') light(x-1,y, 'N');
        }
        if (int(mass[x][y].ch)==92) {
            if (side=='N') mass[x][y].N1=1;
            if (side=='S') mass[x][y].S1=1;
            if (side=='W') mass[x][y].W1=1;
            if (side=='E') mass[x][y].E1=1;
            mass[x][y].isVisited=true;
            if (way=='S') light(x, y+1, 'E');
            if (way=='N') light(x,y-1, 'W');
            if (way=='E') light(x+1,y, 'S');
            if (way=='W') light(x-1,y, 'N');
        }
    };
}
int main()
{
    
    file.open("input.txt");
    file1.open("output.txt");
    int i=1;
    for(int j=0;j<112;j++) {
        mass[0][j].ch='#';
        mass[111][j].ch='#';
    }
    while (file) {
        string s;
        getline(file,s);
        if (s!="") {
            s='#'+s+'#';
            for (int j=0;j<s.length();j++){
                mass[i][j].ch=s[j];
            }
            i++;
        }
    }
    int anss11=0,anss12=0,anss22=0,anss21=0,anss31=0,anss32=0,anss41=0,anss42=0;

    light(1,1,'E');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss11++;
            }
        }
    }
    clear1();
    light(1,1,'S');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss12++;
            }
        }
    }
    clear1();
    light(1,110,'S');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss21++;
            }
        }
    }
    clear1();
    light(1,110,'W');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss22++;
            }
        }
    }
    clear1();
    light(110,1,'N');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss31++;
            }
        }
    }
    clear1();
    light(110,1,'E');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss32++;
            }
        }
    }
    clear1();
    light(110,110,'N');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss41++;
            }
        }
    }
    clear1();
    light(110,110,'W');
    for(int j=1;j<=110;j++) {
        for(int jj=1;jj<=110;jj++) {
            if (mass[j][jj].isVisited) {
                anss42++;
            }
        }
    }
    clear1();
    int anss=max(anss11,max(anss12,max(anss21,max(anss22,max(anss31,max(anss32,max(anss41,anss42)))))));
    for(int j1=2;j1<110;j1++) {
        int anss2=0,anss1=0,anss3=0,anss4=0;
        light(1,j1,'S');
        for(int j=1;j<=110;j++) {
            for(int jj=1;jj<=110;jj++) {
                if (mass[j][jj].isVisited) {
                    anss1++;
                }
            }
        }
        clear1();
        light(j1,1,'E');
        for(int j=1;j<=110;j++) {
            for(int jj=1;jj<=110;jj++) {
                if (mass[j][jj].isVisited) {
                    anss2++;
                }
            }
        }
        clear1();
        light(110,j1,'N');
        for(int j=1;j<=110;j++) {
            for(int jj=1;jj<=110;jj++) {
                if (mass[j][jj].isVisited) {
                    anss3++;
                }
            }
        }
        clear1();
        light(j1,110,'W');
        for(int j=1;j<=110;j++) {
            for(int jj=1;jj<=110;jj++) {
                if (mass[j][jj].isVisited) {
                    anss4++;
                }
            }
        }
        clear1();
        anss=max(anss,max(anss1,max(anss2,max(anss3,anss4))));
    }
    file1<<anss;
}
