import java.util.*;

public class MainSort {
    public static void main (String args[]) {
        ArrayList<Integer> arr = generateArrayList(20);
        System.out.println(arr);
        Sorter sorter = new Sorter();
        sorter.selectionSort(arr, true);
        System.out.println(arr);
    }

    public static int[] generateArray (int length) {
        int[] list = new int [length];
        for (int i : list) {
            i = (int)((Math.random() * 20) + 1);
        }
        return list;
    }
    public static int[] generateArray () {
        return generateArray(10);
    }

    public static ArrayList<Integer> generateArrayList (int length) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < length; i++) {
            list.add((int)((Math.random() * 20) + 1));
        }
        return list;
    }
    public static ArrayList<Integer> generateArrayList () {
        return generateArrayList(10);
    }
}