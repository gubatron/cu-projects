#include "MovieInventory.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/////////////////////////////////////////////////
///// HELPER FUNCTIONS /////
/////////////////////////////////////////////////

// in-order traversal
void printMovieInventoryHelper(MovieItem *m, float optMinRating, int optMinYear)
{
  if (m->left != NULL)
  {
    printMovieInventoryHelper(m->left, optMinRating, optMinYear);
  }
  if (m != NULL)
  {
    if (optMinRating == 0 && optMinRating == 0)
    {
      // print everything
      cout << "Movie: " << m->title << " " << m->rating << endl;
    }
    else
    {
      if (m->rating >= optMinRating && m->year >= optMinYear)
      {
        cout << m->title << "(" << m->year << ") " << m->rating << endl;
      }
    }
  }
  if (m->right != NULL)
  {
    printMovieInventoryHelper(m->right, optMinRating, optMinYear);
  }
}

void addMovieItemHelper(MovieItem *current, MovieItem *newMovieItem)
{
  if (current == NULL)
  {
    // cout << "addMovieItemHelper: PARENT NODE IS NULL, CHECK YOUR LOGIC!" << endl;
    return;
  }

  if (newMovieItem->title == current->title)
  {
    //cout << "addMovieItemHelper: movie " << current->title << " already exists" << endl;
    return;
  }

  if (newMovieItem->title > current->title)
  {
    if (current->right == NULL)
    {
      current->right = newMovieItem;
      //cout << "addMovieItemHelper: added to the right of " << current->title << endl;
    }
    else
    {
      //cout << "addMovieItemHelper: diving to the right of " << current->title << endl;
      addMovieItemHelper(current->right, newMovieItem);
    }
  }
  else
  {
    if (current->left == NULL)
    {
      current->left = newMovieItem;
      //cout << "addMovieItemHelper: added to the left of " << current->title << endl;
    }
    else
    {
      //cout << "addMovieItemHelper: diving to the left of " << current->title << endl;
      addMovieItemHelper(current->left, newMovieItem);
    }
  }
}

void printMovieItem(MovieItem *movieItemPtr)
{
  cout << "Movie Info:" << endl;
  cout << "==================" << endl;
  cout << "Ranking:" << movieItemPtr->ranking << endl;
  cout << "Title  :" << movieItemPtr->title << endl;
  cout << "Year   :" << movieItemPtr->year << endl;
  cout << "rating :" << movieItemPtr->rating << endl;
}

MovieItem *getMovieByTitle(MovieItem *current, string title)
{
  if (current == NULL)
  {
    return NULL;
  }

  if (current->title == title)
  {
    return current;
  }

  if (current->title > title)
  {
    return getMovieByTitle(current->left, title);
  }

  return getMovieByTitle(current->right, title);
}

// Use with delete()
MovieItem *minValueNode(MovieItem *node)
{
  auto current = node;
  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

MovieItem *deleteMovieItemHelper(MovieItem *current, MovieItem *foundMovie)
{
  if (current == NULL)
  {
    return NULL;
  }
  if (foundMovie->title < current->title)
  {
    current->left = deleteMovieItemHelper(current->left, foundMovie);
  }
  else if (foundMovie->title > current->title)
  {
    current->right = deleteMovieItemHelper(current->right, foundMovie);
  }
  else
  {
    if (current->left == NULL)
    {
      auto temp = current->right;
      delete current;
      return temp;
    }
    else if (current->right == NULL)
    {
      auto temp = current->left;
      delete current;
      return temp;
    }
    // node with two children: Get the inorder successor (smallest
    // in the right subtree)
    auto minRightTemp = minValueNode(current->right);
    // Copy the inorder successor's content to this node
    current->ranking = minRightTemp->ranking;
    current->title = minRightTemp->title;
    current->year = minRightTemp->year;
    current->rating = minRightTemp->rating;
    // Delete the inorder successor
    current->right = deleteMovieItemHelper(current->right, minRightTemp);
  }
  return current;
}

// Use with averageRating()
void inOrderAverage(MovieItem *movieNode, int &count, float &avgRating)
{
  if (movieNode != NULL)
  {
    inOrderAverage(movieNode->left, count, avgRating);
    avgRating += movieNode->rating;
    inOrderAverage(movieNode->right, count, avgRating);
    count++;
  }
}
/////////////////////////////////////////////////
///// CLASS FUNCTIONS /////
/////////////////////////////////////////////////

// MovieItem: node struct that will be stored in the MovieInventory BST

MovieInventory::MovieInventory()
{
  root = NULL;
}

MovieInventory::~MovieInventory()
{
  //TODO
  delete root;
}

void MovieInventory::printMovieInventory()
{
  if (root == NULL)
  {
    cout << "Tree is Empty. Cannot print" << endl;
    return;
  }
  printMovieInventoryHelper(root, 0, 0);
}

void MovieInventory::addMovieItem(int ranking, string title, int year, float rating)
{
  auto temp = new MovieItem(ranking, title, year, rating);
  if (root == NULL)
  {
    root = temp;
    return;
  }
  addMovieItemHelper(root, temp);
}

void MovieInventory::getMovie(string title)
{
  if (root == NULL)
  {
    cout << "Movie not found." << endl;
    return;
  }

  MovieItem *foundMovie = getMovieByTitle(root, title);

  if (foundMovie == NULL)
  {
    cout << "Movie not found." << endl;
    return;
  }

  printMovieItem(foundMovie);
}

void MovieInventory::searchMovies(float rating, int year)
{
  if (root == NULL)
  {
    cout << "Tree is Empty. Cannot query Movies" << endl;
    return;
  }

  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  printMovieInventoryHelper(root, rating, year);
}

void MovieInventory::averageRating()
{
  int count = 0;
  float average = 0.0;

  if (root == NULL)
  {
    cout << "Average rating:0.0" << endl;
  }
  else
  {
    inOrderAverage(root, count, average);
    average = average / count;
    cout << "Average rating:" << average << endl;
  }
}

void MovieInventory::deleteMovieItem(string title)
{
  auto foundMovie = getMovieByTitle(root, title);
  if (foundMovie == NULL)
  {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  }
  deleteMovieItemHelper(root, foundMovie);
}

void MovieInventory::leftRotate(string title)
{
  MovieItem *x;  // "Root"
  MovieItem *xp; // parent
  MovieItem *y;  // "Pivot"

  // BEFORE ROTATION
  // If x was the root before rotation, make y the new root.
  if (x == root)
  {
    y = root;
  }
  // If x does not have a right child, don’t perform any rotation.
  // so if x's rigth is NOT NULL, do the rotation
  if (x->right != NULL) // x has right child
  {
    /*help from Wikipedia 
    https://en.wikipedia.org/wiki/Tree_rotation
    OS: Opposite Side
    RS: Rotation Side

        Pivot = Root.OS
        Root.OS = Pivot.RS
        Pivot.RS = Root
        Root = Pivot
    */

    y = x->right; // x and it’s left descendants become the left subtree of y, with x as the left child.
    x->right = y->left;
    y->left = x;
    x = y;

    xp = root;
    
    if (y->title < xp->title)
    {
      // make y left child of xp
      xp->left = y;
    }
    else
    {
      xp->right = y;
    }
  }

/*
➔ Rotate the node with the given title towards the left.
● After the rotation, the parent of x now becomes the parent of y. y becomes parent of
x.
● Set the children pointers: Three children pointers are modified. 
    i) The left subtree of y becomes the right subtree of x. 
    
    ii) x and it’s left descendants become the left subtree of y, with x as the left child. 
    
    iii) If x was the left (or right) child of xp before the rotation, make y the left 
    (or right) child of xp after rotation accordingly. This can be implemented by comparing 
    the titles of y and xp: if y.title < xp.title, make y the left child of xp, else make y 
    the right child of xp. A less riskier approach is to keep track of whether x was the left
    child or the right child before the rotation, and make y the left or the right child accordingly.

● Take care of the boundary cases: 
    i) If x was the root before rotation, make y the new root. 
    
    ii) If x does not have a right child, don’t perform anyrotation.
*/
}
