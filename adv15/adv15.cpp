#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
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
int HASH(string s) {
    int ans=0;
    for (int i=0;i<s.length();i++) {
        int cur=int(s[i]);
        ans+=cur;
        ans*=17;
        ans%=256;
    }
    return ans;
}
vector<pair<string,int> > boxes[256];
int main()
{
    ifstream file;
    ofstream file1;
    file.open("input.txt");
    file1.open("output.txt");
    string s;
    getline(file,s);
    s=s+',';
    while (s!="") {
        int boxNum=0;
        string comm=s.substr(0,s.find(','));
        string label;
        char act;
        if (comm.find('=') <  comm.length()) {
            act='=';
        } else act='-';
        label=comm.substr(0,comm.find(act));
        s.erase(0,s.find(',')+1);
        boxNum=HASH(label);
        int found=0;
        for(int i=0;i<boxes[boxNum].size(); i++) {
            if (label==boxes[boxNum][i].first) {
                found=1;
                if(act=='-')
                boxes[boxNum].erase(boxes[boxNum].begin()+i);
                if (act=='=') {
                int val=comm[comm.length()-1]-'0';
                boxes[boxNum][i].second=val;
                break;
                }
            }
        }
        if (!found && act=='=') {
            boxes[boxNum].push_back(make_pair(label,(comm[comm.length()-1]-'0')));
        }
    }
    long long anss=0;
    for(int i=0;i<256;i++) {
        if (boxes[i].size()!=0) {
            int j=1;
            for(auto& ii: boxes[i]){
                anss+=(i+1)*j*ii.second;
                j++;
            }
        } 
    }
    file1<<anss;
}
