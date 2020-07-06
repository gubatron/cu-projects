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

void printMovieInventoryHelper(MovieItem *m)
{

  if (m == NULL)
  {
    cout << "Tree is Empty. Cannot print" << endl;
  }
  else
  {
    printMovieInventoryHelper(m->left);
    cout << "Movie: " << m->title << " " << m->rating << endl;
    printMovieInventoryHelper(m->left);
  }
}


void addMovieItemHelper(MovieItem *current, MovieItem *newMovieItem)
{
  if (current == NULL) {
    return;
  }

  if (newMovieItem->title == current->title) {
    return;
  }
  
  if (newMovieItem->title > current->title) {
    if (current->right == NULL) {
      current->right = newMovieItem;
    } else {
      addMovieItemHelper(current->right, newMovieItem);
    }
  } else {
    if (current->left == NULL) {
      current->left = newMovieItem;
    } else {
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
  (printMovieInventoryHelper(root));
}

void MovieInventory::addMovieItem(int ranking, string title, int year, float rating)
{
   addMovieItemHelper(root, new MovieItem(ranking, title, year, rating));
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
