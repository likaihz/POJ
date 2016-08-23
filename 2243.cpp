#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

class Position
{
public:
    int x, y;
    int level;
    Position(int xx, int yy, int ll):x(xx), y(yy), level(ll) {};
    Position() {};
} Begin, End;

int minSteps;
int Dir[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
bool visited[8][8] = {false};

void BFS()
{
    queue<Position> Q;
    Q.push(Begin);
    visited[Begin.x][Begin.y] = true;
    while(!Q.empty()){
        Position front = Q.front();
        if(front.x == End.x && front.y == End.y){
            minSteps = front.level;
            return;
        }
        for(int i = 0; i < 8; i++)
        {
            int newX = front.x+Dir[i][0], newY = front.y+Dir[i][1];
            int newLvl = front.level+1;
            if(0<=newX && newX < 8 && 0 <= newY && newY < 8 && !visited[newX][newY]){
                Position pos(newX, newY, newLvl);
                Q.push(pos);
                visited[newX][newY] = true;
            }
        }
        Q.pop();
    }
}
int main()
{
    char in[6];
    while(gets(in))
    {
        for(int i = 0; i < 8; i++)
            for(int j =0; j < 8; j++)
                visited[i][j] = false;

        Begin.x = in[0] - 'a';
        Begin.y = in[1] - '1';
        Begin.level = 0;
        End.x = in[3] - 'a';
        End.y = in[4] - '1';


        BFS();
        cout <<"To get from "<<in[0]<<in[1]<<" to "<<in[3]<<in[4]<<" takes "<<minSteps<<" knight moves."<< endl;
    }
    return 0;
}
