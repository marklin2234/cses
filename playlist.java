import java.io.*;
import java.util.*;

public class playlist {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()), ans = 0, start = -1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<Integer, Integer> map = new HashMap<>(); 
        for (int i = 0; i < n; i++) {
            int k = Integer.parseInt(st.nextToken());
            
            if (map.containsKey(k)) {
                start = Math.max(start, map.get(k));
            }
            ans = Math.max(ans, i - start);
            map.put(k, i);
        }
        System.out.println(ans);
    }
}
