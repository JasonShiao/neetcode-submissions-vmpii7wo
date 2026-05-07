class Solution {
public:
    void dfs_fill(vector<vector<bool>>& visited, vector<vector<int>>& image,
        const int r, const int c,
        const int origin_color, const int target_color) {
        
        if (r >= image.size() || r < 0 ||
            c >= image[0].size() || c < 0) {
            return;
        }

        if (visited[r][c] == true) {
            return;
        }

        if (image[r][c] == origin_color) {
            // change color
            image[r][c] = target_color;
            // mark visited
            visited[r][c] = true;
            // test and modify adjacent nodes
            dfs_fill(visited, image, r + 1, c, origin_color, target_color);
            dfs_fill(visited, image, r - 1, c, origin_color, target_color);
            dfs_fill(visited, image, r, c + 1, origin_color, target_color);
            dfs_fill(visited, image, r, c - 1, origin_color, target_color);
        } else {
            return;
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        int origin_color = image[sr][sc];

        dfs_fill(visited, image, sr, sc, origin_color, color);

        return image;
    }
};