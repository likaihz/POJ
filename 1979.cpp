#include<cstdio>

using namespace std;

int W, H;
char tiles[20][20];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int DFS(int x, int y)
{
    int res = 0;

    for(int i = 0; i < 4; i++)
    {
        int newX = x+X[i], newY = y+Y[i];
        if(newX < H && newX >=0 && newY < W && newY >=0 && tiles[newX][newY] == '.'){        
            res++;
            tiles[newX][newY] = '#';
            res += DFS(newX, newY);
        }
    }

    return res;
    
}
int main()
{
    int startI, startJ, cntReach = 0;
    
    while(scanf("%d %d",&W, &H))
    {
        if(W == 0 && H == 0) break;
        getchar();
        cntReach = 0;
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++){
                scanf("%c", &tiles[i][j]);
                if(tiles[i][j] == '@')
                    startI = i, startJ = j;
            }
            getchar();
        }

        cntReach = 1 + DFS(startI, startJ);
        printf("%d\n", cntReach);
    }

    return 0;
}
