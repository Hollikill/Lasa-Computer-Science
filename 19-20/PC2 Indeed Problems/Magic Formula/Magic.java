import java.util.*;
import java.io.*;

public class Magic {
    public static void main (String args[]) throws IOException {
        Scanner file = new Scanner(new File("magic.dat"));
        
        boolean run = true;
        
        while (run) {
            int times = 0;
            int a = file.nextInt();
            int b = file.nextInt();
            int c = file.nextInt();
            int d = file.nextInt();
            int l = file.nextInt();

            if (d != 0) {
                for (int i = 0; i <= l; i++) {
                    double out = (a * Math.pow(i, 2)) + (b * i) + c;
                    double outD = out % d;
                    if (outD == 0) {
                        times++;
                    }
                }
                System.out.println(times);
            }
            else {
                run = false;
            }
        }

        file.close();
    }
}