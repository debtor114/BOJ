#include <cstdio>
#include <vector>

using namespace std;

int w, h;
int board[50][50];
int visit[2500];
vector <int> adj_list[2500];
vector <int> land;

void clear() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < w*h; i++) {
        visit[i] = 0;
        adj_list[i].clear();
    }

    land.clear();
    w = 0;
    h = 0;
}

void dfs(int s) {
    visit[s] = 1;

    for (int i = 0; i < adj_list[s].size(); i++) {
        int v = adj_list[s][i];
        if (visit[v] == 0) 
             dfs(v);
    }

}

int dfs_all() {
    int cc = 0;
    for (int i = 0; i < land.size(); i++) {
        if (visit[land[i]] == 0) {
            cc++;
            dfs(land[i]);
        }         
    }
    return cc;
}

int main() {
    while (1) {
        scanf("%d %d", &w, &h);

        if (w == 0 && h ==0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) { 
                scanf("%d", &board[i][j]);
                if (board[i][j]) land.push_back(i*w + j);
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int u = i*w + j;
                int v;

                if (board[i][j]) {
                    // 아래 칸
                    if (i < h-1 && board[i+1][j]) {
                        v = (i+1)*w + j;
                        adj_list[u].push_back(v);
                    }
                    // 윗 칸
                    if (i > 0 && board[i-1][j]) {
                        v = (i-1)*w + j;
                        adj_list[u].push_back(v);
                    }
                    // 우측 칸
                    if (j < w-1 && board[i][j+1]) {
                        v = i*w + j+1;
                        adj_list[u].push_back(v);
                    }
                    // 왼쪽 칸
                    if (j > 0 && board[i][j-1]) {
                        v = i*w + j-1;
                        adj_list[u].push_back(v);
                    }   
                    // 우측 밑쪽 대각선 칸                
                    if (i < h-1 && j < w-1 && board[i+1][j+1]) {
                        v = (i+1)*w + (j+1);
                        adj_list[u].push_back(v);
                    } 
                    // 좌측 밑쪽 대각선 칸
                    if (i < h-1 && j > 0 && board[i+1][j-1]) {
                        v = (i+1)*w + (j-1);
                        adj_list[u].push_back(v);
                    } 
                    // 우측 위쪽 대각선 칸
                    if (i > 0 && j < w-1 && board[i-1][j+1]) {
                        v = (i-1)*w + (j+1);
                        adj_list[u].push_back(v);
                    } 
                    // 좌측 위쪽 대각선 칸
                    if (i > 0 && j > 0 && board[i-1][j-1]) {
                        v = (i-1)*w + (j-1);
                        adj_list[u].push_back(v);
                    }                     
                }
            }
        }

        printf("%d\n", dfs_all());
        clear();
    }

    return 0;

}

// #include<cstdio>
// #include<cstring>
// using namespace std;

// int arr[51][51];
// int check[51][51];
// int dx[] = { -1, 1, 0, 0, 1, 1, -1, -1 };
// int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
// int w, h;

// void dfs(int x, int y, int cnt)
// {
// 	check[x][y] = cnt;

	
// 		for (int i = 0; i < 8; i++)
// 		{
// 			int nx = x + dx[i];
// 			int ny = y + dy[i];

// 			if (0 <= nx && nx < h && 0 <= ny && ny < w)
// 			{
// 				if (arr[nx][ny] == 1 && check[nx][ny] == 0)
// 				{
// 					dfs(nx, ny, cnt);
// 				}
// 			}
// 		}
	
// }


// int main()
// {
// 	while (1)
// 	{
// 		scanf("%d %d", &w, &h);
// 		if (h == 0 && w == 0)
// 			break;

// 		for (int i = 0; i < h; i++)
// 		{
// 			for (int j = 0; j < w; j++)
// 			{
// 				scanf("%d", &arr[i][j]);
// 			}
// 		}

// 		int cnt = 0;
// 		for (int i = 0; i < h; i++)
// 		{
// 			for (int j = 0; j < w; j++)
// 			{
// 				if (arr[i][j] == 1 && check[i][j] == 0)
// 					dfs(i, j, ++cnt);
// 			}
// 		}
// 		printf("%d\n", cnt);

// 		memset(arr, 0, sizeof(arr));
// 		memset(check, 0, sizeof(check));
// 	}

// 	return 0;
// }