//
// Created by one on 2024/10/15.
//

#ifndef MERKLETREENODE_H
#define MERKLETREENODE_H
#include <iostream>
#include <sstream>
#include "sha256.h"
#include <string>
#include <vector>
using namespace std;

class MerkleTreeNode {

private:
    string hash_str;
    MerkleTreeNode* parent;
    MerkleTreeNode* children[2];
public:
   MerkleTreeNode();
   MerkleTreeNode* getParent();
    void setChildren(MerkleTreeNode* children_l, MerkleTreeNode* children_r);
    MerkleTreeNode* getChildren(int index);
    void setParent(MerkleTreeNode* parent);
    string getHash();
    int checkDir();
    MerkleTreeNode* getSibling();
    void setHash(string hash_str);
    virtual ~MerkleTreeNode();
};
MerkleTreeNode::MerkleTreeNode()
{
    parent = nullptr;
    children[0] = nullptr;
    children[1] = nullptr;
}

//???¨´???
void MerkleTreeNode::setHash(string hash_str)
{
    this->hash_str = sha2::hash256_hex_string(hash_str);
}
MerkleTreeNode* MerkleTreeNode::getParent()
{
    return parent;
}
void MerkleTreeNode::setParent(MerkleTreeNode* parent)
{
    this->parent = parent;
}
void MerkleTreeNode::setChildren(MerkleTreeNode* children_l,MerkleTreeNode* children_r)
{
    children[0] = children_l;
    children[1] = children_r;
}
MerkleTreeNode* MerkleTreeNode::getSibling() //???????????????????????????
{
    //????????????
 MerkleTreeNode* parent = getParent();

    //?§Ø?????????????????????
    //????????????????????????
    return parent->getChildren(0) == this ? parent->getChildren(1) : parent->getChildren(0);
}
MerkleTreeNode* MerkleTreeNode::getChildren(int index)
{
    return index <= 1 ? children[index] : nullptr;
}
string MerkleTreeNode::getHash()
{
    return hash_str;
}
int MerkleTreeNode::checkDir()
{
    //????Íè????????????? ????0 ???????1
    return parent->getChildren(0) == this ? 0 : 1;
}

MerkleTreeNode::~MerkleTreeNode() {}




#endif //MERKLETREENODE_H
