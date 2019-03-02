//
// Created by Nicole Leon on 2/25/2019.
//

#include <iostream>
#include "MOVIETREE.HPP"

MovieTree::MovieTree() {
    // initialize any member variables of the class to default
    root = nullptr;
}

MovieTree::~MovieTree() {
    // free all memory that was allocated
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*Print every node in the tree in alphabetical order of titles*/
void MovieTree::printMovieInventory() {
    /* File format format:
     *      77,Witness for the Prosecution,1957,8.4
     *      <ranking>,<title>,<year>,<rating>
     * read through tree, alpha, print
    */

    MovieNode *m;
    //preorder(m); // traverses the tree
    std::cout << "Movie: " << preorder(m) << " " << m->rating << std::endl;

    // for every Movie node (m) in the tree
    //std::cout << "Movie: " << m->title << " " << m->rating << std::endl;
    // TODO CHECK THIS FUNCTION AND HELPER
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating) {
//    MovieNode m;
//    m.ranking = _ranking;
//    m.title = _title;
//    m.year = _year;
//    m.rating = _rating;
    MovieNode *tmp = new MovieNode(title);
    tmp->ranking = ranking;
    tmp->year = year;
    tmp->rating = rating;

    MovieNode *curr = root;
    MovieNode *prev;

    if (root == 0) {
        root = tmp;
        return;
    } else {
        while (curr != 0) {
            prev = curr;
            if (title < curr->parent) {
                curr = curr->leftChild;
            }
            else if (title == curr->parent) return;
            else curr = curr->rightChild;
        }
        if (title < prev->parent) {
            prev->leftChild = tmp;
        } else {
            prev->rightChild = tmp;
        }
    }//TODO what about all the other parameters.... CHECK THIS FUNCTION
}

void MovieTree::findMovie(std::string title) {
    MovieNode *tmp = root;

    while (tmp != nullptr) {
        if (tmp->parent == title) {
            std::cout << "Movie Info:" << std::endl;
            std::cout << "==================" << std::endl;
            std::cout << "Title :" << tmp->title << std::endl;
            std::cout << "Year :" << tmp->year << std::endl;
            std::cout << "Ranking:" << tmp->ranking << std::endl;
            std::cout << "rating :" << tmp->rating << std::endl;
            return;
        } else if (title < tmp->parent) {
            tmp = tmp->leftChild;
        }else {
            tmp = tmp->rightChild;
        }
    }
    std::cout << "Movie not found." << std::endl;
/*
     TODO how is this function different form search(title)
        EXPLAIN PROPER DIFFERENCE BETWEEN MOVIENODE AND MOVIETREE
*/
}

/*Print all the movies with a rating at least as good as rating
 that are newer than year in the preorder fashion*/
void MovieTree::queryMovies(float rating, int year) {
    MovieNode *m;
    std::cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << std::endl;
    if (preorder(m->title) >= m->rating && preorder(m->title) <= m->year ) {
        std::cout << m->title << "(" << m->year << ") " << m->rating << std::endl;
    }
} // TODO not sure how to make this make sense with preorder(*root)

void MovieTree::averageRating() {

}
///////////////////////////////////////////////////////////////////////////////
/*HELPER FUNCTIONS*/
///////////////////////////////////////////////////////////////////////////////
/* search tree
 * returns a pointer to the node with the given title
 * or nullptr if no such movie exists*/
MovieNode *search(std::string title) {
    MovieNode *tmp = root;

    while (tmp->ranking != nullptr) {
        if (tmp == title) {
            /*Yay we found the value*/
            return tmp;
        } else if (title < tmp->ranking) {
            /*Val is not in the right sub-tree*/
            /*if it is at all there, it must be in the left sub-tree*/
            tmp = tmp->leftChild;
        } else {
            tmp = tmp->rightChild;
        }
    }
    return nullptr;
}

// preorder to traverse tree and print
void preorder(MovieNode *root) {
    if (root != nullptr) {
        std::cout << root->title << " ";
        //std::cout << root->rating << " ";
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

// querypreorder
void querypreorder(MovieNode *root) {

}

void menu() {
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Quit" << endl;
}
///////////////////////////////////////////////////////////////////////////////
/*DRIVER FUNCTION*/
///////////////////////////////////////////////////////////////////////////////
void main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: incorrect number of arguments" << std::endl;
    }

    MovieTree T; // tree to store information to be read

    std::ifstream filein(argv[1]);
    if (filein.fail()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int ranking = 0;
    std::string title;
    int year = 0;
    float rating = 0.0;
    MovieTree movie;

    while (filein >> title >> )) {
        if (line != "") {

        }
    }

//
//    void fillTree( BinarySearchTree b)
//    {
//        string name;
//        int phonenumber;
//        Person p;
//        while(file >> name >> phonenumber)
//        {
//            p.setName(name);
//            p.setPhonenumber(phonenumber);
//            cout << p.getName() << "  " << p.getPhonenumber() << endl;
//            b.insert(p);
//        }
//        file.close();
//    }
//








    // Once I read the file, display menu
    std::string choice;
    std::string input;

    while (choice != "6") {
        menu();
        getline(cin,choice);
        choice = "";
        switch(coice) {
            case "1":
                std::cout << "Enter title: " << endl;
                movie.findMovie(getline(cin, input));
                break;
            case "2":
                std::cout << "Enter minimum rating: " << std::endl;
                std::string rating;
                rating = getline(cin,input);
                cout << "Enter minimum year:" << endl;
                std::string year;
                year = getline(cin,input);
                movie.queryMovies(stof(rating), stoi(year)); // todo can I do this for parameters?
                break;
            case "3":
                movie.printMovieInventory();
                break;
            case "4":
                movie.averageRating();
                break;
            case "5":
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "invalid input\n\n";
        }
    }
}