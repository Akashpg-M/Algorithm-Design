// algo:
//
// 1. make the frequency table
// 2. push freq and characters as nodes into a priority queue
// 3. retrieve 2 least freq nodes, create a parent node combining them
// 4. push new parent node back into the queue
// 5. repeat until only one node remains (root of Huffman tree)
// 6. recursively assign binary codes from root to leaves


#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

struct Node{
  char ch;
  int freq;
  Node *left, *right;

  Node(char c, int f){
    ch = c;
    freq = f;
    left = right = nullptr;
  }
};

unordered_map<char, string> huffmanCode(string seq);
void generateCode(Node* root, string code, unordered_map<char, string>& map);

struct Compare{
  bool operator()(Node* first, Node* second){
    return first->freq > second->freq;
  }
};


int main(){
  string seq;
  cout<<"Enter code: ";
  getline(cin, seq); 

  unordered_map<char, string> encode = huffmanCode(seq);
  string encodedSeq = "";

  for(char ch : seq){
    encodedSeq += encode[ch];
  }

  cout<<"\nCharecter Codes: "<<endl;
  for(auto pair : encode){
    
    cout<<pair.first<<" : "<<pair.second<<endl;
    
  }
  cout<<endl;

  cout<<"\nModified Code: "<<encodedSeq<<endl;

  return 0;
}

unordered_map<char, string> huffmanCode(string seq){
  unordered_map<char, int> chFreq;

  for(char ch: seq){
    chFreq[ch]++;
  }

  priority_queue<Node*, vector<Node*>, Compare> nodes;

  for(auto& pair : chFreq){
    nodes.push(new Node(pair.first, pair.second));
  }

  while(nodes.size() > 1){
    Node* left = nodes.top(); nodes.pop();
    Node* right = nodes.top(); nodes.pop();

    Node *newNode = new Node('\0', left->freq + right->freq);
    newNode->left = left;
    newNode->right = right;

    nodes.push(newNode);
  }

  Node* hufftree = nodes.top();

  unordered_map<char, string> map;
  generateCode(hufftree, "", map);

  return map;

}

void generateCode(Node* root, string code, unordered_map<char, string>& map){
  if(!root) return;

  if(!root->left && !root->right){
    map[root->ch] = code;
  }

  generateCode(root->left, code+'0', map);
  generateCode(root->right, code+'1', map);
}
