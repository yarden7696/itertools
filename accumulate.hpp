//Created by yarden && shani on 09/06/2020

#pragma once

namespace itertools{
    typedef struct{
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } oper_plus;

    template <typename container, typename sign = oper_plus>

    class accumulate{
        container _container;
        sign _sign;
        typedef typename container::value_type value_type;

    public:
        explicit accumulate(container cont, sign s = oper_plus()) : _container(cont), _sign(s){}

        class iterator{
            typename container::value_type _data;
            typename container::iterator _iter;
            typename container::iterator _end;
            sign _sign;

        public:
            explicit iterator(typename container::iterator iter, typename container::iterator end, sign s) : _iter(iter), _end(end), _sign(s){
                if(_iter != _end) _data = *iter;
            };

            iterator& operator=(const iterator& it){
                if(this != &it) {
                    this->_data = it._data;
                    this->_iter = it._iter;
                    this->_end = it._end;
                    this->_sign = it._sign;
                }
                return *this;
            };

            iterator& operator ++(){
                ++_iter;
                if(_iter != _end) _data = _sign(_data, *_iter);
                return *this;
            }

            iterator operator ++(int){
                iterator temp = *this;
                ++(*this);
                return temp;
            }

            bool operator !=(const iterator& it) {
                return (_iter != it._iter);
            }

            bool operator ==(const iterator& it) {
                return (_iter == it._iter);
            }

            auto operator *(){
                return _data;
            }
        };


        iterator begin(){ return iterator(_container.begin(), _container.end(), _sign); }
        iterator end(){ return iterator(_container.end(), _container.end(), _sign); }
    };
}
