#pragma once
#include<bits/stdc++.h>
using namespace std;

const int N = 26;
int n = 0;

//单词表
struct wordNode {
    vector<int> positions; 
    string word;
};
vector<wordNode> v(1000000);

//Trie节点的定义
class TrieNode {
public:
    TrieNode* children[N];
    vector<int> positions; //记录单词出现的行号
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < N; ++i)
            children[i] = nullptr;
    }
};

//Trie类的定义
class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(const string& word, int position);//插入单词
    bool search1(const string& word);//整个单词是否存在
    bool search2(const string& prex);//以prex为前缀的单词是否存在
    vector<int> searchWord1(const string& word);//查询整个单词返回行号
    vector<wordNode> searchWord2(const string& prex);//查询单词前缀返回行号
};

//插入单词
void Trie::insert(const string& word, int position) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index])
            curr->children[index] = new TrieNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
    curr->positions.push_back(position);
}

//整个单词是否存在
bool Trie::search1(const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index])
            return false;
        curr = curr->children[index];
    }
    return curr != nullptr && curr->isEndOfWord;
}

//以prex为前缀的单词是否存在
bool Trie::search2(const string& prex) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].word.compare(0, prex.length(), prex) == 0) {
            return true;
        }
    }
    return false;
}

//查询单词返回行号
vector<int> Trie::searchWord1(const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index])
            return {};
        curr = curr->children[index];
    }
    return curr->positions;
}

//查询单词前缀返回行号
vector<wordNode> Trie::searchWord2(const string& prex) {
    vector<wordNode> p(100000);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].word.compare(0, prex.length(), prex) == 0) {
            p[n].word = v[i].word;
            p[n].positions = v[i].positions;
            n++;
        }
    }
    p.resize(n);
    return p;
}
