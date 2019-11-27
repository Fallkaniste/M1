
public class ArrayTriable implements SortableContainer {

	MyComparable[] data ;
	int nbElements;
	
	public ArrayTriable(int i) {
		this.data = new MyComparable[i];
	}
	
	public int length() {
		return this.data.length;
	}

	public MyComparable getIndex(int i) {
		return this.data[i];
	}

	public void setIndex(int j, MyComparable index) {
		this.data[j] = index ;

	}
	
	public boolean addElement(MyComparable element) {
		if (this.nbElements <= this.data.length) {
			this.data[nbElements]= element;
			this.nbElements +=1;
			return true;
		}
		return false;
	}

	
	public void sort() {
		BubbleSort strategie = new BubbleSort();
		strategie.sort(this);
	}
}
