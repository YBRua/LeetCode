#include <string>
#include <vector>

using namespace std;

class OrderedStream {
   public:
    vector<bool> has_outputted;
    vector<string> buffer;
    int ptr;
    OrderedStream(int n) {
        ptr = 1;
        buffer = vector<string>(n, "");
        has_outputted = vector<bool>(n, false);
    }

    vector<string> insert(int idKey, string value) {
        buffer[idKey - 1] = value;

        vector<string> res;
        if (ptr == idKey) {
            while (ptr - 1 < buffer.size() && buffer[ptr - 1].size()) {
                res.push_back(buffer[ptr - 1]);
                ptr++;
            }
        }

        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */