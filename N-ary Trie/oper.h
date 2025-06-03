#pragma once
#pragma once
#include"Ntree.h"

Trie Ti;
int num = 0;//单词表中单词个数

//将文本文档索引化并构建Trie
void indexTextFile(const string& filename, Trie& trie) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "文件无法打开！" << filename << endl;
        return;
    }

    string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        string word;
        for (char c : line) {
            if (isalpha(c)) {
                word += tolower(c); //转换为小写字母
            }
            else {//遇到非字母字符，将之前收集的单词插入到Trie中
                if (!word.empty()) {
                    trie.insert(word, lineNumber);
                    word.clear();
                }
            }
        }
        if (!word.empty()) {
            trie.insert(word, lineNumber);
        }
        lineNumber++;
    }
    file.close();
}

//递归遍历Trie并输出所有单词及其行数
void displayTrieWords(TrieNode* node, const string& prefix = "") {
    if (node == nullptr) return;

    //如果当前节点是单词的结尾，输出该单词及其行数
    if (node->isEndOfWord) {
        v[num].word = prefix;
        cout << prefix << " ( 所在行号:";
        v[num].positions = node->positions;
        for (auto j : node->positions) {
            cout << j << " ";
        }
        cout << ")" << endl;
        num++;
    }

    //递归遍历所有子节点
    for (int i = 0; i < N; ++i) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            string newPrefix = prefix + c;
            displayTrieWords(node->children[i], newPrefix);
        }
    }
}

//显示Trie中的所有单词及其行数
void displayTrieWords(Trie& trie) {
    cout << "单词表如下：" << endl;
    displayTrieWords(trie.root);
}
