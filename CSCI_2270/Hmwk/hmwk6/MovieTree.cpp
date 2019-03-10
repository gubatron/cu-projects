#include <utility>

#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"

////////////////////////////////////////////////////////////////
// Helper functions
////////////////////////////////////////////////////////////////
std::istream &safeGetline(std::istream &is, std::string &t) {
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf *sb = is.rdbuf();

    for (;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if (sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case std::streambuf::traits_type::eof():
                // Also handle the case when the last line has no line ending
                if (t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char) c;
        }
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

    while (safeGetline(filein, line)) {
        std::stringstream linestream(line);

        std::string rankingString;
        getline(linestream, rankingString, ',');
        try {
            ranking = stoi(rankingString);
        } catch (std::invalid_argument &e) {
            std::cout << "invalid ranking argument: " << rankingString << std::endl;
            break;
        }

        getline(linestream, title, ',');

        std::string yearString;
        getline(linestream, yearString, ',');
        try {
            year = stoi(yearString);
        } catch (std::invalid_argument &e) {
            std::cout << "invalid year argument: " << yearString << std::endl;
            break;
        }

        std::string ratingString;
        getline(linestream, ratingString, ',');
        try {
            rating = stof(ratingString);
        } catch (std::invalid_argument &e) {
            std::cout << "invalid rating argument: " << ratingString << std::endl;
            break;
        }

        movieTree->addMovie(ranking, title, year, rating);
    }

    filein.close();
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
            std::cout << " >> " << tmp->head->title << " " << tmp->head->rating << std::endl;
            tmp->head = tmp->head->next;
        }
        inorder(tmp->rightChild);
    }
}


void insertSorted(TreeNode *treeNode, LLMovieNode *movieNode) {
    // When list is empty, add a new node.
    if (treeNode->head == nullptr) {
        treeNode->head = movieNode;
        return;
    }

    auto current = treeNode->head;
    LLMovieNode *prev = nullptr;

    // while not the last one
    while (current->next != nullptr) {
        prev = current;
        // insert in front
        if (current->next->title < movieNode->title) {
            current = current->next;
        }
        movieNode->next = current->next;
        prev->next = movieNode; // maybe current->next = movieNode??
        return;
    }
    // we have a one element list
    if (current == treeNode->head) {
        // is element smaller or bigger?
        // BIGGER
        if (movieNode->title > current->title) {
            current->next = movieNode;
            return;
        }
            // SMALLER, new node becomes the head!
        else {
            treeNode->head = movieNode;
            movieNode->next = current;
            current->next = nullptr;
        }
    }
        // current moved to the end of the list
    else {
        // add bigger at the end
        if (movieNode->title > current->title) {
            current->next = movieNode;
        }
            // add smaller second to last
        else {
            movieNode->next = current;
            prev->next = movieNode; // prev may be null...
        }
    }
}

void deleteLLNode(TreeNode *treeNode, LLMovieNode *movieNode) {
    auto curr = treeNode->head;
    TreeNode *prev = nullptr; // for 1st node, there is no previous


    // visit each node maintaining a ptr to prev node we just visited
    for (curr = treeNode->head; curr != nullptr; curr = curr->next) {
        if (curr->title == movieNode->title) {
            // found it
            // fix beginning pointer
            movieNode = curr->next;
        } else {
            // fix previous node's next to skip over removed node
            prev->head->next = curr->next;
        }
        // deallocate node
        delete curr;
        return;
    }

}


////////////////////////////////////////////////////////////////
// Class functions
////////////////////////////////////////////////////////////////
MovieTree::MovieTree() { root = nullptr; }

MovieTree::~MovieTree() {
    // TODO build destructor
}

// print in alphabetical order of titles
void MovieTree::printMovieInventory() {
    // movies are already sorted alpha as they're added to the linked lists
    inorder(root);
}

// adds movies to linked lists
// sort into alpha as they enter their respective linked lists
void MovieTree::addMovie(int ranking, std::string title, int year, float rating) {
    char titleChar = title[0];
    auto newMovieNode = new LLMovieNode();
    newMovieNode->ranking = ranking;
    newMovieNode->title = std::move(title);
    newMovieNode->year = year;
    newMovieNode->rating = rating;
    newMovieNode->next = nullptr;

    // we don't use title, because we moved it
    // Add node to the TREE based on titleChar of the movie - TreeNode
    TreeNode *curr = root;
    TreeNode *prev = nullptr;

    if (root == nullptr) {
        root = new TreeNode();
        root->titleChar = titleChar;
        insertSorted(root, newMovieNode);
        return;
    } else {
        while (curr != nullptr) {
            prev = curr;

            if (titleChar == curr->titleChar) {
                // we found a node that already has a list of movies
                break;
            }

            if (titleChar < curr->titleChar) {
                curr = curr->leftChild;
            } else {
                curr = curr->rightChild;
            }
        }

        // found last element in the correct direction, let's insert
        // the new TreeNode POINTER (tmp) based on it's tilteChar left or right
        if (prev != nullptr) {
            // There's already a node with a list of movies for this letter
            if (titleChar == prev->titleChar) {
                insertSorted(prev, newMovieNode);
            }
                // We have to add a new node, either left or right
            else {
                // create the new TREE node
                auto tmp = new TreeNode();
                tmp->titleChar = titleChar;
                tmp->parent = prev;
                tmp->leftChild = nullptr;
                tmp->rightChild = nullptr;

                // attach new TREE node to the end either left or right
                // depending on the letter
                if (titleChar < prev->titleChar) {
                    prev->leftChild = tmp;
                } else if (titleChar > prev->titleChar) {
                    prev->rightChild = tmp;
                }

                insertSorted(tmp, newMovieNode);
            }

        }
    }
}

void MovieTree::deleteMovie(std::string title) {
    TreeNode *treeNode = nullptr;
    auto curr = treeNode->head;

    // at the end of the list?
    if (curr == nullptr) return;

    // is current node the one to be deleted?
    if (curr->title == title) {
        LLMovieNode *tmp;
        tmp = curr->next; // save next pointer in the tmp
        delete curr;
        return;
    }
    // check rest of list, fixing next pointer in case the next node is the one removed
    return;

//    // search through tree for the first letter, search through list in alpha for movie
//    TreeNode *curr = root;
//    TreeNode *prev = nullptr;
//
//    // if List under titleChar ends up empty, delete treeNode
//    // treeNode is empty, delete treeNode
//    if (root == nullptr) {
//        TreeNode *tmp = root;
//        tmp->parent = prev; // is this necessary?
//        root = root->parent; // my new root is the parent of tmp, now I can delete tmp
//        delete tmp;
//    }// not sure if ^^^^ makes sense...
//
//    /*delete head of LL*/
//    LLMovieNode *left = LLsearch(title);
//    else { /*either tail node or middle node*/
//
//    }
//

    // if found, delete
    // if movie does not exist, print:
    std::cout << "Movie: " << title << " not found, cannot delete." << std::endl;
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