#include<iostream>
#include<string>
int main(){
  std::cout << "Please input a string, an integer, a character, and a float (space separated): \n";

  std::string w;
  int x;
  char y;
  float z;

  std::cin >> w;
  std::cin >> x;
  std::cin >> y;
  std::cin >> z;

  std::cout << "w= " << w << " x= " << x << " y=" << y << " z= " << z << std::endl;
  
  return 0;
}
