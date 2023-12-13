#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<pair<string,vector<int> >, string> memmo;
string multiplyStrings(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    string result(len1 + len2, '0');
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (result[i + j + 1] - '0');
            result[i + j + 1] = sum % 10 + '0';
            result[i + j] += sum / 10;
        }
    }
    int pos = result.find_first_not_of('0');
    if (pos <=result.length()-1) {
        return result.substr(pos);
    }
    return "0";
}
string addStrings(string num1, string num2) {
    string result;
    int carry = 0;
    string n1 = num1.length() > num2.length() ? num1 : num2;
    string n2 = num1.length() > num2.length() ? num2 : num1;
    n2.insert(0, n1.length() - n2.length(), '0');
    for (int i = n1.length() - 1; i >= 0; --i) {
        int digitSum = (n1[i] - '0') + (n2[i] - '0') + carry;
        carry = digitSum / 10;
        result.push_back((digitSum % 10) + '0');
    }
    if (carry > 0) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
int vectSum(vector<int> num) {
    int ans=0;
    for (int i=0;i<num.size();i++) {
        ans+=num[i];
    }
    return ans;
};
/*bool isCorrect(string line, vector<int> num) {

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
    if (num.size()==0) return true;
    else return false;
}
int findAns(string line, vector<int> num) {
    if (line.length()==0 && num.size()!=0) {
        return 0;
    } else {
        if (line.length()==0 && num.size()==0) {
            return 1;
        }
    }
    //cout<<line<<" \n";
    if (memmo.find(make_pair(line,num))!=memmo.end()) {
        //cout<< memmo.at(make_pair(line,num))<<" znayu\n";
        return memmo.at(make_pair(line, num));
    } else {
        if (line[0]=='.') {
            int ans1=findAns(line.substr(1,line.length()-1),num);
            memmo.insert({make_pair(line, num), ans1});
            return ans1;
        }
        if (line[0]=='?') {
            int ans=findAns('.'+line.substr(1, line.length()-1), num)+findAns('#'+line.substr(1, line.length()-1), num);
            memmo.insert({make_pair(line,num),ans});
            return ans;
        }
        if (line[0]=='#') {
            if (num.size()==0) {
                memmo.insert({make_pair(line,num),0});
                return 0;
            }
            if(line.length()<num[0]) {
                memmo.insert({make_pair(line,num),0});
                return 0;
            }
            if (line.find('.')<num[0]) {
                memmo.insert({make_pair(line,num),0});
                return 0;
            }
            if(line[num[0]]=='#' ) {
                memmo.insert({make_pair(line,num),0});
                return 0;
            }
            if (num.size()==1) {
                string line1=line.substr(num[0]+1);
                if (line1.find('#') < line1.length()) {
                memmo.insert({make_pair(line,num),0});
                return 0;
                }
                memmo.insert({make_pair(line,num),1});
                return 1;
            } else {
                int nn=num[0];
                num.erase(num.begin());
                int ans1=findAns(line.substr(nn+1),num);
                num.push_back(nn); 
                memmo.insert({make_pair(line,num),ans1});   
                return ans1;
            }
        }
    }
    return 0;
}
*/
string ress1(string line, vector<int> num);
string ress(string line, vector<int> num) {
    if (line.length()==0) {
        if (num.size()==0) return "1";
        else return "0";
    } else {
        if (line[0]=='.') {
            return ress1(line.substr(1),num);
        }
        if (line[0]=='?') {
            string res1=ress1('.'+line.substr(1), num);
            string res2=ress1('#'+line.substr(1), num);
            return  addStrings(res1, res2);
        } 
        if (line[0]=='#') {
            if (num.size()==0) return "0";
            if (line.length() < num[0]) return "0";
            if (line.find('.')<num[0]) return "0";

            if (num.size()==1) {
                int nn=num[0];
                num.erase(num.begin());
                return ress1(line.substr(nn), num);
            } else {
                if (line.length()< num[0]+1) return "0";
                if (line[num[0]]=='#' ) return "0";
                int nn=num[0];
                num.erase(num.begin());
                return ress1(line.substr(nn+1), num);
            }
        }
    }
}
string ress1(string line, vector<int> num) {
    if (memmo.find(make_pair(line,num)) != memmo.end()) {
        return memmo.at(make_pair(line, num));
    } else {
        string ans= ress(line,num);
        memmo.insert({make_pair(line,num),ans});
        return ans;
    }
}
int main()
{
    ifstream file;
    ofstream file1;
    file1.open("output.txt");
    file.open("input.txt");
    string ans="0";
    int j=1;
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
            //int ans1=ress1(s1, prob);
            string ans1;
            string sss=s1+'?'+s1+'?'+s1+'?'+s1+'?'+s1;
            if (sss.length()== mprob.size()+vectSum(mprob)-1) ans1="1";
            else
            ans1=ress1(sss,mprob);
            file1<<s1<<" : "<<ans1<<" \n";
            //j++;
            ans=addStrings(ans1,ans);
        }
    }
    /*for (auto& i:memmo) {
        cout<<i.first.first<<" "<<i.second<<" ";
        for (int ii=0;ii<i.first.second.size();ii++)
        cout<<i.first.second[ii]<<" ";
        cout<<"\n";
    }*/
    cout<<ans;
}