#include <iostream>
#include <vector>
#include <string>
#include <climits>
/*Find All occurrences of pat[] in txt[]*/
using namespace std;

vector<int> findOccurr(string &txt, string &pat);

int main()
{
    string txt;
    string pat;

    // cout << "Enter the Main String";
    // getline(cin, txt);
    // cout << "Enter the Pattern String";
    // getline(cin, pat);
    txt="abdabcbabc";
    pat="abc";

    vector<int> occurrences = findOccurr(txt, pat);
    cout << "All the occurrences of Pattern string in Main String are:-";
    for (auto &elem : occurrences)
        cout << elem << " ";

    return 0;
}

vector<int> findOccurr(string &txt,string &pat){
    int n=txt.length(), m=pat.length();
    int h=1;
    
    int d=256;//no. of characters in the input string
    int q=INT_MAX;//base
    //find d^(m-1)
    for(int i=0;i<m-1;i++)
        h=(h*d)%q;
    
    //find hash value of 1st window
    int t=0,p=0;
    for(int i=0;i<m;i++){
        t=(t*d+txt[i])%q;
        p=(p*d+pat[i])%q;
    }

    vector<int> answer;
 
    //compare other windows with pat (hash)
    for(int i=0;i<=n-m;i++){
        if(p==t){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(txt[j+i]!=pat[j]){
                      flag=false;
                      break;
                }
            }
        if(flag==true)
            answer.push_back(i);
        }

        if(i<n-m){
            //next hash value
            t=(d*(t-txt[i]*h)+txt[i+m])%q;

            if(t<0)
                t=t+q;
        }
    }
    return answer;
}