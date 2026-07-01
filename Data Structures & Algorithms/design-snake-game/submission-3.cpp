class SnakeGame {
private:
    int score_ = 0;
    int ROWS = 0;
    int COLS = 0;
    vector<vector<int>> board_; // 0: empty, 1: snake body, 2: food
    deque<pair<int, int>> snake_;
    queue<pair<int, int>> food_;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        // 1. maintain board status
        // 2. movement of snake is a *** deque ***
        //   each move -> push_front and pop_back 1
        //   if food encountered -> push front only
        score_ = 0;
        for (auto f: food) {
            food_.push({f[0], f[1]});
        }
        board_ = vector<vector<int>>(height, vector<int>(width, 0));
        ROWS = height;
        COLS = width;
        // initialize snake on board
        board_[0][0] = 1;
        snake_.push_front({0, 0});
        // initialize food on board
        if (!food_.empty()) {
            board_[food_.front().first][food_.front().second] = 2;
        }
    }
    
    int move(string direction) {
        pair<int, int> new_head_pos = snake_.front();
        if (direction == "R") {
            new_head_pos.second += 1;
        } else if (direction =="L") {
            new_head_pos.second -= 1;
        } else if (direction == "D") {
            new_head_pos.first += 1;
        } else if (direction == "U") {
            new_head_pos.first -= 1;
        }

        // Handle each condition and update
        // 1. Check boundary
        if (new_head_pos.first < 0 || new_head_pos.first >= ROWS
            || new_head_pos.second < 0 || new_head_pos.second >= COLS) {
            return -1;
        }
        // 2. Check food
        if (!food_.empty() &&
            new_head_pos.first == food_.front().first && 
            new_head_pos.second == food_.front().second) {
            // append to the front of snake, no pop
            snake_.push_front(new_head_pos);
            // consume the food
            score_ += 1;
            food_.pop();
            // update the board
            board_[new_head_pos.first][new_head_pos.second] = 1;
            if (!food_.empty()) {
                board_[food_.front().first][food_.front().second] = 2;
            }
            
            return score_;
        }

        // 3. update tail and check body collision
        auto last_tail = snake_.back();
        snake_.pop_back();
        // update board
        board_[last_tail.first][last_tail.second] = 0;
        // check new head
        if (board_[new_head_pos.first][new_head_pos.second] == 1) {
            // body collision
            return -1;
        }
        snake_.push_front(new_head_pos);
        board_[new_head_pos.first][new_head_pos.second] = 1;

        return score_;

    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
