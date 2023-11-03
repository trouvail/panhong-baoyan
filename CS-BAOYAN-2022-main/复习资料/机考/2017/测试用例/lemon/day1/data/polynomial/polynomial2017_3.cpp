//#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
typedef long long ll;
using namespace std;

ll n,m,a;
int mod = 1e9+7;


//����(a*b)%c
ll mul(ll a,ll b,ll mod) {
    ll res = 0;
    while(b > 0){
        if( (b&1) != 0)  // ���������λ��1 --> ���� a�� 2^i ��, �������ǳ���a��2^i ��
            res  = ( res + a) % mod;
        a = (a << 1) % mod;    // a = a * 2    a����b�ж�����λ�������� ÿ�� ����������
        b >>= 1;               // b -> b/2     ����  ȥ�����һλ ��Ϊ��ǰ���һλ���������ˣ�
    }
    return res;
}

//��ȡģ����
ll pow1(ll a,ll n,ll mod){
    ll res = 1;
    while(n > 0){
        if(n&1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        n >>= 1;
    }
    return res;
}


// ���� ret = (a^n)%mod
ll pow2(ll a,ll n,ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1)
            res = mul(res,a,mod);
        a = mul(a,a,mod);
        n >>= 1;
    }
    return res;
}

//�ݹ���η����
ll pow3(ll a,ll n,ll Mod){
    if(n == 0)
        return 1;
    ll halfRes = pow1(a,n/2,Mod);
    ll res = (ll)halfRes * halfRes % Mod;
    if(n&1)
        res = res * a % Mod;
    return res;
}

ll fun(ll b[],ll x)
{
    ll fx = 0;
    for(ll i = 0;i <= m;++i){
        fx +=  mul(b[i],pow3(x,i,mod),mod);
    }
    return fx;
}

ll Sum(ll a,ll n,ll b[])
{
    ll sum=0;
    for(ll i = 0;i <= n;++i){
        sum += mul(pow3(a,i,mod),fun(b,i),mod);
    }
    return sum%mod;
}

int main()
{
    //input:
    ll temp;
    //cin>>n>>m>>a;
    scanf("%lld %lld %lld",&n,&m,&a);
    ll b[m+1];
    for(ll i = 0;i <= m;++i){
        scanf("%lld",&b[i]);
    }
    printf("%lld",Sum(a,n,b));
    //cout<<Sum(a,n,b)<<endl;
    return 0;
}
