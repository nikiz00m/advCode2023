#include <bits/stdc++.h>

using namespace std;
struct maps{
    long long original,result,length;
};
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
bool helpS(maps x, maps y) {
    return x.result<y.result;
}
vector<maps> ss,sf,fw,wl,lt,th,hl;
vector<maps> seeds;

long long minOnLineOnHL(long long st,long long endd){
    cout<<"hl "<<st<<" "<<endd<<" ";
    for (int i=0;i<hl.size();i++) {
        long long end1=hl[i].length+hl[i].original-1,st1=hl[i].original,mer=hl[i].result;
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {

                    cout<<mer+(st-st1)<<"\n";
                    return mer+(st-st1);
                }
                else
                {
                    long long ans=min(minOnLineOnHL(end1+1,endd),mer+st-st1);
                    cout<<ans<<"\n";
                    return ans;
                }
            } else {
                    if (st1>st && endd>end1) {
                            long long ans= min(min(minOnLineOnHL(st,st1-1),minOnLineOnHL(end1+1,endd)),mer);
                            cout<<ans<<"\n";
                        return ans;
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            long long ans=min(minOnLineOnHL(st,st1-1),mer);
                            cout<<ans<<"\n";
                            return ans;
                        }
                    }
            }
    }
    cout<<st<<"\n";
    return st;
}
long long minOnLineOnTH(long long st,long long endd){
    cout<<"th "<<st<<" "<<endd<<"\n";
    for (int i=0;i<th.size();i++) {
        long long end1=th[i].length+th[i].original-1,st1=th[i].original, mer=th[i].result;
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {
                    return minOnLineOnHL(mer+(st-st1),mer-st1+endd);
                }
                else
                {
                    return min(minOnLineOnTH(end1+1,endd),minOnLineOnHL(mer+st-st1,mer-st1+end1));
                }
            } else {
                    if (st1>st && endd>end1) {
                        return min(min(minOnLineOnTH(st,st1-1),minOnLineOnTH(end1+1,endd)),minOnLineOnHL(mer,mer+(end1-st1)));
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            return min(minOnLineOnTH(st,st1-1),minOnLineOnHL(mer,mer+endd-st1));
                        }
                    }
            }


}
return minOnLineOnHL(st,endd);
}
long long minOnLineOnLT(long long st,long long endd){
    cout<<"lt "<<st<<" "<<endd<<"\n";
    for (int i=0;i<lt.size();i++) {
        long long end1=lt[i].length+lt[i].original-1,st1=lt[i].original, mer=lt[i].result;
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {
                    return minOnLineOnTH(mer+(st-st1),mer-st1+endd);
                }
                else
                {
                    return min(minOnLineOnLT(end1+1,endd),minOnLineOnTH(mer+st-st1,mer-st1+end1));
                }
            } else {
                    if (st1>st && endd>end1) {
                        return min(min(minOnLineOnLT(st,st1-1),minOnLineOnLT(end1+1,endd)),minOnLineOnTH(mer,mer+(end1-st1)));
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            return min(minOnLineOnLT(st,st1-1),minOnLineOnTH(mer,mer+endd-st1));
                        }
                    }
            }

}
return minOnLineOnTH(st,endd);
}
long long minOnLineOnWL(long long st,long long endd){
    cout<<"wl "<<st<<" "<<endd<<"\n";
    for (int i=0;i<wl.size();i++) {
        long long end1=wl[i].length+wl[i].original-1,st1=wl[i].original, mer=wl[i].result;
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {
                    return minOnLineOnLT(mer+(st-st1),mer-st1+endd);
                }
                else
                {
                    return min(minOnLineOnWL(end1+1,endd),minOnLineOnLT(mer+st-st1,mer-st1+end1));
                }
            } else {
                    if (st1>st && endd>end1) {
                        return min(min(minOnLineOnWL(st,st1-1),minOnLineOnWL(end1+1,endd)),minOnLineOnLT(mer,mer+(end1-st1)));
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            return min(minOnLineOnWL(st,st1-1),minOnLineOnLT(mer,mer+endd-st1));
                        }
                    }
            }

}
return minOnLineOnLT(st,endd);
}
long long minOnLineOnFW(long long st,long long endd){
    cout<<"fw "<<st<<" "<<endd<<"\n";
    for (int i=0;i<fw.size();i++) {
        long long end1=fw[i].length+fw[i].original-1,st1=fw[i].original, mer=fw[i].result;
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {
                    return minOnLineOnWL(mer+(st-st1),mer-st1+endd);
                }
                else
                {
                    return min(minOnLineOnFW(end1+1,endd),minOnLineOnWL(mer+st-st1,mer-st1+end1));
                }
            } else {
                    if (st1>st && endd>end1) {
                        return min(min(minOnLineOnFW(st,st1-1),minOnLineOnFW(end1+1,endd)),minOnLineOnWL(mer,mer+(end1-st1)));
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            return min(minOnLineOnFW(st,st1-1),minOnLineOnWL(mer,mer+endd-st1));
                        }
                    }
            }

}
return minOnLineOnWL(st,endd);
}
long long minOnLineOnSF(long long st,long long endd){
    cout<<"sf "<<st<<" "<<endd<<"\n";
    for (int i=0;i<sf.size();i++) {
        long long end1=sf[i].length+sf[i].original-1,st1=sf[i].original, mer=sf[i].result;
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {
                    return minOnLineOnFW(mer+(st-st1),mer-st1+endd);
                }
                else
                {
                    return min(minOnLineOnSF(end1+1,endd),minOnLineOnFW(mer+st-st1,mer-st1+end1));
                }
            } else {
                    if (st1>st && endd>end1) {
                        return min(min(minOnLineOnSF(st,st1-1),minOnLineOnSF(end1+1,endd)),minOnLineOnFW(mer,mer+(end1-st1)));
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            return min(minOnLineOnSF(st,st1-1),minOnLineOnFW(mer,mer+endd-st1));
                        }
                    }
            }
}
return minOnLineOnFW(st,endd);
}
long long minOnLineOnSS(long long st,long long endd){
    cout<<"ss "<<st<<" "<<endd<<"\n";
    for (int i=0;i<ss.size();i++) {
        long long end1=ss[i].length+ss[i].original-1,st1=ss[i].original, mer=ss[i].result;
        cout<<st1<<" "<<end1<<" "<<mer<<" ss\n";
        if (st<=(end1) && (st>=st1)){
                if (endd<= (end1) && endd>=st1)
                {
                    return minOnLineOnSF(mer+(st-st1),mer-st1+endd);
                }
                else
                {
                    return min(minOnLineOnSS(end1+1,endd),minOnLineOnSF(mer+st-st1,mer-st1+end1));
                }
            } else {
                    if (st1>st && endd>end1) {
                        return min(min(minOnLineOnSS(st,st1-1),minOnLineOnSS(end1+1,endd)),minOnLineOnSF(mer,mer+(end1-st1)));
                    } else {
                        if (endd>=st1 && endd<=end1) {
                            return min(minOnLineOnSS(st,st1-1),minOnLineOnSF(mer,mer+endd-st1));
                        }
                    }
            }
    }
 return minOnLineOnSF(st,endd);
}
/*
long long findLocation(long long seed){
    long long soil=-1,fer=-1,wat=-1,light=-1,tempe=-1,humi=-1,locat=-1;

    for (int i=0;i!=ss.size();i++) {
        if (seed<=(ss[i].length+ss[i].original-1) && (seed>=ss[i].original)){
            soil=ss[i].result+(seed-ss[i].original);
            break;
        }
    }
    if (soil==-1) soil=seed;

    for (int i=0;i!=sf.size();i++) {
        if (soil<=(sf[i].length+sf[i].original-1) && (soil>=sf[i].original)){
            fer=sf[i].result+(soil-sf[i].original);
            break;
        }
    }
    if (fer==-1) fer=soil;

    for (int i=0;i!=fw.size();i++) {
        if (fer<=(fw[i].length+fw[i].original-1) && (fer>=fw[i].original)){
            wat=fw[i].result+(fer-fw[i].original);
            break;
        }
    }
    if (wat==-1) wat=fer;

    for (int i=0;i!=wl.size();i++) {
        if (wat<=(wl[i].length+wl[i].original-1) && (wat>=wl[i].original)){
            light=wl[i].result+(wat-wl[i].original);
            break;
        }
    }
    if (light==-1) light=wat;

    for (int i=0;i!=lt.size();i++) {
        if (light<=(lt[i].length+lt[i].original-1) && (light>=lt[i].original)){
            tempe=lt[i].result+(light-lt[i].original);
            break;
        }
    }
    if (tempe==-1) tempe=light;

    for (int i=0;i!=th.size();i++) {
        if (tempe<=(th[i].length+th[i].original-1) && (tempe>=th[i].original)){
            humi=th[i].result+(tempe-th[i].original);
            break;
        }
    }
    if (humi==-1) humi=light;

    for (int i=0;i!=hl.size();i++) {
        if (humi<=(hl[i].length+hl[i].original-1) && (humi>=hl[i].original)){
            locat=hl[i].result+(humi-hl[i].original);
            break;
        }
    }
    if (locat==-1) locat=humi;

    return locat;

}*/
int main()
{
    ifstream file;
    file.open("input.txt");
    string seed;
    if (file){
            getline(file,seed);
    }
    seed=seed+' ';
    seed.erase(0,seed.find(':')+2);
    //cout<<seed<<" chmo \n";
    while (seed!=" " && seed!=""){
        string subseed=seed.substr(0,seed.find(' '));
        long long seed1=convert(subseed),seed2;
        seed.erase(0,seed.find(' ')+1);
        subseed=seed.substr(0,seed.find(' '));
        seed2=convert(subseed);
        seed.erase(0,seed.find(' ')+1);
        if (seed1!=-1 && seed2!=1) {
                maps mapp;
        mapp.result=-1;
        mapp.length=seed2;
        mapp.original=seed1;
        seeds.push_back(mapp);

        //cout<<"-"<<subseed<<"- "<<seed1<<" ja \n";

        //cout<<"ne "<<seed<<" \n";
    };
    while (file) {
           string s;
        if (file) {
            getline(file,s);
        }
        //cout<<"tut";
        if ((s.find("soil map:")<(s.length())) && (s.find("soil map:")>=0)) {
            getline(file,s);
            if (s!="" && s!=" ") s=s+' ';
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                ss.push_back(mapp);
                //cout<< mapp.original<<" "<<mapp.result<<" "<<mapp.length<<"\n";
                getline(file,s);
                s=s+' ';
                //cout<<s<<" 7\n";
            }
        }
        if ((s.find("fertilizer map")<(s.length())) && (s.find("fertilizer map")>=0)) {
            getline(file,s);
            if (s!="" && s!=" ") s=s+' ';
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                sf.push_back(mapp);
                getline(file,s);
                s=s+' ';
                //cout<<"6";
            }
        }
        if ((s.find("water map:")<(s.length())) && (s.find("water map:")>=0)) {
            getline(file,s);
            if (s!="" && s!=" ") s=s+' ';
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                fw.push_back(mapp);
                getline(file,s);
                s=s+' ';
                //cout<<"5";
            }
        } if ((s.find("light map:")<(s.length())) && (s.find("light map:")>=0)) {
            getline(file,s);
            if (s!="" && s!=" ") s=s+' ';
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                wl.push_back(mapp);
                getline(file,s);
                s=s+' ';
                //cout<<"4";
            }
        } if ((s.find("temperature map:")<(s.length())) && (s.find("temperature map:")>=0)) {
            getline(file,s);
            if (s!="") s=s+' ';
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                lt.push_back(mapp);
                getline(file,s);
                s=s+' ';
                //cout<<"3";
            }
        } if ((s.find("humidity map")<(s.length())) && (s.find("humidity map")>=0)) {
            getline(file,s);
            if (s!="" && s!=" ") s=s+' ';
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                th.push_back(mapp);
                getline(file,s);
                s=s+' ';
                //cout<<"2";
            }
        } if ((s.find("location map")<(s.length())) && (s.find("location map")>=0)) {
            if (file)
            getline(file,s);
            else {
                break;
            }
            if (s!="" && s!=" ") s=s+' ';
            //cout<<s<<"-\n";
            while (s!="" && s!=" "){
                maps mapp;
                mapp.result=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.original=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                mapp.length=convert(s.substr(0,s.find(' ')));
                s.erase(0,s.find(' ')+1);
                hl.push_back(mapp);
                getline(file,s);
                s=s+' ';
                //cout<<"-"<<s<<"-shuk-"<<s.substr(0,s.find(' '))<<"-1\n";
            }
        }
    }
     }
     sort(ss.begin(),ss.end(),helpS);
     sort(sf.begin(),sf.end(),helpS);
     sort(fw.begin(),fw.end(),helpS);
     sort(wl.begin(),wl.end(),helpS);
     sort(lt.begin(),lt.end(),helpS);
     sort(th.begin(),th.end(),helpS);
     sort(hl.begin(),hl.end(),helpS);

     long long minn=-1;
     for (long long i=0;i<seeds.size();i++) {
         long long st=seeds[i].original,endd=seeds[i].length+seeds[i].original-1;
         if (minn==-1){
            minn=minOnLineOnSS(st,endd);
         } else {
            minn=min(minn,minOnLineOnSS(st,endd));
         }
     }
     cout<<minn;
}
