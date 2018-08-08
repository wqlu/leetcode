/**
 * 利用Java可以计算大数的特点，直接获取结果
 */

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        BigInteger A = scanner.nextBigInteger();
        BigInteger B = scanner.nextBigInteger();

        BigInteger sum = A.multiply(B);
        String result = sum.toString();
        System.out.println(result);
    }
}
