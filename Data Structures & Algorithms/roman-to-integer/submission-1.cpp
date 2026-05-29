class Solution {
public:
    int romanToInt(string s) {
        // From largest to lowest, from left to right
        // i.e. won't have IIIV, IIIX, IIV -> invalid

        // IV for 4
        // IX for 9
        // XL for 40
        // XC for 90
        // CD for 400
        // CM for 900
        // only I,V,X can be on the right of I
        // if double I, no V,X will be following
        // only X,L,C can be on the right of X
        // if double X, no L,C will be following
        // only C,D,M can be on the right of C
        // if double C, no D,M will be following
        int res = 0;
        int tmp_val = 0;
        for (auto c: s) {
            switch (c) {
                case 'I':
                    if (tmp_val % 10 == 0) {
                        tmp_val = 0;
                    }
                    res += 1;
                    tmp_val += 1;
                    break;
                case 'V':
                    if (tmp_val == 1) {
                        // conclude a combo: IV
                        res += 3;
                        tmp_val = 0;
                    } else {
                        res += 5;
                        tmp_val = 0;
                    }
                    break;
                case 'X':
                    if (tmp_val == 1) {
                        // conclude a combo: IX
                        res += 8; // form a 9 with prefix I
                        tmp_val = 0; // clear combo
                    } else {
                        if (tmp_val % 100 == 0) {
                            tmp_val = 0;
                        }
                        res += 10;
                        tmp_val += 10;
                    }
                    break;
                case 'L': // conclude by a single char
                    if (tmp_val == 10) {
                        res += 30; // form a 40 with prefix X
                        tmp_val = 0;
                    } else {
                        res += 50;
                        tmp_val = 0;
                    }
                    break;
                case 'C': // cannot conclude by a single char
                    if (tmp_val == 10) {
                        res += 80;
                        tmp_val = 0;
                    } else {
                        res += 100;
                        tmp_val += 100;
                    }
                    break;
                case 'D': // conclude by a single char
                    if (tmp_val == 100) {
                        res += 300; // form a 400 with prefix C
                        tmp_val = 0;
                    } else {
                        res += 500;
                        tmp_val = 0;
                    }
                    break;
                case 'M': // conclude by a single char
                    if (tmp_val == 100) {
                        res += 800; // form a 900 with prefix C
                        tmp_val = 0;
                    } else {
                        res += 1000;
                        tmp_val = 0;
                    }
                    break;
            }
        }

        return res;
    }
};