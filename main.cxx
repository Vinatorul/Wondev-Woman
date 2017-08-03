#include <bits/stdc++.h>

using namespace std;


vector<string> grid;

pair<int, int> dir_to_diff(string dir) {
    if (dir == "N") {
        return {0, -1};
    } else if (dir == "NE") {
        return {1, -1};
    } else if (dir == "E") {
        return {1, 0};
    } else if (dir == "SE") {
        return {1, 1};
    } else if (dir == "S") {
        return {0, 1};
    } else if (dir == "SW") {
        return {-1, 1};
    } else if (dir == "W") {
        return {-1, 0};
    } else if (dir == "NW") {
        return {-1, -1};
    } else {
        cout << "ERROR" << endl;
    }
}

int main()
{
    int size;
    cin >> size; cin.ignore();
    grid.resize(size);
    int unitsPerPlayer;
    cin >> unitsPerPlayer; cin.ignore();

    // game loop
    while (1) {
        for (int i = 0; i < size; i++) {
            string row;
            cin >> grid[i]; cin.ignore();
        }
            int unitX1;
            int unitY1;
            cin >> unitX1 >> unitY1; cin.ignore();
            int unitX2;
            int unitY2;
            cin >> unitX2 >> unitY2; cin.ignore();
        // for (int i = 0; i < unitsPerPlayer; i++) {
        //     cin >> unitX >> unitY; cin.ignore();
        // }
        for (int i = 0; i < unitsPerPlayer; i++) {
            int otherX;
            int otherY;
            cin >> otherX >> otherY; cin.ignore();
        }
        int legalActions;
        cin >> legalActions; cin.ignore();
        string ans11, ans12;
        string atype1, atype2;
        int cur_val1 = -999;
        int b_val1 = 0;
        int c_p1 = grid[unitY1][unitX1] - '0';
        string ans21, ans22;
        int cur_val2 = -999;
        int b_val2 = 0;
        int c_p2 = grid[unitY2][unitX2] - '0';
        for (int i = 0; i < legalActions; i++) {
            string atype;
            int index;
            string dir1;
            string dir2;
            int dx, dy, dx2, dy2;
            cin >> atype >> index >> dir1 >> dir2; cin.ignore();
            tie(dx, dy) = dir_to_diff(dir1);
            tie(dx2, dy2) = dir_to_diff(dir2);
            if (index == 0) {
                int t_p = grid[unitY1 + dy][unitX1 + dx] - '0';
                int t_p2 = grid[unitY1 + dy + dy2][unitX1 + dx + dx2] - '0';
                if (t_p2 == 3)
                    t_p2 = -1;
                if (t_p - c_p1 + t_p2 >= cur_val1 + b_val1) {
                    cur_val1 = t_p - c_p1;
                    b_val1 = t_p2;
                    ans11 = dir1;
                    ans12 = dir2;
                    atype1 = atype;
                }
            } else {
                int t_p = grid[unitY2 + dy][unitX2 + dx] - '0';
                int t_p2 = grid[unitY2 + dy + dy2][unitX2 + dx + dx2] - '0';
                if (t_p2 == 3)
                    t_p2 = -1;
                if (t_p - c_p2 + t_p2 > cur_val2 + b_val2) {
                    cur_val2 = t_p - c_p2;
                    b_val2 = t_p2; 
                    ans21 = dir1;
                    ans22 = dir2;
                    atype2 = atype;
                }
            }
        }   
        
        if (cur_val1 > cur_val2) {
            cout << atype1 << " 0 " << ans11 << " " << ans12 << endl;
        } else {
            cout << atype2 << " 1 " << ans21 << " " << ans22 << endl;
        }
    }
}