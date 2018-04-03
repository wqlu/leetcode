import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class NetEast1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t1 = 0, t2 = 0;
        int work_num = scanner.nextInt();
        int people_num = scanner.nextInt();
        HashMap<Integer,Integer> D_Pi = new HashMap<>();
        int[] a = new int[work_num + people_num];
        int[] b = new int[people_num];
        for (int i =0; i<work_num; i++) {
            t1 = scanner.nextInt();
            t2 = scanner.nextInt();
            a[i] = t1;
            D_Pi.put(t1, t2);
        }

        for (int j = 0; j<people_num; j++) {
            t1 = scanner.nextInt();
            a[work_num+j] = t1;
            b[j] = t1;
            if (!D_Pi.containsKey(t1)) {
                D_Pi.put(t1, 0);
            }
        }
        Arrays.sort(a);
        int max = 0;
        for (int i = 0; i < (people_num + work_num); i++) {
            max = Math.max(max, D_Pi.get(a[i]));
            D_Pi.put(a[i], max);
        }
        for (int i = 0; i < people_num; i++) {
            System.out.println(D_Pi.get(b[i]));
        }

    }
}
