#ifndef __KDTREE_HPP__
#define __KDTREE_HPP__

#include <vector>

#include "coordinate.hpp"
#include "rectangle.hpp"


struct Node
{
    Coordinate c_;
    Node* left_;
    Node* right_;
    
    ~Node()
    {
        delete left_;
        delete right_;
    }
};


class KDTree
{

    public:
    
        KDTree();
        
        ~KDTree();
        
        void insert(const Coordinate& c);

        bool contains(const Coordinate& c) const;

        std::vector<Coordinate> search(const Rectangle& r) const;


    private:
    
        Node* root_;
};

#endif // __KDTREE_HPP__