package colorExtendPoint;


import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class PointTest {

	private Point p;    

	@Before 
	public void setUp() throws Exception {   
		this.p = new Point(1.0F, 2.0F);  
	} 

	@After
	public void tearDown() throws Exception {   
		this.p = null;  
	} 

	@Test  
	public void testAbscisseConstructor() {   
		assertEquals(1.0F,this.p.getAbscisse(),0F);  
	}    

	@Test  
	public void testOrdinateConstructor() {   
		assertEquals(2.0F,this.p.getOrdinate(),0F);  
	}    

	@Test  
	public void testOrigin_Point() {   
		assertEquals(0.0F,Point.ORIGIN_POINT.getAbscisse(),0F);   
		assertEquals(0.0F,Point.ORIGIN_POINT.getOrdinate(),0F);  
	}    

	@Test  
	public void testTranslate() {   
		float oldAbscisse = this.p.getAbscisse();   
		float oldOrdonnee = this.p.getOrdinate();   
		this.p.translate(1.1F, 2.2F);   
		assertEquals(oldAbscisse + 1.1F, this.p.getAbscisse(),0F);   
		assertEquals(oldOrdonnee + 2.2F, this.p.getOrdinate(),0F);  
	}    

	@Test  
	public void testToScale() {   
		float oldAbscisse = this.p.getAbscisse();   
		float oldOrdonnee = this.p.getOrdinate();   
		this.p.toScale(1.5F);   
		assertEquals(oldAbscisse * 1.5F, this.p.getAbscisse(),0F);   
		assertEquals(oldOrdonnee * 1.5F, this.p.getOrdinate(),0F);  
	}  

	@Test(expected=IllegalArgumentException.class)
	public void NullValueInputForToScaleMethod() {
	    this.p.toScale(0.0F);
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void NegativeValueInputForToScaleMethod() {  
		this.p.toScale(-1.0F);
	}

}
