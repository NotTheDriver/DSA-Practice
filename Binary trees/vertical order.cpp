public:
    vector<int> verticalOrder(Node* root) {
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int horizontalDist=temp.second.first;
            int level=temp.second.second;
            nodes[horizontalDist][level].push_back(frontNode->data);
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(horizontalDist-1,level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(horizontalDist+1,level+1)));
            }
        }
        //traversing the map nodes
        for(auto i:nodes){
            //traversing the int and vector map inside the map nodes
            for(auto j: i.second){
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
