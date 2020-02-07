import java.util.*;
import java.io.*;

public class Armstrong {
    public static void main (String args[]) throws IOException{
        Scanner file = new Scanner(new File("armstrong.dat"));

        int lines = file.nextInt();

        for (int i = 0; i < lines; i++) {
            int num = file.nextInt();
            String numLen = "" + num;
            int len = numLen.length();
            int tot = 0;

            for (int x = 0; x < len; x++) {
                tot += Math.pow(Character.getNumericValue(numLen.charAt(x)), len);
            }

            if (tot == num) {
                System.out.println("ARMSTRONG");
            }
            else {
                System.out.println("NOT AN ARMSTRONG");
            }
        }
    }
}