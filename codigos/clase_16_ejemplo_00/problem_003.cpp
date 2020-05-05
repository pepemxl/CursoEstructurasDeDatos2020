#include <iostream>
#include <string>
#include <stdio.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int N = 128;
        int hash[N] = {0};
        int n = s.length();
        int car;
        int max_len = 0;
        int current_len = 0;
        int max_possible = 0;
        for(int k = 0; k < N;k++){
            hash[k] = 0;
        }
        for(int i = 0;i < n;++i){
            car = int(s[i]);
            hash[car] = 1;
        }
        for(int k = 0; k < N;k++){
            if(hash[k]){
                max_possible++;
            }
        }
        if(max_possible <= 1){
            return max_possible;
        }        
        for(int i = 0;i < n-1;++i){
            current_len = 0;
            if(max_len > n-i && n > 2*N){
                break;
            }
            for(int k = 0; k < N;k++){
                hash[k] = 0;
            }
            car = int(s[i]);
            hash[car] = 1;
            current_len++;
            for(int j = i+1;j < n;++j){
                car = int(s[j]);
                if(hash[car] == 0){
                    hash[car] = 1;    
                    current_len++;
                }else{
                    if(max_len < current_len){
                        max_len = current_len;
                        if(max_len == max_possible){
                            return max_len;
                        }
                    }
                    break;
                }
                if(max_len < current_len){
                    max_len = current_len;
                }
            }
            
        }
        return max_len;
    }
};


int main(){
    Solution sol;
    //printf("%d",' ');
    std::cout << sol.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << sol.lengthOfLongestSubstring(" ") << std::endl;
    std::cout << sol.lengthOfLongestSubstring("  ") << std::endl;
    std::cout << sol.lengthOfLongestSubstring("au") << std::endl;
    return 0;
}