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
    for (int i = 0; i < n; i++) {
        if (keys[i] == key) {
            // Dịch các phần tử phía sau lên 1 vị trí
            for (int j = i; j < n - 1; j++) {
                keys[j] = keys[j + 1];
                values[j] = values[j + 1];
            }
            n--;
            return;
        }
    }
}

    void print() {
        for (int i = 0; i < n; i++)
            cout << keys[i] << ": " << values[i] << "\n";
    }
};
