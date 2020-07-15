//sniippets

ll Div[10010000];
for (ll i = 1; i <= 1e7; i++)
{
    Div[i] = -1;
}
for (ll i = 2; i <= 1e7; i++)
{
    if (Div[i] != -1)
    {
        continue;
    }
    Div[i] = i;
    for (ll j = 2 * i; j <= 1e7; j += i)
    {
        if (Div[j] == -1)
            Div[j] = i;
    }
}
//
cin >> a;
vector<ll> v;
while (a != 1)
{
    v.push_back(Div[a]);
    a /= Div[a];
}
///
///
///
///
#define Fo(i,k,n) for(int i=k;k<n?i<=(int)n:i>=(int)n;k<n?i++:i--)
//
//
//


vector<int> primeFactors(int n)  
{  
    // Print the number of 2s that divide n  
    vector<int> v;
    while (n % 2 == 0)  
    {  
        v.push_back(2); 
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            v.push_back(i); 
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        v.push_back(n); 
        return v;  
}  