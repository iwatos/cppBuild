
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/range/algorithm.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

void print() { std::cout << std::endl; }

template <class Head, class... Tail> void print(Head &&head, Tail &&... tail) {
    std::cout << head;
    if(sizeof...(tail) != 0)
        std::cout << " ";
    print(std::forward<Tail>(tail)...);
}

template <class T> void print(std::vector<T> &vec) {
    for(auto &a : vec) {
        std::cout << a;
        if(&a != &vec.back())
            std::cout << " ";
    }
    std::cout << std::endl;
}

template <class T> void print(std::vector<std::vector<T>> &df) {
    for(auto &vec : df) {
        print(vec);
    }
}

void io() {
    //通常の入力
    std::cout << std::endl << "通常入力:";
    int a, b, c;
    std::cin >> a >> b >> c;
    print(a, b, c);

    //数指定の入力
    std::cout << std::endl << "数指定の入力:";
    int n;
    std::cin >> n;
    print(n);

    std::vector<int> array(n);
    for(int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    print(array);

    //数指定の入力（二次元）
    std::cout << std::endl << "数指定の入力(二次元):";
    int x, y;
    std::cin >> x >> y;
    print(x, y);

    std::vector<std::vector<int>> aot(
        x, std::vector<int>(y)); // arrayOfTwoDimension
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            std::cin >> aot[i][j];
        }
    }
    print(aot);

    //カンマ区切りの読込
    std::cout << std::endl << "カンマ区切りの読み込み:";
    std::string str;
    std::cin >> str;

    std::vector<std::string> strs;
    boost::algorithm::split(strs, str, boost::is_any_of(","));
    print(strs);
}

void vector() {
    // 初期化
    std::vector<int> vec;
    std::vector<int> vec1(10);            //要素数10
    std::vector<int> vec2(10, 5);         //要素数10,全ての要素の値5
    std::vector<int> vec3{1, 2, 3, 4, 5}; //要素の値指定
    std::vector<int> vec4(vec3);          //同じ内容の動的配列を生成
    int array[] = {6, 7, 8, 9, 10};
    std::vector<int> vec5(array, std::end(array)); //配列から生成
    std::vector<std::vector<int>> vec6{{1, 2, 3}, {4, 5, 6}}; //二次元配列

    print(vec1);
    print(vec2);
    print(vec3);
    print(vec4);
    print(vec5);
    print(vec6);

    //値の参照、代入
    vec = vec3;
    vec[0] = 100;                         //[0]を参照,代入
    vec.at(0);                            //[0]を参照
    vec.front();                          //最初の要素
    vec.back();                           //最後の要素
    for(int i = 0; i < vec.size(); i++) { //全要素参照
        vec[i];
    }
    for(const auto v : vec) { //全要素参照
        v;
    }
    for(auto itr = vec.begin(); itr != vec.end(); ++itr) { //全要素参照
        *itr;
    }

    //要素の追加
    vec.push_back(1);               //末尾に追加
    vec.insert(vec.begin() + 2, 3); //[2]に7を挿入

    //要素の削除
    vec.pop_back();             //最後の要素削除
    vec.erase(vec.begin() + 2); //[2]の要素を削除
}

void map() {
    //初期化
    std::map<std::string, int> map;
    std::map<std::string, int> map1{{"A", 1}, {"B", 2}};
    std::map<std::string, int> map2(map1);

    //参照、代入
    map["A"];       //参照　→　1
    map["A"] = 100; //代入
    map["Z"];       //設定されていないので0が表示

    for(auto m : map) { //全要素参照
        m.first;
        m.second;
    }
    for(auto itr = map.begin(); itr != map.end(); ++itr) { //全要素参照
        itr->first;                                        // キーを表示
        itr->second;                                       //値
    }

    //要素の追加
    map["C"] = 3;                       // D要素を値4で追加
    map.insert(std::make_pair("D", 4)); // D要素を値4で追加

    //要素の削除
    map.erase(map.find("Z")); // Z要素削除
}
void set() {
    //初期化
    std::set<int> set;
    std::set<int> set1{3, 1, 4, 3}; //重複分削除され常にソートされている状態
    std::set<int> set2(set1);

    //参照
    set = set1;
    auto itr = set.begin();
    *itr;
    for(auto x : set) {
        x; // 要素を順に表示
    }
    set.find(10);

    //追加
    set.insert(5);

    //削除
    set.erase(1);
}

void stack() {

    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl;

    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
}

void queue() {
    std::queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.front() << std::endl;

    s.pop();
    std::cout << s.front() << std::endl;
    s.pop();
    std::cout << s.front() << std::endl;
    s.pop();
}

void sort() {
    std::vector<int> v{5, 7, 356, 1, 43, 9};

    //昇順にソート
    std::sort(v.begin(), v.end());
    boost::sort(v); // boost使用
    print(v);

    //降順にソート
    std::sort(v.begin(), v.end(), std::greater<int>());
    print(v);
}

int main() {

    io();
    // vector();
    // map();
    // set();
    // stack();
    // queue();
    // sort();
}
