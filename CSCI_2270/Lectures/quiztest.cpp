#include <iostream>

//void reset(int *ip) {
//    ip = 0;
//}
//
//int main() {
//    int i = 100;
//    int *p = &i;
//    reset (p);
//    std::cout << "i : " << *p << std::endl;
//}


//int main(){
//    int a[] = {1, 3, 5, 7};
//    std::cout << a[3] << std::endl; // 7
//    std::cout << a[0] << std::endl; // 1
//    std::cout << *a+2 << std::endl; // 3
//    std::cout << *(a+2) << std::endl; // 5
//    std::cout << *(a+3) << std::endl; // 7
//}



//int main() {
//    int a = 100, b = 200, c = 50, *pa = &a, *pb = &b, *pc = &c;
//    *pa = *pa + *pb + *pc;
//    *pb = 100;
//    pb = pa;
//    pc = pb;
//    std::cout << *pa << "," << *pb << "," << *pc << std::endl;
//}


int main() {
    int m = 1, n = 2, *p = &m, *q = &n, *r;
    r = p; p = q; q = r;
    std::cout << m << "," << n << "," << *p << "," << *q << std::endl;
}