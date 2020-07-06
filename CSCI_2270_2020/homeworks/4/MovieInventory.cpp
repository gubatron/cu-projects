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

void deleteMovieItemHelper(MovieItem* current, MovieItem *foundMovie) 
{
  // No children, just delete
  if (foundMovie->left == NULL && foundMovie->right == NULL)
  {
    delete foundMovie;
  }
}

void MovieInventory::deleteMovieItem(string title)
{
  auto foundMovie = getMovieByTitle(root, title);
  if (foundMovie == NULL) {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  }
  
}

void MovieInventory::leftRotate(string title)
{
  //TODO
}
