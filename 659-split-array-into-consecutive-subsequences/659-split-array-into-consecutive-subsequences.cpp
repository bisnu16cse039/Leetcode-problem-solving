class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        vector<vector<int> > res(10000,vector<int>());
        
        int in=0;
        for(int x: nums){
            if(res.size()==0){
                res[in].push_back(x);
                ++in;
            }
            else{
                int mi_in=-1;
                for(int i=in-1;i>=0;--i){
                    if(res[i].back()+1 == x){
                        if(mi_in==-1)mi_in=i;
                        else if(res[mi_in].size() > res[i].size()){
                            mi_in=i;
                        }
                    }
                    else if(res[i].back() < x)break;
                }
                if(mi_in == -1){
                    res[in].push_back(x);
                    ++in;
                }
                else{
                    res[mi_in].push_back(x);
                }
                
            }
        }
        for(int i=0;i<in;++i){
            if(res[i].size() < 3)return false;
        }
        return true;
    }
};