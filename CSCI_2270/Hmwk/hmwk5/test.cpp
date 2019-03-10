//
// Created by Nicole Leon on 3/3/2019.
//
#include <iostream>

//int myFunc(int n) {
//    int result = 0;
//    if (n<=0) return 0;
//    if (n==1) return 1;
//    result = myFunc(n-1) + myFunc(n-3);
//    return result;
//}
//int main(){
//    std::cout << myFunc(4);
//    return 0;
//}

//void fun(int n){
//    if(n > 0) {
//        fun(n-1);
//        printf("%d ", n);
//        fun(n-1);
//    }
//    else
//        return;
//}
//int main(){
//    fun(3);
//    return 0;
//}

int findSum(TreeNode * root, int depth)
{
    if(root != NULL)
    {
        int rightSum = findSum(root->right, depth + 1);
        int leftSum = findSum(root->left, depth + 1);
        cout << root->key;
        if (depth != 0)
        {
            cout << " ";
        }
        return rightSum + leftSum + root->key;
    }
    else
        return 0;
}

int main() {
    int a = [19, 21, 17, 14, 15, 7, 12];
    findSum(a,0);
}