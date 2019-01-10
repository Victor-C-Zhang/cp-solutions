//
// Created by victor on 1/9/19.
//

//probably the bashiest, most disgusting code I've written thus far
//it's also wrong :(

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define double long double
#define mod 998244353
#define p push
#define pb push_back
#define f first
#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int> , int >
#define pppi pair<ppi,int>




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    int nums[3];
    fill (nums,nums+3,0);
    for (int i=0;i<s.size();i++){
        nums[s[i]-'0']++;
    }
    for (int i=0;i<3;i++){
        nums[i]-=n/3;
    }
    if (nums[2]<0) {
        if (nums[1]<0){
            int ptr = n-1;
            while (nums[2]<0){
                if (s[ptr]=='0'){
                    nums[0]--;
                    nums[2]++;
                    s[ptr]='2';
                }
                ptr--;
            }
            while (nums[1]<0){
                if (s[ptr]=='0'){
                    nums[0]--;
                    nums[1]++;
                    s[ptr]='1';
                }
                ptr--;
            }
        }
        else { //1>=, 2<
            if (nums[0]>0){
                int ptr = n-1;
                while (nums[2]<0){
                    if (nums[s[ptr]-'0']>0){
                        nums[s[ptr]-'0']--;
                        nums[2]++;
                        s[ptr]='2';
                    }
                    ptr--;
                }
            }
            else { //1>= only
                int ptr = n-1;
                while (nums[2]<0){
                    if (s[ptr]=='1'){
                        nums[1]--;
                        nums[2]++;
                        s[ptr]='2';
                    }
                    ptr--;
                }
                ptr = 0;
                while (nums[0]<0){
                    if (s[ptr]=='1'){
                        nums[1]--;
                        nums[0]++;
                        s[ptr]='0';
                    }
                    ptr++;
                }
            }
        }
    }
    else { //nums2 >=0
        if (nums[1]>0){
            int ptr = 0;
            while (nums[0]<0){
                if (nums[s[ptr]-'0']>0){
                    nums[s[ptr]-'0']--;
                    nums[0]++;
                    s[ptr]='0';
                }
                ptr++;
            }
        }
        else { // nums1<, nums2>
            if (nums[0]>0){
                int ptr = 0;
                while (nums[1]<0 && ptr<n){
                    if (s[ptr] == '2'){
                        nums[2]--;
                        nums[1]++;
                        s[ptr]='1';
                    }
                    ptr++;
                }
                while (nums[1]<0 && ptr>-1){
                    if (s[ptr] == '0'){
                        nums[0]--;
                        nums[1]++;
                        s[ptr]='1';
                    }
                    ptr++;
                }
            }
            else { //2> only
                int ptr = 0;
                while (nums[0]<0 && ptr<n){
                    if (s[ptr] == '2'){
                        nums[2]--;
                        nums[0]++;
                        s[ptr]='0';
                    }
                    ptr++;
                }
                ptr = 0;
                while (nums[1]<0 && ptr<n){
                    if (s[ptr] == '2'){
                        nums[2]--;
                        nums[1]++;
                        s[ptr]='1';
                    }
                    ptr++;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << s[i];
    }
    cout << endl;
}