#ifndef HUFFMANCODER_H
#define HUFFMANCODER_H

#include <iostream>
#include <queue>
#include <map>
#include <iterator>
#include <fstream>
#include <string>
#include "InputBitStream.h"
#include "OutputBitStream.h"
#include "Nodes.h"
#include "QString"

using namespace std;

typedef std::vector<bool> HuffCode;
typedef std::map<char, LeafNode *> HuffCodeMap;


class HuffmanCoder {

public :
    static const int UniqueSymbols = 256;
    int frequencies[UniqueSymbols] { 0 };
    string outFile{ "E:/exmp_output" }; //Where to write
    string inFile{ "E:/exmp_output" }; //From where to read
    string TestString{ "" };
    TreeNode* root{ nullptr };
    HuffCodeMap codes;
    LeafNode* endOfFileNode{ nullptr };

    //Build a Huffman tree
    TreeNode* HuffmanCoder::BuildTree()
    {
        std::priority_queue<TreeNode*, std::vector<TreeNode*>, NodeCmp> trees;

        for (int i = 0; i < UniqueSymbols; ++i)
        {
            if (frequencies[i] != 0)
                trees.push(new LeafNode(frequencies[i], (char)i));
        }
        endOfFileNode->f = trees.top()->f + 1;
        trees.push(endOfFileNode);
        while (trees.size() > 1)
        {
            TreeNode* childR = trees.top();
            trees.pop();

            TreeNode* childL = trees.top();
            trees.pop();

            TreeNode* parent = new InternalNode(childR, childL);
            trees.push(parent);
        }
        return trees.top();
    }

    //Run through the tree to give each node corresponding paths
    void HuffmanCoder::GenerateCodes(TreeNode* node, HuffCode& prefix)
    {
        if (node->nodeType == NodeType::Leaf)
        {
            auto leaf = dynamic_cast<LeafNode*>(node);
            codes[leaf->symbol] = leaf;
            codes[leaf->symbol]->path = vector<bool>(prefix);
        }
        else
        {
            const InternalNode* in = dynamic_cast<const InternalNode*>(node);
            HuffCode leftPrefix = prefix;
            leftPrefix.push_back(false);
            GenerateCodes(in->left, leftPrefix);

            HuffCode rightPrefix = prefix;
            rightPrefix.push_back(true);
            GenerateCodes(in->right, rightPrefix);
        }
    }

    //Ask for next operation
    char HuffmanCoder::AskUser()
    {
        char answer;
        cout << "0 - encript message\n2 - decript message" << endl;
        answer = std::getchar();
        switch (answer)
        {
        case '0':
            if (TestString == "") {
                cout << "Write the message" << endl;
                cout.clear(); cin.ignore();
                std::getline(cin, TestString, '\n');
            }
            else
                return '\0';
            Encrypt();
            ShowCodes();
            cout << TestString << endl;
            break;
        case '1':
            break;
        }
        return answer;
    }

    //Encrypt the string
    void HuffmanCoder::Encrypt()
    {
        ////debug 1
        //TryWriteRead();
        //system("pause");
        //return 0;
        ////debug 1

        ////debug 2
        //vector<LeafNode> vec;
        //for (auto a : TestString)
        //{
        //	vec.push_back(LeafNode(13, a));
        //}
        //for(auto a : vec)
        //{
        //	cout << a.GetSymbol()[0];
        //}
        //system("pause");
        //return 0;
        ////debug 2

        ////debug3
        //BitwiseTest(); return 0; InOutTest(); return 0;
        //Build frequency table
        //system("pause");
        //return 0;
        ////debug3

        //Counting symbol frequencies
//        const char* ptr = TestString.c_str();
//        while (*ptr != '\0')
//            ++frequencies[*ptr++];

        for (char &s : TestString)
        {
            frequencies[(unsigned char)s]++;
        }

        endOfFileNode = new LeafNode(0, '\0');
        root = BuildTree();

        GenerateCodes(root, HuffCode());
    }

    void HuffmanCoder::ShowFreqs()
    {
        for(auto fr : frequencies)
        {
            cout << fr << " ";
        }
    }

    //Write to a file bitwise
    void HuffmanCoder::WriteHuffmanEncoding()
    {
        OutputBitStream* oBS = new OutputBitStream(outFile);

        for (auto ch : TestString)
        {
            for (auto a : codes[ch]->path) {
                oBS->Write(a);
            }
        }
        for (auto a : endOfFileNode->path) {
            oBS->Write(a);
        }

        oBS->Close();
        if (oBS != nullptr)
        {
            delete oBS;
        }
    }

    //Show Huffman Codes
    string HuffmanCoder::ShowCodes()
    {
        //setlocale(LC_ALL, "Russian");
        string output = "Here are the codes for symbols: \n \\0";
        for (auto it = codes.begin(); it != codes.end(); ++it)
        {
                std::cout << it->first << " ";
                output += it->first; output += " ";
            for (auto &i : it->second->path) // access by reference to avoid copying
            {
                if (it->first != '\0')
                    cout << i;
                output += ((char)i+48);
            }
            std::cout << std::endl;
            output += "\n";
        }
        return output;
    }

    //Read from a file bitwise
    string HuffmanCoder::ReadHuffmanEncoding()
    {
        auto iBS = new InputBitStream(inFile);
        string input = ""; bool bit;
        char redSymbol;

        if (root == nullptr)
            return "";

        TreeNode *currentNode = root; //vector<int> inp; //Debug

        while (!iBS->eof)
        {
            if (currentNode->nodeType == NodeType::Internal) {

                bit = iBS->Read(); //inp.push_back(bit); //Debug
                currentNode = currentNode->GetChild(bit);
                if (currentNode == nullptr)
                    break;
            }
            else
            {
                redSymbol = currentNode->GetSymbol()[0];
                if (redSymbol != '\0') {
                    input += (char)redSymbol;
                    currentNode = root;
                }
                else
                {
                    break;
                }
            }
        }

        //cout << "{";
        //for (auto a : inp) // Debug
        //{
        //	cout << a;
        //}
        //cout << "}";

        cout << "{" << input << "}" << endl;

        //if (iBS != nullptr) {
        //    delete iBS;
        //}
        return input;
    }

    //Debuging Test
    void HuffmanCoder::TryWriteRead()
    {
        vector<int> vB;
        ofstream oS;
        oS.open(outFile, std::ios_base::out & std::ios_base::binary);
        oS << ("abcdefg");
        oS.close();

        InputBitStream *iBS = new InputBitStream(inFile);
        auto bfr = iBS->Read();
        while (!iBS->eof)
        {
            vB.push_back(bfr);
            bfr = iBS->Read();
        }

        for (auto a : vB) {
            cout << a;
        }
        /*return;*/

        string strng = "";
        unsigned char _currentByte = 0;
        int _bitsPending = 7;
        for (auto a : vB)
        {
            _currentByte |= ((a << _bitsPending) & (1 << _bitsPending));

            if (--_bitsPending < 0) {
                strng += _currentByte;
                _bitsPending = 7;
                _currentByte = 0;
            }
        }

        for (auto a : strng) {
            cout << (char)a;
        }
        if (iBS != nullptr) {
            delete iBS;
        }
    }

    ~HuffmanCoder()
    {
        if (root != nullptr)
            delete root;
    }
};
#endif //HUFFMANCODER_H