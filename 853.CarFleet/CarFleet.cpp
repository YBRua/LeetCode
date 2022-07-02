#include <vector>
#include <iostream>

using namespace std;

/**
 * Sort the cars by their initial position in increasing order
 * Compute the estimated time of arrival for each car
 * for car i, if a car j (j > i) spends longer time to arrive
 * then car i will be blocked by j, and forms a car fleet
 * e.g. 
 * for ETAs [12, 3, 7, 1, 1] (index starting from 0)
 * car 1 will be blocked by car 2, and car 3 will be blocked by car 4
 * this relation forms a (strictly) monotonic decreasing stack
 */

class CarFleet {
   public:
    int position;
    int speed;
    CarFleet(int p, int s) : position(p), speed(s) {}
    friend bool operator<(const CarFleet& a, const CarFleet& b) {
        return a.position < b.position;
    }
    friend bool operator>(const CarFleet& a, const CarFleet& b) {
        return a.position > b.position;
    }
};

class Solution {
   private:
    void _merge_sort(vector<CarFleet>& fleets, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        _merge_sort(fleets, start, mid);
        _merge_sort(fleets, mid + 1, end);
        vector<CarFleet> buffer;
        int i = start, j = mid + 1;
        while (i <= mid && j <= end) {
            if (fleets[i] < fleets[j])
                buffer.push_back(fleets[i++]);
            else
                buffer.push_back(fleets[j++]);
        }
        while (i <= mid) buffer.push_back(fleets[i++]);
        while (j <= end) buffer.push_back(fleets[j++]);
        for (int k = start; k <= end; ++k) fleets[k] = buffer[k - start];
        return;
    }

    void _print_sorted_fleet(const vector<CarFleet>& fleets) {
        for (auto f : fleets) {
            cout << "Pos: " << f.position << " @ " << f.speed << endl;
        }
        return;
    }

   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<CarFleet> car_fleets;
        for (int i = 0; i < position.size(); ++i) {
            car_fleets.push_back(CarFleet(position[i], speed[i]));
        }
        _merge_sort(car_fleets, 0, car_fleets.size() - 1);
        // _print_sorted_fleet(car_fleets);

        // eta is a monotonic decreasing stack
        vector<float> eta;
        for (int i = 0; i < car_fleets.size(); ++i) {
            float current_eta = static_cast<float>(target - car_fleets[i].position) / car_fleets[i].speed;
            while (eta.size() && current_eta >= eta.back()) eta.pop_back();
            eta.push_back(current_eta);
        }

        return eta.size();
    }
};

int main() {
    int target = 12;
    vector<int> positions = {10,8,0,5,3};
    vector<int> speeds = {2,4,1,1,3};
    cout << Solution().carFleet(target, positions, speeds) << endl;
}
