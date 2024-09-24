#include <bits/stdc++.h>
using namespace std;

string lowercase(string s)
{
    for(int i =0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i] = s[i]-'A'+'a';
        }
    }
    return s;
}

int main()
{
    string key = "GYBNQKURP";
    key = lowercase(key);

    int table[3][3],i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            table[i][j] = key[i*3+j]-'a';

    cout<<"Encryption Table : \n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<table[i][j]<<" ";
        cout<<"\n";
    }
    cout<<endl;
    cout<<"Decryption Table : \n";
    /// Decryption
    int DecryptTable[3][3];
    for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
        {
            DecryptTable[i][j] = (-1*((table[(j+1)%3][(i+1)%3]*table[(j+2)%3][(i+2)%3]) - (table[(j+1)%3][(i+2)%3] * table[(j+2)%3][(i+1)%3]))%26+26)%26;
            cout<<DecryptTable[i][j]<<" ";
        }
        cout<<"\n";
	}
	cout<<endl;
    string OriginalString;
    cout<<"Enter string of length 3 : ";
    cin>>OriginalString;
    OriginalString = lowercase(OriginalString);

    int OriginalArray[3];
    for(i=0;i<3;i++)
    {
        OriginalArray[i] = OriginalString[i] - 'a';
    }

    int EncryptedArray[3];
    string EncryptedText = "";
    for(i=0;i<3;i++)
    {
        EncryptedArray[i] = (OriginalArray[0]*table[i][0] + OriginalArray[1]*table[i][1] + OriginalArray[2]*table[i][2])%26;
        EncryptedText += 'a'+EncryptedArray[i];
    }
    cout<<"Encryped Text : "<<EncryptedText;
    cout<<endl;

	string DecryptedString = "";
	for(i=0;i<3;i++)
    {
        DecryptedString += 'a' + (EncryptedArray[0]*DecryptTable[i][0] + EncryptedArray[1]*DecryptTable[i][1] + EncryptedArray[2]*DecryptTable[i][2])%26;
    }

    cout<<"Decrypted String : "<<DecryptedString;
    cout<<endl;

}

