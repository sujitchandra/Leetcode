class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
        
        // Iterate through each string in the input vector
        for (const std::string& str : strs) {
            // Sort the current string
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            
            // Group the sorted string with its anagrams
            anagramGroups[sortedStr].push_back(str);
        }
        
        // Convert the hashmap values to a vector and return
        std::vector<std::vector<std::string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};