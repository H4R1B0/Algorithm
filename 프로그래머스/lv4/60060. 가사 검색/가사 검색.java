import java.util.*;

class Solution {
    int K = -1;
    int count = -1;
    public int[] solution(String[] words, String[] queries) {
        Trie front = new Trie();
        Trie back = new Trie();
        
        for(String word : words){
            front.insert(word);
            back.insert(reverse(word));
        }
        
        int[] answer = new int[queries.length];
        for(int i=0;i<answer.length;i++){
            String query = queries[i];
            if(query.charAt(0) != '?')
                answer[i] = front.find(query,0);
            else
                answer[i] = back.find(reverse(query),0);
        }
        return answer;
    }
    
    class Trie{
        Trie[] children = new Trie[26];
        Map<Integer, Integer> lenMap = new HashMap<>(); //idx, cnt
        
        void insert(String word){
            Trie head = this;
            int len = word.length();
            lenMap.put(len, lenMap.getOrDefault(len, 0)+1);
            
            for(char c : word.toCharArray()){
                int idx = c-'a';
                if(head.children[idx] == null){
                    head.children[idx] = new Trie();
                }
                
                head = head.children[idx];
                head.lenMap.put(len, head.lenMap.getOrDefault(len, 0)+1);
            }
        }
        
        int find(String word, int i){
            if(word.charAt(i) == '?')
                return lenMap.getOrDefault(word.length(), 0);
            int idx = word.charAt(i)-'a';
            return children[idx] == null ? 0 : children[idx].find(word, i+1);
        }
    }
    
    String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }
}