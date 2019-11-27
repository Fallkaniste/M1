import java.util.ArrayList;

public class ListTriable implements SortableContainer {
	
	private ArrayList<MyComparable> data;

	public ListTriable(int i) {
		this.data = new ArrayList<MyComparable>(10);
	}
	
	public int length() {
		return this.data.size();
	}

	
	public MyComparable getIndex(int i) {
		return this.data.get(i);
	}

	
	public void setIndex(int j, MyComparable index) {
		this.data.set(j,index);
	}

	
	public boolean addElement(MyComparable element) {
		return this.data.add(element);
	}

	@Override
	public void sort() {
		BubbleSort strategie = new BubbleSort();
		strategie.sort(this);
	}
}
