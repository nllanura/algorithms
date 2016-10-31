public class Mergesort {

	private int[] array;
	
	public void mergeSort(int[] array) {
		this.array = array;
		mergeSort(0, array.length - 1);
	}

	public void mergeSort(int low, int high) {
		if(low < high) {
			int middle = low + ((high - low) / 2);
			mergeSort(low, middle);
			mergeSort(middle+1, high);
			merge(low, middle, high);
		}
	}

	public void merge(int low, int middle, int high) {
		int[] helpArray = new int[array.length];
		int helperLeft = low;
		int helperRight = middle + 1;
		int current = low;

		while(helperLeft <= middle && helperRight <= high) {
			if(array[helperLeft] <= array[helperRight]) {
				helpArray[current++] = array[helperLeft++];
			} else {
				helpArray[current++] = array[helperRight++];
			}
		}

		while(helperLeft <= middle) helpArray[current++] = array[helperLeft++]; 
		while(helperRight <= high) helpArray[current++] = array[helperRight++];
		for(int i = low; i <= high; i++) {
			array[i] = helpArray[i];
		}
	}
}

