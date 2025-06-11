//#include<bits/stdc++.h>
//using namespace std;
//int n,k,ans=0;
//void recur(int x,int y,int fp,int sp)
//{
//    if (x==n && y==k){
//        if (fp!=1 || sp!=1) ans+=1;
//        return;
//    }
//    if (x>n || y>k) return;
//    if (fp==1 && sp==1) recur(x+1,y,0,fp);
//    else{
//        recur(x+1,y+1,1,fp);
//        recur(x+1,y,0,fp);
//    }
//}
//int main()
//{
//    cin>>n>>k;
//    recur(1,1,1,1);
//    recur(1,0,0,1);
//    cout<<ans;
//}  PROB G
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//void recur (int disk,char from,char aux,char to)
//{
//    if (disk==0) return;
//    recur(disk-1,from,to,aux);
//    cout<<"move disk "<<disk<<" "<<from<<"->"<<to<<"\n";
//    recur(disk-1,aux,from,to);
//}
//int main()
//{
//    cin>>n;
//    cout<<int(pow(2,n)-1)<<"\n";
//    recur(n,'A','B','C');
//}  PROB I
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//void recur (int disk,char from,char aux,char to)
//{
//    if (disk==0) return;
//    recur(disk-1,from,aux,to);
//    cout<<disk<<" : "<<from<<"->"<<aux<<"\n";
//    recur(disk-1,to,aux,from);
//    cout<<disk<<" : "<<aux<<"->"<<to<<"\n";
//    recur(disk-1,from,aux,to);
//}
//int main()
//{
//    cin>>n;
//    recur(n,'A','B','C');
//    cout<<int(pow(3,n)-1);
//}  PROB J
//#include<bits/stdc++.h>
//using namespace std;
//void parenthesischecker(string s)
//{
//    stack<char> st;
//    bool flag=true;
//    for (auto i:s){
//        if (i=='(') st.push(i);
//        else{
//            if (st.empty() || st.top()!='('){
//                flag=false;
//                break;
//            }
//            st.pop();
//        }
//    }
//    if (flag && st.empty()) cout<<"YES";
//    else cout<<"NO";
//}
//int main()
//{
//    string s;
//    cin>>s;
//    parenthesischecker(s);
//}  PROB N
//#include<bits/stdc++.h>
//using namespace std;
//int cnv(char c)
//{
//    if (c=='+' || c=='-') return 1;
//    else return 2;
//}
//int main()
//{
//    string s;
//    string ans="";
//    stack<int> st;
//    cin>>s;
//    for (auto i:s){
//        if (isalpha(i)) ans+=i;
//        else{
//            while(!st.empty() && cnv(st.top())>=cnv(i)){
//                ans+=st.top();
//                st.pop();
//            }
//            st.push(i);
//        }
//    }
//    while(!st.empty()){
//        ans+=st.top();
//        st.pop();
//    }
//    cout<<ans;
//} // PROB O
//#include<bits/stdc++.h>
//using namespace std;
//int n,mod=2052506102,ans=0;
//void recur(int top,int bottom)
//{
//    if (top==n && bottom==n){
//        ans=(ans+1)%mod;
//        return;
//    }
//    else if (top>n || bottom>n){
//        return;
//    }
//    if (top>bottom){
//        for (int i=1;i<=3;i++){
//            recur(top,bottom+i);
//        }
//    }
//    else if (top<bottom){
//        for (int i=1;i<=3;i++){
//            recur(top+i,bottom);
//        }
//    }
//    else{
//        for (int i=1;i<=3;i++){
//            recur(top+i,bottom);
//        }
//        recur(top+1,bottom+1);
//    }
//}
//int main()
//{
//    cin>>n;
//    recur(0,0);
//    cout<<ans;
//} // PROB P
//#include<bits/stdc++.h>
//using namespace std;
//int n,a,b,k,brd[30];
//int f(int idx,int x,int y)
//{
//    if (idx==k){
//        return 0;
//    }
//    int piv=brd[idx];
//    return min((f(idx+1,piv,y)+abs(piv-x)),(f(idx+1,x,piv)+abs(piv-y)));
//}
//int main()
//{
//    cin>>n;
//    cin>>a>>b;
//    cin>>k;
//    for (int i=0;i<k;i++){
//        cin>>brd[i];
//    }
//    cout<<f(0,a,b);
//} PROB Q
//#include <bits/stdc++.h>
//using namespace std;
//int n,k,dp[40][40];
//int f(int x,int y)
//{
//    if (y*2==x) return 2;
//    if (y*2>x) return 0;
//    if (y==1) return x;
//    if (dp[x][y]!=0) return dp[x][y];
//    int ret=f(x-2,y-1)+f(x-1,y);
//    return dp[x][y]=ret;
//}
//int main()
//{
//    cin>>n;
//    cin>>k;
//    cout<<f(n,k);
//} PROB R
//#include<bits/stdc++.h>
//using namespace std;
//int n,w,ans=INT_MAX;
//vector<pair<int,int>> acc;
//int dist(int x1,int y1,int x2,int y2)
//{
//    return abs(x1-x2)+abs(y1-y2);
//}
//void recur(int idx,int x1,int y1,int x2,int y2,int cur)
//{
//    if (idx==w){
//        ans=min(ans,cur);
//        return;
//    }
//    int nxtx=acc[idx].first;
//    int nxty=acc[idx].second;
//    recur(idx+1,nxtx,nxty,x2,y2,cur+dist(x1,y1,nxtx,nxty));
//    recur(idx+1,x1,y1,nxtx,nxty,cur+dist(x2,y2,nxtx,nxty));
//}
//int main()
//{
//    cin>>n;
//    cin>>w;
//    for (int i=0;i<w;i++){
//        int x,y;
//        cin>>x>>y;
//        acc.push_back({x,y});
//    }
//    recur(0,1,1,n,n,0);
//    cout<<ans;
//} PROB S
//#include<bits/stdc++.h>
//#define ll long long int
//using namespace std;
//ll sum=0,dp[1001000],mod=100007;
//int main()
//{
//    int n;
//    cin>>n;
//    dp[1]=2;dp[2]=7,sum=9;
//    for (int i=3;i<=n;i++){
//        dp[i]=(2*sum+dp[i-2]+2)%mod;
//        sum=(sum+dp[i])%mod;
//    }
//    cout<<dp[n];
//}  PROB U
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int dp[101][101]={};
//    string s1,s2;
//    cin>>s1;
//    cin>>s2;
//    int l1=s1.length(),l2=s2.length();
//    for (int i=1;i<=l1;i++){
//        for (int j=1;j<=l2;j++){
//            if (s1[i-1]==s2[j-1]){
//                dp[i][j]=dp[i-1][j-1]+1;
//            }
//            else{
//                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//            }
//        }
//    }
//    cout<<dp[l1][l2];
//} PROB W
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    string s;
//    cin>>s;
//    stack<int> st;
//    bool balance=true;
//    for (auto i:s){
//        if (i=='(' || i=='[' || i=='{') st.push(i);
//        else if (i==')'){
//            if (st.empty() || st.top()!='('){
//                balance=false;
//                break;
//            }
//            else{
//                st.pop();
//            }
//        }
//        else if (i==']'){
//            if (st.empty() || st.top()!='['){
//                balance=false;
//                break;
//            }
//            else{
//                st.pop();
//            }
//        }
//        else if (i=='}'){
//            if (st.empty() || st.top()!='{'){
//                balance=false;
//                break;
//            }
//            else{
//                st.pop();
//            }
//        }
//    }
//    if (balance==true && st.empty()){
//        cout<<"O";
//    }
//    else{
//        cout<<"X";
//    }
//} PROB X
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int n,cur=1;
//    bool flag=true;
//    stack<int> st;
//    vector<char> stackseq;
//    cin>>n;
//    while(n--){
//        int x;
//        cin>>x;
//        while(cur<=x){
//            st.push(cur);
//            stackseq.push_back('+');
//            cur+=1;
//        }
//        if (!st.empty() && st.top()==x){
//            st.pop();
//            stackseq.push_back('-');
//        }
//        else flag=false;
//    }
//    if (flag){
//        for (auto i:stackseq){
//            cout<<i<<"\n";
//        }
//    }
//    else{
//        cout<<"NO";
//    }
//} PROB Y
//#include<bits/stdc++.h>
//using namespace std;
//int cnv(char c)
//{
//    if (c=='*' || c=='/') return 2;
//    else if (c=='+' || c=='-') return 1;
//    else return 0;
//}
//int main()
//{
//    string s,ans="";
//    stack<int> st;
//    cin>>s;
//    for (auto i:s){
//        if (isalpha(i)) ans+=i;
//        else{
//            if (i==')'){
//                while(st.top()!='('){
//                    ans+=st.top();
//                    st.pop();
//                }
//                st.pop();
//            }
//            else if (i=='(') st.push(i);
//            else{
//                while(!st.empty() && cnv(st.top())>=cnv(i)){
//                    ans+=st.top();
//                    st.pop();
//                }
//                st.push(i);
//            }
//        }
//    }
//    while(!st.empty()){
//        ans+=st.top();
//        st.pop();
//    }
//    cout<<ans;
//} PROB Z
//#include<bits/stdc++.h>
//using namespace std;
//char convert(char c)
//{
//    if (c=='a') return 'b';
//    else if (c=='b') return 'c';
//    else return 'a';
//}
//int main()
//{
//    string s;
//    cin>>s;
//    stack<char> st;
//    stack<char> anst;
//    st.push(s[0]);
//    for (int i=1; i<s.size(); i++){
//        while(!st.empty() && st.top()==s[i]){
//            s[i]=convert(s[i]);
//            st.pop();
//        }
//        st.push(s[i]);
//    }
//    while(!st.empty()){
//        anst.push(st.top());
//        st.pop();
//    }
//    while(!anst.empty()){
//        cout<<anst.top();
//        anst.pop();
//    }
//}  PROB AA
//#include <bits/stdc++.h>
//using namespace std;
//int h[80001],seen[80001];
//int main()
//{
//    int n,maxval=0,idx=0;
//    cin>>n;
//    for (int i=0;i<n;i++) cin>>h[i];
//    stack<int> st;
//    for (int i=0;i<n;i++){
//        while(!st.empty() && h[st.top()]<=h[i]){
//            st.pop();
//        }
//        seen[i]=st.size();
//        if (seen[i]>maxval){
//            maxval=seen[i];
//            idx=i;
//        }
//        st.push(i);
//    }
//    cout<<idx+1<<" "<<maxval;
//} PROB AB
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int dp[21][10001],weight[21],value[21],n,w;
//    cin>>n>>w;
//    for (int i=1;i<=n;i++){
//        cin>>weight[i]>>value[i];
//    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=w;j++){
//            if (j>=weight[i]){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
//            }
//            else{
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//    }
//    cout<<dp[n][w];
//} PROB AC
//#include<bits/stdc++.h>
//using namespace std;
//int p,f,pump[21],fire[21],dp[21][21];
//int solve(int i,int j)
//{
//   if (j==f) return 0;
//   if (i==p) return 1e9;
//   if (dp[i][j]!=0) return dp[i][j];
//   return dp[i][j]=min(abs(pump[i]-fire[j])+solve(i+1,j+1),solve(i+1,j));
//}
//int main()
//{
//    cin>>p>>f;
//    for (int i=0;i<p;i++) cin>>pump[i];
//    for (int i=0;i<f;i++) cin>>fire[i];
//    cout<<solve(0,0)<<"\n";
//} PROB AD
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int dp[101][10001],weight[101],value[101],n,m,total=0;
//    cin>>n>>m;
//    for (int i=1;i<=n;i++){
//        cin>>value[i];
//    }
//    for (int i=1;i<=n;i++){
//        cin>>weight[i];
//        total+=weight[i];
//    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=w;j++){
//            if (j>=weight[i]){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
//            }
//            else{
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//    }
//    for (int i=0;i<=total;i++){
//        if (dp[n][i]>=m){{
//            cout<<i;
//            break;
//        }
//    }
//} PROB AF
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//    int n;
//    string s;
//    cin>>n>>s;
//    stack<int> st;
//    int target=1;
//    string res="";
//    for (char ch:s) {
//        st.push(ch-'0');
//        res+="push\n";
//        while (!st.empty() && st.top()==target) {
//            st.pop();
//            res+="pop\n";
//            target++;
//        }
//    }
//    if (target==n+1) {
//        cout<<res;
//    }
//    else {
//        cout<<"-1\n";
//    }
//    return 0;
//} PROB AG
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//    stack<char> st;
//    string s;
//    cin>>s;
//    int ans=0,tmp=1;
//    for (int i=0;i<s.size();i++){
//        if (s[i]=='('){
//            tmp*=2;
//            st.push(s[i]);
//        }
//        else if (s[i]=='['){
//            tmp*=3;
//            st.push(s[i]);
//        }
//        else if (s[i]==')'){
//            if (st.empty() || st.top()!='('){
//                ans=0;
//                break;
//            }
//            if (s[i-1]=='(') ans+=tmp;
//            tmp/=2;
//            st.pop();
//        }
//        else if (s[i]==']'){
//            if (st.empty() || st.top()!='['){
//                ans=0;
//                break;
//            }
//            if (s[i-1]=='[') ans+=tmp;
//            tmp/=3;
//            st.pop();
//        }
//    }
//    if (!st.empty()) ans=0;
//    cout<<ans;
//} PROB AH
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    int ans=0,tmp=1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='('){
            tmp*=2;
            st.push(s[i]);
        }
        else if (s[i]=='['){
            tmp*=3;
            st.push(s[i]);
        }
        else if (s[i]==')'){
            if (st.empty() || st.top()!='('){
                ans=0;
                break;
            }
            if (s[i-1]=='(') ans+=tmp;
            tmp/=2;
            st.pop();
        }else if (s[i]==']'){
            if (st.empty() || st.top()!='['){
                ans=0;
                break;
            }
            if (s[i-1]=='[') ans+=tmp;
            tmp/=3;
            st.pop();
        }
    }
    if (!st.empty()) ans=0;
    cout<<ans;
}
