class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // 1. make a graph from this with nodes as all chars
        // 2. apply topo sort-kahns algo so that we will get order of alphabets

        //adj list - as nodes are chars ... will use map

        unordered_map<char, unordered_set<char>> adj; // unordered_set<char> this is neigh of char(key of map) .. set due to it will handle duplicates as we may get say a->b in two diff words
        unordered_map<char,int> indegree;
        for(auto& word:words){
            for(auto &c:word){
                indegree[c]=0; // indegree of every char init to 0
            }
        } 

        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];

            if(w1.size()>w2.size() && w1.substr(0,w2.size())==w2) return ""; // invalid dict .. abc then ab aya toh invalid dict hai 

            int minlen = min(w1.size(),w2.size()); // for first mismatched char
            for(int j=0;j<minlen;j++){
                if(w1[j]!=w2[j]){
                    char u = w1[j];
                    char v = w2[j]; // ek edge mili from u->v 

                    if(adj[u].find(v)== adj[u].end()){
                        adj[u].insert(v); // agar u ke adj list mein v nhi hai toh insert kr as u->v edge mili hai
                        indegree[v]++; // v ki indegree badha
                    }
                    break; // us word ka kam khatam
                }
            }

        }// graph bn chuka ab normal kahn laga

        queue<char> q;

        for(auto &p:indegree){// indgree 0 wale char q mein push kr;
            if(indegree[p.first]==0) q.push(p.first);
        }

        string ans="";

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            ans+=curr; // q ka front ans mein dal diya ab iske neigh ki indegree km kr , 0 hui toh q mein push kr

            for(auto&neigh:adj[curr]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }


        }

        if(ans.size()<indegree.size()) return ""; // cycle check in kahn

        return ans;
    }
};
