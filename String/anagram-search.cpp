#include <bits/stdc++.h>

using namespace std;

bool areArraysSame(int *a, int *b, int n);
vector<int> findAnagrams(string &txt, string &pat);
int main()
{
    string txt;
    string pat;
    txt="geeksforgeeks";
    pat="frog";

    cout<<"Anagrams of "<<pat<<" in "<<txt<<" are:-";
    vector<int>anagrams_idx=findAnagrams(txt,pat);
    for(auto& elem:anagrams_idx){
        cout<<elem<<" ";
    }
    
    return 0;
}

bool areArraysSame(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

vector<int> findAnagrams(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();

    if (n < m)
        return {};

    int count_txt[256]{0};
    int count_pat[256]{0};
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        count_txt[txt[i]]++;
        count_pat[pat[i]]++;
    }
    if (areArraysSame(count_txt, count_pat, 256))
        ans.push_back(0);

    // compare and slide the windows
    for (int i = m; i < n; i++)
    {
        count_txt[txt[i]]++;     // new End
        count_txt[txt[i - m]]--; // prev Start removed

        if (areArraysSame(count_txt, count_pat, 256))
            ans.push_back(i - m + 1);
    }

    return ans;
}