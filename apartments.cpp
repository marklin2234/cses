#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n,m,k;
    cin >> n >> m >> k;

    int desire[n];
    int size[m];

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        desire[i] = a;
    }

   for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        size[i] = b;
    }
    sort(desire, desire + n);
    sort(size, size + m);

    int i = 0, j = 0, ans = 0;

    while(i < n && j < m) {
        if (size[j] >= desire[i] - k && size[j] <=desire[i] + k) {
            i++;
            j++;
            ans++;
        } else {
            if (size[j] < desire[i] - k) {
                j++;
            } else {
                i++;
            }
        }
    }
    cout << ans << endl;
}
