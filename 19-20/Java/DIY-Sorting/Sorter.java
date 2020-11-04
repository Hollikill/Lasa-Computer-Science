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

    public void bubbleSort(ArrayList<Integer> listToSort, boolean ascending) {
        
    }

    public void selectionSort(ArrayList<Integer> listToSort, boolean ascending) {
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
    }
    public void selectionSort(ArrayList<Integer> listToSort) {
        selectionSort(listToSort, true);
    }
    public void selectionSort() {
        selectionSort(list, true);
    }
    public void selectionSort (int arrToSort,  boolean ascending) {
        ArrayList<Integer> tempList = arrayToArrayList(arrToSort);
        selectionSort(tempList, ascending);
        for (int i = 0; i < arrToSort.length; i++) {
            arrToSort[i] = tempList.get(i);
        }
    }
    public void selectionSort (int[] arrToSort) {
        selectionSort(arrtoSort, true);
    }

    public void swap (ArrayList<Integer> list, int one, int two) {
        int temp = list.get(one);
        list.set(one, list.get(two));
        list.set(two, temp);
    }

    public int[] arrayListToArray (ArrayList<Integer> list) {
        int[list.size()] arr;
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }
        return arr;
    }
    public ArrayList<Integer> arrayToArrayList (int[] arr) {
        ArrayList<Integer> list;
        for (int x : arr) {
            list.add(x);
        }
        return list;
    }
}