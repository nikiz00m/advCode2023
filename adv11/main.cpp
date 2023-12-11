#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > stars;
vector<int> fatLine,fatStolb;
char uni[1000][1000];
int size1,size2;
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
string to_string(int n) {
    string s="";
    int nn=n;
    while (nn!=0){
            char ss='0'+(nn%10);

        s=ss+s;
        nn/=10;
    }
    if (s=="")
        return "0";
    return s;
}
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

long long findAmountFatLine(int x1, int x2){
    long long ans=0,xx=min(x1,x2),xxx=max(x1,x2);
    for(int i=xx;i<=xxx;i++){
        if (find(fatLine.begin(),fatLine.end(),i)!=fatLine.end()) {
            ans++;
        }
    }
    return ans;
}
long long findAmountFatStolb(int y1, int y2){
    long long ans=0,yy=min(y1,y2),yyy=max(y1,y2);
    for(int i=yy;i<=yyy;i++){
        if (find(fatStolb.begin(),fatStolb.end(),i)!=fatStolb.end()) {
            ans++;
        }
    }
    return ans;
}
string findPath(int x1,int y1, int x2, int y2){
    long long axx=abs(x1-x2),bxx=abs(y1-y2),f1=findAmountFatLine(x1,x2),f2=findAmountFatStolb(y1,y2);
    string s1=to_string(axx),s2=to_string(bxx),s3=to_string(f1),s4=to_string(f2);
    string ans=addStrings(s1,addStrings(s2,multiplyStrings("999999",addStrings(s3,s4))));
    return ans;
}
int main()
{
    ifstream file;
    file.open("input.txt");
    int i=0;

    while (file){
        string s;
        getline(file,s);
        if (s!=""){
            i++;
            size1=s.length();
            if (s.find('#')>=s.length()+1) {
                fatLine.push_back(i-1);
            }
            for(int j=0;j<s.length();j++){
                uni[i-1][j]=s[j];
                if (s[j]=='#'){
                   stars.push_back(make_pair(i-1,j));
                }
            }
        }
    }
    size2=i;
    for(int j=0;j<size1;j++){
            int non=0;
        for(int jj=0;jj<size2;jj++) {
            if (uni[jj][j]=='#') {
                non=1;
                break;
            }
        }
        if (non==0) {
            fatStolb.push_back(j);
        }
    }
    string anss="0";
    for(int j=0;j<stars.size()-1;j++){
       for(int jj=j+1;jj<stars.size();jj++){
       string sum=findPath(stars[j].first,stars[j].second,stars[jj].first,stars[jj].second);
        anss=addStrings(anss,sum);
       }
    }
    cout<<anss;
}
