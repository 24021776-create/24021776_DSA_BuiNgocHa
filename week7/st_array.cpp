const int MAX = 100;

class SymbolTableArray {
    string keys[MAX];
    int values[MAX];
    int n = 0;                               // số phần tử hiện có
public:
    void put(string key, int value) {
        for (int i = 0; i < n; i++)
            if (keys[i] == key) { values[i] = value; return; }
        keys[n] = key;
        values[n] = value;
        n++;
    }

    int get(string key) {
        for (int i = 0; i < n; i++)
            if (keys[i] == key) return values[i];
        return -1;
    }

    void remove(string key) {
        for (int i = 0; i < n; i++)
            if (keys[i] == key) {
                keys[i] = keys[n - 1];       // lấy phần tử cuối lấp vào chỗ trống
                values[i] = values[n - 1];
                n--;
                return;
            }
    }

    void print() {
        for (int i = 0; i < n; i++)
            cout << keys[i] << ": " << values[i] << "\n";
    }
};
