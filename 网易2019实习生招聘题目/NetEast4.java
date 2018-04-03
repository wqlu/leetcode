import java.util.Scanner;

public class NetEast4 {

    public static void solution(int len, String position) {
        int start = 0;
        for (int i = 0; i < len; i++) {
            if (position.charAt(i) == 'L') {
                start += 1;
            }else if (position.charAt(i) == 'R') {
                start += 3;
            }
        }
        switch (start % 4){
            case 0:
                System.out.println('N');
                break;
            case 1:
                System.out.println('W');
                break;
            case 2:
                System.out.println('S');
                break;
            case 3:
                System.out.println('E');
                break;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int len = scanner.nextInt();
        String position = scanner.next();
        solution(len, position);
    }
}
