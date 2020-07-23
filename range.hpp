//Created by yarden && shani on 09/06/2020

#pragma once

namespace itertools{
    
    class range{
        int num1, num2;

    public:
        range(int n1, int n2): num1(n1), num2(n2){}

        class iterator{
            int value;
            
        public:
            iterator(int v): value(v) {};

            ///// operators /////
            
            iterator& operator=(const iterator& other){
                if(this != &other) this->value = other.value;
                return *this; // *this caz we return reference 
            }

            bool operator==(const iterator& other) {
                return (value == other.value); // check if the values equals
            }

            bool operator!=(const iterator& other) {
                return (value != other.value); // check if the values different
            }

            // operator ++i
            iterator& operator++(){
                ++value; // adding +1 to value
                return *this; // return the value after adding 
            }

            // operator i++
            iterator operator++(int){
                iterator iter = *this; // save the current value
                value++; // adding +1 to value
                return iter; // return the value before adding 
            }

            int operator*(){ // return the value 
                return value;
            }
        };

        // iterators of class range, "begin" return the beginning of the range (num1) and "end" return the end of the range (num2)
        iterator begin() { return iterator(num1); } // begin itarator is field of the class range
        iterator end() { return iterator(num2); } // end itarator is field of the class range
        typedef int	value_type; // value_type is field of the class range- its the type of element that we running on the container
    };
}
