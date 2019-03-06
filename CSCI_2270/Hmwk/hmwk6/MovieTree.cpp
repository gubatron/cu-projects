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

        movieTree->addMovie(ranking, title, year, rating);
    }

    filein.close();
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

void menu() {
    std::cout << "======Main Menu======" << std::endl;
    std::cout << "1. Print the inventory" << std::endl;
    std::cout << "2. Delete a movie" << std::endl;
    std::cout << "3. Quit" << std::endl;
}

void inorder(TreeNode *root) {
    if (root != nullptr) {
        inorder(root->leftChild);
        std::cout << "Movies starting with letter: " << root->titleChar << std::endl;
        //std::cout << " >> " << title << " " << m->rating << std::endl;
        inorder(root->rightChild);
    }
}

////////////////////////////////////////////////////////////////
// Class functions
////////////////////////////////////////////////////////////////
MovieTree::MovieTree() {

}

MovieTree::~MovieTree() {

}

// print in alphabetical order of titles
void MovieTree::printMovieInventory() {
    inorder(root);
// for every TreeNode (t) in the tree
//    cout << "Movies starting with letter: " << t->titleChar << endl;
// for every LLMovieNode (m) attached to t
//    cout << " >> " << m->title << " " << m->rating << endl;

}

void MovieTree::addMovie(int ranking, std::string title, int year, float rating) {

}

void MovieTree::deleteMovie(std::string title) {

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
