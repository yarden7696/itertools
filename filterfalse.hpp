//Created by yarden && shani on 09/06/2020
#pragma once
#include <iostream>
#include <vector>

namespace itertools{

    template <typename sign, typename container> class filterfalse {

        sign _s; // The condition on every element in the container, whoever **dont** answer the condition will enter the result container
        container _container;  // the container that we get(could be range/ vector/ array...)
        typedef typename container::value_type value_type; // the type of the elements that in the container

    public:
        //  filterfalse CONSTRUCTOR
        filterfalse(sign s, container cont): _s(s), _container(cont){}

        class iterator {
            
            typename container::iterator _begin; //we take from the container the begin iterator(for example-if the container is range so _begin is num1)
            typename container::iterator _end; //we take from the container the end iterator(for example-id the container is range so _iter is num2)
            sign _s; // the condition on the container's elements

        public:
            //  iterator CONSTRUCTOR
            iterator(typename container::iterator begin, typename container::iterator end, sign s) : _begin(begin), _end(end), _s(s){
                while (_begin != _end && _s(*_begin)) //In this while loop we looking for the first element that return false to the condition
                    ++_begin;
            }

            iterator& operator=(const iterator& other){
                if(this != &other) {
                    this->_begin = other._begin;
                    this->_end = other._end;
                    this->_s = other._s;
                }
                return *this; // init this itarator with the values of "other itarator" and return *this 
            }


            bool operator==(const iterator& other) { // checks if other and this points to the same place
                return _begin == other._begin;
            }

            bool operator!=(const iterator& other) { // checks if other and this points to the diffrent place
                return _begin != other._begin;
            }

            iterator& operator++() {
                do { ++_begin; } 
                while (_begin != _end && _s(*_begin));
                return *this;
            }

//             iterator operator++(int){
//                 iterator iter = *this;
//                 ++(*this);
//                 return iter;
//             }

            value_type operator*(){
                return *_begin;
            }
        };

        iterator begin(){ return iterator(_container.begin(), _container.end(), _s); }
        iterator end(){ return iterator(_container.end(), _container.end(), _s); }
    };
}

