#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

ifstream file;
ofstream file1;
struct node {
    int x,y;
    char dir;
};
bool operator<(const node& lhs, const node& rhs) {
    if (lhs.x != rhs.x) {
        return lhs.x < rhs.x;
    }
    if (lhs.y != rhs.y) {
        return lhs.y < rhs.y;
    }
    return lhs.dir < rhs.dir;
}
bool operator==(const node& lhs, const node& rhs) {
    return lhs.x==rhs.x && lhs.y==rhs.y && lhs.dir == rhs.dir;
}
map<node,int> lava;
map<node, int> lava1;
map<int, node> lava2;
map< pair<node,node>, int> rebra;
map<node, vector<node> > neigh;
//map<int,node> dist1;
int visited[1000000];
vector<pair<int,int> > dist;
void dej() {
    node start,end;
    end.x=sqrt(lava.size()/4)-1;
    end.y=end.x;
    end.dir='N';
    start.x=0;
    start.y=0;
    start.dir='N';
    node start1=start,end1;
    end1=end;
    end1.dir='W';
    start1.dir='W';
    int nn=lava1[start],nn1=lava1[start1];
    dist.push_back({0,nn});
    dist.push_back({0,nn1});
    sort(dist.begin(),dist.end());
    //dist1.insert({0,start});
    //dist1.insert({0,start1});
    //file1<<"tut";
    while (!visited[lava1[end]] || !visited[lava1[end1]]) {
        //cout<<dist.size()<<" "<<dist[0].second<<"\n";
        node cur=lava2[dist[0].second];
        int distc=dist[0].first;
        //cur=(*(dist1.begin())).second;
        visited[dist[0].second]=distc;
        dist.erase(dist.begin());
        if (neigh.find(cur)!=neigh.end()) {
        vector<node> sus=neigh[cur];
        for(int i=0;i<sus.size();i++) {
            node neigh=sus[i];
            if (!visited[lava1[neigh]]) {
                int neww=distc+rebra[make_pair(cur,neigh)];
                int nn=lava1[neigh];
                auto it = find_if(dist.begin(), dist.end(), [nn](const auto& pair) {
                return pair.second == nn;
                });
                if (it==dist.end() ) {
                    dist.push_back(make_pair(neww,lava1[neigh]));
                    //dist1.insert(make_pair(neww,neigh));
                } else {
                    if (it->first>neww) {
                        //dist1.erase(dist1.find(make_pair(dist[neigh],neigh)));
                        it->first=neww;
                    }
                }
            }
        }
        sort(dist.begin(),dist.end());
        }
    }
}
int main()
{
    file.open("input.txt");
    file1.open("output.txt");
    int i=0,c=0;
    while (file) {
        string s;
        getline (file,s);
        if (s!="") {
            for(int j=0;j<s.length();j++) {
                int val=s[j]-'0';
                node point1,point2,point3,point4;
                vector<node> emp;
                point1.x=i;
                point1.y=j;
                point1.dir='N';
                lava.insert(make_pair(point1,val));
                lava1.insert(make_pair(point1,c));
                lava2.insert(make_pair(c,point1));
                c++;
                neigh.insert({point1,emp});
                point2=point1;
                point2.dir='S';
                lava.insert(make_pair(point2,val));
                lava1.insert(make_pair(point2,c));
                lava2.insert(make_pair(c,point2));
                c++;
                neigh.insert({point2,emp});
                point3=point1;
                point3.dir='W';
                lava.insert(make_pair(point3,val));
                lava1.insert(make_pair(point3,c));
                lava2.insert(make_pair(c,point3));
                c++;
                neigh.insert({point3,emp});
                point4=point1;
                point4.dir='E';
                lava.insert(make_pair(point4,val));
                lava1.insert(make_pair(point4,c));
                lava2.insert(make_pair(c,point4));
                c++;
                neigh.insert({point4,emp});
            }
            i++; 
        }
    }
    for(auto& ii: lava) {
        node point=ii.first;
        int val=ii.second;
        if (point.dir=='N' || point.dir=='S') {
            int  w=0;
            node point1=point;
            point1.dir='E';
            for(int j=0;j<3;j++) {
                if (point1.y-1<0) {
                    break;
                } 
                point1.y--;
                w+=lava.at(point1);
            }
            for (int j=4;j<11;j++) {
                if (point.y-j<0){
                    break;
                }
                point1.y--;
                neigh[point].push_back(point1);
               w+=lava.at(point1);
               rebra.insert(make_pair(make_pair(point,point1),w));
            }
            w=0;
            point1=point;
            point1.dir='W';
            for(int j=0;j<3;j++) {
                if (point1.y+1>=i) {
                    break;
                } 
                point1.y++;
                w+=lava.at(point1);
            }
            for (int j=4;j<11;j++) {
                if (point.y+j>=i){
                    break;
                }
                point1.y++;
               w+=lava.at(point1);
               neigh[point].push_back(point1);
               rebra.insert(make_pair(make_pair(point,point1),w));
            }
        }

        if (point.dir=='W' || point.dir=='E') {
            int  w=0;
            node point1=point;
            point1.dir='S';
            for(int j=0;j<3;j++) {
                if (point1.x-1<0) {
                    break;
                } 
                point1.x--;
                w+=lava.at(point1);
            }
            for (int j=4;j<11;j++) {
                if (point.x-j<0){
                    break;
                }
                point1.x--;
                neigh[point].push_back(point1);
               w+=lava.at(point1);
               rebra.insert(make_pair(make_pair(point,point1),w));
            }
            w=0;
            point1=point;
            point1.dir='N';
            for(int j=0;j<3;j++) {
                if (point1.x+1>=i) {
                    break;
                } 
                point1.x++;
                w+=lava.at(point1);
            }
            for (int j=4;j<11;j++) {
                if (point.x+j>=i){
                    break;
                }
                point1.x++;
                neigh[point].push_back(point1);
               w+=lava.at(point1);
               rebra.insert(make_pair(make_pair(point,point1),w));
            }
        }
    }
    node end1,end;
    end.x=i-1;
    end.y=end.x;
    end.dir='N';
    end1=end;
    end1.dir='W';
    int nn=lava1[end];
    int nn1=lava1[end1];
    dej();
    int ans1=visited[nn],ans2 =visited[nn1];
    if (ans1!=0 && ans2!=0)
    file1<<min(visited[nn],visited[nn1]);
    else  {
        if (ans1==0) file1<<ans2; else file1<<ans1;
    }
}
