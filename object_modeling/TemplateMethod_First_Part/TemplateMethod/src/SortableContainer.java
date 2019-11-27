
public interface SortableContainer {

	void sort();

	int length();

	MyComparable getIndex(int i);

	void setIndex(int j, MyComparable index);

	boolean addElement(MyComparable element);

}