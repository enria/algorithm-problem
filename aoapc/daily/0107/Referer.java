import java.util.ArrayList;

/*
Java中的数组和array是传值还是传引用？
传引用！！！
*/
public class Referer {
    public static void main(String[] args) {
        int a[] = new int[2];
        testArray(a);
        System.out.println(a[0]);
        System.out.println(a[1]);

        ArrayList<Integer> b = new ArrayList<Integer>();
        testList(b);
        System.out.println(b.get(0));
    }

    static void testArray(int a[]) {
        a[0] = 1;
    }

    static void testList(ArrayList<Integer> a) {
        a.add(3);
    }
}