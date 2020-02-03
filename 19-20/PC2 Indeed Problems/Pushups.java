public class Pushups {
    public static void main (String args[]) {
        int x = 40;

        for (int i = 1; i < x + 1; i++) {
            if (i == 1) {
                System.out.println("On day " + i + " do " + i + " pushups a day for " + i + " day.");
            }
            else {
                System.out.println("On day " + i + " do " + i + " pushups a day for " + i + " days.");
            }
        }
    }
}