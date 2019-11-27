import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;


public abstract class ConteneurTriableTest {

	protected  SortableContainer test;
	
	@Before
	public void setUp() {
		this.test.addElement(new MyString("coucou"));
		this.test.addElement(new MyString("Hello"));
		this.test.addElement(new MyString("World"));
		this.test.addElement(new MyString("Monde"));
		this.test.addElement(new MyString("alphabet"));
		this.test.addElement(new MyString("alphabetisation"));
		this.test.addElement(new MyString("coucou"));
		this.test.addElement(new MyString("Zorro"));
		this.test.addElement(new MyString("Zoe"));
		this.test.addElement(new MyString("TouteBonneChoseAUneFin"));
	}
	
	@Test
	public void testTriArray() {
		this.test.sort();
		for (int i = 0; i < this.test.length()-1; i++) {
			assertTrue(this.test.getIndex(i).lessThanOrEqualTo(this.test.getIndex(i+1)));
		}
	}

}
