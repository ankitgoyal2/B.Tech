#include<bits/stdc++.h>
using namespace std;

string solve(vector<string> v)
{
    int n=v.size();
    string ans;
    if(n==0)
        return ans;

    int indegree[26],outdegree[26];
    for(int i=0;i<26;i++)             //initialize arrays
    {
        indegree[i]=-1;
        outdegree[i]=-1;
    }

    for(int i=0;i<n;i++)            //storing in,out degrees
    {
        indegree[v[i][0]-65] = i;
        outdegree[v[i][2]-65] = i;
    }

    int startindex=0,index;
    while(startindex<26)          // search startindex
    {
        if(indegree[startindex]>-1 && outdegree[startindex]==-1 )
            break;
        startindex++;
    }

    index = startindex;
    while(indegree[index]!=-1)     //adding characters to string
    {
        ans = ans + v[indegree[index]][0];
        index = v[indegree[index]][2]-65;
    }
    ans += v[outdegree[index]][2];

    return ans;
}


int main()
{
    int n;  // number of strings in the array
    cin>>n;
    vector<string> v;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;            // input strings
        v.push_back(s);
    }

    string ans = solve(v);
    cout<<ans<<"\n";        // printing result
}
