#include<iostream>
#include<vector>
using namespace std;

typedef long long llint;
const llint maxn = 2000;
const int INF = 1e9 + 10;
//
llint b[maxn][maxn], counter=1, top[maxn], index_top[maxn];
vector<int> saf[maxn], boroToSaf;
int tedad_saf = 0;


int main(){

    int n,cor_place, a[maxn], a_sorted[maxn], a_random[maxn], operations[maxn], x ;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        int bestValue = -1, bestIndex = -1;
        for (int j = 0; j < tedad_saf; j++){
            if (saf[j].back() <= a[i] && saf[j].back() > bestValue)
                bestValue = saf[bestIndex = j].back();
        }

        if (bestIndex == -1){
            saf[tedad_saf].push_back(a[i]);
            boroToSaf.push_back(tedad_saf);
            tedad_saf++;
        }
        else {
            saf[bestIndex].push_back(a[i]);
            boroToSaf.push_back(bestIndex);
        }
    }

    cout << tedad_saf << " " << 2 * n << endl;

    for (int i = 0; i < n; i++)
        cout << 1 << " " << boroToSaf[i] + 1 << endl;

    for (int i = 0; i < n; i++){
        int min_value = INF, min_index = -1;
        for (int j = 0; j < tedad_saf; j++)
            if (saf[j].size() > 0 && saf[j][0] < min_value)
                min_value = saf[min_index = j][0];
        cout << 2 << " " << min_index + 1 << endl;
        saf[min_index].erase(saf[min_index].begin() + 0);
    }

}

