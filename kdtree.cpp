#include "kdtree.hpp"

#include <stdexcept>

KDTree::KDTree()
    : root_(nullptr)
{
}
        
KDTree::~KDTree()
{
    delete root_;
}


void KDTree::insert(const Coordinate& c)
{
    Node* n = root_;
 
    Node* parent = nullptr;
 
    bool x = true;
 
    while(n != nullptr)
    {
        parent = n;
        
        if(x) // o nó particionou o espaço ao longo do X
        {
            n = (c.x_ < n->c_.x_) ? n->left_ : n->right_;
        }
        else // // o nó particionou o espaço ao longo do Y
        {
           
            n = (c.y_ < n->c_.y_) ? n->left_ : n->right_;
        }
        
        x = !x;
    }
 
    Node* nn = new Node{c, nullptr, nullptr};
 
    if(parent == nullptr)
        root_ = nn;
    else if(x) // parent => particionou por Y
    {
        if(c.y_ < parent->c_.y_)
            parent->left_ = nn;
        else
            parent->right_ = nn;
    }
    else  // parent => particionou por X
    {
        if(c.x_ < parent->c_.x_)
            parent->left_ = nn;
        else
            parent->right_ = nn;
    }
 
    return;
}

bool KDTree::contains(const Coordinate& c) const
{
    // ...
    
    return false;
}

std::vector<Coordinate> KDTree::search(const Rectangle& r) const
{
    std::vector<Coordinate> result;
    
    // ...
    
    return result;
}