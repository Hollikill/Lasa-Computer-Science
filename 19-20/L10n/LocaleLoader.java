import java.io.File;
import java.io.FilenameFilter;
import java.util.ArrayList;
import java.util.Scanner;

public class LocaleLoader {

  public static void main(String[] args) {
    ArrayList<AbstractLocale> locales = getLocales();

    Scanner scan = new Scanner(System.in);

    int x = 1;
    for (AbstractLocale lang : locales) {
      System.out.println(x + ". " + lang.getLocation() + " (" + lang.getLanguage() + ")");
      x++;
    }
    System.out.println("What locale do you want? ");
    String locale = scan.nextLine();
    int desLoc = Character.getNumericValue(locale.charAt(0)) - 1;
    System.out.println(locales.get(desLoc).getGreeting());
    System.out.println("What's the hour? ");
    int hr = scan.nextInt();
    System.out.println("What's the minute? ");
    int mn = scan.nextInt();
    System.out.println("The local time is: " + locales.get(desLoc).getLocalTime(hr, mn)); 
    System.out.println("How much money do you have in your wallet? ");
    int money = scan.nextInt();
    System.out.println("In " + locales.get(desLoc).getLocation() + ", that's worth " + locales.get(desLoc).getCurrencySymbol() + locales.get(desLoc).getCurrencyValue(money));


    System.out.println(locales);
  }

  /**
   * DO NOT MODIFY THIS METHOD.
   * Scans the directory of your .java file for all implementations of
   * AbstractLocale, instantiates them, and puts them in an ArrayList.
   * @return the list of locale implementations.
   */
  public static ArrayList<AbstractLocale> getLocales() {
    ArrayList<AbstractLocale> locales = new ArrayList<AbstractLocale>();
    File pwd = new File(
        ClassLoader.getSystemClassLoader().getResource("").getPath());
    File[] classFiles = pwd.listFiles(new FilenameFilter() {
        public boolean accept(File dir, String name) {
          return name.endsWith(".class");
        }});
    for(File f : classFiles) {
      String className = f.getName().replace(".class", "");
      try {
        Class<?> c = Class.forName(className);
        if (!c.getName().equals("AbstractLocale")) {
          Object obj = c.newInstance();
          if (obj instanceof AbstractLocale)
            locales.add((AbstractLocale)obj);
        }
      } catch (ClassNotFoundException e) {
        System.err.println("Class not found: " + className);
      } catch (InstantiationException e) {
        System.err.println("Error instantiating the object: " + className);
      } catch (IllegalAccessException e) {
        System.err.println("Invalid method access for " + className);
      }
    }
    return locales;
  }
}