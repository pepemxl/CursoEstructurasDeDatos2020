#ifndef CLASS_PAIR_H
#define CLASS_PAIR_H

template<typename T1, typename T2> 
struct Pair{
    T1 first;
    T2 second;
    Pair();
    Pair(const T1 &val1,const T2 &val2);
    Pair<T1, T2>& operator= (const Pair<T1, T2>& pr);
    bool operator== (Pair<T1, T2> const & pr);
    bool operator!= (Pair<T1, T2> const & pr);
    bool operator>= (Pair<T1, T2> const & pr);
    bool operator<= (Pair<T1, T2> const & pr);
    void swap(Pair<T1, T2>  & pr);
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(){

}

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1 &val1,const T2 &val2){
    first = val1;
    second = val2;
}

template <typename T1, typename T2>
Pair<T1, T2> make_pair(T1 key,T2 value){
    return Pair<T1, T2>(key, value);
}

template <typename T1, typename T2>
Pair<T1, T2>& Pair<T1, T2>::operator= (const Pair<T1, T2>& pr){
        return make_pair<T1, T2>(pr.first, pr.second);
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator== (Pair<T1, T2> const & pr){
    return (this->first == pr.first && this->second == pr.second);
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator!= (Pair<T1, T2> const & pr){
    return (this->first != pr.first || this->second != pr.second);
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator>= (Pair<T1, T2> const & pr){
    if( this->first > pr.first ){
        return true;
    }
    if ( this->first == pr.first  && this->second >= pr.second){
        return true;
    }
    return false;
}

template <typename T1, typename T2>
bool Pair<T1, T2>::operator<= (Pair<T1, T2> const & pr){
    return !(*this >= pr);
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const Pair<T1, T2>& pr)
{
    os << "(" << pr.first << ", " << pr.second << ")";
    return os;
}

template <typename T1, typename T2>
void Pair<T1, T2>::swap(Pair<T1, T2> & pr){
    T1 val1 = pr.first;
    T2 val2 = pr.second;
    pr.first  = this->first;
    pr.second = this->second;
    this->first  = val1;
    this->second = val2;
}

#endif
 