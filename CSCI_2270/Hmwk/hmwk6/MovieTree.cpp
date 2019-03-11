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
    float rating;

    int lineNum = 1;
    while (safeGetline(filein, line)) {
        std::stringstream linestream(line);

        if (line == "") {
            continue;
        }

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
        lineNum++;
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
        auto movie = tmp->head;
        while (movie != nullptr) {
            // print linked list
            std::cout << " >> " << movie->title << " " << movie->rating << std::endl;
            movie = movie->next;
        }
        inorder(tmp->rightChild);
    }
}

void insertSorted(TreeNode *treeNode, LLMovieNode *movieNode) {
    // if list is empty, this becomes the head
    if (treeNode->head == nullptr) {
        treeNode->head = movieNode;
        return;
    }

    // if it's smaller than the head,
    // new node becomes head and points next to the old head
    if (movieNode->title < treeNode->head->title) {
        auto oldHead = treeNode->head;
        treeNode->head = movieNode;
        movieNode->next = oldHead;
        return;
    }

    auto current = treeNode->head;
    auto next = treeNode->head->next;

    // we scan either until the end of the list
    // or when we find a node smaller than the new one
    while (next != nullptr && next->title < movieNode->title) {
        current = current->next;
        next = current->next;
    }

    current->next = movieNode;
    movieNode->next = next;
}

// This function is called because we know the node's list of movies is empty, no movie deletion needed here.
void tryDeleteTreeNodeIfEmpty(TreeNode *root, TreeNode *movieNode) {
    if (movieNode->head != nullptr) {
        // movieNode has elements on the list, we don't need to re-arrange the tree
        return;
    }
    if (movieNode->leftChild == nullptr && movieNode->rightChild == nullptr) {
        if (movieNode->parent != nullptr) {
            auto parent = movieNode->parent;
            if (parent->leftChild == movieNode) {
                parent->leftChild = nullptr;
            } else if (parent->rightChild == movieNode) {
                parent->rightChild = nullptr;
            }
        }
        delete movieNode;
        return;
    }

    // If we have a left child
    if (movieNode->leftChild != nullptr && movieNode->rightChild == nullptr) {
        auto parent = movieNode->parent;

        if (parent != nullptr) {
            // I'm my dad's left child, point my dad's left to my left child
            if (parent->leftChild == movieNode) {
                parent->leftChild = movieNode->leftChild;
            } else if (parent->rightChild == movieNode) {
                parent->rightChild = movieNode->leftChild;
            }
        }

        // left child should know who is his new parent
        movieNode->leftChild->parent = parent;
        delete movieNode;
    }
        // if we have a right child
    else if (movieNode->rightChild != nullptr && movieNode->leftChild == nullptr) {
        auto parent = movieNode->parent;

        if (parent != nullptr) {
            if (parent->leftChild == movieNode) {
                parent->leftChild = movieNode->rightChild;
            } else if (parent->rightChild == movieNode) {
                parent->rightChild = movieNode->rightChild;
            }
        }

        // right child should know who is his new parent!
        movieNode->rightChild->parent = parent;
        delete movieNode;
    }
        // got two kids
    else if (movieNode->leftChild != nullptr && movieNode->rightChild != nullptr) {
        // By convention, we'll make left child the master, right the slave
        auto masterChild = movieNode->leftChild;
        auto slaveChild = movieNode->rightChild;


        // let's decide where the right child will be as a child of the left.
        if (slaveChild->titleChar < masterChild->titleChar) {
            masterChild->leftChild = slaveChild;
        } else {
            masterChild->rightChild = slaveChild;
        }

        masterChild->parent = movieNode->parent;


        if (masterChild->parent != nullptr) {
            if (masterChild->parent->leftChild == movieNode) {
                masterChild->parent->leftChild = masterChild;
            } else {
                masterChild->parent->rightChild = masterChild;
            }
        }

        delete movieNode;
    }
}

TreeNode *getMin(TreeNode *T) {
    if (T == nullptr) return nullptr;
    else {
        if (T->leftChild == nullptr) return T;
        else return getMin(T->leftChild);
    }
}

void tryDeleteTreeNodeIfEmptyMovies(TreeNode *root, TreeNode *movieNode) {
    if (root == 0) return;
    else {
        if (movieNode->titleChar < root->titleChar) return tryDeleteTreeNodeIfEmptyMovies(root->leftChild, movieNode);
        else if (movieNode->titleChar > root->titleChar)
            return tryDeleteTreeNodeIfEmptyMovies(root->rightChild, movieNode);
        else {
            // remove value that is equal to the key
            // 4 cases
            // 1. Have no leftChild or rightChild child
            if (root->leftChild == nullptr && root->rightChild == nullptr) {
                delete root;
            }
                // 2. Only have a leftChild child
            else if (root->leftChild != nullptr && root->rightChild == nullptr) {
                TreeNode *tmp = root;
                delete tmp;
            }
                // 3. Only have a rightChild child
            else if (root->leftChild == nullptr && root->rightChild != nullptr) {
                TreeNode *tmp = root;
                delete tmp;
            }
                // 4. Have both left and right children
            else {
                TreeNode *to_replace = getMin(root->rightChild);
                root = to_replace;
                tryDeleteTreeNodeIfEmptyMovies(root->rightChild, to_replace);
            }
        }
    }
}


////////////////////////////////////////////////////////////////
// Class functions
////////////////////////////////////////////////////////////////
MovieTree::MovieTree() {
    root = nullptr;
}

MovieTree::~MovieTree() {
    if (root != nullptr && root->head != nullptr) {
        auto current = root->head;
        while (current != nullptr) {
            auto toDelete = current;
            current = current->next;
            if (toDelete != nullptr) {
                delete toDelete;
            }
        }
    }
    if (root != nullptr) {
        delete root;
    }
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
        // the new TreeNode POINTER (tmp) based on it's titleChar left or right
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
    // find node with first letter of title
    char titleChar = title[0];

    auto movieNode = root;

    // scan the tree for the right TreeNode
    while (movieNode != nullptr && movieNode->titleChar != titleChar) {
        if (titleChar < movieNode->titleChar) {
            movieNode = movieNode->leftChild;
        } else {
            movieNode = movieNode->rightChild;
        }
    }

    // could not find a TreeNode with that letter
    if (movieNode == nullptr || movieNode->head == nullptr) {
        std::cout << "Movie: " << title << " not found, cannot delete." << std::endl;
        return;
    }

    auto current = movieNode->head;
    auto next = movieNode->head->next;

    // the movie we're looking for is at the head
    if (current->title == title) {
        //delete and relink
        delete current;
        movieNode->head = movieNode->head->next;
        tryDeleteTreeNodeIfEmptyMovies(root, movieNode);
        return;
    }

    // look for the movie along the list
    while (next != nullptr && next->title != title) {
        current = current->next;
        next = current->next;
    }

    // got to the end of the list and didn't find the movie
    if (next == nullptr) {
        std::cout << "Movie: " << title << " not found, cannot delete." << std::endl;
        return;
    }

    // we found it, and it's the next one
    current->next = next->next;
    delete next;

    tryDeleteTreeNodeIfEmptyMovies(root, movieNode);
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
