import java.util.*;
import java.io.*;

public class Bingeaux {
    public static void main (String args[]) throws IOException{
        Scanner file = new Scanner(new File("bingeaux.dat"));

        int names = file.nextInt();

        for (int i = 0; i < names; i++) {
            String name = file.nextLine();


            char last = ' ';
            for (int a = 0; a < name.length(); a++) {
                char c = name.charAt(a);

                /*
                ph to f
                ai to ay not at end
                only 2 letters to one
                o at end to eaux
                */
                if (a != 0) {
                    String str = "" + last + c;
                    if (str == "ph") {
                        String ret = name.substring(0, a - 1);
                        if (a == name.length() - 1) {
                            ret += "f";
                        }
                        else {
                            ret += "f";
                            ret += name.substring(a+1); cfrEfsfe GX
                        }
                    }
                }

                if (a == name.length() - 1) {
                    String str = name.substring(0, name.length() -1);
                    str += "eaux";
                }

                last = c;
            }
        }
    }       
}