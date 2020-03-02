import java.io.File;
import java.io.FilenameFilter;
import java.util.ArrayList;

public class LocaleLoader {

  public static void main(String[] args) {
    ArrayList<AbstractLocale> locales = getLocales();
    // Your code goes here.
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