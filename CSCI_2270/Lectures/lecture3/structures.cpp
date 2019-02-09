#include<iostream>
void main(int argc, char* argv[]) {
  struct address {
  long id; // unique ID: 1614011140000
  std::string name; // Name: Ashutosh Trivedi
  std::string phone; //Phone number: (720) 707-9663
  std::string email; //ashutosh.trivedi@gmail.com
  std::string street; //4141 Spruce Street
  std::string city; // Philadelphia
  std::string state; //PA
  int zip; // 19104
  float lat; //39.948610
  float lon; //-75.177830
};


// Structure is useful for storing an aggregation of element.
// Unlike an array, the elements of a structure may be of different types.
// – Each element of field is referred by a given name.

int main(int argc, char* argv[]) {
  struct address {
  long id; // unique ID: 1614011140000
  std::string name; // Name: Ashutosh Trivedi
  std::string phone; //Phone number: (720) 707-9663
  std::string email; //ashutosh.trivedi@gmail.com
  std::string street; //4141 Spruce Street
  std::string city; // Philadelphia
  std::string state; //PA
  int zip; // 19104
  float lat; //39.948610
  float lon; //-75.177830
  };
  address myadress = {1614011140000, "Ashutosh Trivedi", "(720) 707-9663", "ashutosh.trivedi@gmail.com", "
  4141 Spruce Street","Philadelphia","PA",19104,39.948610,-75.177830};
  std::cout << myadress.name << " lives in " << myadress.state << std::endl;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////

// CONSTRUCTORS

int main(int argc, char* argv[]) {
struct Address {
long id; // unique ID: 1614011140000
std::string name; // Name: Ashutosh Trivedi
std::string phone; //Phone number: (720) 707-9663
std::string email; //ashutosh.trivedi@gmail.com
std::string street; //4141 Spruce Street
std::string city; // Philadelphia
std::string state; //PA
int zip; // 19104
float lat; //39.948610
float lon; //-75.177830
Address() {};
 Address(long _id, std::string _name, std::string _phone, std::string _email, std::string _street, std::
string _city, std::string _state, int _zip,float _lat, float _lon) {
id = _id;
name = _name;
phone = _phone;
email = _email;
street = _street;
city = _city;
state = _state;
zip = _zip;
lat = _lat;
lon = _lon;
}

///////////////////////////////////////////////////////////////////////////////

// MEMBER FUNCTIONS

struct Address {
long id; // unique ID: 1614011140000
std::string name; // Name: Ashutosh Trivedi
std::string phone; //Phone number: (720) 707-9663
std::string email; //ashutosh.trivedi@gmail.com
std::string street; //4141 Spruce Street
std::string city; // Philadelphia
std::string state; //PA
int zip; // 19104
float lat; //39.948610
float lon; //-75.177830
Address() {};
Address(long _id, std::string _name, std::string _phone, std::string _email, std::string _street, std::
string _city, std::string _state, int _zip,float _lat, float _lon) {
id = _id;
name = _name;
phone = _phone;
email = _email;
street = _street;
city = _city;
state = _state;
zip = _zip;
lat = _lat;
lon = _lon;
}
void prettyPrint() {
std:: cout << name << std::endl;
std::cout << " Id: \n " << id << std::endl;
std::cout << " Ph: \n " << phone << std::endl;
std::cout << " E-mail: \n " << email << std::endl;
std::cout << " Address: "<< std::endl;
std::cout << " "<< street << ", " << city << ", " << state << "-" << zip << std::endl;
std::cout << " Location: ("<< lat << ", " << lon << ")" << std::endl;
std::cout<< "_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/"
<< std::endl;
