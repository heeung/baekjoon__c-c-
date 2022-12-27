import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int tmp = 0;
        
        int X = scan.nextInt();
        int N = scan.nextInt();
        
        for (int i = 0; i < N; i++) {
            int cost = scan.nextInt();
            int num = scan.nextInt();
            
            tmp += multiplyNumber(cost, num);
        }
        System.out.println((tmp == X) ? "Yes" : "No");
    }
    
    public static int multiplyNumber(int cost, int num) {
        return (cost * num);
    }
}
