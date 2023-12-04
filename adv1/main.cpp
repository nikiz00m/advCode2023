#include <bits/stdc++.h>

using namespace std;
bool createNum(string s, string s1 , int i)
{
 int l=s1.length();
 string ch="";
 for (int j=0;j<l;j++){
        if((j+i)>=s.length())
        return false;
        else
    ch=ch+s[j+i];
 //cout<<ch<<"->\n";
 }
 //cout<<ch<<" check "<<s1<<"\n";
 if(s1==ch){
    return true;
 }
 return false;
}
bool createNum1(string s, string s1 , int i)
{
 int l=s1.length();
 string ch="";
 for (int j=0;j<l;j++){
        if (s.length()-j-i-1<0)
        return false;
        else
    ch=s[s.length()-j-i-1]+ch;
 }
 //cout<<ch<<" check "<<s1<<"\n";
 if(s1==ch){
    return true;
 }
 return false;
}
int checkStrNum1(int i, string s)
{
 if(createNum1(s,"one",i))
 {
   return 1;
 }
 if(createNum1(s,"two",i))
 {
   return 2;
 }
 if(createNum1(s,"three",i))
 {
   return 3;
 }
 if(createNum1(s,"four",i))
 {
   return 4;
 }
 if(createNum1(s,"five",i))
 {
   return 5;
 }
 if(createNum1(s,"six",i))
 {
   return 6;
 }
 if(createNum1(s,"seven",i))
 {
   return 7;
 }
 if(createNum1(s,"eight",i))
 {
   return 8;
 }
 if(createNum1(s,"nine",i))
 {
   return 9;
 }
 return -1;
}
int checkStrNum(int i, string s)
{
 if(createNum(s,"one",i))
 {
   return 1;
 }
 if(createNum(s,"two",i))
 {
   return 2;
 }
 if(createNum(s,"three",i))
 {
   return 3;
 }
 if(createNum(s,"four",i))
 {
   return 4;
 }
 if(createNum(s,"five",i))
 {
   return 5;
 }
 if(createNum(s,"six",i))
 {
   return 6;
 }
 if(createNum(s,"seven",i))
 {
   return 7;
 }
 if(createNum(s,"eight",i))
 {
   return 8;
 }
 if(createNum(s,"nine",i))
 {
   return 9;
 }
 return -1;
}
int main()
{
    int sum=0;
    while(cin.good() && !cin.eof())
    {
        string line;
        cin >> line;
        int dig1,dig2;
        dig1=-1;
        dig2=-1;
        int len=line.length();
        for(int i=0; i<len; i++)
        {
            int n1,n2;
            n1=checkStrNum(i,line);
            n2=checkStrNum1(i,line);
            //cout<<n1<<"  "<<n2<<"pov\n";
            if ((isdigit(line[i]) || (n1!=-1) ) && dig1==-1)
                {
                    if(isdigit(line[i]))
                    dig1=line[i]-'0';
                    else
                    dig1=n1;
                    //cout<<dig1<<"tut\n";
                }
            if ((isdigit(line[len-i-1]) || (n2!=-1)) && dig2==-1)
                {
                    if (isdigit(line[len-i-1]))
                    dig2=line[len-i-1]-'0';
                    else
                        dig2=n2;
                    //cout<<dig2<<"tut2\n";
                }
            if(dig2!=-1 && dig1!=-1) {
                sum+= dig1*10+dig2;
                break;
            }

        }
    }
    cout <<sum;
    return 0;
}
