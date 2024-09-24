#include<bits/stdc++.h>
using namespace std;

pair<int,int> findInTable(char table[5][5], char x)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(table[i][j]==x)
            {
                pair<int,int>ans = make_pair(i,j);
                return ans;
            }
        }
    }
}

int main()
{
    string key = "monarchy";
    int i,j;
    /// Generating table
    char table[5][5];

    bool arr[26];
    memset(arr,false,sizeof(arr));
    int index = 0;
    for(i=0;i<key.length();i++)
    {
        if(arr[key[i]-'a']==false && key[i]!='j')
        {
            table[index/5][index%5] = key[i];
            arr[key[i]-'a'] = true;
            index++;
        }
    }
    for(i=0;i<26;i++)
    {
        if('a'+i=='j')  continue;
        if(arr[i]==false)
        {
            table[index/5][index%5] = 'a'+i;
            arr[i] = true;
            index++;
        }
    }
    cout<<"5x5 Square Table : \n";
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)    cout<<table[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;
    string originalText;
    cout<<"Enter PlainText : ";
    cin>>originalText;

    int len = originalText.length();

    /// Converting to lowercase(if in uppercase)
    for(i=0;i<len;i++)
    {
        if(originalText[i]>='A' && originalText[i]<='Z')
        {
            originalText[i] = originalText[i]-'A'+'a';
        }
    }


    if(len%2==1)
    {
        originalText += 'z';
        len++;
    }
    string EncryptedText="";
    for(i=0;i<len;i+=2)
    {
        char a1 = originalText[i];
        char a2 = originalText[i+1];

        if(a1=='j')         a1='i';
        else if(a2=='j')    a2 = 'i';

        pair<int,int>p1 = findInTable(table, a1);
        pair<int,int>p2 = findInTable(table, a2);

        if(p1.second==p2.second)
        {
            EncryptedText += table[(p1.first+1)%5][p1.second];
            EncryptedText += table[(p2.first+1)%5][p2.second];
        }
        else if(p1.first==p2.first)
        {
            EncryptedText += table[p1.first][(p1.second+1)%5];
            EncryptedText += table[p1.first][(p2.second+1)%5];
        }
        else
        {
            EncryptedText += table[p1.first][p2.second];
            EncryptedText += table[p2.first][p1.second];
        }
    }

    cout<<"The Encrypted String is : "<<EncryptedText<<endl;


    string DecryptedText = "";

    for(i=0;i<len;i+=2)
    {
        char a1 = EncryptedText[i];
        char a2 = EncryptedText[i+1];

        pair<int,int>p1 = findInTable(table,a1);
        pair<int,int>p2 = findInTable(table,a2);

        if(p1.second==p2.second)
        {
            DecryptedText += table[(p1.first-1 + 5)%5][p1.second];
            DecryptedText += table[(p2.first-1 + 5)%5][p2.second];
        }
        else if(p1.first==p2.first)
        {
            DecryptedText += table[p1.first][(p1.second-1+5)%5];
            DecryptedText += table[p2.first][(p2.second-1+5)%5];
        }
        else
        {
            DecryptedText += table[p1.first][p2.second];
            DecryptedText += table[p2.first][p1.second];
        }
    }

    cout<<"The Decrypted String is : "<<DecryptedText<<endl;

}
