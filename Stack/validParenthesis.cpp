#include <iostream>
#include <string>

using namespace std;

bool isValid(string str);
//Main Point to NOTE:- When you're finding a corresponding closing bracket, then all the coming brackets (while traversing)
//should be closed inside the target Opening and Closing bracket pair. 
int main()
{
    //    const char ch=')';
    //    cout<<"Corresponding opening brace of "<<ch<<" is= "<<findOpenBrace(ch)<<endl;
    string str = "[({(())}[()])]";
    cout << "Is string " << str << " Valid?? " << isValid(str) << endl;
    return 0;
}
char findCloseBrace(char openBrace)
{
    switch (openBrace)
    {
    case '[':
        return ']';

    case '{':
        return '}';

    case '(':
        return ')';

    default:
        return '0';
    }
}
bool correctOrder(string str,int s,int e){
    if(e==s)//only 1 bracket lie between s and e
        return false;
    while(s<=e){
        if(str[s]=='0' || str[e]=='0')
            return false;
        s++;e--;
    }
    return true;
}
int findBrace(string &str, char ch, int idx)
{
    int n = str.length();
    for (int i =n-1 ; i>idx; i--)
    {
        if (str[i] == ch)
        {
            str[i] = '0';
           if(correctOrder(str,idx+1,i-1))
            return i;
            else 
                return -1;
        }
    }
    return -1;
}
bool isValid(string str)
{
    int n = str.length();
    for (int i = 0; i < n;)
    {
        char openingBrace = str[i];
        char closingBrace;
        if (openingBrace == '0')//opening and closing pair is visited
            i++;
        else
        {
           closingBrace=findCloseBrace(openingBrace);
            if (closingBrace == '0') // opening brace was the closeBrace
                return false;
            int idx = findBrace(str, closingBrace, i);
            if (idx == -1) // no such closing brace in the remaining part of string
                return false;
            if (i+1==idx)
                i = i + 2;
            else
                i++;
        }
    }
    return true;
}