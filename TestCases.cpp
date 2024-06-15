// Question 1 Solution in Java:

import java.util.*;

class MyHashMap {
    private static final int SIZE = 1000;
    private List<List<Entry>> map;

    public MyHashMap() {
        map = new ArrayList<>(Collections.nCopies(SIZE, null));
    }

    private int hash(int key) {
        return key % SIZE;
    }

    public void put(int key, int value) {
        int h = hash(key);
        if (map.get(h) == null) {
            map.set(h, new LinkedList<>());
        }
        for (Entry entry : map.get(h)) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        map.get(h).add(new Entry(key, value));
    }

    public int get(int key) {
        int h = hash(key);
        if (map.get(h) == null) return -1;
        for (Entry entry : map.get(h)) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        return -1;
    }

    public void remove(int key) {
        int h = hash(key);
        if (map.get(h) == null) return;
        Iterator<Entry> it = map.get(h).iterator();
        while (it.hasNext()) {
            if (it.next().key == key) {
                it.remove();
                return;
            }
        }
    }

    private class Entry {
        int key, value;

        Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public static void main(String[] args) {
        MyHashMap hashMap = new MyHashMap();
        hashMap.put(1, 1);
        hashMap.put(2, 2);
        System.out.println(hashMap.get(1)); // returns 1
        System.out.println(hashMap.get(3)); // returns -1 (not found)
        hashMap.put(2, 1); // update the existing value
        System.out.println(hashMap.get(2)); // returns 1
        hashMap.remove(2); // remove the mapping for 2
        System.out.println(hashMap.get(2)); // returns -1 (not found)
    }
}
