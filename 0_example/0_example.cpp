#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//入力
void prints()
{
    cout << "s" << endl;
}

int main()
{
    //cinでファイルから読込
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    //cinの高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    

    //通常の入力
    int a,b,c,d,e;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cout << a << "," << b << ","<< c << ","<< d << ","<< e << endl;

    //数指定の入力
    int N;
    cin >> N;
    cout << N << endl;

    int n[N];
    for(int i = 0; i < N; i++){
        cin >> n[i];
        cout << n[i] << flush;
        i != N-1 ? cout << "," : cout << endl; ///一連の数字をカンマ区切りにし最後に改行を加える
    }

    //縦横の個数指定の入力
    int H,W;
    cin >> H;
    cin >> W;
    cout << H << "," << W << endl;

    int box[H][W];
    for(int i = 0; i < H; i++){
        for(int k = 0; k < W; k++){
        cin >> box[i][k];
        cout << box[i][k] << flush;
        k != W-1 ? cout << "," : cout << endl; //一連の数字をカンマ区切りにし最後に改行を加える
        }
    }

    //カンマ区切りの読込
    int f,g,h;
    cin >> f;
    cin.ignore();
    cin >> g;
    cin.ignore();
    cin >> h;
    cout << f << "," << g << ","<< h << endl;
    
    //文字列の読込
    string str[3];
    cin >> str[0];
    cin >> str[1];
    cin >> str[2];
    cout << str[0] << "," << str[1] << ","<< str[2] << endl;

    return 0;
}