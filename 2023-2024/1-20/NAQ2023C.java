import java.util.*;
import java.io.*;

public class NAQ2023C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), players = Integer.parseInt(st.nextToken());

        double lowerBound = 0, higherBound = 0;
        double[][] days = new double[n][2];
        PriorityQueue<Double[]> pq = new PriorityQueue<>(new Comparator<Double[]>() {
            @Override
            public int compare(Double[] a, Double[] b) {
                if (b[1]-a[1] < 1) return 1;
                else if (b[1]-a[1] > 1) return -1;
                else return 0;
            }
        });

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            days[i][0] = Integer.parseInt(st.nextToken());
            days[i][1] = Integer.parseInt(st.nextToken())-1; //Adjust the index to be 0 based
            if (days[i][0]/players > higherBound) higherBound = days[i][0]/players;
        }

        double oldAns = 0;
        while (higherBound-lowerBound > 1e-9) {
            double foodPerDay = (higherBound+lowerBound)/2;
            if (foodPerDay == oldAns) break;
            oldAns = foodPerDay;

            boolean notEnough = false;
            for (int i = 0; i < n; i++) {
                double temp = foodPerDay*players;
                while (!pq.isEmpty() && pq.peek()[1] < days[i][1] && temp > 0) {
                    Double[] savedFood = pq.poll();
                    if (savedFood[0] > temp) {
                        savedFood[0] -= temp;
                        temp = 0;
                        pq.add(savedFood);
                    } else {
                        temp -= savedFood[0];
                    }
                }
                if (days[i][0] >= temp) {
                    pq.add(new Double[]{days[i][0]-temp, days[i][1]});
                } else {
                    temp -= days[i][0];

                    while (!pq.isEmpty() && temp > 0) {
                        Double[] savedFood = pq.poll();
                        if (savedFood[0] > temp) {
                            savedFood[0] -= temp;
                            temp = 0;
                            pq.add(savedFood);
                        } else {
                            temp -= savedFood[0];
                        }
                    }
                    if (temp != 0) {
                        notEnough = true;
                        break;
                    }
                }
                while (!pq.isEmpty() && pq.peek()[1] <= i) pq.poll();
            }
            if (notEnough) {
                higherBound = foodPerDay-1e-9;
            } else {
                lowerBound = foodPerDay+1e-9;
            }
            pq.clear();
        }
        double res = (higherBound+lowerBound)/2;
        if (res < 1e-9) System.out.println(-1);
        else System.out.printf("%.10f\n", res);
    }
}