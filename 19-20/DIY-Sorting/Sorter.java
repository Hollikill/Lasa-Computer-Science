import java.util.*;

public class Sorter {
    ArrayList<Integer> list;

    public Sorter() {
        this(ArrayList<Integer>());
    }
    public Sorter(ArrayList<Integer> newList) {
        list = newList;
    }

    public void setList(ArrayList<Integer> newList) {
        list = newList;
    }

    public ArrayList<Integer> selectionSort(ArrayList<Integer> listToSort, boolean ascending) {

    }

    public ArrayList<Integer> selectionSort(ArrayList<Integer> listToSort) {
        return selectionSort(listToSort, true);
    }

    public ArrayList<Integer> selectionSort() {
        return selectionSort(list, true);
    }
}