public import java.util.Scanner;

class ShellSort {
    public void sort(int arr[]) {
        int n = arr.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter number of elements in array: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter elements of array one by one: ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();

        ShellSort ss = new ShellSort();
        ss.sort(arr);

        System.out.println("Sorted array is");
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
    }
} {
    
}
