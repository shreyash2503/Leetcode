class UnionFind {
    public:
    vector<int> par;
    vector<int> size;
    int count;
    UnionFind(int n){
        this->par = vector<int>(n + 1);
        for(int i{};i<n;i++){
            par[i] = i;
        }
        this->size = vector<int>(n + 1, 0);
    }

    int find(int x){
        if(par[x] != x){
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool _union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py){
            return false;
        }
        if(size[px] < size[py]){
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] = size[py];
        }
        count -= 1;
        return true;
    }


};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        size_t size = edges.size();
        UnionFind u(size);

        for(auto& v: edges){
            int first = v[0];
            int second = v[1];
            bool ans = u._union(first, second);
            if(!ans){
                return v;
            }
        }
        return {};

        
        
    }
};
