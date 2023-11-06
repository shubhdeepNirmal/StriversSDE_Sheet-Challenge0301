class AuthenticationManager {
    int ttl=0;
   unordered_map<string,int>mp;

public:
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
       
        mp[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {

        auto it=mp.find(tokenId);
        if(it==mp.end()) return;
        else{
            if(mp[tokenId]>currentTime) mp[tokenId]=currentTime+ttl;
        }
        return;
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto it:mp)
        {
            if(it.second>currentTime) count++;
        }
        return count;

    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */