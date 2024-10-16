//
// Created by one on 2024/10/15.
//

#ifndef MERKLETREE_H
#define MERKLETREE_H
#include "MerkleTreeNode.h"
#include <iostream>
#include "sha256.h"
using namespace std;
class MerkleTree{

private:
	string merkleRoot;
	int makeBinary(vector<MerkleTreeNode*>& node_vector);
	void printTreeLevel(vector<MerkleTreeNode*> v);
	vector<vector<MerkleTreeNode*>> base; //里面存的是一个个节点列表
public:
	MerkleTree();
	void buildTree();
	void buildBaseLeafes(vector<string> base_leafs);
	int verify(string hash);
	virtual ~MerkleTree();
};
MerkleTree::MerkleTree() {}

int MerkleTree::makeBinary(vector<MerkleTreeNode*>& node_vector) //使叶子节点成为双数
{
	int vectSize = node_vector.size();
	if ((vectSize % 2) != 0) //如果元素个数为奇数，就把再最后一个节点push_back一次
	{
		node_vector.push_back(node_vector.end()[-1]);
		vectSize++;
	}
	return vectSize;
}

void MerkleTree::printTreeLevel(vector<MerkleTreeNode*> v)
{
	for (MerkleTreeNode* el : v)
	{
		cout << el->getHash() << endl;
	}
	cout << endl;
}

void MerkleTree::buildTree() //建造merkle tree
{
	do
	{
		vector<MerkleTreeNode*> new_nodes;
		makeBinary(base.end()[-1]); //传入尾元素 即一个节点列表

		for (int i = 0; i < base.end()[-1].size(); i += 2)
		{
			MerkleTreeNode* new_parent = new MerkleTreeNode; //设置父亲节点 传入最后一个元素 即一个节点列表的第i和i+1个
			base.end()[-1][i]->setParent(new_parent);
			base.end()[-1][i + 1]->setParent(new_parent);

			//通过两个孩子节点的哈希值设置父节点哈希值
			new_parent->setHash(base.end()[-1][i]->getHash() + base.end()[-1][i + 1]->getHash());
			//将该父节点的左右孩子节点设置为这两个
			new_parent->setChildren(base.end()[-1][i], base.end()[-1][i + 1]);
			//将new_parent压入new_nodes
			new_nodes.push_back(new_parent);

			cout << "将 " << base.end()[-1][i]->getHash() << " 和 " << base.end()[-1][i + 1]->getHash() << " 连接,得到对应父节点的哈希值 " << endl;
		}

		cout << endl;
		cout << "得到的对应父节点的哈希值:" << endl;
		printTreeLevel(new_nodes);

		base.push_back(new_nodes); //将新一轮的父节点new_nodes压入base

		cout << "该层的结点有 " << base.end()[-1].size() << " 个:" << endl;
	} while (base.end()[-1].size() > 1); //这样每一轮得到新一层的父节点，知道得到根节点 退出循环

	merkleRoot = base.end()[-1][0]->getHash(); //根节点的哈希值

	cout << "Merkle Root : " << merkleRoot << endl << endl;
}

void MerkleTree::buildBaseLeafes(vector<string> base_leafs) //建立叶子节点列表
{
	vector<MerkleTreeNode*> new_nodes;

	cout << "叶子结点及对应的哈希值: " << endl;

	for (auto leaf : base_leafs) //给每一个字符串创建对应节点，并通过这个字符串设置哈希值
	{
		MerkleTreeNode* new_node = new MerkleTreeNode;
		new_node->setHash(leaf);
		cout << leaf << ":" << new_node->getHash() << endl;

		new_nodes.push_back(new_node);
	}

	base.push_back(new_nodes);
	cout << endl;
}

int MerkleTree::verify(string hash)
{
	MerkleTreeNode* el_node = nullptr;
	string act_hash = hash;

	for (int i = 0; i < base[0].size(); i++)
	{
		if (base[0][i]->getHash() == hash)
		{
			el_node = base[0][i];
		}
	}
	if (el_node == nullptr)
	{
		return 0;
	}

	cout << "使用到的哈希值:" << endl;
	cout << act_hash << endl;

	do  //验证merkle tree是否改变过
	{
		//父节点的哈希是左孩子的哈希string+右孩子的哈希string
		//如果el_node的父节点的左节点是el_node
		if (el_node->checkDir() == 0)
		{
			//是左孩子就 做孩子的哈希string+右孩子的哈希string
			act_hash = sha2::hash256_hex_string(act_hash + el_node->getSibling()->getHash());
		}
		else
		{
			act_hash = sha2::hash256_hex_string(el_node->getSibling()->getHash() + act_hash);
		}

		std::cout << act_hash << endl;

		el_node = el_node->getParent();
	} while ((el_node->getParent()) != NULL); //到达根节点

	return act_hash == merkleRoot ? 1 : 0;
}

MerkleTree::~MerkleTree() {}

#endif //MERKLETREE_H
