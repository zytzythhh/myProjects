#pragma once
#include<bits/stdc++.h>
using namespace std;

const int N = 26;
int n = 0;

//���ʱ�
struct wordNode {
    vector<int> positions; 
    string word;
};
vector<wordNode> v(1000000);

//Trie�ڵ�Ķ���
class TrieNode {
public:
    TrieNode* children[N];
    vector<int> positions; //��¼���ʳ��ֵ��к�
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < N; ++i)
            children[i] = nullptr;
    }
};

//Trie��Ķ���
class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(const string& word, int position);//���뵥��
    bool search1(const string& word);//���������Ƿ����
    bool search2(const string& prex);//��prexΪǰ׺�ĵ����Ƿ����
    vector<int> searchWord1(const string& word);//��ѯ�������ʷ����к�
    vector<wordNode> searchWord2(const string& prex);//��ѯ����ǰ׺�����к�
};

//���뵥��
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

//���������Ƿ����
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

//��prexΪǰ׺�ĵ����Ƿ����
bool Trie::search2(const string& prex) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].word.compare(0, prex.length(), prex) == 0) {
            return true;
        }
    }
    return false;
}

//��ѯ���ʷ����к�
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

//��ѯ����ǰ׺�����к�
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
