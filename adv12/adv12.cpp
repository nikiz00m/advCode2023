#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;
int vectSum(vector<int> num) {
    int ans=0;
    for (int i=0;i<num.size();i++) {
        ans+=num[i];
    }
    return ans;
}
bool isCorrect(string line, vector<int> num) {
    int last=0, isProb=0,sum=vectSum(num);
    for(int i=0;i<line.length();i++) {
        if (line[i]=='?') {
            return true;
        }
        if (line[i]=='.') {
            if(isProb) {
                if (num.size()==0) return false;
                if (num[0]==last) {
                    num.erase(num.begin());
                    sum-=last;
                    last=0;
                    isProb=0;
                } else return false;
            }
            int sizen=num.size()-1;
            int maxx=max(sizen,0);
            if (line.length()-i-1<sum+maxx) return false;
        }
        if (line[i]=='#') {
            isProb=1;
            last++;
            if (num[0]<last) {
                return false;
            }
        }
    }
    if(isProb) {
    if (num.size()==0) return false;
        if (num[0]==last) {
                num.erase(num.begin());
                sum-=last;
                last=0;
                isProb=0;
        } else return false;
    }
    //cout<<"tut "<<line<<" "<<num.size()<<"\n";
    if (num.size()==0) return true;
    else return false;
}
int findAns(string line, vector<int> num) {
    int anss=0;
    //cout<<line<<">>>";
    if (line.find('?')!=string::npos) {
        string line1=line,line2=line;
        line1[line.find('?')]='.';
        line2[line.find('?')]='#';
        //cout<<line1<<"   "<<line2<<"\n";
        if (isCorrect(line1,num)) anss+=findAns(line1, num);
        if (isCorrect(line2,num)) anss+=findAns(line2, num);
    } else return 1;
    return anss;
}
int main()
{
    ifstream file;
    file.open("input.txt");
    int ans=0;
    while (file) {
        string s;
        getline(file,s);
        if (s!="") {
            string s1=s.substr(0,s.find(' '));
            s.erase(0,s.find(' ')+1);
            s=s+',';
            vector<int> prob;
            while(s!="") {
                prob.push_back(stoi(s.substr(0,s.find(','))));
                s.erase(0,s.find(',')+1);
            }
            vector<int> mprob;
            for(int i=0;i<5;i++) {
                for(int j=0;j<prob.size();j++){
                    mprob.push_back(prob[j]);
                }
            }
            int ans1=findAns(s1+s1+s1+s1+s1,mprob);
            //cout<<"otv:"<<ans1<<"\n";
            ans+=ans1;
        }
    }
    cout<<ans;
}
