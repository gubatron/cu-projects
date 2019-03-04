//
// Created by Nicole Leon on 2/25/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"

////////////////////////////////////////////////////////////////
// HELPER FUNCTIONS
////////////////////////////////////////////////////////////////

// preorder to traverse tree and print if conditions are met.
void preorder(MovieNode *root, float base_rating, int base_year) {
    if (root != nullptr) {
        if (root->rating >= base_rating && root->year > base_year) {
            std::cout << root->title << "(" << root->year << ") " << root->rating << std::endl;
        }
        preorder(root->leftChild, base_rating, base_year);
        preorder(root->rightChild, base_rating, base_year);
    }
}

void inorder(MovieNode *root) {
    if (root != nullptr) {
        inorder(root->leftChild);
        std::cout << "Movie: " << root->title << " " << root->rating << std::endl;
        inorder(root->rightChild);
    }
}

void postorder_average(MovieNode *node, int &count, float &avg_rating) {
    if (node != nullptr) {
        postorder_average(node->leftChild, count, avg_rating);
        postorder_average(node->rightChild, count, avg_rating);
        avg_rating += node->rating;
        count++;
    }
}

void loadFile(MovieTree *movieTree, char *filepath) {
    std::ifstream filein(filepath);
    if (filein.fail()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    int ranking = 0;
    std::string title;
    int year = 0;
    float rating = 0.0;

    while (getline(filein, line)) {
        std::stringstream linestream(line);

        std::string rankingString;
        getline(linestream, rankingString, ',');
        ranking = stoi(rankingString);

        getline(linestream, title, ',');

        std::string yearString;
        getline(linestream, yearString, ',');
        year = stoi(yearString);

        std::string ratingString;
        getline(linestream, ratingString, ',');
        rating = stof(ratingString);

        movieTree->addMovieNode(ranking, title, year, rating);
    }

    filein.close();
}

void menu() {
    std::cout << "======Main Menu======" << std::endl;
    std::cout << "1. Find a movie" << std::endl;
    std::cout << "2. Query movies" << std::endl;
    std::cout << "3. Print the inventory" << std::endl;
    std::cout << "4. Average Rating of movies" << std::endl;
    std::cout << "5. Quit" << std::endl;
}

std::string lowercase(std::string s) {
    char char_array[s.size()];
    auto s_char_array = s.c_str();
    for (int i=0; i < s.size(); i++) {
        char_array[i] = static_cast<char>(tolower(s_char_array[i]));
    }
    std::string result(char_array);
    return result;
}

////////////////////////////////////////////////////////////////
// Class functions
////////////////////////////////////////////////////////////////

MovieTree::MovieTree() {
    // initialize any member variables of the class to default
    root = nullptr;
}

MovieTree::~MovieTree() {
    // free all memory that was allocated
}


/**
 * Print every node in the tree in alphabetical order of titles
 */
void MovieTree::printMovieInventory() {
    inorder(root);
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating) {
    auto tmp = new MovieNode();
    tmp->title = title;
    tmp->ranking = ranking;
    tmp->year = year;
    tmp->rating = rating;

    MovieNode *curr = root;
    MovieNode *prev = nullptr;

    if (root == nullptr) {
        root = tmp;
        return;
    } else {
        while (curr != nullptr) {
            prev = curr;
            if (title < curr->title) {
                curr = curr->leftChild;
            } else if (title == curr->title) return;
            else curr = curr->rightChild;
        }

        // found last element in the correct direction, let's insert
        // the new MovieNode POINTER (tmp) based on it's title left or right
        if (prev != nullptr) {
            if (title < prev->title) {
                prev->leftChild = tmp;
            } else {
                prev->rightChild = tmp;
            }
            tmp->parent = prev;
        }
    }
}

void MovieTree::findMovie(std::string title) {
    MovieNode *tmp = root;

    while (tmp != nullptr) {
        // make a copy of the strings to make a lowercase comparison without altering the original strings
        // of the MovieNode*'s

        std::string tmp_title_lowercase = lowercase(tmp->title);
        std::string title_lowercase = lowercase(title);

        if (tmp_title_lowercase == title_lowercase) {
            std::cout << "Movie Info:" << std::endl;
            std::cout << "==================" << std::endl;
            std::cout << "Ranking:" << tmp->ranking << std::endl;
            std::cout << "Title  :" << tmp->title << std::endl;
            std::cout << "Year   :" << tmp->year << std::endl;
            std::cout << "rating :" << tmp->rating << std::endl;
            return;
        } else if (title_lowercase < tmp_title_lowercase) {
            tmp = tmp->leftChild;
        } else {
            tmp = tmp->rightChild;
        }
    }
    std::cout << "Movie not found." << std::endl;
}

/*Print all the movies with a rating at least as good as rating
 that are newer than year in the preorder fashion*/
void MovieTree::queryMovies(float rating, int year) {
    std::cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << std::endl;
    preorder(root, rating, year);
}

void MovieTree::averageRating() {
    int count = 0;
    float average = 0.0;
    if (root != nullptr) {
      postorder_average(root, count, average);
      average = average / count;
    }
    std::cout << "Average rating:" << average << std::endl;
}
///////////////////////////////////////////////////////////////////////////////
/*HELPER FUNCTIONS*/
///////////////////////////////////////////////////////////////////////////////
/* search tree
 * returns a pointer to the node with the given title
 * or nullptr if no such movie exists*/
MovieNode *MovieTree::search(std::string title) {
    MovieNode *tmp = root;

    while (tmp != nullptr) {
        if (tmp->title == title) {
            /*Yay we found the value*/
            return tmp;
        } else if (title < tmp->title) {
            /*Val is not in the right sub-tree*/
            /*if it is at all there, it must be in the left sub-tree*/
            tmp = tmp->leftChild;
        } else {
            tmp = tmp->rightChild;
        }
    }
    return nullptr;
}


///////////////////////////////////////////////////////////////////////////////
/*DRIVER FUNCTION*/
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: incorrect number of arguments" << std::endl;
    }

    MovieTree tree;
    loadFile(&tree, argv[1]);


    // Once I read the file, display menu
    std::string choice;
    std::string input;

    while (choice != "6") {
        menu();
        getline(std::cin, choice);
        int choiceNum;
        try {
            choiceNum = stoi(choice);
        } catch (std::invalid_argument &e) {
            choiceNum = -1;
        }
        switch (choiceNum) {
            case 1:
                std::cout << "Enter title: " << std::endl;
                getline(std::cin, input);
                tree.findMovie(input);
                break;
            case 2:
                std::cout << "Enter minimum rating: " << std::endl;
                float rating;
                getline(std::cin, input);
                try {
                    rating = stof(input);
                } catch (std::invalid_argument &e) {
                    std::cout << "Error: invalid rating '" << input << "'" << std::endl;
                    break;
                }

                std::cout << "Enter minimum year:" << std::endl;
                getline(std::cin, input);
                int year;

                try {
                    year = stoi(input);
                } catch (std::invalid_argument &e) {
                    std::cout << "Error: invalid year '" << input << "'" << std::endl;
                    break;
                }

                tree.queryMovies(rating, year);
                break;
            case 3:
                tree.printMovieInventory();
                break;
            case 4:
                tree.averageRating();
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "invalid input\n\n";
        }
    }
}
