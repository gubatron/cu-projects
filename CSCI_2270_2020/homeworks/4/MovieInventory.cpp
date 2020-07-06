#include "MovieInventory.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;


static const string MOVIE_NOT_FOUND = "Movie not found.";

/////////////////////////////////////////////////
///// HELPER FUNCTIONS /////
/////////////////////////////////////////////////

void printMovieInventoryHelper(MovieItem *root, MovieItem *m)
{

  if (root == NULL)
  {
    cout << "Tree is Empty. Cannot print" << endl;
    return;
  }

  if (m->left != NULL) {
    printMovieInventoryHelper(root, m->left);
  } else {
    cout << "Movie: " << m->title << " " << m->rating << endl;
  }

  if (m->right != NULL) {
    printMovieInventoryHelper(root, m->right);
  } else {
    cout << "Movie: " << m->title << " " << m->rating << endl;
  }
}


void addMovieItemHelper(MovieItem *current, MovieItem *newMovieItem)
{
  if (current == NULL) {
    cout << "addMovieItemHelper: PARENT NODE IS NULL, CHECK YOUR LOGIC!" << endl;
    return;
  }

  if (newMovieItem->title == current->title) {
    cout << "addMovieItemHelper: movie " << current->title << " already exists" << endl;
    return;
  }
  
  if (newMovieItem->title > current->title) {
    if (current->right == NULL) {
      current->right = newMovieItem;
      cout << "addMovieItemHelper: added to the right of " << current->title << endl;
    } else {
      cout << "addMovieItemHelper: diving to the right of " << current->title << endl;
      addMovieItemHelper(current->right, newMovieItem);
    }
  } else {
    if (current->left == NULL) {
      current->left = newMovieItem;
      cout << "addMovieItemHelper: added to the left of " << current->title << endl;      
    } else {
      cout << "addMovieItemHelper: diving to the left of " << current->title << endl;      
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
  // TODO
  printMovieInventoryHelper(root, root);
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

void MovieInventory::deleteMovieItem(string title)
{
  //TODO
}

void MovieInventory::leftRotate(string title)
{
  //TODO
}
