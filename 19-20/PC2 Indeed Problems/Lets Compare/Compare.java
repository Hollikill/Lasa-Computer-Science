import java.util.*;
import java.io.*;

public class Compare {
    public static void main (String args[]) throws IOException{
        Scanner file = new Scanner(new File("compare.dat"));

        String comapreTo = "9th Annual Indeed Computer Science UIL Invitational";

        while (file.hasNext()) {
            String line = file.nextLine();

            for (int i = 0; i < comapreTo.length() - 1 && i < line.length() - 1; i++) {
                int x = 0;

                if (line.charAt(i) == comapreTo.charAt(i)) {
                    x++;
                }

                System.out.println(x);
            }
        }
    }
}