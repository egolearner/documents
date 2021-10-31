/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (41.21%)
 * Likes:    3299
 * Dislikes: 139
 * Total Accepted:    306.5K
 * Total Submissions: 734.9K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 *
 *
 *
 * Example:
 *
 *
 * Input
 *
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 *
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 500
 * word in addWord consists lower-case English letters.
 * word in search consist of  '.' or lower-case English letters.
 * At most 50000 calls will be made to addWord and search.
 *
 *
 */

// @lc code=start
class WordDictionary {
    struct Node;
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
        Node* n = root;
        for (auto c : word) {
            int index = c-'a';
            if (!n->children[index]) {
                n->children[index] = new Node;
            }
            n = n->children[index];
        }
        n->end = true;
    }

    bool search(string word) {
        return search_impl(root, word.c_str());
    }
private:
    bool search_impl(Node* n, const char* cur) {
        if (!n) {
            return false;
        }
        if (!*cur) {
            return n->end;
        }
        if (*cur == '.') {
            for (auto c : n->children) {
                if (search_impl(c, cur+1)) {
                    return true;
                }
            }
            return false;
        }
        return search_impl(n->children[*cur-'a'], cur+1);
    }

    struct Node {
        bool end{false};
        Node *children[26]{0};
        ~Node() {
            for (auto c : children) {
                delete c;
            }
        }
    };
    Node* root{new Node};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

/*
XXX 另一种解法
class WordDictionary {
public:
    WordDictionary() {}

    void addWord(string word) {
        words[word.size()].push_back(word);
    }

    bool search(string word) {
        for(auto s: words[word.size()]) if(isEqual(s, word)) return true;
        return false;
    }

private:
    unordered_map<int, vector<string>>words;

    bool isEqual(string a, string b){
        for(int i = 0; i < a.size(); i++){
            if(b[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};
*/
