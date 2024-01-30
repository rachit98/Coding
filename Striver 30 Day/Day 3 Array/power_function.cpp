class Solution {
public:
    double myPow(double x, int n) {
        if (n==0 or x==1.0)
            return 1;
        if(x==0.0)
            return 0;
        if(n==1)
            return x;
        if(n==-1)
            return 1/x;
        vector<double> powers;
        long range = abs(n);
        //cout<<range<<" Range" << endl;
        if(n<0)
            powers.push_back(1/x);
        else
            powers.push_back(x);

        for(long i=1;i<range;i*=2)
        {   
            double dummy = powers.back();
            //cout<<"prev "<<dummy<<endl;
            powers.push_back(dummy*dummy);

            //cout<< i<<"  "<< powers.back()<<endl;

            if(powers.back() == 0)
                return 0;
        }
        //cout<<"Last "<<powers.back()<<endl;
        vector<int> bits;
        int temp = abs(n);
        while(temp)
        {
            bits.push_back(temp%2);
            temp/=2;
        }
        double ans = 1;
        for(int i=0;i<bits.size();i++)
        {
            //cout<<bits[i]<<" bits[i]  "<<powers[i]<<" powers[i]"<<endl;
            if(bits[i]==1)
            {
                 
                ans*=powers[i];
            }
        }
        
        return ans;
    }
};