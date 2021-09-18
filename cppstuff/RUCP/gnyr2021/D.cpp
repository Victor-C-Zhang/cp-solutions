#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define vi vector <int>
#define vvi vector < vector <int> >
//#define pi pair <int, int>
//#define ppi pair < pair <int, int>, int>
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > >
#define zp mp(0, 0)

//std::random_device dev;
//std::mt19937 rng(dev());
//std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]


// trie node
struct TrieNode
{
  struct TrieNode *children[2];

  // isEndOfWord is true if the node represents
  // end of a word
  int isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode() {
  auto *pNode =  new TrieNode;
  pNode->isEndOfWord = -1;

  for (int i = 0; i < 2; i++)
    pNode->children[i] = nullptr;

  return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key, int label)
{
  struct TrieNode *pCrawl = root;

  for (int i = 0; i < key.size(); ++i) {
    unsigned index = key[i]-'0';
    if (!pCrawl->children[index])
      pCrawl->children[index] = getNode();

    pCrawl = pCrawl->children[index];
  }

  // mark last node as leaf
  pCrawl->isEndOfWord = label;
}

// Returns the index of the longest match, -1 if there is none
// key should be provided in reverse
int search(struct TrieNode *root, string key) {
  struct TrieNode *pCrawl = root;
  int idx = -1;
  for (int i = 0; i <= key.size(); ++i) {
    if (pCrawl->isEndOfWord != -1) idx = pCrawl->isEndOfWord;
    unsigned index = key[i] - '0';
    if (!pCrawl->children[index])
      return idx;
    pCrawl = pCrawl->children[index];
  }
  return idx;
}

string toString(uint32_t mask, int bits) {
  string ret(bits,'0');
  for (int i=0;i<bits;++i) {
    if (mask&(1<<(31-i))) ret[i] = '1';
  }
  return ret;
}

void freeNode(struct TrieNode* root) {
  if (root->children[0] != nullptr) freeNode(root->children[0]);
  if (root->children[1] != nullptr) freeNode(root->children[1]);
  delete(root);
}

signed main() {
  ios_base::sync_with_stdio(false);
  fstream in{"d.in"};
  in.tie(nullptr);
  cout.tie(nullptr);

  struct TrieNode* root = getNode();
  int x,y; in >> x >> y;
  uint32_t mask;
  int len;
  for (int i = 0; i < x; ++i) {
    in >> hex >> mask >> dec >> len;
    insert(root,toString(mask,len),i);
  }
  while (y--) {
    in >> hex >> mask;
    cout << search(root,toString(mask,32)) << endl;
  }
  freeNode(root);
  return 0;
}

/* List of CP snippets:
 *
 * cp-header (standard header)
 */