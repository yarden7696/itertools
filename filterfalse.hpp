//Created by yarden && shani on 09/06/2020
#pragma once
#include <iostream>
#include <vector>

namespace itertools{

    template<typename sign, typename container>

    class filterfalse {

        sign _s;
        container _container;
        typedef typename container::value_type value_type;

    public:
        filterfalse(sign s, container cont): _s(s), _container(cont){}

        class iterator{
            typename container::iterator _begin;
            typename container::iterator _end;
            sign _s;

        public:
            iterator(typename container::iterator iter, typename container::iterator end, sign s) : _begin(iter), _end(end), _s(s){
                while (_begin != _end && _s(*_begin))
                    ++_begin;
            }

            iterator& operator=(const iterator& it){
                if(this != &it) {
                    this->_begin = it._begin;
                    this->_end = it._end;
                    this->_s = it._s;
                }
                return *this;
            }


            bool operator==(const iterator& it) {
                return _begin == it._begin;
            }

            bool operator!=(const iterator& it) {
                return _begin != it._begin;
            }

            iterator& operator++(){
                do{
                    ++_begin;
                } while (_begin != _end && _s(*_begin));
                return *this;
            }

            iterator operator++(int){
                iterator iter = *this;
                ++(*this);
                return iter;
            }

            value_type operator*(){
                return *_begin;
            }
        };

        iterator begin(){ return iterator(_container.begin(), _container.end(), _s); }
        iterator end(){ return iterator(_container.end(), _container.end(), _s); }
    };
}

