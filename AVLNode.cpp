/*
 * CSCI-2421: Data Structures and Program Design
 * University of Colorado Denver
 * AVL Tree Base Implementation.
 */
#include "AVLNode.h"

AVLNode::AVLNode()
{
    this->data = Contact();
    this->balance = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

AVLNode::AVLNode(Contact& data, AVLNode* parent)
{
    this->data = Contact(data);
    this->balance = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = parent;
}

AVLNode::AVLNode(Contact& data, AVLNode* left, AVLNode* right)
{
    this->data = Contact(data);
    this->balance = 0;
    this->left = left;
    this->right = right;
    this->parent = nullptr;
}

AVLNode::AVLNode(Contact& data, AVLNode* left, AVLNode* right, int balance)
{
    this->data = Contact(data);
    this->balance = balance;
    this->left = left;
    this->right = right;
    this->parent = nullptr;
}

AVLNode::~AVLNode()
{
    delete this->left;
    delete this->right;
}

void AVLNode::setData(Contact& data)
{
    this->data = Contact(data);
}

void AVLNode::setBalance(int bal)
{
    this->balance = bal;
}

void AVLNode::setLeft(AVLNode* left)
{
    this->left = left;
}

void AVLNode::setRight(AVLNode* right)
{
    this->right = right;
}

Contact& AVLNode::getData() const
{
    return this->data;
}

int AVLNode::getBalance() const
{
    return this->balance;
}

const AVLNode* const AVLNode::getLeft() const
{
    return this->left;
}

const AVLNode* const AVLNode::getRight() const
{
    return this->right;
}

bool AVLNode::operator < (const AVLNode& avlNode) const
{
    if ( this->data < avlNode.data ) return true;
    return false;
}

std::ostream& operator << (std::ostream& out, const AVLNode& avlNode)
{
    out << avlNode.data;
    return out;
}
