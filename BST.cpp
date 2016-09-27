#include <cstdlib>
#include <iostream>
#include "BST.h"


BST::BST(){
    root = NULL;
}

BST::node* BST::CreateLeaf(int key){
    
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

void BST::AddLeaf(int key)
{    
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* ptr)
{
    if(root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if(key < ptr->key)
    {
        if(ptr->left != NULL)
        {
            AddLeafPrivate(key, ptr->left);
        }
        else
        {
            ptr->left = CreateLeaf(key);
        }
    }
    else if(key > ptr->key)
    {
        if(ptr->right != NULL)
        {
            AddLeafPrivate(key, ptr->right);
        }
        else
        {
            ptr->right = CreateLeaf(key);
        }
    }
    else
    {
        std::cout << "Key already in tree" << std::endl;
    }
}

void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* ptr)
{
    if(root != NULL)
    {
        if(ptr->left != NULL)
        {
            PrintInOrderPrivate(ptr->left);
        }
        std::cout << ptr->key << " ";
        if(ptr->right != NULL)
        {
            PrintInOrderPrivate(ptr->right);
        }
    }
    else
    {
        std::cout << "Tree is empty" << std::endl;
    }
}

BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* ptr)
{
    if(ptr != NULL)
    {
        if(ptr->key == key)
        {
            return ptr;
        }
        else
        {
            if(key < ptr->key)
            {
                return ReturnNodePrivate(key, ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int BST::ReturnRootKey()
{
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1;
    }
}

void BST::PrintChildren(int key)
{
    node* ptr = ReturnNode(key);
    if(ptr != NULL)
    {
        std::cout << "\nparent " << ptr->key << "\n";
        
        ptr->left == NULL ?
            std::cout << "\nLeft child is null\n" : 
            std::cout << "\nLeft child " << ptr->left->key << "\n";
        
        ptr->right == NULL ?
            std::cout << "\nRight child is null\n" : 
            std::cout << "\nRight child " << ptr->right->key << "\n";
        
    }
    else
    {
        std::cout << "Key doesn't exist";
    }
}

int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* ptr)
{
    if(root == NULL)
    {
        std::cout << "\nTree is empty\n";
        return -1;
    }
    else
    {
        if(ptr->left != NULL)
        {
            return FindSmallestPrivate(ptr->left);
        }
        else
        {
            return ptr->key;
        }
    }
}

void BST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* ptr)
{
    if(root != NULL)
    {
        if(root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if((key < ptr->key) && (ptr->left != NULL))
            {
                ptr->left->key == key ?
                    RemoveMatch(ptr, ptr->left, true) :
                    RemoveNodePrivate(key, ptr->left);
            }
            else if((key > ptr->key) && (ptr->right != NULL))
            {
                ptr->right->key == key ?
                    RemoveMatch(ptr, ptr->right, true) :
                    RemoveNodePrivate(key, ptr->right);
            }
            else
            {
                std::cout << "\nKey not in tree\n";
            }
        }
    }
    else
    {
        std::cout << "\nTree is empty\n";
    }
}

void BST::RemoveRootMatch()
{
    if(root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;
        
        if((root->left == NULL) && (root->right == NULL)){
            root = NULL;
            delete delPtr;
        }
        else if((root->left == NULL) && (root->right != NULL))
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            std::cout << rootKey << " was deleted "
                    "new root has key " << root->key << std::endl;
        }
        else if((root->left != NULL) && (root->right == NULL))
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            std::cout << rootKey << " was deleted "
                    "new root has key " << root->key << std::endl;
        }
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            std::cout << "Root was overwritten. " << root->key << 
                    " is the new root\n";
        }
    }
    else
    {
        std::cout << "\nTree is empty\n";
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
    if(root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        
        if((match->left == NULL) && (match->right == NULL))
        {
            delPtr = match;
            left == true ?
                parent->left = NULL :
                parent->right = NULL;
            delete delPtr;
            std::cout << matchKey << " node was deleted\n";
        }
        else if((match->left == NULL) && (match->right != NULL))
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            std::cout << matchKey << " node was deleted\n";
        }
        else if((match->left != NULL) && (match->right == NULL))
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            std::cout << matchKey << " node was deleted\n";
        }
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        std::cout << "\nTree is empty\n";
    }
}