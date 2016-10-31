public class Sort {
	public static void main(String[] args) {
		Mergesort ms = new Mergesort();
		Quicksort qs = new Quicksort();
		int[] values = {5,9,2,0,5,10,3};	
		//ms.mergeSort(values);
		qs.quickSort(values);
		for(int i : values) {
			System.out.print(i + " ");
		}
	}
}

