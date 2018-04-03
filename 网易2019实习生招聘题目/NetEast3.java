import java.util.Scanner;

public class NetEast3 {

    public static void solution(int len, String road) {
        int light = 0;
        for (int i = 0; i < len; i++) {
            if (road.charAt(i) == '.') {
                light ++;
                i += 2;
            }
        }
        System.out.println(light);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int examples = scanner.nextInt();
        for (int i = 0; i < examples; i++) {
            int len = scanner.nextInt();
            String road = scanner.next();
            solution(len, road);
        }
    }
}
