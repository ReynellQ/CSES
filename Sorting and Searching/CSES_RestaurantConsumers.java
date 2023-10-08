import java.io.*;
import java.util.*;

public class CSES_RestaurantConsumers {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        int n = Integer.valueOf(in.readLine());
        int[][] arrive = new int[n][2];
        
        for(int i = 0 ; i < n ; ++i){
            st = new StringTokenizer(in.readLine());
            arrive[i][0] = Integer.valueOf(st.nextToken());
            arrive[i][1] = Integer.valueOf(st.nextToken());
        }
        Arrays.sort(arrive, (a, b)->a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        for(int i = 0 ; i < n ; ++i){
            int i1 = bs1(arrive, arrive[i][0]);
            int i2 = bs2(arrive, arrive[i][0]);
            System.out.println(i1 +" " + i2);
            System.out.println( i2 - i1 + 1);
        }
        in.close();
        out.flush();
        out.close();
    }
    //Ends before or equal x
    public static int bs1(int[][] arrive, int x){
        int l = 0, r = arrive.length - 1, mid;
        while(l < r){
            mid = (l + r + 1)/2;
            if(arrive[mid][1] <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
    //Starts after or equal x
    public static int bs2(int[][] arrive, int x){
        int l = 0, r = arrive.length - 1, mid;
        while(l < r){
            mid = (l + r + 1)/2;
            if(arrive[mid][0] < x)
                l = mid;
            else
                r = mid - 1;
        }
        return l + 1;
    }
}
