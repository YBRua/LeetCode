#include <cstdio>
#include <deque>

int map[100][100];

inline bool is_row_valid(int row, int n_rows) {
    return row >= 0 && row < n_rows;
}

inline bool is_col_valid(int col, int n_cols) {
    return col >= 0 && col < n_cols;
}

void bfs_labeling(int init_row, int init_col, int n_rows, int n_cols, int label) {
    std::deque<std::pair<int, int>> queue;
    queue.push_back(std::pair<int, int>(init_row, init_col));
    while (queue.size()) {
        auto ele = queue.front();
        auto crow = ele.first;
        auto ccol = ele.second;
        queue.pop_front();
        if (map[crow][ccol] == label) {
            continue;
        }
        map[crow][ccol] = label;
        if (is_row_valid(crow + 1, n_rows) && map[crow+1][ccol] == 1) {
            queue.push_back(std::pair<int, int>(crow + 1, ccol));
        }
        if (is_row_valid(crow - 1, n_rows) && map[crow-1][ccol] == 1) {
            queue.push_back(std::pair<int, int>(crow - 1 , ccol));
        }
        if (is_col_valid(ccol + 1, n_cols) && map[crow][ccol+1] == 1) {
            queue.push_back(std::pair<int, int>(crow, ccol + 1));
        }
        if (is_col_valid(ccol - 1, n_cols) && map[crow][ccol-1] == 1) {
            queue.push_back(std::pair<int, int>(crow, ccol - 1));
        }
    }
}

int count_islands(int n_rows, int n_cols) {
    int label = 2;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (map[i][j] == 1) {
                bfs_labeling(i, j, n_rows, n_cols, label++);
            }
        }
    }
    return label - 2;
}

int main() {
    int n_rows = 0, n_cols = 0;
    scanf("%d %d", &n_rows, &n_cols);
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", count_islands(n_rows, n_cols));
}
