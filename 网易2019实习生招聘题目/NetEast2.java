import java.util.Scanner;

public class NetEast2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int begin = scanner.nextInt();
        int end = scanner.nextInt();
        int result = 0;

        for (int i = begin; i <= end; i++) {
            switch (i%3) {
                case 1: ;break;
                case 2: ++result; break;
                case 0: ++result; break;
            }
        }
        System.out.println(result);
    }
}
