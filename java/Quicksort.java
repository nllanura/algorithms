public class Quicksort {
	public void quickSort(int[] array) {
		quickSort(array, 0, array.length - 1);
	}

	public void quickSort(int[] array, int left, int right) {
		if(array.length == 0) return;
		int pivot = array[left + ((right - left) / 2)];
		int i = left, j = right;

		while(i <= j) {
			while(array[i] < pivot) i++;
			while(array[j] > pivot) j--;
			if(i <= j) {
				swap(array, i++, j--);
			}
		}

		if(left < j) quickSort(array, left, j);
		if(i < right) quickSort(array, i, right);
	}

	public void swap(int[] array, int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
