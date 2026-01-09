#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;             // Tọa độ hàng, cột
    int g, h;             // g: chi phí đi từ đầu, h: ước lượng tới đích
    int parentX, parentY; // Để truy vết đường đi

    // F = G + H
    int f() const { return g + h; }
};

// So sánh để dùng trong Priority Queue (lấy f nhỏ nhất ra trước)
struct CompareNode
{
    bool operator()(const Node *a, const Node *b)
    {
        return a->f() > b->f();
    }
};

bool isValid(int x, int y, int rows, int cols)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Hàm tính H (Manhattan)
int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void aStarSearch(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> end)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // 4 hướng di chuyển: Lên, Xuống, Trái, Phải
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Mảng lưu trạng thái Node
    vector<vector<Node *>> nodeMap(rows, vector<Node *>(cols, nullptr));

    // Hàng đợi ưu tiên (Open List)
    priority_queue<Node *, vector<Node *>, CompareNode> openList;

    // Khởi tạo nút bắt đầu
    Node *startNode = new Node{start.first, start.second, 0, heuristic(start.first, start.second, end.first, end.second), -1, -1};
    nodeMap[start.first][start.second] = startNode;
    openList.push(startNode);

    // Mảng đánh dấu đã duyệt (Closed List)
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    while (!openList.empty())
    {
        Node *current = openList.top();
        openList.pop();

        int cx = current->x;
        int cy = current->y;

        // Nếu đã đến đích
        if (cx == end.first && cy == end.second)
        {
            cout << "Tim thay duong di!\n";
            // Truy vết ngược lại từ đích về đầu
            while (current->parentX != -1)
            {
                grid[current->x][current->y] = 2; // Đánh dấu đường đi là 2
                int px = current->parentX;
                int py = current->parentY;
                current = nodeMap[px][py];
            }
            grid[start.first][start.second] = 2;
            return;
        }

        visited[cx][cy] = true;

        // Duyệt các ô hàng xóm
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // Kiểm tra hợp lệ: Trong ma trận, không phải tường (1), chưa duyệt
            if (isValid(nx, ny, rows, cols) && grid[nx][ny] == 0 && !visited[nx][ny])
            {
                int newG = current->g + 1;

                // Nếu chưa có trong nodeMap hoặc tìm thấy đường ngắn hơn
                if (nodeMap[nx][ny] == nullptr || newG < nodeMap[nx][ny]->g)
                {
                    Node *neighbor = new Node{nx, ny, newG, heuristic(nx, ny, end.first, end.second), cx, cy};
                    nodeMap[nx][ny] = neighbor;
                    openList.push(neighbor);
                }
            }
        }
    }
    cout << "Khong tim thay duong di.\n";
}

int main()
{
    // 0: Đường đi, 1: Tường
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}};

    pair<int, int> start = {0, 0};
    pair<int, int> end = {4, 4};

    aStarSearch(grid, start, end);

    // In kết quả (Số 2 là đường đi)
    cout << "\nBan do lo trinh (2 la duong di):\n";
    for (const auto &row : grid)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return;