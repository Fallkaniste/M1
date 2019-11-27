
public class BubbleSort {
	
	public void sort(SortableContainer container) {
		int i = container.length();
		boolean swap = true ;
		while (i > .0 && swap) {
			swap = false;
			for (int j = 0 ; j<i-1 ; j++) {
				if (container.getIndex(j).greaterThan(container.getIndex(j+1))) {
					MyComparable tmp = container.getIndex(j);
					container.setIndex(j,container.getIndex(j+1));
					container.setIndex(j+1,tmp);
					swap = true ;
				}
			}
			i--;
		}
	}
}
