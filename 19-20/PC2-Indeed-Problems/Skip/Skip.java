public class Skip {
    public static void main (String args[]) {
        int x = 40;
        for (int i = 1; i <= x; i++) {
            int a = 1;
            for (int b = 0; b < 10; b++) {
                System.out.print(a + " ");
                a+=i;
            }
            System.out.println("");
        }
    }
}