class Solution {

    unordered_set<int> pools_filled; // hash: start * 20000 + end (max = 20000^2 + 20000) is within int32.

    int hash(int start, int end) {
        return start*20000 + end;
    }

public:
    int trap(vector<int>& height) {

        if (height.size() < 2) return 0;

        // two pointer
        int start = 0;
        int end = 1; 
        
        int cumul_area = 0;
        int occupied_area = 0;

        // left to right sweep
        while (start <= end && end < height.size()) {
            if (end - start >= 2) {
                // check if enough to form enclosure
                if (height[end] >= height[start]) {
                    // fill pool and reset

                    //cout << "Filling the pool:" << start << "," << end << endl;
                    //cout << "Occupied area:" << occupied_area << endl;
                    cumul_area += (end - start - 1) * min(height[start], height[end]);
                    cumul_area -= occupied_area;

                    pools_filled.insert(hash(start, end));

                    occupied_area = 0;

                    start = end;
                    end++;
                } else {
                    // add to occupied area
                    occupied_area += height[end];
                    //cout << "Adding to occupied:" << height[end] << endl;
                    end++;
                }
            } else {
                if (height[end] >= height[start]) {
                    // reset
                    occupied_area = 0;
                    start = end;
                    end++;
                } else {
                    // add to occupied area
                    occupied_area += height[end];
                    //cout << "Adding to occupied2:" << height[end] << endl;
                    end++;
                }
            }
        }

        start = height.size() - 1;
        end = height.size() - 2;
        occupied_area = 0;

        // right to left sweep
        while (end <= start && end >= 0) {
            if (start - end >= 2) {
                // check if enough to form enclosure
                if (height[end] >= height[start]) {
                    // fill pool and reset
                    if (pools_filled.find(hash(end, start)) == pools_filled.end()) {
                        //cout << "Filling the pool:" << start << "," << end << endl;

                        cumul_area += (start - end - 1) * min(height[start], height[end]);
                        cumul_area -= occupied_area;

                        occupied_area = 0;

                        start = end;
                        end--;
                    } else {
                        //cout << "Pool already filled before, skipping" << endl;
                        occupied_area = 0;
                        start = end;
                        end--;
                    }
                } else {
                    // add to occupied area
                    occupied_area += height[end];
                    end--;
                }
            } else {
                if (height[end] >= height[start]) {
                    // reset
                    occupied_area = 0;
                    start = end;
                    end--;
                } else {
                    // add to occupied area
                    occupied_area += height[end];
                    end--;
                }
            }
        }

        return cumul_area;
    }
};
