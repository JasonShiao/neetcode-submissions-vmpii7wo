class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // only the nearby asteroids collide
        // use stack (or deque)
        stack<int> asteroid_stack;
        for (auto& ast: asteroids) {
            //bool new_ast_processed = false; // either add to stack or explode
            while (true) {
                if (asteroid_stack.empty()) {
                    asteroid_stack.push(ast);
                    break;
                }
                // check direction
                if (asteroid_stack.top() < 0 || ast > 0) {
                    // same dir -> never collide
                    asteroid_stack.push(ast);
                    break;
                } else {
                    // opposite -> collide
                    if (abs(asteroid_stack.top()) > abs(ast)) {
                        // exploded by existing
                        break;
                    } else if (abs(asteroid_stack.top()) < abs(ast)) {
                        // explode the existing, keep checking the last (not break)
                        asteroid_stack.pop();
                    } else { // both explode
                        asteroid_stack.pop();
                        break;
                    }
                }
            }
        }
        vector<int> res;
        while (!asteroid_stack.empty()) {
            res.push_back(asteroid_stack.top());
            asteroid_stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};