import java.util.*;
import java.io.*;

public class Bingeaux {
    public static void main (String args[]) throws IOException{
        Scanner file = new Scanner(new File("bingeaux.dat"));
        
        int names = file.nextInt();
        
        for (int i = 0; i < names; i++) {
            String name = file.nextLine();
            
            char last = ' ';

            ArrayList<String> pos = new ArrayList<String>();

            for (int changes = 0; changes < 15; changes++) {
                boolean u = false;
                boolean k = false;
                boolean o = false;
                boolean p = false;

                if (changes == 0 ||changes == 4 ||changes == 5 ||changes == 6 ||changes == 10 ||changes == 11 ||changes == 12 ||changes == 14) {
                    u = true;
                } // 1,5,6,7,11,12,13,15
                if (changes == 1 ||changes == 4 ||changes == 7 ||changes == 8 ||changes == 10 ||changes == 11 ||changes == 13 ||changes == 14) {
                    k = true;
                } // 2,5,8,9,11,12,14,15
                if (changes == 2 ||changes == 5 ||changes == 7 ||changes == 9 ||changes == 10 ||changes == 12 ||changes == 13 ||changes == 14) {
                    o = true;
                } // 3,6,8,10,11,13,14,15
                if (changes == 3 ||changes == 6 ||changes == 8 ||changes == 9 ||changes == 11 ||changes == 12 ||changes == 13 ||changes == 14) {
                    p = true;
                } // 4,7,9,10,12,13,14,15

                String ret = "";

                for (int a = 0; a < name.length(); a++) {
                    char c = name.charAt(a);
                    
                    if (a != 0) {
                        String str = "" + last + c;
                        if (str == "ph" && u) {
                            ret = name.substring(0, a - 1);
                            if (a == name.length() - 1) {
                                ret += "f";
                            }
                            else {
                                ret += "f";
                                ret += name.substring(a+1);
                            }
                        }
                        if (str == "ai" && a != name.length() - 1 && k) {
                            ret = name.substring(0, a - 1);
                            ret += "ay";
                            ret += name.substring(a+1);
                        }
                        if (last == c && o) {
                            if (a == 1) {
                                if (name.length() > 2) {
                                    if (name.charAt(2) == c) {
                                        ret = name;
                                    }
                                    else {
                                        ret = "" + c + name.substring(2);
                                    }
                                }
                                else {
                                    ret = "" + c;
                                }
                            }
                            else if (a == name.length() - 1) {
                                if (name.charAt(a - 2) == c) {
                                    ret = name;
                                }
                                else {
                                    ret = name.substring(0, a - 1) + c;
                                }
                            }
                            else {
                                if (name.charAt(a - 2) == c || name.charAt(a + 1) == c) {
                                    ret = name;
                                }
                                else {
                                    ret = name.substring(0, a - 1) + c + name.substring(a + 1);
                                }
                            }
                        }
                    }
                    
                    if (a == name.length() - 1 && p) {
                        if (c == 'o') {
                            String str = name.substring(0, name.length() -1);
                            str += "eaux";
                            ret = str;
                        }
                    }
                    
                    last = c;
                }

                boolean b = true;

                for (String s : pos) {
                    if (ret.equals(s)) {
                        b = false;
                    }
                }

                if (b) {
                    pos.add(ret);
                }
            }

            for (String s : pos) {
                System.out.println(s);
            }
        }

        file.close();
    }       
}