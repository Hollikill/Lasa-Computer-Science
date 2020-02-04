import java.util.*;
import java.io.*;

public class Compare {
    public static void main (String args[]) throws IOException{
        Scanner file = new Scanner(new File("compare.dat"));

        String comapreTo = "9th Annual Indeed Computer Science UIL Invitational";

        while (file.hasNext()) {
            String line = file.nextLine();

            int x = 0;

            for (int i = 0; i < comapreTo.length() && i < line.length(); i++) {
                if (line.charAt(i) == comapreTo.charAt(i)) {
                    x++;
                }
            }

            System.out.println(x);
        }
    }
}