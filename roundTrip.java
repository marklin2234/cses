import java.io.*;
import java.util.*;

public class roundTrip {
    
    static boolean check = false;
    private static void dfs(int curr, boolean[] vis, List<List<Integer>> adj, List<Integer> path, int[] prev) {
        if (check) return;
        vis[curr] = true;
        prev[curr] = path.size();
        path.add(curr);

        for (int next : adj.get(curr)) {
            if (!vis[next]) {
                dfs(next, vis, adj, path, prev);
            } else {
                int idx = prev[next];
                if (idx == -1) continue;

                // 1 2 3 4 5
                if (path.size() - idx + 1 > 3) {
                    check = true;
                    System.out.println(path.size() - idx + 1);
                    for (int i = idx; i < path.size(); i++) {
                        System.out.print(path.get(i) + " ");
                    }
                    System.out.println(path.get(idx));
                    return;
                }
            }
        }
        path.remove(path.size() - 1);
        prev[curr] = -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        boolean vis[] = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            int[] prev = new int[n + 1];
            Arrays.fill(prev, -1);
            if (!vis[i]) dfs(i, vis, adj, new ArrayList<>(), prev);
            if (check) break;
        }
        if (!check) System.out.println("IMPOSSIBLE");
    }
}

