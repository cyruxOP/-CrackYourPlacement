class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> v ={{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5}, {"IV",4},{"I",1}};
    string res="";
    for(int i=0;i<v.size();i++)
    {
        int ans=0;
        ans = num / v[i].second;
        num = num%v[i].second;
        for(int j=0;j<ans;j++){
            res+=v[i].first;
        }
        if(!num)
            break;
    }
        return res;
    }
};