#pragma once
#pragma once
#include"Ntree.h"

Trie Ti;
int num = 0;//���ʱ��е��ʸ���

//���ı��ĵ�������������Trie
void indexTextFile(const string& filename, Trie& trie) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�ļ��޷��򿪣�" << filename << endl;
        return;
    }

    string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        string word;
        for (char c : line) {
            if (isalpha(c)) {
                word += tolower(c); //ת��ΪСд��ĸ
            }
            else {//��������ĸ�ַ�����֮ǰ�ռ��ĵ��ʲ��뵽Trie��
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

//�ݹ����Trie��������е��ʼ�������
void displayTrieWords(TrieNode* node, const string& prefix = "") {
    if (node == nullptr) return;

    //�����ǰ�ڵ��ǵ��ʵĽ�β������õ��ʼ�������
    if (node->isEndOfWord) {
        v[num].word = prefix;
        cout << prefix << " ( �����к�:";
        v[num].positions = node->positions;
        for (auto j : node->positions) {
            cout << j << " ";
        }
        cout << ")" << endl;
        num++;
    }

    //�ݹ���������ӽڵ�
    for (int i = 0; i < N; ++i) {
        if (node->children[i] != nullptr) {
            char c = 'a' + i;
            string newPrefix = prefix + c;
            displayTrieWords(node->children[i], newPrefix);
        }
    }
}

//��ʾTrie�е����е��ʼ�������
void displayTrieWords(Trie& trie) {
    cout << "���ʱ����£�" << endl;
    displayTrieWords(trie.root);
}
