/**
 * Think of strings as arrays
 * string s; 
 * s[1];
 * 
 * 
 * int main(void){
     int arrayOfIntegersA[4]; // gives array of 4 values but values are garbage
     int arrayOfIntegersB[4] = {65,32,1,5};
     int arrayOfIntegers[ ] = {65,32,1,5}; // same as above
     int arrayOfIntegers[3] = {65,32,1,5}; // gives error, too many initializers
     
     for(int i=0; i<3; i++){
         cout << arrayOfIntegersB[i] << " ";   // returns numbers in array
         // If you do i<6, you go too far and it'll fill in the rest of spaces with 0
     }
 }