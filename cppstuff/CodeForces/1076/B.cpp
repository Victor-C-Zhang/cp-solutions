//
// Created by victor on 11/12/18.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
//#define s second
#define vi vector <int>
#define vvi vector < vector <int> >
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define zp mp(0, 0)

bool prime[100000];

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

//    // Print all prime numbers
//    for (int p=2; p<=n; p++)
//        if (prime[p])
//            cout << p << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n%2==0) {
        cout << n/2 << endl;
        return 0;
    }

    SieveOfEratosthenes(100000);
    bool sent = false;
    for (int i=3;i<100000;i++){
        if (prime[i]) {
            if (n%i == 0) {
                n-=i;
                sent = true;
                break;
            }
        }
    }
    if (sent) {
        cout << n/2 + 1 << endl;
    }
    else cout << 1 << endl;
}

