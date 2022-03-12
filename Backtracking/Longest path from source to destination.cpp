#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxlen=0;
const int M=10,N=10;
vector<int> delx = {0,0,1,-1};
vector<int> dely = {1,-1,0,0};
vector<pair<int,int>> path={make_pair(0,0)},maxpath;

void backtrack(int mat[M][N], int sx, int sy, int dx, int dy, int L)
{
    if ( sx==dx and sy==dy ) {
        if ( L>maxlen ) {
            maxpath = path;
            maxlen = L;
        }
        return;
    }
    if ( sx<0 or sx>=M or sy<0 or sy>=N or not mat[sx][sy] ) {
        return;
    }
    mat[sx][sy] = 0;
    for ( int i=0; i<delx.size(); i++ ) {
        path.push_back(make_pair(sx+delx[i],sy+dely[i]));
        backtrack(mat,sx+delx[i],sy+dely[i],dx,dy,L+1);
        path.pop_back();
    }
    mat[sx][sy] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int mat[M][N] = 
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
		{ 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
	};
    backtrack(mat,0,0,5,7,0);
    cout << "Traversal sequence: " << '\n';
    for (auto it=maxpath.begin(); it!=maxpath.end(); it++ ) {
        cout << it->first << ',' << it->second << " -> ";
    }
    cout << "Finished\n";
    cout << "Length of Longest Route excluding source: " << maxlen << '\n';
    return 0;
}
