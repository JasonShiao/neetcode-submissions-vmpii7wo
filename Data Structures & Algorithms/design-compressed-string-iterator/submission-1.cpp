class StringIterator {
private:
    string compressed_str;
    int compressed_str_idx;
    char cur_ch;
    int rep_remaining;
public:
    StringIterator(string compressedString) {
        compressed_str = compressedString;
        compressed_str_idx = 0;
        cur_ch = ' ';
        rep_remaining = 0;
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }

        // 1. first try to pop remaining ch
        if (rep_remaining > 0) {
            rep_remaining -= 1;
            return cur_ch;
        }

        // 2. if no remaining, try to load the next from compressed str
        cur_ch = compressed_str[compressed_str_idx++];
        while (isdigit(compressed_str[compressed_str_idx])) {
            rep_remaining *= 10;
            rep_remaining += compressed_str[compressed_str_idx] - '0';

            compressed_str_idx++;
        }
        // pop one from latest updated ch
        rep_remaining -= 1;
        return cur_ch;
        
    }
    
    bool hasNext() {
        if (rep_remaining == 0 && 
            compressed_str_idx == compressed_str.length()) {
            return false;
        } else {
            return true;
        }
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
