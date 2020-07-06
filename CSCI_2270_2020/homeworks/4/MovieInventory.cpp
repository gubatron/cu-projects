#include "MovieInventory.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/////////////////////////////////////////////////
///// HELPER FUNCTIONS /////
/////////////////////////////////////////////////

void printMovieInventoryHelper(MovieItem *m)
{
  // in-order traversal
  if (m->left != NULL) {
    printMovieInventoryHelper(m->left);
  }
  if (m != NULL) {
    cout << "Movie: " << m->title << " " << m->rating << endl;
  }
  if (m->right != NULL) {
    printMovieInventoryHelper(m->right);
  }
}


void addMovieItemHelper(MovieItem *current, MovieItem *newMovieItem)
{
  if (current == NULL) {
    cout << "addMovieItemHelper: PARENT NODE IS NULL, CHECK YOUR LOGIC!" << endl;
    return;
  }

  if (newMovieItem->title == current->title) {
    //cout << "addMovieItemHelper: movie " << current->title << " already exists" << endl;
    return;
  }
  
  if (newMovieItem->title > current->title) {
    if (current->right == NULL) {
      current->right = newMovieItem;
      //cout << "addMovieItemHelper: added to the right of " << current->title << endl;
    } else {
      //cout << "addMovieItemHelper: diving to the right of " << current->title << endl;
      addMovieItemHelper(current->right, newMovieItem);
    }
  } else {
    if (current->left == NULL) {
      current->left = newMovieItem;
      //cout << "addMovieItemHelper: added to the left of " << current->title << endl;      
    } else {
      //cout << "addMovieItemHelper: diving to the left of " << current->title << endl;      
      addMovieItemHelper(current->left, newMovieItem);
    }
  }  
}

void printMovieItem(MovieItem* movieItemPtr) {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << movieItemPtr->ranking << endl;
    cout << "Title  :" << movieItemPtr->title << endl;
    cout << "Year   :" << movieItemPtr->year << endl;
    cout << "rating :" << movieItemPtr->rating << endl;
}

MovieItem* getMovieByTitle(MovieItem *current, string title)
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
  printMovieInventoryHelper(root);
}

void MovieInventory::addMovieItem(int ranking, string title, int year, float rating)
{
  auto temp = new MovieItem(ranking, title, year, rating);
  if (root == NULL) {
    root = temp;
    return;
  }
  addMovieItemHelper(root, temp);
}

void MovieInventory::getMovie(string title)
{
  static const string MOVIE_NOT_FOUND = "Movie not found.";  
  if (root == NULL) {
    cout << MOVIE_NOT_FOUND << endl;
    return;
  }

  MovieItem *foundMovie = getMovieByTitle(root, title);

  if (foundMovie == NULL) {
    cout << MOVIE_NOT_FOUND << endl;
    return;
  }

  printMovieItem(foundMovie);
}

void MovieInventory::searchMovies(float rating, int year)
{
  //TODO
}

void MovieInventory::averageRating()
{
  //TODO
}

MovieItem* getParent(MovieItem *current, MovieItem *foundMovie) {
  
}

MovieItem* minValueNode(MovieItem *node) {
  auto current = node; 
  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current; 
}

MovieItem* deleteMovieItemHelper(MovieItem *current, MovieItem *foundMovie) 
{
  if (current == NULL) {
    return NULL;
  }
  if (foundMovie->title < current->title) {
    current->left = deleteMovieItemHelper(current->left, foundMovie);
  } else if (foundMovie->title > current->title) {
    current->right = deleteMovieItemHelper(current->right, foundMovie);
  } else {
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


void MovieInventory::deleteMovieItem(string title)
{
  auto foundMovie = getMovieByTitle(root, title);
  if (foundMovie == NULL) {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  }
  deleteMovieItemHelper(root, foundMovie);
}

void MovieInventory::leftRotate(string title)
{
  //TODO
}
