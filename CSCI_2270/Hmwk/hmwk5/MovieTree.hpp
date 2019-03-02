/****************************************************************/
/*                    MovieTree Definition                      */
/****************************************************************/
/*      LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]       */
/****************************************************************/

#pragma once

#include <string>


// MovieNode: node struct that will be stored in the MovieTree BST

struct MovieNode {
    int ranking;       // Rank of the movie
    std::string title; // Title of the movie
    int year;          // Year this movie was released
    float rating;      // IMDB rating

    MovieNode *parent = nullptr;     // Pointer to the parent node
    MovieNode *leftChild = nullptr;  // Pointer to the leftchild
    MovieNode *rightChild = nullptr; // Pointer to the rightChild

    // default constructor
    MovieNode() {}
};

// Class for storing and manipulating a tree of MovieNode's
class MovieTree {
private:
    // Pointer to the root node
    MovieNode *root;
public:
    // Check writeup for detailed function descriptions
    MovieTree();

    ~MovieTree();

    void printMovieInventory();

    void addMovieNode(int ranking, std::string title, int year, float rating);

    void findMovie(std::string title);

    void queryMovies(float rating, int year);

    void averageRating();

private:
    MovieNode *search(std::string title);

    void preorder(MovieNode *root);

    void queryPreorder(MovieNode *root);

    void menu();
};