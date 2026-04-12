import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[] totalGrowth = new int[2 * M - 1];

        int[] diff = new int[2 * M]; 

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int num0 = Integer.parseInt(st.nextToken());
            int num1 = Integer.parseInt(st.nextToken());
            int num2 = Integer.parseInt(st.nextToken());

            if (num0 < 2 * M - 1) {
                diff[num0] += 1;
            }
			
            if (num0 + num1 < 2 * M - 1) {
                diff[num0 + num1] += 1;
            }
        }

        int currentDailySum = 0;
        int[] boundary = new int[2 * M - 1];
        for (int i = 0; i < 2 * M - 1; i++) {
            currentDailySum += diff[i];
            boundary[i] = currentDailySum + 1;
        }

        StringBuilder sb = new StringBuilder();
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < M; c++) {
                if (c == 0) {
                    sb.append(boundary[M - 1 - r]).append(" ");
                } else {
                    sb.append(boundary[M - 1 + c]).append(" ");
                }
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}