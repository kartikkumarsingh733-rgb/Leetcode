class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }
        
        string left_half = "";
        char middle_char = 0; // 0 acts as a null checker
        
        // Build the left half in strictly increasing alphabetical order
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0){
                middle_char = i + 'a'; // Save the odd character for the center
            }
            
            // Append half of the occurrences
            left_half += string(freq[i] / 2, i + 'a'); 
        }
        
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        // Assemble the pieces
        if(middle_char != 0){
            return left_half + middle_char + right_half;
        }
        
        return left_half + right_half;
    }
};