package colorExtendPoint;

import static org.junit.Assert.assertEquals;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class ColoredPointTest {

	private ColoredPoint p;    

	@Before
	public void setUp() throws Exception {   
		this.p = new ColoredPoint(1.0F, 2.0F,1,2,3);  
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

	@Test  
	public void testRedComponentOfColor() {   
		assertEquals(1,this.p.getRed());  
	} 

	@Test  
	public void testGreenComponentOfColor() {   
		assertEquals(2,this.p.getGreen());  
	}    

	@Test  
	public void testBlueComponentOfColor() {   
		assertEquals(3,this.p.getBlue());  
	}   

	@Test  
	public void testRedComponentSetter() {   
		this.p.setRed(255);   
		assertEquals(255,this.p.getRed());  
	} 

	@Test  
	public void testGreenComponentSetter() {   
		this.p.setGreen(255);   
		assertEquals(255,this.p.getGreen());  
	}    

	@Test  
	public void testBlueComponentSetter() {   
		this.p.setBlue(255);   
		assertEquals(255,this.p.getBlue());  
	}    

	@Test  
	public void testOrigin_Point() {   
		assertEquals(0.0F,ColoredPoint.ORIGIN_POINT.getAbscisse(),0F);   
		assertEquals(0.0F,ColoredPoint.ORIGIN_POINT.getOrdinate(),0F);   
		assertEquals(0,ColoredPoint.ORIGIN_POINT.getRed());   
		assertEquals(0,ColoredPoint.ORIGIN_POINT.getGreen());   
		assertEquals(0,ColoredPoint.ORIGIN_POINT.getBlue());  
	} 
}
