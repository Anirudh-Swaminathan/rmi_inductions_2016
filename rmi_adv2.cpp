#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class PathFinder
{
private:
    char world[51][51];
    int n;
    int m;
    int start_x,end_x;
    int start_y,end_y;
    stack< pair<int,int> > q;
    int mark[51][51];
    bool reached = false;
    int xparent[51][51];
    int yparent[51][51];
    string paths[51][51];
    stack<string> path;

    void dfs(int x,int y)
    {
        //cout<<"\nIn BFS";
        mark[x][y] = 1;
        q.push(make_pair(x,y));
        while(!q.empty())
        {
            pair<int,int> cur = q.top();
            q.pop();
            //cout<<cur.first;
            //Up,Down,Left,Right
            //cout<<world[cur.first][cur.second]<<" has been visited "<<endl;
            if(world[cur.first][cur.second] == 'g')
            {
                //cout<<"The goal has been reached!!";
                end_x = cur.first;
                end_y = cur.second;
                reached = true;
                break;
            }
            //Can I go up
            if(cur.first!=0)
            {
                if(mark[cur.first - 1][cur.second] == 0 && world[cur.first-1][cur.second]!='1')
                {
                    mark[cur.first-1][cur.second] = 1;

                    xparent[cur.first-1][cur.second] = cur.first;
                    yparent[cur.first-1][cur.second] = cur.second;
                    paths[cur.first-1][cur.second] = "UP";

                    q.push(make_pair(cur.first-1,cur.second));
                }
            }
            //Can go down
            if(cur.first!=m-1)
            {
                if(mark[cur.first + 1][cur.second] == 0 && world[cur.first+1][cur.second]!='1')
                {
                    mark[cur.first+1][cur.second] = 1;

                    xparent[cur.first+1][cur.second] = cur.first;
                    yparent[cur.first+1][cur.second] = cur.second;
                    paths[cur.first+1][cur.second] = "DOWN";

                    q.push(make_pair(cur.first+1,cur.second));
                }
            }
            //Can go left
            if(cur.second!=0)
            {
                if(mark[cur.first][cur.second-1] == 0 && world[cur.first][cur.second-1]!='1')
                {
                    mark[cur.first][cur.second-1] = 1;

                    xparent[cur.first][cur.second-1] = cur.first;
                    yparent[cur.first][cur.second-1] = cur.second;
                    paths[cur.first][cur.second-1] = "LEFT";

                    q.push(make_pair(cur.first,cur.second-1));
                }
            }
            //Can go right
            if(cur.second!=n-1)
            {
                if(mark[cur.first][cur.second+1] == 0 && world[cur.first][cur.second+1]!='1')
                {
                    mark[cur.first][cur.second+1] = 1;

                    xparent[cur.first][cur.second+1] = cur.first;
                    yparent[cur.first][cur.second+1] = cur.second;
                    paths[cur.first][cur.second+1] = "RIGHT";

                    q.push(make_pair(cur.first,cur.second+1));
                }
            }
        }
    }

public:
    PathFinder()
    {
        for(int i=0; i<51; ++i)
        {
            for(int j=0; j<51;++j)
            {
                mark[i][j] = 0;
                xparent[i][j]=-1;
                yparent[i][j] = -1;
                paths[i][j] = "";
            }
        }
    }
    void input()
    {
        cin>>m;
        cin>>n;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                cin>>world[i][j];
                if(world[i][j] == 's')
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }
    }
    void operate()
    {
        //cout<<"\nIn operate";
        dfs(start_x,start_y);
    }
    void print_path()
    {
        if(reached)
        {
            int a1 = end_x;
            int b1 = end_y;
            int x = 0;
            while(world[a1][b1] != 's')
            {
                path.push(paths[a1][b1]);
                x++;
                int p =a1;
                a1 = xparent[a1][b1];
                b1 = yparent[p][b1];
            }
            cout<<"\nThe shortest path is "<<endl;
            while(!path.empty())
            {
                cout<<"\n"<<path.top();
                path.pop();
            }
            cout<<"\nThe number of steps that must be taken to reach the goal is "<<x;
        }
        else
        {
            cout<<"\nSorry, No path exists to the goal ";
        }
    }
    void output()
    {
        cout<<"\nThe sizes are "<<m<<" * "<<n;
        cout<<"\nThe gird entered is "<<endl;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                cout<<world[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\nThe indices of the start grid are ("<<start_x<<","<<start_y<<") and the start is "<<world[start_x][start_y];
        if(!reached)
        {
            cout<<"\nThe goal is unreachable from the starting point";
        }
    }
};
int main()
{
    PathFinder pf;
    pf.input();
    pf.operate();
    pf.print_path();
    //pf.output();
    return 0;
}

