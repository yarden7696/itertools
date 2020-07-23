//Created by yarden && shani on 09/06/2020

#pragma once
#include <iostream>
#include <vector>

namespace itertools{

    template<typename container1, typename container2> class compress {

        container1 _container1; // the container that we get(could be range/ vector/ array...)
        container2 _container2; // boolean container
        typedef typename container1::value_type value_type; // the type of the elements that in the container1

    public:
        //  compress CONSTRUCTOR
        compress(container1 cont1, container2 cont2): _container1(cont1), _container2(cont2){}

        class iterator{
            
            typename container1::iterator _begin; //we take from the container1 the begin iterator
            typename container1::iterator _end; //we take from the container1 the end iterator
            typename container2::iterator _begin2; //we take from the container2 the begin iterator

        public:
            //  iterator CONSTRUCTOR
            iterator(typename container1::iterator begin, typename container1::iterator end, typename container2::iterator begin2):
            _begin(begin), _end(end), _begin2(begin2) {
                while (_begin != _end && !(*_begin2)) { //In this while loop we looking for the first "True" in the container
                    ++_begin;
                    ++_begin2;
                }
            }

            iterator& operator=(const iterator& other) {  // now this.begin points to where *other.begin points
                if(this != &other) this->_begin = other._begin;
                return *this;
            }

            bool operator==(const iterator& other) {  // checks if other and this points to the same place
                return _begin == other._begin;
            }

            bool operator !=(const iterator& other) { // checks if other and this points to the diffrent place
                return _begin != other._begin;
            }

            iterator& operator++() { // note: _begin and _begin2 points to the first element that is True
                do{
                    ++_begin;
                    ++_begin2;
                  } 
                while (_begin!=_end && !(*_begin2)); // running on the container1 and container2 until we get the next True
                return *this; // return the element that we found
            }

            value_type operator*(){
                return *_begin;
            }
            
        }; // End class iterator

        iterator begin(){return iterator(_container1.begin(), _container1.end(), _container2.begin()); } // field of the class accumulate
        iterator end(){ return iterator(_container1.end(), _container1.end(), _container2.end()); } // field of the class accumulate
    }; // End class compress
}


