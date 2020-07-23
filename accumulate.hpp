//Created by yarden && shani on 09/06/2020

#pragma once

namespace itertools {
    
    typedef struct { // the default sign is adding two numbers a and b
        template <typename T> T operator ()(T a, T b) const {
            return a+b;
        }
    } oper_plus;

    
    template <typename container, typename sign = oper_plus> class accumulate { // the default is oper_plus
        
        container _container; // the container that we get(could be range/ vector/ array...)
        sign _sign; //  the default is "oper_plus", we can get any other sign
        typedef typename container::value_type value_type; // the type of the elements that in the container

    public:
        explicit accumulate(container cont, sign s = oper_plus()) : _container(cont), _sign(s){}

        class iterator{
            typename container::value_type _data; // take the type of elements in the container we get
            typename container::iterator _begin;//we take from the container the begin iterator(for example-if the container is range so _begin is num1) 
            typename container::iterator _end;//we take from the container the end iterator(for example-id the container is range so _iter is num2)
            sign _sign; // the sign that we get in line 14

        public:
            //constructor of iterator
            explicit iterator(typename container::iterator begin, typename container::iterator end, sign s) : _begin(begin), _end(end), _sign(s){
                if(_begin != _end) _data = *begin; // Initialize _data to the value of begin iterator (always init _data to the value in begin itarator)
            };

            iterator& operator=(const iterator& other){
                if(this != &other) {
                    this->_data = other._data;
                    this->_iter = other._begin;
                    this->_end = other._end;
                    this->_sign = other._sign;
                }
                return *this; // init this itarator with values of "other itarator" and return *this 
            };

            // operator ++i
            iterator& operator ++(){
                ++_begin; // now begin points to the next element
                if(_begin != _end) _data = _sign(_data, *_begin); // sigh is responsible for ++ i.
                //sigh gets the current value (_data) and the next value (*begin), made calculation operation and puts the result into _data.
                return *this; //When we do return *this it returns the updated _data that *begin points on it.
            }

            iterator operator ++(int){
                iterator temp = *this;
                ++(*this);
                return temp;
            }

            
            bool operator !=(const iterator& other) {
                return (_begin != other._begin); // checks if other and this points to the diffrent place
            }

            bool operator ==(const iterator& it) {
                return (_begin == it._begin);  // checks if other and this points to the same place
            }

            auto operator *(){
                return _data;
            }
        };


        iterator begin(){ return iterator(_container.begin(), _container.end(), _sign); } // Field of the class accumulate
        iterator end(){ return iterator(_container.end(), _container.end(), _sign); }  // Field of the class accumulate
    };
}
