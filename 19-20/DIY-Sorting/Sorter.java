import java.util.*;

public class Sorter {
    ArrayList<Integer> list;

    public Sorter() {
        this(new ArrayList<Integer>());
    }
    public Sorter(ArrayList<Integer> newList) {
        list = newList;
    }

    public void setList(ArrayList<Integer> newList) {
        list = newList;
    }

    public ArrayList<Integer> selectionSort(ArrayList<Integer> listToSort, boolean ascending) {
        for (int i = 0; i < listToSort.size() - 1; i++) {
            int lowestNumSoFar = -1;
            for (int b = i; b < listToSort.size(); b++) {
                if (b == i) {
                    lowestNumSoFar = b;
                }
                else {
                    if (ascending) {
                        if (listToSort.get(b) < listToSort.get(lowestNumSoFar)) {
                            lowestNumSoFar = b;
                        }
                    }
                    else {
                        if (listToSort.get(b) > listToSort.get(lowestNumSoFar)) {
                            lowestNumSoFar = b;
                        }
                    }
                }
            }
            swap(listToSort, i, lowestNumSoFar);
            System.out.println(listToSort);
        }
        return listToSort;
    }

    public ArrayList<Integer> selectionSort(ArrayList<Integer> listToSort) {
        return selectionSort(listToSort, true);
    }

    public ArrayList<Integer> selectionSort() {
        return selectionSort(list, true);
    }

    public void swap (ArrayList<Integer> list, int one, int two) {
        int temp = list.get(one);
        list.set(one, list.get(two));
        list.set(two, temp);
    }
}