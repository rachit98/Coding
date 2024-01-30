vector<int> Solution::repeatedNumber(const vector<int> &A) {
vector<int> ans;
long n=A.size();

long sum=(n*(n+1))/2;
long square=(n*(n+1)*((2*n)+1))/6;

long  asum=0;
long  asquare=0;

for(int i:A){
    asum += i;
    asquare += ((long)i)*i;
}
long  s1=asum-sum;
long  s2=asquare-square;

long diff=s1;
long summ=s2/s1;

long repeated=(summ+diff)/2;
long missing=(summ-diff)/2;
 ans.push_back((int)repeated);
 ans.push_back((int)missing);
 
 return ans;

}