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


// MovieItem addMovieItemHelper(MovieItem *m, string t)
// {
//   // add a leaf
//   if (m == NULL) {
//     return new MovieItem(t);
//   }
//   // search in left sub tree
//   // search in right sub tree
// }


MovieItem getMovieHelper(MovieItem *current, string title)
{
  if (current == NULL)
  {
    cout << "Movie not found." << endl;
    return *current;
  }
  else if (current->title == title)
  {
    // FOUND
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << current->ranking << endl;
    cout << "Title  :" << current->title << endl;
    cout << "Year   :" << current->year << endl;
    cout << "rating :" << current->rating << endl;
    return *current;
  }
  else if (current->title > title)
  {
    return getMovieHelper(current->left, title);
  }
  return getMovieHelper(current->right, title);
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

// void MovieInventory::addMovieItem(int ranking, string title, int year, float rating)
// {
//   //TODO
//   auto *tmp = new MovieItem(ranking, title, year, rating);

//   root = addMovieItemHelper(tmp, tmp->title);
//   cout << tmp->title << " has been added" << endl;
// }


void MovieInventory::getMovie(string title)
{
  //TODO
  MovieItem movie;
  if (movie->title == NULL)
  getMovieHelper(root, title);  
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