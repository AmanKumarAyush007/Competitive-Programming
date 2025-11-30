// debug.h

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const vector<A> &v);
template<typename A> ostream& operator<<(ostream &os, const set<A> &v);
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &v);
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &v);
template<typename A, typename B> ostream& operator<<(ostream &os, const unordered_map<A, B> &v);

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    cerr << t;
    if(sizeof...(v)) cerr << ", ";
    _print(v...);
}

template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template<typename A>
ostream& operator<<(ostream &os, const vector<A> &v) {
    os << '{';
    for (auto it = v.begin(); it != v.end(); ++it)
        os << (it != v.begin() ? ", " : "") << *it;
    return os << '}';
}

template<typename A>
ostream& operator<<(ostream &os, const set<A> &v) {
    os << '{';
    for (auto it = v.begin(); it != v.end(); ++it)
        os << (it != v.begin() ? ", " : "") << *it;
    return os << '}';
}

template<typename A>
ostream& operator<<(ostream &os, const multiset<A> &v) {
    os << '{';
    for (auto it = v.begin(); it != v.end(); ++it)
        os << (it != v.begin() ? ", " : "") << *it;
    return os << '}';
}

template<typename A, typename B>
ostream& operator<<(ostream &os, const map<A, B> &v) {
    os << '{';
    for (auto it = v.begin(); it != v.end(); ++it)
        os << (it != v.begin() ? ", " : "") << it->first << ": " << it->second;
    return os << '}';
}

template<typename A, typename B>
ostream& operator<<(ostream &os, const unordered_map<A, B> &v) {
    os << '{';
    for (auto it = v.begin(); it != v.end(); ++it)
        os << (it != v.begin() ? ", " : "") << it->first << ": " << it->second;
    return os << '}';
}
