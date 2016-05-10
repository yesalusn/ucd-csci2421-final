/*
 * CSCI-2421: Data Structures and Program Design
 * University of Colorado Denver
 * AVL Tree Base Implementation.
 */
#ifndef AVLNode_H
#define AVLNode_H

#include <iostream>

class Contact;

class AVLNode {
public:
    AVLNode();
    AVLNode(Contact&, AVLNode*);
    AVLNode(Contact&, AVLNode*, AVLNode*);
    AVLNode(Contact&, AVLNode*, AVLNode*, int);
    ~AVLNode();

    void setData(Contact&);
    void setBalance(int);
    void setLeft(AVLNode*);
    void setRight(AVLNode*);

    Contact& getData() const;
    int getBalance() const;
    const AVLNode* const getLeft() const;
    const AVLNode* const getRight() const;

    bool operator < (const AVLNode&) const;
    friend std::ostream& operator << (std::ostream&, const AVLNode&);

    /* Tree structure pointers */
    AVLNode* left;
    AVLNode* right;
    AVLNode* parent;

    /* AVL Balance Factor */
    int balance;

    /* Node Internal Data */
    typedef Contact contact;
    contact data;
};

#endif
