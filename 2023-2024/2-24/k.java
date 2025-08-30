import java.util.*;
import java.io.*;
public class k {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        while (tests-- != 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken()), k = Long.parseLong(st.nextToken()), a = Long.parseLong(st.nextToken()), b = Long.parseLong(st.nextToken());

            long res = 0;
            while (k > 0) {
                if (a == 0) {
                    res = 1;
                    break;
                }
                long newSerious = (n*b)/a;
                if (newSerious <= n) {
                    res = -1;
                    break;
                }

                long converted = newSerious-n;
                long nextN = ((converted+1)*a)/(b-a);

                if (nextN < newSerious) nextN = newSerious;
                
                long convertedBeforeNextN = Math.max(nextN-newSerious, converted);
                if (k > convertedBeforeNextN) {
                    long runs = (long)Math.ceil((double)convertedBeforeNextN/converted);
                    k -= runs*converted;
                    res += runs;
                    n += runs*converted;
                } else {
                    n += k;
                    res += (long)Math.ceil((double)k/converted);
                    k = 0;
                }
            }
            System.out.println(res);
        }
    }
}