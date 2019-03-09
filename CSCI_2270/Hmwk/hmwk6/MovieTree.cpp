#include <utility>

#include <utility>

#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"

////////////////////////////////////////////////////////////////
// Helper functions
////////////////////////////////////////////////////////////////
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

        /*TODO code addMovie to linked lists based on character letter*/
        movieTree->addMovie(ranking, title, year, rating);
    }

    filein.close();
}

std::string lowercase(const std::string &s) {
    char char_array[s.size()];
    auto s_char_array = s.c_str();
    for (int i=0; i < s.size(); i++) {
        char_array[i] = static_cast<char>(tolower(s_char_array[i]));
    }
    std::string result(char_array);
    return result;
}

void menu() {
    std::cout << "======Main Menu======" << std::endl;
    std::cout << "1. Print the inventory" << std::endl;
    std::cout << "2. Delete a movie" << std::endl;
    std::cout << "3. Quit" << std::endl;
}


void inorder(TreeNode *root) {
    auto tmp = root;
    if (root != nullptr) {
        inorder(tmp->leftChild);

        std::cout << "Movies starting with letter: " << tmp->titleChar << std::endl;
        // root->head is an LLMovieNode
        while (tmp->head != nullptr) {
            // print linked list
            std::cout << "Movie: " << tmp->head->title << " " << tmp->head->rating << std::endl;
            tmp->head = tmp->head->next;
        }

        inorder(tmp->rightChild);
    }
}


////////////////////////////////////////////////////////////////
// Class functions
////////////////////////////////////////////////////////////////
MovieTree::MovieTree() {root = nullptr;}

MovieTree::~MovieTree() = default;

// print in alphabetical order of titles
void MovieTree::printMovieInventory() {
    // movies are already sorted alpha as they're added to the linked lists
    inorder(root);
}

// adds movies to linked lists
// sort into alpha as they enter their respective linked lists
void MovieTree::addMovie(int ranking, std::string title, int year, float rating) {
    auto newMovieNode = new LLMovieNode();
    newMovieNode->ranking = ranking;
    newMovieNode->title = std::move(title);
    newMovieNode->year = year;
    newMovieNode->rating = rating;
    newMovieNode->next = nullptr;

    char titleChar = title[0];
    // Add node to the TREE based on titleChar of the movie - TreeNode
    TreeNode *curr = root;
    TreeNode *prev = nullptr;

    if (root == nullptr) {
        root = ;
        return;
    } else {
        while (curr != nullptr) {
            prev = curr;
            if (titleChar < curr->titleChar) {
                curr = curr->leftChild;
            } else if (titleChar == curr->titleChar) return;
            else curr = curr->rightChild;
        }

        // found last element in the correct direction, let's insert
        // the new TreeNode POINTER (tmp) based on it's tilteChar left or right
        if (prev != nullptr) {
            if (titleChar < prev->titleChar) {
                prev->leftChild = tmp;
                // insert sorted linked list

            } else {
                prev->rightChild = tmp;
                // insert sorted linked list
            }
            tmp->parent = prev;
        }
    }
    // Add LINKED LIST of movie titles alphabetically to the TREE NODE - LLMovieNode (head?)

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

//    If there is no tree node corresponding to the first letter of title, create it and insert
//    it in the tree in the alphabetically correct position
//    ◆ Create a linked list node with ranking, title, year and rating, and insert it in the
//    linked list associated with the tree node associated with the first letter of title. The
//    linked list must also be in alphabetical order, such that for each node,
//            node->title < node->next->title
//
}

void MovieTree::deleteMovie(std::string title) {
    // search through tree for the first letter, search through list in alpha for movie
    // if found, delete
}


////////////////////////////////////////////////////////////////
// Driver function
////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: incorrect number of arguments" << std::endl;
    }

    MovieTree tree;
    loadFile(&tree, argv[1]);

    std::string choice;
    std::string input;

    while (choice != "4") {
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
                tree.printMovieInventory();
                break;
            case 2:
                std::cout << "Enter title:\n";
                getline(std::cin, input);
                tree.deleteMovie(input);
                break;
            case 3:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "invalid input\n\n";
        }
    }
}