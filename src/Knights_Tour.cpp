#include <iostream>
using namespace std;
int N;
int board[100][100];//Bang
//Tao mang duong di
int arr[8][2] = { {2,1}, {1,2}, {-1,2}, {-2,1},
                      {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };
bool isValid(int x, int y) {
    return ( x<N && y<N && board[x][y]==-1);
}
bool knight_tour(int x,int y,int moveCount) {
    if (moveCount==N*N) return true;//Base case
    for (int i=0;i<8;i++) {
    	//Xac dinh toa do vi tri kha nang tiep theo.
        int nextX = x + arr[i][0];
        int nextY = y + arr[i][1];
        if (isValid(nextX, nextY)) {
            board[nextX][nextY] = moveCount;
            if (knight_tour(nextX, nextY, moveCount + 1))  //De quy
			{return true;}
            board[nextX][nextY] = -1; // Quay lui
        }
    }
    return false;
}
// In bang NxN sau khi duoc danh dau
void printBoard() {
    for (int i=0;i<N; i++) {
        for (int j=0;j<N;j++) {
            cout<<board[i][j]<< " ";
        }
        cout<<endl;
    }
}

int main() {
	cin>>N;
    for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
    board[i][j]=-1;
    int x,y;
    cin>>x>>y;
    board[x][y] = 0;
    
    if (knight_tour(x,y,1)) {
        printBoard();
    } else {
        cout << "Khong tim thay duong di phu hop" << endl;
    }
    return 0;
}
