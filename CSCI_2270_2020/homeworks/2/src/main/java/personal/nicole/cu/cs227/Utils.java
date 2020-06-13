package personal.nicole.cu.cs227;

import java.lang.reflect.Array;
import java.util.Map;
import java.util.Set;

public final class Utils {
    static void printArray(Object[] array) {
        for (Object obj : array) {
            if (obj != null) {
                System.out.println(obj.toString());
            } else {
                System.out.println("<null!>");
            }
        }
    }

    static <T> T[] doubleArray(Class<T> clazz, T[] array) {
        int newCapacity = array.length * 2;
        T[] resultArray = (T[]) Array.newInstance(clazz, newCapacity);
        for (int i = 0; i < newCapacity; i++) {
            if (i < array.length) {
                resultArray[i] = array[i];
            } else {
                resultArray[i] = null;
            }
        }
        return resultArray;
    }

    public static <T> void printMap(Map<String, T> map) {
        Set<String> keys = map.keySet();
        for (String key : keys) {
            System.out.println(key + " => " + map.get(key).toString());
        }
    }
}
