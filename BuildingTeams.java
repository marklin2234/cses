import java.io.*;
import java.util.*;

public class BuildingTeams {
    static boolean impossible = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        
        int[] ans = new int[n + 1];

        // we want to detect any cycles of 3. If there is a cycle of 3, then it is impossible.
        // Otherwise, we just put people in alternating teams
        for (int i = 1; i <= n; i++) {
            List<Integer> path = new ArrayList<>();
            if (ans[i] == 0)
                dfs(i, adj, ans, 1);
            if (impossible) {
                System.out.println("IMPOSSIBLE");
                return;
            }
        }
        for (int i = 1; i <= n; i++) System.out.print(ans[i] + " ");
    }
    private static void dfs(int curr, List<List<Integer>> adj, int[] ans, int team) {
        if (impossible) return;

        ans[curr] = team;
        for (int next : adj.get(curr)) {
            if (ans[next] == 0) dfs(next, adj, ans, team == 1 ? 2 : 1);
            else if (ans[next] == team) {
                impossible = true;
            }
        }
    }
}
