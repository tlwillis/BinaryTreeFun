#ifndef BST_H
#define BST_H

#ifdef __cplusplus
extern "C" {
    
#endif


class BST{
private:
    struct node{
        int key;
        node* left;
        node* right;
    };
    
    node* root;
    void AddLeafPrivate(int key, node* ptr);
    void PrintInOrderPrivate(node* ptr);
    node* ReturnNodePrivate(int key, node* ptr);
    int FindSmallestPrivate(node* ptr);
    void RemoveNodePrivate(int key, node* ptr);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node* match, bool left);
    
public:
    
    BST();
    node* CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();
    node* ReturnNode(int key);
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);
    
    
};

#ifdef __cplusplus
}

#endif

#endif /* BST_H */

